#include "MotorDetails.h"
#include "util.h"

#include <QIODevice>
#include <QDebug>

MotorDetails::MotorDetails(int motor, QObject *parent)
    : QObject{parent}
{
    byteStream_.fill(0x00, 37); // packet size 37 - fill zeros by defualt
    byteStream_[0] = 0x25;      // packet size 37
    motorNum_ = motor;
    QByteArray motorID = Util::formatInt(motor + 2, 1);
    byteStream_[1] = motorID[0];
    updateByteStream();         //generate checksum and encode empty packet
}

int MotorDetails::motorNum() const { return motorNum_; }

short MotorDetails::controlValue() const { return controlValue_; }
bool MotorDetails::controlMode() const { return controlMode_; }
bool MotorDetails::motorMode() const { return motorMode_; }
bool MotorDetails::softwareEnable() const { return softwareEnable_; }
bool MotorDetails::debugMode() const { return debugMode_; }
short MotorDetails::currentMotorTorque() const { return currentMotorTorque_; }
short MotorDetails::currentRpmValue() const { return currentRpmValue_; }
char MotorDetails::motorTemperature() const { return motorTemperature_; }
short MotorDetails::inverterPeakCurrent() const { return inverterPeakCurrent_; }
short MotorDetails::currentMotorPower() const { return currentMotorPower_; }
unsigned short MotorDetails::absoluteAngle() const { return absoluteAngle_; }
bool MotorDetails::motorAboutToStall() const { return motorAboutToStall_; }
bool MotorDetails::delayInReadingTempSensor() const { return delayInReadingTempSensor_; }
bool MotorDetails::delayInReadingPosSensor() const { return delayInReadingPosSensor_; }
bool MotorDetails::inverter1TempVeryHigh() const { return inverter1TempVeryHigh_; }
bool MotorDetails::inverter2TempVeryHigh() const { return inverter2TempVeryHigh_; }
bool MotorDetails::inverter3TempVeryHigh() const { return inverter3TempVeryHigh_; }
bool MotorDetails::inverter4TempVeryHigh() const { return inverter4TempVeryHigh_; }
bool MotorDetails::inverter5TempVeryHigh() const { return inverter5TempVeryHigh_; }
bool MotorDetails::inverter6TempVeryHigh() const { return inverter6TempVeryHigh_; }
bool MotorDetails::cpuTemperatureVeryHigh() const { return cpuTemperatureVeryHigh_; }
bool MotorDetails::hallTemperatureVeryHigh() const { return hallTemperatureVeryHigh_; }
bool MotorDetails::dclinkTemperatureVeryHigh() const { return dclinkTemperatureVeryHigh_; }
bool MotorDetails::delayInDclinkCommunication() const { return delayInDclinkCommunication_; }
bool MotorDetails::inverter1OverCurrent() const { return inverter1OverCurrent_; }
bool MotorDetails::inverter2OverCurrent() const { return inverter2OverCurrent_; }
bool MotorDetails::inverter3OverCurrent() const { return inverter3OverCurrent_; }
bool MotorDetails::inverter4OverCurrent() const { return inverter4OverCurrent_; }
bool MotorDetails::inverter5OverCurrent() const { return inverter5OverCurrent_; }
bool MotorDetails::inverter6OverCurrent() const { return inverter6OverCurrent_; }
bool MotorDetails::dcOvervoltageWarning() const { return dcOvervoltageWarning_; }
bool MotorDetails::dcUndervoltageWarning() const { return dcUndervoltageWarning_; }
bool MotorDetails::canCommsTimeout() const { return canCommsTimeout_; }
bool MotorDetails::inverter1FaultWarning() const { return inverter1FaultWarning_; }
bool MotorDetails::inverter2FaultWarning() const { return inverter2FaultWarning_; }
bool MotorDetails::inverter3FaultWarning() const { return inverter3FaultWarning_; }
bool MotorDetails::inverter4FaultWarning() const { return inverter4FaultWarning_; }
bool MotorDetails::inverter5FaultWarning() const { return inverter5FaultWarning_; }
bool MotorDetails::inverter6FaultWarning() const { return inverter6FaultWarning_; }
bool MotorDetails::canSendWarning() const { return canSendWarning_; }
bool MotorDetails::lostFramesOnCanBusWarning() const { return lostFramesOnCanBusWarning_; }
bool MotorDetails::overspeedWarning() const { return overspeedWarning_; }
bool MotorDetails::cpuOverload() const { return cpuOverload_; }
bool MotorDetails::torqueLimited() const { return torqueLimited_; }
bool MotorDetails::startAtHighRpm() const { return startAtHighRpm_; }
bool MotorDetails::initError() const { return initError_; }
bool MotorDetails::settingsNotFound() const { return settingsNotFound_; }
bool MotorDetails::motorStalled() const { return motorStalled_; }
bool MotorDetails::controllerDataReadingTimeout() const { return controllerDataReadingTimeout_; }
bool MotorDetails::invalidHallSensorSequence() const { return invalidHallSensorSequence_; }
bool MotorDetails::invalidHallSector() const { return invalidHallSector_; }
bool MotorDetails::errorReadingTempSensor() const { return errorReadingTempSensor_; }
bool MotorDetails::positionSensorReadingError() const { return positionSensorReadingError_; }
bool MotorDetails::errorReadingEncoder() const { return errorReadingEncoder_; }
bool MotorDetails::zeroPositionOffsetNotSet() const { return zeroPositionOffsetNotSet_; }
bool MotorDetails::hwEnableNotSet() const { return hwEnableNotSet_; }
bool MotorDetails::inverter1TempTooHigh() const { return inverter1TempTooHigh_; }
bool MotorDetails::inverter2TempTooHigh() const { return inverter2TempTooHigh_; }
bool MotorDetails::inverter3TempTooHigh() const { return inverter3TempTooHigh_; }
bool MotorDetails::inverter4TempTooHigh() const { return inverter4TempTooHigh_; }
bool MotorDetails::inverter5TempTooHigh() const { return inverter5TempTooHigh_; }
bool MotorDetails::inverter6TempTooHigh() const { return inverter6TempTooHigh_; }
bool MotorDetails::cpuTemperatureTooHigh() const { return cpuTemperatureTooHigh_; }
bool MotorDetails::hallTemperatureTooHigh() const { return hallTemperatureTooHigh_; }
bool MotorDetails::dclinkTemperatureTooHigh() const { return dclinkTemperatureTooHigh_; }
bool MotorDetails::errorInDclinkCommunication() const { return errorInDclinkCommunication_; }
bool MotorDetails::inverter1Overcurrent() const { return inverter1Overcurrent_; }
bool MotorDetails::inverter2Overcurrent() const { return inverter2Overcurrent_; }
bool MotorDetails::inverter3Overcurrent() const { return inverter3Overcurrent_; }
bool MotorDetails::inverter4Overcurrent() const { return inverter4Overcurrent_; }
bool MotorDetails::inverter5Overcurrent() const { return inverter5Overcurrent_; }
bool MotorDetails::inverter6Overcurrent() const { return inverter6Overcurrent_; }
bool MotorDetails::dcOvervoltageError() const { return dcOvervoltageError_; }
bool MotorDetails::dcUndervoltageError() const { return dcUndervoltageError_; }
bool MotorDetails::doubleCanCommsTimeout() const { return doubleCanCommsTimeout_; }
bool MotorDetails::inverter1FaultError() const { return inverter1FaultError_; }
bool MotorDetails::inverter2FaultError() const { return inverter2FaultError_; }
bool MotorDetails::inverter3FaultError() const { return inverter3FaultError_; }
bool MotorDetails::inverter4FaultError() const { return inverter4FaultError_; }
bool MotorDetails::inverter5FaultError() const { return inverter5FaultError_; }
bool MotorDetails::inverter6FaultError() const { return inverter6FaultError_; }
bool MotorDetails::canSendError() const { return canSendError_; }
bool MotorDetails::lostFramesOnCanBusError() const { return lostFramesOnCanBusError_; }
bool MotorDetails::overspeedError() const { return overspeedError_; }
bool MotorDetails::cpuOverloaded() const { return cpuOverloaded_; }
bool MotorDetails::canCommsTimeoutError() const { return canCommsTimeoutError_; }


