#ifndef KEYMOTOR_H
#define KEYMOTOR_H

#include "IPacket.h"
#include "../Util/PropertyDefinitions.h"

#include <QCanBusDevice>

class KeyMotor : public IPacket{
    // Q_OBJECT

    // DEFINE_PROPERTY(short, ControlValue, 0x550)

    // DEFINE_PROPERTY(unsigned char, MiscStatus, 0x551)
    // SUB_PROPERTY(bool )

public:
//    KeyMotor();
};

#endif // KEYMOTOR_H
