#include "Mppt.h"

Mppt::Mppt(QCanBusDevice* canDevice) : IPacket(canDevice) {
    timerData_ = {
        {0x600, {200, [this]() { sendM0C0Message(0x600); }}},
        {0x601, {200, [this]() { sendM0C1Message(0x601); }}},
        {0x602, {200, [this]() { sendM1C0Message(0x602); }}},
        {0x603, {200, [this]() { sendM1C1Message(0x603); }}},
        {0x604, {200, [this]() { sendM2C0Message(0x604); }}},
        {0x605, {200, [this]() { sendM2C1Message(0x605); }}},
        {0x606, {200, [this]() { sendM3C0Message(0x606); }}},
        {0x607, {200, [this]() { sendM3C1Message(0x607); }}}
    };

    initAndStartTimers();
}
