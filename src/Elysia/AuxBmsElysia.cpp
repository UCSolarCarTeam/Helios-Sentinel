#include "AuxBmsElysia.h"
#include "../util.h"

AuxBms::AuxBms(QObject *parent)
    : QObject{parent}
{
    byteStream_.fill(0x00, 15);
    byteStream_[0] = 0x0F;
    byteStream_[1] = 0x0B;
    updateByteStream();
}


QByteArray AuxBms::byteStream() const{
    return byteStream_;
}

QByteArray AuxBms::encodedByteStream() const{
    return encodedByteStream_;
}

QString AuxBms::byteStreamStr() const {
    return QString(byteStream_.toHex(' '));
}

QString AuxBms::encodedByteStreamStr() const{
    return QString(encodedByteStream_.toHex(' '));
}


 /*

BELOW IS NOT DISPLAYED IN DEBUG DASHBOARD

find out if needed

*/

void AuxBms::setOrionTimeout(bool on){
    //byteStream_[11] += on ? 0x80 : -0x80;
    orionTimeout_ = on;
    updateByteStream();
}

void AuxBms::setCncHighCurrent(bool on){
    //byteStream_[12] += on ? 0x01 : -0x01;
    cncHighCurrent_ = on;
    updateByteStream();
}

void AuxBms::setDncHighCurrent(bool on){
    //byteStream_[12] += on ? 0x02 : -0x02;
    dncHighCurrent_ = on;
    updateByteStream();
}

void AuxBms::setContactorDisconnected(bool on){
    //byteStream_[12] += on ? 0x04 : -0x04;
    contactorDisconnected_ = on;
    updateByteStream();
}

/*

ABOVE IS NOT DISPLAYED IN DEBUG DASHBOARD

find out if needed

*/

void AuxBms::updateByteStream(){
    QByteArray checksum = Util::generateChecksum(byteStream_, 1, 11);
    byteStream_[12] = checksum.at(0);
    byteStream_[13] = checksum.at(1);
    encodedByteStream_ = Util::encodeByteStream(byteStream_);
    emit encodedByteStreamStrChanged();
    emit byteStreamStrChanged();
}
