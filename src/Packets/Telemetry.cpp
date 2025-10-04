#include "Telemetry.h"

Telemetry::Telemetry(QCanBusDevice* canDevice) : IPacket(canDevice) {
    timerData_ = {
        {0x630, {500, [this]() { sendGpsTimeMessage(0x630); }}},
        {0x631, {500, [this]() { sendGpsFlagsMessage(0x631); }}},
        {0x632, {500, [this]() { sendGpsPositionMessage(0x632); }}},
        {0x633, {500, [this]() { sendMpuAccelerationMessage(0x633); }}},
        {0x634, {500, [this]() { sendMpuGyroscopeMessage(0x634); }}},
        {0x635, {500, [this]() { sendMpuTemperatureMessage(0x635); }}}
    };

    initAndStartTimers();
}
