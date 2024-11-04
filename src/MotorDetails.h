#ifndef MOTORDETAILS_H
#define MOTORDETAILS_H

#include <QObject>

class MotorDetails : public QObject
{
    Q_OBJECT
public:
    explicit MotorDetails(int motor, QObject *parent = nullptr);
    // NOT SURE TO KEEP
    Q_PROPERTY(int motorNum READ motorNum WRITE setMotorNum NOTIFY motorNumChanged FINAL)

    Q_PROPERTY(short controlValue READ controlValue WRITE setControlValue NOTIFY controlValueChanged FINAL)
    Q_PROPERTY(bool controlMode READ controlMode NOTIFY controlModeChanged FINAL)
    Q_PROPERTY(bool motorMode READ motorMode NOTIFY motorModeChanged FINAL)
    Q_PROPERTY(bool softwareEnable READ softwareEnable NOTIFY softwareEnableChanged FINAL)
    Q_PROPERTY(bool debugMode READ debugMode NOTIFY debugModeChanged FINAL)
    Q_PROPERTY(short currentMotorTorque READ currentMotorTorque WRITE setCurrentMotorTorque NOTIFY currentMotorTorqueChanged FINAL)
    Q_PROPERTY(short currentRpmValue READ currentRpmValue WRITE setCurrentRpmValue NOTIFY currentRpmValueChanged FINAL)
    Q_PROPERTY(char motorTemperature READ motorTemperature WRITE setMotorTemperature NOTIFY motorTemperatureChanged FINAL)
    Q_PROPERTY(short inverterPeakCurrent READ inverterPeakCurrent WRITE setInverterPeakCurrent NOTIFY inverterPeakCurrentChanged FINAL)
    Q_PROPERTY(short currentMotorPower READ currentMotorPower WRITE setCurrentMotorPower NOTIFY currentMotorPowerChanged FINAL)
    Q_PROPERTY(unsigned short absoluteAngle READ absoluteAngle WRITE setAbsoluteAngle NOTIFY absoluteAngleChanged FINAL)
    Q_PROPERTY(bool motorAboutToStall READ motorAboutToStall NOTIFY motorAboutToStallChanged FINAL)
    Q_PROPERTY(bool delayInReadingTempSensor READ delayInReadingTempSensor NOTIFY delayInReadingTempSensorChanged FINAL)
    Q_PROPERTY(bool delayInReadingPosSensor READ delayInReadingPosSensor NOTIFY delayInReadingPosSensorChanged FINAL)
    Q_PROPERTY(bool inverter1TempVeryHigh READ inverter1TempVeryHigh NOTIFY inverter1TempVeryHighChanged FINAL)
    Q_PROPERTY(bool inverter2TempVeryHigh READ inverter2TempVeryHigh NOTIFY inverter2TempVeryHighChanged FINAL)
    Q_PROPERTY(bool inverter3TempVeryHigh READ inverter3TempVeryHigh NOTIFY inverter3TempVeryHighChanged FINAL)
    Q_PROPERTY(bool inverter4TempVeryHigh READ inverter4TempVeryHigh NOTIFY inverter4TempVeryHighChanged FINAL)
    Q_PROPERTY(bool inverter5TempVeryHigh READ inverter5TempVeryHigh NOTIFY inverter5TempVeryHighChanged FINAL)
    Q_PROPERTY(bool inverter6TempVeryHigh READ inverter6TempVeryHigh NOTIFY inverter6TempVeryHighChanged FINAL)
    Q_PROPERTY(bool cpuTemperatureVeryHigh READ cpuTemperatureVeryHigh NOTIFY cpuTemperatureVeryHighChanged FINAL)
    Q_PROPERTY(bool hallTemperatureVeryHigh READ hallTemperatureVeryHigh NOTIFY hallTemperatureVeryHighChanged FINAL)
    Q_PROPERTY(bool dclinkTemperatureVeryHigh READ dclinkTemperatureVeryHigh NOTIFY dclinkTemperatureVeryHighChanged FINAL)
    Q_PROPERTY(bool delayInDclinkCommunication READ delayInDclinkCommunication NOTIFY delayInDclinkCommunicationChanged FINAL)
    Q_PROPERTY(bool inverter1OverCurrent READ inverter1OverCurrent NOTIFY inverter1OverCurrentChanged FINAL)
    Q_PROPERTY(bool inverter2OverCurrent READ inverter2OverCurrent NOTIFY inverter2OverCurrentChanged FINAL)
    Q_PROPERTY(bool inverter3OverCurrent READ inverter3OverCurrent NOTIFY inverter3OverCurrentChanged FINAL)
    Q_PROPERTY(bool inverter4OverCurrent READ inverter4OverCurrent NOTIFY inverter4OverCurrentChanged FINAL)
    Q_PROPERTY(bool inverter5OverCurrent READ inverter5OverCurrent NOTIFY inverter5OverCurrentChanged FINAL)
    Q_PROPERTY(bool inverter6OverCurrent READ inverter6OverCurrent NOTIFY inverter6OverCurrentChanged FINAL)
    Q_PROPERTY(bool dcOvervoltageWarning READ dcOvervoltageWarning NOTIFY dcOvervoltageWarningChanged FINAL)
    Q_PROPERTY(bool dcUndervoltageWarning READ dcUndervoltageWarning NOTIFY dcUndervoltageWarningChanged FINAL)
    Q_PROPERTY(bool canCommsTimeout READ canCommsTimeout NOTIFY canCommsTimeoutChanged FINAL)
    Q_PROPERTY(bool inverter1FaultWarning READ inverter1FaultWarning NOTIFY inverter1FaultWarningChanged FINAL)
    Q_PROPERTY(bool inverter2FaultWarning READ inverter2FaultWarning NOTIFY inverter2FaultWarningChanged FINAL)
    Q_PROPERTY(bool inverter3FaultWarning READ inverter3FaultWarning NOTIFY inverter3FaultWarningChanged FINAL)
    Q_PROPERTY(bool inverter4FaultWarning READ inverter4FaultWarning NOTIFY inverter4FaultWarningChanged FINAL)
    Q_PROPERTY(bool inverter5FaultWarning READ inverter5FaultWarning NOTIFY inverter5FaultWarningChanged FINAL)
    Q_PROPERTY(bool inverter6FaultWarning READ inverter6FaultWarning NOTIFY inverter6FaultWarningChanged FINAL)
    Q_PROPERTY(bool canSendWarning READ canSendWarning NOTIFY canSendWarningChanged FINAL)
    Q_PROPERTY(bool lostFramesOnCanBusWarning READ lostFramesOnCanBusWarning NOTIFY lostFramesOnCanBusWarningChanged FINAL)
    Q_PROPERTY(bool overspeedWarning READ overspeedWarning NOTIFY overspeedWarningChanged FINAL)
    Q_PROPERTY(bool cpuOverload READ cpuOverload NOTIFY cpuOverloadChanged FINAL)
    Q_PROPERTY(bool torqueLimited READ torqueLimited NOTIFY torqueLimitedChanged FINAL)
    Q_PROPERTY(bool startAtHighRpm READ startAtHighRpm NOTIFY startAtHighRpmChanged FINAL)
    Q_PROPERTY(bool initError READ initError NOTIFY initErrorChanged FINAL)
    Q_PROPERTY(bool settingsNotFound READ settingsNotFound NOTIFY settingsNotFoundChanged FINAL)
    Q_PROPERTY(bool motorStalled READ motorStalled NOTIFY motorStalledChanged FINAL)
    Q_PROPERTY(bool controllerDataReadingTimeout READ controllerDataReadingTimeout NOTIFY controllerDataReadingTimeoutChanged FINAL)
    Q_PROPERTY(bool invalidHallSensorSequence READ invalidHallSensorSequence NOTIFY invalidHallSensorSequenceChanged FINAL)
    Q_PROPERTY(bool invalidHallSector READ invalidHallSector NOTIFY invalidHallSectorChanged FINAL)
    Q_PROPERTY(bool errorReadingTempSensor READ errorReadingTempSensor NOTIFY errorReadingTempSensorChanged FINAL)
    Q_PROPERTY(bool positionSensorReadingError READ positionSensorReadingError NOTIFY positionSensorReadingErrorChanged FINAL)
    Q_PROPERTY(bool errorReadingEncoder READ errorReadingEncoder NOTIFY errorReadingEncoderChanged FINAL)
    Q_PROPERTY(bool zeroPositionOffsetNotSet READ zeroPositionOffsetNotSet NOTIFY zeroPositionOffsetNotSetChanged FINAL)
    Q_PROPERTY(bool hwEnableNotSet READ hwEnableNotSet NOTIFY hwEnableNotSetChanged FINAL)
    Q_PROPERTY(bool inverter1TempTooHigh READ inverter1TempTooHigh NOTIFY inverter1TempTooHighChanged FINAL)
    Q_PROPERTY(bool inverter2TempTooHigh READ inverter2TempTooHigh NOTIFY inverter2TempTooHighChanged FINAL)
    Q_PROPERTY(bool inverter3TempTooHigh READ inverter3TempTooHigh NOTIFY inverter3TempTooHighChanged FINAL)
    Q_PROPERTY(bool inverter4TempTooHigh READ inverter4TempTooHigh NOTIFY inverter4TempTooHighChanged FINAL)
    Q_PROPERTY(bool inverter5TempTooHigh READ inverter5TempTooHigh NOTIFY inverter5TempTooHighChanged FINAL)
    Q_PROPERTY(bool inverter6TempTooHigh READ inverter6TempTooHigh NOTIFY inverter6TempTooHighChanged FINAL)
    Q_PROPERTY(bool cpuTemperatureTooHigh READ cpuTemperatureTooHigh NOTIFY cpuTemperatureTooHighChanged FINAL)
    Q_PROPERTY(bool hallTemperatureTooHigh READ hallTemperatureTooHigh NOTIFY hallTemperatureTooHighChanged FINAL)
    Q_PROPERTY(bool dclinkTemperatureTooHigh READ dclinkTemperatureTooHigh NOTIFY dclinkTemperatureTooHighChanged FINAL)
    Q_PROPERTY(bool errorInDclinkCommunication READ errorInDclinkCommunication NOTIFY errorInDclinkCommunicationChanged FINAL)
    Q_PROPERTY(bool inverter1Overcurrent READ inverter1Overcurrent NOTIFY inverter1OvercurrentChanged FINAL)
    Q_PROPERTY(bool inverter2Overcurrent READ inverter2Overcurrent NOTIFY inverter2OvercurrentChanged FINAL)
    Q_PROPERTY(bool inverter3Overcurrent READ inverter3Overcurrent NOTIFY inverter3OvercurrentChanged FINAL)
    Q_PROPERTY(bool inverter4Overcurrent READ inverter4Overcurrent NOTIFY inverter4OvercurrentChanged FINAL)
    Q_PROPERTY(bool inverter5Overcurrent READ inverter5Overcurrent NOTIFY inverter5OvercurrentChanged FINAL)
    Q_PROPERTY(bool inverter6Overcurrent READ inverter6Overcurrent NOTIFY inverter6OvercurrentChanged FINAL)
    Q_PROPERTY(bool dcOvervoltageError READ dcOvervoltageError NOTIFY dcOvervoltageErrorChanged FINAL)
    Q_PROPERTY(bool dcUndervoltageError READ dcUndervoltageError NOTIFY dcUndervoltageErrorChanged FINAL)
    Q_PROPERTY(bool doubleCanCommsTimeout READ doubleCanCommsTimeout NOTIFY doubleCanCommsTimeoutChanged FINAL)
    Q_PROPERTY(bool inverter1FaultError READ inverter1FaultError NOTIFY inverter1FaultErrorChanged FINAL)
    Q_PROPERTY(bool inverter2FaultError READ inverter2FaultError NOTIFY inverter2FaultErrorChanged FINAL)
    Q_PROPERTY(bool inverter3FaultError READ inverter3FaultError NOTIFY inverter3FaultErrorChanged FINAL)
    Q_PROPERTY(bool inverter4FaultError READ inverter4FaultError NOTIFY inverter4FaultErrorChanged FINAL)
    Q_PROPERTY(bool inverter5FaultError READ inverter5FaultError NOTIFY inverter5FaultErrorChanged FINAL)
    Q_PROPERTY(bool inverter6FaultError READ inverter6FaultError NOTIFY inverter6FaultErrorChanged FINAL)
    Q_PROPERTY(bool canSendError READ canSendError NOTIFY canSendErrorChanged FINAL)
    Q_PROPERTY(bool lostFramesOnCanBusError READ lostFramesOnCanBusError NOTIFY lostFramesOnCanBusErrorChanged FINAL)
    Q_PROPERTY(bool overspeedError READ overspeedError NOTIFY overspeedErrorChanged FINAL)
    Q_PROPERTY(bool cpuOverloaded READ cpuOverloaded NOTIFY cpuOverloadedChanged FINAL)
    Q_PROPERTY(bool canCommsTimeoutError READ canCommsTimeoutError NOTIFY canCommsTimeoutErrorChanged FINAL)

