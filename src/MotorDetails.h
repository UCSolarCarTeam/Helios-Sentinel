#ifndef MOTORDETAILS_H
#define MOTORDETAILS_H

#include <QObject>

class MotorDetails : public QObject {
    Q_OBJECT

    Q_PROPERTY(short controlValue READ controlValue WRITE setControlValue NOTIFY controlValueChanged FINAL)

    Q_PROPERTY(bool controlMode READ controlMode WRITE setControlMode NOTIFY controlModeChanged FINAL)
    Q_PROPERTY(bool motorMode READ motorMode WRITE setMotorMode NOTIFY motorModeChanged FINAL)
    Q_PROPERTY(bool softwareEnable READ softwareEnable WRITE setSoftwareEnable NOTIFY softwareEnableChanged FINAL)
    Q_PROPERTY(bool debugMode READ debugMode WRITE setDebugMode NOTIFY debugModeChanged FINAL)

    Q_PROPERTY(short currentMotorTorque READ currentMotorTorque WRITE setCurrentMotorTorque NOTIFY currentMotorTorqueChanged FINAL)
    Q_PROPERTY(short currentRpmValue READ currentRpmValue WRITE setCurrentRpmValue NOTIFY currentRpmValueChanged FINAL)
    Q_PROPERTY(char motorTemperature READ motorTemperature WRITE setMotorTemperature NOTIFY motorTemperatureChanged FINAL)
    Q_PROPERTY(short inverterPeakCurrent READ inverterPeakCurrent WRITE setInverterPeakCurrent NOTIFY inverterPeakCurrentChanged FINAL)
    Q_PROPERTY(short currentMotorPower READ currentMotorPower WRITE setCurrentMotorPower NOTIFY currentMotorPowerChanged FINAL)
    Q_PROPERTY(unsigned short absoluteAngle READ absoluteAngle WRITE setAbsoluteAngle NOTIFY absoluteAngleChanged FINAL)

