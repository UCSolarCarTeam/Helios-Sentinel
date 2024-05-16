#ifndef DRIVERCONTROLS_H
#define DRIVERCONTROLS_H

#include <QObject>

class DriverControls : public QObject
{
    Q_OBJECT
public:
    explicit DriverControls(QObject *parent = nullptr);

    Q_PROPERTY(bool driverControlsAlive READ driverControlsAlive WRITE setDriverControlsAlive NOTIFY driverControlsAliveChanged FINAL)

    Q_PROPERTY(bool headlightsOff READ headlightsOff WRITE setHeadlightsOff NOTIFY headlightsOffChanged FINAL)
    Q_PROPERTY(bool headlightsLow READ headlightsLow WRITE setHeadlightsLow NOTIFY headlightsLowChanged FINAL)
    Q_PROPERTY(bool headlightsHigh READ headlightsHigh WRITE setHeadlightsHigh NOTIFY headlightsHighChanged FINAL)
    Q_PROPERTY(bool signalRight READ signalRight WRITE setSignalRight NOTIFY signalRightChanged FINAL)
    Q_PROPERTY(bool signalLeft READ signalLeft WRITE setSignalLeft NOTIFY signalLeftChanged FINAL)
    Q_PROPERTY(bool hazards READ hazards WRITE setHazards NOTIFY hazardsChanged FINAL)
    Q_PROPERTY(bool interior READ interior WRITE setInterior NOTIFY interiorChanged FINAL)

    Q_PROPERTY(bool volumeUp READ volumeUp WRITE setVolumeUp NOTIFY volumeUpChanged FINAL)
    Q_PROPERTY(bool volumeDown READ volumeDown WRITE setVolumeDown NOTIFY volumeDownChanged FINAL)
    Q_PROPERTY(bool next READ next WRITE setNext NOTIFY nextChanged FINAL)
    Q_PROPERTY(bool prev READ prev WRITE setPrev NOTIFY prevChanged FINAL)

    Q_PROPERTY(bool brakes READ brakes WRITE setBrakes NOTIFY brakesChanged FINAL)
    Q_PROPERTY(bool forward READ forward WRITE setForward NOTIFY forwardChanged FINAL)
    Q_PROPERTY(bool reverse READ reverse WRITE setReverse NOTIFY reverseChanged FINAL)
    Q_PROPERTY(bool pushToTalk READ pushToTalk WRITE setPushToTalk NOTIFY pushToTalkChanged FINAL)
    Q_PROPERTY(bool horn READ horn WRITE setHorn NOTIFY hornChanged FINAL)
    Q_PROPERTY(bool reset READ reset WRITE setReset NOTIFY resetChanged FINAL)
    Q_PROPERTY(bool aux READ aux WRITE setAux NOTIFY auxChanged FINAL)
    Q_PROPERTY(bool lap READ lap WRITE setLap NOTIFY lapChanged FINAL)

    Q_PROPERTY(unsigned short acceleration READ acceleration WRITE setAcceleration NOTIFY accelerationChanged FINAL)
    Q_PROPERTY(unsigned short regenBraking READ regenBraking WRITE setRegenBraking NOTIFY regenBrakingChanged FINAL)

    Q_PROPERTY(QString byteStreamStr READ byteStreamStr NOTIFY byteStreamStrChanged FINAL)
    Q_PROPERTY(QString encodedByteStreamStr READ encodedByteStreamStr NOTIFY encodedByteStreamStrChanged FINAL)

    bool driverControlsAlive() const;

    bool headlightsOff() const;
    bool headlightsLow() const;
    bool headlightsHigh() const;
    bool signalRight() const;
    bool signalLeft() const;
    bool hazards() const;
    bool interior() const;

    bool volumeUp() const;
    bool volumeDown() const;
    bool next() const;
    bool prev() const;

    bool brakes() const;
    bool forward() const;
    bool reverse() const;
    bool pushToTalk() const;
    bool horn() const;
    bool reset() const;
    bool aux() const;
    bool lap() const;

    unsigned short acceleration() const;
    unsigned short regenBraking() const;

    QByteArray byteStream() const;
    QByteArray encodedByteStream() const; //HERE
    QString byteStreamStr() const;
    QString encodedByteStreamStr() const; //HERE

public slots:
    void setDriverControlsAlive(bool alive);

    void setHeadlightsOff(bool on);
    void setHeadlightsLow(bool on);
    void setHeadlightsHigh(bool on);
    void setSignalRight(bool on);
    void setSignalLeft(bool on);
    void setHazards(bool on);
    void setInterior(bool on);

    void setVolumeUp(bool on);
    void setVolumeDown(bool on);
    void setNext(bool on);
    void setPrev(bool on);

    void setBrakes(bool on);
    void setForward(bool on);
    void setReverse(bool on);
    void setPushToTalk(bool on);
    void setHorn(bool on);
    void setReset(bool on);
    void setAux(bool on);
    void setLap(bool on);

    void setAcceleration(unsigned short accel);
    void setRegenBraking(unsigned short rg);

signals:
    void driverControlsAliveChanged(bool alive);

    void headlightsOffChanged(bool on);
    void headlightsLowChanged(bool on);
    void headlightsHighChanged(bool on);
    void signalRightChanged(bool on);
    void signalLeftChanged(bool on);
    void hazardsChanged(bool on);
    void interiorChanged(bool on);

    void volumeUpChanged(bool on);
    void volumeDownChanged(bool on);
    void nextChanged(bool on);
    void prevChanged(bool on);

    void brakesChanged(bool on);
    void forwardChanged(bool on);
    void reverseChanged(bool on);
    void pushToTalkChanged(bool on);
    void hornChanged(bool on);
    void resetChanged(bool on);
    void auxChanged(bool on);
    void lapChanged(bool on);

    void accelerationChanged(unsigned short accel);
    void regenBrakingChanged(unsigned short rg);

    void byteStreamStrChanged();
    void encodedByteStreamStrChanged();

private:
    bool driverControlsAlive_;

    bool headlightsOff_;
    bool headlightsLow_;
    bool headlightsHigh_;
    bool signalRight_;
    bool signalLeft_;
    bool hazards_;
    bool interior_;

    bool volumeUp_;
    bool volumeDown_;
    bool next_;
    bool prev_;

    bool brakes_;
    bool forward_;
    bool reverse_;
    bool pushToTalk_;
    bool horn_;
    bool reset_;
    bool aux_;
    bool lap_;

    unsigned short acceleration_;
    unsigned short regenBraking_;

    QByteArray byteStream_;
    QByteArray encodedByteStream_;

    void updateByteStream();



};

#endif // DRIVERCONTROLS_H
