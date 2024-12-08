#ifndef BATTERY_H
#define BATTERY_H

#include <QObject>

class Battery : public QObject
{
    Q_OBJECT
public:
    explicit Battery(QObject *parent = nullptr);

    Q_PROPERTY(bool bmuAlive READ bmuAlive WRITE setBmuAlive NOTIFY bmuAliveChanged FINAL)
    Q_PROPERTY(bool dischargeRelay READ dischargeRelay WRITE setDischargeRelay NOTIFY dischargeRelayChanged FINAL)
    Q_PROPERTY(bool chargeRelay READ chargeRelay WRITE setChargeRelay NOTIFY chargeRelayChanged FINAL)
    Q_PROPERTY(bool chargerSafety READ chargerSafety WRITE setChargerSafety NOTIFY chargerSafetyChanged FINAL)
    Q_PROPERTY(bool malfunctionIndicator READ malfunctionIndicator WRITE setMalfunctionIndicator NOTIFY malfunctionIndicatorChanged FINAL)
    Q_PROPERTY(bool multiPurposeInputSignal READ multiPurposeInputSignal WRITE setMultiPurposeInputSignal NOTIFY multiPurposeInputSignalChanged FINAL)
    Q_PROPERTY(bool alwaysOnSignal READ alwaysOnSignal WRITE setAlwaysOnSignal NOTIFY alwaysOnSignalChanged FINAL)
    Q_PROPERTY(bool isReadySignal READ isReadySignal WRITE setIsReadySignal NOTIFY isReadySignalChanged FINAL)
    Q_PROPERTY(bool isChargingSignal READ isChargingSignal WRITE setIsChargingSignal NOTIFY isChargingSignalChanged FINAL)

    Q_PROPERTY(int populatedCells READ populatedCells WRITE setPopulatedCells NOTIFY populatedCellsChanged FINAL)
    Q_PROPERTY(float input12V READ input12V WRITE setInput12V NOTIFY input12VChanged FINAL)
    Q_PROPERTY(float fanVoltage READ fanVoltage WRITE setFanVoltage NOTIFY fanVoltageChanged FINAL)
    Q_PROPERTY(float packCurrent READ packCurrent WRITE setPackCurrent NOTIFY packCurrentChanged FINAL)
    Q_PROPERTY(float packVoltage READ packVoltage WRITE setPackVoltage NOTIFY packVoltageChanged FINAL)
    Q_PROPERTY(float packSoc READ packSoc WRITE setPackSoc NOTIFY packSocChanged FINAL)
    Q_PROPERTY(float packAmphours READ packAmphours WRITE setPackAmphours NOTIFY packAmphoursChanged FINAL)

    Q_PROPERTY(float packDod READ packDod WRITE setPackDod NOTIFY packDodChanged FINAL)
    Q_PROPERTY(int highTemp READ highTemp WRITE setHighTemp NOTIFY highTempChanged FINAL)
    Q_PROPERTY(int highThermistorId READ highThermistorId WRITE setHighThermistorId NOTIFY highThermistorIdChanged FINAL)
    Q_PROPERTY(int lowTemp READ lowTemp WRITE setLowTemp NOTIFY lowTempChanged FINAL)
    Q_PROPERTY(int lowThermistorId READ lowThermistorId WRITE setLowThermistorId NOTIFY lowThermistorIdChanged FINAL)
    Q_PROPERTY(int avgTemp READ avgTemp WRITE setAvgTemp NOTIFY avgTempChanged FINAL)
    Q_PROPERTY(int internalTemp READ internalTemp WRITE setInternalTemp NOTIFY internalTempChanged FINAL)

    Q_PROPERTY(int fanSpeed READ fanSpeed WRITE setFanSpeed NOTIFY fanSpeedChanged FINAL)
    Q_PROPERTY(int reqFanSpeed READ reqFanSpeed WRITE setReqFanSpeed NOTIFY reqFanSpeedChanged FINAL)
    Q_PROPERTY(int lowCellVoltage READ lowCellVoltage WRITE setLowCellVoltage NOTIFY lowCellVoltageChanged FINAL)
    Q_PROPERTY(int lowCellVoltageId READ lowCellVoltageId WRITE setLowCellVoltageId NOTIFY lowCellVoltageIdChanged FINAL)
    Q_PROPERTY(int highCellVoltage READ highCellVoltage WRITE setHighCellVoltage NOTIFY highCellVoltageChanged FINAL)
    Q_PROPERTY(int highCellVoltageId READ highCellVoltageId WRITE setHighCellVoltageId NOTIFY highCellVoltageIdChanged FINAL)
    Q_PROPERTY(int avgCellVoltage READ avgCellVoltage WRITE setAvgCellVoltage NOTIFY avgCellVoltageChanged FINAL)

    Q_PROPERTY(QString byteStreamStr READ byteStreamStr NOTIFY byteStreamStrChanged FINAL)
    Q_PROPERTY(QString encodedByteStreamStr READ encodedByteStreamStr NOTIFY encodedByteStreamStrChanged FINAL)

