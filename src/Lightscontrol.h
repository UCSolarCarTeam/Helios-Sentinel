#ifndef LIGHTSCONTROL_H
#define LIGHTSCONTROL_H

#include <QObject>

class LightsControl : public QObject
{
    Q_OBJECT

public:
    explicit LightsControl(QObject *parent = nullptr);

    Q_PROPERTY(bool lightsAlive READ lightsAlive WRITE setLightsAlive NOTIFY lightsAliveChanged FINAL)
    Q_PROPERTY(bool lowBeams READ lowBeams WRITE setLowBeams NOTIFY lowBeamsChanged FINAL)
    Q_PROPERTY(bool highBeams READ highBeams WRITE setHighBeams NOTIFY highBeamsChanged FINAL)
    Q_PROPERTY(bool brakeLights READ brakeLights WRITE setBrakeLights NOTIFY brakeLightsChanged FINAL)
    Q_PROPERTY(bool leftSignal READ leftSignal WRITE setLeftSignal NOTIFY leftSignalChanged FINAL)
    Q_PROPERTY(bool rightSignal READ rightSignal WRITE setRightSignal NOTIFY rightSignalChanged FINAL)
    Q_PROPERTY(bool bmsStrobeLight READ bmsStrobeLigh WRITE setbmsStrobeLigh NOTIFY bmsStrobeLighChanged FINAL)

    bool lightsAlive() const;
    bool lowBeams() const;
    bool highBeams() const;
    bool brakeLights() const;
    bool leftSignal() const;
    bool rightSignal() const;
    bool bmsStrobeLights() const;

    QByteArray byteStream() const;
    QByteArray encodedByteStream() const;
    QString byteStreamStr() const;
    QString encodedByteStreamStr() const;

public slots:
    void setLightsAlive(bool alive);
    void setLowBeams(bool on);
    void setHighBeams(bool on);
    void setBrakeLights(bool on);
    void setLeftSignal(bool on);
    void setRightSignal(bool on);
    void setBmsStrobeLights(bool on);

signals:
    void lightsAliveChanged(bool on);
    void lowBeamsChanged(bool on);
    void highBeamsChanged(bool on);
    void brakeLightsChanged(bool on);
    void leftSignalChanged(bool on);
    void rightSignalChanged(bool on);
    void bmsStrobeLightsChanged(bool on);

    void byteStreamStrChanged();
    void encodedByteStreamStrChanged();

private:
    bool lightsAlive_;
    bool lowBeams_;
    bool highBeams_;
    bool brakeLights_;
    bool leftSignal_;
    bool rightSignal_;
    bool bmsStrobeLights_;

    QByteArray byteStream_;
    QByteArray encodedByteStream_;

    void updateByteStream();
};


#endif // LIGHTSCONTROL_H
