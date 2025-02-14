#include "LightsElysia.h"
#include "../util.h"

#include <QIODevice>
#include <QDebug>

LightsElysia::LightsElysia(QObject *parent)
    : QObject{parent}
{
    byteStream_.fill(0x00, 7); //packet size 7 - fill zeros by defualt
    byteStream_[0] = 0x07; //packet size
    byteStream_[1] = 0x0A; //packet ID (10)

    updateByteStream(); //generate checksum and encode empty packet
}



QByteArray LightsElysia::byteStream() const{
    return byteStream_;
}

QByteArray LightsElysia::encodedByteStream() const{
    return encodedByteStream_;
}



void LightsElysia::updateByteStream(){
    QByteArray checksum = Util::generateChecksum(byteStream_, 1, 3);
    byteStream_[4] = checksum.at(0);
    byteStream_[5] = checksum.at(1);
    encodedByteStream_ = Util::encodeByteStream(byteStream_);
    emit encodedByteStreamStrChanged();
    emit byteStreamChangedStr();
}

QString LightsElysia::encodedByteStreamStr() const {
    return(encodedByteStream_.toHex(' '));
}

QString LightsElysia::byteStreamStr() const {
    return QString(byteStream_.toHex(' '));
}



