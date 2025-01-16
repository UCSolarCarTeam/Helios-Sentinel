#include "Battery.h"
#include "util.h"

#include <QDebug>

Battery::Battery(QObject *parent)
    : QObject{parent}
{
    byteStream_.fill(0x00, 52);
    byteStream_[0] = 0x34;
    byteStream_[1] = 0x07;
    updateByteStream();
}

QByteArray Battery::byteStream() const{
    return byteStream_;
}

QByteArray Battery::encodedByteStream() const{
    return encodedByteStream_;
}

QString Battery::byteStreamStr() const {
    return QString(byteStream_.toHex(' '));
}

QString Battery::encodedByteStreamStr() const{
    return QString(encodedByteStream_.toHex(' '));
}

void Battery::updateByteStream(){
    QByteArray checksum = Util::generateChecksum(byteStream_, 1, 48);
    byteStream_[49] = checksum.at(0);
    byteStream_[50] = checksum.at(1);
    encodedByteStream_ = Util::encodeByteStream(byteStream_);
    emit encodedByteStreamStrChanged();
    emit byteStreamStrChanged();
}

