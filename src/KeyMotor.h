#ifndef KEYMOTOR_H
#define KEYMOTOR_H

#include <QObject>

class KeyMotor : public QObject
{
    Q_OBJECT
public:
    explicit KeyMotor(QObject *parent = nullptr);

    Q_PROPERTY(unsigned short motorSetpoint READ motorSetpoint WRITE setMotorSetpoint NOTIFY motorSetpointChanged);
    Q_PROPERTY(bool controlMode READ controlMode WRITE setControlMode NOTIFY controlModeChanged);
    Q_PROPERTY(bool motorMode READ motorMode WRITE setMotorMode NOTIFY motorModeChanged);
    Q_PROPERTY(bool softwareEnable READ softwareEnable WRITE setSoftwareEnable NOTIFY softwareEnableChanged);
    Q_PROPERTY(bool debugMode READ debugMode WRITE setDebugMode NOTIFY debugModeChanged);

    Q_PROPERTY(QString byteStreamStr READ byteStreamStr NOTIFY byteStreamStrChanged)
    Q_PROPERTY(QString encodedByteStreamStr READ encodedByteStreamStr NOTIFY encodedByteStreamStrChanged FINAL)

    unsigned short motorSetpoint() const;
    bool controlMode() const;
    bool motorMode() const;
    bool softwareEnable() const;
    bool debugMode() const;

    QByteArray byteStream() const;
    QByteArray encodedByteStream() const;
    QString byteStreamStr() const;
    QString encodedByteStreamStr() const;

public slots:
    void setMotorSetpoint(unsigned short motorSetpoint);
    void setControlMode(bool controlMode);
    void setMotorMode(bool motorMode);
    void setSoftwareEnable(bool softwareEnable);
    void setDebugMode(bool debugMode);

signals:
    void motorSetpointChanged(unsigned short motorSetpoint);
    void controlModeChanged(bool value);
    void motorModeChanged(bool value);
    void softwareEnableChanged(bool value);
    void debugModeChanged(bool value);

    void byteStreamChanged();
    void byteStreamStrChanged();
    void encodedByteStreamStrChanged();


private:

    unsigned short motorSetpoint_;
    bool controlMode_;
    bool motorMode_;
    bool softwareEnable_;
    bool debugMode_;
    QByteArray byteStream_;
    QByteArray encodedByteStream_;
    void updateByteStream();

};

#endif // KEYMOTOR_H
