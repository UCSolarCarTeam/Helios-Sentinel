#ifndef MBMS_H
#define MBMS_H

#include <QObject>


class Mbms : public QObject
{
    Q_OBJECT
public:
    explicit Mbms(QObject *parent = nullptr);

    Q_PROPERTY(bool commonContactorState READ commonContactorState WRITE setCommonContactorState NOTIFY commonContactorStateChanged FINAL)
    Q_PROPERTY(bool motorContactorState READ motorContactorState WRITE setMotorContactorState NOTIFY motorContactorStateChanged FINAL)
    Q_PROPERTY(bool arrayContactorState READ arrayContactorState WRITE setArrayContactorState NOTIFY arrayContactorStateChanged FINAL)
    Q_PROPERTY(bool lvContactorState READ lvContactorState WRITE setLvContactorState NOTIFY lvContactorStateChanged FINAL)
    Q_PROPERTY(bool chargeContactorState READ chargeContactorState WRITE setChargeContactorState NOTIFY chargeContactorStateChanged FINAL)

    Q_PROPERTY(bool commonContactorError READ commonContactorError WRITE setCommonContactorError NOTIFY commonContactorErrorChanged FINAL)
    Q_PROPERTY(bool motorContactorError READ motorContactorError WRITE setMotorContactorError NOTIFY motorContactorErrorChanged FINAL)
    Q_PROPERTY(bool arrayContactorError READ arrayContactorError WRITE setArrayContactorError NOTIFY arrayContactorErrorChanged FINAL)
    Q_PROPERTY(bool lvContactorError READ lvContactorError WRITE setLvContactorError NOTIFY lvContactorErrorChanged FINAL)
    Q_PROPERTY(bool chargeContactorError READ chargeContactorError WRITE setChargeContactorError NOTIFY chargeContactorErrorChanged FINAL)

    Q_PROPERTY(bool strobeBmsLight READ strobeBmsLight WRITE setStrobeBmsLight NOTIFY strobeBmsLightChanged FINAL)
    Q_PROPERTY(bool allowCharge READ allowCharge WRITE setAllowCharge NOTIFY allowChargeChanged FINAL)
    Q_PROPERTY(bool highVoltageEnableState READ highVoltageEnableState WRITE setHighVoltageEnableState NOTIFY highVoltageEnableStateChanged FINAL)
    Q_PROPERTY(bool allowDischarge READ allowDischarge WRITE setAllowDischarge NOTIFY allowDischargeChanged FINAL)
    Q_PROPERTY(bool orionCanReceivedRecently READ orionCanReceivedRecently WRITE setOrionCanReceivedRecently NOTIFY orionCanReceivedRecentlyChanged FINAL)
    Q_PROPERTY(bool dischargeShouldTrip READ dischargeShouldTrip WRITE setDischargeShouldTrip NOTIFY dischargeShouldTripChanged FINAL)
    Q_PROPERTY(bool chargeShouldTrip READ chargeShouldTrip WRITE setChargeShouldTrip NOTIFY chargeShouldTripChanged FINAL)

    Q_PROPERTY(unsigned short auxillaryBatteryVoltage READ auxillaryBatteryVoltage WRITE setAuxillaryBatteryVoltage NOTIFY auxillaryBatteryVoltageChanged FINAL)
    Q_PROPERTY(unsigned short motorVoltage READ motorVoltage WRITE setMotorVoltage NOTIFY motorVoltageChanged FINAL)
    Q_PROPERTY(unsigned short arrayVoltage READ arrayVoltage WRITE setArrayVoltage NOTIFY arrayVoltageChanged FINAL)
    Q_PROPERTY(unsigned short lvVoltage READ lvVoltage WRITE setLvVoltage NOTIFY lvVoltageChanged FINAL)
    Q_PROPERTY(unsigned short chargeVoltage READ chargeVoltage WRITE setChargeVoltage NOTIFY chargeVoltageChanged FINAL)
    Q_PROPERTY(unsigned short commonCurrent READ commonCurrent WRITE setCommonCurrent NOTIFY commonCurrentChanged FINAL)
    Q_PROPERTY(unsigned short motorCurrent READ motorCurrent WRITE setMotorCurrent NOTIFY motorCurrentChanged FINAL)
    Q_PROPERTY(unsigned short arrayCurrent READ arrayCurrent WRITE setArrayCurrent NOTIFY arrayCurrentChanged FINAL)
    Q_PROPERTY(unsigned short lvCurrent READ lvCurrent WRITE setLvCurrent NOTIFY lvCurrentChanged FINAL)
    Q_PROPERTY(unsigned short chargeCurrent READ chargeCurrent WRITE setChargeCurrent NOTIFY chargeCurrentChanged FINAL)

