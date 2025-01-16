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

int MotorDetailsElysia::phaseBCurrent() const { return phaseBCurrent_; }
int MotorDetailsElysia::phaseCCurrent() const { return phaseCCurrent_; }
int MotorDetailsElysia::motorVoltageReal() const { return motorVoltageReal_; }
int MotorDetailsElysia::motorVoltageImag() const { return motorVoltageImag_; }
int MotorDetailsElysia::motorCurrentReal() const { return motorCurrentReal_; }
int MotorDetailsElysia::motorCurrentImag() const { return motorCurrentImag_; }
int MotorDetailsElysia::blackEMF() const { return blackEMF_; }
int MotorDetailsElysia::voltageRailSupply15() const { return voltageRailSupply15_; }
int MotorDetailsElysia::voltageRailSupply3() const { return voltageRailSupply3_; }
int MotorDetailsElysia::voltageRailSupply2() const { return voltageRailSupply2_; }
int MotorDetailsElysia::heatSinkTemp() const { return heatSinkTemp_; }
int MotorDetailsElysia::motorTemp() const { return motorTemp_; }
int MotorDetailsElysia::dspBoardTemp() const { return dspBoardTemp_; }
int MotorDetailsElysia::dcBusAmpHours() const { return dcBusAmpHours_; }
int MotorDetailsElysia::odometer() const { return odometer_; }
int MotorDetailsElysia::slipSpeed() const { return slipSpeed_; }
int MotorDetailsElysia::motorNum() const { return motorNum_; }

QByteArray MotorDetailsElysia::encodedByteStream() const { return encodedByteStream_; }

void MotorDetailsElysia::setPhaseCCurrent(int value) {
    QByteArray in = Util::formatFloat(value);
    byteStream_.replace(2, 4, in);
    phaseCCurrent_ = value;
    updateByteStream();
}

void MotorDetailsElysia::setPhaseBCurrent(int value) {
    QByteArray in = Util::formatFloat(value);
    byteStream_.replace(6, 4, in);
    phaseBCurrent_ = value;
    updateByteStream();
}

void MotorDetailsElysia::setMotorVoltageReal(int value) {
    QByteArray in = Util::formatFloat(value);
    byteStream_.replace(10, 4, in);
    motorVoltageReal_ = value;
    updateByteStream();
}

void MotorDetailsElysia::setMotorVoltageImag(int value) {
    QByteArray in = Util::formatFloat(value);
    byteStream_.replace(14, 4, in);
    motorVoltageImag_ = value;
    updateByteStream();
}

void MotorDetailsElysia::setMotorCurrentReal(int value) {
    QByteArray in = Util::formatFloat(value);
    byteStream_.replace(18, 4, in);
    motorCurrentReal_ = value;
    updateByteStream();
}

void MotorDetailsElysia::setMotorCurrentImag(int value) {
    QByteArray in = Util::formatFloat(value);
    byteStream_.replace(22, 4, in);
    motorCurrentImag_ = value;
    updateByteStream();
}

void MotorDetailsElysia::setBlackEMF(int value) {
    QByteArray in = Util::formatFloat(value);
    byteStream_.replace(26, 4, in);
    blackEMF_ = value;
    updateByteStream();
}

void MotorDetailsElysia::setVoltageRailSupply15(int value) {
    QByteArray in = Util::formatFloat(value);
    byteStream_.replace(30, 4, in);
    voltageRailSupply15_ = value;
    updateByteStream();
}

void MotorDetailsElysia::setVoltageRailSupply3(int value) {
    QByteArray in = Util::formatFloat(value);
    byteStream_.replace(34, 4, in);
    voltageRailSupply3_ = value;
    updateByteStream();
}

void MotorDetailsElysia::setVoltageRailSupply2(int value) {
    QByteArray in = Util::formatFloat(value);
    byteStream_.replace(38, 4, in);
    voltageRailSupply2_ = value;
    updateByteStream();
}

void MotorDetailsElysia::setHeatSinkTemp(int value) {
    QByteArray in = Util::formatFloat(value);
    byteStream_.replace(42, 4, in);
    heatSinkTemp_ = value;
    updateByteStream();
}

void MotorDetailsElysia::setMotorTemp(int value) {
    QByteArray in = Util::formatFloat(value);
    byteStream_.replace(46, 4, in);
    motorTemp_ = value;
    updateByteStream();
}

void MotorDetailsElysia::setDspBoardTemp(int value) {
    QByteArray in = Util::formatFloat(value);
    byteStream_.replace(50, 4, in);
    dspBoardTemp_ = value;
    updateByteStream();
}

void MotorDetailsElysia::setDcBusAmpHours(int value) {
    QByteArray in = Util::formatFloat(value);
    byteStream_.replace(54, 4, in);
    dcBusAmpHours_ = value;
    updateByteStream();
}

void MotorDetailsElysia::setOdometer(int value) {
    QByteArray in = Util::formatFloat(value);
    byteStream_.replace(58, 4, in);
    odometer_ = value;
    updateByteStream();
}

void MotorDetailsElysia::setSlipSpeed(int value) {
    QByteArray in = Util::formatFloat(value);
    byteStream_.replace(62, 4, in);
    slipSpeed_ = value;
    updateByteStream();
}

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
