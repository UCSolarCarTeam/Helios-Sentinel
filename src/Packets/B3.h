#ifndef B3_H
#define B3_H

#include "IPacket.h"
#include "../Util/PropertyDefinitions.h"

class B3 : public IPacket{
    Q_OBJECT

    DEFINE_PROPERTY(unsigned char, LightsInputs)
    SUB_PROPERTY(bool, RightSignalIn, LightsInputs, 0x01, 0)
    SUB_PROPERTY(bool, LeftSignalIn, LightsInputs, 0x02, 0)
    SUB_PROPERTY(bool, HazardLightsIn, LightsInputs, 0x04, 0)
    SUB_PROPERTY(bool, HeadlightsIn, LightsInputs, 0x08, 0)

    DEFINE_PROPERTY(unsigned short, DigitalInputs)
    SUB_PROPERTY(bool, Forward, DigitalInputs, 0x01, 0)
    SUB_PROPERTY(bool, Neutral, DigitalInputs, 0x02, 0)
    SUB_PROPERTY(bool, Reverse, DigitalInputs, 0x04, 0)
    SUB_PROPERTY(bool, Horn, DigitalInputs, 0x08, 0)
    SUB_PROPERTY(bool, Brake, DigitalInputs, 0x10, 0)
    SUB_PROPERTY(bool, Handbrake, DigitalInputs, 0x20, 0)
    SUB_PROPERTY(bool, MotorReset, DigitalInputs, 0x40, 0)
    SUB_PROPERTY(bool, RaceMode, DigitalInputs, 0x80, 0)
    SUB_PROPERTY(bool, Lap, DigitalInputs, 0x0100, 0)

    DEFINE_PROPERTY(unsigned short, AnalogInputs)
    SUB_PROPERTY(unsigned char, Acceleration, AnalogInputs, 0xFF, 0)
    SUB_PROPERTY(unsigned char, RegenBraking, AnalogInputs, 0xFF, 8)

    DEFINE_PROPERTY(unsigned char, LightsStatus)
    SUB_PROPERTY(bool, RightSignalStatus, LightsStatus, 0x01, 0)
    SUB_PROPERTY(bool, LeftSignalStatus, LightsStatus, 0x02, 0)
    SUB_PROPERTY(bool, DaytimeRunningLightStatus, LightsStatus, 0x04, 0)
    SUB_PROPERTY(bool, HeadlightStatus, LightsStatus, 0x08, 0)
    SUB_PROPERTY(bool, BrakeLightStatus, LightsStatus, 0x10, 0)
    SUB_PROPERTY(bool, HornStatus, LightsStatus, 0x20, 0)

public:
    B3(QCanBusDevice* canDevice);
};

#endif // B3_H