QByteArray MotorDetails::encodedByteStream() const { return encodedByteStream_; }

void MotorDetails::setControlValue(short newControlValue) {
    QByteArray in = Util::formatInt(newControlValue,2);
    byteStream_.replace(2, 2, in);
    controlValue_ = newControlValue;
    updateByteStream();
}

void MotorDetails::setControlMode(bool status) {
    byteStream_[4] += status ? 0x01: -0x01;
    controlMode_ = status;
    updateByteStream();
}

void MotorDetails::setMotorMode(bool status) {
    byteStream_[4] += status ? 0x02: -0x02;
    motorMode_ = status;
    updateByteStream();
}

void MotorDetails::setSoftwareEnable(bool status) {
    byteStream_[4] += status ? 0x04: -0x04;
    softwareEnable_ = status;
    updateByteStream();
}

void MotorDetails::setDebugMode(bool status) {
    byteStream_[4] += status ? 0x08: -0x08;
    debugMode_ = status;
    updateByteStream();
}

void MotorDetails::setCurrentMotorTorque(short newCurrentMotorTorque) {
    QByteArray in = Util::formatInt(newCurrentMotorTorque,2);
    byteStream_.replace(5, 2, in);
    currentMotorTorque_ = newCurrentMotorTorque;
    updateByteStream();
}

