#ifndef TELEMETRY_H
#define TELEMETRY_H


#include <QObject>


class Telemetry : public QObject
{
    Q_OBJECT
public:
    explicit Telemetry(QObject *parent = nullptr);

    Q_PROPERTY(unsigned short gpsYear READ gpsYear WRITE setGpsYear NOTIFY gpsYearChanged FINAL)
    Q_PROPERTY(unsigned char gpsMonth READ gpsMonth WRITE setGpsMonth NOTIFY gpsMonthChanged FINAL)
    Q_PROPERTY(unsigned char gpsDay READ gpsDay WRITE setGpsDay NOTIFY gpsDayChanged FINAL)
    Q_PROPERTY(unsigned char gpsHour READ gpsHour WRITE setGpsHour NOTIFY gpsHourChanged FINAL)
    Q_PROPERTY(unsigned char gpsMinute READ gpsMinute WRITE setGpsMinute NOTIFY gpsMinuteChanged FINAL)
    Q_PROPERTY(unsigned char gpsSecond READ gpsSecond WRITE setGpsSecond NOTIFY gpsSecondChanged FINAL)
    Q_PROPERTY(unsigned char gpsValidityFlags READ gpsValidityFlags WRITE setGpsValidityFlags NOTIFY gpsValidityFlagsChanged FINAL)
    Q_PROPERTY(unsigned char gpsFixStatusFlags READ gpsFixStatusFlags WRITE setGpsFixStatusFlags NOTIFY gpsFixStatusFlagsChanged FINAL)
    Q_PROPERTY(unsigned char gpsAdditionalFlags READ gpsAdditionalFlags WRITE setGpsAdditionalFlags NOTIFY gpsAdditionalFlagsChanged FINAL)
    Q_PROPERTY(int gpsLongitude READ gpsLongitude WRITE setGpsLongitude NOTIFY gpsLongitudeChanged FINAL)
    Q_PROPERTY(int gpsLatitude READ gpsLatitude WRITE setGpsLatitude NOTIFY gpsLatitudeChanged FINAL)
    Q_PROPERTY(unsigned short mpuAccelerationX READ mpuAccelerationX WRITE setMpuAccelerationX NOTIFY mpuAccelerationXChanged FINAL)
    Q_PROPERTY(unsigned short mpuAccelerationY READ mpuAccelerationY WRITE setMpuAccelerationY NOTIFY mpuAccelerationYChanged FINAL)
    Q_PROPERTY(unsigned short mpuAccelerationZ READ mpuAccelerationZ WRITE setMpuAccelerationZ NOTIFY mpuAccelerationZChanged FINAL)
    Q_PROPERTY(unsigned short mpuRotationX READ mpuRotationX WRITE setMpuRotationX NOTIFY mpuRotationXChanged FINAL)
    Q_PROPERTY(unsigned short mpuRotationY READ mpuRotationY WRITE setMpuRotationY NOTIFY mpuRotationYChanged FINAL)
    Q_PROPERTY(unsigned short mpuRotationZ READ mpuRotationZ WRITE setMpuRotationZ NOTIFY mpuRotationZChanged FINAL)
    Q_PROPERTY(unsigned short mpuTemperature READ mpuTemperature WRITE setMpuTemperature NOTIFY mpuTemperatureChanged FINAL)

    Q_PROPERTY(QString byteStreamStr READ byteStreamStr NOTIFY byteStreamStrChanged FINAL)
    Q_PROPERTY(QString encodedByteStreamStr READ encodedByteStreamStr NOTIFY encodedByteStreamStrChanged FINAL)


    unsigned short gpsYear() const;
    unsigned char gpsMonth() const;
    unsigned char gpsDay() const;
    unsigned char gpsHour() const;
    unsigned char gpsMinute() const;
    unsigned char gpsSecond() const;
    unsigned char gpsValidityFlags() const;
    unsigned char gpsFixStatusFlags() const;
    unsigned char gpsAdditionalFlags() const;
    int gpsLongitude() const;
    int gpsLatitude() const;
    unsigned short mpuAccelerationX() const;
    unsigned short mpuAccelerationY() const;
    unsigned short mpuAccelerationZ() const;
    unsigned short mpuRotationX() const;
    unsigned short mpuRotationY() const;
    unsigned short mpuRotationZ() const;
    unsigned short mpuTemperature() const;

    QByteArray byteStream() const;
    QByteArray encodedByteStream() const;
    QString byteStreamStr() const;
    QString encodedByteStreamStr() const;


public slots:
    void setGpsYear(unsigned short year);
    void setGpsMonth(unsigned char month);
    void setGpsDay(unsigned char day);
    void setGpsHour(unsigned char hour);
    void setGpsMinute(unsigned char minute);
    void setGpsSecond(unsigned char second);
    void setGpsValidityFlags(unsigned char flags);
    void setGpsFixStatusFlags(unsigned char flags);
    void setGpsAdditionalFlags(unsigned char flags);
    void setGpsLongitude(int longitude);
    void setGpsLatitude(int latitude);
    void setMpuAccelerationX(unsigned short acceleration);
    void setMpuAccelerationY(unsigned short acceleration);
    void setMpuAccelerationZ(unsigned short acceleration);
    void setMpuRotationX(unsigned short rotation);
    void setMpuRotationY(unsigned short rotation);
    void setMpuRotationZ(unsigned short rotation);
    void setMpuTemperature(unsigned short temperature);


signals:
    void gpsYearChanged(unsigned short year);
    void gpsMonthChanged(unsigned char month);
    void gpsDayChanged(unsigned char day);
    void gpsHourChanged(unsigned char hour);
    void gpsMinuteChanged(unsigned char minute);
    void gpsSecondChanged(unsigned char second);
    void gpsValidityFlagsChanged(unsigned char flags);
    void gpsFixStatusFlagsChanged(unsigned char flags);
    void gpsAdditionalFlagsChanged(unsigned char flags);
    void gpsLongitudeChanged(int longitude);
    void gpsLatitudeChanged(int latitude);
    void mpuAccelerationXChanged(unsigned short acceleration);
    void mpuAccelerationYChanged(unsigned short acceleration);
    void mpuAccelerationZChanged(unsigned short acceleration);
    void mpuRotationXChanged(unsigned short rotation);
    void mpuRotationYChanged(unsigned short rotation);
    void mpuRotationZChanged(unsigned short rotation);
    void mpuTemperatureChanged(unsigned short temperature);

    void byteStreamStrChanged();
    void encodedByteStreamStrChanged();


private:
    unsigned short gpsYear_;
    unsigned char gpsMonth_;
    unsigned char gpsDay_;
    unsigned char gpsHour_;
    unsigned char gpsMinute_;
    unsigned char gpsSecond_;
    unsigned char gpsValidityFlags_;
    unsigned char gpsFixStatusFlags_;
    unsigned char gpsAdditionalFlags_;
    int gpsLongitude_;
    int gpsLatitude_;
    unsigned short mpuAccelerationX_;
    unsigned short mpuAccelerationY_;
    unsigned short mpuAccelerationZ_;
    unsigned short mpuRotationX_;
    unsigned short mpuRotationY_;
    unsigned short mpuRotationZ_;
    unsigned short mpuTemperature_;

    QByteArray byteStream_;
    QByteArray encodedByteStream_;

    void updateByteStream();
};


#endif // TELEMETRY_H
