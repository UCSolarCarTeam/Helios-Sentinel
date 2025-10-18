#ifndef BATTERYFAULTS_H
#define BATTERYFAULTS_H

#include "IPacket.h"
#include "../Util/PropertyDefinitions.h"

#include <QCanBus>

class BatteryFaults : public IPacket {
    Q_OBJECT

    DEFINE_PROPERTY(unsigned long long, Errors)
    SUB_PROPERTY(bool, DclReducedDueToLowSoc, Errors, 0x0001, 0)
    SUB_PROPERTY(bool, DclReducedDueToHighCellResistance, Errors, 0x0002, 0)
    SUB_PROPERTY(bool, DclReducedDueToTemperature, Errors, 0x0004, 0)
    SUB_PROPERTY(bool, DclReducedDueToLowCellVoltage, Errors, 0x0008, 0)
    SUB_PROPERTY(bool, DclReducedDueToLowPackVoltage, Errors, 0x0010, 0)
    SUB_PROPERTY(bool, DclAndCclReducedDueToVoltageFailsafe, Errors, 0x0040, 0)
    SUB_PROPERTY(bool, DclAndCclReducedDueToCommunicationFailsafe, Errors, 0x0080, 0)
    SUB_PROPERTY(bool, CclReducedDueToHighSoc, Errors, 0x0200, 0)
    SUB_PROPERTY(bool, CclReducedDueToHighCellResistance, Errors, 0x0400, 0)
    SUB_PROPERTY(bool, CclReducedDueToTemperature, Errors, 0x0800, 0)
    SUB_PROPERTY(bool, CclReducedDueToHighCellVoltage, Errors, 0x1000, 0)
    SUB_PROPERTY(bool, CclReducedDueToHighPackVoltage, Errors, 0x2000, 0)
    SUB_PROPERTY(bool, CclReducedDueToChargerLatch, Errors, 0x4000, 0)
    SUB_PROPERTY(bool, CclReducedDueToAlternateCurrentLimit, Errors, 0x8000, 0)

    SUB_PROPERTY(bool, InternalCommunicationFault, Errors, 0x0001, 16)
    SUB_PROPERTY(bool, InternalConversionFault, Errors, 0x0002, 16)
    SUB_PROPERTY(bool, WeakCellFault, Errors, 0x0004, 16)
    SUB_PROPERTY(bool, LowCellVoltageFault, Errors, 0x0008, 16)
    SUB_PROPERTY(bool, OpenWiringFault, Errors, 0x0010, 16)
    SUB_PROPERTY(bool, CurrentSensorFault, Errors, 0x0020   , 16)
    SUB_PROPERTY(bool, PackVoltageSensorFault, Errors, 0x0040, 16)
    SUB_PROPERTY(bool, WeakPackFault, Errors, 0x0080, 16)
    SUB_PROPERTY(bool, VoltageRedundancyFault, Errors, 0x0100, 16)
    SUB_PROPERTY(bool, FanMonitorFault, Errors, 0x0200, 16)
    SUB_PROPERTY(bool, ThermistorFault, Errors, 0x0400, 16)
    SUB_PROPERTY(bool, CanbusCommunicationsFault, Errors, 0x0800, 16)
    SUB_PROPERTY(bool, AlwaysOnSupplyFault, Errors, 0x1000, 16)
    SUB_PROPERTY(bool, HighVoltageIsolationFault, Errors, 0x2000, 16)
    SUB_PROPERTY(bool, PowerSupplyFault, Errors, 0x4000, 16)
    SUB_PROPERTY(bool, ChargeLimitEnforcementFault, Errors, 0x8000, 16)

    SUB_PROPERTY(bool, DischargeLimitEnforcementFault, Errors, 0x0001, 32)
    SUB_PROPERTY(bool, ChargerSafetyRelayFault, Errors, 0x0002, 32)
    SUB_PROPERTY(bool, InternalMemoryFault, Errors, 0x0004, 32)
    SUB_PROPERTY(bool, InternalThermistorFault, Errors, 0x0008, 32)
    SUB_PROPERTY(bool, InternalLogicFault, Errors, 0x0010, 32)


public:
    BatteryFaults(QCanBusDevice* canDevice);
};

#endif // BATTERYFAULTS_H
