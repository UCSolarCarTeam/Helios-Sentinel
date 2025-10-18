#include "Mppt.h"

Mppt::Mppt(QCanBusDevice* canDevice, const unsigned int idOffset) : IPacket(canDevice) {
    timerData_ = {
        {0x600 + idOffset, {200, [this, idOffset]() { sendDataMessage(0x600 + idOffset); }}}
    };

    initAndStartTimers();
}
