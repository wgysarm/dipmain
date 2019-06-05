#include "IVFDEvent.h"


static const int et1 = QEvent::registerEventType(E_CANCLERTSP);
static const int et2 = QEvent::registerEventType(E_STARTRTSP);
static const int et3 = QEvent::registerEventType(E_STOPRTSP);
static const int et4 = QEvent::registerEventType(E_STARTALARM);
static const int et5 = QEvent::registerEventType(E_STOPALARM);
static const int et6 = QEvent::registerEventType(E_DEVICEREG);
static const int et7 = QEvent::registerEventType(E_INTERRUPT);

IVFDEvent::IVFDEvent(int type)
    : QEvent(static_cast<QEvent::Type>(type)),m_id(0)
{


}



int IVFDEvent::getType(IVFDEVENTTYPE eType)
{
    int iRet = et1;
    switch(eType)
    {
    case E_CANCLERTSP:
            iRet = et1;
        break;
    case E_STARTRTSP:
            iRet = et2;
        break;
    case E_STOPRTSP:
            iRet = et3;
        break;
    case E_STARTALARM:
            iRet = et4;
        break;
    case E_STOPALARM:
            iRet = et5;
        break;
    case E_DEVICEREG:
            iRet = et6;
        break;
    case E_INTERRUPT:
            iRet = et7;
        break;

    }
    return iRet;

}
