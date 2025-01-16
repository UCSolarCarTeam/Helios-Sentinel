#ifndef KEYMOTOR_H
#define KEYMOTOR_H
#include "PropertyDefinition.h"
#include <QObject>

class KeyMotor : public QObject
{
    Q_OBJECT
public:
    explicit KeyMotor(QObject *parent = nullptr);

    DEFINE_PROPERTY_WHOLE_NUMBER(unsigned short, MotorSetpoint, 2, 2)
    DEFINE_PROPERTY_BOOL(ControlMode, 4, 0x01)
    DEFINE_PROPERTY_BOOL(MotorMode, 4, 0x02)
    DEFINE_PROPERTY_BOOL(SoftwareEnable, 4, 0x04)
    DEFINE_PROPERTY_BOOL(DebugMode, 4, 0x08)

    Q_PROPERTY(QString byteStreamStr READ byteStreamStr NOTIFY byteStreamStrChanged)
    Q_PROPERTY(QString encodedByteStreamStr READ encodedByteStreamStr NOTIFY encodedByteStreamStrChanged FINAL)

    QByteArray byteStream() const;
    QByteArray encodedByteStream() const;
    QString byteStreamStr() const;
    QString encodedByteStreamStr() const;


signals:
    void byteStreamChanged();
    void byteStreamStrChanged();
    void encodedByteStreamStrChanged();


private:

    QByteArray byteStream_;
    QByteArray encodedByteStream_;
    void updateByteStream();

};

#endif // KEYMOTOR_H
