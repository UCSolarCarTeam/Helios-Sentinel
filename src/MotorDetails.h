#ifndef MOTORDETAILS_H
#define MOTORDETAILS_H
#include "PropertyDefinition.h"
#include <QObject>
namespace {
const char CONTROL_MODE_MASK = 0x01;
const char MOTOR_MODE_MASK = 0x02;
const char SOFTWARE_ENABLE_MASK = 0x04;
const char DEBUG_MODE_MASK = 0x08;

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
class MotorDetails : public QObject {
    Q_OBJECT

    DEFINE_PROPERTY_WHOLE_NUMBER(short, ControlValue, 2, 2)
    DEFINE_PROPERTY_BOOL(ControlMode, 4, 0x01)
    DEFINE_PROPERTY_BOOL(MotorMode, 4, 0x02)
    DEFINE_PROPERTY_BOOL(SoftwareEnable, 4, 0x04)
    DEFINE_PROPERTY_BOOL(DebugMode, 4, 0x08)

    DEFINE_PROPERTY_WHOLE_NUMBER(short, CurrentMotorTorque, 5, 2)
    DEFINE_PROPERTY_WHOLE_NUMBER(short, CurrentRpmValue, 7, 2)
    DEFINE_PROPERTY_WHOLE_NUMBER(char, MotorTemperature, 9, 1)
    DEFINE_PROPERTY_WHOLE_NUMBER(short, InverterPeakCurrent, 10, 2)
    DEFINE_PROPERTY_WHOLE_NUMBER(short, CurrentMotorPower, 12, 2)
    DEFINE_PROPERTY_WHOLE_NUMBER(unsigned short, AbsoluteAngle, 14, 2)

    DEFINE_PROPERTY_MASK_BOOL(MotorAboutToStall, 16, MOTOR_ABOUT_TO_STALL_MASK)
    DEFINE_PROPERTY_MASK_BOOL(DelayInReadingTempSensor, 16, DELAY_IN_READING_TEMP_SENSOR_MASK)
    DEFINE_PROPERTY_MASK_BOOL(DelayInReadingPosSensor, 16, DELAY_IN_READING_POS_SENSOR_MASK)
    DEFINE_PROPERTY_MASK_BOOL(Inverter1TempVeryHigh, 16, INVERTER_1_TEMP_VERY_HIGH_MASK)
    DEFINE_PROPERTY_MASK_BOOL(Inverter2TempVeryHigh, 16, INVERTER_2_TEMP_VERY_HIGH_MASK)
    DEFINE_PROPERTY_MASK_BOOL(Inverter3TempVeryHigh, 16, INVERTER_3_TEMP_VERY_HIGH_MASK)
    DEFINE_PROPERTY_MASK_BOOL(Inverter4TempVeryHigh, 16, INVERTER_4_TEMP_VERY_HIGH_MASK)
    DEFINE_PROPERTY_MASK_BOOL(Inverter5TempVeryHigh, 16, INVERTER_5_TEMP_VERY_HIGH_MASK)
    DEFINE_PROPERTY_MASK_BOOL(Inverter6TempVeryHigh, 18, INVERTER_6_TEMP_VERY_HIGH_MASK)
    DEFINE_PROPERTY_MASK_BOOL(CpuTemperatureVeryHigh, 18, CPU_TEMPERATURE_VERY_HIGH_MASK)
    DEFINE_PROPERTY_MASK_BOOL(HallTemperatureVeryHigh, 18, HALL_TEMPERATURE_VERY_HIGH_MASK)
    DEFINE_PROPERTY_MASK_BOOL(DclinkTemperatureVeryHigh, 18, DCLINK_TEMPERATURE_VERY_HIGH_MASK)
    DEFINE_PROPERTY_MASK_BOOL(DelayInDclinkCommunication, 18, DELAY_IN_DCLINK_COMMUNICATION_MASK)
    DEFINE_PROPERTY_MASK_BOOL(Inverter1OverCurrentWarning, 18, INVERTER_1_OVERCURRENT_WARNING_MASK)
    DEFINE_PROPERTY_MASK_BOOL(Inverter2OverCurrentWarning, 18, INVERTER_2_OVERCURRENT_WARNING_MASK)
    DEFINE_PROPERTY_MASK_BOOL(Inverter3OverCurrentWarning, 18, INVERTER_3_OVERCURRENT_WARNING_MASK)
    DEFINE_PROPERTY_MASK_BOOL(Inverter4OverCurrentWarning, 20, INVERTER_4_OVERCURRENT_WARNING_MASK)
    DEFINE_PROPERTY_MASK_BOOL(Inverter5OverCurrentWarning, 20, INVERTER_5_OVERCURRENT_WARNING_MASK)
    DEFINE_PROPERTY_MASK_BOOL(Inverter6OverCurrentWarning, 20, INVERTER_6_OVERCURRENT_WARNING_MASK)
    DEFINE_PROPERTY_MASK_BOOL(DcOvervoltageWarning, 20, DC_OVERVOLTAGE_WARNING_MASK)
    DEFINE_PROPERTY_MASK_BOOL(DcUndervoltageWarning, 20, DC_UNDERVOLTAGE_WARNING_MASK)
    DEFINE_PROPERTY_MASK_BOOL(CanCommsTimeout, 20, CAN_COMMS_TIMEOUT_MASK)
    DEFINE_PROPERTY_MASK_BOOL(Inverter1faultWarning, 20, INVERTER_1_FAULT_WARNING_MASK)
    DEFINE_PROPERTY_MASK_BOOL(Inverter2faultWarning, 20, INVERTER_2_FAULT_WARNING_MASK)
    DEFINE_PROPERTY_MASK_BOOL(Inverter3faultWarning, 22, INVERTER_3_FAULT_WARNING_MASK)
    DEFINE_PROPERTY_MASK_BOOL(Inverter4faultWarning, 22, INVERTER_4_FAULT_WARNING_MASK)
    DEFINE_PROPERTY_MASK_BOOL(Inverter5faultWarning, 22, INVERTER_5_FAULT_WARNING_MASK)
    DEFINE_PROPERTY_MASK_BOOL(Inverter6faultWarning, 22, INVERTER_6_FAULT_WARNING_MASK)
    DEFINE_PROPERTY_MASK_BOOL(CanSendWarning, 22, CAN_SEND_WARNING_MASK)
    DEFINE_PROPERTY_MASK_BOOL(LostFramesOnCanBusWarning, 22, LOST_FRAMES_ON_CAN_BUS_WARNING_MASK)
    DEFINE_PROPERTY_MASK_BOOL(OverspeedWarning, 22, OVERSPEED_WARNING_MASK)
    DEFINE_PROPERTY_MASK_BOOL(CpuOverload, 22, CPU_OVERLOAD_MASK)
    DEFINE_PROPERTY_MASK_BOOL(TorqueLimited, 24, TORQUE_LIMITED_MASK)
    DEFINE_PROPERTY_MASK_BOOL(StartAtHighRpm, 24, START_AT_HIGH_RPM_MASK)

