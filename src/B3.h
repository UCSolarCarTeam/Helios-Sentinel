#ifndef B3_H
#define B3_H
#include "PropertyDefinition.h"
#include <QObject>

class B3 : public QObject
{
    Q_OBJECT
public:
    explicit B3(QObject *parent = nullptr);

    DEFINE_PROPERTY_BOOL(RightSignalIn, 2, 0x01)
    DEFINE_PROPERTY_BOOL(LeftSignalIn,2,0x02)
    DEFINE_PROPERTY_BOOL(HazardLights,2,0x04)
    DEFINE_PROPERTY_BOOL(HeadlightsSwitch,2,0x08)
    DEFINE_PROPERTY_BOOL(ForwardSwitch,2, 0x10)
    DEFINE_PROPERTY_BOOL(HornSwitch, 2, 0x20)
    DEFINE_PROPERTY_BOOL(Forward,2,0x40)
    DEFINE_PROPERTY_BOOL(Neutral,3,0x01)
    DEFINE_PROPERTY_BOOL(Reverse,3,0x02)
    DEFINE_PROPERTY_BOOL(BrakeSwitch, 3, 0x04)
    DEFINE_PROPERTY_BOOL(HandbrakeSwitch, 3, 0x08)
    DEFINE_PROPERTY_BOOL(MotorReset, 3, 0x10)
    DEFINE_PROPERTY_BOOL(RaceMode, 3, 0x20)
    DEFINE_PROPERTY_BOOL(Lap, 3, 0x40)
    DEFINE_PROPERTY_BOOL(ZoomZoom, 3, 0x80)
    DEFINE_PROPERTY_INT(unsigned short,Acceleration, 4, 2)
    DEFINE_PROPERTY_INT(unsigned short,RegenBraking,6,2)
    DEFINE_PROPERTY_BOOL(RightSignalOut, 8, 0x01)
    DEFINE_PROPERTY_BOOL(LeftSignalOut, 8, 0x02)
    DEFINE_PROPERTY_BOOL(DaytimeRunningLightSignal, 8, 0x04)
    DEFINE_PROPERTY_BOOL(HeadlightSignal, 8, 0x08)
    DEFINE_PROPERTY_BOOL(BrakeLightSignal, 8, 0x10)
    DEFINE_PROPERTY_BOOL(HornSignal, 8, 0x20)

    Q_PROPERTY(QString byteStreamStr READ byteStreamStr NOTIFY byteStreamStrChanged)
    Q_PROPERTY(QString encodedByteStreamStr READ encodedByteStreamStr NOTIFY encodedByteStreamStrChanged)

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

#endif // B3_H
