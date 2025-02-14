#include "DriverControlsElysia.h"
#include "../util.h"
#include <QDebug>

DriverControlsElysia::DriverControlsElysia(QObject *parent)
    : QObject{parent}
{
    byteStream_.fill(0x00, 13);
    byteStream_[0] = 0x0D;
    byteStream_[1] = 0x04;

    updateByteStream();
}

QByteArray DriverControlsElysia::byteStream() const{
    return byteStream_;
}

QByteArray DriverControlsElysia::encodedByteStream() const{
    return encodedByteStream_;
}

QString DriverControlsElysia::byteStreamStr() const {
    return QString(byteStream_.toHex(' '));
}

QString DriverControlsElysia::encodedByteStreamStr() const{
    return QString(encodedByteStream_.toHex(' '));
}


void DriverControlsElysia::updateByteStream(){
    QByteArray checksum = Util::generateChecksum(byteStream_, 1, 9);
    byteStream_[10] = checksum.at(0);
    byteStream_[11] = checksum.at(1);
    encodedByteStream_ = Util::encodeByteStream(byteStream_);
    emit encodedByteStreamStrChanged();
    emit byteStreamStrChanged();
}

