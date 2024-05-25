#ifndef KEYMOTOR_H
#define KEYMOTOR_H

#include <QObject>

class KeyMotor : public QObject
{
    Q_OBJECT
public:
    explicit KeyMotor(QObject *parent = nullptr);

    Q_PROPERTY(bool m0Alive READ m0Alive NOTIFY m0AliveChanged)
    Q_PROPERTY(float m0SetCurrent READ m0SetCurrent NOTIFY m0SetCurrentChanged)
    Q_PROPERTY(float m0SetVelocity READ m0SetVelocity NOTIFY m0SetVelocityChanged)
    Q_PROPERTY(float m0BusCurrent READ m0BusCurrent NOTIFY m0BusCurrentChanged)
    Q_PROPERTY(float m0BusVoltage READ m0BusVoltage NOTIFY m0BusVoltageChanged)
    Q_PROPERTY(float m0VehicleVelocity READ m0VehicleVelocity NOTIFY m0VehicleVelocityChanged)

    Q_PROPERTY(bool m1Alive READ m1Alive NOTIFY m1AliveeChanged)
    Q_PROPERTY(float m1SetCurrent READ m1SetCurrent NOTIFY m1SetCurrentChanged)
    Q_PROPERTY(float m1SetVelocity READ m1SetVelocity NOTIFY m1SetVelocityChanged)
    Q_PROPERTY(float m1BusCurrent READ m1BusCurrent NOTIFY m1BusCurrentChanged)
    Q_PROPERTY(float m1BusVoltage READ m1BusVoltage NOTIFY m1BusVoltageChanged)
    Q_PROPERTY(float m1VehicleVelocity READ m1VehicleVelocity NOTIFY m1VehicleVelocityChanged)

    Q_PROPERTY(QString byteStreamStr READ byteStreamStr NOTIFY byteStreamChangedStr)
    Q_PROPERTY(QString encodedByteStreamStr READ encodedByteStreamStr NOTIFY encodedByteStreamStrChanged FINAL)

    bool m0Alive() const;
    float m0SetCurrent() const;
    float m0SetVelocity() const;
    float m0BusCurrent() const;
    float m0BusVoltage() const;
    float m0VehicleVelocity() const;

    bool m1Alive() const;
    float m1SetCurrent() const;
    float m1SetVelocity() const;
    float m1BusCurrent() const;
    float m1BusVoltage() const;
    float m1VehicleVelocity() const;

    QByteArray byteStream() const;
    QByteArray encodedByteStream() const;
    QString byteStreamStr() const;
    QString encodedByteStreamStr() const;

public slots:
    void setM0Alive(bool alive);
    void setM0SetCurrent(float value);
    void setM0SetVelocity(float value);
    void setM0BusCurrent(float value);
    void setM0BusVoltage(float value);
    void setM0VehicleVelocity(float value);

    void setM1Alive(bool alive);
    void setM1SetCurrent(float value);
    void setM1SetVelocity(float value);
    void setM1BusCurrent(float value);
    void setM1BusVoltage(float value);
    void setM1VehicleVelocity(float value);

signals:
    void m0AliveChanged(bool alive);
    void m0SetCurrentChanged(float value);
    void m0SetVelocityChanged(float value);
    void m0BusCurrentChanged(float value);
    void m0BusVoltageChanged(float value);
    void m0VehicleVelocityChanged(float value);

    void m1AliveChanged(bool alive);
    void m1SetCurrentChanged(float value);
    void m1SetVelocityChanged(float value);
    void m1BusCurrentChanged(float value);
    void m1BusVoltageChanged(float value);
    void m1VehicleVelocityChanged(float value);

private:
    bool m0Alive_;
    bool m0SetCurrent_;
    bool m0SetVelocity_;
    bool m0BusCurrent_;
    bool m0BusVoltage_;
    bool m0VehicleVelocity;
    bool m1Alive_;
    bool m1SetCurrent_;
    bool m1SetVelocity_;
    bool m1BusCurrent_;
    bool m1BusVoltage_;
    bool m1VehicleVelocity;
    QByteArray byteStream_;
    QByteArray encodedByteStream_;

    void updateByteStream();

};

#endif // KEYMOTOR_H
