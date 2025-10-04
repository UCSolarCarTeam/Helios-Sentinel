#ifndef KEYMOTOR_H
#define KEYMOTOR_H

#include "IPacket.h"
#include "../Util/PropertyDefinitions.h"

#include <QCanBusDevice>

class KeyMotor : public IPacket{
    Q_OBJECT

    DEFINE_PROPERTY(unsigned long long, DriveCommand, 0x501)
    SUB_PROPERTY(float, Velocity, DriveCommand, 0xFFFFFFFFULL, 0)
    SUB_PROPERTY(float, Current, DriveCommand, 0xFFFFFFFFULL, 32)
    
    DEFINE_PROPERTY(unsigned long long, PowerCommand, 0x502) //empty from 0-31
    SUB_PROPERTY(float, BusCurrentOut, PowerCommand, 0xFFFFFFFFULL, 32)

public:
   KeyMotor(QCanBusDevice* canDevice);
};

#endif // KEYMOTOR_H
