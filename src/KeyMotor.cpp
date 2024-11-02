#include "KeyMotor.h"
#include "util.h"

#include <QIODevice>
#include <QDebug>

KeyMotor::KeyMotor(QObject *parent)
    : QObject{parent},
    motorSetpoint_(0),
    controlMode_(false),
    motorMode_(false),
    softwareEnable_(false),
    debugMode_(false)

{
    byteStream_.fill(0x00, 8); // packet size 47 - fill zeros by defualt
    byteStream_[0] = 0x08;      // packet size 47
    byteStream_[1] = 0x01;      // packet ID (1)
    updateByteStream();         //generate checksum and encode empty packet
}

unsigned short KeyMotor::motorSetpoint() const {return motorSetpoint_;}
bool KeyMotor::controlMode() const {return controlMode_;}
bool KeyMotor::motorMode() const {return motorMode_;}
bool KeyMotor::softwareEnable() const {return softwareEnable_;}
bool KeyMotor::debugMode() const {return debugMode_;}


QByteArray KeyMotor::encodedByteStream() const { return encodedByteStream_; }


void KeyMotor::setMotorSetpoint(unsigned short point) {
    QByteArray in = Util::formatInt(point, 2);
    byteStream_.replace(2, 2, in);
    motorSetpoint_ = point;
    updateByteStream();
}
void KeyMotor::setControlMode(bool status){
    byteStream_[4] += status ? 0x01 : -0x01;
    controlMode_ = status;
    updateByteStream();
}
void KeyMotor::setMotorMode(bool status) {
    byteStream_[4] += status ? 0x02 : -0x02;
    motorMode_ = status;
    updateByteStream();
}
void KeyMotor::setSoftwareEnable(bool status){
    byteStream_[4] += status ? 0x04 : -0x04;
    softwareEnable_ = status;
    updateByteStream();
}
void KeyMotor::setDebugMode(bool status){
    byteStream_[4] += status ? 0x08:-0x08;
    debugMode_ = status;
    updateByteStream();
}


void KeyMotor::updateByteStream(){
    // (1, size - 4)
    QByteArray checksum = Util::generateChecksum(byteStream_, 1, 4);
    // size - 3 and size - 2
    byteStream_[5] = checksum.at(0);
    byteStream_[6] = checksum.at(1);
    encodedByteStream_ = Util::encodeByteStream(byteStream_);
    emit encodedByteStreamStrChanged();
    emit byteStreamStrChanged();
}

QString KeyMotor::encodedByteStreamStr() const {
    return(encodedByteStream_.toHex(' '));
}

QString KeyMotor::byteStreamStr() const {
    return QString(byteStream_.toHex(' '));
}



