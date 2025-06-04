#ifndef TELEMETRY_H
#define TELEMETRY_H

#include "IPacket.h"
#include "../Util/PropertyDefinitions.h"

#include <QObject>
#include <QCanBus>

class Telemetry : public IPacket {
    Q_OBJECT

    DEFINE_PROPERTY(unsigned long long, GpsTime, 0x630)
    SUB_PROPERTY(unsigned short, Year, GpsTime, 0xFFFFULL, 0)
    SUB_PROPERTY(unsigned char, Month, GpsTime, 0xFFULL, 16)
    SUB_PROPERTY(unsigned char, Day, GpsTime, 0xFFUL, 24)
    SUB_PROPERTY(unsigned char, Hour, GpsTime, 0xFFUL, 32)
    SUB_PROPERTY(unsigned char, Minute, GpsTime, 0xFFUL, 40)
    SUB_PROPERTY(unsigned char, Second, GpsTime, 0xFFUL, 48)

    DEFINE_PROPERTY(unsigned int, GpsFlags, 0x631)
    SUB_PROPERTY(unsigned char, ValidityFlags, GpsFlags, 0xFF, 0)
    SUB_PROPERTY(unsigned char, FixStatusFlags, GpsFlags, 0xFF, 8)
    SUB_PROPERTY(unsigned char, AdditionalFlags, GpsFlags, 0xFF, 16)

    DEFINE_PROPERTY(unsigned long long, GpsPosition, 0x632)
    SUB_PROPERTY(float, Longitude, GpsPosition, 0xFFFFFFFF00000000ULL, 0)
    SUB_PROPERTY(float, Latitude, GpsPosition, 0xFFFFFFFFULL, 32)

    DEFINE_PROPERTY(unsigned long long, MpuAcceleration, 0x633)
    SUB_PROPERTY(unsigned short, AccelerationX, MpuAcceleration, 0xFFFFULL, 0)
    SUB_PROPERTY(unsigned short, AccelerationY, MpuAcceleration, 0xFFFFULL, 16)
    SUB_PROPERTY(unsigned short, AccelerationZ, MpuAcceleration, 0xFFFFULL, 32)

    DEFINE_PROPERTY(unsigned long long, MpuGyroscope, 0x634)
    SUB_PROPERTY(unsigned short, RotationX, MpuGyroscope, 0xFFFFULL, 0)
    SUB_PROPERTY(unsigned short, RotationY, MpuGyroscope, 0xFFFFULL, 16)
    SUB_PROPERTY(unsigned short, RotationZ, MpuGyroscope, 0xFFFFULL, 32)

    DEFINE_PROPERTY(unsigned short, MpuTemperature, 0x635)

public:
    Telemetry(QCanBusDevice* canDevice);
};

#endif // TELEMETRY_H
