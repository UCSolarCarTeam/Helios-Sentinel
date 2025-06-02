#include "B3.h"

B3::B3(QCanBusDevice* canDevice) : IPacket(canDevice) {
    timerData_ = {
        {0x610, {100, [this]() { sendLightsInputsMessage(); }}},
        {0x611, {50, [this]() { sendDigitalInputsMessage(); }}},
        {0x612, {50, [this]() { sendAnalogInputsMessage(); }}},
        {0x620, {200, [this]() { sendLightsStatusMessage(); }}}
    };

    initAndStartTimers();
}
