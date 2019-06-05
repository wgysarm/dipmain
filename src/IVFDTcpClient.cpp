#include "IVFDTcpClient.h"

IVFDTcpClient::IVFDTcpClient(QObject *parent, quint16 portn, QString hostAddr) : QObject(parent)
{
    qDebug() << "3 IVFDTcpClient::IVFDTcpClient IVFDTcpClient create";
    m_portn = portn;
    m_tcpAddress = QHostAddress(hostAddr);
    m_tcpClientSocket = new QTcpSocket(this);
    m_socketisconnectted = false;
    ///* * //create the thread;
    m_threadClient = new QThread(this);
    if(m_threadClient != NULL)
    {
        m_threadClient->start();
    }
    this->moveToThread(m_threadClient);

    QObject::connect(m_threadClient, SIGNAL(finished()), this, SLOT(deleteLater()));
    QObject::connect(this, SIGNAL(SIG_StopClientThread()), m_threadClient, SLOT(quit()));
    //*/
    QObject::connect(this, SIGNAL(SIG_SendMsgToServer(QByteArray, QByteArray)), this, SLOT(SLOT_SendMsgToServer(QByteArray, QByteArray)));//from outside signal

    QObject::connect(m_tcpClientSocket, SIGNAL(readyRead()), this, SLOT(SLOT_ReadMsg()));
    QObject::connect(m_tcpClientSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(SLOT_DisplayError(QAbstractSocket::SocketError)));
    QObject::connect(m_tcpClientSocket, SIGNAL(connected()), this, SLOT(SLOT_ClientConnected()));
    QObject::connect(this, SIGNAL(SIG_ConnectToHost(QString, quint16)), this, SLOT(SLOT_NewConnect(QString, quint16)));
    QObject::connect(this, SIGNAL(SIG_TcpSocketSendMsg(QByteArray,QByteArray)), this, SLOT(SLOT_TcpSocketSendMsg(QByteArray,QByteArray)));
}

void IVFDTcpClient::SLOT_ReadMsg()
{
    QByteArray ba;
    while(m_tcpClientSocket->bytesAvailable())
    {
        ba = m_tcpClientSocket->readAll();
    }
    m_msgFromServer = QString(ba);
    qDebug() <<  "3 IVFDTcpClient::SLOT_ReadMsg():" << m_msgFromServer;
    qDebug() << "3 IVFDTcpClient::SLOT_ReadMsg():connect status is :" << m_socketisconnectted << "current thread:" << QThread::currentThread();
}

void IVFDTcpClient::SLOT_NewConnect(QString addr, quint16 portn)
{
    qDebug() << "3 IVFDTcpClient::SLOT_NewConnect():" << addr << "@" << portn;
    m_blockSize = 0;
    m_tcpClientSocket->abort();
    m_tcpClientSocket->connectToHost(QHostAddress(addr), portn);
}
void IVFDTcpClient::SLOT_ClientConnected()
{
    m_socketisconnectted = true;

}

void IVFDTcpClient::SLOT_DisplayError(QAbstractSocket::SocketError)
{
    qDebug() << "3 In IVFDTcpClient displayError: " << m_tcpClientSocket->errorString();
}

void IVFDTcpClient::SLOT_ClearClient()
{

}

void IVFDTcpClient::SLOT_HeartBeat()
{

}

void IVFDTcpClient::SLOT_SendMsgToServer(QByteArray cmd, QByteArray val)
{
    if(!m_socketisconnectted)
    {
        emit SIG_ConnectToHost(QString("127.0.0.1"), 58890);//58890 is the listen to dip module
        if(m_tcpClientSocket != NULL)
        {
            qDebug() << "3 IVFDTcpClient::SLOT_SendMsgToServer: m_tcpClientSocket != NULL";
            emit SIG_TcpSocketSendMsg(cmd, val);
        }
    }else
    {
        qDebug() << "3 IVFDTcpClient::SLOT_SendMsgToServer: tcpsocket is connected";
        emit SIG_TcpSocketSendMsg(cmd, val);
    }

}

void IVFDTcpClient::SLOT_TcpSocketSendMsg(QByteArray cmd , QByteArray val)
{
//    qDebug() << "3 IVFDTcpClient::SLOT_TcpSocketSendMsg:" << cmd << "---" << val ;
    if(m_tcpClientSocket != NULL)
    {
        qDebug() << "3 IVFDTcpClient::SLOT_TcpSocketSendMsg: write socket:" << m_tcpClientSocket->peerAddress() << "@port:" << m_tcpClientSocket->peerPort();
//        QByteArray ba("what");
//        QString sendstr = cmd.append("&").append(val);
        m_tcpClientSocket->write(val);
        QThread::msleep(10);
        m_tcpClientSocket->disconnectFromHost();
        m_tcpClientSocket->waitForDisconnected(3);
        m_socketisconnectted = false;
    }
    QThread::msleep(30);//test for wait untill process;this is important otherwise there be down machine.
}

void IVFDTcpClient::SLOT_Test()
{
    while(1)
    {
        qDebug() << "test";
        QThread::msleep(1000);
    }
}
