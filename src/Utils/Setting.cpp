#include "Setting.h"

Setting::Setting(QObject *parent)
    : QObject{parent}
{
}
bool Setting::isElysia() const {return isElysia_;}

void Setting::setIsElysia(bool value) {
    isElysia_ = value;
    emit isElysiaChanged(isElysia_);
}
