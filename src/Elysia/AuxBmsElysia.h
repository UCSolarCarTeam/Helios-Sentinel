#ifndef AUXBMSELYSIA_H
#define AUXBMSELYSIA_H
#include "../PropertyDefinition.h"
#include <QObject>

class AuxBms : public QObject
{
    Q_OBJECT
public:
    explicit AuxBms(QObject *parent = nullptr);

    DEFINE_PROPERTY_WHOLE_NUMBER(int, PrechargeState,2,1 )
    DEFINE_PROPERTY_WHOLE_NUMBER(int, AuxVoltage, 3,1)
    DEFINE_PROPERTY_BOOL(BmsAlive, 4, 0x01)
    DEFINE_PROPERTY_BOOL(StrobeLight, 5, 0x01)
    DEFINE_PROPERTY_BOOL(AllowCharge, 6, 0x01)
    DEFINE_PROPERTY_BOOL(HighVoltageEnable, 7, 0x01)
    DEFINE_PROPERTY_BOOL(AllowDischarge, 8, 0x01)
    DEFINE_PROPERTY_BOOL(OrionRecieved, 9, 0x01)
    DEFINE_PROPERTY_BOOL(ChargeContactor, 10, 0x01)
    DEFINE_PROPERTY_BOOL(DischargeContactor, 10, 0x02)
    DEFINE_PROPERTY_BOOL(CommonContactor, 10, 0x04)
    DEFINE_PROPERTY_BOOL(DischargeShould, 10, 0x08)
    DEFINE_PROPERTY_BOOL(ChargeShould, 10, 0x10)
    DEFINE_PROPERTY_BOOL(ChargeOpen, 10, 0x20)
    DEFINE_PROPERTY_BOOL(DischargeOpen, 10, 0x40)
    DEFINE_PROPERTY_BOOL(CtHighCellVoltage, 11, 0x01)
    DEFINE_PROPERTY_BOOL(CtHighTempCurrent, 11, 0x02)
    DEFINE_PROPERTY_BOOL(CtPackCurrent, 11, 0x04)
    DEFINE_PROPERTY_BOOL(DtLowCellVoltage, 11, 0x08)
    DEFINE_PROPERTY_BOOL(DtHighTempCurrent, 11, 0x10)
    DEFINE_PROPERTY_BOOL(DtPackCurrent, 11, 0x20)
    DEFINE_PROPERTY_BOOL(Protection, 11, 0x40)

    Q_PROPERTY(QString byteStreamStr READ byteStreamStr NOTIFY byteStreamStrChanged FINAL)
    Q_PROPERTY(QString encodedByteStreamStr READ encodedByteStreamStr NOTIFY encodedByteStreamStrChanged FINAL)

    bool orionTimeout() const;
    bool cncHighCurrent() const;
    bool dncHighCurrent() const;
    bool contactorDisconnected() const;

    QByteArray byteStream() const;
    QByteArray encodedByteStream() const; //HERE
    QString byteStreamStr() const;
    QString encodedByteStreamStr() const; //HERE

public slots:


    void setOrionTimeout(bool on);
    void setCncHighCurrent(bool on);
    void setDncHighCurrent(bool on);
    void setContactorDisconnected(bool on);


signals:

    void orionTimeoutChanged(bool on);
    void cncHighCurrentChanged(bool on);
    void dncHighCurrentChanged(bool on);
    void contactorDisconnectedChanged(bool on);

    void byteStreamStrChanged();
    void encodedByteStreamStrChanged();

private:
    bool orionTimeout_ = false;
    bool cncHighCurrent_ = false;
    bool dncHighCurrent_ = false;
    bool contactorDisconnected_ = false;

    QByteArray byteStream_;
    QByteArray encodedByteStream_;

    void updateByteStream();
};

#endif // AUXBMSELYSIA_H
