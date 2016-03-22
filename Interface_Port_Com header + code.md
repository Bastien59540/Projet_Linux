#ifndef PORT_COM_H
#define PORT_COM_H

#include <stdio.h>
#include <iostream>
#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QThread>
#include <exception>

using namespace std;

class Port_Com : public QObject
{
     Q_OBJECT
public:
    explicit Port_Com(QObject *Parent = 0);
    ~Port_Com();

private:

    QSerialPort *serial;
    QByteArray rx;
    bool res;
    void Connecter();
    void Gauche();
    void Droite();
    void Quitter();
signals:
  void statut(QString);

public slots:





private slots:

};

#endif // PORT_COM_H

### CODE  ####

#include "port_com.h"

Port_Com::Port_Com(QObject *parent) : QObject(parent)
{
    res=false;
    cout<<"start"<<endl;
    try
    {
    this->serial=new QSerialPort(this);
    //serial->setPortName("COM1");
    this->serial->setPortName("COM1");
    this->serial->setBaudRate(QSerialPort::Baud9600);
    this->serial->setDataBits(QSerialPort::Data8);
    this->serial->setParity(QSerialPort::NoParity);
    this->serial->setStopBits(QSerialPort::OneStop);
    this->serial->setFlowControl(QSerialPort::NoFlowControl);
    connect(serial,SIGNAL(readyRead()),this,SLOT(read()));
    }
    catch(exception e)
    {
        cout<<e.what()<<endl;
    }
}

Port_Com::~Port_Com()
{
    serial->close();
}

void Port_Com::Connecter(){           //OUverture du port serie et on le garde ouvert
    if(serial->open(QIODevice::ReadWrite)){
       emit statut("O");
        res=true;
    }
    else{
        serial->close();
        emit statut("E");
    }
}

void Port_Com::Gauche(){
serial->write("G");
}

void Port_Com::Droite()
{
serial->write("D");
}

void Port_Com::Quitter()
{
serial->close();
}



