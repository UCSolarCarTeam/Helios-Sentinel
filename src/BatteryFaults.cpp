#include "BatteryFaults.h"

BatteryFaults::BatteryFaults(QObject *parent)
    : QObject{parent}
{
    byteStream_.fill(0x00, 10);
    byteStream_[0] = 0x0A;
    byteStream_[1] = 0x06;
}

bool BatteryFaults::internalCommunication() const{
    return internalCommunication_;
}

bool BatteryFaults::internalConversion() const{
    return internalConversion_;
}

bool BatteryFaults::weakCell() const{
    return weakCell_;
}

bool BatteryFaults::lowCellVoltage() const{
    return lowCellVoltage_;
}

bool BatteryFaults::openWiring() const{
    return openWiring_;
}

bool BatteryFaults::currentSensor() const{
    return currentSensor_;
}

bool BatteryFaults::packVoltageSensor() const{
    return packVoltageSensor_;
}

bool BatteryFaults::weakPack() const{
    return weakPack_;
}

bool BatteryFaults::voltageRedundancy() const{
    return voltageRedundancy_;
}

bool BatteryFaults::fanMonitor() const{
    return fanMonitor_;
}

bool BatteryFaults::thermistor() const{
    return thermistor_;
}

bool BatteryFaults::canbusCommunications() const{
    return canbusCommunications_;
}

bool BatteryFaults::alwaysOnSupply() const{
    return alwaysOnSupply_;
}

bool BatteryFaults::highVoltageIsolation() const{
    return highVoltageIsolation_;
}

bool BatteryFaults::powerSupply12V() const{
    return powerSupply12V_;
}

bool BatteryFaults::chargeLimitEnforcement() const{
    return chargeLimitEnforcement_;
}

bool BatteryFaults::dischargeLimitEnforcement() const{
    return dischargeLimitEnforcement_;
}

bool BatteryFaults::chargerSafetyRelay() const{
    return chargerSafetyRelay_;
}

bool BatteryFaults::internalMemory() const{
    return internalMemory_;
}

bool BatteryFaults::internalThermistor() const{
    return internalThermistor_;
}

bool BatteryFaults::internalLogic() const{
    return internalLogic_;
}

bool BatteryFaults::dclSoc() const{
    return dclSoc_;
}

bool BatteryFaults::dclCellResistance() const{
    return dclCellResistance_;
}

bool BatteryFaults::dclTemperature() const{
    return dclTemperature_;
}

bool BatteryFaults::dclPackVoltage() const{
    return dclPackVoltage_;
}

bool BatteryFaults::dclCellVoltage() const{
    return dclCellVoltage_;
}

bool BatteryFaults::dclCclVoltage() const{
    return dclCclVoltage_;
}

bool BatteryFaults::dclCclCommunication() const{
    return dclCclCommunication_;
}

bool BatteryFaults::cclSoc() const{
    return cclSoc_;
}

bool BatteryFaults::cclCellResistance() const{
    return cclCellResistance_;
}

bool BatteryFaults::cclChargerVoltage() const{
    return cclChargerVoltage_;
}

bool BatteryFaults::cclTemperature() const{
    return cclTemperature_;
}

bool BatteryFaults::cclCellVoltage() const{
    return cclCellVoltage_;
}

bool BatteryFaults::cclPackVoltage() const{
    return cclPackVoltage_;
}

bool BatteryFaults::cclChargerLatch() const{
    return cclChargerLatch_;
}

bool BatteryFaults::cclCurrent() const{
    return cclCurrent_;
}

QByteArray BatteryFaults::byteStream() const{
    return byteStream_;
}

QByteArray BatteryFaults::encodedByteStream() const{
    return encodedByteStream_;
}

QString BatteryFaults::encodedByteStreamStr() const {
    return(encodedByteStream_.toHex(' '));
}

QString BatteryFaults::byteStreamStr() const {
    return QString(byteStream_.toHex(' '));
}











