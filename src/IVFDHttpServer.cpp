#include "IVFDHttpServer.h"
#include "IvfdHttpC.h"
#include <QDebug>
#include <pthread.h>


extern pthread_t currentpthread ;


IVFDHttpServer::IVFDHttpServer(QObject *parent):QObject(parent), m_timeStamp(0)
{
    m_httpThread.start();

    this->moveToThread(&m_httpThread);
    m_event = NULL;
    m_pReceiver = NULL;


    QObject::connect(&m_httpThread, SIGNAL(finished()), this, SLOT(deleteLater()));
    QObject::connect(this, SIGNAL(SIG_UpdateTimeStamp(qlonglong)), this, SLOT(SLOT_UpdateTimeStamp(qlonglong)));
}

IVFDHttpServer::~IVFDHttpServer()
{

}

void IVFDHttpServer::SLOT_CreatNewHttpServer()
{
    qDebug() << "----IVFDHttpServer-----CreateNewhttpServer ----------" << QThread::currentThread();

    SLOT_StartHttpServer();
}


void IVFDHttpServer::SLOT_StartHttpServer()
{
//    HttpServer	*m_httpServer = new HttpServer(this);
    IvfdHttpC	*m_httpServer = new IvfdHttpC();
    qDebug() << "---IVFDHttpServer----Starthttpserver thread-------"<< QThread::currentThread();

    if(m_httpServer==NULL)
    {
        qDebug() << "absent of init http server";
    }

    quint32 portNumber = m_httpServer->m_httpserver->GetServerPortNum();
    m_httpServer->m_httpserver->SetServerPortNum(58891);
    portNumber = m_httpServer->m_httpserver->GetServerPortNum();

    qDebug() << "befor listen";
    if(!m_httpServer->m_httpserver->listen(portNumber))
    {
        qDebug() << QObject::tr("failed start server!");
        exit(-1);
    }
    qDebug() << QObject::tr("success start server!");

    QObject::connect(m_httpServer->m_httpserver, SIGNAL(SIG_OpenCPlayWindow()), this, SIGNAL(SIG_OpenCPlayWindow()), Qt::QueuedConnection);
    QObject::connect(m_httpServer->m_httpserver, SIGNAL(SIG_CmdFromBrowser(QString,QString)), this, SIGNAL(SIG_CmdFromBrowser(QString,QString)), Qt::QueuedConnection);
    QObject::connect(this, SIGNAL(SIG_CmdFromBrowser(QString,QString)), this, SLOT(SLOT_PrintCmd(QString,QString)));
    QObject::connect(this, SIGNAL(SIG_CmdAnswerFromTopUi(QByteArray)), m_httpServer->m_httpserver, SIGNAL(SIG_CmdAnswerFromTopUi(QByteArray)), Qt::QueuedConnection);
    QObject::connect(this, SIGNAL(SIG_UpdateTimeStamp(qlonglong)), m_httpServer->m_httpserver, SIGNAL(SIG_UpdateTimeStamp(qlonglong)), Qt::QueuedConnection);
}

void IVFDHttpServer::SLOT_PrintCmd(QString module, QString cmd)
{
    qDebug() << "In IVFDHttpServer-----" << QThread::currentThread() << "----" <<module << "----" << cmd;
    m_event = new IVFDEvent(IVFDEvent::getType(E_CANCLERTSP));
//    QCoreApplication::postEvent(this, m_event);
    QCoreApplication::postEvent(this,m_event);
//    if(m_pReceiver != NULL)
//    {
//        delete m_pReceiver;
//        m_pReceiver = NULL;
//    }
//    pthread_cancel(currentpthread);
    qDebug() << "postEvernt in IVFDHttpServer----------" << currentpthread;
}


bool IVFDHttpServer::event(QEvent *e)
{

    if(e->type() == static_cast<QEvent::Type>(IVFDEvent::getType(E_CANCLERTSP)))
    {
        IVFDEvent *m_e = (IVFDEvent *)e;
        qDebug() << "ivfdhttpEvent dealed! ------" << m_e->getId();
        return true;
    }
    return QObject::event(e);

}

void IVFDHttpServer::SLOT_UpdateTimeStamp(qlonglong timestamp)
{

    m_timeStamp = timestamp;
}