    Q_PROPERTY(QString byteStreamStr READ byteStreamStr NOTIFY byteStreamStrChanged FINAL)
    Q_PROPERTY(QString encodedByteStreamStr READ encodedByteStreamStr NOTIFY encodedByteStreamStrChanged FINAL)

    // NOT SURE TO KEEP
    int motorNum() const;


    short controlValue() const;
    bool controlMode() const;
    bool motorMode() const;
    bool softwareEnable() const;
    bool debugMode() const;
    short currentMotorTorque() const;
    short currentRpmValue() const;
    char motorTemperature() const;
    short inverterPeakCurrent() const;
    short currentMotorPower() const;
    unsigned short absoluteAngle() const;
    bool motorAboutToStall() const;
    bool delayInReadingTempSensor() const;
    bool delayInReadingPosSensor() const;
    bool inverter1TempVeryHigh() const;
    bool inverter2TempVeryHigh() const;
    bool inverter3TempVeryHigh() const;
    bool inverter4TempVeryHigh() const;
    bool inverter5TempVeryHigh() const;
    bool inverter6TempVeryHigh() const;
    bool cpuTemperatureVeryHigh() const;
    bool hallTemperatureVeryHigh() const;
    bool dclinkTemperatureVeryHigh() const;
    bool delayInDclinkCommunication() const;
    bool inverter1OverCurrent() const;
    bool inverter2OverCurrent() const;
    bool inverter3OverCurrent() const;
    bool inverter4OverCurrent() const;
    bool inverter5OverCurrent() const;
    bool inverter6OverCurrent() const;
    bool dcOvervoltageWarning() const;
    bool dcUndervoltageWarning() const;
    bool canCommsTimeout() const;
    bool inverter1FaultWarning() const;
    bool inverter2FaultWarning() const;
    bool inverter3FaultWarning() const;
    bool inverter4FaultWarning() const;
    bool inverter5FaultWarning() const;
    bool inverter6FaultWarning() const;
    bool canSendWarning() const;
    bool lostFramesOnCanBusWarning() const;
    bool overspeedWarning() const;
    bool cpuOverload() const;
    bool torqueLimited() const;
    bool startAtHighRpm() const;
    bool initError() const;
    bool settingsNotFound() const;
    bool motorStalled() const;
    bool controllerDataReadingTimeout() const;
    bool invalidHallSensorSequence() const;
    bool invalidHallSector() const;
    bool errorReadingTempSensor() const;
    bool positionSensorReadingError() const;
    bool errorReadingEncoder() const;
    bool zeroPositionOffsetNotSet() const;
    bool hwEnableNotSet() const;
    bool inverter1TempTooHigh() const;
    bool inverter2TempTooHigh() const;
    bool inverter3TempTooHigh() const;
    bool inverter4TempTooHigh() const;
    bool inverter5TempTooHigh() const;
    bool inverter6TempTooHigh() const;
    bool cpuTemperatureTooHigh() const;
    bool hallTemperatureTooHigh() const;
    bool dclinkTemperatureTooHigh() const;
    bool errorInDclinkCommunication() const;
    bool inverter1Overcurrent() const;
    bool inverter2Overcurrent() const;
    bool inverter3Overcurrent() const;
    bool inverter4Overcurrent() const;
    bool inverter5Overcurrent() const;
    bool inverter6Overcurrent() const;
    bool dcOvervoltageError() const;
    bool dcUndervoltageError() const;
    bool doubleCanCommsTimeout() const;
    bool inverter1FaultError() const;
    bool inverter2FaultError() const;
    bool inverter3FaultError() const;
    bool inverter4FaultError() const;
    bool inverter5FaultError() const;
    bool inverter6FaultError() const;
    bool canSendError() const;
    bool lostFramesOnCanBusError() const;
    bool overspeedError() const;
    bool cpuOverloaded() const;
    bool canCommsTimeoutError() const;


