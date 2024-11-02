#include "B3.h"
#include "util.h"

#include <QIODevice>
#include <QDebug>

B3::B3(QObject *parent)
    : QObject{parent},
    rightSignalIn_(false),
          leftSignalIn_(false),
          hazardLights_(false),
          headlightsSwitch_(false),
          forwardSwitch_(false),
          hornSwitch_(false),
          forward_(false),
          neutral_(false),
          reverse_(false),
          brakeSwitch_(false),
          handbrakeSwitch_(false),
          motorReset_(false),
          raceMode_(false),
          lap_(false),
          zoomZoom_(false),
          acceleration_(0),
          regenBraking_(0),
          rightSignalOut_(false),
          leftSignalOut_(false),
          daytimeRunningLightSignal_(false),
          headlightSignal_(false),
          brakeLightSignal_(false),
          hornSignal_(false)
{
    byteStream_.fill(0x00, 11); // packet size 11 - fill zeros by defualt
    byteStream_[0] = 0x0B;      // packet size 11
    byteStream_[1] = 0x04;      // packet ID (4)

    updateByteStream();         //generate checksum and encode empty packet
}

bool B3::rightSignalIn() const { return rightSignalIn_; }

bool B3::leftSignalIn() const { return leftSignalIn_; }

bool B3::hazardLights() const { return hazardLights_; }

bool B3::headlightsSwitch() const { return headlightsSwitch_; }

bool B3::forwardSwitch() const { return forwardSwitch_; }

bool B3::hornSwitch() const { return hornSwitch_; }

bool B3::forward() const { return forward_; }

bool B3::neutral() const { return neutral_; }

bool B3::reverse() const { return reverse_; }

bool B3::brakeSwitch() const { return brakeSwitch_; }

bool B3::handbrakeSwitch() const { return handbrakeSwitch_; }

bool B3::motorReset() const { return motorReset_; }

bool B3::raceMode() const { return raceMode_; }

bool B3::lap() const { return lap_; }

bool B3::zoomZoom() const { return zoomZoom_; }

unsigned short B3::acceleration() const { return acceleration_; }

unsigned short B3::regenBraking() const { return regenBraking_; }

bool B3::rightSignalOut() const { return rightSignalOut_; }

bool B3::leftSignalOut() const { return leftSignalOut_; }

bool B3::daytimeRunningLightSignal() const { return daytimeRunningLightSignal_; }

bool B3::headlightSignal() const { return headlightSignal_; }

bool B3::brakeLightSignal() const { return brakeLightSignal_; }

bool B3::hornSignal() const { return hornSignal_; }

QByteArray B3::encodedByteStream() const { return encodedByteStream_; }


void B3::setRightSignalIn(bool on) {
    byteStream_[2] += on ? 0x01 : -0x01;
    rightSignalIn_ = on;
    updateByteStream();
}

void B3::setLeftSignalIn(bool on) {
    byteStream_[2] += on ? 0x02 : -0x02;
    leftSignalIn_ = on;
    updateByteStream();
}

void B3::setHazardLights(bool on) {
    byteStream_[2] += on ? 0x04 : -0x04;
    hazardLights_ = on;
    updateByteStream();
}

void B3::setHeadlightsSwitch(bool on) {
    byteStream_[2] += on ? 0x08 : -0x08;
    headlightsSwitch_ = on;
    updateByteStream();
}

void B3::setForwardSwitch(bool on) {
    byteStream_[2] += on ? 0x10 : -0x10;
    forwardSwitch_ = on;
    updateByteStream();
}

void B3::setHornSwitch(bool on) {
    byteStream_[2] += on ? 0x20 : -0x20;
    hornSwitch_ = on;
    updateByteStream();
}

void B3::setForward(bool on) {
    byteStream_[2] += on ? 0x40 : -0x40;
    forward_ = on;
    updateByteStream();
}

void B3::setNeutral(bool on) {
    byteStream_[3] += on ? 0x01 : -0x01;
    neutral_ = on;
    updateByteStream();
}

void B3::setReverse(bool on) {
    byteStream_[3] += on ? 0x02 : -0x02;
    reverse_ = on;
    updateByteStream();
}

void B3::setBrakeSwitch(bool on) {
    byteStream_[3] += on ? 0x04 : -0x04;
    brakeSwitch_ = on;
    updateByteStream();
}

void B3::setHandbrakeSwitch(bool on) {
    byteStream_[3] += on ? 0x08 : -0x08;
    handbrakeSwitch_ = on;
    updateByteStream();
}

void B3::setMotorReset(bool on) {
    byteStream_[3] += on ? 0x10 : -0x10;
    motorReset_ = on;
    updateByteStream();
}

void B3::setRaceMode(bool on) {
    byteStream_[3] += on ? 0x20 : -0x20;
    raceMode_ = on;
    updateByteStream();
}

void B3::setLap(bool on) {
    byteStream_[3] += on ? 0x40 : -0x40;
    lap_ = on;
    updateByteStream();
}

void B3::setZoomZoom(bool on) {
    byteStream_[3] += on ? 0x80 : -0x80;
    zoomZoom_ = on;
    updateByteStream();
}

void B3::setAcceleration(unsigned short accel) {
    QByteArray in = Util::formatInt(accel, 2);
    byteStream_.replace(4, 2, in);
    acceleration_ = accel;
    updateByteStream();
}

void B3::setRegenBraking(unsigned short regen) {
    QByteArray in = Util::formatInt(regen, 2);
    byteStream_.replace(6, 2, in);
    regenBraking_ = regen;
    updateByteStream();
}

void B3::setRightSignalOut(bool on) {
    byteStream_[7] += on ? 0x01 : -0x01;
    rightSignalOut_ = on;
    updateByteStream();
}

void B3::setLeftSignalOut(bool on) {
    byteStream_[7] += on ? 0x02 : -0x02;
    leftSignalOut_ = on;
    updateByteStream();
}

void B3::setDaytimeRunningLightSignal(bool on) {
    byteStream_[7] += on ? 0x04 : -0x04;
    daytimeRunningLightSignal_ = on;
    updateByteStream();
}

void B3::setHeadlightSignal(bool on) {
    byteStream_[7] += on ? 0x08 : -0x08;
    headlightSignal_ = on;
    updateByteStream();
}

void B3::setBrakeLightSignal(bool on) {
    byteStream_[7] += on ? 0x10 : -0x10;
    brakeLightSignal_ = on;
    updateByteStream();
}

void B3::setHornSignal(bool on) {
    byteStream_[7] += on ? 0x20 : -0x20;
    hornSignal_ = on;
    updateByteStream();
}

void B3::updateByteStream(){
    // (1, size - 4)
    QByteArray checksum = Util::generateChecksum(byteStream_, 1, 7);
    // size - 3 and size - 2
    byteStream_[8] = checksum.at(0);
    byteStream_[9] = checksum.at(1);
    encodedByteStream_ = Util::encodeByteStream(byteStream_);
    emit encodedByteStreamStrChanged();
    emit byteStreamStrChanged();
}

QString B3::encodedByteStreamStr() const {
    return(encodedByteStream_.toHex(' '));
}

QString B3::byteStreamStr() const {
    return QString(byteStream_.toHex(' '));
}
