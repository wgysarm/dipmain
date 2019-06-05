#include "IVFDTcpClientWorker.h"
#include <QDebug>
#include <QXmlStreamReader>


IVFDTcpClientWorker::IVFDTcpClientWorker(qintptr socketHandle, QObject *parent)
    : QObject(parent),
      m_nID(socketHandle)
{
    m_tcpSocket = NULL;
}

IVFDTcpClientWorker::~IVFDTcpClientWorker()
{
    qDebug() << QString::fromLocal8Bit("析构……。……。……。……。……。……………。");
}

void IVFDTcpClientWorker::SLOT_RevMessageFromServer()
{
    IVFDTcpSocket* tcpSocket = (IVFDTcpSocket*)QObject::sender();
    if(tcpSocket != m_tcpSocket)
    {
        qDebug() << "unKnown Data";
        return;
    }

    if(tcpSocket->bytesAvailable() <= 0)
    {
        qDebug() << "no data";
        return;
    }

    long lengthHeader = QString(tcpSocket->read(8)).toLong();

    if(lengthHeader <= 0)
    {
        qDebug() << "no data 2";
        return;
    }

    QByteArray pByte;
    pByte = tcpSocket->read(lengthHeader);

    //解析数据（这部分可以根据自己定义的通信协议及通信的数据结构进行解析
    //我这里采用的是xml的数据结构
    int nIndex = -1;//命令码
    QString strData;
    QXmlStreamReader reader(pByte);
    while(!reader.atEnd())
    {
        if(reader.isStartElement())
        {
            if(reader.name().compare("MCODE", Qt::CaseInsensitive) == 0)
            {
                nIndex = reader.readElementText().remove("0X").toInt();
            }

            if(reader.name().compare("DATA", Qt::CaseInsensitive) == 0)
            {
                strData = reader.readElementText();
            }
        }
        reader.readNext();
    }

    switch (nIndex)
    {
    case 1://心跳包
    {//为了减少开销，心跳包由定时器发送，客户端收到服务端的心跳后，只恢复标志位即可
//        QString strHeart;
//        strHeart = QString("<HEAD><MCODE>%1</MCODE><DATA>heart</DATA></HEAD>").arg("0X01");
        qDebug()<<QString::fromLocal8Bit("收到心跳包") << m_nID;
//        emit SIG_SendData2TcpSocket(strHeart, m_nID);
    }
        break;
    default:
        break;
    }

    emit SIG_RevDataFromServer(strData);

}

void IVFDTcpClientWorker::SLOT_ServerDisConnect()
{
    qDebug() << QString::fromLocal8Bit("服务端关闭") << m_nID;
    emit SIG_Disconnect();
}

void IVFDTcpClientWorker::SLOT_DisConnect()
{
    if(m_tcpSocket)
    {
        qDebug() << QString::fromLocal8Bit("断开与服务端连接") << m_nID;
        emit SIG_DisConnectTcpSocket(m_nID);
//        m_tcpSocket->disconnectFromHost();
//        m_tcpSocket->deleteLater();
//        m_tcpSocket = NULL;
    }
}

void IVFDTcpClientWorker::SLOT_SendData(QString data, int id)
{
    if(m_tcpSocket)
    {
        if(id == m_nID)
        {
            emit SIG_SendData2TcpSocket(data, m_nID);
        }
    }
}

void IVFDTcpClientWorker::SLOT_ConnectServer(QString hostName, int port, int timeout)
{
    if(NULL == m_tcpSocket)
    {
        m_tcpSocket = new IVFDTcpSocket(m_nID);

        connect(m_tcpSocket, SIGNAL(readyRead()), this, SLOT(SLOT_RevMessageFromServer()));
        connect(m_tcpSocket, SIGNAL(disconnected()), this, SLOT(SLOT_ServerDisConnect()));
        connect(this, SIGNAL(SIG_DisConnectTcpSocket(int)), m_tcpSocket, SLOT(disConnectTcp(int)));
        connect(this, SIGNAL(SIG_SendData2TcpSocket(QString,int)), m_tcpSocket, SLOT(sendData(QString,int)));
    }

    if(m_tcpSocket)
    {
        m_tcpSocket->connectToHost(hostName, port);
        if(!m_tcpSocket->waitForConnected(timeout))
        {
            qDebug()<<"conncet to server is timeout";
            emit SIG_Result(-1);
        }
        else
        {
            emit SIG_Result(0);
        }
    }
}
