#ifndef MPPTELYSIA_H
#define MPPTELYSIA_H

#include "../PropertyDefinition.h"
#include <QObject>

class MpptElysia : public QObject
{
    Q_OBJECT
public:
    explicit MpptElysia(int channel, QObject *parent = nullptr);

    DEFINE_PROPERTY_BOOL(Alive,2, 0x80)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, ArrayVoltage, 3, 2)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, ArrayCurrent, 5, 2)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, BatteryVoltage, 7, 2)
    DEFINE_PROPERTY_WHOLE_NUMBER(int, Temp, 9, 2)


    Q_PROPERTY(QString byteStreamStr READ byteStreamStr NOTIFY byteStreamStrChanged FINAL)
    Q_PROPERTY(QString encodedByteStreamStr READ encodedByteStreamStr NOTIFY encodedByteStreamStrChanged FINAL)

    QByteArray byteStream() const;
    QByteArray encodedByteStream() const;
    QString byteStreamStr() const;
    QString encodedByteStreamStr() const;



signals:

    void byteStreamStrChanged();
    void encodedByteStreamStrChanged();

private:

    QByteArray byteStream_;
    QByteArray encodedByteStream_;

    void updateByteStream();

};


#endif // MPPTELYSIA_H
