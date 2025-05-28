#ifndef BATTERYFAULTS_H
#define BATTERYFAULTS_H
#include "PropertyDefinition.h"
#include <QObject>

class BatteryFaults : public QObject
{
    Q_OBJECT
public:
    explicit BatteryFaults(QObject *parent = nullptr);

    DEFINE_BOOL(DischargeLimitEnforcement, 3, 0x01)
    DEFINE_BOOL(ChargerSafetyRelay, 3, 0x02)
    DEFINE_BOOL(InternalMemory, 3, 0x04)
    DEFINE_BOOL(InternalThermistor, 3, 0x08)
    DEFINE_BOOL(InternalLogic, 3, 0x10)

    DEFINE_BOOL(VoltageRedundancy, 4, 0x01)
    DEFINE_BOOL(FanMonitor, 4, 0x02)
    DEFINE_BOOL(Thermistor, 4, 0x04)
    DEFINE_BOOL(CanbusCommunications, 4, 0x08)
    DEFINE_BOOL(AlwaysOnSupply, 4, 0x10)
    DEFINE_BOOL(HighVoltageIsolation, 4, 0x20)
    DEFINE_BOOL(PowerSupply12V, 4, 0x40)
    DEFINE_BOOL(ChargeLimitEnforcement, 4, 0x80)

    DEFINE_BOOL(InternalCommunication, 5, 0x01)
    DEFINE_BOOL(InternalConversion, 5, 0x02)
    DEFINE_BOOL(WeakCell, 5, 0x04)
    DEFINE_BOOL(LowCellVoltage, 5, 0x08)
    DEFINE_BOOL(OpenWiring, 5, 0x10)
    DEFINE_BOOL(CurrentSensor, 5, 0x20)
    DEFINE_BOOL(PackVoltageSensor, 5, 0x40)
    DEFINE_BOOL(WeakPack, 5, 0x80)

    DEFINE_BOOL(CclSoc, 6, 0x02)
    DEFINE_BOOL(CclCellResistance, 6, 0x04)
    DEFINE_BOOL(CclTemperature, 6, 0x08)
    DEFINE_BOOL(CclCellVoltage, 6, 0x10)
    DEFINE_BOOL(CclPackVoltage, 6, 0x20)
    DEFINE_BOOL(CclChargerLatch, 6, 0x40)
    DEFINE_BOOL(CclCurrent, 6, 0x80)

    DEFINE_BOOL(DclSoc, 7, 0x01)
    DEFINE_BOOL(DclCellResistance, 7, 0x02)
    DEFINE_BOOL(DclTemperature, 7, 0x04)
    DEFINE_BOOL(DclCellVoltage, 7, 0x08)
    DEFINE_BOOL(DclPackVoltage, 7, 0x10)
    DEFINE_BOOL(DclCclVoltage, 7, 0x40)
    DEFINE_BOOL(DclCclCommunication, 7, 0x80)

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
