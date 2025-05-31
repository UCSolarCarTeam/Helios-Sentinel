#ifndef B3_H
#define B3_H
#include "PropertyDefinition.h"
#include <QObject>

class B3 : public QObject
{
    Q_OBJECT
public:
    explicit B3(QObject *parent = nullptr);

    DEFINE_BOOL(RightSignalIn, 2, 0x01)
    DEFINE_BOOL(LeftSignalIn,2,0x02)
    DEFINE_BOOL(HazardLights,2,0x04)
    DEFINE_BOOL(HeadlightsSwitch,2,0x08)
    DEFINE_BOOL(ForwardSwitch,3, 0x01)
    DEFINE_BOOL(HornSwitch, 3, 0x02)
    DEFINE_BOOL(Forward, 3, 0x04)
    DEFINE_BOOL(Neutral, 3,0x08)
    DEFINE_BOOL(Reverse, 3, 0x10)
    DEFINE_BOOL(BrakeSwitch, 3, 0x20)
    DEFINE_BOOL(HandbrakeSwitch, 3, 0x40)
    DEFINE_BOOL(MotorReset, 3, 0x80)
    DEFINE_BOOL(RaceMode, 4, 0x01)
    DEFINE_BOOL(Lap, 4, 0x02)
    DEFINE_BOOL(ZoomZoom, 4, 0x04)
    DEFINE_WHOLE_NUMBER(unsigned char, Acceleration, 5, 1)
    DEFINE_WHOLE_NUMBER(unsigned char, RegenBraking, 6, 1)
    DEFINE_BOOL(RightSignalOut, 7, 0x01)
    DEFINE_BOOL(LeftSignalOut, 7, 0x02)
    DEFINE_BOOL(DaytimeRunningLightSignal, 7, 0x04)
    DEFINE_BOOL(HeadlightSignal, 7, 0x08)
    DEFINE_BOOL(BrakeLightSignal, 7, 0x10)
    DEFINE_BOOL(HornSignal, 7, 0x20)

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
