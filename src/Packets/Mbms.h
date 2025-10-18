#ifndef MBMS_H
#define MBMS_H

#include "IPacket.h"
#include "../Util/PropertyDefinitions.h"

#include <QCanBusDevice>

class Mbms : public IPacket {
    Q_OBJECT

    DEFINE_PROPERTY(unsigned char, ContactorCommand)
    SUB_PROPERTY(bool, CommonContactorCommand, ContactorCommand, 0x01, 0)
    SUB_PROPERTY(bool, MotorContactorCommand, ContactorCommand, 0x02, 0)
    SUB_PROPERTY(bool, ArrayContactorCommand, ContactorCommand, 0x04, 0)
    SUB_PROPERTY(bool, LvContactorCommand, ContactorCommand, 0x08, 0)
    SUB_PROPERTY(bool, ChargeContactorCommand, ContactorCommand, 0x10, 0)

    DEFINE_PROPERTY(unsigned int, Status)
    SUB_PROPERTY(unsigned char, AuxillaryBatteryVoltage, Status, 0x1F, 0)
    SUB_PROPERTY(bool, StrobeBmsLight, Status, 0x01, 5)
    SUB_PROPERTY(bool, ChargeEnable, Status, 0x02, 5)
    SUB_PROPERTY(bool, NChargeSafety, Status, 0x04, 5)
    SUB_PROPERTY(bool, DischargeEnable, Status, 0x08, 5)
    SUB_PROPERTY(bool, OrionCanReceivedRecently, Status, 0x10, 5)
    SUB_PROPERTY(bool, DischargeShouldTrip, Status, 0x20, 5)
    SUB_PROPERTY(bool, ChargeShouldTrip, Status, 0x40, 5)
    SUB_PROPERTY(unsigned char, StartupState, Status, 0x0F, 12)
    SUB_PROPERTY(unsigned char, SystemState, Status, 0x07, 16)

    DEFINE_PROPERTY(unsigned short, PowerSelectionStatus)
    SUB_PROPERTY(bool, NMainPowerSwitch, PowerSelectionStatus, 0x0001, 0)
    SUB_PROPERTY(bool, ExternalShutdown, PowerSelectionStatus, 0x0002, 0)
    SUB_PROPERTY(bool, En1, PowerSelectionStatus, 0x0004, 0)
    SUB_PROPERTY(bool, NDcdcFault, PowerSelectionStatus, 0x0008, 0)
    SUB_PROPERTY(bool, N3Aoc, PowerSelectionStatus, 0x0010, 0)
    SUB_PROPERTY(bool, NDcdcOn, PowerSelectionStatus, 0x0020, 0)
    SUB_PROPERTY(bool, NChgFault, PowerSelectionStatus, 0x0040, 0)
    SUB_PROPERTY(bool, NChgOn, PowerSelectionStatus, 0x0080, 0)
    SUB_PROPERTY(bool, NChgLvEn, PowerSelectionStatus, 0x0100, 0)
    SUB_PROPERTY(bool, AbattDisable, PowerSelectionStatus, 0x0200, 0)
    SUB_PROPERTY(bool, Key, PowerSelectionStatus, 0x0400, 0)

    DEFINE_PROPERTY(unsigned int, Trip)
    SUB_PROPERTY(bool, HighCellVoltageTrip, Trip, 0x0001, 0)
    SUB_PROPERTY(bool, LowCellVoltageTrip, Trip, 0x0002, 0)
    SUB_PROPERTY(bool, CommonHighCurrentTrip, Trip, 0x0004, 0)
    SUB_PROPERTY(bool, MotorHighCurrentTrip, Trip, 0x0008, 0)
    SUB_PROPERTY(bool, ArrayHighCurrentTrip, Trip, 0x0010, 0)
    SUB_PROPERTY(bool, LvHighCurrentTrip, Trip, 0x0020, 0)
    SUB_PROPERTY(bool, ChargeHighCurrentTrip, Trip, 0x0040, 0)
    SUB_PROPERTY(bool, ProtectionTrip, Trip, 0x0080, 0)
    SUB_PROPERTY(bool, OrionMessageTimeoutTrip, Trip, 0x0100, 0)
    SUB_PROPERTY(bool, ContactorDisconnectedUnexpectedlyTrip, Trip, 0x0200, 0)
    SUB_PROPERTY(bool, ContactorConnectedUnexpectelyTrip, Trip, 0x0400, 0)
    SUB_PROPERTY(bool, CommonHeartbeatDeadTrip, Trip, 0x0800, 0)
    SUB_PROPERTY(bool, MotorHeartbeatDeadTrip, Trip, 0x1000, 0)
    SUB_PROPERTY(bool, ArrayHeartbeatDeadTrip, Trip, 0x2000, 0)
    SUB_PROPERTY(bool, LvHeartbeatDeadTrip, Trip, 0x4000, 0)
    SUB_PROPERTY(bool, ChargeHeartbeatDeadTrip, Trip, 0x8000, 0)
    SUB_PROPERTY(bool, MpsDisabledTrip, Trip, 0x01, 16)
    SUB_PROPERTY(bool, EsdEnabledTrip, Trip, 0x02, 16)
    SUB_PROPERTY(bool, HighTemperatureTrip, Trip, 0x04, 16)
    SUB_PROPERTY(bool, LowTemperatureTrip, Trip, 0x08, 16)

    DEFINE_PROPERTY(unsigned short, SoftBatteryLimitWarning)
    SUB_PROPERTY(bool, HighCellVoltageWarning, SoftBatteryLimitWarning, 0x0001, 0)
    SUB_PROPERTY(bool, LowCellVoltageWarning, SoftBatteryLimitWarning, 0x0002, 0)
    SUB_PROPERTY(bool, CommonHighCurrentWarning, SoftBatteryLimitWarning, 0x0004, 0)
    SUB_PROPERTY(bool, MotorHighCurrentWarning, SoftBatteryLimitWarning, 0x0008, 0)
    SUB_PROPERTY(bool, ArrayHighCurrentWarning, SoftBatteryLimitWarning, 0x0010, 0)
    SUB_PROPERTY(bool, LvHighCurrentWarning, SoftBatteryLimitWarning, 0x0020, 0)
    SUB_PROPERTY(bool, ChargeHighCurrentWarning, SoftBatteryLimitWarning, 0x0040, 0)
    SUB_PROPERTY(bool, HighTemperatureWarning, SoftBatteryLimitWarning, 0x0080, 0)
    SUB_PROPERTY(bool, LowTemperatureWarning, SoftBatteryLimitWarning, 0x0100, 0)
    SUB_PROPERTY(bool, CanOc12VWarning, SoftBatteryLimitWarning, 0x0200, 0)

public:
    Mbms(QCanBusDevice* canDevice);
};

#endif // MBMS_H
