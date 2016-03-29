/// \author Quentin Berdal
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/QtGlobal>

#include <QMainWindow>
#include <QGraphicsItem>
#include <QtSerialPort/QSerialPort>
#include "protocol.h"

QT_BEGIN_NAMESPACE

class QLabel;
class SettingsDialog;
class custom_scene;

namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE


/*/////////////////////////////////////////////////*/

/** Main GUI
 * Contain all elements used to control the board
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void putData(Message *data);             ///< Put data on serial port with protocol.
                                             ///< See "protocol.h" for more information

private slots:
    void openSerialPort();                   ///< Open serial port according to setting.
                                             ///< Setup made through settingsdialog
    void closeSerialPort();                  ///< Close serial port
    void about();
    void readData();                         ///< Read data from packet.
                                             ///< See "protocol.h" for more information
    void writeData(const QByteArray &data);  ///< Write data without protocol

    void handleError(QSerialPort::SerialPortError error);///< Serial port error handler

    void on_pushButton_clicked();   ///< Auto mode: rectangle.
                                    ///< Request the board to draw a rectangle

    void on_pushButton_2_clicked(); ///< Auto mode: ellipse.
                                    ///< Request the board to draw an ellipse

    void on_pushButton_3_clicked(); ///< Auto mode: triangle.
                                    ///< Request the board to draw a triangle

    void on_pushButton_4_clicked(); ///< Tracking mode.
                                    ///< Switch to tracking mode.
                                    ///< The mouse cursor is used to move the laser.

private:
    void initActionsConnections();  ///< Connect actions and Slots
    custom_scene *scene;            ///< Main scene for mouse tracking
    QGraphicsRectItem *rect;        ///< Limite rectangle ([0;0],[180;180])
    QGraphicsRectItem *rect2;       ///< Half limite rectangle ([45;45],[135;135])
    QGraphicsLineItem *lin;         ///< X axis
    QGraphicsLineItem *lin2;        ///< Y axis
    QGraphicsEllipseItem *pt;       ///< Laser position

private:
    void showStatusMessage(const QString &message);///< Print in status bar

    Ui::MainWindow *ui;
    QLabel *status;
    SettingsDialog *settings;
    QSerialPort *serial;

signals:
    void positionUpdated(int x,int y);

};

#include "custom_scene.h"

#endif // MAINWINDOW_H
