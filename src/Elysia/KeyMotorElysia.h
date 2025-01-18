#ifndef KEYMOTORELYSIA_H
#define KEYMOTORELYSIA_H
#include "../PropertyDefinition.h"
#include <QObject>

class KeyMotorElysia : public QObject
{
    Q_OBJECT
public:
    explicit KeyMotorElysia(QObject *parent = nullptr);


    DEFINE_PROPERTY_BOOL(M0Alive,2,0x01)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, M0SetCurrent, 3, 4)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, M0SetVelocity, 7, 4)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, M0BusCurrent, 11, 4)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, M0BusVoltage, 15, 4)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, M0VehicleVelocity, 19, 4)



    DEFINE_PROPERTY_BOOL(M1Alive,23,0x01)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, M1SetCurrent, 24, 4)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, M1SetVelocity, 28, 4)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, M1BusCurrent, 32, 4)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, M1BusVoltage, 36, 4)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, M1VehicleVelocity, 40, 4)


    Q_PROPERTY(QString byteStreamStr READ byteStreamStr NOTIFY byteStreamStrChanged)
    Q_PROPERTY(QString encodedByteStreamStr READ encodedByteStreamStr NOTIFY encodedByteStreamStrChanged FINAL)

    bool m0Alive() const;
    int m0SetCurrent() const;
    int m0SetVelocity() const;
    int m0BusCurrent() const;
    int m0BusVoltage() const;
    int m0VehicleVelocity() const;

    bool m1Alive() const;
    int m1SetCurrent() const;
    int m1SetVelocity() const;
    int m1BusCurrent() const;
    int m1BusVoltage() const;
    int m1VehicleVelocity() const;

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
