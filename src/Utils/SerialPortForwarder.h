#ifndef SERIALPORTFORWARDER_H
#define SERIALPORTFORWARDER_H

#include <QObject>
#include <QtSerialPort/QSerialPort>

class SerialPortForwarder : public QObject
{
    Q_OBJECT
public:
    explicit SerialPortForwarder(const QString &portName, QObject *parent = nullptr);
     ~SerialPortForwarder() override;
    void forwardData(const QByteArray &data);
     QSerialPort* getSerialPort() const;

private:
    QSerialPort *serialPort_;
};

#endif // SERIALPORTFORWARDER_H
