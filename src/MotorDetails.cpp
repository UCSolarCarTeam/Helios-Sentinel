#include "MotorDetails.h"
#include "util.h"

#include <QIODevice>
#include <QDebug>

namespace {
    const char CONTROL_ON_MASK = 0x01;
    const char MOTOR_ON_MASK = 0x02;
    const char SOFTWARE_ENABLE_MASK = 0x04;
    const char DEBUG_ON_MASK = 0x08;

    const short MOTOR_ABOUT_TO_STALL_MASK = 0x0001;
    const short DELAY_IN_READING_TEMP_SENSOR_MASK = 0x0002;
    const short DELAY_IN_READING_POS_SENSOR_MASK = 0x0004;
    const short INVERTER_1_TEMP_VERY_HIGH_MASK = 0x0008;
    const short INVERTER_2_TEMP_VERY_HIGH_MASK = 0x0010;
    const short INVERTER_3_TEMP_VERY_HIGH_MASK = 0x0020;
    const short INVERTER_4_TEMP_VERY_HIGH_MASK = 0x0040;
    const short INVERTER_5_TEMP_VERY_HIGH_MASK = 0x0080;

    const short INVERTER_6_TEMP_VERY_HIGH_MASK = 0x0001;
    const short CPU_TEMPERATURE_VERY_HIGH_MASK = 0x0002;
    const short HALL_TEMPERATURE_VERY_HIGH_MASK = 0x0004;
    const short DCLINK_TEMPERATURE_VERY_HIGH_MASK = 0x0008;
    const short DELAY_IN_DCLINK_COMMUNICATION_MASK = 0x0010;
    const short INVERTER_1_OVERCURRENT_WARNING_MASK = 0x0020;
    const short INVERTER_2_OVERCURRENT_WARNING_MASK = 0x0040;
    const short INVERTER_3_OVERCURRENT_WARNING_MASK = 0x0080;

    const short INVERTER_4_OVERCURRENT_WARNING_MASK = 0x0001;
    const short INVERTER_5_OVERCURRENT_WARNING_MASK = 0x0002;
    const short INVERTER_6_OVERCURRENT_WARNING_MASK = 0x0004;
    const short DC_OVERVOLTAGE_WARNING_MASK = 0x0008;
    const short DC_UNDERVOLTAGE_WARNING_MASK = 0x0010;
    const short CAN_COMMS_TIMEOUT_MASK = 0x0020;
    const short INVERTER_1_FAULT_WARNING_MASK = 0x0040;
    const short INVERTER_2_FAULT_WARNING_MASK = 0x0080;

    const short INVERTER_3_FAULT_WARNING_MASK = 0x0001;
    const short INVERTER_4_FAULT_WARNING_MASK = 0x0002;
    const short INVERTER_5_FAULT_WARNING_MASK = 0x0004;
    const short INVERTER_6_FAULT_WARNING_MASK = 0x0008;
    const short CAN_SEND_WARNING_MASK = 0x0010;
    const short LOST_FRAMES_ON_CAN_BUS_WARNING_MASK = 0x0020;
    const short OVERSPEED_WARNING_MASK = 0x0040;
    const short CPU_OVERLOAD_MASK = 0x0080;

    const char TORQUE_LIMITED_MASK = 0x01;
    const char START_AT_HIGH_RPM_MASK = 0x02;

    const short INIT_ERROR_MASK = 0x0001;
    const short SETTINGS_NOT_FOUND_MASK = 0x0002;
    const short MOTOR_STALLED_MASK = 0x0004;
    const short CONTROLLER_DATA_READING_TIMEOUT_MASK = 0x0008;
    const short INVALID_HALL_SENSOR_SEQUENCE_MASK = 0x0010;
    const short INVALID_HALL_SECTOR_MASK = 0x0020;
    const short ERROR_READING_TEMP_SENSOR_MASK = 0x0040;
    const short POSITION_SENSOR_READING_ERROR_MASK = 0x0080;

    const short ERROR_READING_ENCODER_MASK = 0x0001;
    const short ZERO_POSITION_OFFSET_NOT_SET_MASK = 0x0002;
    const short HW_ENABLE_NOT_SET_MASK = 0x0004;
    const short INVERTER_1_TEMP_TOO_HIGH_MASK = 0x0008;
    const short INVERTER_2_TEMP_TOO_HIGH_MASK = 0x0010;
    const short INVERTER_3_TEMP_TOO_HIGH_MASK = 0x0020;
    const short INVERTER_4_TEMP_TOO_HIGH_MASK = 0x0040;
    const short INVERTER_5_TEMP_TOO_HIGH_MASK = 0x0080;

