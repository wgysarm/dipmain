#ifndef IVFDTCPSERVERHB_H
#define IVFDTCPSERVERHB_H

#include <QObject>
#include <QTcpServer>
#include "IVFDTcpServerWorker.h"
#include <QThread>
#include <QTimer>
#define HTCPCLIENT_HEART_TIMEOUT_COUNT 3

class IVFDTcpServerHB : public QTcpServer
{
    Q_OBJECT
public:
    explicit IVFDTcpServerHB(QObject *parent = 0);
    ~IVFDTcpServerHB();

    bool    startServer(int port);

private:
    QMap<int, QThread*> m_mapThread;        //保存所有客户端线程 key 为客户端唯一的id
    QMap<int, int>      m_mapClientHeart;   //保存所有客户端心跳状态 key 为客户端唯一的id

    QTimer*             m_checkClientTimer; //检测客户端的定时器

protected:
    void incomingConnection(qintptr handle);    //重载

signals:
    void SIG_NewClient(int id);
    void SIG_SendData(int id, QString data); //向客户端发数据
    void SIG_DisconnectClient(int id);       //服务端主动断开某客户端，id = -1时表示断开所有连接的客户端；

private slots:
    void    SLOT_CheckClientTimer();          //定时检测所有客户端
    void    SLOT_ClientHeartStatus(int id, int nHeartOutTimes);   //心跳状态

    void    SLOT_ClientDisconnect(int id);    //客户端主动断
    void    SLOT_RecMessage(int id, int cmdID, QString data);
};

#endif // IVFDTCPSERVERHB_H