    DEFINE_PROPERTY_MASK_BOOL(InitError, 25, INIT_ERROR_MASK)
    DEFINE_PROPERTY_MASK_BOOL(SettingsNotFound, 25, SETTINGS_NOT_FOUND_MASK)
    DEFINE_PROPERTY_MASK_BOOL(MotorStalled, 25, MOTOR_STALLED_MASK)
    DEFINE_PROPERTY_MASK_BOOL(ControllerDataReadingTimeout, 25, CONTROLLER_DATA_READING_TIMEOUT_MASK)
    DEFINE_PROPERTY_MASK_BOOL(InvalidHallSensorSequence, 25, INVALID_HALL_SENSOR_SEQUENCE_MASK)
    DEFINE_PROPERTY_MASK_BOOL(InvalidHallSector, 25, INVALID_HALL_SECTOR_MASK)
    DEFINE_PROPERTY_MASK_BOOL(ErrorReadingTempSensor, 25, ERROR_READING_TEMP_SENSOR_MASK)
    DEFINE_PROPERTY_MASK_BOOL(PositionSensorReadingError, 25, POSITION_SENSOR_READING_ERROR_MASK)
    DEFINE_PROPERTY_MASK_BOOL(ErrorReadingEncoder, 27, ERROR_READING_ENCODER_MASK)
    DEFINE_PROPERTY_MASK_BOOL(ZeroPositionOffsetNotSet, 27, ZERO_POSITION_OFFSET_NOT_SET_MASK)
    DEFINE_PROPERTY_MASK_BOOL(HwEnableNotSet, 27, HW_ENABLE_NOT_SET_MASK)
    DEFINE_PROPERTY_MASK_BOOL(Inverter1TempTooHigh, 27, INVERTER_1_TEMP_TOO_HIGH_MASK)
    DEFINE_PROPERTY_MASK_BOOL(Inverter2TempTooHigh, 27, INVERTER_2_TEMP_TOO_HIGH_MASK)
    DEFINE_PROPERTY_MASK_BOOL(Inverter3TempTooHigh, 27, INVERTER_3_TEMP_TOO_HIGH_MASK)
    DEFINE_PROPERTY_MASK_BOOL(Inverter4TempTooHigh, 27, INVERTER_4_TEMP_TOO_HIGH_MASK)
    DEFINE_PROPERTY_MASK_BOOL(Inverter5TempTooHigh, 27, INVERTER_5_TEMP_TOO_HIGH_MASK)
    DEFINE_PROPERTY_MASK_BOOL(Inverter6TempTooHigh, 29, INVERTER_6_TEMP_TOO_HIGH_MASK)
    DEFINE_PROPERTY_MASK_BOOL(CpuTemperatureTooHigh, 29, CPU_TEMPERATURE_TOO_HIGH_MASK)
    DEFINE_PROPERTY_MASK_BOOL(HallTemperatureTooHigh, 29, HALL_TEMPERATURE_TOO_HIGH_MASK)
    DEFINE_PROPERTY_MASK_BOOL(DclinkTemperatureTooHigh, 29, DCLINK_TEMPERATURE_TOO_HIGH_MASK)
    DEFINE_PROPERTY_MASK_BOOL(ErrorInDclinkCommunication, 29, ERROR_IN_DCLINK_COMMUNICATION_MASK)
    DEFINE_PROPERTY_MASK_BOOL(Inverter1OvercurrentError, 29, INVERTER_1_OVERCURRENT_ERROR_MASK)
    DEFINE_PROPERTY_MASK_BOOL(Inverter2OvercurrentError, 29, INVERTER_2_OVERCURRENT_ERROR_MASK)
    DEFINE_PROPERTY_MASK_BOOL(Inverter3OvercurrentError, 29, INVERTER_3_OVERCURRENT_ERROR_MASK)
    DEFINE_PROPERTY_MASK_BOOL(Inverter4OvercurrentError, 31, INVERTER_4_OVERCURRENT_ERROR_MASK)

