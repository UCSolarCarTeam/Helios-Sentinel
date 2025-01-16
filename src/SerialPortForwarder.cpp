#include "SerialPortForwarder.h"
#include <stdexcept>
#include <QDebug>

SerialPortForwarder::SerialPortForwarder(const QString &portName, QObject *parent)
    : QObject{parent}
{
    serialPort_ = new QSerialPort(portName, this);
    serialPort_->setBaudRate(QSerialPort::Baud115200);
    serialPort_->setParity(QSerialPort::NoParity);
    serialPort_->setStopBits(QSerialPort::OneStop);
    serialPort_->setDataBits(QSerialPort::Data8);

    if (!serialPort_->open(QIODevice::ReadWrite)) {
        qDebug() << "Failed to open port" << portName << ", error:" << serialPort_->errorString();
        throw std::runtime_error("Failed to connect to serial port");
    }else{
        qDebug() << "Succefully opened Port";
    }
}

SerialPortForwarder::~SerialPortForwarder() {}

void SerialPortForwarder::forwardData(const QByteArray &data){
    if(serialPort_->isOpen()){
        serialPort_->write(data);
    }
}
