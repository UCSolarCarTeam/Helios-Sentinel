#ifndef DRIVERCONTROLSELYSIA_H
#define DRIVERCONTROLSELYSIA_H
#include "../../Utils/PropertyDefinition.h"
#include <QObject>

class DriverControlsElysia : public QObject
{
    Q_OBJECT
public:
    explicit DriverControlsElysia(QObject *parent = nullptr);

    DEFINE_PROPERTY_BOOL(DriverControlsAlive, 1, 0x01)
    DEFINE_PROPERTY_BOOL(HeadlightsOff, 3, 0x01)
    DEFINE_PROPERTY_BOOL(HeadlightsLow, 3, 0x02)
    DEFINE_PROPERTY_BOOL(HeadlightsHigh, 3, 0x04)
    DEFINE_PROPERTY_BOOL(SignalRight, 3, 0x08)
    DEFINE_PROPERTY_BOOL(SignalLeft, 3, 0x10)
    DEFINE_PROPERTY_BOOL(Hazards, 3, 0x20)
    DEFINE_PROPERTY_BOOL(Interior, 3, 0x40)
    DEFINE_PROPERTY_BOOL(VolumeUp, 4, 0x01)
    DEFINE_PROPERTY_BOOL(VolumeDown, 4, 0x02)
    DEFINE_PROPERTY_BOOL(Next, 4, 0x04)
    DEFINE_PROPERTY_BOOL(Prev, 4, 0x08)
    DEFINE_PROPERTY_BOOL(Brakes, 9, 0x01)
    DEFINE_PROPERTY_BOOL(Forward, 9, 0x02)
    DEFINE_PROPERTY_BOOL(Reverse, 9, 0x04)
    DEFINE_PROPERTY_BOOL(PushToTalk, 9, 0x08)
    DEFINE_PROPERTY_BOOL(Horn, 9, 0x10)
    DEFINE_PROPERTY_BOOL(Reset, 9, 0x20)
    DEFINE_PROPERTY_BOOL(Aux, 9, 0x40)
    DEFINE_PROPERTY_BOOL(Lap, 9, 0x80)

    DEFINE_PROPERTY_WHOLE_NUMBER(unsigned short, Acceleration, 5, 2)
    DEFINE_PROPERTY_WHOLE_NUMBER(unsigned short, RegenBraking, 5, 2)

    Q_PROPERTY(QString byteStreamStr READ byteStreamStr NOTIFY byteStreamStrChanged FINAL)
    Q_PROPERTY(QString encodedByteStreamStr READ encodedByteStreamStr NOTIFY encodedByteStreamStrChanged FINAL)



    QByteArray byteStream() const;
    QByteArray encodedByteStream() const; //HERE
    QString byteStreamStr() const;
    QString encodedByteStreamStr() const; //HERE



signals:

    void byteStreamStrChanged();
    void encodedByteStreamStrChanged();

private:

    QByteArray byteStream_;
    QByteArray encodedByteStream_;

    void updateByteStream();



};

#endif // DRIVERCONTROLSELYSIA_H