    DEFINE_PROPERTY_MASK_BOOL(Inverter5OvercurrentError, 31, INVERTER_5_OVERCURRENT_ERROR_MASK)
    DEFINE_PROPERTY_MASK_BOOL(Inverter6OvercurrentError, 31, INVERTER_6_OVERCURRENT_ERROR_MASK)
    DEFINE_PROPERTY_MASK_BOOL(DcOvervoltageError, 31, DC_OVERVOLTAGE_ERROR_MASK)
    DEFINE_PROPERTY_MASK_BOOL(DcUndervoltageError, 31, DC_UNDERVOLTAGE_ERROR_MASK)
    DEFINE_PROPERTY_MASK_BOOL(DoubleCanIdOnBus, 31, DOUBLE_CAN_ID_ON_BUS_MASK)
    DEFINE_PROPERTY_MASK_BOOL(CanCommsTimeoutError, 31, CAN_COMMS_TIMEOUT_ERROR_MASK)
    DEFINE_PROPERTY_MASK_BOOL(Inverter1FaultError, 31, INVERTER_1_FAULT_ERROR_MASK)
    DEFINE_PROPERTY_MASK_BOOL(Inverter2FaultError, 32, INVERTER_2_FAULT_ERROR_MASK)
    DEFINE_PROPERTY_MASK_BOOL(Inverter3FaultError, 32, INVERTER_3_FAULT_ERROR_MASK)
    DEFINE_PROPERTY_MASK_BOOL(Inverter4FaultError, 32, INVERTER_4_FAULT_ERROR_MASK)
    DEFINE_PROPERTY_MASK_BOOL(Inverter5FaultError, 32, INVERTER_5_FAULT_ERROR_MASK)
    DEFINE_PROPERTY_MASK_BOOL(Inverter6FaultError, 32, INVERTER_6_FAULT_ERROR_MASK)
    DEFINE_PROPERTY_MASK_BOOL(CanSendError, 32, CAN_SEND_ERROR_MASK)
    DEFINE_PROPERTY_MASK_BOOL(LostFramesOnCanBusError, 32, LOST_FRAMES_ON_CAN_BUS_ERROR_MASK)
    DEFINE_PROPERTY_MASK_BOOL(OverspeedError, 32, OVERSPEED_ERROR_MASK)
    DEFINE_PROPERTY_MASK_BOOL(CpuOverloaded, 33, CPU_OVERLOADED_MASK)

    Q_PROPERTY(QString byteStreamStr READ byteStreamStr NOTIFY byteStreamStrChanged FINAL)
    Q_PROPERTY(QString encodedByteStreamStr READ encodedByteStreamStr NOTIFY encodedByteStreamStrChanged FINAL)

public:
    explicit MotorDetails(int motor, QObject *parent = nullptr);

    QByteArray encodedByteStream() const { return encodedByteStream_; }

    QString encodedByteStreamStr() const;
    QString byteStreamStr() const;


signals:
    void byteStreamStrChanged();
    void encodedByteStreamStrChanged();

private:
    QByteArray byteStream_;
    QByteArray encodedByteStream_;

    void updateByteStream();
};

#endif // MOTORDETAILS_H
