#ifndef PROXIMITYSENSORS_H
#define PROXIMITYSENSORS_H

class ProximitySensors : public QObject
{
    Q_OBJECT
public:
    explicit ProximitySensors(QObject *parent = nullptr);

    Q_PROPERTY(unsigned short proximitySensor1 READ proximitySensor1 WRITE setProximitySensor1 NOTIFY proximitySensor1Changed FINAL)
    Q_PROPERTY(unsigned short proximitySensor2 READ proximitySensor2 WRITE setProximitySensor2 NOTIFY proximitySensor2Changed FINAL)
    Q_PROPERTY(unsigned short proximitySensor3 READ proximitySensor3 WRITE setProximitySensor3 NOTIFY proximitySensor3Changed FINAL)
    Q_PROPERTY(unsigned short proximitySensor4 READ proximitySensor4 WRITE setProximitySensor4 NOTIFY proximitySensor4Changed FINAL)


    unsigned short proximitySensor1() const;
    unsigned short proximitySensor2() const;
    unsigned short proximitySensor3() const;
    unsigned short proximitySensor4() const;
    QByteArray byteStream() const;
    QByteArray encodedByteStream() const;
    QString byteStreamStr() const;
    QString encodedByteStreamStr() const;


public slots:
    void setProximitySensor1(unsigned short value);
    void setProximitySensor2(unsigned short value);
    void setProximitySensor3(unsigned short value);
    void setProximitySensor4(unsigned short value);


signals:
    void proximitySensor1Changed(unsigned short value);
    void proximitySensor2Changed(unsigned short value);
    void proximitySensor3Changed(unsigned short value);
    void proximitySensor4Changed(unsigned short value);

    void byteStreamStrChanged();
    void encodedByteStreamStrChanged();


private:
    unsigned short proximitySensor1_;
    unsigned short proximitySensor2_;
    unsigned short proximitySensor3_;
    unsigned short proximitySensor4_;
    QByteArray byteStream_;
    QByteArray encodedByteStream_;

    void updateByteStream();
};

#endif // PROXIMITYSENSORS_H
