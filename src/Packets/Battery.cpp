#include "Battery.h"

Battery::Battery(QCanBusDevice* canDevice) : IPacket(canDevice) {
    timerData_ = {
        {0x301, {200, [this]() { sendStartupInfoMessage(); }}},
        {0x302, {1000, [this]() { sendPackInfoMessage(); }}},
        {0x304, {200, [this]() { sendTempInfoMessage(); }}},
        {0x305, {200, [this]() { sendCellVoltagesMessage(); }}},
        {0x30A, {2000, [this]() { sendMaxMinVoltagesMessage(); }}}
    };

    initAndStartTimers();
}
