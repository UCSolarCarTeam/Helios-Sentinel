#include <QDebug>
#include <QThread>
#include "setting.h"

Setting::Setting(QObject *parent)
    : QObject{parent}, socatProcess(new QProcess(this)), forwarder_(new SerialPortForwarder(""))
{
     // Socat command for opening two virtual serial ports
    QString socatPath;

#ifdef Q_OS_MAC
    socatPath = "/opt/homebrew/bin/socat";  // Default for macOS
#elif defined(Q_OS_LINUX)
    socatPath = "/usr/bin/socat";  // Default for Linux
#endif
    socatProcess->setProgram(socatPath);
    socatProcess->setArguments({
         "-d", "-d",
         "pty,raw,echo=0",
         "pty,raw,echo=0"
    });
    socatProcess->setProcessChannelMode(QProcess::MergedChannels);

    QObject::connect(socatProcess, &QProcess::readyReadStandardOutput, this, &Setting::handleProcessOutput);
    QObject::connect(socatProcess, &QProcess::errorOccurred, this, &Setting::handleProcessError);
}

bool Setting::connectSerialPort() const { return connectSerialPort_; }

QString Setting::secondPortName() const { return secondPortName_; }

SerialPortForwarder* Setting::getForwarder() const { return forwarder_; }

void Setting::setConnectSerialPort(bool alive)
{
    if (alive) {
        socatProcess->start();

        if (socatProcess->waitForStarted()) {
            connectSerialPort_ = alive;

        } else {
            qWarning() << "Failed to start socat process.";
        }
    } else {
        // Kill process to close virtual serial ports
        if (socatProcess->state() == QProcess::Running) {
            socatProcess->kill();
            socatProcess->waitForFinished();
            qDebug() << "Socat process stopped.";
            delete forwarder_;
            forwarder_ = new SerialPortForwarder("");
            connectSerialPort_ = alive;
        }
    }
}

void Setting::setSecondPortName(QString name)
{
    secondPortName_ = name;
    emit secondPortNameChanged(name);
}


void Setting::handleProcessOutput() {
    // Append process output to a buffer to ensure the entire output is collected
    processOutputBuffer_.append(QString::fromUtf8(socatProcess->readAllStandardOutput()));

    // Regex to match serial port paths like /dev/pts/3 and /dev/ttys011
    QRegularExpression regex("(/dev/(pts/|ttys)[A-Za-z0-9]+)");
    QRegularExpressionMatchIterator matches = regex.globalMatch(processOutputBuffer_);

    QStringList serialPorts;
    while (matches.hasNext()) {
        QRegularExpressionMatch match = matches.next();
        if (match.hasMatch()) {
            serialPorts.append(match.captured(1));
        }
    }

    if (serialPorts.size() >= 2) {
        delete forwarder_;
        forwarder_ = new SerialPortForwarder(serialPorts.at(0));
        setSecondPortName(serialPorts.at(1));
    }
}

void Setting::handleProcessError(QProcess::ProcessError error) {
    qWarning() << "Socat process error:" << error;
    qWarning() << "Process error string:" << socatProcess->errorString();
    qWarning() << "Failed command:" << socatProcess->program() << socatProcess->arguments();
}