void MotorDetails::setCurrentRpmValue(short newCurrentRpmValue) {
    QByteArray in = Util::formatInt(newCurrentRpmValue,2);
    byteStream_.replace(7, 2, in);
    currentRpmValue_ = newCurrentRpmValue;
    updateByteStream();
}

void MotorDetails::setMotorTemperature(char newMotorTemperature) {
    byteStream_[9] = newMotorTemperature;
    motorTemperature_ = newMotorTemperature;
    updateByteStream();
}

void MotorDetails::setInverterPeakCurrent(short newInverterPeakCurrent) {
    QByteArray in = Util::formatInt(newInverterPeakCurrent,2);
    byteStream_.replace(10, 2, in);
    inverterPeakCurrent_ = newInverterPeakCurrent;
    updateByteStream();
}

void MotorDetails::setCurrentMotorPower(short newCurrentMotorPower) {
    QByteArray in = Util::formatInt(newCurrentMotorPower,2);
    byteStream_.replace(12, 2, in);
    currentMotorPower_ = newCurrentMotorPower;
    updateByteStream();
}

void MotorDetails::setAbsoluteAngle(unsigned short newAbsoluteAngle) {
    QByteArray in = Util::formatInt(newAbsoluteAngle,2);
    byteStream_.replace(14, 2, in);
    absoluteAngle_ = newAbsoluteAngle;
    updateByteStream();
}

void MotorDetails::setMotorAboutToStall(bool status) {
    byteStream_[16] += status ? 0x01:-0x01;
    motorAboutToStall_ = status;
    updateByteStream();

}

void MotorDetails::setDelayInReadingTempSensor(bool status) {
    byteStream_[16] += status ? 0x02:-0x02;
    delayInReadingTempSensor_ = status;
    updateByteStream();
}

void MotorDetails::setDelayInReadingPosSensor(bool status) {
    byteStream_[16] += status ? 0x04:-0x04;
    delayInReadingPosSensor_ = status;
    updateByteStream();
}

void MotorDetails::setInverter1TempVeryHigh(bool status) {
    byteStream_[16] += status ? 0x08:-0x08;
    inverter1TempVeryHigh_ = status;
    updateByteStream();
}

void MotorDetails::setInverter2TempVeryHigh(bool status) {
    byteStream_[17] += status ? 0x10:-0x10;
    inverter2TempVeryHigh_ = status;
    updateByteStream();
}

void MotorDetails::setInverter3TempVeryHigh(bool status) {
    byteStream_[17] += status ? 0x20:-0x20;
    inverter3TempVeryHigh_ = status;
    updateByteStream();
}


void MotorDetails::setInverter4TempVeryHigh(bool status) {
    byteStream_[17] += status ? 0x40:-0x40;
    inverter4TempVeryHigh_ = status;
    updateByteStream();
}

void MotorDetails::setInverter5TempVeryHigh(bool status) {
    byteStream_[17] += status ? 0x80:-0x80;
    inverter5TempTooHigh_ = status;
    updateByteStream();
}

void MotorDetails::setInverter6TempVeryHigh(bool status) {
    byteStream_[18] += status ? 0x01:-0x01;
    inverter6TempTooHigh_ = status;
    updateByteStream();
}

void MotorDetails::setCpuTemperatureVeryHigh(bool status) {
    byteStream_[18] += status ? 0x02:-0x02;
    cpuTemperatureVeryHigh_ = status;
    updateByteStream();
}

void MotorDetails::setHallTemperatureVeryHigh(bool status) {
    byteStream_[18] += status ? 0x04:-0x04;
    hallTemperatureVeryHigh_ = status;
    updateByteStream();
}