    Q_PROPERTY(bool highCellVoltageTrip READ highCellVoltageTrip WRITE setHighCellVoltageTrip NOTIFY highCellVoltageTripChanged FINAL)
    Q_PROPERTY(bool lowCellVoltageTrip READ lowCellVoltageTrip WRITE setLowCellVoltageTrip NOTIFY lowCellVoltageTripChanged FINAL)
    Q_PROPERTY(bool highCommonCurrentTrip READ highCommonCurrentTrip WRITE setHighCommonCurrentTrip NOTIFY highCommonCurrentTripChanged FINAL)
    Q_PROPERTY(bool motorTCTrip READ motorTCTrip WRITE setMotorTCTrip NOTIFY motorTCTripChanged FINAL)
    Q_PROPERTY(bool arrayTCTrip READ arrayTCTrip WRITE setArrayTCTrip NOTIFY arrayTCTripChanged FINAL)
    Q_PROPERTY(bool lvTCTrip READ lvTCTrip WRITE setLvTCTrip NOTIFY lvTCTripChanged FINAL)
    Q_PROPERTY(bool chargeTCTrip READ chargeTCTrip WRITE setChargeTCTrip NOTIFY chargeTCTripChanged FINAL)
    Q_PROPERTY(bool protectionTrip READ protectionTrip WRITE setProtectionTrip NOTIFY protectionTripChanged FINAL)
    Q_PROPERTY(bool orionMessageTimeoutTrip READ orionMessageTimeoutTrip WRITE setOrionMessageTimeoutTrip NOTIFY orionMessageTimeoutTripChanged FINAL)
    Q_PROPERTY(bool contactorDisconnectedTrip READ contactorDisconnectedTrip WRITE setContactorDisconnectedTrip NOTIFY contactorDisconnectedTripChanged FINAL)

    Q_PROPERTY(QString byteStreamStr READ byteStreamStr NOTIFY byteStreamStrChanged FINAL)
    Q_PROPERTY(QString encodedByteStreamStr READ encodedByteStreamStr NOTIFY encodedByteStreamStrChanged FINAL)


    bool commonContactorState() const;
    bool motorContactorState() const;
    bool arrayContactorState() const;
    bool lvContactorState() const;
    bool chargeContactorState() const;

    bool commonContactorError() const;
    bool motorContactorError() const;
    bool arrayContactorError() const;
    bool lvContactorError() const;
    bool chargeContactorError() const;

    bool strobeBmsLight() const;
    bool allowCharge() const;
    bool highVoltageEnableState() const;
    bool allowDischarge() const;
    bool orionCanReceivedRecently() const;
    bool dischargeShouldTrip() const;
    bool chargeShouldTrip() const;

    unsigned short auxillaryBatteryVoltage() const;
    unsigned short motorVoltage() const;
    unsigned short arrayVoltage() const;
    unsigned short lvVoltage() const;
    unsigned short chargeVoltage() const;
    unsigned short commonCurrent() const;
    unsigned short motorCurrent() const;
    unsigned short arrayCurrent() const;
    unsigned short lvCurrent() const;
    unsigned short chargeCurrent() const;

    bool highCellVoltageTrip() const;
    bool lowCellVoltageTrip() const;
    bool highCommonCurrentTrip() const;
    bool motorTCTrip() const;
    bool arrayTCTrip() const;
    bool lvTCTrip() const;
    bool chargeTCTrip() const;
    bool protectionTrip() const;
    bool orionMessageTimeoutTrip() const;
    bool contactorDisconnectedTrip() const;

    QByteArray byteStream() const;
    QByteArray encodedByteStream() const;
    QString byteStreamStr() const;
    QString encodedByteStreamStr() const;


public slots:
    void setCommonContactorState(bool on);
    void setMotorContactorState(bool on);
    void setArrayContactorState(bool on);
    void setLvContactorState(bool on);
    void setChargeContactorState(bool on);

    void setCommonContactorError(bool on);
    void setMotorContactorError(bool on);
    void setArrayContactorError(bool on);
    void setLvContactorError(bool on);
    void setChargeContactorError(bool on);

    void setStrobeBmsLight(bool on);
    void setAllowCharge(bool on);
    void setHighVoltageEnableState(bool on);
    void setAllowDischarge(bool on);
    void setOrionCanReceivedRecently(bool on);
    void setDischargeShouldTrip(bool on);
    void setChargeShouldTrip(bool on);

