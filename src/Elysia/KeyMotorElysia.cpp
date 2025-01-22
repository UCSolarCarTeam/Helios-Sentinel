#include "KeyMotorElysia.h"
#include "util.h"

#include <QIODevice>
#include <QDebug>

KeyMotorElysia::KeyMotorElysia(QObject *parent)
    : QObject{parent}
{
    byteStream_.fill(0x00, 47); // packet size 47 - fill zeros by defualt
    byteStream_[0] = 0x2F;      // packet size 47
    byteStream_[1] = 0x01;      // packet ID (1)

    updateByteStream();         //generate checksum and encode empty packet
}


QByteArray KeyMotorElysia::encodedByteStream() const { return encodedByteStream_; }

void KeyMotorElysia::updateByteStream(){
    // (1, size - 4)
    QByteArray checksum = Util::generateChecksum(byteStream_, 1, 43);
    // size - 3 and size - 2
    byteStream_[44] = checksum.at(0);
    byteStream_[45] = checksum.at(1);
    encodedByteStream_ = Util::encodeByteStream(byteStream_);
    emit encodedByteStreamStrChanged();
    emit byteStreamStrChanged();
}

QString KeyMotorElysia::encodedByteStreamStr() const {
    return(encodedByteStream_.toHex(' '));
}

QString KeyMotorElysia::byteStreamStr() const {
    return QString(byteStream_.toHex(' '));
}
