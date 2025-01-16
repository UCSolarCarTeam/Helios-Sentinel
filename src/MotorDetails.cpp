#include "MotorDetails.h"
#include "util.h"

#include <QIODevice>
#include <QDebug>

MotorDetails::MotorDetails(int motor, QObject *parent)
    : QObject{parent} 
{
    byteStream_.fill(0x00, 37);
    byteStream_[0] = 0x21;
    if(motor) byteStream_[1] = 0x03; // motor 1
    else byteStream_[1] = 0x02; // motor 0
    updateByteStream();         //generate checksum and encode empty packet
}

void MotorDetails::updateByteStream(){
    // (1, size - 4)
    QByteArray checksum = Util::generateChecksum(byteStream_, 1, 33);
    // size - 3 and size - 2
    byteStream_[34] = checksum.at(0);
    byteStream_[35] = checksum.at(1);
    encodedByteStream_ = Util::encodeByteStream(byteStream_);
    emit encodedByteStreamStrChanged();
    emit byteStreamStrChanged();
}

QString MotorDetails::encodedByteStreamStr() const {
    return(encodedByteStream_.toHex(' '));
}

QString MotorDetails::byteStreamStr() const {
    return QString(byteStream_.toHex(' '));
}