    Q_PROPERTY(bool motorAboutToStall READ motorAboutToStall WRITE setMotorAboutToStall NOTIFY motorAboutToStallChanged FINAL)
    Q_PROPERTY(bool delayInReadingTempSensor READ delayInReadingTempSensor WRITE setDelayInReadingTempSensor NOTIFY delayInReadingTempSensorChanged FINAL)
    Q_PROPERTY(bool delayInReadingPosSensor READ delayInReadingPosSensor WRITE setDelayInReadingPosSensor NOTIFY delayInReadingPosSensorChanged FINAL)
    Q_PROPERTY(bool inverter1TempVeryHigh READ inverter1TempVeryHigh WRITE setInverter1TempVeryHigh NOTIFY inverter1TempVeryHighChanged FINAL)
    Q_PROPERTY(bool inverter2TempVeryHigh READ inverter2TempVeryHigh WRITE setInverter2TempVeryHigh NOTIFY inverter2TempVeryHighChanged FINAL)
    Q_PROPERTY(bool inverter3TempVeryHigh READ inverter3TempVeryHigh WRITE setInverter3TempVeryHigh NOTIFY inverter3TempVeryHighChanged FINAL)
    Q_PROPERTY(bool inverter4TempVeryHigh READ inverter4TempVeryHigh WRITE setInverter4TempVeryHigh NOTIFY inverter4TempVeryHighChanged FINAL)
    Q_PROPERTY(bool inverter5TempVeryHigh READ inverter5TempVeryHigh WRITE setInverter5TempVeryHigh NOTIFY inverter5TempVeryHighChanged FINAL)
    Q_PROPERTY(bool inverter6TempVeryHigh READ inverter6TempVeryHigh WRITE setInverter6TempVeryHigh NOTIFY inverter6TempVeryHighChanged FINAL)
    Q_PROPERTY(bool cpuTemperatureVeryHigh READ cpuTemperatureVeryHigh WRITE setCpuTemperatureVeryHigh NOTIFY cpuTemperatureVeryHighChanged FINAL)
    Q_PROPERTY(bool hallTemperatureVeryHigh READ hallTemperatureVeryHigh WRITE setHallTemperatureVeryHigh NOTIFY hallTemperatureVeryHighChanged FINAL)
    Q_PROPERTY(bool dclinkTemperatureVeryHigh READ dclinkTemperatureVeryHigh WRITE setDclinkTemperatureVeryHigh NOTIFY dclinkTemperatureVeryHighChanged FINAL)
    Q_PROPERTY(bool delayInDclinkCommunication READ delayInDclinkCommunication WRITE setDelayInDclinkCommunication NOTIFY delayInDclinkCommunicationChanged FINAL)
    Q_PROPERTY(bool inverter1OverCurrentWarning READ inverter1OverCurrentWarning WRITE setInverter1OverCurrentWarning NOTIFY inverter1OverCurrentWarningChanged FINAL)
    Q_PROPERTY(bool inverter2OverCurrentWarning READ inverter2OverCurrentWarning WRITE setInverter2OverCurrentWarning NOTIFY inverter2OverCurrentWarningChanged FINAL)
    Q_PROPERTY(bool inverter3OverCurrentWarning READ inverter3OverCurrentWarning WRITE setInverter3OverCurrentWarning NOTIFY inverter3OverCurrentWarningChanged FINAL)
    Q_PROPERTY(bool inverter4OverCurrentWarning READ inverter4OverCurrentWarning WRITE setInverter4OverCurrentWarning NOTIFY inverter4OverCurrentWarningChanged FINAL)
    Q_PROPERTY(bool inverter5OverCurrentWarning READ inverter5OverCurrentWarning WRITE setInverter5OverCurrentWarning NOTIFY inverter5OverCurrentWarningChanged FINAL)
    Q_PROPERTY(bool inverter6OverCurrentWarning READ inverter6OverCurrentWarning WRITE setInverter6OverCurrentWarning NOTIFY inverter6OverCurrentWarningChanged FINAL)
    Q_PROPERTY(bool dcOvervoltageWarning READ dcOvervoltageWarning WRITE setDcOvervoltageWarning NOTIFY dcOvervoltageWarningChanged FINAL)
    Q_PROPERTY(bool dcUndervoltageWarning READ dcUndervoltageWarning WRITE setDcUndervoltageWarning NOTIFY dcUndervoltageWarningChanged FINAL)
    Q_PROPERTY(bool canCommsTimeout READ canCommsTimeout WRITE setCanCommsTimeout NOTIFY canCommsTimeoutChanged FINAL)
    Q_PROPERTY(bool inverter1faultWarning READ inverter1faultWarning WRITE setInverter1faultWarning NOTIFY inverter1faultWarningChanged FINAL)
    Q_PROPERTY(bool inverter2faultWarning READ inverter2faultWarning WRITE setInverter2faultWarning NOTIFY inverter2faultWarningChanged FINAL)
    Q_PROPERTY(bool inverter3faultWarning READ inverter3faultWarning WRITE setInverter3faultWarning NOTIFY inverter3faultWarningChanged FINAL)
    Q_PROPERTY(bool inverter4faultWarning READ inverter4faultWarning WRITE setInverter4faultWarning NOTIFY inverter4faultWarningChanged FINAL)
    Q_PROPERTY(bool inverter5faultWarning READ inverter5faultWarning WRITE setInverter5faultWarning NOTIFY inverter5faultWarningChanged FINAL)
    Q_PROPERTY(bool inverter6faultWarning READ inverter6faultWarning WRITE setInverter6faultWarning NOTIFY inverter6faultWarningChanged FINAL)
    Q_PROPERTY(bool canSendWarning READ canSendWarning WRITE setCanSendWarning NOTIFY canSendWarningChanged FINAL)
    Q_PROPERTY(bool lostFramesOnCanBusWarning READ lostFramesOnCanBusWarning WRITE setLostFramesOnCanBusWarning NOTIFY lostFramesOnCanBusWarningChanged FINAL)
    Q_PROPERTY(bool overspeedWarning READ overspeedWarning WRITE setOverspeedWarning NOTIFY overspeedWarningChanged FINAL)
    Q_PROPERTY(bool cpuOverload READ cpuOverload WRITE setCpuOverload NOTIFY cpuOverloadChanged FINAL)
    Q_PROPERTY(bool torqueLimited READ torqueLimited WRITE setTorqueLimited NOTIFY torqueLimitedChanged FINAL)
    Q_PROPERTY(bool startAtHighRpm READ startAtHighRpm WRITE setStartAtHighRpm NOTIFY startAtHighRpmChanged FINAL)
    
