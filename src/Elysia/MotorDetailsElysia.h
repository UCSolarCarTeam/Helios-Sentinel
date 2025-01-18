#ifndef MOTORDETAILSELYSIA_H
#define MOTORDETAILSELYSIA_H
#include "../PropertyDefinition.h"

#include <QObject>

class MotorDetailsElysia : public QObject
{
    Q_OBJECT
public:
    explicit MotorDetailsElysia(int motor, QObject *parent = nullptr);

    DEFINE_PROPERTY_WHOLE_NUMBER(int, PhaseCCurrent, 2, 4)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, PhaseBCurrent, 6, 4)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, MotorVoltageReal, 10, 4)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, MotorVoltageImag, 14, 4)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, MotorCurrentReal, 18, 4)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, MotorCurrentImag, 22, 4)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, BlackEMF, 26, 4)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, VoltageRailSupply15, 30, 4)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, VoltageRailSupply3, 34, 4)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, VoltageRailSupply2, 38, 4)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, HeatSinkTemp, 42, 4)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, MotorTemp, 46, 4)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, DspBoardTemp, 50, 4)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, DcBusAmpHours, 54, 4)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, Odometer, 58, 4)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, SlipSpeed, 62, 4)


    Q_PROPERTY(int motorNum READ motorNum WRITE setMotorNum NOTIFY motorNumChanged FINAL)
    Q_PROPERTY(QString byteStreamStr READ byteStreamStr NOTIFY byteStreamStrChanged FINAL)
    Q_PROPERTY(QString encodedByteStreamStr READ encodedByteStreamStr NOTIFY encodedByteStreamStrChanged FINAL)

    int phaseCCurrent() const;
    int phaseBCurrent() const;
    int motorVoltageReal() const;
    int motorVoltageImag() const;
    int motorCurrentReal() const;
    int motorCurrentImag() const;
    int blackEMF() const;
    int voltageRailSupply15() const;

    int voltageRailSupply3() const;
    int voltageRailSupply2() const;
    int heatSinkTemp() const;
    int motorTemp() const;
    int dspBoardTemp() const;
    int dcBusAmpHours() const;
    int odometer() const;
    int slipSpeed() const;

    int motorNum() const;
    QByteArray byteStream() const;
    QByteArray encodedByteStream() const;
    QString byteStreamStr() const;
    QString encodedByteStreamStr() const;

public slots:
    void setMotorNum(int i);

signals:

    void motorNumChanged(int i);
    void byteStreamStrChanged();
    void encodedByteStreamStrChanged();

private:
    int motorNum_;
    QByteArray byteStream_;
    QByteArray encodedByteStream_;

    void updateByteStream();

};

#endif // MOTORDETAILSELYSIA_H
