#include "Lightscontrol.h"
#include "util.h"

LightsControl::LightsControl(QObject *parent)
    : QObject{parent},
    lightsAlive_(false),
    lowBeams_(false),
    highBeams_(false),
    brakeLights_(false),
    leftSignal_(false),
    rightSignal_(false),
    bmsStrobeLights_(false)
{
    byteStream_.fill(0x00, 8);
    byteStream_[0] = 0x08;
    byteStream_[1] = 0x0A;

    updateByteStream();
}

bool LightsControl::lightsAlive() const {
    return lightsAlive_;
}

bool LightsControl::lowBeams() const {
    return lowBeams_;
}

bool LightsControl::highBeams() const {
    return highBeams_;
}

bool LightsControl::brakeLights() const {
    return brakeLights_;
}

bool LightsControl::leftSignal() const {
    return leftSignal_;
}

bool LightsControl::rightSignal() const {
    return rightSignal_;
}

bool LightsControl::bmsStrobeLights() const {
    return bmsStrobeLights_;
}

QByteArray LightsControl::byteStream() const {
    return byteStream_;
}

QByteArray LightsControl::encodedByteStream() const {
    return encodedByteStream_;
}

QString LightsControl::byteStreamStr() const {
    return QString(byteStream_.toHex(' '));
}

QString LightsControl::encodedByteStreamStr() const {
    return QString(encodedByteStream_.toHex(' '));
}

void LightsControl::setLightsAlive(bool alive) {
    byteStream_[2] = alive ? 0x01 : 0x00;
    lightsAlive_ = alive;
    updateByteStream();
}

void LightsControl::setLowBeams(bool on) {
    byteStream_[3] += on ? 0x01 : -0x01;
    lowBeams_ = on;
    updateByteStream();
}

void LightsControl::setHighBeams(bool on) {
    byteStream_[3] += on ? 0x02 : -0x02;
    highBeams_ = on;
    updateByteStream();
}
void LightsControl::setBrakeLights(bool on) {
    byteStream_[3] += on ? 0x04 : -0x04;
    brakeLights_ = on;
    updateByteStream();
}

void LightsControl::setLeftSignal(bool on) {
    byteStream_[3] += on ? 0x08 : -0x08;
    leftSignal_ = on;
    updateByteStream();
}

void LightsControl::setRightSignal(bool on) {
    byteStream_[3] += on ? 0x10 : -0x10;
    rightSignal_ = on;
    updateByteStream();
}

void LightsControl::setBmsStrobeLights(bool on) {
    byteStream_[3] += on ? 0x20 : -0x20;
    bmsStrobeLights_ = on;
    updateByteStream();
}

void LightsControl::updateByteStream(){
    QByteArray checksum = Util::generateChecksum(byteStream_, 1, 5);
    byteStream_[6] = checksum.at(0);
    byteStream_[7] = checksum.at(1);
    encodedByteStream_ = Util::encodeByteStream(byteStream_);
    emit encodedByteStreamStrChanged();
    emit byteStreamStrChanged();
}
