#ifndef PROXIMITYSENSORS_H
#define PROXIMITYSENSORS_H

#include "PropertyDefinition.h"
#include <QObject>

class ProximitySensors : public QObject
{
    Q_OBJECT
public:
    explicit ProximitySensors(QObject *parent = nullptr);

    DEFINE_WHOLE_NUMBER(unsigned short, ProximitySensor1, 2, 2)
    DEFINE_WHOLE_NUMBER(unsigned short, ProximitySensor2, 4, 2)
    DEFINE_WHOLE_NUMBER(unsigned short, ProximitySensor3, 6, 2)
    DEFINE_WHOLE_NUMBER(unsigned short, ProximitySensor4, 8, 2)


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

#endif // PROXIMITYSENSORS_H
