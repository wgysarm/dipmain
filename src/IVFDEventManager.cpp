
#include "IVFDEventManager.h"
#include "IVFDSeqLinkList.h"
#include "IVFDSeqQueue.h"
#include "IVFDUiDesign.h"
#include <QDebug>

static IVFDUiDesign *pFather;

IVFDEventManager::IVFDEventManager(QObject *parent) : QObject(parent)
{
    InitThis();
}
IVFDEventManager::~IVFDEventManager()
{

}

void IVFDEventManager::InitThis()
{

    QObject::connect(&m_thread, SIGNAL(finished()), this, SLOT(deleteLater()));
    QObject::connect(this, SIGNAL(SIG_ThreadQuit()), &m_thread, SLOT(quit()));
    QObject::connect(this, SIGNAL(SIG_DoEventManager()), this, SLOT(SLOT_DoEventManager()));
    QObject::connect(this, SIGNAL(SIG_ThreadStart()), this, SLOT(SLOT_ThreadStart()));
}

int IVFDEventManager::SLOT_ThreadStart(){

    m_thread.start();
    this->moveToThread(&m_thread);
}

int IVFDEventManager::SLOT_DoEventManager()
{
    SeqQueue *queueevent = (SeqQueue *)(IVFDUiDesign::m_queueevent);

    while(1){
        TSeqLinkList *pqueuelist = (TSeqLinkList *)queueevent;
        //if queue is empty please wait for 50ms;
        if(pqueuelist->length == 0)
        {
        }
        int len = SeqQueue_Length(queueevent);
        ALARMEVENT *event = (ALARMEVENT *)SeqQueue_Retrieve(queueevent);
        if(event!=NULL && event->alamdatainfo != NULL){
            ALARMDATAINFO *p_alarmdatainfo = (ALARMDATAINFO *)event->alamdatainfo;
            if(p_alarmdatainfo != NULL){
                qDebug() << "3 IVFDEventManager::SLOT_DoEventManager:" << event->status << " " << event->alamdatainfo->alarmTime << " " << event->alamdatainfo->alarmType;
                QByteArray ba_sendtoclient;
                ba_sendtoclient.resize(sizeof(*p_alarmdatainfo));
                memcpy(ba_sendtoclient.data(), p_alarmdatainfo, sizeof(*p_alarmdatainfo));
                event->status = 0;//remark the event item of the everntarray unused;
                emit SIG_SendToClient(ba_sendtoclient, ba_sendtoclient);
            }
        }else{
        }

        QThread::msleep(100);
    }

}

