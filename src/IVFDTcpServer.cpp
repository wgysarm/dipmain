#include "IVFDTcpServer.h"
#include "IVFDUiDesign.h"

//static IVFDUiDesign *pFather;

IVFDTcpServer::IVFDTcpServer(QObject *parent) : QObject(parent)
{
    InitThis();
}

IVFDTcpServer::~IVFDTcpServer()
{

}


void IVFDTcpServer::SLOT_StartTcpServerThread()
{
    m_tcpserverThread.start();
    moveToThread(&m_tcpserverThread);

}

void IVFDTcpServer::SLOT_StopTcpServerThread()
{

    m_tcpserverThread.quit();
}

void IVFDTcpServer::SLOT_HasNewConnection()
{
    while(m_tcpserver->hasPendingConnections())
    {
        m_tcpsocket = m_tcpserver->nextPendingConnection();
        QObject::connect(m_tcpsocket, SIGNAL(readyRead()), this, SLOT(SLOT_ReadyReadAll()));
        QObject::connect(m_tcpsocket, SIGNAL(disconnected()), m_tcpsocket, SLOT(deleteLater()));
        QObject::connect(m_tcpsocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(SLOT_SocketError(QAbstractSocket::SocketError)));

    }
}

void IVFDTcpServer::SLOT_ReadyReadAll()
{
    m_ba = m_tcpsocket->readAll();
    XReadAll(m_ba);
}

void IVFDTcpServer::SLOT_SocketError(QAbstractSocket::SocketError err)
{
    qDebug() << "3 IVFDTcpServer::SLOT_SocketError:" << err;
}

void IVFDTcpServer::SLOT_WriteToTcpSocket(QByteArray ba)
{
    m_tcpsocket->write(ba);
//    m_tcpsocket->flush();

}


void IVFDTcpServer::XReadAll(QByteArray ba)
{
    QString tosend("show me the meaning of being lonely!");
    emit SIG_TellTop(ba);
}

void IVFDTcpServer::InitThis()
{
    m_hostAddr = QHostAddress(QHostAddress::Any);
    m_port = 58892;
    m_tcpserver = new QTcpServer(this);
    m_tcpsocket = new QTcpSocket(this);
    m_tcpserver->listen(m_hostAddr, m_port);


//    pFather = (IVFDUiDesign *)this->parent();


    QObject::connect(&m_tcpserverThread, SIGNAL(finished()), this, SLOT(deleteLater()));
    QObject::connect(m_tcpserver, SIGNAL(newConnection()), this, SLOT(SLOT_HasNewConnection()));

    QObject::connect(this, SIGNAL(SIG_StartTcpServerThread()), this, SLOT(SLOT_StartTcpServerThread()));
    QObject::connect(this, SIGNAL(SIG_StopTcpServerThread()), this, SLOT(SLOT_StopTcpServerThread()));
    QObject::connect(this, SIGNAL(SIG_WriteToTcpSocket(QByteArray)), this, SLOT(SLOT_WriteToTcpSocket(QByteArray)));
    QObject::connect(this, SIGNAL(SIG_WriteFileToSocket(QString)), this, SLOT(SLOT_WriteFileToSocket(QString)));
}

void IVFDTcpServer::SLOT_WriteFileToSocket(QString filename)
{

    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly));
    {
        qDebug() << "open file failed !";
        return;
    }

    QString http = "HTTP/1.1 200 OK\r\n";
    http += "Server: nginx\r\n";
    http += "Content-Type: application/octet-stream=utf-8\r\n";
    http += "Connection: keep-alive\r\n";
    http += QString("Content-Length: %1\r\n\r\n").arg(QString::number(file.size()));

    if(m_tcpsocket != NULL)
    {
        QByteArray headData , data;
        headData.append(http);
        m_tcpsocket->write(headData);

        while(!file.atEnd())
        {
            data = file.read(10240);
            m_tcpsocket->write(data);
            m_tcpsocket->flush();
        }
        qDebug() << "3 Send file success! " ;
    }
}

