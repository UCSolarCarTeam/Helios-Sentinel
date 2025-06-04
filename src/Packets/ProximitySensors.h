#ifndef PROXIMITYSENSORS_H
#define PROXIMITYSENSORS_H

#include "IPacket.h"
#include "../Util/PropertyDefinitions.h"

#include <QObject>
#include <QCanBus>
#include <QTimer>
#include <QDebug>

class ProximitySensors : public IPacket {
    Q_OBJECT

    DEFINE_PROPERTY(unsigned short, ProximitySensor1, 0x700)
    DEFINE_PROPERTY(unsigned short, ProximitySensor2, 0x701)
    DEFINE_PROPERTY(unsigned short, ProximitySensor3, 0x702)
    DEFINE_PROPERTY(unsigned short, ProximitySensor4, 0x703)

public:
    ProximitySensors(QCanBusDevice* canDevice);
};

#endif // PROXIMITYSENSORS_H
