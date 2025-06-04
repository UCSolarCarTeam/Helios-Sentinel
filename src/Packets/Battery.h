#ifndef BATTERY_H
#define BATTERY_H

#include "IPacket.h"
#include "../Util/PropertyDefinitions.h"

class Battery : public IPacket {
    Q_OBJECT

    DEFINE_PROPERTY(unsigned long long, StartupInfo, 0x301)
    SUB_PROPERTY(bool, DischargeRelayEnabled, StartupInfo, 0x0100000000000000, 0)
    SUB_PROPERTY(bool, ChargeRelayEnabled, StartupInfo, 0x0200000000000000, 0)
    SUB_PROPERTY(bool, ChargerSafetyEnabled, StartupInfo, 0x0400000000000000, 0)
    SUB_PROPERTY(bool, MalfunctionIndicatorEnabled, StartupInfo, 0x0800000000000000, 0)
    SUB_PROPERTY(bool, MultiPurposeInputSignal, StartupInfo, 0x1000000000000000, 0)
    SUB_PROPERTY(bool, AlwaysOnSignal, StartupInfo, 0x2000000000000000, 0)
    SUB_PROPERTY(bool, IsReadySignal, StartupInfo, 0x4000000000000000, 0)
    SUB_PROPERTY(bool, IsChargingSignal, StartupInfo, 0x8000000000000000, 0)
    SUB_PROPERTY(unsigned char, PopulatedCells, StartupInfo, 0xFFULL, 8)
    SUB_PROPERTY(unsigned short, Input12V, StartupInfo, 0xFFFFULL, 16)
    SUB_PROPERTY(unsigned short, FanVoltage, StartupInfo, 0xFFFFULL, 32)


    DEFINE_PROPERTY(unsigned long long, PackInfo, 0x302)
    SUB_PROPERTY(unsigned short, PackCurrent, PackInfo, 0xFFFFULL, 0)
    SUB_PROPERTY(unsigned short, PackVoltage, PackInfo, 0xFFFFULL, 16)
    SUB_PROPERTY(unsigned char, PackStateOfCharge, PackInfo, 0xFFULL, 32)
    SUB_PROPERTY(unsigned short, PackAmphours, PackInfo, 0xFFFFULL, 40)
    SUB_PROPERTY(unsigned char, PackDepthOfDischarge, PackInfo, 0xFFULL, 56)

    DEFINE_PROPERTY(unsigned long long, Errors, 0x303)
    //Current Limit Status
    SUB_PROPERTY(bool, DclReducedLowSOC, Errors, 0x0001000000000000, 0)
    SUB_PROPERTY(bool, DclReducedHighCellResistance, Errors, 0x0002000000000000, 0)
    SUB_PROPERTY(bool, DclReducedTemp, Errors, 0x0004000000000000, 0)
    SUB_PROPERTY(bool, DclReducedLowCellVoltage, Errors, 0x0008000000000000, 0)
    SUB_PROPERTY(bool, DclReducedLowPackVoltage, Errors, 0x0010000000000000, 0)
    //0x0020 skipped
    SUB_PROPERTY(bool, DclCclReducedVoltageFailsafe, Errors, 0x0040000000000000, 0)
    SUB_PROPERTY(bool, DclCclReducedCommunicationFailsafe, Errors, 0x0080000000000000, 0)
    //0x0100 skipped
    SUB_PROPERTY(bool, CclReducedHighSoc, Errors, 0x0200000000000000, 0)
    SUB_PROPERTY(bool, CclReducedHighCellResistance, Errors, 0x0400000000000000, 0)
    SUB_PROPERTY(bool, CclReducedTemp, Errors, 0x0800000000000000, 0)
    SUB_PROPERTY(bool, CclReducedHighCellVoltage, Errors, 0x1000000000000000, 0)
    SUB_PROPERTY(bool, CclReducedHighPackVoltage, Errors, 0x2000000000000000, 0)
    SUB_PROPERTY(bool, CclReducedChargerLatch, Errors, 0x4000000000000000, 0)
    SUB_PROPERTY(bool, CclReducedAlternateCurrrentLimit, Errors, 0x8000000000000000, 0)
    //DTCs (faults)
    SUB_PROPERTY(bool, InternalCommunication, Errors, 0x000001000000, 0)
    SUB_PROPERTY(bool, InternalConversion, Errors, 0x000002000000, 0)
    SUB_PROPERTY(bool, WeakCell, Errors, 0x000004000000, 0)
    SUB_PROPERTY(bool, LowCellVoltageFault, Errors, 0x000008000000, 0)
    SUB_PROPERTY(bool, OpenWiring, Errors, 0x000010000000, 0)
    SUB_PROPERTY(bool, CurrentSensor, Errors, 0x000020000000, 0)
    SUB_PROPERTY(bool, PackVoltageSensor, Errors, 0x000040000000, 0)
    SUB_PROPERTY(bool, WeakPack, Errors, 0x000080000000, 0)
    SUB_PROPERTY(bool, VoltageRedundacy, Errors, 0x000100000000, 0)
    SUB_PROPERTY(bool, FanMonitor, Errors, 0x000200000000, 0)
    SUB_PROPERTY(bool, Thermistor, Errors, 0x000400000000, 0)
    SUB_PROPERTY(bool, CanbusCommunications, Errors, 0x000800000000, 0)
    SUB_PROPERTY(bool, AlwaysOnSupply, Errors, 0x001000000000, 0)
    SUB_PROPERTY(bool, HighVoltageIsolation, Errors, 0x002000000000, 0)
    SUB_PROPERTY(bool, PowerSupply12V, Errors, 0x004000000000, 0)
    SUB_PROPERTY(bool, ChargeLimitEnforcement, Errors, 0x008000000000, 0)
    SUB_PROPERTY(bool, DischargeSafetyRelay, Errors, 0x010000000000, 0)
    SUB_PROPERTY(bool, ChargerSafetyRelay, Errors, 0x020000000000, 0)
    SUB_PROPERTY(bool, InternalMemory, Errors, 0x040000000000, 0)
    SUB_PROPERTY(bool, InternalThermistor, Errors, 0x080000000000, 0)
    SUB_PROPERTY(bool, InternalLogic, Errors, 0x100000000000, 0)

