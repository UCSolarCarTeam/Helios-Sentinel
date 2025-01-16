#ifndef LIGHTS_H
#define LIGHTS_H
#include "PropertyDefinition.h"
#include <QObject>

class Lights : public QObject
{
    Q_OBJECT
public:
    explicit Lights(QObject *parent = nullptr);

    DEFINE_PROPERTY_BOOL(LightsAlive, 2, 0x01)
    DEFINE_PROPERTY_BOOL(LowBeams, 3, 0x01)
    DEFINE_PROPERTY_BOOL(HighBeams, 3, 0x02)
    DEFINE_PROPERTY_BOOL(BrakeLights, 3, 0x04)
    DEFINE_PROPERTY_BOOL(LeftSignal, 3, 0x08)
    DEFINE_PROPERTY_BOOL(RightSignal, 3, 0x10)
    DEFINE_PROPERTY_BOOL(BmsLight, 3, 0x20)
    Q_PROPERTY(QString byteStreamStr READ byteStreamStr NOTIFY byteStreamChangedStr)
    Q_PROPERTY(QString encodedByteStreamStr READ encodedByteStreamStr NOTIFY encodedByteStreamStrChanged FINAL)

    QByteArray byteStream() const;
    QByteArray encodedByteStream() const;
    QString byteStreamStr() const;
    QString encodedByteStreamStr() const;



signals:
    void byteStreamChanged();
    void byteStreamChangedStr();
    void encodedByteStreamStrChanged();

private:

    QByteArray byteStream_;
    QByteArray encodedByteStream_;

    void updateByteStream();

};

#endif // LIGHTS_H