    bool bmuAlive() const;
    bool dischargeRelay() const;
    bool chargeRelay() const;
    bool chargerSafety() const;
    bool malfunctionIndicator() const;
    bool multiPurposeInputSignal() const;
    bool alwaysOnSignal() const;
    bool isReadySignal() const;
    bool isChargingSignal() const;

    int populatedCells() const;
    float input12V() const;
    float fanVoltage() const;
    float packCurrent() const;
    float packVoltage() const;
    float packSoc() const;
    float packAmphours() const;

    float packDod() const;
    int highTemp() const;
    int highThermistorId() const;
    int lowTemp() const;
    int lowThermistorId() const;
    int avgTemp() const;
    int internalTemp() const;

    int fanSpeed() const;
    int reqFanSpeed() const;
    int lowCellVoltage() const;
    int lowCellVoltageId() const;
    int highCellVoltage() const;
    int highCellVoltageId() const;
    int avgCellVoltage() const;

    QByteArray byteStream() const;
    QByteArray encodedByteStream() const; //HERE
    QString byteStreamStr() const;
    QString encodedByteStreamStr() const; //HERE

public slots:
    void setBmuAlive(bool on);
    void setDischargeRelay(bool on);
    void setChargeRelay(bool on);
    void setChargerSafety(bool on);
    void setMalfunctionIndicator(bool on);
    void setMultiPurposeInputSignal(bool on);
    void setAlwaysOnSignal(bool on);
    void setIsReadySignal(bool on);
    void setIsChargingSignal(bool on);

    void setPopulatedCells(int i);
    void setInput12V(float i);
    void setFanVoltage(float i);
    void setPackCurrent(float i);
    void setPackVoltage(float i);
    void setPackSoc(float i);
    void setPackAmphours(float i);

    void setPackDod(float i);
    void setHighTemp(int i);
    void setHighThermistorId(int i);
    void setLowTemp(int i);
    void setLowThermistorId(int i);
    void setAvgTemp(int i);
    void setInternalTemp(int i);

    void setFanSpeed(int i);
    void setReqFanSpeed(int i);
    void setLowCellVoltage(int i);
    void setLowCellVoltageId(int i);
    void setHighCellVoltage(int i);
    void setHighCellVoltageId(int i);
    void setAvgCellVoltage(int i);

signals:
    void bmuAliveChanged(bool on);
    void dischargeRelayChanged(bool on);
    void chargeRelayChanged(bool on);
    void chargerSafetyChanged(bool on);
    void malfunctionIndicatorChanged(bool on);
    void multiPurposeInputSignalChanged(bool on);
    void alwaysOnSignalChanged(bool on);
    void isReadySignalChanged(bool on);
    void isChargingSignalChanged(bool on);

    void populatedCellsChanged(int i);
    void input12VChanged(float i);
    void fanVoltageChanged(float i);
    void packCurrentChanged(float i);
    void packVoltageChanged(float i);
    void packSocChanged(float i);
    void packAmphoursChanged(float i);

    void packDodChanged(float i);
    void highTempChanged(int i);
    void highThermistorIdChanged(int i);
    void lowTempChanged(int i);
    void lowThermistorIdChanged(int i);
    void avgTempChanged(int i);
    void internalTempChanged(int i);

    void fanSpeedChanged(int i);
    void reqFanSpeedChanged(int i);
    void lowCellVoltageChanged(int i);
    void lowCellVoltageIdChanged(int i);
    void highCellVoltageChanged(int i);
    void highCellVoltageIdChanged(int i);
    void avgCellVoltageChanged(int i);

    void byteStreamStrChanged();
    void encodedByteStreamStrChanged();

private:
    bool bmuAlive_ = false;
    bool dischargeRelay_ = false;
    bool chargeRelay_ = false;
    bool chargerSafety_ = false;
    bool malfunctionIndicator_ = false;
    bool multiPurposeInputSignal_ = false;
    bool alwaysOnSignal_ = false;
    bool isReadySignal_ = false;
    bool isChargingSignal_ = false;

    int populatedCells_ = 0;
    float input12V_ = 0.0;
    float fanVoltage_ = 0.0;
    float packCurrent_ = 0;
    float packVoltage_ = 0;
    float packSoc_ = 0;
    float packAmphours_ = 0;

    float packDod_ = 0;
    int highTemp_ = 0;
    int highThermistorId_ = 0;
    int lowTemp_ = 0;
    int lowThermistorId_ = 0;
    int avgTemp_ = 0;
    int internalTemp_ = 0;

    int fanSpeed_ = 0;
    int reqFanSpeed_ = 0;
    int lowCellVoltage_ = 0;
    int lowCellVoltageId_ = 0;
    int highCellVoltage_ = 0;
    int highCellVoltageId_ = 0;
    int avgCellVoltage_ = 0;

    QByteArray byteStream_;
    QByteArray encodedByteStream_;

    void updateByteStream();

};

#endif // BATTERY_H
