#include "Battery.h"
#include "util.h"

Battery::Battery(QObject *parent)
    : QObject{parent}
{
    byteStream_.fill(0x00, 52);
    byteStream_[0] = 0x34;
    byteStream_[1] = 0x07;
    updateByteStream();
}

bool Battery::bmuAlive() const{
    return bmuAlive_;
}

bool Battery::dischargeRelay() const{
    return dischargeRelay_;
}

bool Battery::chargeRelay() const{
    return chargeRelay_;
}

bool Battery::chargerSafety() const{
    return chargerSafety_;
}

bool Battery::malfunctionIndicator() const{
    return malfunctionIndicator_;
}

bool Battery::multiPurposeInputSignal() const{
    return multiPurposeInputSignal_;
}

bool Battery::alwaysOnSignal() const{
    return alwaysOnSignal_;
}

bool Battery::isReadySignal() const{
    return isReadySignal_;
}

bool Battery::isChargingSignal() const{
    return isChargingSignal_;
}

int Battery::populatedCells() const{
    return populatedCells_;
}

int Battery::input12V() const{
    return input12V_;
}

int Battery::fanVoltage() const{
    return fanVoltage_;
}

int Battery::packCurrent() const{
    return packCurrent_;
}

int Battery::packVoltage() const{
    return packVoltage_;
}

int Battery::packSoc() const{
    return packSoc_;
}

int Battery::packAmphours() const{
    return packAmphours_;
}

int Battery::packDod() const{
    return packDod_;
}

int Battery::highTemp() const{
    return highTemp_;
}

int Battery::highThermistorId() const{
    return highThermistorId_;
}

int Battery::lowTemp() const{
    return lowTemp_;
}

int Battery::lowThermistorId() const{
    return lowThermistorId_;
}

int Battery::avgTemp() const{
    return avgTemp_;
}

int Battery::internalTemp() const{
    return internalTemp_;
}

int Battery::fanSpeed() const{
    return fanSpeed_;
}

int Battery::reqFanSpeed() const{
    return reqFanSpeed_;
}

int Battery::lowCellVoltage() const{
    return lowCellVoltage_;
}

int Battery::lowCellVoltageId() const{
    return lowCellVoltageId_;
}

int Battery::highCellVoltage() const{
    return highCellVoltage_;
}

int Battery::highCellVoltageId() const{
    return highCellVoltageId_;
}

int Battery::avgCellVoltage() const{
    return avgCellVoltage_;
}

QByteArray Battery::byteStream() const{
    return byteStream_;
}

QByteArray Battery::encodedByteStream() const{
    return encodedByteStream_;
}

QString Battery::byteStreamStr() const {
    return QString(byteStream_.toHex(' '));
}

QString Battery::encodedByteStreamStr() const{
    return QString(encodedByteStream_.toHex(' '));
}

void Battery::setBmuAlive(bool on){
    byteStream_[2] = on ? 0x01 : 0x00;
    bmuAlive_ = on;
    updateByteStream();
}

void Battery::setDischargeRelay(bool on){
    byteStream_[3] += on ? 0x01 : -0x01;
    dischargeRelay_ = on;
    updateByteStream();
}

void Battery::setChargeRelay(bool on){
    byteStream_[3] += on ? 0x02 : -0x02;
    chargeRelay_ = on;
    updateByteStream();
}

void Battery::setChargerSafety(bool on){
    byteStream_[3] += on ? 0x04 : -0x04;
    chargerSafety_ = on;
    updateByteStream();
}

void Battery::setMalfunctionIndicator(bool on){
    byteStream_[3] += on ? 0x08 : -0x08;
    malfunctionIndicator_ = on;
    updateByteStream();
}

void Battery::setMultiPurposeInputSignal(bool on){
    byteStream_[3] += on ? 0x10 : -0x10;
    multiPurposeInputSignal_ = on;
    updateByteStream();
}

void Battery::setAlwaysOnSignal(bool on){
    byteStream_[3] += on ? 0x20 : -0x20;
    alwaysOnSignal_ = on;
    updateByteStream();
}

void Battery::setIsReadySignal(bool on){
    byteStream_[3] += on ? 0x40 : -0x40;
    isReadySignal_ = on;
    updateByteStream();
}

void Battery::setIsChargingSignal(bool on){
    byteStream_[3] += on ? 0x80 : -0x80;
    isChargingSignal_ = on;
    updateByteStream();
}

