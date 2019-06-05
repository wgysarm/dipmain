#include "IVFDTcpServerHB.h"


IVFDTcpServerHB::IVFDTcpServerHB(QObject *parent)
    : QTcpServer(parent)
{
    m_checkClientTimer = new QTimer;
    connect(m_checkClientTimer, SIGNAL(timeout()), this, SLOT(sltCheckClientTimer()));
}

IVFDTcpServerHB::~IVFDTcpServerHB()
{

}

bool IVFDTcpServerHB::startServer(int port)
{
    bool ret = true;
    ret = this->listen(QHostAddress::Any, port);

    if(ret)
    {
        m_checkClientTimer->start(1000);
    }

    return ret;
}

void IVFDTcpServerHB::incomingConnection(qintptr handle)
{
    IVFDTcpServerWorker* worker = new IVFDTcpServerWorker(handle);
    QThread* thread = new QThread(worker);
    worker->moveToThread(thread);

    //connect(thread, SIGNAL(finished()), worker, SLOT(deleteLater()));
    connect(this, SIGNAL(SIG_NewClient(int)), worker, SLOT(SLOT_NewClient(int)));
    connect(this, SIGNAL(SIG_SendData(int,QString)), worker, SLOT(SLOT_SendData(int,QString)));
    connect(this, SIGNAL(SIG_DisconnectClient(int)), worker, SLOT(SLOT_DisConnectClient(int)));
    connect(worker, SIGNAL(SIG_ClientDisconnect(int)), this, SLOT(SLOT_ClientDisconnect(int)));
    connect(worker, SIGNAL(SIG_ClientHeartStatus(int, int)), this, SLOT(SLOT_ClientHeartStatus(int, int)));
    connect(worker, SIGNAL(SIG_RevMessage(int,int,QString)), this, SLOT(SLOT_RecMessage(int, int, QString)));
    thread->start();

    m_mapThread[handle] = thread;
    m_mapClientHeart[handle] = 0;
    emit SIG_NewClient(handle);
}

void IVFDTcpServerHB::SLOT_CheckClientTimer()
{
    if(m_mapThread.size() < 0)
    {
        return;
    }
    qDebug() << QString(tr("check client,release all resource!"));

    int nHeartOutTimes = 0;
    QMap<int, int>::iterator i;
    for(i = m_mapClientHeart.begin(); i != m_mapClientHeart.end();)
    {
        nHeartOutTimes = i.value();
        nHeartOutTimes++;
        i.value() = nHeartOutTimes;
        if(nHeartOutTimes > HTCPCLIENT_HEART_TIMEOUT_COUNT)
        {
            SLOT_ClientDisconnect(i.key());
            m_mapClientHeart.erase(i++);
        }
        else
        {
            i++;
        }
    }
}

void IVFDTcpServerHB::SLOT_ClientHeartStatus(int id, int nHeartOutTimes)
{
    QMap<int, int>::iterator i;
    for(i = m_mapClientHeart.begin(); i != m_mapClientHeart.end(); ++i)
    {
        if(i.key() == id)
        {
            i.value() = nHeartOutTimes;
            break;
        }
    }
}

void IVFDTcpServerHB::SLOT_ClientDisconnect(int id)
{
    emit SIG_DisconnectClient(id);

    QMap<int, QThread*>::iterator k = m_mapThread.find(id);
    if (k != m_mapThread.end())
    {
        QThread *thread = k.value();
        if (thread)
        {
            if (thread->isRunning())
            {
                thread->quit();
                thread->wait();
            }
        }
        m_mapThread.erase(k);
    }
    qDebug() << QString(tr("close thread,release resource!"));
}

void IVFDTcpServerHB::SLOT_RecMessage(int id, int cmdID, QString data)
{
    //某个客户端，某条命令及数据内容，进一步解析或于UI的交互在这个函数中进行；
    //其它接收到命令后的耗时操作，全放线程中进行；
}
