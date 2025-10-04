#include "KeyMotor.h"

KeyMotor::KeyMotor(QCanBusDevice* canDevice) : IPacket(canDevice) {
    timerData_ = {
        {0x501, {100, [this]() { sendDriveCommandMessage(); }}},
        {0x502, {100, [this]() { sendPowerCommandMessage(); }}}
    };

    initAndStartTimers();
}