    const short INVERTER_6_TEMP_TOO_HIGH_MASK = 0x0001;
    const short CPU_TEMPERATURE_TOO_HIGH_MASK = 0x0002;
    const short HALL_TEMPERATURE_TOO_HIGH_MASK = 0x0004;
    const short DCLINK_TEMPERATURE_TOO_HIGH_MASK = 0x0008;
    const short ERROR_IN_DCLINK_COMMUNICATION_MASK = 0x0010;
    const short INVERTER_1_OVERCURRENT_ERROR_MASK = 0x0020;
    const short INVERTER_2_OVERCURRENT_ERROR_MASK = 0x0040;
    const short INVERTER_3_OVERCURRENT_ERROR_MASK = 0x0080;

    const short INVERTER_4_OVERCURRENT_ERROR_MASK = 0x0001;
    const short INVERTER_5_OVERCURRENT_ERROR_MASK = 0x0002;
    const short INVERTER_6_OVERCURRENT_ERROR_MASK = 0x0004;
    const short DC_OVERVOLTAGE_ERROR_MASK = 0x0008;
    const short DC_UNDERVOLTAGE_ERROR_MASK = 0x0010;
    const short DOUBLE_CAN_ID_ON_BUS_MASK = 0x0020;
    const short CAN_COMMS_TIMEOUT_ERROR_MASK = 0x0040;
    const short INVERTER_1_FAULT_ERROR_MASK = 0x0080;
    const short INVERTER_2_FAULT_ERROR_MASK = 0x0001;
    const short INVERTER_3_FAULT_ERROR_MASK = 0x0002;
    const short INVERTER_4_FAULT_ERROR_MASK = 0x0004;
    const short INVERTER_5_FAULT_ERROR_MASK = 0x0008;
    const short INVERTER_6_FAULT_ERROR_MASK = 0x0010;
    const short CAN_SEND_ERROR_MASK = 0x0020;
    const short LOST_FRAMES_ON_CAN_BUS_ERROR_MASK = 0x0040;
    const short OVERSPEED_ERROR_MASK = 0x0080;

    const char CPU_OVERLOADED_MASK = 0x01;
}
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
    QByteArray checksum = Util::generateChecksum(byteStream_, 1, 33);
    // size - 3 and size - 2
    byteStream_[34] = checksum.at(0);
    byteStream_[35] = checksum.at(1);
    encodedByteStream_ = Util::encodeByteStream(byteStream_);
    emit encodedByteStreamStrChanged();
    emit byteStreamStrChanged();
    qDebug() << "BS: " << byteStream_.toHex(' ');
    qDebug() << "EBS: " << encodedByteStream_.toHex(' ');
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
    byteStream_[4] = mode ? (byteStream_[4] | CONTROL_ON_MASK)
                          : (byteStream_[4] & ~CONTROL_ON_MASK);
    controlMode_ = mode;
    updateByteStream();
}

void MotorDetails::setMotorMode(bool mode) {
    byteStream_[4] = mode ? (byteStream_[4] | MOTOR_ON_MASK)
                          : (byteStream_[4] & ~MOTOR_ON_MASK);
    motorMode_ = mode;
    updateByteStream();
}

void MotorDetails::setSoftwareEnable(bool enable) {
    byteStream_[4] = enable ? (byteStream_[4] | SOFTWARE_ENABLE_MASK)
                          : (byteStream_[4] & ~SOFTWARE_ENABLE_MASK);
    softwareEnable_ = enable;
    updateByteStream();
}

