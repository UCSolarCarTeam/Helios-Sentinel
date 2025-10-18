#include "BatteryFaults.h"

BatteryFaults::BatteryFaults(QCanBusDevice* canDevice) : IPacket(canDevice) {
    timerData_ = {
        {0x303, {512, [this]() { sendCanMessage<unsigned long long>(0x303, getErrors()); }}}
    };

    initAndStartTimers();
}
