#ifndef BATTERYFAULTS_H
#define BATTERYFAULTS_H
#include "PropertyDefinition.h"
#include <QObject>

class BatteryFaults : public QObject
{
    Q_OBJECT
public:
    explicit BatteryFaults(QObject *parent = nullptr);
    DEFINE_PROPERTY_BOOL(InternalCommunication, 2, 0x01)
    DEFINE_PROPERTY_BOOL(InternalConversion, 2, 0x02)
    DEFINE_PROPERTY_BOOL(WeakCell, 2, 0x04)
    DEFINE_PROPERTY_BOOL(LowCellVoltage, 2, 0x08)
    DEFINE_PROPERTY_BOOL(OpenWiring, 2, 0x10)
    DEFINE_PROPERTY_BOOL(CurrentSensor, 2, 0x20)
    DEFINE_PROPERTY_BOOL(PackVoltageSensor, 2, 0x40)
    DEFINE_PROPERTY_BOOL(WeakPack, 2, 0x80)
    DEFINE_PROPERTY_BOOL(VoltageRedundancy, 3, 0x01)
    DEFINE_PROPERTY_BOOL(FanMonitor, 3, 0x02)
    DEFINE_PROPERTY_BOOL(Thermistor, 3, 0x04)
    DEFINE_PROPERTY_BOOL(CanbusCommunications, 3, 0x08)
    DEFINE_PROPERTY_BOOL(AlwaysOnSupply, 3, 0x10)
    DEFINE_PROPERTY_BOOL(HighVoltageIsolation, 3, 0x20)
    DEFINE_PROPERTY_BOOL(PowerSupply12V, 3, 0x40)
    DEFINE_PROPERTY_BOOL(ChargeLimitEnforcement, 3, 0x80)
    DEFINE_PROPERTY_BOOL(DischargeLimitEnforcement, 4, 0x01)
    DEFINE_PROPERTY_BOOL(ChargerSafetyRelay, 4, 0x02)
    DEFINE_PROPERTY_BOOL(InternalMemory, 4, 0x04)
    DEFINE_PROPERTY_BOOL(InternalThermistor, 4, 0x08)
    DEFINE_PROPERTY_BOOL(InternalLogic, 4, 0x10)
    DEFINE_PROPERTY_BOOL(DclSoc, 6, 0x01)
    DEFINE_PROPERTY_BOOL(DclCellResistance, 6, 0x02)
    DEFINE_PROPERTY_BOOL(DclTemperature, 6, 0x04)
    DEFINE_PROPERTY_BOOL(DclCellVoltage, 6, 0x08)
    DEFINE_PROPERTY_BOOL(DclPackVoltage, 6, 0x10)
    DEFINE_PROPERTY_BOOL(DclCclVoltage, 6, 0x40)
    DEFINE_PROPERTY_BOOL(DclCclCommunication, 6, 0x80)
    DEFINE_PROPERTY_BOOL(CclSoc, 7, 0x02)
    DEFINE_PROPERTY_BOOL(CclCellResistance, 7, 0x04)
    DEFINE_PROPERTY_BOOL(CclTemperature, 7, 0x08)
    DEFINE_PROPERTY_BOOL(CclCellVoltage, 7, 0x10)
    DEFINE_PROPERTY_BOOL(CclPackVoltage, 7, 0x20)
    DEFINE_PROPERTY_BOOL(CclChargerLatch, 7, 0x40)
    DEFINE_PROPERTY_BOOL(CclCurrent, 7, 0x80)

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

#endif // BATTERYFAULTS_H
