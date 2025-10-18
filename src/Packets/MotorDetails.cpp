#include "MotorDetails.h"

MotorDetails::MotorDetails(QCanBusDevice* canDevice, const unsigned int idOffset) : IPacket(canDevice) {
    timerData_ = {
        {0x400 + idOffset, {500, [this, idOffset]() { sendIdInfoMessage(0x400 + idOffset); }}},
        {0x401 + idOffset, {500, [this, idOffset]() { sendStatusMessage(0x401 + idOffset); }}},
        {0x402 + idOffset, {500, [this, idOffset]() { sendBusMeasurementMessage(0x402 + idOffset); }}},
        {0x403 + idOffset, {500, [this, idOffset]() { sendVelocityMeasurementMessage(0x403 + idOffset); }}},
        {0x404 + idOffset, {500, [this, idOffset]() { sendPhaseCurrentMeasurementMessage(0x404 + idOffset); }}},
        {0x405 + idOffset, {500, [this, idOffset]() { sendMotorVoltageVectorMeasurementMessage(0x405 + idOffset); }}},
        {0x406 + idOffset, {500, [this, idOffset]() { sendMotorCurrentVectorMeasurementMessage(0x406 + idOffset); }}},
        {0x407 + idOffset, {500, [this, idOffset]() { sendMotorBackEmfMeasurementPredictionMessage(0x407 + idOffset); }}},
        {0x408 + idOffset, {500, [this, idOffset]() { sendVoltageRail15VMeasurementMessage(0x408 + idOffset); }}},
        {0x409 + idOffset, {500, [this, idOffset]() { sendVoltageRail3V31V9MeasurementMessage(0x409 + idOffset); }}},
        {0x40A + idOffset, {500, [this, idOffset]() { sendReserved0AMessage(0x40A + idOffset); }}},
        {0x40B + idOffset, {500, [this, idOffset]() { sendHeatsinkMotorTempMeasurementMessage(0x40B + idOffset); }}},
        {0x40C + idOffset, {500, [this, idOffset]() { sendDspBoardTempMeasurementMessage(0x40C + idOffset); }}},
        {0x40D + idOffset, {500, [this, idOffset]() { sendReserved0DMessage(0x40D + idOffset); }}},
        {0x40E + idOffset, {500, [this, idOffset]() { sendOdometerBusAhMeasurementMessage(0x40E + idOffset); }}},
        {0x417 + idOffset, {500, [this, idOffset]() { sendSlipSpeedMeasurementMessage(0x417 + idOffset); }}}
    };

    initAndStartTimers();
}
