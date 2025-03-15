#ifndef MOTORFAULTSELYSIA_H
#define MOTORFAULTSELYSIA_H
#include "../PropertyDefinition.h"
#include <QObject>

class MotorFaults : public QObject
{
    Q_OBJECT
public:
    explicit MotorFaults(QObject *parent = nullptr);

    DEFINE_BOOL(MotorOverSpeedM0, 2, 0x01)
    DEFINE_BOOL(SoftwareOverCurrentM0, 2, 0x02)
    DEFINE_BOOL(DcBusOverVoltageM0, 2, 0x04)
    DEFINE_BOOL(BadMotorPHSM0, 2, 0x08)
    DEFINE_BOOL(WatchdogCausedLastResetM0, 2, 0x10)
    DEFINE_BOOL(ConfigReadErrorM0, 2, 0x20)
    DEFINE_BOOL(RailUnderVoltageLockM0, 2, 0x40)
    DEFINE_BOOL(DesaturationFaultM0, 2, 0x80)

    DEFINE_BOOL(MotorOverSpeedM1, 3, 0x01)
    DEFINE_BOOL(SoftwareOverCurrentM1, 3, 0x02)
    DEFINE_BOOL(DcBusOverVoltageM1, 3, 0x04)
    DEFINE_BOOL(BadMotorPHSM1, 3, 0x08)
    DEFINE_BOOL(WatchdogCausedLastResetM1, 3, 0x10)
    DEFINE_BOOL(ConfigReadErrorM1, 3, 0x20)
    DEFINE_BOOL(RailUnderVoltageLockM1, 3, 0x40)
    DEFINE_BOOL(DesaturationFaultM1, 3, 0x80)

    DEFINE_BOOL(OutputVoltagePWMM0, 4, 0x01)
    DEFINE_BOOL(MotorCurrentM0, 4, 0x02)
    DEFINE_BOOL(VelocityM0, 4, 0x04)
    DEFINE_BOOL(BusCurrentM0, 4, 0x08)
    DEFINE_BOOL(BusVoltageUpperM0, 4, 0x10)
    DEFINE_BOOL(BusVoltageLowerM0, 4, 0x20)
    DEFINE_BOOL(MotorTemperatureIPMM0, 4, 0x40)

    DEFINE_BOOL(OutputVoltagePWMM1, 5, 0x01)
    DEFINE_BOOL(MotorCurrentM1, 5, 0x02)
    DEFINE_BOOL(VelocityM1, 5, 0x04)
    DEFINE_BOOL(BusCurrentM1, 5, 0x08)
    DEFINE_BOOL(BusVoltageUpperM1, 5, 0x10)
    DEFINE_BOOL(BusVoltageLowerM1, 5, 0x20)
    DEFINE_BOOL(MotorTemperatureIPMM1, 5, 0x40)

    DEFINE_WHOLE_NUMBER(int, CANRXErrorCountM0, 6, 1)
    DEFINE_WHOLE_NUMBER(int, CANTXErrorCountM0, 7, 1)
    DEFINE_WHOLE_NUMBER(int, CANRXErrorCountM1, 8, 1)
    DEFINE_WHOLE_NUMBER(int, CANTXErrorCountM1, 9, 1)


    Q_PROPERTY(QString byteStreamStr READ byteStreamStr NOTIFY byteStreamStrChanged)
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
#endif // MOTORFAULTSELYSIA_H
