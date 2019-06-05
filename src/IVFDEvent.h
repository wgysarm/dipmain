#ifndef IVFDEVENT_H
#define IVFDEVENT_H

#include <QEvent>

enum IVFDEVENTTYPE{
    E_CANCLERTSP = QEvent::User + 10,
    E_STARTRTSP,
    E_STOPRTSP,
    E_STARTALARM,
    E_STOPALARM,
    E_INTERRUPT,
    E_DEVICEREG,

};



class IVFDEvent : public QEvent
{
public:
    explicit IVFDEvent(int type);

public:
    inline int getId(){return m_id;}
    inline void setId(int id){m_id = id;}
    static int getType(IVFDEVENTTYPE eType);

private:
    int m_id;
};

#endif // IVFDHTTPSERVEREVENT_H
