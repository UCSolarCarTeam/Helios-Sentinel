#include "Mbms.h"

#include "util.h"

#include <QIODevice>
#include <QDebug>

Mbms::Mbms(QObject *parent)
    : QObject(parent)
{
    byteStream_.fill(0x00, 30); // packet size 30 - fill zeros by defualt
    byteStream_[0] = 0x1E;      // packet size 30
    byteStream_[1] = 0x09;      // packet ID (9)

    updateByteStream();         //generate checksum and encode empty packet
}

QByteArray Mbms::encodedByteStream() const { return encodedByteStream_; }


void Mbms::updateByteStream(){
    // (1, size - 4)
    QByteArray checksum = Util::generateChecksum(byteStream_, 1, 26);
    // size - 3 and size - 2
    byteStream_[27] = checksum.at(0);
    byteStream_[28] = checksum.at(1);
    encodedByteStream_ = Util::encodeByteStream(byteStream_);
    emit encodedByteStreamStrChanged();
    emit byteStreamStrChanged();
}

QString Mbms::encodedByteStreamStr() const {
    return(encodedByteStream_.toHex(' '));
}

QString Mbms::byteStreamStr() const {
    return QString(byteStream_.toHex(' '));
}

