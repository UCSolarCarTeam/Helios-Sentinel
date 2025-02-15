#include "AuxBmsElysia.h"
#include "../util.h"

AuxBmsElysia::AuxBmsElysia(QObject *parent)
    : QObject{parent}
{
    byteStream_.fill(0x00, 15);
    byteStream_[0] = 0x0F;
    byteStream_[1] = 0x0B;
    updateByteStream();
}


QByteArray AuxBmsElysia::byteStream() const{
    return byteStream_;
}

QByteArray AuxBmsElysia::encodedByteStream() const{
    return encodedByteStream_;
}

QString AuxBmsElysia::byteStreamStr() const {
    return QString(byteStream_.toHex(' '));
}

QString AuxBmsElysia::encodedByteStreamStr() const{
    return QString(encodedByteStream_.toHex(' '));
}


void AuxBmsElysia::updateByteStream(){
    QByteArray checksum = Util::generateChecksum(byteStream_, 1, 11);
    byteStream_[12] = checksum.at(0);
    byteStream_[13] = checksum.at(1);
    encodedByteStream_ = Util::encodeByteStream(byteStream_);
    emit encodedByteStreamStrChanged();
    emit byteStreamStrChanged();
}
