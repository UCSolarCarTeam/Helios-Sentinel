#ifndef LIGHTS_H
#define LIGHTS_H

#include <QObject>

class Lights : public QObject
{
    Q_OBJECT
public:
    explicit Lights(QObject *parent = nullptr);

    Q_PROPERTY(bool lightsAlive READ lightsAlive NOTIFY lightsAliveChanged)
    Q_PROPERTY(bool lowBeams READ lowBeams NOTIFY lowBeamsChanged)
    Q_PROPERTY(bool highBeams READ highBeams NOTIFY highBeamsChanged)
    Q_PROPERTY(bool brakeLights READ brakeLights NOTIFY brakeLightsChanged)
    Q_PROPERTY(bool leftSignal READ leftSignal NOTIFY leftSignalChanged)
    Q_PROPERTY(bool rightSignal READ rightSignal NOTIFY rightSignalChanged)
    Q_PROPERTY(bool bmsLight READ bmsLight NOTIFY bmsLightChanged)
    Q_PROPERTY(QString byteStreamStr READ byteStreamStr NOTIFY byteStreamChangedStr)
    Q_PROPERTY(QString encodedByteStreamStr READ encodedByteStreamStr NOTIFY encodedByteStreamStrChanged FINAL)

    bool lightsAlive() const;
    bool lowBeams() const;
    bool highBeams() const;
    bool brakeLights() const;
    bool leftSignal() const;
    bool rightSignal() const;
    bool bmsLight() const;
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
    void setBmsLight(bool on);


signals:
    void lightsAliveChanged(bool alive);
    void lowBeamsChanged(bool on);
    void highBeamsChanged(bool on);
    void brakeLightsChanged(bool on);
    void leftSignalChanged(bool on);
    void rightSignalChanged(bool on);
    void bmsLightChanged(bool on);
    void byteStreamChanged();
    void byteStreamChangedStr();
    void encodedByteStreamStrChanged();

private:
    bool lightsAlive_;
    bool lowBeams_;
    bool highBeams_;
    bool brakeLights_;
    bool leftSignal_;
    bool rightSignal_;
    bool bmsLight_;
    QByteArray byteStream_;
    QByteArray encodedByteStream_;

    void updateByteStream();

};

#endif // LIGHTS_H
