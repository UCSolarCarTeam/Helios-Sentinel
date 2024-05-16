#include "lights.h"
#include "util.h"

#include <QIODevice>
#include <QDebug>

Lights::Lights(QObject *parent)
    : QObject{parent},
    lightsAlive_(false),
    lowBeams_(false),
    highBeams_(false),
    brakeLights_(false),
    leftSignal_(false),
    rightSignal_(false),
    bmsLight_(false)
{
    byteStream_.fill(0x00, 7); //packet size 7 - fill zeros by defualt
    byteStream_[0] = 0x07; //packet size
    byteStream_[1] = 0x0A; //packet ID (10)

    updateByteStream(); //generate checksum and encode empty packet
}

bool Lights::lightsAlive() const {
    return lightsAlive_;
}

bool Lights::lowBeams() const {
    return lowBeams_;
}

bool Lights::highBeams() const {
    return highBeams_;
}

bool Lights::brakeLights() const {
    return brakeLights_;
}

bool Lights::leftSignal() const {
    return leftSignal_;
}

bool Lights::rightSignal() const {
    return rightSignal_;
}

bool Lights::bmsLight() const {
    return bmsLight_;
}

QByteArray Lights::byteStream() const{
    return byteStream_;
}

QByteArray Lights::encodedByteStream() const{
    return encodedByteStream_;
}

void Lights::setLightsAlive(bool alive){
    byteStream_[2] = alive ? 0x01 : 0x00;
    lightsAlive_ = alive;
    updateByteStream();

}

void Lights::setLowBeams(bool on){
    byteStream_[3] += on ? 0x01 : -0x01;
    lowBeams_ = on;
    updateByteStream();
}

void Lights::setHighBeams(bool on){
    byteStream_[3] += on ? 0x02 : -0x02;
    highBeams_ = on;
    updateByteStream();
}

void Lights::setBrakeLights(bool on){
    byteStream_[3] += on ? 0x04 : -0x04;
    brakeLights_ = on;
    updateByteStream();
}

void Lights::setLeftSignal(bool on){
    byteStream_[3] += on ? 0x08 : -0x08;
    leftSignal_ = on;
    updateByteStream();
}

void Lights::setRightSignal(bool on){
    byteStream_[3] += on ? 0x10 : -0x10;
    rightSignal_ = on;
    updateByteStream();
}

void Lights::setBmsLight(bool on){
    byteStream_[3] += on ? 0x20 : -0x20;
    bmsLight_ = on;
    updateByteStream();
}

void Lights::updateByteStream(){
    QByteArray checksum = Util::generateChecksum(byteStream_, 1, 3);
    byteStream_[4] = checksum.at(0);
    byteStream_[5] = checksum.at(1);
    encodedByteStream_ = Util::encodeByteStream(byteStream_);
    emit encodedByteStreamStrChanged();
    emit byteStreamChangedStr();
}

QString Lights::encodedByteStreamStr() const {
    return(encodedByteStream_.toHex(' '));
}

QString Lights::byteStreamStr() const {
    return QString(byteStream_.toHex(' '));
}