void MotorDetails::setDebugMode(bool mode) {
    byteStream_[4] = mode ? (byteStream_[4] | DEBUG_ON_MASK)
                          : (byteStream_[4] & ~DEBUG_ON_MASK);
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

void MotorDetails::setAbsoluteAngle(unsigned short angle) {
    QByteArray in = Util::formatInt(angle, 2);
    byteStream_.replace(14, 2, in);
    absoluteAngle_ = angle;
    updateByteStream();
}

void MotorDetails::setMotorAboutToStall(bool on) {
    byteStream_[16] = on ? (byteStream_[16] | MOTOR_ABOUT_TO_STALL_MASK)
                           : (byteStream_[16] & ~MOTOR_ABOUT_TO_STALL_MASK);
    motorAboutToStall_ = on;
    updateByteStream();
}

void MotorDetails::setDelayInReadingTempSensor(bool on) {
    byteStream_[16] = on ? (byteStream_[16] | DELAY_IN_READING_TEMP_SENSOR_MASK)
                           : (byteStream_[16] & ~DELAY_IN_READING_TEMP_SENSOR_MASK);
    delayInReadingTempSensor_ = on;
    updateByteStream();
}

void MotorDetails::setDelayInReadingPosSensor(bool on) {
    byteStream_[16] = on ? (byteStream_[16] | DELAY_IN_READING_POS_SENSOR_MASK)
                           : (byteStream_[16] & ~DELAY_IN_READING_POS_SENSOR_MASK);
    delayInReadingPosSensor_ = on;
    updateByteStream();
}

void MotorDetails::setInverter1TempVeryHigh(bool on) {
    byteStream_[16] = on ? (byteStream_[16] | INVERTER_1_TEMP_VERY_HIGH_MASK)
                           : (byteStream_[16] & ~INVERTER_1_TEMP_VERY_HIGH_MASK);
    inverter1TempVeryHigh_ = on;
    updateByteStream();
}

void MotorDetails::setInverter2TempVeryHigh(bool on) {
    byteStream_[16] = on ? (byteStream_[16] | INVERTER_2_TEMP_VERY_HIGH_MASK)
                           : (byteStream_[16] & ~INVERTER_2_TEMP_VERY_HIGH_MASK);
    inverter2TempVeryHigh_ = on;
    updateByteStream();
}

void MotorDetails::setInverter3TempVeryHigh(bool on) {
    byteStream_[16] = on ? (byteStream_[16] | INVERTER_3_TEMP_VERY_HIGH_MASK)
                           : (byteStream_[16] & ~INVERTER_3_TEMP_VERY_HIGH_MASK);
    inverter3TempVeryHigh_ = on;
    updateByteStream();
}

void MotorDetails::setInverter4TempVeryHigh(bool on) {
    byteStream_[16] = on ? (byteStream_[16] | INVERTER_4_TEMP_VERY_HIGH_MASK)
                           : (byteStream_[16] & ~INVERTER_4_TEMP_VERY_HIGH_MASK);
    inverter4TempVeryHigh_ = on;
    updateByteStream();
}

void MotorDetails::setInverter5TempVeryHigh(bool on) {
    byteStream_[16] = on ? (byteStream_[16] | INVERTER_5_TEMP_VERY_HIGH_MASK)
                           : (byteStream_[16] & ~INVERTER_5_TEMP_VERY_HIGH_MASK);
    inverter5TempVeryHigh_ = on;
    updateByteStream();
}

void MotorDetails::setInverter6TempVeryHigh(bool on) {
    byteStream_[18] = on ? (byteStream_[18] | INVERTER_6_TEMP_VERY_HIGH_MASK)
                           : (byteStream_[18] & ~INVERTER_6_TEMP_VERY_HIGH_MASK);
    inverter6TempVeryHigh_ = on;
    updateByteStream();
}

void MotorDetails::setCpuTemperatureVeryHigh(bool on) {
    byteStream_[18] = on ? (byteStream_[18] | CPU_TEMPERATURE_VERY_HIGH_MASK)
                           : (byteStream_[18] & ~CPU_TEMPERATURE_VERY_HIGH_MASK);
    cpuTemperatureVeryHigh_ = on;
    updateByteStream();
}

void MotorDetails::setHallTemperatureVeryHigh(bool on) {
    byteStream_[18] = on ? (byteStream_[18] | HALL_TEMPERATURE_VERY_HIGH_MASK)
                           : (byteStream_[18] & ~HALL_TEMPERATURE_VERY_HIGH_MASK);
    hallTemperatureVeryHigh_ = on;
    updateByteStream();
}

void MotorDetails::setDclinkTemperatureVeryHigh(bool on) {
    byteStream_[18] = on ? (byteStream_[18] | DCLINK_TEMPERATURE_VERY_HIGH_MASK)
                           : (byteStream_[18] & ~DCLINK_TEMPERATURE_VERY_HIGH_MASK);
    dclinkTemperatureVeryHigh_ = on;
    updateByteStream();
}

void MotorDetails::setDelayInDclinkCommunication(bool on) {
    byteStream_[18] = on ? (byteStream_[18] | DELAY_IN_DCLINK_COMMUNICATION_MASK)
                           : (byteStream_[18] & ~DELAY_IN_DCLINK_COMMUNICATION_MASK);
    delayInDclinkCommunication_ = on;
    updateByteStream();
}

void MotorDetails::setInverter1OverCurrentWarning(bool on) {
    byteStream_[18] = on ? (byteStream_[18] | INVERTER_1_OVERCURRENT_WARNING_MASK)
                           : (byteStream_[18] & ~INVERTER_1_OVERCURRENT_WARNING_MASK);
    inverter1OverCurrentWarning_ = on;
    updateByteStream();
}

void MotorDetails::setInverter2OverCurrentWarning(bool on) {
    byteStream_[18] = on ? (byteStream_[18] | INVERTER_2_OVERCURRENT_WARNING_MASK)
                           : (byteStream_[18] & ~INVERTER_2_OVERCURRENT_WARNING_MASK);
    inverter2OverCurrentWarning_ = on;
    updateByteStream();
}

void MotorDetails::setInverter3OverCurrentWarning(bool on) {
    byteStream_[18] = on ? (byteStream_[18] | INVERTER_3_OVERCURRENT_WARNING_MASK)
                           : (byteStream_[18] & ~INVERTER_3_OVERCURRENT_WARNING_MASK);
    inverter3OverCurrentWarning_ = on;
    updateByteStream();
}

void MotorDetails::setInverter4OverCurrentWarning(bool on) {
    byteStream_[20] = on ? (byteStream_[20] | INVERTER_4_OVERCURRENT_WARNING_MASK)
                           : (byteStream_[20] & ~INVERTER_4_OVERCURRENT_WARNING_MASK);
    inverter4OverCurrentWarning_ = on;
    updateByteStream();
}

void MotorDetails::setInverter5OverCurrentWarning(bool on) {
    byteStream_[20] = on ? (byteStream_[20] | INVERTER_5_OVERCURRENT_WARNING_MASK)
                           : (byteStream_[20] & ~INVERTER_5_OVERCURRENT_WARNING_MASK);
    inverter5OverCurrentWarning_ = on;
    updateByteStream();
}

void MotorDetails::setInverter6OverCurrentWarning(bool on) {
    byteStream_[20] = on ? (byteStream_[20] | INVERTER_6_OVERCURRENT_WARNING_MASK)
                           : (byteStream_[20] & ~INVERTER_6_OVERCURRENT_WARNING_MASK);
    inverter6OverCurrentWarning_ = on;
    updateByteStream();
}

void MotorDetails::setDcOvervoltageWarning(bool on) {
    byteStream_[20] = on ? (byteStream_[20] | DC_OVERVOLTAGE_WARNING_MASK)
                           : (byteStream_[20] & ~DC_OVERVOLTAGE_WARNING_MASK);
    dcOvervoltageWarning_ = on;
    updateByteStream();
}

void MotorDetails::setDcUndervoltageWarning(bool on) {
    byteStream_[20] = on ? (byteStream_[20] | DC_UNDERVOLTAGE_WARNING_MASK)
                           : (byteStream_[20] & ~DC_UNDERVOLTAGE_WARNING_MASK);
    dcUndervoltageWarning_ = on;
    updateByteStream();
}

void MotorDetails::setCanCommsTimeout(bool on) {
    byteStream_[20] = on ? (byteStream_[20] | CAN_COMMS_TIMEOUT_MASK)
                           : (byteStream_[20] & ~CAN_COMMS_TIMEOUT_MASK);
    canCommsTimeout_ = on;
    updateByteStream();
}

void MotorDetails::setInverter1faultWarning(bool on) {
    byteStream_[20] = on ? (byteStream_[20] | INVERTER_1_FAULT_WARNING_MASK)
                           : (byteStream_[20] & ~INVERTER_1_FAULT_WARNING_MASK);
    inverter1faultWarning_ = on;
    updateByteStream();
}

void MotorDetails::setInverter2faultWarning(bool on) {
    byteStream_[20] = on ? (byteStream_[20] | INVERTER_2_FAULT_WARNING_MASK)
                           : (byteStream_[20] & ~INVERTER_2_FAULT_WARNING_MASK);
    inverter2faultWarning_ = on;
    updateByteStream();
}

void MotorDetails::setInverter3faultWarning(bool on) {
    byteStream_[22] = on ? (byteStream_[22] | INVERTER_3_FAULT_WARNING_MASK)
                           : (byteStream_[22] & ~INVERTER_3_FAULT_WARNING_MASK);
    inverter3faultWarning_ = on;
    updateByteStream();
}

void MotorDetails::setInverter4faultWarning(bool on) {
    byteStream_[22] = on ? (byteStream_[22] | INVERTER_4_FAULT_WARNING_MASK)
                           : (byteStream_[22] & ~INVERTER_4_FAULT_WARNING_MASK);
    inverter4faultWarning_ = on;
    updateByteStream();
}

void MotorDetails::setInverter5faultWarning(bool on) {
    byteStream_[22] = on ? (byteStream_[22] | INVERTER_5_FAULT_WARNING_MASK)
                           : (byteStream_[22] & ~INVERTER_5_FAULT_WARNING_MASK);
    inverter5faultWarning_ = on;
    updateByteStream();
}

void MotorDetails::setInverter6faultWarning(bool on) {
    byteStream_[22] = on ? (byteStream_[22] | INVERTER_6_FAULT_WARNING_MASK)
                           : (byteStream_[22] & ~INVERTER_6_FAULT_WARNING_MASK);
    inverter6faultWarning_ = on;
    updateByteStream();
}

void MotorDetails::setCanSendWarning(bool on) {
    byteStream_[22] = on ? (byteStream_[22] | CAN_SEND_WARNING_MASK)
                           : (byteStream_[22] & ~CAN_SEND_WARNING_MASK);
    canSendWarning_ = on;
    updateByteStream();
}

void MotorDetails::setLostFramesOnCanBusWarning(bool on) {
    byteStream_[22] = on ? (byteStream_[22] | LOST_FRAMES_ON_CAN_BUS_WARNING_MASK)
                           : (byteStream_[22] & ~LOST_FRAMES_ON_CAN_BUS_WARNING_MASK);
    lostFramesOnCanBusWarning_ = on;
    updateByteStream();
}

void MotorDetails::setOverspeedWarning(bool on) {
    byteStream_[22] = on ? (byteStream_[22] | OVERSPEED_WARNING_MASK)
                           : (byteStream_[22] & ~OVERSPEED_WARNING_MASK);
    overspeedWarning_ = on;
    updateByteStream();
}

void MotorDetails::setCpuOverload(bool on) {
    byteStream_[22] = on ? (byteStream_[22] | CPU_OVERLOAD_MASK)
                           : (byteStream_[22] & ~CPU_OVERLOAD_MASK);
    cpuOverload_ = on;
    updateByteStream();
}

void MotorDetails::setTorqueLimited(bool on) {
    byteStream_[24] = on ? (byteStream_[24] | TORQUE_LIMITED_MASK)
                           : (byteStream_[24] & ~TORQUE_LIMITED_MASK);
    torqueLimited_ = on;
    updateByteStream();
}

void MotorDetails::setStartAtHighRpm(bool on) {
    byteStream_[24] = on ? (byteStream_[24] | START_AT_HIGH_RPM_MASK)
                           : (byteStream_[24] & ~START_AT_HIGH_RPM_MASK);
    startAtHighRpm_ = on;
    updateByteStream();
}

void MotorDetails::setInitError(bool on) {
    byteStream_[25] = on ? (byteStream_[25] | INIT_ERROR_MASK)
                           : (byteStream_[25] & ~INIT_ERROR_MASK);
    initError_ = on;
    updateByteStream();
}

void MotorDetails::setSettingsNotFound(bool on) {
    byteStream_[25] = on ? (byteStream_[25] | SETTINGS_NOT_FOUND_MASK)
                           : (byteStream_[25] & ~SETTINGS_NOT_FOUND_MASK);
    settingsNotFound_ = on;
    updateByteStream();
}

void MotorDetails::setMotorStalled(bool on) {
    byteStream_[25] = on ? (byteStream_[25] | MOTOR_STALLED_MASK)
                           : (byteStream_[25] & ~MOTOR_STALLED_MASK);
    motorStalled_ = on;
    updateByteStream();
}

void MotorDetails::setControllerDataReadingTimeout(bool on) {
    byteStream_[25] = on ? (byteStream_[25] | CONTROLLER_DATA_READING_TIMEOUT_MASK)
                           : (byteStream_[25] & ~CONTROLLER_DATA_READING_TIMEOUT_MASK);
    controllerDataReadingTimeout_ = on;
    updateByteStream();
}

void MotorDetails::setInvalidHallSensorSequence(bool on) {
    byteStream_[25] = on ? (byteStream_[25] | INVALID_HALL_SENSOR_SEQUENCE_MASK)
                           : (byteStream_[25] & ~INVALID_HALL_SENSOR_SEQUENCE_MASK);
    invalidHallSensorSequence_ = on;
    updateByteStream();
}

void MotorDetails::setInvalidHallSector(bool on) {
    byteStream_[25] = on ? (byteStream_[25] | INVALID_HALL_SECTOR_MASK)
                           : (byteStream_[25] & ~INVALID_HALL_SECTOR_MASK);
    invalidHallSector_ = on;
    updateByteStream();
}

void MotorDetails::setErrorReadingTempSensor(bool on) {
    byteStream_[25] = on ? (byteStream_[25] | ERROR_READING_TEMP_SENSOR_MASK)
                           : (byteStream_[25] & ~ERROR_READING_TEMP_SENSOR_MASK);
    errorReadingTempSensor_ = on;
    updateByteStream();
}

void MotorDetails::setPositionSensorReadingError(bool on) {
    byteStream_[25] = on ? (byteStream_[25] | POSITION_SENSOR_READING_ERROR_MASK)
                           : (byteStream_[25] & ~POSITION_SENSOR_READING_ERROR_MASK);
    positionSensorReadingError_ = on;
    updateByteStream();
}

void MotorDetails::setErrorReadingEncoder(bool on) {
    byteStream_[27] = on ? (byteStream_[27] | ERROR_READING_ENCODER_MASK)
                           : (byteStream_[27] & ~ERROR_READING_ENCODER_MASK);
    errorReadingEncoder_ = on;
    updateByteStream();
}

void MotorDetails::setZeroPositionOffsetNotSet(bool on) {
    byteStream_[27] = on ? (byteStream_[27] | ZERO_POSITION_OFFSET_NOT_SET_MASK)
                           : (byteStream_[27] & ~ZERO_POSITION_OFFSET_NOT_SET_MASK);
    zeroPositionOffsetNotSet_ = on;
    updateByteStream();
}

void MotorDetails::setHwEnableNotSet(bool on) {
    byteStream_[27] = on ? (byteStream_[27] | HW_ENABLE_NOT_SET_MASK)
                           : (byteStream_[27] & ~HW_ENABLE_NOT_SET_MASK);;
    hwEnableNotSet_ = on;
    updateByteStream();
}

void MotorDetails::setInverter1TempTooHigh(bool on) {
    byteStream_[27] = on ? (byteStream_[27] | INVERTER_1_TEMP_TOO_HIGH_MASK)
                           : (byteStream_[27] & ~INVERTER_1_TEMP_TOO_HIGH_MASK);
    inverter1TempTooHigh_ = on;
    updateByteStream();
}

void MotorDetails::setInverter2TempTooHigh(bool on) {
    byteStream_[27] = on ? (byteStream_[27] | INVERTER_2_TEMP_TOO_HIGH_MASK)
                           : (byteStream_[27] & ~INVERTER_2_TEMP_TOO_HIGH_MASK);
    inverter2TempTooHigh_ = on;
    updateByteStream();
}

void MotorDetails::setInverter3TempTooHigh(bool on) {
    byteStream_[27] = on ? (byteStream_[27] | INVERTER_3_TEMP_TOO_HIGH_MASK)
                           : (byteStream_[27] & ~INVERTER_3_TEMP_TOO_HIGH_MASK);
    inverter3TempTooHigh_ = on;
    updateByteStream();
}

void MotorDetails::setInverter4TempTooHigh(bool on) {
    byteStream_[27] = on ? (byteStream_[27] | INVERTER_4_TEMP_TOO_HIGH_MASK)
                           : (byteStream_[27] & ~INVERTER_4_TEMP_TOO_HIGH_MASK);
    inverter4TempTooHigh_ = on;
    updateByteStream();
}

void MotorDetails::setInverter5TempTooHigh(bool on) {
    byteStream_[27] = on ? (byteStream_[27] | INVERTER_5_TEMP_TOO_HIGH_MASK)
                           : (byteStream_[27] & ~INVERTER_5_TEMP_TOO_HIGH_MASK);
    inverter5TempTooHigh_ = on;
    updateByteStream();
}

void MotorDetails::setInverter6TempTooHigh(bool on) {
    byteStream_[29] = on ? (byteStream_[29] | INVERTER_6_TEMP_TOO_HIGH_MASK)
                           : (byteStream_[29] & ~INVERTER_6_TEMP_TOO_HIGH_MASK);
    inverter6TempTooHigh_ = on;
    updateByteStream();
}

void MotorDetails::setCpuTemperatureTooHigh(bool on) {
    byteStream_[29] = on ? (byteStream_[29] | CPU_TEMPERATURE_TOO_HIGH_MASK)
                           : (byteStream_[29] & ~CPU_TEMPERATURE_TOO_HIGH_MASK);
    cpuTemperatureTooHigh_ = on;
    updateByteStream();
}

void MotorDetails::setHallTemperatureTooHigh(bool on) {
    byteStream_[29] = on ? (byteStream_[29] | HALL_TEMPERATURE_TOO_HIGH_MASK)
                           : (byteStream_[29] & ~HALL_TEMPERATURE_TOO_HIGH_MASK);
    hallTemperatureTooHigh_ = on;
    updateByteStream();
}

void MotorDetails::setDclinkTemperatureTooHigh(bool on) {
    byteStream_[29] = on ? (byteStream_[29] | DCLINK_TEMPERATURE_TOO_HIGH_MASK)
                           : (byteStream_[29] & ~DCLINK_TEMPERATURE_TOO_HIGH_MASK);
    dclinkTemperatureTooHigh_ = on;
    updateByteStream();
}

void MotorDetails::setErrorInDclinkCommunication(bool on) {
    byteStream_[29] = on ? (byteStream_[29] | ERROR_IN_DCLINK_COMMUNICATION_MASK)
                           : (byteStream_[29] & ~ERROR_IN_DCLINK_COMMUNICATION_MASK);
    errorInDclinkCommunication_ = on;
    updateByteStream();
}

void MotorDetails::setInverter1OvercurrentError(bool on) {
    byteStream_[29] = on ? (byteStream_[29] | INVERTER_1_OVERCURRENT_ERROR_MASK)
                           : (byteStream_[29] & ~INVERTER_1_OVERCURRENT_ERROR_MASK);
    inverter1OvercurrentError_ = on;
    updateByteStream();
}

void MotorDetails::setInverter2OvercurrentError(bool on) {
    byteStream_[29] = on ? (byteStream_[29] | INVERTER_2_OVERCURRENT_ERROR_MASK)
                           : (byteStream_[29] & ~INVERTER_2_OVERCURRENT_ERROR_MASK);
    inverter2OvercurrentError_ = on;
    updateByteStream();
}

void MotorDetails::setInverter3OvercurrentError(bool on) {
    byteStream_[29] = on ? (byteStream_[29] | INVERTER_3_OVERCURRENT_ERROR_MASK)
                           : (byteStream_[29] & ~INVERTER_3_OVERCURRENT_ERROR_MASK);
    inverter3OvercurrentError_ = on;
    updateByteStream();
}

void MotorDetails::setInverter4OvercurrentError(bool on) {
    byteStream_[31] = on ? (byteStream_[31] | INVERTER_4_OVERCURRENT_ERROR_MASK)
                           : (byteStream_[31] & ~INVERTER_4_OVERCURRENT_ERROR_MASK);
    inverter4OvercurrentError_ = on;
    updateByteStream();
}

void MotorDetails::setInverter5OvercurrentError(bool on) {
    byteStream_[31] = on ? (byteStream_[31] | INVERTER_5_OVERCURRENT_ERROR_MASK)
                           : (byteStream_[31] & ~INVERTER_5_OVERCURRENT_ERROR_MASK);
    inverter5OvercurrentError_ = on;
    updateByteStream();
}

void MotorDetails::setInverter6OvercurrentError(bool on) {
    byteStream_[31] = on ? (byteStream_[31] | INVERTER_6_OVERCURRENT_ERROR_MASK)
                           : (byteStream_[31] & ~INVERTER_6_OVERCURRENT_ERROR_MASK);
    inverter6OvercurrentError_ = on;
    updateByteStream();
}

void MotorDetails::setDcOvervoltageError(bool on) {
    byteStream_[31] = on ? (byteStream_[31] | DC_OVERVOLTAGE_ERROR_MASK)
                           : (byteStream_[31] & ~DC_OVERVOLTAGE_ERROR_MASK);
    dcOvervoltageError_ = on;
    updateByteStream();
}

void MotorDetails::setDcUndervoltageError(bool on) {
    byteStream_[31] = on ? (byteStream_[31] | DC_UNDERVOLTAGE_ERROR_MASK)
                           : (byteStream_[31] & ~DC_UNDERVOLTAGE_ERROR_MASK);
    dcUndervoltageError_ = on;
    updateByteStream();
}

void MotorDetails::setDoubleCanIdOnBus(bool on) {
    byteStream_[31] = on ? (byteStream_[31] | DOUBLE_CAN_ID_ON_BUS_MASK)
                           : (byteStream_[31] & ~DOUBLE_CAN_ID_ON_BUS_MASK);
    doubleCanIdOnBus_ = on;
    updateByteStream();
}

void MotorDetails::setCanCommsTimeoutError(bool on) {
    byteStream_[31] = on ? (byteStream_[31] | CAN_COMMS_TIMEOUT_ERROR_MASK)
                           : (byteStream_[31] & ~CAN_COMMS_TIMEOUT_ERROR_MASK);
    canCommsTimeoutError_ = on;
    updateByteStream();
}

void MotorDetails::setInverter1FaultError(bool on) {
    byteStream_[31] = on ? (byteStream_[31] | INVERTER_1_FAULT_ERROR_MASK)
                           : (byteStream_[31] & ~INVERTER_1_FAULT_ERROR_MASK);
    inverter1FaultError_ = on;
    updateByteStream();
}

void MotorDetails::setInverter2FaultError(bool on) {
    byteStream_[32] = on ? (byteStream_[32] | INVERTER_2_FAULT_ERROR_MASK)
                           : (byteStream_[32] & ~INVERTER_2_FAULT_ERROR_MASK);
    inverter2FaultError_ = on;
    updateByteStream();
}

void MotorDetails::setInverter3FaultError(bool on) {
    byteStream_[32] = on ? (byteStream_[32] | INVERTER_3_FAULT_ERROR_MASK)
                           : (byteStream_[32] & ~INVERTER_3_FAULT_ERROR_MASK);
    inverter3FaultError_ = on;
    updateByteStream();
}

void MotorDetails::setInverter4FaultError(bool on) {
    byteStream_[32] = on ? (byteStream_[32] | INVERTER_4_FAULT_ERROR_MASK)
                           : (byteStream_[32] & ~INVERTER_4_FAULT_ERROR_MASK);
    inverter4FaultError_ = on;
    updateByteStream();
}

void MotorDetails::setInverter5FaultError(bool on) {
    byteStream_[32] = on ? (byteStream_[32] | INVERTER_5_FAULT_ERROR_MASK)
                           : (byteStream_[32] & ~INVERTER_5_FAULT_ERROR_MASK);
    inverter5FaultError_ = on;
    updateByteStream();
}

void MotorDetails::setInverter6FaultError(bool on) {
    byteStream_[32] = on ? (byteStream_[32] | INVERTER_6_FAULT_ERROR_MASK)
                           : (byteStream_[32] & ~INVERTER_6_FAULT_ERROR_MASK);
    inverter6FaultError_ = on;
    updateByteStream();
}

void MotorDetails::setCanSendError(bool on) {
    byteStream_[32] = on ? (byteStream_[32] | CAN_SEND_ERROR_MASK)
                           : (byteStream_[32] & ~CAN_SEND_ERROR_MASK);
    canSendError_ = on;
    updateByteStream();
}

void MotorDetails::setLostFramesOnCanBusError(bool on) {
    byteStream_[32] = on ? (byteStream_[32] | LOST_FRAMES_ON_CAN_BUS_ERROR_MASK)
                           : (byteStream_[32] & ~LOST_FRAMES_ON_CAN_BUS_ERROR_MASK);
    lostFramesOnCanBusError_ = on;
    updateByteStream();
}

void MotorDetails::setOverspeedError(bool on) {
    byteStream_[32] = on ? (byteStream_[32] | OVERSPEED_ERROR_MASK)
                           : (byteStream_[32] & ~OVERSPEED_ERROR_MASK);
    overspeedError_ = on;
    updateByteStream();
}

void MotorDetails::setCpuOverloaded(bool on) {
    byteStream_[33] = on ? (byteStream_[33] | CPU_OVERLOADED_MASK)
                           : (byteStream_[33] & ~CPU_OVERLOADED_MASK);
    cpuOverloaded_ = on;
    updateByteStream();
}
