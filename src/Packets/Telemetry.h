#ifndef TELEMETRY_H
#define TELEMETRY_H

#include "../Utils/PropertyDefinition.h"
#include <QObject>


class Telemetry : public QObject
{
    Q_OBJECT
public:
    explicit Telemetry(QObject *parent = nullptr);

    DEFINE_PROPERTY_WHOLE_NUMBER(unsigned short, GpsYear, 2, 2)
    DEFINE_PROPERTY_WHOLE_NUMBER(unsigned char, GpsMonth, 4, 1)
    DEFINE_PROPERTY_WHOLE_NUMBER(unsigned char, GpsDay, 5, 1)
    DEFINE_PROPERTY_WHOLE_NUMBER(unsigned char, GpsHour, 6, 1)
    DEFINE_PROPERTY_WHOLE_NUMBER(unsigned char, GpsMinute, 7, 1)
    DEFINE_PROPERTY_WHOLE_NUMBER(unsigned char, GpsSecond, 8, 1)
    DEFINE_PROPERTY_WHOLE_NUMBER(unsigned char, GpsValidityFlags, 9, 1)
    DEFINE_PROPERTY_WHOLE_NUMBER(unsigned char, GpsFixStatusFlags, 10, 1)
    DEFINE_PROPERTY_WHOLE_NUMBER(unsigned char, GpsAdditionalFlags, 11, 1)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, GpsLongitude, 12, 4)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, GpsLatitude, 16, 4)
    DEFINE_PROPERTY_WHOLE_NUMBER(unsigned short, MpuAccelerationX, 20, 2)
    DEFINE_PROPERTY_WHOLE_NUMBER(unsigned short, MpuAccelerationY, 22, 2)
    DEFINE_PROPERTY_WHOLE_NUMBER(unsigned short, MpuAccelerationZ, 24, 2)
    DEFINE_PROPERTY_WHOLE_NUMBER(unsigned short, MpuRotationX, 26, 2)
    DEFINE_PROPERTY_WHOLE_NUMBER(unsigned short, MpuRotationY, 28, 2)
    DEFINE_PROPERTY_WHOLE_NUMBER(unsigned short, MpuRotationZ, 30, 2)
    DEFINE_PROPERTY_WHOLE_NUMBER(unsigned short, MpuTemperature, 32, 2)


    Q_PROPERTY(QString byteStreamStr READ byteStreamStr NOTIFY byteStreamStrChanged FINAL)
    Q_PROPERTY(QString encodedByteStreamStr READ encodedByteStreamStr NOTIFY encodedByteStreamStrChanged FINAL)

    QByteArray byteStream() const;
    QByteArray encodedByteStream() const;
    QString byteStreamStr() const;
    QString encodedByteStreamStr() const;

signals:
    void byteStreamStrChanged();
    void encodedByteStreamStrChanged();


private:

    QByteArray byteStream_;
    QByteArray encodedByteStream_;

    void updateByteStream();
};


#endif // TELEMETRY_H
