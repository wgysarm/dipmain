#ifndef IVFDTCPWORKER_H
#define IVFDTCPWORKER_H

#include <QObject>
#include <QDebug>
#include <QXmlStreamReader>
#include "IVFDTcpSocket.h"

class IVFDTcpServerWorker : public QObject
{
    Q_OBJECT
public:
    explicit IVFDTcpServerWorker(qintptr socketHandle, QObject *parent = 0);

private:
    IVFDTcpSocket* m_tcpSocket;
    qintptr m_nID;

signals:
    void SIG_SendData2TcpSocket(QString data, int id);   //向客户端发数据
    void SIG_DisConnectTcpSocket(int id);                //断开某个客户端

    void SIG_ClientDisconnect(int id);
    void SIG_ClientHeartStatus(int id, int nHeartOutTimes);
    void SIG_RevMessage(int id, int cmdID, QString data);

public slots:
    void SLOT_RevMessageFromClient();     //客户端发来数据处理
    void SLOT_ClientDisConnect();         //客户端发来断开信号

    void SLOT_NewClient(int id);          //新客户端连接
    void SLOT_SendData(int id, QString data); //向客户端发送数据
    void SLOT_DisConnectClient(int id);       //服务端主动断开某客户端，当id = -1时表示断开全部
};

#endif // IVFDTCPWORKER_H