void MotorDetails::setDclinkTemperatureVeryHigh(bool status) {
    byteStream_[18] += status ? 0x08:-0x08;
    dclinkTemperatureVeryHigh_ = status;
    updateByteStream();
}

void MotorDetails::setDelayInDclinkCommunication(bool status) {
    byteStream_[19] += status ? 0x10:-0x10;
    delayInDclinkCommunication_ = status;
    updateByteStream();
}

void MotorDetails::setInverter1OverCurrent(bool status) {
    byteStream_[19] += status ? 0x20:-0x20;
    inverter1OverCurrent_ = status;
    updateByteStream();
}

void MotorDetails::setInverter2OverCurrent(bool status) {
    byteStream_[19] += status ? 0x40:-0x40;
    inverter2OverCurrent_ = status;
    updateByteStream();
}

void MotorDetails::setInverter3OverCurrent(bool status) {
    byteStream_[19] += status ? 0x80:-0x80;
    inverter3OverCurrent_ = status;
    updateByteStream();
}

void MotorDetails::setInverter4OverCurrent(bool status) {
    byteStream_[20] += status ? 0x01:-0x01;
    inverter4OverCurrent_ = status;
    updateByteStream();
}

void MotorDetails::setInverter5OverCurrent(bool status) {
    byteStream_[20] += status ? 0x02:-0x02;
    inverter5OverCurrent_ = status;
    updateByteStream();
}

void MotorDetails::setInverter6OverCurrent(bool status) {
    byteStream_[20] += status ? 0x04:-0x04;
    inverter6OverCurrent_ = status;
    updateByteStream();
}

void MotorDetails::setDcOvervoltageWarning(bool status) {
    byteStream_[20] += status ? 0x08:-0x08;
    dcOvervoltageWarning_ = status;
    updateByteStream();
}

void MotorDetails::setDcUndervoltageWarning(bool status) {
    byteStream_[21] += status ? 0x10:-0x10;
    dcUndervoltageWarning_ = status;
    updateByteStream();
}

void MotorDetails::setCanCommsTimeout(bool status) {
    byteStream_[21] += status ? 0x20:-0x20;
    canCommsTimeout_ = status;
    updateByteStream();
}

void MotorDetails::setInverter1FaultWarning(bool status) {
    byteStream_[21] += status ? 0x40:-0x40;
    inverter1FaultWarning_ = status;
    updateByteStream();
}

void MotorDetails::setInverter2FaultWarning(bool status) {
    byteStream_[21] += status ? 0x80:-0x80;
    inverter2FaultWarning_ = status;
    updateByteStream();
}

void MotorDetails::setInverter3FaultWarning(bool status) {
    byteStream_[22] += status ? 0x01:-0x01;
    inverter3FaultWarning_ = status;
    updateByteStream();
}


void MotorDetails::setInverter4FaultWarning(bool status) {
    byteStream_[22] += status ? 0x02:-0x02;
    inverter4FaultWarning_ = status;
    updateByteStream();
}

void MotorDetails::setInverter5FaultWarning(bool status) {
    byteStream_[22] += status ? 0x04:-0x04;
    inverter5FaultWarning_ = status;
    updateByteStream();
}

void MotorDetails::setInverter6FaultWarning(bool status) {
    byteStream_[22] += status ? 0x08:-0x08;
    inverter6FaultWarning_ = status;
    updateByteStream();
}

void MotorDetails::setCanSendWarning(bool status) {
    byteStream_[23] += status ? 0x10:-0x10;
    canSendWarning_ = status;
    updateByteStream();
}

void MotorDetails::setLostFramesOnCanBusWarning(bool status) {
    byteStream_[23] += status ? 0x20:-0x20;
    lostFramesOnCanBusWarning_ = status;
    updateByteStream();
}

void MotorDetails::setOverspeedWarning(bool status) {
    byteStream_[23] += status ? 0x40:-0x40;
    overspeedWarning_ = status;
    updateByteStream();
}

void MotorDetails::setCpuOverload(bool status) {
    byteStream_[23] += status ? 0x80:-0x80;
    cpuOverload_ = status;
    updateByteStream();
}

void MotorDetails::setTorqueLimited(bool status) {
    byteStream_[24] += status ? 0x01:-0x01;
    torqueLimited_ = status;
    updateByteStream();
}

