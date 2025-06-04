#ifndef KEYMOTOR_H
#define KEYMOTOR_H

#include "IPacket.h"
#include "../Util/PropertyDefinitions.h"

#include <QCanBusDevice>

class KeyMotor : public IPacket{
    Q_OBJECT

    DEFINE_PROPERTY(short, ControlValue, 0x550)

    DEFINE_PROPERTY(unsigned char, MiscStatus, 0x551)
    SUB_PROPERTY(unsigned char, ControlMode, MiscStatus, 0x03, 0)
    SUB_PROPERTY(unsigned char, MotorMode, MiscStatus, 0x07, -2)
    SUB_PROPERTY(bool, SoftwareEnable, MiscStatus, 0x20, 0)
    //ignored 0x40
    SUB_PROPERTY(bool, DebugMode, MiscStatus, 0x80, 0)

public:
   KeyMotor(QCanBusDevice* canDevice);
};

#endif // KEYMOTOR_H
