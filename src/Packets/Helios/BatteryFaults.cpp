#include "BatteryFaults.h"

#include "util.h"

BatteryFaults::BatteryFaults(QObject *parent)
    : QObject{parent}
{
    byteStream_.fill(0x00, 11);
    byteStream_[0] = 0x0B;
    byteStream_[1] = 0x06;
}

QByteArray BatteryFaults::byteStream() const{
    return byteStream_;
}

QByteArray BatteryFaults::encodedByteStream() const{
    return encodedByteStream_;
}

QString BatteryFaults::encodedByteStreamStr() const {
    return(encodedByteStream_.toHex(' '));    // bool cclChargerVoltage() const;

}

QString BatteryFaults::byteStreamStr() const {
    return QString(byteStream_.toHex(' '));
}


void BatteryFaults::updateByteStream(){
    QByteArray checksum = Util::generateChecksum(byteStream_, 1, 7);
    byteStream_[8] = checksum.at(0);
    byteStream_[9] = checksum.at(1);
    encodedByteStream_ = Util::encodeByteStream(byteStream_);
    emit encodedByteStreamStrChanged();
    emit byteStreamStrChanged();
}