void MotorDetails::setStartAtHighRpm(bool status) {
    byteStream_[24] += status ? 0x02:-0x02;
    startAtHighRpm_ = status;
    updateByteStream();
}

void MotorDetails::setInitError(bool status) {
    byteStream_[25] += status ? 0x01:-0x01;
    initError_ = status;
    updateByteStream();
}

void MotorDetails::setSettingsNotFound(bool status) {
    byteStream_[25] += status ? 0x02:-0x02;
    settingsNotFound_ = status;
    updateByteStream();
}

void MotorDetails::setMotorStalled(bool status) {
    byteStream_[25] += status ? 0x04:-0x04;
    motorStalled_ = status;
    updateByteStream();
}


void MotorDetails::setControllerDataReadingTimeout(bool status) {
    byteStream_[25] += status ? 0x08:-0x08;
    controllerDataReadingTimeout_ = status;
    updateByteStream();
}

void MotorDetails::setInvalidHallSensorSequence(bool status) {
    byteStream_[26] += status ? 0x10:-0x10;
    invalidHallSensorSequence_ = status;
    updateByteStream();
}

void MotorDetails::setInvalidHallSector(bool status) {
    byteStream_[26] += status ? 0x20:-0x20;
    invalidHallSector_ = status;
    updateByteStream();
}

void MotorDetails::setErrorReadingTempSensor(bool status) {
    byteStream_[26] += status ? 0x40:-0x40;
    errorReadingTempSensor_ = status;
    updateByteStream();
}

void MotorDetails::setPositionSensorReadingError(bool status) {
    byteStream_[26] += status ? 0x80:-0x80;
    positionSensorReadingError_ = status;
    updateByteStream();
}

void MotorDetails::setErrorReadingEncoder(bool status) {
    byteStream_[27] += status ? 0x01:-0x01;
    errorReadingEncoder_ = status;
    updateByteStream();
}

void MotorDetails::setZeroPositionOffsetNotSet(bool status) {
    byteStream_[27] += status ? 0x02:-0x02;
    zeroPositionOffsetNotSet_ = status;
    updateByteStream();
}

void MotorDetails::setHwEnableNotSet(bool status) {
    byteStream_[27] += status ? 0x04:-0x04;
    hwEnableNotSet_ = status;
    updateByteStream();
}

void MotorDetails::setInverter1TempTooHigh(bool status) {
    byteStream_[27] += status ? 0x08:-0x08;
    inverter1TempTooHigh_ = status;
    updateByteStream();
}

void MotorDetails::setInverter2TempTooHigh(bool status) {
    byteStream_[28] += status ? 0x10:-0x10;
    inverter2TempTooHigh_ = status;
    updateByteStream();
}

void MotorDetails::setInverter3TempTooHigh(bool status) {
    byteStream_[28] += status ? 0x20:-0x20;
    inverter3TempTooHigh_ = status;
    updateByteStream();
}

void MotorDetails::setInverter4TempTooHigh(bool status) {
    byteStream_[28] += status ? 0x40:-0x40;
    inverter4TempTooHigh_ = status;
    updateByteStream();
}

void MotorDetails::setInverter5TempTooHigh(bool status) {
    byteStream_[28] += status ? 0x80:-0x80;
    inverter5TempTooHigh_ = status;
    updateByteStream();
}

void MotorDetails::setInverter6TempTooHigh(bool status) {
    byteStream_[29] += status ? 0x01:-0x01;
    inverter6TempTooHigh_ = status;
    updateByteStream();
}

void MotorDetails::setCpuTemperatureTooHigh(bool status) {
    byteStream_[29] += status ? 0x02:-0x02;
    cpuTemperatureTooHigh_ = status;
    updateByteStream();
}

void MotorDetails::setHallTemperatureTooHigh(bool status) {
    byteStream_[29] += status ? 0x04:-0x04;
    hallTemperatureTooHigh_ = status;
    updateByteStream();
}

void MotorDetails::setDclinkTemperatureTooHigh(bool status) {
    byteStream_[29] += status ? 0x08:-0x08;
    dclinkTemperatureTooHigh_ = status;
    updateByteStream();
}

void MotorDetails::setErrorInDclinkCommunication(bool status) {
    byteStream_[30] += status ? 0x10:-0x10;
    errorInDclinkCommunication_ = status;
    updateByteStream();
}

void MotorDetails::setInverter1Overcurrent(bool status) {
    byteStream_[30] += status ? 0x20:-0x20;
    inverter1OverCurrent_ = status;
    updateByteStream();
}

