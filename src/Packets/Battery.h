#ifndef BATTERY_H
#define BATTERY_H

#include "IPacket.h"
#include "../Util/PropertyDefinitions.h"

class Battery : public IPacket {
    Q_OBJECT

    DEFINE_PROPERTY(unsigned long long, StartupInfo)
    SUB_PROPERTY(bool, DischargeRelayEnabled, StartupInfo, 0x01, 0)
    SUB_PROPERTY(bool, ChargeRelayEnabled, StartupInfo, 0x02, 0)
    SUB_PROPERTY(bool, ChargerSafetyEnabled, StartupInfo, 0x04, 0)
    SUB_PROPERTY(bool, MalfunctionIndicatorEnabled, StartupInfo, 0x08, 0)
    SUB_PROPERTY(bool, MultiPurposeInputSignal, StartupInfo, 0x10, 0)
    SUB_PROPERTY(bool, AlwaysOnSignal, StartupInfo, 0x20, 0)
    SUB_PROPERTY(bool, IsReadySignal, StartupInfo, 0x40, 0)
    SUB_PROPERTY(bool, IsChargingSignal, StartupInfo, 0x80, 0)
    SUB_PROPERTY(unsigned char, PopulatedCells, StartupInfo, 0xFFULL, 8)
    SUB_PROPERTY(unsigned short, Input12V, StartupInfo, 0xFFFFULL, 16)
    SUB_PROPERTY(unsigned short, FanVoltage, StartupInfo, 0xFFFFULL, 32)

    DEFINE_PROPERTY(unsigned long long, PackInfo)
    SUB_PROPERTY(unsigned short, PackCurrent, PackInfo, 0xFFFFULL, 0)
    SUB_PROPERTY(unsigned short, PackVoltage, PackInfo, 0xFFFFULL, 16)
    SUB_PROPERTY(unsigned char, PackStateOfCharge, PackInfo, 0xFFULL, 32)
    SUB_PROPERTY(unsigned short, PackAmphours, PackInfo, 0xFFFFULL, 40)
    SUB_PROPERTY(unsigned char, PackDepthOfDischarge, PackInfo, 0xFFULL, 56)

    DEFINE_PROPERTY(unsigned long long, TempInfo)
    SUB_PROPERTY(unsigned char, HighTemperature, TempInfo, 0xFFULL, 0)
    SUB_PROPERTY(unsigned char, HighThermistorId, TempInfo, 0xFFULL, 8)
    SUB_PROPERTY(unsigned char, LowTemperature, TempInfo, 0xFFULL, 16)
    SUB_PROPERTY(unsigned char, LowThermistorId, TempInfo, 0xFFULL, 24)
    SUB_PROPERTY(unsigned char, AverageTemperature, TempInfo, 0xFFULL, 32)
    SUB_PROPERTY(unsigned char, InternalTemperature, TempInfo, 0xFFULL, 40)
    SUB_PROPERTY(unsigned char, FanSpeed, TempInfo, 0xFFULL, 48)
    SUB_PROPERTY(unsigned char, RequestedFanSpeed, TempInfo, 0xFFULL, 56)

    DEFINE_PROPERTY(unsigned long long, CellVoltages)
    SUB_PROPERTY(unsigned short, LowCellVoltage, CellVoltages, 0xFFFFULL, 0)
    SUB_PROPERTY(unsigned char, LowCellVoltageId, CellVoltages, 0xFFULL, 16)
    SUB_PROPERTY(unsigned short, HighCellVoltage, CellVoltages, 0xFFFFULL, 24)
    SUB_PROPERTY(unsigned char, HighCellVoltageId, CellVoltages, 0xFFULL, 40)
    SUB_PROPERTY(unsigned short, AverageCellVoltage, CellVoltages, 0xFFFFULL, 48)

    DEFINE_PROPERTY(unsigned long long, MaxMinVoltages)
    SUB_PROPERTY(unsigned short, MaxCellVoltage, MaxMinVoltages, 0xFFFFULL, 0)
    SUB_PROPERTY(unsigned short, MinCellVoltage, MaxMinVoltages, 0xFFFFULL, 16)
    SUB_PROPERTY(unsigned short, MaxPackVoltage, MaxMinVoltages, 0xFFFFULL, 32)
    SUB_PROPERTY(unsigned short, MinPackVoltage, MaxMinVoltages, 0xFFFFULL, 48)

public:
    Battery(QCanBusDevice* canDevice);
};

#endif // BATTERY_H
