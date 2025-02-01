#include "DriverControlsElysia.h"
#include "../util.h"

#include <QDebug>

DriverControls::DriverControls(QObject *parent)
    : QObject{parent}
{
    byteStream_.fill(0x00, 13);
    byteStream_[0] = 0x0D;
    byteStream_[1] = 0x04;

    updateByteStream();
}

QByteArray DriverControls::byteStream() const{
    return byteStream_;
}

QByteArray DriverControls::encodedByteStream() const{
    return encodedByteStream_;
}

QString DriverControls::byteStreamStr() const {
    return QString(byteStream_.toHex(' '));
}

QString DriverControls::encodedByteStreamStr() const{
    return QString(encodedByteStream_.toHex(' '));
}


void DriverControls::updateByteStream(){
    QByteArray checksum = Util::generateChecksum(byteStream_, 1, 9);
    byteStream_[10] = checksum.at(0);
    byteStream_[11] = checksum.at(1);
    encodedByteStream_ = Util::encodeByteStream(byteStream_);
    emit encodedByteStreamStrChanged();
    emit byteStreamStrChanged();
}

