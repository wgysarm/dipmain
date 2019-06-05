#ifndef IVFDTCPCLIENTWORKER_H
#define IVFDTCPCLIENTWORKER_H

#include <QObject>
#include "IVFDTcpSocket.h"

class IVFDTcpClientWorker : public QObject
{
    Q_OBJECT
    explicit IVFDTcpClientWorker(qintptr socketHandle, QObject *parent = 0);
    ~IVFDTcpClientWorker();

private:
    IVFDTcpSocket* m_tcpSocket;
    qintptr m_nID;

signals:
    void SIG_SendData2TcpSocket(QString data, int id);
    void SIG_DisConnectTcpSocket(int id);

    void SIG_Result(int id);
    void SIG_Disconnect();

    void SIG_RevDataFromServer(QString data);        //收到服务端发来数据

public slots:
    void SLOT_RevMessageFromServer();     //服务端发来数据处理
    void SLOT_ServerDisConnect();         //服务端发来断开信号

    void SLOT_SendData(QString data, int id); //向服务端发送数据
    void SLOT_DisConnect();                   //客户端主动断开

    void SLOT_ConnectServer(QString hostName, int port, int timeout);};

#endif // IVFDTCPCLIENTWORKER_H
