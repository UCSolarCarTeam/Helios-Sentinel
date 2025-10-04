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


#define SUB_PROPERTY(type, name, parent, mask, offset)                                      \
Q_PROPERTY(type name READ get##name WRITE set##name NOTIFY name##Changed)                   \
public:                                                                                     \
    type get##name() const { return name##_; }                                              \
public Q_SLOTS:                                                                             \
    void set##name(type value) {                                                            \
        name##_ = value;                                                                    \
        if constexpr (std::is_same<type, float>::value){                                    \
            uint32_t ieee;                                                                  \
            std::memcpy(&ieee, &value, sizeof(float));                                      \
            parent##_ &= ~(mask << offset);                                                 \
            parent##_ |= (static_cast<decltype(parent##_)>(ieee) << offset);                \
        } else if constexpr (std::is_same<type, bool>::value){                              \
            if(value) parent##_ |= mask;                                                    \
            else parent##_ &= ~mask;                                                        \
        } else{                                                                             \
            parent##_ = (parent##_ & ~(mask << offset)) |                                   \
                        (static_cast<decltype(parent##_)>(value) << offset);                \
        }                                                                                   \
    }                                                                                       \
Q_SIGNALS:                                                                                  \
    void name##Changed(type newValue);                                                      \
private:                                                                                    \
    type name##_ = 0;


#endif // PROPERTYDEFINITIONS_H
