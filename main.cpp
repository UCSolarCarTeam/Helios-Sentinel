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


    // QByteArray keyMotorData;
    // keyMotorData.append(1);
    // keyMotorData.append(1);
    // keyMotorData.append(0x45);

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

    QByteArray keyMotorData("\x2F\x01\x01\x04\x05\x06\x07\x08\x08\x08"
                            "\x0B\x0C\x0D\x0E\x0F\x10\x11\x12\x13\x14"
                            "\x15\x16\x01\x18\x19\x1A\x1B\x1C\x1D\x1E"
                            "\x1F\x20\x21\x22\x23\x24\x25\x26\x27\x28"
                            "\x29\x29\x2A\x2B\xB3\xD9\x00", 47);

    QByteArray motor0Details("\x45\x02\x01\x04\x05\x06\x07\x08\x08\x08"
                             "\x0B\x0C\x0D\x0E\x0F\x10\x11\x12\x13\x14"
                             "\x15\x16\x01\x18\x19\x1A\x1B\x1C\x1D\x1E"
                             "\x1F\x20\x21\x22\x23\x24\x25\x26\x27\x28"
                             "\x29\x29\x2A\x2B\xB3\xD9\x25\x26\x27\x28"
                             "\x0B\x0C\x0D\x0E\x0F\x10\x11\x12\x13\x14"
                             "\x15\x16\x01\x18\x19\x1A\x1B\x1C\x00", 69);

    QByteArray motor1Details("\x45\x03\x01\x04\x05\x06\x07\x08\x08\x08"
                             "\x0B\x0C\x0D\x0E\x0F\x10\x11\x12\x13\x14"
                             "\x15\x16\x01\x18\x19\x1A\x1B\x1C\x1D\x1E"
                             "\x1F\x20\x21\x22\x23\x24\x25\x26\x27\x28"
                             "\x29\x29\x2A\x2B\xB3\xD9\x25\x26\x27\x28"
                             "\x0B\x0C\x0D\x0E\x0F\x10\x11\x12\x13\x14"
                             "\x15\x16\x01\x18\x19\x1A\x1B\x1C\x00", 69);

    QByteArray driverControls("\x0D\x04\x01\x04\x05\x06\x07\x08\x08\x08"
                              "\x0B\x0C\x00", 13);

    QByteArray motorFaults("\x0D\x05\x01\x04\x05\x06\x07\x08\x08\x08"
                           "\x0B\x0C\x00", 13);

    QByteArray batteryFaults("\x0D\x06\x01\x04\x05\x06\x07\x08\x08\x00", 10);

    QByteArray battery("\x34\x07\x01\x04\x05\x06\x07\x08\x08\x08"
                       "\x0B\x0C\x0D\x0E\x0F\x10\x11\x12\x13\x14"
                       "\x15\x16\x01\x18\x19\x1A\x1B\x1C\x1D\x1E"
                       "\x1F\x20\x21\x22\x23\x24\x25\x26\x27\x28"
                       "\x29\x29\x2A\x2B\xB3\xD9\x25\x26\x27\x28"
                       "\x0B\x00", 52);

    QByteArray MPPT0("\x0E\x09\x00\x04\x05\x06\x07\x08\x08\x08"
                     "\x0B\x0C\x0D\x00", 14);
    QByteArray MPPT1("\x0E\x09\x01\x04\x05\x06\x07\x08\x08\x08"
                     "\x0B\x0C\x0D\x00", 14);
    QByteArray MPPT2("\x0E\x09\x02\x04\x05\x06\x07\x08\x08\x08"
                     "\x0B\x0C\x0D\x00", 14);
    QByteArray MPPT3("\x0E\x09\x03\x04\x05\x06\x07\x08\x08\x08"
                     "\x0B\x0C\x0D\x00", 14);

    QByteArray lights("\x07\x0A\x03\x04\x05\x06\x00", 7);

    QByteArray auxBMS("\x0F\x0B\x01\x04\x05\x06\x07\x08\x08\x08"
                      "\x0B\x0C\x0D\x01\x00", 15);

    QByteArray package1 = keyMotorData;
    package1.append(motor0Details);
    package1.append(motor1Details);
    package1.append(driverControls);
    package1.append(motorFaults);
    package1.append(batteryFaults);
    package1.append(battery);
    package1.append(MPPT0);
    package1.append(MPPT1);
    package1.append(MPPT2);
    package1.append(MPPT3);
    package1.append(lights);
    package1.append(auxBMS);

    // Write to serial port
    serial.write(package1);
    qDebug() << "Sent data: " << package1;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSerialPort serial;
    serial.setPortName("/dev/ttys006");
    serial.setBaudRate(115200);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);

    if (serial.open(QIODevice::WriteOnly)) {
        qDebug() << "Serial port opened successfully.";

        // Use a QTimer to send data every 1 seconds
        QTimer timer;
        timer.setInterval(200);  // 1 seconds interval
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