    Q_PROPERTY(bool initError READ initError WRITE setInitError NOTIFY initErrorChanged FINAL)
    Q_PROPERTY(bool settingsNotFound READ settingsNotFound WRITE setSettingsNotFound NOTIFY settingsNotFoundChanged FINAL)
    Q_PROPERTY(bool motorStalled READ motorStalled WRITE setMotorStalled NOTIFY motorStalledChanged FINAL)
    Q_PROPERTY(bool controllerDataReadingTimeout READ controllerDataReadingTimeout WRITE setControllerDataReadingTimeout NOTIFY controllerDataReadingTimeoutChanged FINAL)
    Q_PROPERTY(bool invalidHallSensorSequence READ invalidHallSensorSequence WRITE setInvalidHallSensorSequence NOTIFY invalidHallSensorSequenceChanged FINAL)
    Q_PROPERTY(bool invalidHallSector READ invalidHallSector WRITE setInvalidHallSector NOTIFY invalidHallSectorChanged FINAL)
    Q_PROPERTY(bool errorReadingTempSensor READ errorReadingTempSensor WRITE setErrorReadingTempSensor NOTIFY errorReadingTempSensorChanged FINAL)
    Q_PROPERTY(bool positionSensorReadingError READ positionSensorReadingError WRITE setPositionSensorReadingError NOTIFY positionSensorReadingErrorChanged FINAL)
    Q_PROPERTY(bool errorReadingEncoder READ errorReadingEncoder WRITE setErrorReadingEncoder NOTIFY errorReadingEncoderChanged FINAL)
    Q_PROPERTY(bool zeroPositionOffsetNotSet READ zeroPositionOffsetNotSet WRITE setZeroPositionOffsetNotSet NOTIFY zeroPositionOffsetNotSetChanged FINAL)
    Q_PROPERTY(bool hwEnableNotSet READ hwEnableNotSet WRITE setHwEnableNotSet NOTIFY hwEnableNotSetChanged FINAL)
    Q_PROPERTY(bool inverter1TempTooHigh READ inverter1TempTooHigh WRITE setInverter1TempTooHigh NOTIFY inverter1TempTooHighChanged FINAL)
    Q_PROPERTY(bool inverter2TempTooHigh READ inverter2TempTooHigh WRITE setInverter2TempTooHigh NOTIFY inverter2TempTooHighChanged FINAL)
    Q_PROPERTY(bool inverter3TempTooHigh READ inverter3TempTooHigh WRITE setInverter3TempTooHigh NOTIFY inverter3TempTooHighChanged FINAL)
    Q_PROPERTY(bool inverter4TempTooHigh READ inverter4TempTooHigh WRITE setInverter4TempTooHigh NOTIFY inverter4TempTooHighChanged FINAL)
    Q_PROPERTY(bool inverter5TempTooHigh READ inverter5TempTooHigh WRITE setInverter5TempTooHigh NOTIFY inverter5TempTooHighChanged FINAL)
    Q_PROPERTY(bool inverter6TempTooHigh READ inverter6TempTooHigh WRITE setInverter6TempTooHigh NOTIFY inverter6TempTooHighChanged FINAL)
    Q_PROPERTY(bool cpuTemperatureTooHigh READ cpuTemperatureTooHigh WRITE setCpuTemperatureTooHigh NOTIFY cpuTemperatureTooHighChanged FINAL)
    Q_PROPERTY(bool hallTemperatureTooHigh READ hallTemperatureTooHigh WRITE setHallTemperatureTooHigh NOTIFY hallTemperatureTooHighChanged FINAL)
    Q_PROPERTY(bool dclinkTemperatureTooHigh READ dclinkTemperatureTooHigh WRITE setDclinkTemperatureTooHigh NOTIFY dclinkTemperatureTooHighChanged FINAL)
    Q_PROPERTY(bool errorInDclinkCommunication READ errorInDclinkCommunication WRITE setErrorInDclinkCommunication NOTIFY errorInDclinkCommunicationChanged FINAL)
    Q_PROPERTY(bool inverter1OvercurrentError READ inverter1OvercurrentError WRITE setInverter1OvercurrentError NOTIFY inverter1OvercurrentErrorChanged FINAL)
    Q_PROPERTY(bool inverter2OvercurrentError READ inverter2OvercurrentError WRITE setInverter2OvercurrentError NOTIFY inverter2OvercurrentErrorChanged FINAL)
    Q_PROPERTY(bool inverter3OvercurrentError READ inverter3OvercurrentError WRITE setInverter3OvercurrentError NOTIFY inverter3OvercurrentErrorChanged FINAL)
    Q_PROPERTY(bool inverter4OvercurrentError READ inverter4OvercurrentError WRITE setInverter4OvercurrentError NOTIFY inverter4OvercurrentErrorChanged FINAL)
    Q_PROPERTY(bool inverter5OvercurrentError READ inverter5OvercurrentError WRITE setInverter5OvercurrentError NOTIFY inverter5OvercurrentErrorChanged FINAL)
    Q_PROPERTY(bool inverter6OvercurrentError READ inverter6OvercurrentError WRITE setInverter6OvercurrentError NOTIFY inverter6OvercurrentErrorChanged FINAL)
    Q_PROPERTY(bool dcOvervoltageError READ dcOvervoltageError WRITE setDcOvervoltageError NOTIFY dcOvervoltageErrorChanged FINAL)
    Q_PROPERTY(bool dcUndervoltageError READ dcUndervoltageError WRITE setDcUndervoltageError NOTIFY dcUndervoltageErrorChanged FINAL)
    Q_PROPERTY(bool doubleCanIdOnBus READ doubleCanIdOnBus WRITE setDoubleCanIdOnBus NOTIFY doubleCanIdOnBusChanged FINAL)
    Q_PROPERTY(bool canCommsTimeoutError READ canCommsTimeoutError WRITE setCanCommsTimeoutError NOTIFY canCommsTimeoutErrorChanged FINAL)
    Q_PROPERTY(bool inverter1FaultError READ inverter1FaultError WRITE setInverter1FaultError NOTIFY inverter1FaultErrorChanged FINAL)
    Q_PROPERTY(bool inverter2FaultError READ inverter2FaultError WRITE setInverter2FaultError NOTIFY inverter2FaultErrorChanged FINAL)
    Q_PROPERTY(bool inverter3FaultError READ inverter3FaultError WRITE setInverter3FaultError NOTIFY inverter3FaultErrorChanged FINAL)
    Q_PROPERTY(bool inverter4FaultError READ inverter4FaultError WRITE setInverter4FaultError NOTIFY inverter4FaultErrorChanged FINAL)
    Q_PROPERTY(bool inverter5FaultError READ inverter5FaultError WRITE setInverter5FaultError NOTIFY inverter5FaultErrorChanged FINAL)
    Q_PROPERTY(bool inverter6FaultError READ inverter6FaultError WRITE setInverter6FaultError NOTIFY inverter6FaultErrorChanged FINAL)
    Q_PROPERTY(bool canSendError READ canSendError WRITE setCanSendError NOTIFY canSendErrorChanged FINAL)
    Q_PROPERTY(bool lostFramesOnCanBusError READ lostFramesOnCanBusError WRITE setLostFramesOnCanBusError NOTIFY lostFramesOnCanBusErrorChanged FINAL)
    Q_PROPERTY(bool overspeedError READ overspeedError WRITE setOverspeedError NOTIFY overspeedErrorChanged FINAL)
    Q_PROPERTY(bool cpuOverloaded READ cpuOverloaded WRITE setCpuOverloaded NOTIFY cpuOverloadedChanged FINAL)
    Q_PROPERTY(QString byteStreamStr READ byteStreamStr NOTIFY byteStreamStrChanged FINAL)
    Q_PROPERTY(QString encodedByteStreamStr READ encodedByteStreamStr NOTIFY encodedByteStreamStrChanged FINAL)

public:
    explicit MotorDetails(int motor, QObject *parent = nullptr);

