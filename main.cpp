#include <QCoreApplication>
#include <QSerialPort>
#include <QTimer>

// Taken from the Embedded Repo
union DataUnion
{
    float floatData;
    short shortData[2];
    unsigned short uShortData[2];
    char charData[4];
    unsigned int uIntData;
};

// Taken from the Embedded Repo
void writeFloatIntoArray(unsigned char* data, int index, float value)
{
    qDebug() << "Data before: " << data;

    union DataUnion dataUnion;
    dataUnion.floatData = value;
    data[index++] = dataUnion.charData[0];
    data[index++] = dataUnion.charData[1];
    data[index++] = dataUnion.charData[2];
    data[index] = dataUnion.charData[3];

    qDebug() << "Data after: " << data;
}




void sendData(QSerialPort& serial)
{
    // QSerialPort requires const char * or QByteArray
    // Might cause issues with unsigned char data


    QByteArray keyMotorData;
    keyMotorData.append(1);
    keyMotorData.append(1);
    keyMotorData.append(0x45);

    /*unsigned char keyMotorData[47];
    for (int i = 0; i < 47; i++) {
        keyMotorData[i] = 0;
    }
    keyMotorData[0] = 1;                            // PackageID = 1
    keyMotorData[1] = 1; */                           // M0 Alive (0x01)

    // writeFloatIntoArray(keyMotorData, 2, 69);       // M0 Set Current = 69
    // writeFloatIntoArray(keyMotorData, 6, 69);       // M0 Set Velocity = 69
    // writeFloatIntoArray(keyMotorData, 10, 69);      // M0 Bus Current = 69
    // writeFloatIntoArray(keyMotorData, 14, 69);      // M0 Bus Voltage
    // writeFloatIntoArray(keyMotorData, 18, 69);      // M0 Vehicle Veolcity

    // keyMotorData[22] = 1;                           // M1 Alive
    // writeFloatIntoArray(keyMotorData, 23, 69);
    // writeFloatIntoArray(keyMotorData, 27, 69);
    // writeFloatIntoArray(keyMotorData, 31, 69);
    // writeFloatIntoArray(keyMotorData, 35, 69);
    // writeFloatIntoArray(keyMotorData, 39, 69);



    // Convert unsigned char array to QByteArray to send through serial port
    // QByteArray data = QByteArray((char*)keyMotorData, 47);



    // Write to serial port
    serial.write(keyMotorData);
    qDebug() << "Sent data: " << keyMotorData.toHex();
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSerialPort serial;
    serial.setPortName("/dev/ttys001");
    serial.setBaudRate(115200);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);

    if (serial.open(QIODevice::WriteOnly)) {
        qDebug() << "Serial port opened successfully.";

        // Use a QTimer to send data every 1 seconds
        QTimer timer;
        timer.setInterval(1000);  // 1 seconds interval
        QObject::connect(&timer, &QTimer::timeout, [&]() {
            sendData(serial);
        });
        timer.start();

        // Start the application event loop
        return a.exec();
    } else {
        qDebug() << "Failed to open serial port.";
        return 1;
    }
}

