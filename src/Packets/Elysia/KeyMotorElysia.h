#ifndef KEYMOTORELYSIA_H
#define KEYMOTORELYSIA_H
#include "../../Utils/PropertyDefinition.h"
#include <QObject>

class KeyMotorElysia : public QObject
{
    Q_OBJECT
public:
    explicit KeyMotorElysia(QObject *parent = nullptr);


    DEFINE_PROPERTY_BOOL(M0Alive,2,0x01)
    DEFINE_PROPERTY_FLOAT(float, M0SetCurrent, 3, 4)
    DEFINE_PROPERTY_FLOAT(float, M0SetVelocity, 7, 4)
    DEFINE_PROPERTY_FLOAT(float, M0BusCurrent, 11, 4)
    DEFINE_PROPERTY_FLOAT(float, M0BusVoltage, 15, 4)
    DEFINE_PROPERTY_FLOAT(float, M0VehicleVelocity, 19, 4)



    DEFINE_PROPERTY_BOOL(M1Alive,23,0x01)
    DEFINE_PROPERTY_FLOAT(float, M1SetCurrent, 24, 4)
    DEFINE_PROPERTY_FLOAT(float, M1SetVelocity, 28, 4)
    DEFINE_PROPERTY_FLOAT(float, M1BusCurrent, 32, 4)
    DEFINE_PROPERTY_FLOAT(float, M1BusVoltage, 36, 4)
    DEFINE_PROPERTY_FLOAT(float, M1VehicleVelocity, 40, 4)


    Q_PROPERTY(QString byteStreamStr READ byteStreamStr NOTIFY byteStreamStrChanged)
    Q_PROPERTY(QString encodedByteStreamStr READ encodedByteStreamStr NOTIFY encodedByteStreamStrChanged FINAL)


    QByteArray byteStream() const;
    QByteArray encodedByteStream() const;
    QString byteStreamStr() const;
    QString encodedByteStreamStr() const;


signals:

    // void byteStreamChanged();
    void byteStreamStrChanged();
    void encodedByteStreamStrChanged();


private:
    QByteArray byteStream_;
    QByteArray encodedByteStream_;
    void updateByteStream();

};

#endif // KEYMOTORELYSIA_H
