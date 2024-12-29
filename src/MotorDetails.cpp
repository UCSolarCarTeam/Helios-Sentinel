#include "MotorDetails.h"
#include "util.h"

#include <QIODevice>
#include <QDebug>

MotorDetails::MotorDetails(int motor, QObject *parent)
    : QObject{parent}
{
    byteStream_.fill(0x00, 37);
    byteStream_[0] = 0x21;
    if(motor) byteStream_[1] = 0x03; // motor 1
    else byteStream_[1] = 0x02; // motor 0
    updateByteStream();         //generate checksum and encode empty packet
}


void MotorDetails::updateByteStream(){
    // (1, size - 4)
    QByteArray checksum = Util::generateChecksum(byteStream_, 1, 29);
    // size - 3 and size - 2
    byteStream_[33] = checksum.at(0);
    byteStream_[34] = checksum.at(1);
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

void MotorDetails::setControlValue(short controlValue) {
    QByteArray in = Util::formatInt(controlValue, 2);
    byteStream_.replace(2, 2, in);
    controlValue_ = controlValue;
    updateByteStream();
}

void MotorDetails::setControlMode(bool mode) {
    byteStream_[4] = mode ? 0x01 : -0x01;
    controlMode_ = mode;
    updateByteStream();
}

void MotorDetails::setMotorMode(bool mode) {
    byteStream_[4] = mode ? 0x02 : -0x02;
    motorMode_ = mode;
    updateByteStream();
}

void MotorDetails::setSoftwareEnable(bool enable) {
    byteStream_[4] = enable ? 0x04 : -0x04;
    softwareEnable_ = enable;
    updateByteStream();
}

void MotorDetails::setDebugMode(bool mode) {
    byteStream_[4] = mode ? 0x08 : -0x08;
    debugMode_ = mode;
    updateByteStream();
}

void MotorDetails::setCurrentMotorTorque(short torque) {
    QByteArray in = Util::formatInt(torque, 2);
    byteStream_.replace(5, 2, in);
    currentMotorTorque_ = torque;
    updateByteStream();
}

void MotorDetails::setCurrentRpmValue(short rpm) {
    QByteArray in = Util::formatInt(rpm, 2);
    byteStream_.replace(7, 2, in);
    currentRpmValue_ = rpm;
    updateByteStream();
}

void MotorDetails::setMotorTemperature(char temp) {
    byteStream_[9] = temp;
    motorTemperature_ = temp;
    updateByteStream();
}

void MotorDetails::setInverterPeakCurrent(short current) {
    QByteArray in = Util::formatInt(current, 2);
    byteStream_.replace(10, 2, in);
    inverterPeakCurrent_ = current;
    updateByteStream();
}

void MotorDetails::setCurrentMotorPower(short power) {
    QByteArray in = Util::formatInt(power, 2);
    byteStream_.replace(12, 2, in);
    currentMotorPower_ = power;
    updateByteStream();
}

void MotorDetails::setAbsuluteAngle(unsigned short angle) {
    QByteArray in = Util::formatInt(angle, 2);
    byteStream_.replace(14, 2, in);
    absuluteAngle_ = angle;
    updateByteStream();
}

void MotorDetails::setMotorAboutToStall(bool on) {
    byteStream_[16] = on ? 0x01 : -0x01;
    motorAboutToStall_ = on;
    updateByteStream();
}

void MotorDetails::setDelayInReadingTempSensor(bool on) {
    byteStream_[16] = on ? 0x02 : -0x02;
    delayInReadingTempSensor_ = on;
    updateByteStream();
}

void MotorDetails::setDelayInReadingPosSensor(bool on) {
    byteStream_[16] = on ? 0x04 : -0x04;
    delayInReadingPosSensor_ = on;
    updateByteStream();
}

void MotorDetails::setInverter1TempVeryHigh(bool on) {
    byteStream_[16] = on ? 0x08 : -0x08;
    inverter1TempVeryHigh_ = on;
    updateByteStream();
}

void MotorDetails::setInverter2TempVeryHigh(bool on) {
    byteStream_[16] = on ? 0x10 : -0x10;
    inverter2TempVeryHigh_ = on;
    updateByteStream();
}

void MotorDetails::setInverter3TempVeryHigh(bool on) {
    byteStream_[16] = on ? 0x20 : -0x20;
    inverter3TempVeryHigh_ = on;
    updateByteStream();
}

void MotorDetails::setInverter4TempVeryHigh(bool on) {
    byteStream_[16] = on ? 0x40 : -0x40;
    inverter4TempVeryHigh_ = on;
    updateByteStream();
}

void MotorDetails::setInverter5TempVeryHigh(bool on) {
    byteStream_[16] = on ? 0x80 : -0x80;
    inverter5TempVeryHigh_ = on;
    updateByteStream();
}

void MotorDetails::setInverter6TempVeryHigh(bool on) {
    byteStream_[18] = on ? 0x01 : -0x01;
    inverter6TempVeryHigh_ = on;
    updateByteStream();
}

void MotorDetails::setCpuTemperatureVeryHigh(bool on) {
    byteStream_[18] = on ? 0x02 : -0x02;
    cpuTemperatureVeryHigh_ = on;
    updateByteStream();
}

void MotorDetails::setHallTemperatureVeryHigh(bool on) {
    byteStream_[18] = on ? 0x04 : -0x04;
    hallTemperatureVeryHigh_ = on;
    updateByteStream();
}

void MotorDetails::setDclinkTemperatureVeryHigh(bool on) {
    byteStream_[18] = on ? 0x08 : -0x08;
    dclinkTemperatureVeryHigh_ = on;
    updateByteStream();
}

void MotorDetails::setDelayInDclinkCommunication(bool on) {
    byteStream_[18] = on ? 0x10 : -0x10;
    delayInDclinkCommunication_ = on;
    updateByteStream();
}

void MotorDetails::setInverter1OverCurrentWarning(bool on) {
    byteStream_[18] = on ? 0x20 : -0x20;
    inverter1OverCurrentWarning_ = on;
    updateByteStream();
}

void MotorDetails::setInverter2OverCurrentWarning(bool on) {
    byteStream_[18] = on ? 0x40 : -0x40;
    inverter2OverCurrentWarning_ = on;
    updateByteStream();
}

void MotorDetails::setInverter3OverCurrentWarning(bool on) {
    byteStream_[18] = on ? 0x80 : -0x80;
    inverter3OverCurrentWarning_ = on;
    updateByteStream();
}

void MotorDetails::setInverter4OverCurrentWarning(bool on) {
    byteStream_[20] = on ? 0x01 : -0x01;
    inverter4OverCurrentWarning_ = on;
    updateByteStream();
}

void MotorDetails::setInverter5OverCurrentWarning(bool on) {
    byteStream_[20] = on ? 0x02 : -0x02;
    inverter5OverCurrentWarning_ = on;
    updateByteStream();
}

void MotorDetails::setInverter6OverCurrentWarning(bool on) {
    byteStream_[20] = on ? 0x04 : -0x04;
    inverter6OverCurrentWarning_ = on;
    updateByteStream();
}

void MotorDetails::setDcOvervoltageWarning(bool on) {
    byteStream_[20] = on ? 0x08 : -0x08;
    dcOvervoltageWarning_ = on;
    updateByteStream();
}

void MotorDetails::setDcUndervoltageWarning(bool on) {
    byteStream_[20] = on ? 0x10 : -0x10;
    dcUndervoltageWarning_ = on;
    updateByteStream();
}

void MotorDetails::setCanCommsTimeout(bool on) {
    byteStream_[20] = on ? 0x20 : -0x20;
    canCommsTimeout_ = on;
    updateByteStream();
}

void MotorDetails::setInverter1faultWarning(bool on) {
    byteStream_[20] = on ? 0x40 : -0x40;
    inverter1faultWarning_ = on;
    updateByteStream();
}

void MotorDetails::setInverter2faultWarning(bool on) {
    byteStream_[20] = on ? 0x80 : -0x80;
    inverter2faultWarning_ = on;
    updateByteStream();
}

void MotorDetails::setInverter3faultWarning(bool on) {
    byteStream_[22] = on ? 0x01 : -0x01;
    inverter3faultWarning_ = on;
    updateByteStream();
}

void MotorDetails::setInverter4faultWarning(bool on) {
    byteStream_[22] = on ? 0x02 : -0x02;
    inverter4faultWarning_ = on;
    updateByteStream();
}

void MotorDetails::setInverter5faultWarning(bool on) {
    byteStream_[22] = on ? 0x04 : -0x04;
    inverter5faultWarning_ = on;
    updateByteStream();
}

void MotorDetails::setInverter6faultWarning(bool on) {
    byteStream_[22] = on ? 0x08 : -0x08;
    inverter6faultWarning_ = on;
    updateByteStream();
}

void MotorDetails::setCanSendWarning(bool on) {
    byteStream_[22] = on ? 0x10 : -0x10;
    canSendWarning_ = on;
    updateByteStream();
}

void MotorDetails::setLostFramesOnCanBusWarning(bool on) {
    byteStream_[22] = on ? 0x20 : -0x20;
    lostFramesOnCanBusWarning_ = on;
    updateByteStream();
}

void MotorDetails::setOverspeedWarning(bool on) {
    byteStream_[22] = on ? 0x40 : -0x40;
    overspeedWarning_ = on;
    updateByteStream();
}

void MotorDetails::setCpuOverload(bool on) {
    byteStream_[22] = on ? 0x80 : -0x80;
    cpuOverload_ = on;
    updateByteStream();
}

void MotorDetails::setTorqueLimited(bool on) {
    byteStream_[24] = on ? 0x01 : -0x01;
    torqueLimited_ = on;
    updateByteStream();
}

void MotorDetails::setStartAtHighRpm(bool on) {
    byteStream_[24] = on ? 0x02 : -0x02;
    startAtHighRpm_ = on;
    updateByteStream();
}

void MotorDetails::setInitError(bool on) {
    byteStream_[25] = on ? 0x01 : -0x01;
    initError_ = on;
    updateByteStream();
}

void MotorDetails::setSettingsNotFound(bool on) {
    byteStream_[25] = on ? 0x02 : -0x02;
    settingsNotFound_ = on;
    updateByteStream();
}

void MotorDetails::setMotorStalled(bool on) {
    byteStream_[25] = on ? 0x04 : -0x04;
    motorStalled_ = on;
    updateByteStream();
}

void MotorDetails::setControllerDataReadingTimeout(bool on) {
    byteStream_[25] = on ? 0x08 : -0x08;
    controllerDataReadingTimeout_ = on;
    updateByteStream();
}

void MotorDetails::setInvalidHallSensorSequence(bool on) {
    byteStream_[25] = on ? 0x10 : -0x10;
    invalidHallSensorSequence_ = on;
    updateByteStream();
}

void MotorDetails::setInvalidHallSector(bool on) {
    byteStream_[25] = on ? 0x20 : -0x20;
    invalidHallSector_ = on;
    updateByteStream();
}

void MotorDetails::setErrorReadingTempSensor(bool on) {
    byteStream_[25] = on ? 0x40 : -0x40;
    errorReadingTempSensor_ = on;
    updateByteStream();
}

void MotorDetails::setPositionSensorReadingError(bool on) {
    byteStream_[25] = on ? 0x80 : -0x80;
    positionSensorReadingError_ = on;
    updateByteStream();
}

void MotorDetails::setErrorReadingEncoder(bool on) {
    byteStream_[27] = on ? 0x01 : -0x01;
    errorReadingEncoder_ = on;
    updateByteStream();
}

void MotorDetails::setZeroPositionOffsetNotSet(bool on) {
    byteStream_[27] = on ? 0x02 : -0x02;
    zeroPositionOffsetNotSet_ = on;
    updateByteStream();
}

void MotorDetails::setHwEnableNotSet(bool on) {
    byteStream_[27] = on ? 0x04 : -0x04;
    hwEnableNotSet_ = on;
    updateByteStream();
}

void MotorDetails::setInverter1TempTooHigh(bool on) {
    byteStream_[27] = on ? 0x08 : -0x08;
    inverter1TempTooHigh_ = on;
    updateByteStream();
}

void MotorDetails::setInverter2TempTooHigh(bool on) {
    byteStream_[27] = on ? 0x10 : -0x10;
    inverter2TempTooHigh_ = on;
    updateByteStream();
}

void MotorDetails::setInverter3TempTooHigh(bool on) {
    byteStream_[27] = on ? 0x20 : -0x20;
    inverter3TempTooHigh_ = on;
    updateByteStream();
}

void MotorDetails::setInverter4TempTooHigh(bool on) {
    byteStream_[27] = on ? 0x40 : -0x40;
    inverter4TempTooHigh_ = on;
    updateByteStream();
}

void MotorDetails::setInverter5TempTooHigh(bool on) {
    byteStream_[27] = on ? 0x80 : -0x80;
    inverter5TempTooHigh_ = on;
    updateByteStream();
}

void MotorDetails::setInverter6TempTooHigh(bool on) {
    byteStream_[29] = on ? 0x01 : -0x01;
    inverter6TempTooHigh_ = on;
    updateByteStream();
}

void MotorDetails::setCpuTemperatureTooHigh(bool on) {
    byteStream_[29] = on ? 0x02 : -0x02;
    cpuTemperatureTooHigh_ = on;
    updateByteStream();
}

void MotorDetails::setHallTemperatureTooHigh(bool on) {
    byteStream_[29] = on ? 0x04 : -0x04;
    hallTemperatureTooHigh_ = on;
    updateByteStream();
}

void MotorDetails::setDclinkTemperatureTooHigh(bool on) {
    byteStream_[29] = on ? 0x08 : -0x08;
    dclinkTemperatureTooHigh_ = on;
    updateByteStream();
}

void MotorDetails::setErrorInDclinkCommunication(bool on) {
    byteStream_[29] = on ? 0x10 : -0x10;
    errorInDclinkCommunication_ = on;
    updateByteStream();
}

void MotorDetails::setInverter1OvercurrentError(bool on) {
    byteStream_[29] = on ? 0x20 : -0x20;
    inverter1OvercurrentError_ = on;
    updateByteStream();
}

void MotorDetails::setInverter2OvercurrentError(bool on) {
    byteStream_[29] = on ? 0x40 : -0x40;
    inverter2OvercurrentError_ = on;
    updateByteStream();
}

void MotorDetails::setInverter3OvercurrentError(bool on) {
    byteStream_[29] = on ? 0x80 : -0x80;
    inverter3OvercurrentError_ = on;
    updateByteStream();
}

void MotorDetails::setInverter4OvercurrentError(bool on) {
    byteStream_[31] = on ? 0x01 : -0x01;
    inverter4OvercurrentError_ = on;
    updateByteStream();
}

void MotorDetails::setInverter5OvercurrentError(bool on) {
    byteStream_[31] = on ? 0x02 : -0x02;
    inverter5OvercurrentError_ = on;
    updateByteStream();
}

void MotorDetails::setInverter6OvercurrentError(bool on) {
    byteStream_[31] = on ? 0x04 : -0x04;
    inverter6OvercurrentError_ = on;
    updateByteStream();
}

void MotorDetails::setDcOvervoltageError(bool on) {
    byteStream_[31] = on ? 0x08 : -0x08;
    dcOvervoltageError_ = on;
    updateByteStream();
}

void MotorDetails::setDcUndervoltageError(bool on) {
    byteStream_[31] = on ? 0x10 : -0x10;
    dcUndervoltageError_ = on;
    updateByteStream();
}

void MotorDetails::setDoubleCanIdOnBus(bool on) {
    byteStream_[31] = on ? 0x20 : -0x20;
    doubleCanIdOnBus_ = on;
    updateByteStream();
}

void MotorDetails::setCanCommsTimeoutError(bool on) {
    byteStream_[31] = on ? 0x40 : -0x40;
    canCommsTimeoutError_ = on;
    updateByteStream();
}

void MotorDetails::setInverter1FaultError(bool on) {
    byteStream_[31] = on ? 0x80 : -0x80;
    inverter1FaultError_ = on;
    updateByteStream();
}

void MotorDetails::setInverter2FaultError(bool on) {
    byteStream_[32] = on ? 0x01 : -0x01;
    inverter2FaultError_ = on;
    updateByteStream();
}

void MotorDetails::setInverter3FaultError(bool on) {
    byteStream_[32] = on ? 0x02 : -0x02;
    inverter3FaultError_ = on;
    updateByteStream();
}

void MotorDetails::setInverter4FaultError(bool on) {
    byteStream_[32] = on ? 0x04 : -0x04;
    inverter4FaultError_ = on;
    updateByteStream();
}

void MotorDetails::setInverter5FaultError(bool on) {
    byteStream_[32] = on ? 0x08 : -0x08;
    inverter5FaultError_ = on;
    updateByteStream();
}

void MotorDetails::setInverter6FaultError(bool on) {
    byteStream_[32] = on ? 0x10 : -0x10;
    inverter6FaultError_ = on;
    updateByteStream();
}

void MotorDetails::setCanSendError(bool on) {
    byteStream_[32] = on ? 0x20 : -0x20;
    canSendError_ = on;
    updateByteStream();
}

void MotorDetails::setLostFramesOnCanBusError(bool on) {
    byteStream_[32] = on ? 0x40 : -0x40;
    lostFramesOnCanBusError_ = on;
    updateByteStream();
}

void MotorDetails::setOverspeedError(bool on) {
    byteStream_[32] = on ? 0x80 : -0x80;
    overspeedError_ = on;
    updateByteStream();
}

void MotorDetails::setCpuOverloaded(bool on) {
    byteStream_[33] = on ? 0x01 : -0x01;
    cpuOverloaded_ = on;
    updateByteStream();
}
