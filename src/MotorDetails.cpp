#include "MotorDetails.h"
#include "util.h"

#include <QIODevice>
#include <QDebug>

MotorDetails::MotorDetails(int motor, QObject *parent)
    : QObject{parent}
{
    byteStream_.fill(0x00, 69); // packet size 69 - fill zeros by defualt
    byteStream_[0] = 0x45;      // packet size 69
    motorNum_ = motor;
    QByteArray motorID = Util::formatInt(motor + 2, 1);
    byteStream_[1] = motorID[0];
    updateByteStream();         //generate checksum and encode empty packet
}

int MotorDetails::phaseBCurrent() const { return phaseBCurrent_; }
int MotorDetails::phaseCCurrent() const { return phaseCCurrent_; }
int MotorDetails::motorVoltageReal() const { return motorVoltageReal_; }
int MotorDetails::motorVoltageImag() const { return motorVoltageImag_; }
int MotorDetails::motorCurrentReal() const { return motorCurrentReal_; }
int MotorDetails::motorCurrentImag() const { return motorCurrentImag_; }
int MotorDetails::blackEMF() const { return blackEMF_; }
int MotorDetails::voltageRailSupply15() const { return voltageRailSupply15_; }
int MotorDetails::voltageRailSupply3() const { return voltageRailSupply3_; }
int MotorDetails::voltageRailSupply2() const { return voltageRailSupply2_; }
int MotorDetails::heatSinkTemp() const { return heatSinkTemp_; }
int MotorDetails::motorTemp() const { return motorTemp_; }
int MotorDetails::dspBoardTemp() const { return dspBoardTemp_; }
int MotorDetails::dcBusAmpHours() const { return dcBusAmpHours_; }
int MotorDetails::odometer() const { return odometer_; }
int MotorDetails::slipSpeed() const { return slipSpeed_; }
int MotorDetails::motorNum() const { return motorNum_; }

QByteArray MotorDetails::encodedByteStream() const { return encodedByteStream_; }

void MotorDetails::setPhaseCCurrent(int value) {
    QByteArray in = Util::formatFloat(value);
    byteStream_.replace(2, 4, in);
    phaseCCurrent_ = value;
    updateByteStream();
}

void MotorDetails::setPhaseBCurrent(int value) {
    QByteArray in = Util::formatFloat(value);
    byteStream_.replace(6, 4, in);
    phaseBCurrent_ = value;
    updateByteStream();
}

void MotorDetails::setMotorVoltageReal(int value) {
    QByteArray in = Util::formatFloat(value);
    byteStream_.replace(10, 4, in);
    motorVoltageReal_ = value;
    updateByteStream();
}

void MotorDetails::setMotorVoltageImag(int value) {
    QByteArray in = Util::formatFloat(value);
    byteStream_.replace(14, 4, in);
    motorVoltageImag_ = value;
    updateByteStream();
}

void MotorDetails::setMotorCurrentReal(int value) {
    QByteArray in = Util::formatFloat(value);
    byteStream_.replace(18, 4, in);
    motorCurrentReal_ = value;
    updateByteStream();
}

void MotorDetails::setMotorCurrentImag(int value) {
    QByteArray in = Util::formatFloat(value);
    byteStream_.replace(22, 4, in);
    motorCurrentImag_ = value;
    updateByteStream();
}

void MotorDetails::setBlackEMF(int value) {
    QByteArray in = Util::formatFloat(value);
    byteStream_.replace(26, 4, in);
    blackEMF_ = value;
    updateByteStream();
}

void MotorDetails::setVoltageRailSupply15(int value) {
    QByteArray in = Util::formatFloat(value);
    byteStream_.replace(30, 4, in);
    voltageRailSupply15_ = value;
    updateByteStream();
}

void MotorDetails::setVoltageRailSupply3(int value) {
    QByteArray in = Util::formatFloat(value);
    byteStream_.replace(34, 4, in);
    voltageRailSupply3_ = value;
    updateByteStream();
}

void MotorDetails::setVoltageRailSupply2(int value) {
    QByteArray in = Util::formatFloat(value);
    byteStream_.replace(38, 4, in);
    voltageRailSupply2_ = value;
    updateByteStream();
}

void MotorDetails::setHeatSinkTemp(int value) {
    QByteArray in = Util::formatFloat(value);
    byteStream_.replace(42, 4, in);
    heatSinkTemp_ = value;
    updateByteStream();
}

void MotorDetails::setMotorTemp(int value) {
    QByteArray in = Util::formatFloat(value);
    byteStream_.replace(46, 4, in);
    motorTemp_ = value;
    updateByteStream();
}

void MotorDetails::setDspBoardTemp(int value) {
    QByteArray in = Util::formatFloat(value);
    byteStream_.replace(50, 4, in);
    dspBoardTemp_ = value;
    updateByteStream();
}

void MotorDetails::setDcBusAmpHours(int value) {
    QByteArray in = Util::formatFloat(value);
    byteStream_.replace(54, 4, in);
    dcBusAmpHours_ = value;
    updateByteStream();
}

void MotorDetails::setOdometer(int value) {
    QByteArray in = Util::formatFloat(value);
    byteStream_.replace(58, 4, in);
    odometer_ = value;
    updateByteStream();
}

void MotorDetails::setSlipSpeed(int value) {
    QByteArray in = Util::formatFloat(value);
    byteStream_.replace(62, 4, in);
    slipSpeed_ = value;
    updateByteStream();
}

void MotorDetails::setMotorNum(int value) {
    motorNum_ = value;
}

void MotorDetails::updateByteStream(){
    // (1, size - 4)
    QByteArray checksum = Util::generateChecksum(byteStream_, 1, 65);
    // size - 3 and size - 2
    byteStream_[66] = checksum.at(0);
    byteStream_[67] = checksum.at(1);
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



