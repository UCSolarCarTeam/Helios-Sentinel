#include "KeyMotor.h"
#include "util.h"

#include <QIODevice>
#include <QDebug>

KeyMotor::KeyMotor(QObject *parent)
    : QObject{parent}

{
    byteStream_.fill(0x00, 8); // packet size 8 - fill zeros by defualt
    byteStream_[0] = 0x08;      // packet size 8
    byteStream_[1] = 0x01;      // packet ID (1)
    updateByteStream();         //generate checksum and encode empty packet
}


QByteArray KeyMotor::encodedByteStream() const { return encodedByteStream_; }


void KeyMotor::updateByteStream(){
    // (1, size - 4)
    QByteArray checksum = Util::generateChecksum(byteStream_, 1, 4);
    // size - 3 and size - 2
    byteStream_[5] = checksum.at(0);
    byteStream_[6] = checksum.at(1);
    encodedByteStream_ = Util::encodeByteStream(byteStream_);
    emit encodedByteStreamStrChanged();
    emit byteStreamStrChanged();
}

QString KeyMotor::encodedByteStreamStr() const {
    return(encodedByteStream_.toHex(' '));
}

QString KeyMotor::byteStreamStr() const {
    return QString(byteStream_.toHex(' '));
}