void Battery::setPopulatedCells(int i){
    byteStream_[4] = Util::formatInt(i, 1)[0];
    populatedCells_ = i;
    updateByteStream();
}

void Battery::setInput12V(int i){
    QByteArray in = Util::formatInt(i, 4);
    byteStream_.replace(5, 4, in);
    input12V_ = i;
    updateByteStream();
}

void Battery::setFanVoltage(int i){
    QByteArray in = Util::formatInt(i, 4);
    byteStream_.replace(9, 4, in);
    fanVoltage_ = i;
    updateByteStream();
}

void Battery::setPackCurrent(int i){
    QByteArray in = Util::formatInt(i, 4);
    byteStream_.replace(13, 4, in);
    packCurrent_ = i;
    updateByteStream();
}

void Battery::setPackVoltage(int i){
    QByteArray in = Util::formatInt(i, 4);
    byteStream_.replace(17, 4, in);
    packCurrent_ = i;
    updateByteStream();
}

void Battery::setPackSoc(int i){
    QByteArray in = Util::formatInt(i, 4);
    byteStream_.replace(21, 4, in);
    packSoc_ = i;
    updateByteStream();
}

void Battery::setPackAmphours(int i){
    QByteArray in = Util::formatInt(i, 4);
    byteStream_.replace(25, 4, in);
    packAmphours_ = i;
    updateByteStream();
}

void Battery::setPackDod(int i){
    QByteArray in = Util::formatInt(i, 4);
    byteStream_.replace(29, 4, in);
    packDod_ = i;
    updateByteStream();
}

void Battery::setHighTemp(int i){
    QByteArray in = Util::formatInt(i, 1);
    byteStream_[33] = in[0];
    highTemp_ = i;
    updateByteStream();
}

void Battery::setHighThermistorId(int i){
    QByteArray in = Util::formatInt(i, 1);
    byteStream_[34] = in[0];
    highThermistorId_ = i;
    updateByteStream();
}

void Battery::setLowTemp(int i){
    QByteArray in = Util::formatInt(i, 1);
    byteStream_[35] = in[0];
    lowTemp_ = i;
    updateByteStream();
}

void Battery::setLowThermistorId(int i){
    QByteArray in = Util::formatInt(i, 1);
    byteStream_[36] = in[0];
    lowThermistorId_ = i;
    updateByteStream();
}

void Battery::setAvgTemp(int i){
    QByteArray in = Util::formatInt(i, 1);
    byteStream_[37] = in[0];
    avgTemp_ = i;
    updateByteStream();
}

void Battery::setInternalTemp(int i){
    QByteArray in = Util::formatInt(i, 1);
    byteStream_[38] = in[0];
    internalTemp_ = i;
    updateByteStream();
}

void Battery::setFanSpeed(int i){
    QByteArray in = Util::formatInt(i, 1);
    byteStream_[39] = in[0];
    fanSpeed_ = i;
    updateByteStream();
}

void Battery::setReqFanSpeed(int i){
    QByteArray in = Util::formatInt(i, 1);
    byteStream_[40] = in[0];
    reqFanSpeed_ = i;
    updateByteStream();
}

void Battery::setLowCellVoltage(int i){
    QByteArray in = Util::formatInt(i, 2);
    byteStream_.replace(41, 2, in);
    lowCellVoltage_ = i;
    updateByteStream();
}

void Battery::setLowCellVoltageId(int i){
    QByteArray in = Util::formatInt(i, 1);
    byteStream_[43] = in[0];
    lowCellVoltageId_ = i;
    updateByteStream();
}

void Battery::setHighCellVoltage(int i){
    QByteArray in = Util::formatInt(i, 2);
    byteStream_.replace(44, 2, in);
    highCellVoltage_ = i;
    updateByteStream();
}

void Battery::setHighCellVoltageId(int i){
    QByteArray in = Util::formatInt(i, 1);
    byteStream_[46] = in[0];
    highCellVoltageId_ = i;
    updateByteStream();
}

void Battery::setAvgCellVoltage(int i){
    QByteArray in = Util::formatInt(i, 2);
    byteStream_.replace(47, 2, in);
    avgCellVoltage_ = i;
    updateByteStream();
}

void Battery::updateByteStream(){
    QByteArray checksum = Util::generateChecksum(byteStream_, 1, 48);
    byteStream_[49] = checksum.at(0);
    byteStream_[50] = checksum.at(1);
    encodedByteStream_ = Util::encodeByteStream(byteStream_);
    emit encodedByteStreamStrChanged();
    emit byteStreamStrChanged();
}

