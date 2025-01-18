#include "MotorDetailsElysia.h"
#include "util.h"

#include <QIODevice>
#include <QDebug>

MotorDetailsElysia::MotorDetailsElysia(int motor, QObject *parent)
    : QObject{parent}
{
    byteStream_.fill(0x00, 69); // packet size 69 - fill zeros by defualt
    byteStream_[0] = 0x45;      // packet size 69
    motorNum_ = motor;
    QByteArray motorID = Util::formatInt(motor + 2, 1);
    byteStream_[1] = motorID[0];
    updateByteStream();         //generate checksum and encode empty packet
}


int MotorDetailsElysia::motorNum() const { return motorNum_; }

QByteArray MotorDetailsElysia::encodedByteStream() const { return encodedByteStream_; }


void MotorDetailsElysia::setMotorNum(int value) {
    motorNum_ = value;
}

void MotorDetailsElysia::updateByteStream(){
    // (1, size - 4)
    QByteArray checksum = Util::generateChecksum(byteStream_, 1, 65);
    // size - 3 and size - 2
    byteStream_[66] = checksum.at(0);
    byteStream_[67] = checksum.at(1);
    encodedByteStream_ = Util::encodeByteStream(byteStream_);
    emit encodedByteStreamStrChanged();
    emit byteStreamStrChanged();
}

QString MotorDetailsElysia::encodedByteStreamStr() const {
    return(encodedByteStream_.toHex(' '));
}

QString MotorDetailsElysia::byteStreamStr() const {
    return QString(byteStream_.toHex(' '));
}
