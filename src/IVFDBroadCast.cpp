#include "IVFDBroadCast.h"
#include <QDebug>


IVFDBroadCast::IVFDBroadCast(QObject *parent) : QObject(parent)
{
    qDebug() << "--------IVFDBroadCast--------" << QThread::currentThread();
    m_tcpServer = new QTcpServer(this);
    m_tcpSocket = new QTcpSocket(this);
    m_udpSocket = new QUdpSocket(this);
    m_timer = new QTimer(this);
    m_broadCastThread = new QThread(this);
    m_udpPorts = 58897;
    m_tcpPorts = 58897;
    m_hostAddr = new QHostAddress(QHostAddress::LocalHost);

    IVFDBroadCastInit();

}

IVFDBroadCast::~IVFDBroadCast()
{

}

void IVFDBroadCast::IVFDBroadCastInit()
{
    if(m_broadCastThread == NULL || m_tcpServer == NULL ||
             m_udpSocket == NULL || m_tcpSocket == NULL ||
             m_hostAddr == NULL)
    {
        qDebug() << "IVFDBroadCastInit quit" ;
        return;
    }

    m_broadCastThread->start();
    this->moveToThread(m_broadCastThread);

    QObject::connect(this, SIGNAL(Sig_SendBroadCast(QString)), this, SLOT(SLOT_SendBroadCast(QString)));
    QObject::connect(this, SIGNAL(Sig_StartBroadCastThread()), this, SLOT(SLOT_StartBroadCastThread()));
    QObject::connect(this, SIGNAL(Sig_StopBroadCastThread()), this, SLOT(SLOT_StopBroadCastThread()));
    QObject::connect(m_broadCastThread, SIGNAL(finished()), this, SLOT(deleteLater()));

}


void IVFDBroadCast::setUdpPortn(quint32 portn)
{

    m_udpPorts = portn;
}

void IVFDBroadCast::setTcpPortn(quint32 portn)
{
    m_tcpPorts = portn;
}

quint16 IVFDBroadCast::getUdpPortn()
{
    return m_udpPorts;
}

quint16 IVFDBroadCast::getTcpPortn()
{
    return m_tcpPorts;
}


int IVFDBroadCast::SLOT_SendBroadCast(QString str)
{
    qDebug() << str << "----" << QThread::currentThread();
    QByteArray datagram;
    QString msg(QString("IVFDDevReg#%1#%2").arg(QString("192.168.120.166")).arg(QString("58897")));
    datagram.resize(msg.length());

    int len = m_udpSocket->writeDatagram(datagram, QHostAddress::Broadcast, datagram.size());
    if(len == msg.length())
    {
        qDebug() << "-------IVFDBroadCast--------SLOT_SendBroadCast success";
    }

    return 0;
}

int IVFDBroadCast::SLOT_StartBroadCastThread()
{
    m_timer->setInterval(3000);
    m_timer->start();
    qDebug() << "-------------IVFDBroadCast--------SLOT_StartBroadCastThread()---" << QThread::currentThread();
    QObject::connect(m_timer, SIGNAL(timeout()), this, SLOT(SLOT_DoTimer()));

    qDebug() << "-------------IVFDBroadCast--------SLOT_StartBroadCastThread()---" << m_udpPorts;
    if(m_udpSocket->bind(m_udpPorts))
    {
        QObject::connect(m_udpSocket, SIGNAL(connected()), this, SLOT(SLOT_UdpConnected()));
        QObject::connect(m_udpSocket, SIGNAL(readyRead()), this, SLOT(SLOT_UdpReadyRead()));
    }
    return 0;
}

void IVFDBroadCast::SLOT_StopBroadCastThread()
{
    m_broadCastThread->quit();
}


void IVFDBroadCast::SLOT_DoTimer()
{
    SLOT_SendBroadCast(((*m_hostAddr).toString()).append(":").append(QString::number(m_udpPorts)));

}

int IVFDBroadCast::setHostAddr(QHostAddress addr)
{

    *m_hostAddr = addr;
    return 0;
}

QHostAddress* IVFDBroadCast::getHostAddr(void)
{

    return m_hostAddr;
}

void IVFDBroadCast::SLOT_UdpConnected()
{
    qDebug() << "---------IVFDBroadCast--- udpconnected---" << QThread::currentThread();
    qDebug() << m_udpSocket->peerAddress() << "------" << m_udpSocket->peerPort();
}


void IVFDBroadCast::SLOT_UdpReadyRead()
{

    QHostAddress sender;
    quint16 senderPort;

    sender = m_udpSocket->peerAddress();
    senderPort = m_udpSocket->peerPort();

    while(m_udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(m_udpSocket->pendingDatagramSize());
        m_udpSocket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);
        QString recvmsg(datagram);

        qDebug() << recvmsg;
    }
    QString retmsg = QString("IVFDHost#%1#%2").arg(m_hostAddr->toString()).arg(QString::number(m_udpPorts));

    QByteArray datagram = retmsg.toLatin1();
    m_udpSocket->writeDatagram(datagram.data(), datagram.size(), sender, senderPort);

}
