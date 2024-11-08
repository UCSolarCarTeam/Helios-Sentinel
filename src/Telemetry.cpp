#include "Telemetry.h"

#include "util.h"

#include <QIODevice>
#include <QDebug>

Telemetry::Telemetry(QObject *parent)
    : QObject(parent),
    gpsYear_(0),
    gpsMonth_(0),
    gpsDay_(0),
    gpsHour_(0),
    gpsMinute_(0),
    gpsSecond_(0),
    gpsValidityFlags_(0),
    gpsFixStatusFlags_(0),
    gpsAdditionalFlags_(0),
    gpsLongitude_(0),
    gpsLatitude_(0),
    mpuAccelerationX_(0),
    mpuAccelerationY_(0),
    mpuAccelerationZ_(0),
    mpuRotationX_(0),
    mpuRotationY_(0),
    mpuRotationZ_(0),
    mpuTemperature_(0)
{
    byteStream_.fill(0x00, 37); // packet size 37 - fill zeros by defualt
    byteStream_[0] = 0x25;      // packet size 37
    byteStream_[1] = 0x05;      // packet ID (5)

    updateByteStream();         //generate checksum and encode empty packet
}


unsigned short Telemetry::gpsYear() const { return gpsYear_; }
unsigned char Telemetry::gpsMonth() const { return gpsMonth_; }
unsigned char Telemetry::gpsDay() const { return gpsDay_; }
unsigned char Telemetry::gpsHour() const { return gpsHour_; }
unsigned char Telemetry::gpsMinute() const { return gpsMinute_; }
unsigned char Telemetry::gpsSecond() const { return gpsSecond_; }

unsigned char Telemetry::gpsValidityFlags() const { return gpsValidityFlags_; }
unsigned char Telemetry::gpsFixStatusFlags() const { return gpsFixStatusFlags_; }
unsigned char Telemetry::gpsAdditionalFlags() const { return gpsAdditionalFlags_; }

int Telemetry::gpsLongitude() const { return gpsLongitude_; }
int Telemetry::gpsLatitude() const { return gpsLatitude_; }

unsigned short Telemetry::mpuAccelerationX() const { return mpuAccelerationX_; }
unsigned short Telemetry::mpuAccelerationY() const { return mpuAccelerationY_; }
unsigned short Telemetry::mpuAccelerationZ() const { return mpuAccelerationZ_; }
unsigned short Telemetry::mpuRotationX() const { return mpuRotationX_; }
unsigned short Telemetry::mpuRotationY() const { return mpuRotationY_; }
unsigned short Telemetry::mpuRotationZ() const { return mpuRotationZ_; }
unsigned short Telemetry::mpuTemperature() const { return mpuTemperature_; }

QByteArray Telemetry::encodedByteStream() const { return encodedByteStream_; }


void Telemetry::setGpsYear(unsigned short value) {
    QByteArray in = Util::formatInt(value, 2);
    byteStream_.replace(2, 2, in);
    gpsYear_ = value;
    updateByteStream();
}

void Telemetry::setGpsMonth(unsigned char value) {
    byteStream_[4] = value;
    gpsMonth_ = value;
    updateByteStream();
}

void Telemetry::setGpsDay(unsigned char value) {
    byteStream_[5] = value;
    gpsDay_ = value;
    updateByteStream();
}

void Telemetry::setGpsHour(unsigned char value) {
    byteStream_[6] = value;
    gpsHour_ = value;
    updateByteStream();
}

void Telemetry::setGpsMinute(unsigned char value) {
    byteStream_[7] = value;
    gpsMinute_ = value;
    updateByteStream();
}

void Telemetry::setGpsSecond(unsigned char value) {
    byteStream_[8] = value;
    gpsSecond_ = value;
    updateByteStream();
}

void Telemetry::setGpsValidityFlags(unsigned char value) {
    byteStream_[9] = value;
    gpsValidityFlags_ = value;
    updateByteStream();
}

void Telemetry::setGpsFixStatusFlags(unsigned char value) {
    byteStream_[10] = value;
    gpsFixStatusFlags_ = value;
    updateByteStream();
}

void Telemetry::setGpsAdditionalFlags(unsigned char value) {
    byteStream_[11] = value;
    gpsAdditionalFlags_ = value;
    updateByteStream();
}

void Telemetry::setGpsLongitude(int value) {
    QByteArray in = Util::formatInt(value, 4);
    byteStream_.replace(12, 4, in);
    gpsLongitude_ = value;
    updateByteStream();
}

void Telemetry::setGpsLatitude(int value) {
    QByteArray in = Util::formatInt(value, 4);
    byteStream_.replace(16, 4, in);
    gpsLatitude_ = value;
    updateByteStream();
}

void Telemetry::setMpuAccelerationX(unsigned short value) {
    QByteArray in = Util::formatInt(value, 2);
    byteStream_.replace(20, 2, in);
    mpuAccelerationX_ = value;
    updateByteStream();
}

void Telemetry::setMpuAccelerationY(unsigned short value) {
    QByteArray in = Util::formatInt(value, 2);
    byteStream_.replace(22, 2, in);
    mpuAccelerationY_ = value;
    updateByteStream();
}

void Telemetry::setMpuAccelerationZ(unsigned short value) {
    QByteArray in = Util::formatInt(value, 2);
    byteStream_.replace(24, 2, in);
    mpuAccelerationZ_ = value;
    updateByteStream();
}

void Telemetry::setMpuRotationX(unsigned short value) {
    QByteArray in = Util::formatInt(value, 2);
    byteStream_.replace(26, 2, in);
    mpuRotationX_ = value;
    updateByteStream();
}

void Telemetry::setMpuRotationY(unsigned short value) {
    QByteArray in = Util::formatInt(value, 2);
    byteStream_.replace(28, 2, in);
    mpuRotationY_ = value;
    updateByteStream();
}

void Telemetry::setMpuRotationZ(unsigned short value) {
    QByteArray in = Util::formatInt(value, 2);
    byteStream_.replace(30, 2, in);
    mpuRotationZ_ = value;
    updateByteStream();
}

void Telemetry::setMpuTemperature(unsigned short value) {
    QByteArray in = Util::formatInt(value, 2);
    byteStream_.replace(32, 2, in);
    mpuTemperature_ = value;
    updateByteStream();
}


void Telemetry::updateByteStream(){
    // (1, size - 4)
    QByteArray checksum = Util::generateChecksum(byteStream_, 1, 33);
    // size - 3 and size - 2
    byteStream_[34] = checksum.at(0);
    byteStream_[35] = checksum.at(1);
    encodedByteStream_ = Util::encodeByteStream(byteStream_);
    emit encodedByteStreamStrChanged();
    emit byteStreamStrChanged();
}

QString Telemetry::encodedByteStreamStr() const {
    return(encodedByteStream_.toHex(' '));
}

QString Telemetry::byteStreamStr() const {
    return QString(byteStream_.toHex(' '));
}



