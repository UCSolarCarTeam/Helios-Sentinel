#include "Telemetry.h"

#include "util.h"

#include <QIODevice>
#include <QDebug>

Telemetry::Telemetry(QObject *parent)
    : QObject(parent)
{
    byteStream_.fill(0x00, 37); // packet size 37 - fill zeros by defualt
    byteStream_[0] = 0x25;      // packet size 37
    byteStream_[1] = 0x05;      // packet ID (5)

    updateByteStream();         //generate checksum and encode empty packet
}

QByteArray Telemetry::encodedByteStream() const { return encodedByteStream_; }

void Telemetry::updateByteStream(){
    // (1, size - 4)
    QByteArray checksum = Util::generateChecksum(byteStream_, 1, 33);
    // size - 3 and size - 2
    byteStream_[34] = checksum.at(0);
    byteStream_[35] = checksum.at(1);
    encodedByteStream_ = Util::encodeByteStream(byteStream_);
    emit encodedByteStreamStrChanged();
    emit byteStreamStrChanged();
}

QString Telemetry::encodedByteStreamStr() const {
    return(encodedByteStream_.toHex(' '));
}

QString Telemetry::byteStreamStr() const {
    return QString(byteStream_.toHex(' '));
}



