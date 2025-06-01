#ifndef PROPERTYDEFINITIONS_H
#define PROPERTYDEFINITIONS_H

#define DEFINE_PROPERTY(type, name, id)                                     \
Q_PROPERTY(type name READ get##name WRITE set##name NOTIFY name##Changed)   \
public:                                                                     \
    type get##name() const { return name##_; }                              \
public Q_SLOTS:                                                             \
    void set##name(type value){                                             \
        name##_ = value;                                                    \
    }                                                                       \
    void send##name##Message(){                                             \
        sendCanMessage(id, name##_);                                        \
    }                                                                       \
Q_SIGNALS:                                                                  \
    void name##Changed(type newValue);                                      \
private:                                                                    \
    type name##_ = 0;

#endif // PROPERTYDEFINITIONS_H
