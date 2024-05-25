#include "DriverControls.h"
#include "util.h"

#include <QDebug>

DriverControls::DriverControls(QObject *parent)
    : QObject{parent},
    driverControlsAlive_(false),
    headlightsOff_(false),
    headlightsHigh_(false),
    headlightsLow_(false),
    signalRight_(false),
    signalLeft_(false),
    hazards_(false),
    interior_(false),
    volumeUp_(false),
    volumeDown_(false),
    next_(false),
    prev_(false),
    brakes_(false),
    forward_(false),
    reverse_(false),
    pushToTalk_(false),
    horn_(false),
    reset_(false),
    aux_(false),
    lap_(false),
    acceleration_(0),
    regenBraking_(0)
{
    byteStream_.fill(0x00, 13);
    byteStream_[0] = 0x0D;
    byteStream_[1] = 0x04;

    updateByteStream();
}

bool DriverControls::driverControlsAlive() const{
    return driverControlsAlive_;
}

bool DriverControls::headlightsOff() const{
    return headlightsOff_;
}

bool DriverControls::headlightsLow() const{
    return headlightsLow_;
}

bool DriverControls::headlightsHigh() const{
    return headlightsHigh_;
}

bool DriverControls::signalRight() const{
    return signalRight_;
}

bool DriverControls::signalLeft() const{
    return signalLeft_;
}

bool DriverControls::hazards() const{
    return hazards_;
}

bool DriverControls::interior() const{
    return interior_;
}

bool DriverControls::volumeUp() const{
    return volumeUp_;
}

bool DriverControls::volumeDown() const{
    return volumeDown_;
}

bool DriverControls::next() const{
    return next_;
}

bool DriverControls::prev() const{
    return prev_;
}

bool DriverControls::brakes() const{
    return brakes_;
}

bool DriverControls::forward() const{
    return forward_;
}

bool DriverControls::reverse() const{
    return reverse_;
}

bool DriverControls::pushToTalk() const{
    return pushToTalk_;
}

bool DriverControls::horn() const{
    return horn_;
}

bool DriverControls::reset() const{
    return reset_;
}

bool DriverControls::aux() const{
    return aux_;
}

bool DriverControls::lap() const{
    return lap_;
}

unsigned short DriverControls::acceleration() const{
    return acceleration_;
}

unsigned short DriverControls::regenBraking() const{
    return regenBraking_;
}

QByteArray DriverControls::byteStream() const{
    return byteStream_;
}

QByteArray DriverControls::encodedByteStream() const{
    return encodedByteStream_;
}

QString DriverControls::byteStreamStr() const {
    return QString(byteStream_.toHex(' '));
}

QString DriverControls::encodedByteStreamStr() const{
    return QString(encodedByteStream_.toHex(' '));
}

void DriverControls::setDriverControlsAlive(bool alive){
    byteStream_[2] = alive ? 0x01 : 0x00;
    driverControlsAlive_ = alive;
    updateByteStream();
}

void DriverControls::setHeadlightsOff(bool on){
    byteStream_[3] += on ? 0x01 : -0x01;
    headlightsOff_ = on;
    updateByteStream();
}

void DriverControls::setHeadlightsLow(bool on){
    byteStream_[3] += on ? 0x02 : -0x02;
    headlightsLow_ = on;
    updateByteStream();
}

void DriverControls::setHeadlightsHigh(bool on){
    byteStream_[3] += on ? 0x04 : -0x04;
    headlightsLow_ = on;
    updateByteStream();
}

void DriverControls::setSignalRight(bool on){
    byteStream_[3] += on ? 0x08 : -0x08;
    signalRight_ = on;
    updateByteStream();
}

void DriverControls::setSignalLeft(bool on){
    byteStream_[3] += on ? 0x10 : -0x10;
    signalLeft_ = on;
    updateByteStream();
}

void DriverControls::setHazards(bool on){
    byteStream_[3] += on ? 0x20 : -0x20;
    hazards_ = on;
    updateByteStream();
}

void DriverControls::setInterior(bool on){
    byteStream_[3] += on ? 0x40 : -0x40;
    interior_ = on;
    updateByteStream();
}

void DriverControls::setVolumeUp(bool on){
    byteStream_[4] += on ? 0x01 : -0x01;
    volumeUp_ = on;
    updateByteStream();
}

void DriverControls::setVolumeDown(bool on){
    byteStream_[4] += on ? 0x02 : -0x02;
    volumeDown_ = on;
    updateByteStream();
}

void DriverControls::setNext(bool on){
    byteStream_[4] += on ? 0x04 : -0x04;
    next_ = on;
    updateByteStream();
}

void DriverControls::setPrev(bool on){
    byteStream_[4] += on ? 0x08 : -0x08;
    prev_ = on;
    updateByteStream();
}

void DriverControls::setBrakes(bool on){
    byteStream_[9] += on ? 0x01 : -0x01;
    brakes_ = on;
    updateByteStream();
}

void DriverControls::setForward(bool on){
    byteStream_[9] += on ? 0x02 : -0x02;
    forward_ = on;
    updateByteStream();
}

void DriverControls::setReverse(bool on){
    byteStream_[9] += on ? 0x04 : -0x04;
    reverse_ = on;
    updateByteStream();
}

void DriverControls::setPushToTalk(bool on){
    byteStream_[9] += on ? 0x08 : -0x08;
    pushToTalk_ = on;
    updateByteStream();
}

void DriverControls::setHorn(bool on){
    byteStream_[9] += on ? 0x10 : -0x10;
    horn_ = on;
    updateByteStream();
}

void DriverControls::setReset(bool on){
    byteStream_[9] += on ? 0x20 : -0x20;
    reset_ = on;
    updateByteStream();
}

void DriverControls::setAux(bool on){
    byteStream_[9] += on ? 0x40 : -0x40;
    reset_ = on;
    updateByteStream();
}

void DriverControls::setLap(bool on){
    byteStream_[9] += on ? 0x80 : -0x80;
    lap_ = on;
    updateByteStream();
}

void DriverControls::setAcceleration(unsigned short accel){
    // qDebug() << "ACCEL: " << accel;
    // unsigned char highByte = (accel >> 8) & 0xFF;  // Most significant byte
    // unsigned char lowByte = accel & 0xFF;
    // byteStream_[5] = lowByte;
    // byteStream_[6] = highByte;
    QByteArray in = Util::formatInt(accel, 2);
    byteStream_.replace(5, 2, in);
    acceleration_ = accel;
    updateByteStream();
}

void DriverControls::setRegenBraking(unsigned short rg){
    // qDebug() << "RG: " << rg;
    // unsigned char highByte = (rg >> 8) & 0xFF;  // Most significant byte
    // unsigned char lowByte = rg & 0xFF;
    // byteStream_[7] = lowByte;
    // byteStream_[8] = highByte;
    QByteArray in = Util::formatInt(rg, 2);
    byteStream_.replace(7, 2, in);
    regenBraking_ = rg;
    updateByteStream();
}

void DriverControls::updateByteStream(){
    QByteArray checksum = Util::generateChecksum(byteStream_, 1, 9);
    byteStream_[10] = checksum.at(0);
    byteStream_[11] = checksum.at(1);
    encodedByteStream_ = Util::encodeByteStream(byteStream_);
    emit encodedByteStreamStrChanged();
    emit byteStreamStrChanged();
}