    QByteArray byteStream() const;
    QByteArray encodedByteStream() const;
    QString byteStreamStr() const;
    QString encodedByteStreamStr() const;

public slots:
    // NOT SURE TO KEEP
    void setMotorNum(int i);

    void setControlValue(short newControlValue);
    void setControlMode(bool newControlMode);
    void setMotorMode(bool newMotorMode);
    void setSoftwareEnable(bool newSoftwareEnable);
    void setDebugMode(bool newDebugMode);
    void setCurrentMotorTorque(short newCurrentMotorTorque);
    void setCurrentRpmValue(short newCurrentRpmValue);
    void setMotorTemperature(char newMotorTemperature);
    void setInverterPeakCurrent(short newInverterPeakCurrent);
    void setCurrentMotorPower(short newCurrentMotorPower);
    void setAbsoluteAngle(unsigned short newAbsoluteAngle);
    void setMotorAboutToStall(bool newMotorAboutToStall);
    void setDelayInReadingTempSensor(bool newDelayInReadingTempSensor);
    void setDelayInReadingPosSensor(bool newDelayInReadingPosSensor);
    void setInverter1TempVeryHigh(bool newInverter1TempVeryHigh);
    void setInverter2TempVeryHigh(bool newInverter2TempVeryHigh);
    void setInverter3TempVeryHigh(bool newInverter3TempVeryHigh);
    void setInverter4TempVeryHigh(bool newInverter4TempVeryHigh);
    void setInverter5TempVeryHigh(bool newInverter5TempVeryHigh);
    void setInverter6TempVeryHigh(bool newInverter6TempVeryHigh);
    void setCpuTemperatureVeryHigh(bool newCpuTemperatureVeryHigh);
    void setHallTemperatureVeryHigh(bool newHallTemperatureVeryHigh);
    void setDclinkTemperatureVeryHigh(bool newDclinkTemperatureVeryHigh);
    void setDelayInDclinkCommunication(bool newDelayInDclinkCommunication);
    void setInverter1OverCurrent(bool newInverter1OverCurrent);
    void setInverter2OverCurrent(bool newInverter2OverCurrent);
    void setInverter3OverCurrent(bool newInverter3OverCurrent);
    void setInverter4OverCurrent(bool newInverter4OverCurrent);
    void setInverter5OverCurrent(bool newInverter5OverCurrent);
    void setInverter6OverCurrent(bool newInverter6OverCurrent);
    void setDcOvervoltageWarning(bool newDcOvervoltageWarning);
    void setDcUndervoltageWarning(bool newDcUndervoltageWarning);
    void setCanCommsTimeout(bool newCanCommsTimeout);
    void setInverter1FaultWarning(bool newInverter1FaultWarning);
    void setInverter2FaultWarning(bool newInverter2FaultWarning);
    void setInverter3FaultWarning(bool newInverter3FaultWarning);
    void setInverter4FaultWarning(bool newInverter4FaultWarning);
    void setInverter5FaultWarning(bool newInverter5FaultWarning);
    void setInverter6FaultWarning(bool newInverter6FaultWarning);
    void setCanSendWarning(bool newCanSendWarning);
    void setLostFramesOnCanBusWarning(bool newLostFramesOnCanBusWarning);
    void setOverspeedWarning(bool newOverspeedWarning);
    void setCpuOverload(bool newCpuOverload);
    void setTorqueLimited(bool newTorqueLimited);
    void setStartAtHighRpm(bool newStartAtHighRpm);
    void setInitError(bool newInitError);
    void setSettingsNotFound(bool newSettingsNotFound);
    void setMotorStalled(bool newMotorStalled);
    void setControllerDataReadingTimeout(bool newControllerDataReadingTimeout);
    void setInvalidHallSensorSequence(bool newInvalidHallSensorSequence);
    void setInvalidHallSector(bool newInvalidHallSector);
    void setErrorReadingTempSensor(bool newErrorReadingTempSensor);
    void setPositionSensorReadingError(bool newPositionSensorReadingError);
    void setErrorReadingEncoder(bool newErrorReadingEncoder);
    void setZeroPositionOffsetNotSet(bool newZeroPositionOffsetNotSet);
    void setHwEnableNotSet(bool newHwEnableNotSet);
    void setInverter1TempTooHigh(bool newInverter1TempTooHigh);
    void setInverter2TempTooHigh(bool newInverter2TempTooHigh);
    void setInverter3TempTooHigh(bool newInverter3TempTooHigh);
    void setInverter4TempTooHigh(bool newInverter4TempTooHigh);
    void setInverter5TempTooHigh(bool newInverter5TempTooHigh);
    void setInverter6TempTooHigh(bool newInverter6TempTooHigh);
    void setCpuTemperatureTooHigh(bool newCpuTemperatureTooHigh);
    void setHallTemperatureTooHigh(bool newHallTemperatureTooHigh);
    void setDclinkTemperatureTooHigh(bool newDclinkTemperatureTooHigh);
    void setErrorInDclinkCommunication(bool newErrorInDclinkCommunication);
    void setInverter1Overcurrent(bool newInverter1Overcurrent);
    void setInverter2Overcurrent(bool newInverter2Overcurrent);
    void setInverter3Overcurrent(bool newInverter3Overcurrent);
    void setInverter4Overcurrent(bool newInverter4Overcurrent);
    void setInverter5Overcurrent(bool newInverter5Overcurrent);
    void setInverter6Overcurrent(bool newInverter6Overcurrent);
    void setDcOvervoltageError(bool newDcOvervoltageError);
    void setDcUndervoltageError(bool newDcUndervoltageError);
    void setDoubleCanCommsTimeout(bool newDoubleCanCommsTimeout);
    void setInverter1FaultError(bool newInverter1FaultError);
    void setInverter2FaultError(bool newInverter2FaultError);
    void setInverter3FaultError(bool newInverter3FaultError);
    void setInverter4FaultError(bool newInverter4FaultError);
    void setInverter5FaultError(bool newInverter5FaultError);
    void setInverter6FaultError(bool newInverter6FaultError);
    void setCanSendError(bool newCanSendError);
    void setLostFramesOnCanBusError(bool newLostFramesOnCanBusError);
    void setOverspeedError(bool newOverspeedError);
    void setCpuOverloaded(bool newCpuOverloaded);
    void setCanCommsTimeoutError(bool newCanCommsTimeoutError);


signals:

