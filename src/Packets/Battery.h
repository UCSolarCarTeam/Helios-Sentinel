#ifndef BATTERY_H
#define BATTERY_H

#include <QObject>
#include "../Utils/PropertyDefinition.h"
class Battery : public QObject
{
    Q_OBJECT
public:
    explicit Battery(QObject *parent = nullptr);
    DEFINE_PROPERTY_BOOL(BmuAlive, 2,0x01)
    DEFINE_PROPERTY_BOOL(DischargeRelay, 3, 0x01)
    DEFINE_PROPERTY_BOOL(ChargeRelay, 3, 0x02)
    DEFINE_PROPERTY_BOOL(ChargerSafety, 3, 0x04)
    DEFINE_PROPERTY_BOOL(MalfunctionIndicator, 3, 0x08)
    DEFINE_PROPERTY_BOOL(MultiPurposeInputSignal, 3, 0x10)
    DEFINE_PROPERTY_BOOL(AlwaysOnSignal, 3, 0x20)
    DEFINE_PROPERTY_BOOL(IsReadySignal, 3, 0x40)
    DEFINE_PROPERTY_BOOL(IsChargingSignal, 3, 0x80)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, PopulatedCells,4,1 )
    DEFINE_PROPERTY_FLOAT(float, Input12V, 5,4)
    DEFINE_PROPERTY_FLOAT(float, FanVoltage, 9, 4)
    DEFINE_PROPERTY_FLOAT(float, PackCurrent, 13, 4)
    DEFINE_PROPERTY_FLOAT(float, PackVoltage, 17, 4)
    DEFINE_PROPERTY_FLOAT(float, PackSoc, 21, 4)
    DEFINE_PROPERTY_FLOAT(float, PackAmphours, 25, 4)
    DEFINE_PROPERTY_FLOAT(float, PackDod, 29, 4)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, HighTemp, 33, 1)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, HighThermistorId, 34, 1)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, LowTemp, 35, 1)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, LowThermistorId, 36, 1)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, AvgTemp, 37, 1)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, InternalTemp, 38, 1)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, FanSpeed, 39, 1)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, ReqFanSpeed, 40, 1)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, LowCellVoltage, 41, 2)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, LowCellVoltageId, 43, 1)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, HighCellVoltage, 44, 2)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, HighCellVoltageId, 46, 1)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, AvgCellVoltage, 47, 2)


    Q_PROPERTY(QString byteStreamStr READ byteStreamStr NOTIFY byteStreamStrChanged FINAL)
    Q_PROPERTY(QString encodedByteStreamStr READ encodedByteStreamStr NOTIFY encodedByteStreamStrChanged FINAL)


    QByteArray byteStream() const;
    QByteArray encodedByteStream() const; //HERE
    QString byteStreamStr() const;
    QString encodedByteStreamStr() const; //HERE

public slots:




signals:
    void byteStreamStrChanged();
    void encodedByteStreamStrChanged();

private:

    QByteArray byteStream_;
    QByteArray encodedByteStream_;

    void updateByteStream();

};

#endif // BATTERY_H
