#ifndef B3_H
#define B3_H


#include <QObject>

class B3 : public QObject
{
    Q_OBJECT
public:
    explicit B3(QObject *parent = nullptr);

    Q_PROPERTY(bool rightSignalIn READ rightSignalIn WRITE setRightSignalIn NOTIFY rightSignalInChanged)
    Q_PROPERTY(bool leftSignalIn READ leftSignalIn WRITE setLeftSignalIn NOTIFY leftSignalInChanged)
    Q_PROPERTY(bool hazardLights READ hazardLights WRITE setHazardLights NOTIFY hazardLightsChanged)
    Q_PROPERTY(bool headlightsSwitch READ headlightsSwitch WRITE setHeadlightsSwitch NOTIFY headlightsSwitchChanged)
    Q_PROPERTY(bool forwardSwitch READ forwardSwitch WRITE setForwardSwitch NOTIFY forwardSwitchChanged)
    Q_PROPERTY(bool hornSwitch READ hornSwitch WRITE setHornSwitch NOTIFY hornSwitchChanged)
    Q_PROPERTY(bool forward READ forward WRITE setForward NOTIFY forwardChanged)
    Q_PROPERTY(bool neutral READ neutral WRITE setNeutral NOTIFY neutralChanged)
    Q_PROPERTY(bool reverse READ reverse WRITE setReverse NOTIFY reverseChanged)
    Q_PROPERTY(bool brakeSwitch READ brakeSwitch WRITE setBrakeSwitch NOTIFY brakeSwitchChanged)
    Q_PROPERTY(bool handbrakeSwitch READ handbrakeSwitch WRITE setHandbrakeSwitch NOTIFY handbrakeSwitchChanged)
    Q_PROPERTY(bool motorReset READ motorReset WRITE setMotorReset NOTIFY motorResetChanged)
    Q_PROPERTY(bool raceMode READ raceMode WRITE setRaceMode NOTIFY raceModeChanged)
    Q_PROPERTY(bool lap READ lap WRITE setLap NOTIFY lapChanged)
    Q_PROPERTY(bool zoomZoom READ zoomZoom WRITE setZoomZoom NOTIFY zoomZoomChanged)
    Q_PROPERTY(unsigned short acceleration READ acceleration WRITE setAcceleration NOTIFY accelerationChanged)
    Q_PROPERTY(unsigned short regenBraking READ regenBraking WRITE setRegenBraking NOTIFY regenBrakingChanged)
    Q_PROPERTY(bool rightSignalOut READ rightSignalOut WRITE setRightSignalOut NOTIFY rightSignalOutChanged)
    Q_PROPERTY(bool leftSignalOut READ leftSignalOut WRITE setLeftSignalOut NOTIFY leftSignalOutChanged)
    Q_PROPERTY(bool daytimeRunningLightSignal READ daytimeRunningLightSignal WRITE setDaytimeRunningLightSignal NOTIFY daytimeRunningLightSignalChanged)
    Q_PROPERTY(bool headlightSignal READ headlightSignal WRITE setHeadlightSignal NOTIFY headlightSignalChanged)
    Q_PROPERTY(bool brakeLightSignal READ brakeLightSignal WRITE setBrakeLightSignal NOTIFY brakeLightSignalChanged)
    Q_PROPERTY(bool hornSignal READ hornSignal WRITE setHornSignal NOTIFY hornSignalChanged)

    Q_PROPERTY(QString byteStreamStr READ byteStreamStr NOTIFY byteStreamStrChanged)
    Q_PROPERTY(QString encodedByteStreamStr READ encodedByteStreamStr NOTIFY encodedByteStreamStrChanged)

    bool rightSignalIn() const;
    bool leftSignalIn() const;
    bool hazardLights() const;
    bool headlightsSwitch() const;
    bool forwardSwitch() const;
    bool hornSwitch() const;
    bool forward() const;
    bool neutral() const;
    bool reverse() const;
    bool brakeSwitch() const;
    bool handbrakeSwitch() const;
    bool motorReset() const;
    bool raceMode() const;
    bool lap() const;
    bool zoomZoom() const;
    unsigned short acceleration() const;
    unsigned short regenBraking() const;
    bool rightSignalOut() const;
    bool leftSignalOut() const;
    bool daytimeRunningLightSignal() const;
    bool headlightSignal() const;
    bool brakeLightSignal() const;
    bool hornSignal() const;

    QByteArray byteStream() const;
    QByteArray encodedByteStream() const;
    QString byteStreamStr() const;
    QString encodedByteStreamStr() const;


public slots:
    void setRightSignalIn(bool on);
    void setLeftSignalIn(bool on);
    void setHazardLights(bool on);
    void setHeadlightsSwitch(bool on);
    void setForwardSwitch(bool on);
    void setHornSwitch(bool on);
    void setForward(bool on);
    void setNeutral(bool on);
    void setReverse(bool on);
    void setBrakeSwitch(bool on);
    void setHandbrakeSwitch(bool on);
    void setMotorReset(bool on);
    void setRaceMode(bool on);
    void setLap(bool on);
    void setZoomZoom(bool on);
    void setAcceleration(unsigned short acceleration);
    void setRegenBraking(unsigned short regen);
    void setRightSignalOut(bool on);
    void setLeftSignalOut(bool on);
    void setDaytimeRunningLightSignal(bool on);
    void setHeadlightSignal(bool on);
    void setBrakeLightSignal(bool on);
    void setHornSignal(bool on);


signals:
    void rightSignalInChanged(bool on);
    void leftSignalInChanged(bool on);
    void hazardLightsChanged(bool on);
    void headlightsSwitchChanged(bool on);
    void forwardSwitchChanged(bool on);
    void hornSwitchChanged(bool on);
    void forwardChanged(bool on);
    void neutralChanged(bool on);
    void reverseChanged(bool on);
    void brakeSwitchChanged(bool on);
    void handbrakeSwitchChanged(bool on);
    void motorResetChanged(bool on);
    void raceModeChanged(bool on);
    void lapChanged(bool on);
    void zoomZoomChanged(bool on);
    void accelerationChanged(unsigned short acceleration);
    void regenBrakingChanged(unsigned short regen);
    void rightSignalOutChanged(bool on);
    void leftSignalOutChanged(bool on);
    void daytimeRunningLightSignalChanged(bool on);
    void headlightSignalChanged(bool on);
    void brakeLightSignalChanged(bool on);
    void hornSignalChanged(bool on);

    void byteStreamStrChanged();
    void encodedByteStreamStrChanged();


private:
    bool rightSignalIn_;
    bool leftSignalIn_;
    bool hazardLights_;
    bool headlightsSwitch_;
    bool forwardSwitch_;
    bool hornSwitch_;
    bool forward_;
    bool neutral_;
    bool reverse_;
    bool brakeSwitch_;
    bool handbrakeSwitch_;
    bool motorReset_;
    bool raceMode_;
    bool lap_;
    bool zoomZoom_;
    unsigned short acceleration_;
    unsigned short regenBraking_;
    bool rightSignalOut_;
    bool leftSignalOut_;
    bool daytimeRunningLightSignal_;
    bool headlightSignal_;
    bool brakeLightSignal_;
    bool hornSignal_;

    QByteArray byteStream_;
    QByteArray encodedByteStream_;

    void updateByteStream();

};

#endif // B3_H