    // NOT SURE TO KEEP
    void motorNumChanged(int i);

    void controlValueChanged(short newValue);
    void controlModeChanged(bool newControlMode);
    void motorModeChanged(bool newMotorMode);
    void softwareEnableChanged(bool newSoftwareEnable);
    void debugModeChanged(bool newDebugMode);
    void currentMotorTorqueChanged(short newTorque);
    void currentRpmValueChanged(short newRpm);
    void motorTemperatureChanged(char newTemperature);
    void inverterPeakCurrentChanged(short newPeakCurrent);
    void currentMotorPowerChanged(short newMotorPower);
    void absoluteAngleChanged(unsigned short newAngle);
    void motorAboutToStallChanged(bool newMotorAboutToStall);
    void delayInReadingTempSensorChanged(bool newDelayInReadingTempSensor);
    void delayInReadingPosSensorChanged(bool newDelayInReadingPosSensor);
    void inverter1TempVeryHighChanged(bool newInverter1TempVeryHigh);
    void inverter2TempVeryHighChanged(bool newInverter2TempVeryHigh);
    void inverter3TempVeryHighChanged(bool newInverter3TempVeryHigh);
    void inverter4TempVeryHighChanged(bool newInverter4TempVeryHigh);
    void inverter5TempVeryHighChanged(bool newInverter5TempVeryHigh);
    void inverter6TempVeryHighChanged(bool newInverter6TempVeryHigh);
    void cpuTemperatureVeryHighChanged(bool newCpuTemperatureVeryHigh);
    void hallTemperatureVeryHighChanged(bool newHallTemperatureVeryHigh);
    void dclinkTemperatureVeryHighChanged(bool newDclinkTemperatureVeryHigh);
    void delayInDclinkCommunicationChanged(bool newDelayInDclinkCommunication);
    void inverter1OverCurrentChanged(bool newInverter1OverCurrent);
    void inverter2OverCurrentChanged(bool newInverter2OverCurrent);
    void inverter3OverCurrentChanged(bool newInverter3OverCurrent);
    void inverter4OverCurrentChanged(bool newInverter4OverCurrent);
    void inverter5OverCurrentChanged(bool newInverter5OverCurrent);
    void inverter6OverCurrentChanged(bool newInverter6OverCurrent);
    void dcOvervoltageWarningChanged(bool newDcOvervoltageWarning);
    void dcUndervoltageWarningChanged(bool newDcUndervoltageWarning);
    void canCommsTimeoutChanged(bool newCanCommsTimeout);
    void inverter1FaultWarningChanged(bool newInverter1FaultWarning);
    void inverter2FaultWarningChanged(bool newInverter2FaultWarning);
    void inverter3FaultWarningChanged(bool newInverter3FaultWarning);
    void inverter4FaultWarningChanged(bool newInverter4FaultWarning);
    void inverter5FaultWarningChanged(bool newInverter5FaultWarning);
    void inverter6FaultWarningChanged(bool newInverter6FaultWarning);
    void canSendWarningChanged(bool newCanSendWarning);
    void lostFramesOnCanBusWarningChanged(bool newLostFramesOnCanBusWarning);
    void overspeedWarningChanged(bool newOverspeedWarning);
    void cpuOverloadChanged(bool newCpuOverload);
    void torqueLimitedChanged(bool newTorqueLimited);
    void startAtHighRpmChanged(bool newStartAtHighRpm);
    void initErrorChanged(bool newInitError);
    void settingsNotFoundChanged(bool newSettingsNotFound);
    void motorStalledChanged(bool newMotorStalled);
    void controllerDataReadingTimeoutChanged(bool newControllerDataReadingTimeout);
    void invalidHallSensorSequenceChanged(bool newInvalidHallSensorSequence);
    void invalidHallSectorChanged(bool newInvalidHallSector);
    void errorReadingTempSensorChanged(bool newErrorReadingTempSensor);
    void positionSensorReadingErrorChanged(bool newPositionSensorReadingError);
    void errorReadingEncoderChanged(bool newErrorReadingEncoder);
    void zeroPositionOffsetNotSetChanged(bool newZeroPositionOffsetNotSet);
    void hwEnableNotSetChanged(bool newHwEnableNotSet);
    void inverter1TempTooHighChanged(bool newInverter1TempTooHigh);
    void inverter2TempTooHighChanged(bool newInverter2TempTooHigh);
    void inverter3TempTooHighChanged(bool newInverter3TempTooHigh);
    void inverter4TempTooHighChanged(bool newInverter4TempTooHigh);
    void inverter5TempTooHighChanged(bool newInverter5TempTooHigh);
    void inverter6TempTooHighChanged(bool newInverter6TempTooHigh);
    void cpuTemperatureTooHighChanged(bool newCpuTemperatureTooHigh);
    void hallTemperatureTooHighChanged(bool newHallTemperatureTooHigh);
    void dclinkTemperatureTooHighChanged(bool newDclinkTemperatureTooHigh);
    void errorInDclinkCommunicationChanged(bool newErrorInDclinkCommunication);
    void inverter1OvercurrentChanged(bool newInverter1Overcurrent);
    void inverter2OvercurrentChanged(bool newInverter2Overcurrent);
    void inverter3OvercurrentChanged(bool newInverter3Overcurrent);
    void inverter4OvercurrentChanged(bool newInverter4Overcurrent);
    void inverter5OvercurrentChanged(bool newInverter5Overcurrent);
    void inverter6OvercurrentChanged(bool newInverter6Overcurrent);
    void dcOvervoltageErrorChanged(bool newDcOvervoltageError);
    void dcUndervoltageErrorChanged(bool newDcUndervoltageError);
    void doubleCanCommsTimeoutChanged(bool newDoubleCanCommsTimeout);
    void inverter1FaultErrorChanged(bool newInverter1FaultError);
    void inverter2FaultErrorChanged(bool newInverter2FaultError);
    void inverter3FaultErrorChanged(bool newInverter3FaultError);
    void inverter4FaultErrorChanged(bool newInverter4FaultError);
    void inverter5FaultErrorChanged(bool newInverter5FaultError);
    void inverter6FaultErrorChanged(bool newInverter6FaultError);
    void canSendErrorChanged(bool newCanSendError);
    void lostFramesOnCanBusErrorChanged(bool newLostFramesOnCanBusError);
    void overspeedErrorChanged(bool newOverspeedError);
    void cpuOverloadedChanged(bool newCpuOverloaded);
    void canCommsTimeoutErrorChanged(bool newCanCommsTimeoutError);

