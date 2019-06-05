#ifndef IVFDBROADCAST_H
#define IVFDBROADCAST_H

#include <QObject>
#include <QUdpSocket>
#include <QThread>
#include <QTimer>
#include <QString>
#include <QHostAddress>
#include <QTcpSocket>
#include <QTcpServer>


class IVFDBroadCast : public QObject
{
    Q_OBJECT
public:
    explicit IVFDBroadCast(QObject *parent = 0);
    ~IVFDBroadCast();

    QUdpSocket *m_udpSocket;
    QTimer *m_timer;
    QThread *m_broadCastThread;
    QHostAddress *m_hostAddr;
    QTcpSocket *m_tcpSocket;
    QTcpServer *m_tcpServer;

    quint16 m_udpPorts;
    quint16 m_tcpPorts;

    void setUdpPortn(quint32 portn);
    quint16 getUdpPortn();
    void setTcpPortn(quint32 portn);
    quint16 getTcpPortn();


    int setHostAddr(QHostAddress addr);
    QHostAddress* getHostAddr(void);

    void IVFDBroadCastInit();

signals:
    void Sig_SendBroadCast(QString);
    void Sig_StartBroadCastThread();
    void Sig_StopBroadCastThread();

public slots:
    int SLOT_StartBroadCastThread();
    int SLOT_SendBroadCast(QString);
    void SLOT_StopBroadCastThread();
    void SLOT_DoTimer();

    void SLOT_UdpConnected();
    void SLOT_UdpReadyRead();


};

#endif // IVFDBROADCAST_H
