#ifndef BATTERYFAULTS_H
#define BATTERYFAULTS_H

#include <QObject>

class BatteryFaults : public QObject
{
    Q_OBJECT
public:
    explicit BatteryFaults(QObject *parent = nullptr);

//     Q_PROPERTY(bool internalCommunication READ internalCommunication WRITE setInternalCommunication NOTIFY internalCommunicationChanged FINAL)
//     Q_PROPERTY(bool internalConversion READ internalConversion WRITE setInternalConversion NOTIFY internalConversionChanged FINAL)
//     Q_PROPERTY(bool weakCell READ weakCell WRITE setWeakCell NOTIFY weakCellChanged FINAL)
//     Q_PROPERTY(bool lowCellVoltage READ lowCellVoltage WRITE setLowCellVoltage NOTIFY lowCellVoltageChanged FINAL)
//     Q_PROPERTY(bool openWiring READ openWiring WRITE setOpenWiring NOTIFY openWiringChanged FINAL)
//     Q_PROPERTY(bool currentSensor READ currentSensor WRITE setCurrentSensor NOTIFY currentSensorChanged FINAL)
//     Q_PROPERTY(bool packVoltageSensor READ packVoltageSensor WRITE setPackVoltageSensor NOTIFY packVoltageSensorChanged FINAL)
//     Q_PROPERTY(bool weakPack READ weakPack WRITE setWeakPack NOTIFY weakPackChanged FINAL)
//     Q_PROPERTY(bool voltageRedundancy READ voltageRedundancy WRITE setVoltageRedundancy NOTIFY voltageRedundancyChanged FINAL)
//     Q_PROPERTY(bool fanMonitor READ fanMonitor WRITE setFanMonitor NOTIFY fanMonitorChanged FINAL)
//     Q_PROPERTY(bool thermistor READ thermistor WRITE setThermistor NOTIFY thermistorChanged FINAL)
//     Q_PROPERTY(bool canbusCommunications READ canbusCommunications WRITE setCanbusCommunications NOTIFY canbusCommunicationsChanged FINAL)
//     Q_PROPERTY(bool alwaysOnSupply READ alwaysOnSupply WRITE setAlwaysOnSupply NOTIFY alwaysOnSupplyChanged FINAL)
//     Q_PROPERTY(bool highVoltageIsolation READ highVoltageIsolation WRITE setHighVoltageIsolation NOTIFY highVoltageIsolationChanged FINAL)
//     Q_PROPERTY(bool powerSupply12V READ powerSupply12V WRITE setPowerSupply12V NOTIFY powerSupply12VChanged FINAL)
//     Q_PROPERTY(bool chargeLimitEnforcement READ chargeLimitEnforcement WRITE setChargeLimitEnforcement NOTIFY chargeLimitEnforcementChanged FINAL)
//     Q_PROPERTY(bool dischargeLimitEnforcement READ dischargeLimitEnforcement WRITE setDischargeLimitEnforcement NOTIFY dischargeLimitEnforcementChanged FINAL)
//     Q_PROPERTY(bool chargerSafetyRelay READ chargerSafetyRelay WRITE setChargerSafetyRelay NOTIFY chargerSafetyRelayChanged FINAL)
//     Q_PROPERTY(bool internalMemory READ internalMemory WRITE setInternalMemory NOTIFY internalMemoryChanged FINAL)
//     Q_PROPERTY(bool internalThermistor READ internalThermistor WRITE setInternalThermistor NOTIFY internalThermistorChanged FINAL)
//     Q_PROPERTY(bool internalLogic READ internalLogic WRITE setInternalLogic NOTIFY internalLogicChanged FINAL)

//     Q_PROPERTY(bool dclSoc READ dclSoc WRITE setDclSoc NOTIFY dclSocChanged FINAL)
//     Q_PROPERTY(bool dclCellResistance READ dclCellResistance WRITE setDclCellResistance NOTIFY dclCellResistanceChanged FINAL)
//     Q_PROPERTY(bool dclTemperature READ dclTemperature WRITE setDclTemperature NOTIFY dclTemperatureChanged FINAL)
//     Q_PROPERTY(bool dclPackVoltage READ dclPackVoltage WRITE setDclPackVoltage NOTIFY dclPackVoltageChanged FINAL)
//     Q_PROPERTY(bool dclCellVoltage READ dclCellVoltage WRITE setDclCellVoltage NOTIFY dclCellVoltageChanged FINAL)
//     Q_PROPERTY(bool dclCclVoltage READ dclCclVoltage WRITE setDclCclVoltage NOTIFY dclCclVoltageChanged FINAL)
//     Q_PROPERTY(bool dclCclCommunication READ dclCclCommunication WRITE setDclCclCommunication NOTIFY dclCclCommunicationChanged FINAL)
//     Q_PROPERTY(bool cclSoc READ cclSoc WRITE setCclSoc NOTIFY cclSocChanged FINAL)
//     Q_PROPERTY(bool cclCellResistance READ cclCellResistance WRITE setCclCellResistance NOTIFY cclCellResistanceChanged FINAL)
//     Q_PROPERTY(bool cclTemperature READ cclTemperature WRITE setCclTemperature NOTIFY cclTemperatureChanged FINAL)
//     Q_PROPERTY(bool cclCellVoltage READ cclCellVoltage WRITE setCclCellVoltage NOTIFY cclCellVoltageChanged FINAL)
//     Q_PROPERTY(bool cclPackVoltage READ cclPackVoltage WRITE setCclPackVoltage NOTIFY cclPackVoltageChanged FINAL)
//     Q_PROPERTY(bool cclChargerLatch READ cclChargerLatch WRITE setCclChargerLatch NOTIFY cclChargerLatchChanged FINAL)
//     Q_PROPERTY(bool cclCurrent READ cclCurrent WRITE setCclCurrent NOTIFY cclCurrentChanged FINAL)

//     Q_PROPERTY(QString byteStreamStr READ byteStreamStr NOTIFY byteStreamStrChanged FINAL)
//     Q_PROPERTY(QString encodedByteStreamStr READ encodedByteStreamStr NOTIFY encodedByteStreamStrChanged FINAL)

    bool internalCommunication();
    bool internalConversion();
    bool weakCell();
    bool lowCellVoltage();
    bool openWiring();
    bool currentSensor();
    bool packVoltageSensor();
    bool weakPack();
    bool voltageRedundancy();
    bool fanMonitor();
    bool thermistor();
    bool canbusCommunications();
    bool alwaysOnSupply();
    bool highVoltageIsolation();
    bool powerSupply12V();
    bool chargeLimitEnforcement();
    bool dischargeLimitEnforcement();
    bool chargerSafetyRelay();
    bool internalMemory();
    bool internalThermistor();
    bool internalLogic();

    bool dclSoc();
    bool dclCellResistance();
    bool dclTemperature();
    bool dclPackVoltage();
    bool dclCellVoltage();




signals:
};

#endif // BATTERYFAULTS_H
