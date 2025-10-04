#ifndef MOTORDETAILS_H
#define MOTORDETAILS_H

#include "IPacket.h"
#include "../Util/PropertyDefinitions.h"

class MotorDetails : public IPacket{
    Q_OBJECT

    DEFINE_PROPERTY(unsigned long long, IdInfo)
    SUB_PROPERTY(unsigned int, TritiumId, IdInfo, 0xFFFFFFFFULL, 0)
    SUB_PROPERTY(unsigned int, SerialNumber, IdInfo, 0xFFFFFFFFULL, 32)

    DEFINE_PROPERTY(unsigned long long, Status)
    SUB_PROPERTY(unsigned short, LimitFlags, Status, 0xFFFFULL, 0)
    SUB_PROPERTY(unsigned short, ErrorFlags, Status, 0xFFFFULL, 16)
    SUB_PROPERTY(unsigned short, ActiveMotor, Status, 0xFFFFULL, 32)
    SUB_PROPERTY(unsigned char, TxErrorCount, Status, 0xFFULL, 48)
    SUB_PROPERTY(unsigned char, RxErrorCount, Status, 0xFFULL, 56)

    DEFINE_PROPERTY(unsigned long long, BusMeasurement)
    SUB_PROPERTY(unsigned int, BusVoltage, BusMeasurement, 0xFFFFFFFFULL, 0)
    SUB_PROPERTY(unsigned int, BusCurrent, BusMeasurement, 0xFFFFFFFFULL, 32)

    DEFINE_PROPERTY(unsigned long long, VelocityMeasurement)
    SUB_PROPERTY(unsigned int, MotorVelocity, VelocityMeasurement, 0xFFFFFFFFULL, 0)
    SUB_PROPERTY(unsigned int, VehicleVelocity, VelocityMeasurement, 0xFFFFFFFFULL, 32)

    DEFINE_PROPERTY(unsigned long long, PhaseCurrentMeasurement)
    SUB_PROPERTY(unsigned int, PhaseCurrentB, PhaseCurrentMeasurement, 0xFFFFFFFFULL, 0)
    SUB_PROPERTY(unsigned int, PhaseCurrentC, PhaseCurrentMeasurement, 0xFFFFFFFFULL, 32)

    DEFINE_PROPERTY(unsigned long long, MotorVoltageVectorMeasurement)
    SUB_PROPERTY(unsigned int, Vq, MotorVoltageVectorMeasurement, 0xFFFFFFFFULL, 0)
    SUB_PROPERTY(unsigned int, Vd, MotorVoltageVectorMeasurement, 0xFFFFFFFFULL, 32)

    DEFINE_PROPERTY(unsigned long long, MotorCurrentVectorMeasurement)
    SUB_PROPERTY(unsigned int, Iq, MotorCurrentVectorMeasurement, 0xFFFFFFFFULL, 0)
    SUB_PROPERTY(unsigned int, Id, MotorCurrentVectorMeasurement, 0xFFFFFFFFULL, 32)

    DEFINE_PROPERTY(unsigned long long, MotorBackEmfMeasurementPrediction)
    SUB_PROPERTY(unsigned int, Bemfq, MotorBackEmfMeasurementPrediction, 0xFFFFFFFFULL, 0)
    SUB_PROPERTY(unsigned int, Bemfd, MotorBackEmfMeasurementPrediction, 0xFFFFFFFFULL, 32)

    DEFINE_PROPERTY(unsigned long long, VoltageRail15VMeasurement)
    SUB_PROPERTY(unsigned int, Supply15V, VoltageRail15VMeasurement, 0xFFFFFFFFULL, 0)
    SUB_PROPERTY(unsigned int, ReservedSupply15V, VoltageRail15VMeasurement, 0xFFFFFFFFULL, 32)

    DEFINE_PROPERTY(unsigned long long, VoltageRail3V31V9Measurement)
    SUB_PROPERTY(unsigned int, Supply1V9, VoltageRail3V31V9Measurement, 0xFFFFFFFFULL, 0)
    SUB_PROPERTY(unsigned int, Supply3V3, VoltageRail3V31V9Measurement, 0xFFFFFFFFULL, 32)

    DEFINE_PROPERTY(unsigned long long, Reserved0A)
    SUB_PROPERTY(unsigned int, Reserved0A0, Reserved0A, 0xFFFFFFFFULL, 0)
    SUB_PROPERTY(unsigned int, Reserved0A1, Reserved0A, 0xFFFFFFFFULL, 32)

    DEFINE_PROPERTY(unsigned long long, HeatsinkMotorTempMeasurement)
    SUB_PROPERTY(unsigned int, MotorTemp, HeatsinkMotorTempMeasurement, 0xFFFFFFFFULL, 0)
    SUB_PROPERTY(unsigned int, HeatsinkTemp, HeatsinkMotorTempMeasurement, 0xFFFFFFFFULL, 32)

    DEFINE_PROPERTY(unsigned long long, DspBoardTempMeasurement)
    SUB_PROPERTY(unsigned int, DspBoardTemp, DspBoardTempMeasurement, 0xFFFFFFFFULL, 0)
    SUB_PROPERTY(unsigned int, ReservedDspBoardTemp, DspBoardTempMeasurement, 0xFFFFFFFFULL, 32)

    DEFINE_PROPERTY(unsigned long long, Reserved0D)
    SUB_PROPERTY(unsigned int, Reserved0D0, Reserved0D, 0xFFFFFFFFULL, 0)
    SUB_PROPERTY(unsigned int, Reserved0D1, Reserved0D, 0xFFFFFFFFULL, 32)

    DEFINE_PROPERTY(unsigned long long, OdometerBusAhMeasurement)
    SUB_PROPERTY(unsigned int, Odometer, OdometerBusAhMeasurement, 0xFFFFFFFFULL, 0)
    SUB_PROPERTY(unsigned int, DCBusAh, OdometerBusAhMeasurement, 0xFFFFFFFFULL, 32)

    DEFINE_PROPERTY(unsigned long long, SlipSpeedMeasurement)
    SUB_PROPERTY(unsigned int, SlipSpeed, SlipSpeedMeasurement, 0xFFFFFFFFULL, 0)
    SUB_PROPERTY(unsigned int, ReservedSlipSpeed, SlipSpeedMeasurement, 0xFFFFFFFFULL, 32)

public:
    MotorDetails(QCanBusDevice* canDevice);
};

#endif // MOTORDETAILS_H
