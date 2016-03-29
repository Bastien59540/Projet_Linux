#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settingsdialog.h"

#include <QMessageBox>
#include <QLabel>
#include <QtSerialPort/QSerialPort>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    serial = new QSerialPort(this);

    settings = new SettingsDialog;

    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionQuit->setEnabled(true);
    ui->actionConfigure->setEnabled(true);

    status = new QLabel;
    ui->statusBar->addWidget(status);

    QBrush brush((Qt::GlobalColor) 7,(Qt::BrushStyle) Qt::SolidPattern);
    scene = new custom_scene();
    scene->setParent(this);
    rect  = scene->addRect(QRectF(0,0,360,360));
    rect2 = scene->addRect(QRectF(90,90,180,180));
    lin   = scene->addLine(0,180,360,180);
    lin2  = scene->addLine(180,0,180,360);
    pt    = scene->addEllipse(177,177,6,6);
    pt->setBrush(brush);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();

    initActionsConnections();

    connect(serial, SIGNAL(error(QSerialPort::SerialPortError)), this,
            SLOT(handleError(QSerialPort::SerialPortError)));
    connect(this,SIGNAL(positionUpdated(int,int)),scene,SLOT(gotNewPosition(int,int)));
    connect(serial, SIGNAL(readyRead()), this, SLOT(readData()));

}


MainWindow::~MainWindow()
{
    if(serial->isOpen())
    {
        QByteArray a;
        a.push_back(1);
        a.push_back(255);
        a.push_back(4);
        writeData(a);
        closeSerialPort();
    }

    delete settings;
    delete ui;
}

//! [4]
void MainWindow::openSerialPort()
{
    SettingsDialog::Settings p = settings->settings();// get serial port setting from settingsdialog
    serial->setPortName(p.name);
    serial->setBaudRate(p.baudRate);
    serial->setDataBits(p.dataBits);
    serial->setParity(p.parity);
    serial->setStopBits(p.stopBits);
    serial->setFlowControl(p.flowControl);
    if (serial->open(QIODevice::ReadWrite))// try to open a serial port with current setting
    {
        // if connection etablished

        Message a;
        unsigned char b[2]={90,90};
        a.data=b;
        putData(&a);// init position to [90;90] ( range 0-180 )

        // update gui
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
        ui->pushButton_4->setEnabled(true);
        ui->actionConnect->setEnabled(false);
        ui->actionDisconnect->setEnabled(true);
        ui->actionConfigure->setEnabled(false);
        showStatusMessage(tr("Connecte a %1 : %2, %3, %4, %5, %6")
                          .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
                          .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));
    } else {
        // if impossible to open the port

        QMessageBox::critical(this, tr("Erreur"), serial->errorString());// error pop-up

        showStatusMessage(tr("Open error"));// write in status bar
    }
}

void MainWindow::closeSerialPort()
{
    if (serial->isOpen())
        serial->close();

    // update gui

    ui->pushButton_4->setText("Activer le tracking");
    ui->graphicsView->setEnabled(false);
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionConfigure->setEnabled(true);
    showStatusMessage(tr("Deconnecte"));
}

void MainWindow::writeData(const QByteArray &data)
{
    serial->write(data);
}

void MainWindow::readData()
{
    QByteArray buff = serial->readAll();
    Message *data=ReadFrame(&buff);

    // if frame is correct
    if(data->mode == Protocol::ACK)
    {
        int x = (int) data->data[0];// data value less transmission offset
        int y = (int) data->data[1];// ""

        // update gui

        QString up="Position: ";
        up.push_back(x);
        up.push_back(" ; ");
        up.push_back(y);
        this->ui->Position->setText(up);
        x = (x * 2) - 3;
        y = (y * 2) - 3;
        pt->setPos(x,y);

        emit positionUpdated(x,y);// Deprecated
    }
    else
    {
        if(data->mode == Protocol::NACK)
            showStatusMessage(tr("NACK send by board"));
    }
}

void MainWindow::putData(Message *data)
{
    if(serial->isOpen())
    {
        const QByteArray *ref=ApplyProtocol(data);

        this->serial->write(*ref);             // send processed data
    }
}

void MainWindow::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("Erreur critique: "), serial->errorString());
        closeSerialPort();
    }
}
//! [8]

void MainWindow::initActionsConnections()
{
    connect(ui->actionConnect, SIGNAL(triggered()), this, SLOT(openSerialPort()));
    connect(ui->actionDisconnect, SIGNAL(triggered()), this, SLOT(closeSerialPort()));
    connect(ui->actionQuit, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionConfigure, SIGNAL(triggered()), settings, SLOT(show()));
    connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(about()));
}

void MainWindow::showStatusMessage(const QString &message)
{
    status->setText(message);
}

void MainWindow::about()
{
    showStatusMessage(tr("(c)213-50-1-2016"));
}


void MainWindow::on_pushButton_clicked()
{
    Message data;
    unsigned char m[1];
    m[0]=(unsigned char)Protocol::CUBE;
    data.mode=Protocol::MODE_AUTO;
    data.data=m;
    putData(&data);
}

void MainWindow::on_pushButton_2_clicked()
{
    Message data;
    unsigned char m[1];
    m[0]=(unsigned char)Protocol::ELLIPSE;
    data.mode=Protocol::MODE_AUTO;
    data.data=m;
    putData(&data);
}

void MainWindow::on_pushButton_3_clicked()
{
    Message data;
    unsigned char m[1];
    m[0]=(unsigned char)Protocol::TRIANGLE;
    data.mode=Protocol::MODE_AUTO;
    data.data=m;
    putData(&data);
}

void MainWindow::on_pushButton_4_clicked()
{
    // enable / disable tracking mode

    if(ui->graphicsView->isEnabled())
    {
        ui->pushButton_4->setText("Activer le tracking");
        ui->graphicsView->setEnabled(false);
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
    }
    else
    {
        ui->pushButton_4->setText("Desactiver le tracking");
        ui->graphicsView->setEnabled(true);
        ui->pushButton->setEnabled(false);
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
    }
}