    short controlValue() const { return controlValue_; }
    bool controlMode() const { return controlMode_; }
    bool motorMode() const { return motorMode_; }
    bool softwareEnable() const { return softwareEnable_; }
    bool debugMode() const { return debugMode_; }
    short currentMotorTorque() const { return currentMotorTorque_; }
    short currentRpmValue() const { return currentRpmValue_; }
    char motorTemperature() const { return motorTemperature_; }
    short inverterPeakCurrent() const { return inverterPeakCurrent_; }
    short currentMotorPower() const { return currentMotorPower_; }
    unsigned short absoluteAngle() const { return absoluteAngle_; }
    bool motorAboutToStall() const { return motorAboutToStall_; }
    bool delayInReadingTempSensor() const { return delayInReadingTempSensor_; }
    bool delayInReadingPosSensor() const { return delayInReadingPosSensor_; }
    bool inverter1TempVeryHigh() const { return inverter1TempVeryHigh_; }
    bool inverter2TempVeryHigh() const { return inverter2TempVeryHigh_; }
    bool inverter3TempVeryHigh() const { return inverter3TempVeryHigh_; }
    bool inverter4TempVeryHigh() const { return inverter4TempVeryHigh_; }
    bool inverter5TempVeryHigh() const { return inverter5TempVeryHigh_; }
    bool inverter6TempVeryHigh() const { return inverter6TempVeryHigh_; }
    bool cpuTemperatureVeryHigh() const { return cpuTemperatureVeryHigh_; }
    bool hallTemperatureVeryHigh() const { return hallTemperatureVeryHigh_; }
    bool dclinkTemperatureVeryHigh() const { return dclinkTemperatureVeryHigh_; }
    bool delayInDclinkCommunication() const { return delayInDclinkCommunication_; }
    bool inverter1OverCurrentWarning() const { return inverter1OverCurrentWarning_; }
    bool inverter2OverCurrentWarning() const { return inverter2OverCurrentWarning_; }
    bool inverter3OverCurrentWarning() const { return inverter3OverCurrentWarning_; }
    bool inverter4OverCurrentWarning() const { return inverter4OverCurrentWarning_; }
    bool inverter5OverCurrentWarning() const { return inverter5OverCurrentWarning_; }
    bool inverter6OverCurrentWarning() const { return inverter6OverCurrentWarning_; }
    bool dcOvervoltageWarning() const { return dcOvervoltageWarning_; }
    bool dcUndervoltageWarning() const { return dcUndervoltageWarning_; }
    bool canCommsTimeout() const { return canCommsTimeout_; }
    bool inverter1faultWarning() const { return inverter1faultWarning_; }
    bool inverter2faultWarning() const { return inverter2faultWarning_; }
    bool inverter3faultWarning() const { return inverter3faultWarning_; }
    bool inverter4faultWarning() const { return inverter4faultWarning_; }
    bool inverter5faultWarning() const { return inverter5faultWarning_; }
    bool inverter6faultWarning() const { return inverter6faultWarning_; }
    bool canSendWarning() const { return canSendWarning_; }
    bool lostFramesOnCanBusWarning() const { return lostFramesOnCanBusWarning_; }
    bool overspeedWarning() const { return overspeedWarning_; }
    bool cpuOverload() const { return cpuOverload_; }
    bool torqueLimited() const { return torqueLimited_; }
    bool startAtHighRpm() const { return startAtHighRpm_; }
    bool initError() const { return initError_; }
    bool settingsNotFound() const { return settingsNotFound_; }
    bool motorStalled() const { return motorStalled_; }
    bool controllerDataReadingTimeout() const { return controllerDataReadingTimeout_; }
    bool invalidHallSensorSequence() const { return invalidHallSensorSequence_; }
    bool invalidHallSector() const { return invalidHallSector_; }
    bool errorReadingTempSensor() const { return errorReadingTempSensor_; }
    bool positionSensorReadingError() const { return positionSensorReadingError_; }
    bool errorReadingEncoder() const { return errorReadingEncoder_; }
    bool zeroPositionOffsetNotSet() const { return zeroPositionOffsetNotSet_; }
    bool hwEnableNotSet() const { return hwEnableNotSet_; }
    bool inverter1TempTooHigh() const { return inverter1TempTooHigh_; }
    bool inverter2TempTooHigh() const { return inverter2TempTooHigh_; }
    bool inverter3TempTooHigh() const { return inverter3TempTooHigh_; }
    bool inverter4TempTooHigh() const { return inverter4TempTooHigh_; }
    bool inverter5TempTooHigh() const { return inverter5TempTooHigh_; }
    bool inverter6TempTooHigh() const { return inverter6TempTooHigh_; }
    bool cpuTemperatureTooHigh() const { return cpuTemperatureTooHigh_; }
    bool hallTemperatureTooHigh() const { return hallTemperatureTooHigh_; }
    bool dclinkTemperatureTooHigh() const { return dclinkTemperatureTooHigh_; }
    bool errorInDclinkCommunication() const { return errorInDclinkCommunication_; }
    bool inverter1OvercurrentError() const { return inverter1OvercurrentError_; }
    bool inverter2OvercurrentError() const { return inverter2OvercurrentError_; }
    bool inverter3OvercurrentError() const { return inverter3OvercurrentError_; }
    bool inverter4OvercurrentError() const { return inverter4OvercurrentError_; }
    bool inverter5OvercurrentError() const { return inverter5OvercurrentError_; }
    bool inverter6OvercurrentError() const { return inverter6OvercurrentError_; }
    bool dcOvervoltageError() const { return dcOvervoltageError_; }
    bool dcUndervoltageError() const { return dcUndervoltageError_; }
    bool doubleCanIdOnBus() const { return doubleCanIdOnBus_; }
    bool canCommsTimeoutError() const { return canCommsTimeoutError_; }
    bool inverter1FaultError() const { return inverter1FaultError_; }
    bool inverter2FaultError() const { return inverter2FaultError_; }
    bool inverter3FaultError() const { return inverter3FaultError_; }
    bool inverter4FaultError() const { return inverter4FaultError_; }
    bool inverter5FaultError() const { return inverter5FaultError_; }
    bool inverter6FaultError() const { return inverter6FaultError_; }
    bool canSendError() const { return canSendError_; }
    bool lostFramesOnCanBusError() const { return lostFramesOnCanBusError_; }
    bool overspeedError() const { return overspeedError_; }
    bool cpuOverloaded() const { return cpuOverloaded_; }

