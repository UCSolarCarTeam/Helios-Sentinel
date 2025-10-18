#ifndef MPPT_H
#define MPPT_H

#include "IPacket.h"
#include "../Util/PropertyDefinitions.h"

class Mppt : public IPacket {
    Q_OBJECT

    DEFINE_PROPERTY(unsigned long long, Data)
    SUB_PROPERTY(unsigned short, ArrayVoltage, Data, 0xFFFFULL, 0)
    SUB_PROPERTY(unsigned short, ArrayCurrent, Data, 0xFFFFULL, 16)
    SUB_PROPERTY(unsigned short, BatteryVoltage, Data, 0xFFFFULL, 32)
    SUB_PROPERTY(unsigned short, Temperature, Data, 0xFFFFULL, 48)

public:
    Mppt(QCanBusDevice* canDevice, const unsigned int idOffset);
};

#endif // MPPT_H
