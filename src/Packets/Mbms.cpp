#include "Mbms.h"

Mbms::Mbms(QCanBusDevice* canDevice) : IPacket(canDevice) {
    timerData_ = {
        {0x101, {500, [this]() { sendCanMessage<unsigned char>(0x101, getContactorCommand()); }}},
        {0x102, {500, [this]() { sendCanMessage<unsigned int>(0x102, getStatus()); }}},
        {0x103, {500, [this]() { sendCanMessage<unsigned short>(0x103, getPowerSelectionStatus()); }}},
        {0x104, {500, [this]() { sendCanMessage<unsigned int>(0x104, getTrip()); }}},
        {0x105, {500, [this]() { sendCanMessage<unsigned short>(0x105, getSoftBatteryLimitWarning()); }}}
    };

    initAndStartTimers();
}
