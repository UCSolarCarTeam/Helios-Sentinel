#ifndef PROPERTYDEFINITION_H
#define PROPERTYDEFINITION_H
#include <QObject>

/**
 *  Defines Packet Attribute Properties for linking to qml
 *  Creates Q_PROPERY with getter, setter, and signal, as well as the
 *  private class var (type name_)
 *
 *  Defines:
 *  public getter Name()
 *  public setter setName(type)
 *  private var Name_
 *  public slot: void setName(type i)
 *  signals: void NameChanged(type i
 *
 *  Note that name should be capilized in current state to follow
 *  best naming conventions
*/
#define DEFINE_PROPERTY(type, name) \
Q_SIGNALS:\
    void name##Changed(type on);\
private:\
    type name##_; \
\
public Q_SLOTS: \
    void set##name(type on); \
public: \
type name() const; \
Q_PROPERTY(bool name READ name WRITE set##name NOTIFY name##Changed); \




#endif // PROPERTYDEFINITION_H
