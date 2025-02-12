#ifndef SETTING_H
#define SETTING_H

#include <QObject>
#include <QProcess>
#include <QRegularExpression>

#include "SerialPortForwarder.h"

class Setting : public QObject
{
    Q_OBJECT
public:
    explicit Setting(QObject *parent = nullptr);
    Q_PROPERTY(bool getIsElysia READ getIsElysia NOTIFY isElysiaChanged FINAL)
    Q_PROPERTY(bool connectSerialPort READ connectSerialPort WRITE setConnectSerialPort NOTIFY connectSerialPortChanged FINAL)
    Q_PROPERTY(QString secondPortName READ secondPortName WRITE setSecondPortName NOTIFY secondPortNameChanged FINAL)

    bool getIsElysia() const {return isElysia_;};
    bool connectSerialPort() const;
    QString secondPortName() const;
    SerialPortForwarder* getForwarder() const;

signals:
    void isElysiaChanged(bool on);
    void connectSerialPortChanged(QString portName);
    void secondPortNameChanged(QString portName);

public slots:
    void setIsElysia(bool value) {
        isElysia_ = value;
        emit isElysiaChanged(isElysia_);
    };

    void setConnectSerialPort(bool alive);
    void setSecondPortName(QString name);
    void handleProcessOutput();
    void handleProcessError(QProcess::ProcessError error);

private:
    bool isElysia_ = false;
    bool connectSerialPort_ = false;
    QString processOutputBuffer_;
    SerialPortForwarder *forwarder_;
    QString secondPortName_;
    QProcess *socatProcess;
};

#endif // SETTING_H