void MotorDetails::setInverter2Overcurrent(bool status) {
    byteStream_[30] += status ? 0x40:-0x40;
    inverter2OverCurrent_ = status;
    updateByteStream();
}

void MotorDetails::setInverter3Overcurrent(bool status) {
    byteStream_[30] += status ? 0x80:-0x80;
    inverter3OverCurrent_ = status;
    updateByteStream();
}
void MotorDetails::setInverter4Overcurrent(bool status) {
    byteStream_[31] += status ? 0x01:-0x01;
    inverter4OverCurrent_ = status;
    updateByteStream();
}

void MotorDetails::setInverter5Overcurrent(bool status) {
    byteStream_[31] += status ? 0x02:-0x02;
    inverter5OverCurrent_ = status;
    updateByteStream();
}

void MotorDetails::setInverter6Overcurrent(bool status) {
    byteStream_[31] += status ? 0x04:-0x04;
    inverter6OverCurrent_ = status;
    updateByteStream();
}

void MotorDetails::setDcOvervoltageError(bool status) {
    byteStream_[31] += status ? 0x08:-0x08;
    dcOvervoltageError_ = status;
    updateByteStream();
}

void MotorDetails::setDcUndervoltageError(bool status) {
    byteStream_[31] += status ? 0x10:-0x10;
    dcUndervoltageError_ = status;
    updateByteStream();
}

void MotorDetails::setDoubleCanCommsTimeout(bool status) {
    byteStream_[31] += status ? 0x20:-0x20;
    doubleCanCommsTimeout_ = status;
    updateByteStream();
}
void MotorDetails::setCanCommsTimeoutError(bool status) {
    byteStream_[31] += status ? 0x40:-0x40;
    canCommsTimeoutError_ = status;
    updateByteStream();
}

void MotorDetails::setInverter1FaultError(bool status) {
    byteStream_[31] += status ? 0x80:-0x80;
    inverter1FaultError_ = status;
    updateByteStream();
}

void MotorDetails::setInverter2FaultError(bool status) {
    byteStream_[32] += status ? 0x01:-0x01;
    inverter2FaultError_ = status;
    updateByteStream();
}

void MotorDetails::setInverter3FaultError(bool status) {
    byteStream_[32] += status ? 0x02:-0x02;
    inverter3FaultError_ = status;
    updateByteStream();
}

void MotorDetails::setInverter4FaultError(bool status) {
    byteStream_[32] += status ? 0x04:-0x04;
    inverter4FaultError_ = status;
    updateByteStream();
}

void MotorDetails::setInverter5FaultError(bool status) {
    byteStream_[32] += status ? 0x08:-0x08;
    inverter5FaultError_ = status;
    updateByteStream();
}

void MotorDetails::setInverter6FaultError(bool status) {
    byteStream_[32] += status ? 0x10:-0x10;
    inverter6FaultError_ = status;
    updateByteStream();
}

void MotorDetails::setCanSendError(bool status) {
    byteStream_[32] += status ? 0x20:-0x20;
    canSendError_ = status;
    updateByteStream();
}

void MotorDetails::setLostFramesOnCanBusError(bool status) {
    byteStream_[32] += status ? 0x40:-0x40;
    lostFramesOnCanBusError_ = status;
    updateByteStream();
}

void MotorDetails::setOverspeedError(bool status) {
    byteStream_[32] += status ? 0x80:-0x80;
    overspeedError_ = status;
    updateByteStream();
}

void MotorDetails::setCpuOverloaded(bool status) {
    byteStream_[33] = status ? 0x01: 0x00;
    cpuOverloaded_ = status;
    updateByteStream();
}

void MotorDetails::setMotorNum(int value) {
    motorNum_ = value;
}

void MotorDetails::updateByteStream(){
    // (1, size - 4)
    QByteArray checksum = Util::generateChecksum(byteStream_, 1, 33);
    // size - 3 and size - 2
    byteStream_[34] = checksum.at(0);
    byteStream_[35] = checksum.at(1);
    encodedByteStream_ = Util::encodeByteStream(byteStream_);
    emit encodedByteStreamStrChanged();
    emit byteStreamStrChanged();
}

QString MotorDetails::encodedByteStreamStr() const {
    return(encodedByteStream_.toHex(' '));
}

QString MotorDetails::byteStreamStr() const {
    return QString(byteStream_.toHex(' '));
}