    void setAuxillaryBatteryVoltage(unsigned short value);
    void setMotorVoltage(unsigned short value);
    void setArrayVoltage(unsigned short value);
    void setLvVoltage(unsigned short value);
    void setChargeVoltage(unsigned short value);
    void setCommonCurrent(unsigned short value);
    void setMotorCurrent(unsigned short value);
    void setArrayCurrent(unsigned short value);
    void setLvCurrent(unsigned short value);
    void setChargeCurrent(unsigned short value);

    void setHighCellVoltageTrip(bool on);
    void setLowCellVoltageTrip(bool on);
    void setHighCommonCurrentTrip(bool on);
    void setMotorTCTrip(bool on);
    void setArrayTCTrip(bool on);
    void setLvTCTrip(bool on);
    void setChargeTCTrip(bool on);
    void setProtectionTrip(bool on);
    void setOrionMessageTimeoutTrip(bool on);
    void setContactorDisconnectedTrip(bool on);

signals:
    void commonContactorStateChanged(bool on);
    void motorContactorStateChanged(bool on);
    void arrayContactorStateChanged(bool on);
    void lvContactorStateChanged(bool on);
    void chargeContactorStateChanged(bool on);

    void commonContactorErrorChanged(bool on);
    void motorContactorErrorChanged(bool on);
    void arrayContactorErrorChanged(bool on);
    void lvContactorErrorChanged(bool on);
    void chargeContactorErrorChanged(bool on);

    void strobeBmsLightChanged(bool on);
    void allowChargeChanged(bool on);
    void highVoltageEnableStateChanged(bool on);
    void allowDischargeChanged(bool on);
    void orionCanReceivedRecentlyChanged(bool on);
    void dischargeShouldTripChanged(bool on);
    void chargeShouldTripChanged(bool on);

    void auxillaryBatteryVoltageChanged(unsigned short value);
    void motorVoltageChanged(unsigned short value);
    void arrayVoltageChanged(unsigned short value);
    void lvVoltageChanged(unsigned short value);
    void chargeVoltageChanged(unsigned short value);
    void commonCurrentChanged(unsigned short value);
    void motorCurrentChanged(unsigned short value);
    void arrayCurrentChanged(unsigned short value);
    void lvCurrentChanged(unsigned short value);
    void chargeCurrentChanged(unsigned short value);

    void highCellVoltageTripChanged(bool on);
    void lowCellVoltageTripChanged(bool on);
    void highCommonCurrentTripChanged(bool on);
    void motorTCTripChanged(bool on);
    void arrayTCTripChanged(bool on);
    void lvTCTripChanged(bool on);
    void chargeTCTripChanged(bool on);
    void protectionTripChanged(bool on);
    void orionMessageTimeoutTripChanged(bool on);
    void contactorDisconnectedTripChanged(bool on);

    void byteStreamStrChanged();
    void encodedByteStreamStrChanged();


private:
    bool commonContactorState_;
    bool motorContactorState_;
    bool arrayContactorState_;
    bool lvContactorState_;
    bool chargeContactorState_;

    bool commonContactorError_;
    bool motorContactorError_;
    bool arrayContactorError_;
    bool lvContactorError_;
    bool chargeContactorError_;

    bool strobeBmsLight_;
    bool allowCharge_;
    bool highVoltageEnableState_;
    bool allowDischarge_;
    bool orionCanReceivedRecently_;
    bool dischargeShouldTrip_;
    bool chargeShouldTrip_;

    unsigned short auxillaryBatteryVoltage_;
    unsigned short motorVoltage_;
    unsigned short arrayVoltage_;
    unsigned short lvVoltage_;
    unsigned short chargeVoltage_;
    unsigned short commonCurrent_;
    unsigned short motorCurrent_;
    unsigned short arrayCurrent_;
    unsigned short lvCurrent_;
    unsigned short chargeCurrent_;

    bool highCellVoltageTrip_;
    bool lowCellVoltageTrip_;
    bool highCommonCurrentTrip_;
    bool motorTCTrip_;
    bool arrayTCTrip_;
    bool lvTCTrip_;
    bool chargeTCTrip_;
    bool protectionTrip_;
    bool orionMessageTimeoutTrip_;
    bool contactorDisconnectedTrip_;

    QByteArray byteStream_;
    QByteArray encodedByteStream_;

    void updateByteStream();
};


#endif // MBMS_H
