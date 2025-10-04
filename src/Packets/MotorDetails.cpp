#include "MotorDetails.h"

MotorDetails::MotorDetails(QCanBusDevice* canDevice, const unsigned int idOffset) : IPacket(canDevice) {
    timerData_ = {
        {0x420 + idOffset, {500, [this, idOffset]() { sendIdInfoMessage(0x420 + idOffset); }}},
        {0x421 + idOffset, {500, [this, idOffset]() { sendStatusMessage(0x421 + idOffset); }}},
        {0x422 + idOffset, {500, [this, idOffset]() { sendBusMeasurementMessage(0x422 + idOffset); }}},
        {0x423 + idOffset, {500, [this, idOffset]() { sendVelocityMeasurementMessage(0x423 + idOffset); }}},
        {0x424 + idOffset, {500, [this, idOffset]() { sendPhaseCurrentMeasurementMessage(0x424 + idOffset); }}},
        {0x425 + idOffset, {500, [this, idOffset]() { sendMotorVoltageVectorMeasurementMessage(0x425 + idOffset); }}},
        {0x426 + idOffset, {500, [this, idOffset]() { sendMotorCurrentVectorMeasurementMessage(0x426 + idOffset); }}},
        {0x427 + idOffset, {500, [this, idOffset]() { sendMotorBackEmfMeasurementPredictionMessage(0x427 + idOffset); }}},
        {0x428 + idOffset, {500, [this, idOffset]() { sendVoltageRail15VMeasurementMessage(0x428 + idOffset); }}},
        {0x429 + idOffset, {500, [this, idOffset]() { sendVoltageRail3V31V9MeasurementMessage(0x429 + idOffset); }}},
        {0x42A + idOffset, {500, [this, idOffset]() { sendReserved0AMessage(0x42A + idOffset); }}},
        {0x42B + idOffset, {500, [this, idOffset]() { sendHeatsinkMotorTempMeasurementMessage(0x42B + idOffset); }}},
        {0x42C + idOffset, {500, [this, idOffset]() { sendDspBoardTempMeasurementMessage(0x42C + idOffset); }}},
        {0x42D + idOffset, {500, [this, idOffset]() { sendReserved0DMessage(0x42D + idOffset); }}},
        {0x42E + idOffset, {500, [this, idOffset]() { sendOdometerBusAhMeasurementMessage(0x42E + idOffset); }}},
        {0x437 + idOffset, {500, [this, idOffset]() { sendSlipSpeedMeasurementMessage(0x437 + idOffset); }}}
    };

    initAndStartTimers();
}
