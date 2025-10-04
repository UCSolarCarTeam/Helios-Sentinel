#ifndef IPACKET_H
#define IPACKET_H

#include <QObject>
#include <QCanBusDevice>
#include <QDebug>
#include <QTimer>

class IPacket : public QObject {
public:
    explicit IPacket(QCanBusDevice* canDevice) : canDevice_(canDevice) {}

    void initAndStartTimers(){
        for(const auto& [id, data] : timerData_) {
            QTimer* timer = new QTimer(this);
            connect(timer, &QTimer::timeout, data.sender);
            timer->start(data.interval);
            timers_.push_back(timer);
        }
    }

    template <typename T>
    void sendCanMessage(unsigned int id, T data){
        static_assert(std::is_arithmetic<T>::value, "Data must be an arithmetic type");

        if(canDevice_){
            QCanBusFrame frame;
            frame.setFrameId(id);

            QByteArray payload;
            // Organize payloads in little endian
            for(int i = 0; i < sizeof(T); ++i){
                payload.append(static_cast<char>((data >> (8 * i)) & 0xFF));
            }

            frame.setPayload(payload);

            if(!canDevice_->writeFrame(frame)) qDebug() << "failed write";

        }else {
            qDebug() << "No Can (do)";
        }
    }

private:
    struct intervalData_ {
        int interval;
        std::function<void()> sender;
    };

    std::vector<QTimer*> timers_;

    QCanBusDevice* canDevice_;

protected:
    std::map<unsigned int, intervalData_> timerData_;
};

#endif // IPACKET_H
