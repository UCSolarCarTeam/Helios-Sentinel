#ifndef PROXIMITYSENSORS_H
#define PROXIMITYSENSORS_H

#include <QObject>
#include <QCanBus>
#include <QTimer>
#include <QDebug>

class ProximitySensors : public QObject{
    Q_OBJECT
    Q_PROPERTY(unsigned short proximitySensor1 READ getProximitySensor1 WRITE setProximitySensor1 NOTIFY proximitySensor1Changed)
    Q_PROPERTY(unsigned short proximitySensor2 READ getProximitySensor2 WRITE setProximitySensor2 NOTIFY proximitySensor2Changed)
    Q_PROPERTY(unsigned short proximitySensor3 READ getProximitySensor3 WRITE setProximitySensor3 NOTIFY proximitySensor3Changed)
    Q_PROPERTY(unsigned short proximitySensor4 READ getProximitySensor4 WRITE setProximitySensor4 NOTIFY proximitySensor4Changed)

public:
    ProximitySensors(QCanBusDevice* canDevice) : canDevice_(canDevice) {
        timerSensor1_ = new QTimer(this);
        timerSensor2_ = new QTimer(this);
        timerSensor3_ = new QTimer(this);
        timerSensor4_ = new QTimer(this);

        // Connect timers to their respective sending methods
        connect(timerSensor1_, &QTimer::timeout, this, &ProximitySensors::sendSensor1Message);
        connect(timerSensor2_, &QTimer::timeout, this, &ProximitySensors::sendSensor2Message);
        connect(timerSensor3_, &QTimer::timeout, this, &ProximitySensors::sendSensor3Message);
        connect(timerSensor4_, &QTimer::timeout, this, &ProximitySensors::sendSensor4Message);
    };

    
    unsigned short getProximitySensor1() const { return proximitySensor1_; }

    unsigned short getProximitySensor2() const { return proximitySensor2_; }

    unsigned short getProximitySensor3() const { return proximitySensor3_; }

    unsigned short getProximitySensor4() const { return proximitySensor4_; }

    void startSendingAtFrequency(int intervalMs) {
        // Start timers for each sensor at the specified interval
        timerSensor1_->start(intervalMs);
        timerSensor2_->start(intervalMs);
        timerSensor3_->start(intervalMs);
        timerSensor4_->start(intervalMs);
        qDebug() << "Started sending CAN messages at" << intervalMs << "ms intervals.";
    }

    void stopSending() {
        // Stop all timers
        timerSensor1_->stop();
        timerSensor2_->stop();
        timerSensor3_->stop();
        timerSensor4_->stop();
        qDebug() << "Stopped sending CAN messages.";
    }

    void sendCanMessage(unsigned int frameId, unsigned short sensorValue) {
        if (canDevice_) {
            QCanBusFrame frame;
            frame.setFrameId(frameId);

            // Create payload in big-endian format
            QByteArray payload;
            payload.append(static_cast<char>((sensorValue >> 8) & 0xFF)); // High byte first
            payload.append(static_cast<char>(sensorValue & 0xFF));        // Low byte second

            frame.setPayload(payload);

            if (canDevice_->writeFrame(frame)) {
                qDebug() << "Frame sent successfully with ID:" << frameId << "Payload:" << payload.toHex();
            } else {
                qDebug() << "Failed to send frame with ID:" << frameId;
            }
        } else {
            qDebug() << "CAN device is not initialized.";
        }
    }

public slots:

    void setProximitySensor1(unsigned short value) { 
        if (proximitySensor1_ != value) {
            proximitySensor1_ = value;
            emit proximitySensor1Changed();
        }
    }

    void setProximitySensor2(unsigned short value) {
        if (proximitySensor2_ != value) {
            proximitySensor2_ = value;
            emit proximitySensor2Changed();
        }
    }

    void setProximitySensor3(unsigned short value) {
        if (proximitySensor3_ != value) {
            proximitySensor3_ = value;
            emit proximitySensor3Changed();
        }
    }

    void setProximitySensor4(unsigned short value) {
        if (proximitySensor4_ != value) {
            proximitySensor4_ = value;
            emit proximitySensor4Changed();
        }
    }
    
    void sendSensor1Message() {
        sendCanMessage(0x700, proximitySensor1_);
    }

    void sendSensor2Message() {
        sendCanMessage(0x701, proximitySensor2_);
    }

    void sendSensor3Message() {
        sendCanMessage(0x702, proximitySensor3_);
    }

    void sendSensor4Message() {
        sendCanMessage(0x703, proximitySensor4_);
    }

signals:
    void proximitySensor1Changed();
    void proximitySensor2Changed();
    void proximitySensor3Changed();
    void proximitySensor4Changed();


private:
    unsigned short proximitySensor1_=1;
    unsigned short proximitySensor2_=2;
    unsigned short proximitySensor3_=3;
    unsigned short proximitySensor4_=4;

    QCanBusDevice* canDevice_;

    QTimer *timerSensor1_;
    QTimer *timerSensor2_;
    QTimer *timerSensor3_;
    QTimer *timerSensor4_;
};

#endif // PROXIMITYSENSORS_H
