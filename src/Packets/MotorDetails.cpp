#include "MotorDetails.h"

MotorDetails::MotorDetails(QCanBusDevice* canDevice) : IPacket(canDevice) {
    timerData_ = {
        {0x420, {500, [this]() { sendIdInfoMessage(); }}},
        {0x421, {500, [this]() { sendStatusMessage(); }}},
        {0x422, {500, [this]() { sendBusMeasurementMessage(); }}},
        {0x423, {500, [this]() { sendVelocityMeasurementMessage(); }}},
        {0x424, {500, [this]() { sendPhaseCurrentMeasurementMessage(); }}},
        {0x425, {500, [this]() { sendMotorVoltageVectorMeasurementMessage(); }}},
        {0x426, {500, [this]() { sendMotorCurrentVectorMeasurementMessage(); }}},
        {0x427, {500, [this]() { sendMotorBackEmfMeasurementPredictionMessage(); }}},
        {0x428, {500, [this]() { sendVoltageRail15VMeasurementMessage(); }}},
        {0x429, {500, [this]() { sendVoltageRail3V31V9MeasurementMessage(); }}},
        {0x42A, {500, [this]() { sendReserved0AMessage(); }}},
        {0x42B, {500, [this]() { sendHeatsinkMotorTempMeasurementMessage(); }}},
        {0x42C, {500, [this]() { sendDspBoardTempMeasurementMessage(); }}},
        {0x42D, {500, [this]() { sendReserved0DMessage(); }}},
        {0x42E, {500, [this]() { sendOdometerBusAhMeasurementMessage(); }}},
        {0x437, {500, [this]() { sendSlipSpeedMeasurementMessage(); }}}
    };

    initAndStartTimers();
}
