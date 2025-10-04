#ifndef MPPT_H
#define MPPT_H

#include "IPacket.h"
#include "../Util/PropertyDefinitions.h"

class Mppt : public IPacket {
    Q_OBJECT

    DEFINE_PROPERTY(unsigned long long, M0C0)
    SUB_PROPERTY(unsigned short, M0C0ArrayVoltage, M0C0, 0xFFFFULL, 0)
    SUB_PROPERTY(unsigned short, M0C0ArrayCurrent, M0C0, 0xFFFFULL, 16)
    SUB_PROPERTY(unsigned short, M0C0BatteryVoltage, M0C0, 0xFFFFULL, 32)
    SUB_PROPERTY(unsigned short, M0C0Temperature, M0C0, 0xFFFFULL, 48)

    DEFINE_PROPERTY(unsigned long long, M0C1)
    SUB_PROPERTY(unsigned short, M0C1ArrayVoltage, M0C1, 0xFFFFULL, 0)
    SUB_PROPERTY(unsigned short, M0C1ArrayCurrent, M0C1, 0xFFFFULL, 16)
    SUB_PROPERTY(unsigned short, M0C1BatteryVoltage, M0C1, 0xFFFFULL, 32)
    SUB_PROPERTY(unsigned short, M0C1Temperature, M0C1, 0xFFFFULL, 48)

    DEFINE_PROPERTY(unsigned long long, M1C0)
    SUB_PROPERTY(unsigned short, M1C0ArrayVoltage, M1C0, 0xFFFFULL, 0)
    SUB_PROPERTY(unsigned short, M1C0ArrayCurrent, M1C0, 0xFFFFULL, 16)
    SUB_PROPERTY(unsigned short, M1C0BatteryVoltage, M1C0, 0xFFFFULL, 32)
    SUB_PROPERTY(unsigned short, M1C0Temperature, M1C0, 0xFFFFULL, 48)

    DEFINE_PROPERTY(unsigned long long, M1C1)
    SUB_PROPERTY(unsigned short, M1C1ArrayVoltage, M1C1, 0xFFFFULL, 0)
    SUB_PROPERTY(unsigned short, M1C1ArrayCurrent, M1C1, 0xFFFFULL, 16)
    SUB_PROPERTY(unsigned short, M1C1BatteryVoltage, M1C1, 0xFFFFULL, 32)
    SUB_PROPERTY(unsigned short, M1C1Temperature, M1C1, 0xFFFFULL, 48)

    DEFINE_PROPERTY(unsigned long long, M2C0)
    SUB_PROPERTY(unsigned short, M2C0ArrayVoltage, M2C0, 0xFFFFULL, 0)
    SUB_PROPERTY(unsigned short, M2C0ArrayCurrent, M2C0, 0xFFFFULL, 16)
    SUB_PROPERTY(unsigned short, M2C0BatteryVoltage, M2C0, 0xFFFFULL, 32)
    SUB_PROPERTY(unsigned short, M2C0Temperature, M2C0, 0xFFFFULL, 48)

    DEFINE_PROPERTY(unsigned long long, M2C1)
    SUB_PROPERTY(unsigned short, M2C1ArrayVoltage, M2C1, 0xFFFFULL, 0)
    SUB_PROPERTY(unsigned short, M2C1ArrayCurrent, M2C1, 0xFFFFULL, 16)
    SUB_PROPERTY(unsigned short, M2C1BatteryVoltage, M2C1, 0xFFFFULL, 32)
    SUB_PROPERTY(unsigned short, M2C1Temperature, M2C1, 0xFFFFULL, 48)

    DEFINE_PROPERTY(unsigned long long, M3C0)
    SUB_PROPERTY(unsigned short, M3C0ArrayVoltage, M3C0, 0xFFFFULL, 0)
    SUB_PROPERTY(unsigned short, M3C0ArrayCurrent, M3C0, 0xFFFFULL, 16)
    SUB_PROPERTY(unsigned short, M3C0BatteryVoltage, M3C0, 0xFFFFULL, 32)
    SUB_PROPERTY(unsigned short, M3C0Temperature, M3C0, 0xFFFFULL, 48)

    DEFINE_PROPERTY(unsigned long long, M3C1)
    SUB_PROPERTY(unsigned short, M3C1ArrayVoltage, M3C1, 0xFFFFULL, 0)
    SUB_PROPERTY(unsigned short, M3C1ArrayCurrent, M3C1, 0xFFFFULL, 16)
    SUB_PROPERTY(unsigned short, M3C1BatteryVoltage, M3C1, 0xFFFFULL, 32)
    SUB_PROPERTY(unsigned short, M3C1Temperature, M3C1, 0xFFFFULL, 48)

public:
    Mppt(QCanBusDevice* canDevice);
};

#endif // MPPT_H
