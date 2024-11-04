#include "Mbms.h"

#include "util.h"

#include <QIODevice>
#include <QDebug>

Mbms::Mbms(QObject *parent)
    : QObject(parent),
    commonContactorState_(false),
    motorContactorState_(false),
    arrayContactorState_(false),
    lvContactorState_(false),
    chargeContactorState_(false),

    commonContactorError_(false),
    motorContactorError_(false),
    arrayContactorError_(false),
    lvContactorError_(false),
    chargeContactorError_(false),

    strobeBmsLight_(false),
    allowCharge_(false),
    highVoltageEnableState_(false),
    allowDischarge_(false),
    orionCanReceivedRecently_(false),
    dischargeShouldTrip_(false),
    chargeShouldTrip_(false),

    auxillaryBatteryVoltage_(0),
    motorVoltage_(0),
    arrayVoltage_(0),
    lvVoltage_(0),
    chargeVoltage_(0),
    commonCurrent_(0),
    motorCurrent_(0),
    arrayCurrent_(0),
    lvCurrent_(0),
    chargeCurrent_(0),

    highCellVoltageTrip_(false),
    lowCellVoltageTrip_(false),
    highCommonCurrentTrip_(false),
    motorTCTrip_(false),
    arrayTCTrip_(false),
    lvTCTrip_(false),
    chargeTCTrip_(false),
    protectionTrip_(false),
    orionMessageTimeoutTrip_(false),
    contactorDisconnectedTrip_(false)
{
    byteStream_.fill(0x00, 30); // packet size 30 - fill zeros by defualt
    byteStream_[0] = 0x1E;      // packet size 30
    byteStream_[1] = 0x09;      // packet ID (9)

    updateByteStream();         //generate checksum and encode empty packet
}

bool Mbms::commonContactorState() const { return commonContactorState_; }
bool Mbms::motorContactorState() const { return motorContactorState_; }
bool Mbms::arrayContactorState() const { return arrayContactorState_; }
bool Mbms::lvContactorState() const { return lvContactorState_; }
bool Mbms::chargeContactorState() const { return chargeContactorState_; }

bool Mbms::commonContactorError() const { return commonContactorError_; }
bool Mbms::motorContactorError() const { return motorContactorError_; }
bool Mbms::arrayContactorError() const { return arrayContactorError_; }
bool Mbms::lvContactorError() const { return lvContactorError_; }
bool Mbms::chargeContactorError() const { return chargeContactorError_; }

bool Mbms::strobeBmsLight() const { return strobeBmsLight_; }
bool Mbms::allowCharge() const { return allowCharge_; }
bool Mbms::highVoltageEnableState() const { return highVoltageEnableState_; }
bool Mbms::allowDischarge() const { return allowDischarge_; }
bool Mbms::orionCanReceivedRecently() const { return orionCanReceivedRecently_; }
bool Mbms::dischargeShouldTrip() const { return dischargeShouldTrip_; }
bool Mbms::chargeShouldTrip() const { return chargeShouldTrip_; }

unsigned short Mbms::auxillaryBatteryVoltage() const { return auxillaryBatteryVoltage_; }
unsigned short Mbms::motorVoltage() const { return motorVoltage_; }
unsigned short Mbms::arrayVoltage() const { return arrayVoltage_; }
unsigned short Mbms::lvVoltage() const { return lvVoltage_; }
unsigned short Mbms::chargeVoltage() const { return chargeVoltage_; }
unsigned short Mbms::commonCurrent() const { return commonCurrent_; }
unsigned short Mbms::motorCurrent() const { return motorCurrent_; }
unsigned short Mbms::arrayCurrent() const { return arrayCurrent_; }
unsigned short Mbms::lvCurrent() const { return lvCurrent_; }
unsigned short Mbms::chargeCurrent() const { return chargeCurrent_; }

