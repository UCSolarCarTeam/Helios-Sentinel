#include "KeyMotor.h"
#include "util.h"

#include <QIODevice>
#include <QDebug>

KeyMotor::KeyMotor(QObject *parent)
    : QObject{parent},
    m0Alive_(false),
    m0SetCurrent_(0),
    m0SetVelocity_(0),
    m0BusCurrent_(0),
    m0BusVoltage_(0),
    m0VehicleVelocity(0),
    m1Alive_(false),
    m1SetCurrent_(0),
    m1SetVelocity_(0),
    m1BusCurrent_(0),
    m1BusVoltage_(0),
    m1VehicleVelocity(0)
{
    byteStream_.fill(0x00, 47); // packet size 47 - fill zeros by defualt
    byteStream_[0] = 0x2F;      // packet size 47
    byteStream_[1] = 0x00;      // packet ID (0)

    updateByteStream();         //generate checksum and encode empty packet
}

bool KeyMotor::m0Alive() const { return m0Alive_; }

int KeyMotor::m0SetCurrent() const { return m0SetCurrent_; }

int KeyMotor::m0SetVelocity() const { return m0SetVelocity_; }

int KeyMotor::m0BusCurrent() const { return m0BusCurrent_; }

int KeyMotor::m0BusVoltage() const { return m0BusVoltage_; }

int KeyMotor::m0VehicleVelocity() const { return m0VehicleVelocity_; }

bool KeyMotor::m1Alive() const { return m1Alive_; }

int KeyMotor::m1SetCurrent() const { return m1SetCurrent_; }

int KeyMotor::m1SetVelocity() const { return m1SetVelocity_; }

int KeyMotor::m1BusCurrent() const { return m1BusCurrent_; }

int KeyMotor::m1BusVoltage() const { return m1BusVoltage_; }

int KeyMotor::m1VehicleVelocity() const { return m1VehicleVelocity_; }

QByteArray KeyMotor::encodedByteStream() const { return encodedByteStream_; }


void KeyMotor::setM0Alive(bool alive) {
    byteStream_[2] = alive ? 0x01 : 0x00;
    lightsAlive_ = alive;
    updateByteStream();

}

void KeyMotor::setM0SetCurrent(int value) {
    byteStream_[3] += on ? 0x01 : -0x01;
    lowBeams_ = on;
    updateByteStream();
}

void KeyMotor::setM0SetVelocity(int value) {
    byteStream_[3] += on ? 0x02 : -0x02;
    highBeams_ = on;
    updateByteStream();
}

void KeyMotor::setM0BusCurrent(int value) {
    byteStream_[3] += on ? 0x04 : -0x04;
    brakeLights_ = on;
    updateByteStream();
}

void KeyMotor::setM0BusVoltage(int value) {
    byteStream_[3] += on ? 0x04 : -0x04;
    brakeLights_ = on;
    updateByteStream();
}

void KeyMotor::setM0VehicleVelocity(int value) {
    byteStream_[3] += on ? 0x04 : -0x04;
    brakeLights_ = on;
    updateByteStream();
}

void KeyMotor::setM1Alive(bool alive) {
    byteStream_[2] = alive ? 0x01 : 0x00;
    lightsAlive_ = alive;
    updateByteStream();

}

void KeyMotor::setM1SetCurrent(int value) {
    byteStream_[3] += on ? 0x01 : -0x01;
    lowBeams_ = on;
    updateByteStream();
}

void KeyMotor::setM1SetVelocity(int value) {
    byteStream_[3] += on ? 0x02 : -0x02;
    highBeams_ = on;
    updateByteStream();
}

void KeyMotor::setM1BusCurrent(int value) {
    byteStream_[3] += on ? 0x04 : -0x04;
    brakeLights_ = on;
    updateByteStream();
}

void KeyMotor::setM1BusVoltage(int value) {
    byteStream_[3] += on ? 0x04 : -0x04;
    brakeLights_ = on;
    updateByteStream();
}

void KeyMotor::setM1VehicleVelocity(int value) {
    byteStream_[3] += on ? 0x04 : -0x04;
    brakeLights_ = on;
    updateByteStream();
}

// Fix hardcode sizes
void KeyMotor::updateByteStream(){
    QByteArray checksum = Util::generateChecksum(byteStream_, 1, 3);
    byteStream_[4] = checksum.at(0);
    byteStream_[5] = checksum.at(1);
    encodedByteStream_ = Util::encodeByteStream(byteStream_);
    emit encodedByteStreamStrChanged();
    emit byteStreamChangedStr();
}

QString KeyMotor::encodedByteStreamStr() const {
    return(encodedByteStream_.toHex(' '));
}

QString KeyMotor::byteStreamStr() const {
    return QString(byteStream_.toHex(' '));
}