    QByteArray encodedByteStream() const { return encodedByteStream_; }

    QString encodedByteStreamStr() const;
    QString byteStreamStr() const;


public slots:
    void setControlValue(short value);
    void setControlMode(bool mode);
    void setMotorMode(bool mode);
    void setSoftwareEnable(bool enable);
    void setDebugMode(bool mode);
    void setCurrentMotorTorque(short torque);
    void setCurrentRpmValue(short rpm);
    void setMotorTemperature(char temperature);
    void setInverterPeakCurrent(short current);
    void setCurrentMotorPower(short power);
    void setAbsoluteAngle(unsigned short angle);
    void setMotorAboutToStall(bool stall);
    void setDelayInReadingTempSensor(bool delay);
    void setDelayInReadingPosSensor(bool delay);
    void setInverter1TempVeryHigh(bool high);
    void setInverter2TempVeryHigh(bool high);
    void setInverter3TempVeryHigh(bool high);
    void setInverter4TempVeryHigh(bool high);
    void setInverter5TempVeryHigh(bool high);
    void setInverter6TempVeryHigh(bool high);
    void setCpuTemperatureVeryHigh(bool high);
    void setHallTemperatureVeryHigh(bool high);
    void setDclinkTemperatureVeryHigh(bool high);
    void setDelayInDclinkCommunication(bool delay);
    void setInverter1OverCurrentWarning(bool warning);
    void setInverter2OverCurrentWarning(bool warning);
    void setInverter3OverCurrentWarning(bool warning);
    void setInverter4OverCurrentWarning(bool warning);
    void setInverter5OverCurrentWarning(bool warning);
    void setInverter6OverCurrentWarning(bool warning);
    void setDcOvervoltageWarning(bool warning);
    void setDcUndervoltageWarning(bool warning);
    void setCanCommsTimeout(bool timeout);
    void setInverter1faultWarning(bool warning);
    void setInverter2faultWarning(bool warning);
    void setInverter3faultWarning(bool warning);
    void setInverter4faultWarning(bool warning);
    void setInverter5faultWarning(bool warning);
    void setInverter6faultWarning(bool warning);
    void setCanSendWarning(bool warning);
    void setLostFramesOnCanBusWarning(bool warning);
    void setOverspeedWarning(bool warning);
    void setCpuOverload(bool overload);
    void setTorqueLimited(bool limited);
    void setStartAtHighRpm(bool start);
    void setInitError(bool error);
    void setSettingsNotFound(bool notFound);
    void setMotorStalled(bool stalled);
    void setControllerDataReadingTimeout(bool timeout);
    void setInvalidHallSensorSequence(bool sequence);
    void setInvalidHallSector(bool sector);
    void setErrorReadingTempSensor(bool error);
    void setPositionSensorReadingError(bool error);
    void setErrorReadingEncoder(bool error);
    void setZeroPositionOffsetNotSet(bool notSet);
    void setHwEnableNotSet(bool notSet);
    void setInverter1TempTooHigh(bool high);
    void setInverter2TempTooHigh(bool high);
    void setInverter3TempTooHigh(bool high);
    void setInverter4TempTooHigh(bool high);
    void setInverter5TempTooHigh(bool high);
    void setInverter6TempTooHigh(bool high);
    void setCpuTemperatureTooHigh(bool high);
    void setHallTemperatureTooHigh(bool high);
    void setDclinkTemperatureTooHigh(bool high);
    void setErrorInDclinkCommunication(bool error);
    void setInverter1OvercurrentError(bool error);
    void setInverter2OvercurrentError(bool error);
    void setInverter3OvercurrentError(bool error);
    void setInverter4OvercurrentError(bool error);
    void setInverter5OvercurrentError(bool error);
    void setInverter6OvercurrentError(bool error);
    void setDcOvervoltageError(bool error);
    void setDcUndervoltageError(bool error);
    void setDoubleCanIdOnBus(bool doubleId);
    void setCanCommsTimeoutError(bool error);
    void setInverter1FaultError(bool error);
    void setInverter2FaultError(bool error);
    void setInverter3FaultError(bool error);
    void setInverter4FaultError(bool error);
    void setInverter5FaultError(bool error);
    void setInverter6FaultError(bool error);
    void setCanSendError(bool error);
    void setLostFramesOnCanBusError(bool error);
    void setOverspeedError(bool error);
    void setCpuOverloaded(bool overloaded);

signals:
    void controlValueChanged();
    void controlModeChanged();
    void motorModeChanged();
    void softwareEnableChanged();
    void debugModeChanged();
    void currentMotorTorqueChanged();
    void currentRpmValueChanged();
    void motorTemperatureChanged();
    void inverterPeakCurrentChanged();
    void currentMotorPowerChanged();
    void absoluteAngleChanged();
    void motorAboutToStallChanged();
    void delayInReadingTempSensorChanged();
    void delayInReadingPosSensorChanged();
    void inverter1TempVeryHighChanged();
    void inverter2TempVeryHighChanged();
    void inverter3TempVeryHighChanged();
    void inverter4TempVeryHighChanged();
    void inverter5TempVeryHighChanged();
    void inverter6TempVeryHighChanged();
    void cpuTemperatureVeryHighChanged();
    void hallTemperatureVeryHighChanged();
    void dclinkTemperatureVeryHighChanged();
    void delayInDclinkCommunicationChanged();
    void inverter1OverCurrentWarningChanged();
    void inverter2OverCurrentWarningChanged();
    void inverter3OverCurrentWarningChanged();
    void inverter4OverCurrentWarningChanged();
    void inverter5OverCurrentWarningChanged();
    void inverter6OverCurrentWarningChanged();
    void dcOvervoltageWarningChanged();
    void dcUndervoltageWarningChanged();
    void canCommsTimeoutChanged();
    void inverter1faultWarningChanged();
    void inverter2faultWarningChanged();
    void inverter3faultWarningChanged();
    void inverter4faultWarningChanged();
    void inverter5faultWarningChanged();
    void inverter6faultWarningChanged();
    void canSendWarningChanged();
    void lostFramesOnCanBusWarningChanged();
    void overspeedWarningChanged();
    void cpuOverloadChanged();
    void torqueLimitedChanged();
    void startAtHighRpmChanged();
    void initErrorChanged();
    void settingsNotFoundChanged();
    void motorStalledChanged();
    void controllerDataReadingTimeoutChanged();
    void invalidHallSensorSequenceChanged();
    void invalidHallSectorChanged();
    void errorReadingTempSensorChanged();
    void positionSensorReadingErrorChanged();
    void errorReadingEncoderChanged();
    void zeroPositionOffsetNotSetChanged();
    void hwEnableNotSetChanged();
    void inverter1TempTooHighChanged();
    void inverter2TempTooHighChanged();
    void inverter3TempTooHighChanged();
    void inverter4TempTooHighChanged();
    void inverter5TempTooHighChanged();
    void inverter6TempTooHighChanged();
    void cpuTemperatureTooHighChanged();
    void hallTemperatureTooHighChanged();
    void dclinkTemperatureTooHighChanged();
    void errorInDclinkCommunicationChanged();
    void inverter1OvercurrentErrorChanged();
    void inverter2OvercurrentErrorChanged();
    void inverter3OvercurrentErrorChanged();
    void inverter4OvercurrentErrorChanged();
    void inverter5OvercurrentErrorChanged();
    void inverter6OvercurrentErrorChanged();
    void dcOvervoltageErrorChanged();
    void dcUndervoltageErrorChanged();
    void doubleCanIdOnBusChanged();
    void canCommsTimeoutErrorChanged();
    void inverter1FaultErrorChanged();
    void inverter2FaultErrorChanged();
    void inverter3FaultErrorChanged();
    void inverter4FaultErrorChanged();
    void inverter5FaultErrorChanged();
    void inverter6FaultErrorChanged();
    void canSendErrorChanged();
    void lostFramesOnCanBusErrorChanged();
    void overspeedErrorChanged();
    void cpuOverloadedChanged();
    void byteStreamStrChanged();
    void encodedByteStreamStrChanged();

private:
    short controlValue_ = 0;
    bool controlMode_ = false;
    bool motorMode_ = false;
    bool softwareEnable_ = false;
    bool debugMode_ = false;
    short currentMotorTorque_ = 0;
    short currentRpmValue_ = 0;
    char motorTemperature_ = 0;
    short inverterPeakCurrent_ = 0;
    short currentMotorPower_ = 0;
    unsigned short absoluteAngle_ = 0;
    bool motorAboutToStall_ = false;
    bool delayInReadingTempSensor_ = false;
    bool delayInReadingPosSensor_ = false;
    bool inverter1TempVeryHigh_ = false;
    bool inverter2TempVeryHigh_ = false;
    bool inverter3TempVeryHigh_ = false;
    bool inverter4TempVeryHigh_ = false;
    bool inverter5TempVeryHigh_ = false;
    bool inverter6TempVeryHigh_ = false;
    bool cpuTemperatureVeryHigh_ = false;
    bool hallTemperatureVeryHigh_ = false;
    bool dclinkTemperatureVeryHigh_ = false;
    bool delayInDclinkCommunication_ = false;
    bool inverter1OverCurrentWarning_ = false;
    bool inverter2OverCurrentWarning_ = false;
    bool inverter3OverCurrentWarning_ = false;
    bool inverter4OverCurrentWarning_ = false;
    bool inverter5OverCurrentWarning_ = false;
    bool inverter6OverCurrentWarning_ = false;
    bool dcOvervoltageWarning_ = false;
    bool dcUndervoltageWarning_ = false;
    bool canCommsTimeout_ = false;
    bool inverter1faultWarning_ = false;
    bool inverter2faultWarning_ = false;
    bool inverter3faultWarning_ = false;
    bool inverter4faultWarning_ = false;
    bool inverter5faultWarning_ = false;
    bool inverter6faultWarning_ = false;
    bool canSendWarning_ = false;
    bool lostFramesOnCanBusWarning_ = false;
    bool overspeedWarning_ = false;
    bool cpuOverload_ = false;
    bool torqueLimited_ = false;
    bool startAtHighRpm_ = false;
    bool initError_ = false;
    bool settingsNotFound_ = false;
    bool motorStalled_ = false;
    bool controllerDataReadingTimeout_ = false;
    bool invalidHallSensorSequence_ = false;
    bool invalidHallSector_ = false;
    bool errorReadingTempSensor_ = false;
    bool positionSensorReadingError_ = false;
    bool errorReadingEncoder_ = false;
    bool zeroPositionOffsetNotSet_ = false;
    bool hwEnableNotSet_ = false;
    bool inverter1TempTooHigh_ = false;
    bool inverter2TempTooHigh_ = false;
    bool inverter3TempTooHigh_ = false;
    bool inverter4TempTooHigh_ = false;
    bool inverter5TempTooHigh_ = false;
    bool inverter6TempTooHigh_ = false;
    bool cpuTemperatureTooHigh_ = false;
    bool hallTemperatureTooHigh_ = false;
    bool dclinkTemperatureTooHigh_ = false;
    bool errorInDclinkCommunication_ = false;
    bool inverter1OvercurrentError_ = false;
    bool inverter2OvercurrentError_ = false;
    bool inverter3OvercurrentError_ = false;
    bool inverter4OvercurrentError_ = false;
    bool inverter5OvercurrentError_ = false;
    bool inverter6OvercurrentError_ = false;
    bool dcOvervoltageError_ = false;
    bool dcUndervoltageError_ = false;
    bool doubleCanIdOnBus_ = false;
    bool canCommsTimeoutError_ = false;
    bool inverter1FaultError_ = false;
    bool inverter2FaultError_ = false;
    bool inverter3FaultError_ = false;
    bool inverter4FaultError_ = false;
    bool inverter5FaultError_ = false;
    bool inverter6FaultError_ = false;
    bool canSendError_ = false;
    bool lostFramesOnCanBusError_ = false;
    bool overspeedError_ = false;
    bool cpuOverloaded_ = false;

    QByteArray byteStream_;
    QByteArray encodedByteStream_;

    void updateByteStream();
};

#endif // MOTORDETAILS_H