bool Mbms::highCellVoltageTrip() const { return highCellVoltageTrip_; }
bool Mbms::lowCellVoltageTrip() const { return lowCellVoltageTrip_; }
bool Mbms::highCommonCurrentTrip() const { return highCommonCurrentTrip_; }
bool Mbms::motorTCTrip() const { return motorTCTrip_; }
bool Mbms::arrayTCTrip() const { return arrayTCTrip_; }
bool Mbms::lvTCTrip() const { return lvTCTrip_; }
bool Mbms::chargeTCTrip() const { return chargeTCTrip_; }
bool Mbms::protectionTrip() const { return protectionTrip_; }
bool Mbms::orionMessageTimeoutTrip() const { return orionMessageTimeoutTrip_; }
bool Mbms::contactorDisconnectedTrip() const { return contactorDisconnectedTrip_; }

QByteArray Mbms::encodedByteStream() const { return encodedByteStream_; }


void Mbms::setCommonContactorState(bool on) {
    byteStream_[2] += on ? 0x01 : -0x01;
    commonContactorState_ = on;
    updateByteStream();
}

void Mbms::setMotorContactorState(bool on) {
    byteStream_[2] += on ? 0x02 : -0x02;
    motorContactorState_ = on;
    updateByteStream();
}

void Mbms::setArrayContactorState(bool on) {
    byteStream_[2] += on ? 0x04 : -0x04;
    arrayContactorState_ = on;
    updateByteStream();
}

void Mbms::setLvContactorState(bool on) {
    byteStream_[2] += on ? 0x08 : -0x08;
    lvContactorState_ = on;
    updateByteStream();
}

void Mbms::setChargeContactorState(bool on) {
    byteStream_[2] += on ? 0x10 : -0x10;
    chargeContactorState_ = on;
    updateByteStream();
}

void Mbms::setCommonContactorError(bool on) {
    byteStream_[3] += on ? 0x01 : -0x01;
    commonContactorError_ = on;
    updateByteStream();
}

void Mbms::setMotorContactorError(bool on) {
    byteStream_[3] += on ? 0x02 : -0x02;
    motorContactorError_ = on;
    updateByteStream();
}

void Mbms::setArrayContactorError(bool on) {
    byteStream_[3] += on ? 0x04 : -0x04;
    arrayContactorError_ = on;
    updateByteStream();
}

void Mbms::setLvContactorError(bool on) {
    byteStream_[3] += on ? 0x08 : -0x08;
    lvContactorError_ = on;
    updateByteStream();
}

void Mbms::setChargeContactorError(bool on) {
    byteStream_[3] += on ? 0x10 : -0x10;
    chargeContactorError_ = on;
    updateByteStream();
}

void Mbms::setStrobeBmsLight(bool on) {
    byteStream_[4] += on ? 0x01 : -0x01;
    strobeBmsLight_ = on;
    updateByteStream();
}

void Mbms::setAllowCharge(bool on) {
    byteStream_[4] += on ? 0x02 : -0x02;
    allowCharge_ = on;
    updateByteStream();
}

void Mbms::setHighVoltageEnableState(bool on) {
    byteStream_[4] += on ? 0x04 : -0x04;
    highVoltageEnableState_ = on;
    updateByteStream();
}

void Mbms::setAllowDischarge(bool on) {
    byteStream_[4] += on ? 0x08 : -0x08;
    allowDischarge_ = on;
    updateByteStream();
}

void Mbms::setOrionCanReceivedRecently(bool on) {
    byteStream_[4] += on ? 0x10 : -0x10;
    orionCanReceivedRecently_ = on;
    updateByteStream();
}

void Mbms::setDischargeShouldTrip(bool on) {
    byteStream_[4] += on ? 0x20 : -0x20;
    dischargeShouldTrip_ = on;
    updateByteStream();
}

void Mbms::setChargeShouldTrip(bool on) {
    byteStream_[4] += on ? 0x40 : -0x40;
    chargeShouldTrip_ = on;
    updateByteStream();
}

void Mbms::setAuxillaryBatteryVoltage(unsigned short value) {
    QByteArray in = Util::formatInt(value, 2);
    byteStream_.replace(5, 2, in);
    auxillaryBatteryVoltage_ = value;
    updateByteStream();
}

void Mbms::setMotorVoltage(unsigned short value) {
    QByteArray in = Util::formatInt(value, 2);
    byteStream_.replace(7, 2, in);
    motorVoltage_ = value;
    updateByteStream();
}

void Mbms::setArrayVoltage(unsigned short value) {
    QByteArray in = Util::formatInt(value, 2);
    byteStream_.replace(9, 2, in);
    arrayVoltage_ = value;
    updateByteStream();
}

