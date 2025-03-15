#ifndef DRIVERCONTROLSELYSIA_H
#define DRIVERCONTROLSELYSIA_H
#include "../PropertyDefinition.h"
#include <QObject>

class DriverControls : public QObject
{
    Q_OBJECT
public:
    explicit DriverControls(QObject *parent = nullptr);

    DEFINE_BOOL(DriverControlsAlive, 1, 0x01)
    DEFINE_BOOL(HeadlightsOff, 3, 0x01)
    DEFINE_BOOL(HeadlightsLow, 3, 0x02)
    DEFINE_BOOL(HeadlightsHigh, 3, 0x04)
    DEFINE_BOOL(SignalRight, 3, 0x08)
    DEFINE_BOOL(SignalLeft, 3, 0x10)
    DEFINE_BOOL(Hazards, 3, 0x20)
    DEFINE_BOOL(Interior, 3, 0x40)
    DEFINE_BOOL(VolumeUp, 4, 0x01)
    DEFINE_BOOL(VolumeDown, 4, 0x02)
    DEFINE_BOOL(Next, 4, 0x04)
    DEFINE_BOOL(Prev, 4, 0x08)
    DEFINE_BOOL(Brakes, 9, 0x01)
    DEFINE_BOOL(Forward, 9, 0x02)
    DEFINE_BOOL(Reverse, 9, 0x04)
    DEFINE_BOOL(PushToTalk, 9, 0x08)
    DEFINE_BOOL(Horn, 9, 0x10)
    DEFINE_BOOL(Reset, 9, 0x20)
    DEFINE_BOOL(Aux, 9, 0x40)
    DEFINE_BOOL(Lap, 9, 0x80)

    DEFINE_WHOLE_NUMBER(unsigned short, Acceleration, 5, 2)
    DEFINE_WHOLE_NUMBER(unsigned short, RegenBraking, 5, 2)

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
