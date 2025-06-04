#include "Contactors.h"

Contactors::Contactors(QCanBusDevice* canDevice) : IPacket(canDevice) {
    timerData_ = {
        {0x210, {100, [this]() { sendCommonMessage(); }}},
        {0x211, {100, [this]() { sendMotorMessage(); }}},
        {0x212, {100, [this]() { sendArrayMessage(); }}},
        {0x213, {100, [this]() { sendLvMessage(); }}},
        {0x214, {100, [this]() { sendChargeMessage(); }}},
    };

    initAndStartTimers();
}
