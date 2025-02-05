#include "ProximitySensors.h"
#include "util.h"

#include <QIODevice>
#include <QDebug>

ProximitySensors::ProximitySensors(QObject *parent)
    : QObject{parent}
{
    byteStream_.fill(0x00, 13); // packet size 13 - fill zeros by defualt
    byteStream_[0] = 0x0D;      // packet size 13
    byteStream_[1] = 0x0A;      // packet ID (10)

    updateByteStream();         //generate checksum and encode empty packet
}

QByteArray ProximitySensors::encodedByteStream() const { return encodedByteStream_; }

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