    DEFINE_PROPERTY(unsigned long long, TempInfo, 0x304)
    SUB_PROPERTY(unsigned char, HighTemperature, TempInfo, 0xFFULL, 0)
    SUB_PROPERTY(unsigned char, HighThermistorId, TempInfo, 0xFFULL, 8)
    SUB_PROPERTY(unsigned char, LowTemperature, TempInfo, 0xFFULL, 16)
    SUB_PROPERTY(unsigned char, LowThermistorId, TempInfo, 0xFFULL, 24)
    SUB_PROPERTY(unsigned char, AverageTemperature, TempInfo, 0xFFULL, 32)
    SUB_PROPERTY(unsigned char, InternalTemperature, TempInfo, 0xFFULL, 40)
    SUB_PROPERTY(unsigned char, FanSpeed, TempInfo, 0xFFULL, 48)
    SUB_PROPERTY(unsigned char, RequestedFanSpeed, TempInfo, 0xFFULL, 56)

    DEFINE_PROPERTY(unsigned long long, CellVoltages, 0x305)
    SUB_PROPERTY(unsigned short, LowCellVoltage, CellVoltages, 0xFFFFULL, 0)
    SUB_PROPERTY(unsigned char, LowCellVoltageId, CellVoltages, 0xFFULL, 16)
    SUB_PROPERTY(unsigned short, HighCellVoltage, CellVoltages, 0xFFFFULL, 24)
    SUB_PROPERTY(unsigned char, HighCellVoltageId, CellVoltages, 0xFFULL, 40)
    SUB_PROPERTY(unsigned short, AverageCellVoltage, CellVoltages, 0xFFFFULL, 48)

    DEFINE_PROPERTY(unsigned long long, MaxMinVoltages, 0x30A)
    SUB_PROPERTY(unsigned short, MaxCellVoltage, MaxMinVoltages, 0xFFFFULL, 0)
    SUB_PROPERTY(unsigned short, MinCellVoltage, MaxMinVoltages, 0xFFFFULL, 16)
    SUB_PROPERTY(unsigned short, MaxPackVoltage, MaxMinVoltages, 0xFFFFULL, 32)
    SUB_PROPERTY(unsigned short, MinPackVoltage, MaxMinVoltages, 0xFFFFULL, 48)

public:
    Battery(QCanBusDevice* canDevice);
};

#endif // BATTERY_H
