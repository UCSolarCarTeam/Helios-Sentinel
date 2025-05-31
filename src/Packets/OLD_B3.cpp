#include "B3.h"
#include "util.h"

#include <QIODevice>
#include <QDebug>

B3::B3(QObject *parent)
    : QObject{parent}
{
    byteStream_.fill(0x00, 11); // packet size 12 - fill zeros by defualt
    byteStream_[0] = 0x0C;      // packet size 12
    byteStream_[1] = 0x04;      // packet ID (4)

    updateByteStream();         //generate checksum and encode empty packet
}

QByteArray B3::encodedByteStream() const { return encodedByteStream_; }


void B3::updateByteStream(){
    // (1, size - 4)
    QByteArray checksum = Util::generateChecksum(byteStream_, 1, 7);
    // size - 3 and size - 2
    byteStream_[8] = checksum.at(0);
    byteStream_[9] = checksum.at(1);
    encodedByteStream_ = Util::encodeByteStream(byteStream_);
    emit encodedByteStreamStrChanged();
    emit byteStreamStrChanged();
}

QString B3::encodedByteStreamStr() const {
    return(encodedByteStream_.toHex(' '));
}

QString B3::byteStreamStr() const {
    return QString(byteStream_.toHex(' '));
}
