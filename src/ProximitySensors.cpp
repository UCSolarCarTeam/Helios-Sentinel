#include "ProximitySensors.h"
#include "util.h"

#include <QIODevice>
#include <QDebug>

ProximitySensors::ProximitySensors(QObject *parent)
    : QObject{parent},
    proximitySensor1_(0),
    proximitySensor2_(0),
    proximitySensor3_(0),
    proximitySensor4_(0)
{
}
