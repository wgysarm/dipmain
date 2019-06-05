#include "IVFDTcpServerWorker.h"

IVFDTcpServerWorker::IVFDTcpServerWorker(qintptr socketHandle, QObject *parent) : QObject(parent),m_nID(socketHandle),m_tcpSocket(NULL)
{
}


void IVFDTcpServerWorker::SLOT_NewClient(int id)
{
    if(m_tcpSocket == NULL)
    {
        m_nID = id;

        m_tcpSocket = new IVFDTcpSocket(m_nID);

        connect(m_tcpSocket, SIGNAL(readyRead()), this, SLOT(SLOT_RevMessageFromClient()));
        connect(m_tcpSocket, SIGNAL(disconnected()), this, SLOT(SLOT_ClientDisConnect()));
        connect(this, SIGNAL(SIG_DisConnectTcpSocket(int)), m_tcpSocket, SLOT(disConnectTcp(int)));
        connect(this, SIGNAL(SIG_SendData2TcpSocket(QString,int)), m_tcpSocket, SLOT(SLOT_SendData(QString,int)));

        qDebug() << "new Client" << m_nID;
    }
}

void IVFDTcpServerWorker::SLOT_RevMessageFromClient()
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

    emit SIG_ClientHeartStatus(m_nID, 0);

    QByteArray pByte,pType;
    pType = tcpSocket->read(1);//type
    pByte = tcpSocket->read(lengthHeader);//data
//    pByte = tcpSocket->readAll();

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
    {
        qDebug()<<QString(tr("get heartbeat!")) << m_nID;
        QString strHeart;
        strHeart = QString("<HEAD><MCODE>%1</MCODE><DATA>heart</DATA></HEAD>").arg("0X01");
        qDebug()<<QString(tr("reply heartbeat!"));
        emit SIG_SendData2TcpSocket(strHeart, m_nID);
    }
        break;
    default:
        break;
    }

    if(nIndex != -1)
    {
        emit SIG_RevMessage(m_nID, nIndex, strData);
    }
}

void IVFDTcpServerWorker::SLOT_ClientDisConnect()
{
    qDebug() << "client is disconnected" << m_nID;
    emit SIG_ClientDisconnect(m_nID);
}

void IVFDTcpServerWorker::SLOT_DisConnectClient(int id)
{
    if(m_tcpSocket)
    {
        if(id == m_nID || id == -1)
        {
            emit SIG_DisConnectTcpSocket(m_nID);
        }
    }
}

void IVFDTcpServerWorker::SLOT_SendData(int id, QString data)
{
    if(m_tcpSocket)
    {
        if(id == m_nID)
        {
            emit SIG_SendData2TcpSocket(data, m_nID);
        }
    }
}
