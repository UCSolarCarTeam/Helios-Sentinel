#include "Mppt.h"
#include "util.h"

Mppt::Mppt(int channel, QObject *parent)
    : QObject{parent}
{
    byteStream_.fill(0x00, 14);
    byteStream_[0] = 0x0E;
    byteStream_[1] = 0x08;
    QByteArray channelByte = Util::formatInt(channel, 1);
    byteStream_[2] = channelByte[0];
    updateByteStream();
}


QByteArray Mppt::byteStream() const{
    return byteStream_;
}

QByteArray Mppt::encodedByteStream() const{
    return encodedByteStream_;
}

QString Mppt::byteStreamStr() const {
    return QString(byteStream_.toHex(' '));
}

QString Mppt::encodedByteStreamStr() const{
    return QString(encodedByteStream_.toHex(' '));
}


void Mppt::updateByteStream(){
    QByteArray checksum = Util::generateChecksum(byteStream_, 1, 10);
    byteStream_[11] = checksum.at(0);
    byteStream_[12] = checksum.at(1);
    encodedByteStream_ = Util::encodeByteStream(byteStream_);
    emit encodedByteStreamStrChanged();
    emit byteStreamStrChanged();
}
