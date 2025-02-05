#ifndef MBMS_H
#define MBMS_H
#include "../../Utils/PropertyDefinition.h"
#include <QObject>


class Mbms : public QObject
{
    Q_OBJECT
public:
    explicit Mbms(QObject *parent = nullptr);

    DEFINE_PROPERTY_BOOL(CommonContactorState, 2, 0x01)
    DEFINE_PROPERTY_BOOL(MotorContactorState, 2, 0x02)
    DEFINE_PROPERTY_BOOL(ArrayContactorState, 2, 0x04)
    DEFINE_PROPERTY_BOOL(LvContactorState, 2, 0x08)
    DEFINE_PROPERTY_BOOL(ChargeContactorState, 2, 0x10)
    DEFINE_PROPERTY_BOOL(CommonContactorError, 3, 0x01)
    DEFINE_PROPERTY_BOOL(MotorContactorError, 3, 0x02)
    DEFINE_PROPERTY_BOOL(ArrayContactorError, 3, 0x04)
    DEFINE_PROPERTY_BOOL(LvContactorError, 3, 0x08)
    DEFINE_PROPERTY_BOOL(ChargeContactorError, 3, 0x10)
    DEFINE_PROPERTY_BOOL(StrobeBmsLight, 4, 0x01)
    DEFINE_PROPERTY_BOOL(AllowCharge, 4, 0x02)
    DEFINE_PROPERTY_BOOL(HighVoltageEnableState, 4, 0x04)
    DEFINE_PROPERTY_BOOL(AllowDischarge, 4, 0x08)
    DEFINE_PROPERTY_BOOL(OrionCanReceivedRecently, 4, 0x10)
    DEFINE_PROPERTY_BOOL(DischargeShouldTrip, 4, 0x20)
    DEFINE_PROPERTY_BOOL(ChargeShouldTrip, 4, 0x40)
    DEFINE_PROPERTY_WHOLE_NUMBER(unsigned short, AuxillaryBatteryVoltage, 5, 2)
    DEFINE_PROPERTY_WHOLE_NUMBER(unsigned short, MotorVoltage, 7, 2)
    DEFINE_PROPERTY_WHOLE_NUMBER(unsigned short, ArrayVoltage, 9, 2)
    DEFINE_PROPERTY_WHOLE_NUMBER(unsigned short, LvVoltage, 11, 2)
    DEFINE_PROPERTY_WHOLE_NUMBER(unsigned short, ChargeVoltage, 13, 2)
    DEFINE_PROPERTY_WHOLE_NUMBER(unsigned short, CommonCurrent, 15, 2)
    DEFINE_PROPERTY_WHOLE_NUMBER(unsigned short, MotorCurrent, 17, 2)
    DEFINE_PROPERTY_WHOLE_NUMBER(unsigned short, ArrayCurrent, 19, 2)
    DEFINE_PROPERTY_WHOLE_NUMBER(unsigned short, LvCurrent, 21, 2)
    DEFINE_PROPERTY_WHOLE_NUMBER(unsigned short, ChargeCurrent, 23, 2)
    DEFINE_PROPERTY_BOOL(HighCellVoltageTrip, 25, 0x01)
    DEFINE_PROPERTY_BOOL(LowCellVoltageTrip, 25, 0x02)
    DEFINE_PROPERTY_BOOL(HighCommonCurrentTrip, 25, 0x04)
    DEFINE_PROPERTY_BOOL(MotorTCTrip, 25, 0x08)
    DEFINE_PROPERTY_BOOL(ArrayTCTrip, 25, 0x10)
    DEFINE_PROPERTY_BOOL(LvTCTrip, 25, 0x20)
    DEFINE_PROPERTY_BOOL(ChargeTCTrip, 25, 0x40)
    DEFINE_PROPERTY_BOOL(ProtectionTrip, 25, 0x80)
    DEFINE_PROPERTY_BOOL(OrionMessageTimeoutTrip, 26, 0x01)
    DEFINE_PROPERTY_BOOL(ContactorDisconnectedTrip, 26, 0x02)

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