void Mbms::setLvVoltage(unsigned short value) {
    QByteArray in = Util::formatInt(value, 2);
    byteStream_.replace(11, 2, in);
    lvVoltage_ = value;
    updateByteStream();
}

void Mbms::setChargeVoltage(unsigned short value) {
    QByteArray in = Util::formatInt(value, 2);
    byteStream_.replace(13, 2, in);
    chargeVoltage_ = value;
    updateByteStream();
}

void Mbms::setCommonCurrent(unsigned short value) {
    QByteArray in = Util::formatInt(value, 2);
    byteStream_.replace(15, 2, in);
    commonCurrent_ = value;
    updateByteStream();
}

void Mbms::setMotorCurrent(unsigned short value) {
    QByteArray in = Util::formatInt(value, 2);
    byteStream_.replace(17, 2, in);
    motorCurrent_ = value;
    updateByteStream();
}

void Mbms::setArrayCurrent(unsigned short value) {
    QByteArray in = Util::formatInt(value, 2);
    byteStream_.replace(19, 2, in);
    arrayCurrent_ = value;
    updateByteStream();
}

void Mbms::setLvCurrent(unsigned short value) {
    QByteArray in = Util::formatInt(value, 2);
    byteStream_.replace(21, 2, in);
    lvCurrent_ = value;
    updateByteStream();
}

void Mbms::setChargeCurrent(unsigned short value) {
    QByteArray in = Util::formatInt(value, 2);
    byteStream_.replace(23, 2, in);
    chargeCurrent_ = value;
    updateByteStream();
}

void Mbms::setHighCellVoltageTrip(bool on) {
    byteStream_[25] += on ? 0x01 : -0x01;
    highCellVoltageTrip_ = on;
    updateByteStream();
}

void Mbms::setLowCellVoltageTrip(bool on) {
    byteStream_[25] += on ? 0x02 : -0x02;
    lowCellVoltageTrip_ = on;
    updateByteStream();
}

void Mbms::setHighCommonCurrentTrip(bool on) {
    byteStream_[25] += on ? 0x04 : -0x04;
    highCommonCurrentTrip_ = on;
    updateByteStream();
}

void Mbms::setMotorTCTrip(bool on) {
    byteStream_[25] += on ? 0x08 : -0x08;
    motorTCTrip_ = on;
    updateByteStream();
}

void Mbms::setArrayTCTrip(bool on) {
    byteStream_[25] += on ? 0x10 : -0x10;
    arrayTCTrip_ = on;
    updateByteStream();
}

void Mbms::setLvTCTrip(bool on) {
    byteStream_[25] += on ? 0x20 : -0x20;
    lvTCTrip_ = on;
    updateByteStream();
}

void Mbms::setChargeTCTrip(bool on) {
    byteStream_[25] += on ? 0x40 : -0x40;
    chargeTCTrip_ = on;
    updateByteStream();
}

void Mbms::setProtectionTrip(bool on) {
    byteStream_[25] += on ? 0x80 : -0x80;
    protectionTrip_ = on;
    updateByteStream();
}

void Mbms::setOrionMessageTimeoutTrip(bool on) {
    byteStream_[26] += on ? 0x01 : -0x01;
    orionMessageTimeoutTrip_ = on;
    updateByteStream();
}

void Mbms::setContactorDisconnectedTrip(bool on) {
    byteStream_[26] += on ? 0x02 : -0x02;
    contactorDisconnectedTrip_ = on;
    updateByteStream();
}


void Mbms::updateByteStream(){
    // (1, size - 4)
    QByteArray checksum = Util::generateChecksum(byteStream_, 1, 26);
    // size - 3 and size - 2
    byteStream_[27] = checksum.at(0);
    byteStream_[28] = checksum.at(1);
    encodedByteStream_ = Util::encodeByteStream(byteStream_);
    emit encodedByteStreamStrChanged();
    emit byteStreamStrChanged();
}

QString Mbms::encodedByteStreamStr() const {
    return(encodedByteStream_.toHex(' '));
}

QString Mbms::byteStreamStr() const {
    return QString(byteStream_.toHex(' '));
}

