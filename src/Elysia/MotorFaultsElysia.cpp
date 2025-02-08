#include "MotorFaultsElysia.h"
#include "../util.h"

#include <QIODevice>
#include <QDebug>

MotorFaults::MotorFaults(QObject *parent)
    : QObject{parent}
{
    byteStream_.fill(0x00, 13); // packet size 13 - fill zeros by defualt
    byteStream_[0] = 0x0D;      // packet size 13
    byteStream_[1] = 0x05;      // packet ID (5)

    updateByteStream();         //generate checksum and encode empty packet
}


QByteArray MotorFaults::byteStream() const { return byteStream_; }

QByteArray MotorFaults::encodedByteStream() const{ return encodedByteStream_; }

QString MotorFaults::byteStreamStr() const {
    return QString(byteStream_.toHex(' '));
}

QString MotorFaults::encodedByteStreamStr() const{
    return QString(encodedByteStream_.toHex(' '));
}


void MotorFaults::updateByteStream(){
    QByteArray checksum = Util::generateChecksum(byteStream_, 1, 9);
    byteStream_[10] = checksum.at(0);
    byteStream_[11] = checksum.at(1);
    encodedByteStream_ = Util::encodeByteStream(byteStream_);
    emit encodedByteStreamStrChanged();
    emit byteStreamStrChanged();
}
