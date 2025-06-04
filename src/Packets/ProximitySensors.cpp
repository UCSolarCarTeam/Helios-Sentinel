#include "ProximitySensors.h"

ProximitySensors::ProximitySensors(QCanBusDevice* canDevice) : IPacket(canDevice) {
    timerData_ = {
        {0x700, {500, [this]() { sendProximitySensor1Message(); }}},
        {0x701, {500, [this]() { sendProximitySensor2Message(); }}},
        {0x702, {500, [this]() { sendProximitySensor3Message(); }}},
        {0x703, {500, [this]() { sendProximitySensor4Message(); }}}
    };

    initAndStartTimers();
};
