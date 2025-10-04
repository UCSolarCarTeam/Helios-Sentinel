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

    DEFINE_PROPERTY(unsigned short, ProximitySensor1)
    DEFINE_PROPERTY(unsigned short, ProximitySensor2)
    DEFINE_PROPERTY(unsigned short, ProximitySensor3)
    DEFINE_PROPERTY(unsigned short, ProximitySensor4)

public:
    ProximitySensors(QCanBusDevice* canDevice);
};

#endif // PROXIMITYSENSORS_H