    void byteStreamStrChanged();
    void encodedByteStreamStrChanged();

private:
    // NOT SURE TO KEEP
    int motorNum_;

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
    bool inverter1OverCurrent_ = false;
    bool inverter2OverCurrent_ = false;
    bool inverter3OverCurrent_ = false;
    bool inverter4OverCurrent_ = false;
    bool inverter5OverCurrent_ = false;
    bool inverter6OverCurrent_ = false;
    bool dcOvervoltageWarning_ = false;
    bool dcUndervoltageWarning_ = false;
    bool canCommsTimeout_ = false;
    bool inverter1FaultWarning_ = false;
    bool inverter2FaultWarning_ = false;
    bool inverter3FaultWarning_ = false;
    bool inverter4FaultWarning_ = false;
    bool inverter5FaultWarning_ = false;
    bool inverter6FaultWarning_ = false;
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
    bool inverter1Overcurrent_ = false;
    bool inverter2Overcurrent_ = false;
    bool inverter3Overcurrent_ = false;
    bool inverter4Overcurrent_ = false;
    bool inverter5Overcurrent_ = false;
    bool inverter6Overcurrent_ = false;
    bool dcOvervoltageError_ = false;
    bool dcUndervoltageError_ = false;
    bool doubleCanCommsTimeout_ = false;
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
    bool canCommsTimeoutError_ = false;


    QByteArray byteStream_;
    QByteArray encodedByteStream_;
    void updateByteStream();

};

#endif // MOTORDETAILS_H
