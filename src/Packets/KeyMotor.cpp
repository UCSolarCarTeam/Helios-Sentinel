#include "KeyMotor.h"

KeyMotor::KeyMotor(QCanBusDevice* canDevice) : IPacket(canDevice) {
    timerData_ = {
        {0x550, {100, [this]() { sendControlValueMessage(); }}},
        {0x551, {100, [this]() { sendMiscStatusMessage(); }}}
    };

    initAndStartTimers();
}
