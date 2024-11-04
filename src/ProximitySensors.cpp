#include "ProximitySensors.h"
#include "util.h"

#include <QIODevice>
#include <QDebug>

ProximitySensors::ProximitySensors(QObject *parent)
    : QObject{parent},
    proximitySensor1_(0),
    proximitySensor2_(0),
    proximitySensor3_(0),
    proximitySensor4_(0)
{
    byteStream_.fill(0x00, 13); // packet size 13 - fill zeros by defualt
    byteStream_[0] = 0x0D;      // packet size 13
    byteStream_[1] = 0x0A;      // packet ID (10)

    updateByteStream();         //generate checksum and encode empty packet
}

unsigned short ProximitySensors::proximitySensor1() const { proximitySensor1_; }

unsigned short ProximitySensors::proximitySensor1() const { proximitySensor2_; }

unsigned short ProximitySensors::proximitySensor1() const { proximitySensor3_; }

unsigned short ProximitySensors::proximitySensor1() const { proximitySensor4_; }

QByteArray ProximitySensors::encodedByteStream() const { return encodedByteStream_; }


void ProximitySensors::setProximitySensor1(unsigned short proximity) {
    QByteArray in = Util::formatInt(proximity, 2);
    byteStream_.replace(2, 2, in);
    proximitySensor1_ = proximity;
    updateByteStream();
}

void ProximitySensors::setProximitySensor2(unsigned short proximity) {
    QByteArray in = Util::formatInt(proximity, 2);
    byteStream_.replace(4, 2, in);
    proximitySensor2_ = proximity;
    updateByteStream();
}

void ProximitySensors::setProximitySensor3(unsigned short proximity) {
    QByteArray in = Util::formatInt(proximity, 2);
    byteStream_.replace(6, 2, in);
    proximitySensor3_ = proximity;
    updateByteStream();
}

void ProximitySensors::setProximitySensor4(unsigned short proximity) {
    QByteArray in = Util::formatInt(proximity, 2);
    byteStream_.replace(8, 2, in);
    proximitySensor4_ = proximity;
    updateByteStream();
}

void ProximitySensors::updateByteStream(){
    // (1, size - 4)
    QByteArray checksum = Util::generateChecksum(byteStream_, 1, 9);
    // size - 3 and size - 2
    byteStream_[10] = checksum.at(0);
    byteStream_[11] = checksum.at(1);
    encodedByteStream_ = Util::encodeByteStream(byteStream_);
    emit encodedByteStreamStrChanged();
    emit byteStreamStrChanged();
}

QString ProximitySensors::encodedByteStreamStr() const {
    return(encodedByteStream_.toHex(' '));
}

QString ProximitySensors::byteStreamStr() const {
    return QString(byteStream_.toHex(' '));
}
