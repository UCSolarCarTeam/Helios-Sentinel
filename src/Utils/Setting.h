#ifndef SETTING_H
#define SETTING_H

#include <QObject>

class Setting : public QObject
{
    Q_OBJECT
public:
    explicit Setting(QObject *parent = nullptr);
    Q_PROPERTY(bool isElysia READ issElysia NOTIFY isElysiaChanged FINAL)

    bool isElysia() const;

signals:
    void isElysiaChanged(bool on);

public slots:
    void setIsElysia(bool value);

private:
    bool isElysia_ = false;
};

#endif // SETTING_H
