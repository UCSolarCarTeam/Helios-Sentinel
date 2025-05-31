#ifndef MBMS_H
#define MBMS_H
#include "PropertyDefinition.h"
#include <QObject>


class Mbms : public QObject
{
    Q_OBJECT
public:
    explicit Mbms(QObject *parent = nullptr);

    DEFINE_BOOL(CommonContactorState, 2, 0x01)
    DEFINE_BOOL(MotorContactorState, 2, 0x02)
    DEFINE_BOOL(ArrayContactorState, 2, 0x04)
    DEFINE_BOOL(LvContactorState, 2, 0x08)
    DEFINE_BOOL(ChargeContactorState, 2, 0x10)

    DEFINE_BOOL(CommonContactorError, 3, 0x01)
    DEFINE_BOOL(MotorContactorError, 3, 0x02)
    DEFINE_BOOL(ArrayContactorError, 3, 0x04)
    DEFINE_BOOL(LvContactorError, 3, 0x08)
    DEFINE_BOOL(ChargeContactorError, 3, 0x10)

    DEFINE_BOOL(StrobeBmsLight, 4, 0x01)
    DEFINE_BOOL(AllowCharge, 4, 0x02)
    DEFINE_BOOL(HighVoltageEnableState, 4, 0x04)
    DEFINE_BOOL(AllowDischarge, 4, 0x08)
    DEFINE_BOOL(OrionCanReceivedRecently, 4, 0x10)
    DEFINE_BOOL(DischargeShouldTrip, 4, 0x20)
    DEFINE_BOOL(ChargeShouldTrip, 4, 0x40)

    DEFINE_WHOLE_NUMBER(unsigned short, AuxillaryBatteryVoltage, 5, 2)
    DEFINE_WHOLE_NUMBER(unsigned short, MotorVoltage, 7, 2)
    DEFINE_WHOLE_NUMBER(unsigned short, ArrayVoltage, 9, 2)
    DEFINE_WHOLE_NUMBER(unsigned short, LvVoltage, 11, 2)
    DEFINE_WHOLE_NUMBER(unsigned short, ChargeVoltage, 13, 2)
    DEFINE_WHOLE_NUMBER(unsigned short, CommonCurrent, 15, 2)
    DEFINE_WHOLE_NUMBER(unsigned short, MotorCurrent, 17, 2)
    DEFINE_WHOLE_NUMBER(unsigned short, ArrayCurrent, 19, 2)
    DEFINE_WHOLE_NUMBER(unsigned short, LvCurrent, 21, 2)
    DEFINE_WHOLE_NUMBER(unsigned short, ChargeCurrent, 23, 2)

    DEFINE_BOOL(OrionMessageTimeoutTrip, 25, 0x01)
    DEFINE_BOOL(ContactorDisconnectedTrip, 25, 0x02)

    DEFINE_BOOL(HighCellVoltageTrip, 26, 0x01)
    DEFINE_BOOL(LowCellVoltageTrip, 26, 0x02)
    DEFINE_BOOL(HighCommonCurrentTrip, 26, 0x04)
    DEFINE_BOOL(MotorTCTrip, 26, 0x08)
    DEFINE_BOOL(ArrayTCTrip, 26, 0x10)
    DEFINE_BOOL(LvTCTrip, 26, 0x20)
    DEFINE_BOOL(ChargeTCTrip, 26, 0x40)
    DEFINE_BOOL(ProtectionTrip, 26, 0x80)

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


#endif // MBMS_H
