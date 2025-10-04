#ifndef CONTACTORS_H
#define CONTACTORS_H

#include "IPacket.h"
#include "../Util/PropertyDefinitions.h"

class Contactors : public IPacket{
    Q_OBJECT

    DEFINE_PROPERTY(unsigned int, Common)
    SUB_PROPERTY(bool, CommonIsPrechargerClosed, Common, 0x01, 0)
    SUB_PROPERTY(bool, CommonIsPrechargerClosing, Common, 0x02, 0)
    SUB_PROPERTY(bool, CommonPrechargerError, Common, 0x04, 0)
    SUB_PROPERTY(bool, CommonIsContactorClosed, Common, 0x08, 0)
    SUB_PROPERTY(bool, CommonIsContactorClosing, Common, 0x10, 0)
    SUB_PROPERTY(bool, CommonContactorError, Common, 0x20, 0)
    SUB_PROPERTY(unsigned short, CommonLineCurrent, Common, 0xFFF, 10) //TODO: refine offset calc for 12 bit data types
    SUB_PROPERTY(unsigned short, CommonChargeCurrent, Common, 0xFFF, -2) //TODO: see above
    SUB_PROPERTY(bool, CommonContactorOpeningError, Common, 0x40000000, 0) //Warning can be ignored, TODO: address/suppress warning

    DEFINE_PROPERTY(unsigned int, Motor)
    SUB_PROPERTY(bool, MotorIsPrechargerClosed, Motor, 0x01, 0)
    SUB_PROPERTY(bool, MotorIsPrechargerClosing, Motor, 0x02, 0)
    SUB_PROPERTY(bool, MotorPrechargerError, Motor, 0x04, 0)
    SUB_PROPERTY(bool, MotorIsContactorClosed, Motor, 0x08, 0)
    SUB_PROPERTY(bool, MotorIsContactorClosing, Motor, 0x10, 0)
    SUB_PROPERTY(bool, MotorContactorError, Motor, 0x20, 0)
    SUB_PROPERTY(unsigned short, MotorLineCurrent, Motor, 0xFFF, 10) //TODO: refine offset calc for 12 bit data types
    SUB_PROPERTY(unsigned short, MotorChargeCurrent, Motor, 0xFFF, -2) //TODO: see above
    SUB_PROPERTY(bool, MotorBpsError, Motor, 0x40000000, 0) //Warning can be ignored, TODO: address/suppress warning

    DEFINE_PROPERTY(unsigned int, Array)
    SUB_PROPERTY(bool, ArrayIsPrechargerClosed, Array, 0x01, 0)
    SUB_PROPERTY(bool, ArrayIsPrechargerClosing, Array, 0x02, 0)
    SUB_PROPERTY(bool, ArrayPrechargerError, Array, 0x04, 0)
    SUB_PROPERTY(bool, ArrayIsContactorClosed, Array, 0x08, 0)
    SUB_PROPERTY(bool, ArrayIsContactorClosing, Array, 0x10, 0)
    SUB_PROPERTY(bool, ArrayContactorError, Array, 0x20, 0)
    SUB_PROPERTY(unsigned short, ArrayLineCurrent, Array, 0xFFF, 10) //TODO: refine offset calc for 12 bit data types
    SUB_PROPERTY(unsigned short, ArrayChargeCurrent, Array, 0xFFF, -2) //TODO: see above
    SUB_PROPERTY(bool, ArrayBpsError, Array, 0x40000000, 0) //Warning can be ignored, TODO: address/suppress warning

    DEFINE_PROPERTY(unsigned int, Lv)
    SUB_PROPERTY(bool, LvIsPrechargerClosed, Lv, 0x01, 0)
    SUB_PROPERTY(bool, LvIsPrechargerClosing, Lv, 0x02, 0)
    SUB_PROPERTY(bool, LvPrechargerError, Lv, 0x04, 0)
    SUB_PROPERTY(bool, LvIsContactorClosed, Lv, 0x08, 0)
    SUB_PROPERTY(bool, LvIsContactorClosing, Lv, 0x10, 0)
    SUB_PROPERTY(bool, LvContactorError, Lv, 0x20, 0)
    SUB_PROPERTY(unsigned short, LvLineCurrent, Lv, 0xFFF, 10) //TODO: refine offset calc for 12 bit data types
    SUB_PROPERTY(unsigned short, LvChargeCurrent, Lv, 0xFFF, -2) //TODO: see above
    SUB_PROPERTY(bool, LvBpsError, Lv, 0x40000000, 0) //Warning can be ignored, TODO: address/suppress warning

    DEFINE_PROPERTY(unsigned int, Charge)
    SUB_PROPERTY(bool, ChargeIsPrechargerClosed, Charge, 0x01, 0)
    SUB_PROPERTY(bool, ChargeIsPrechargerClosing, Charge, 0x02, 0)
    SUB_PROPERTY(bool, ChargePrechargerError, Charge, 0x04, 0)
    SUB_PROPERTY(bool, ChargeIsContactorClosed, Charge, 0x08, 0)
    SUB_PROPERTY(bool, ChargeIsContactorClosing, Charge, 0x10, 0)
    SUB_PROPERTY(bool, ChargeContactorError, Charge, 0x20, 0)
    SUB_PROPERTY(unsigned short, ChargeLineCurrent, Charge, 0xFFF, 10) //TODO: refine offset calc for 12 bit data types
    SUB_PROPERTY(unsigned short, ChargeChargeCurrent, Charge, 0xFFF, -2) //TODO: see above
    SUB_PROPERTY(bool, ChargeBpsError, Charge, 0x40000000, 0) //Warning can be ignored, TODO: address/suppress warning

public:
    Contactors(QCanBusDevice* canDevice);
};

#endif // CONTACTORS_H
