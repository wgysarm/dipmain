#ifndef IVFDTCPSERVER_H
#define IVFDTCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QByteArray>
#include <QThread>
#include <QDebug>
#include <QFile>

typedef struct CmdARG{
    int cmdtype;
    int argnum;
    int arg1;
    int arg2;
    int arg3;
    int arg4;
}CmdArg;


class IVFDTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit IVFDTcpServer(QObject *parent = 0);
    QTcpServer *m_tcpserver;
    QTcpSocket *m_tcpsocket;
    QThread m_tcpserverThread;
    QHostAddress m_hostAddr;
    quint16 m_port;
    QByteArray m_ba;

    ~IVFDTcpServer();
    void InitThis();
    void XReadAll(QByteArray);
signals:
    void SIG_StartTcpServerThread();
    void SIG_StopTcpServerThread();
    void SIG_WriteToTcpSocket(QByteArray);
    void SIG_TellTop(QByteArray);
    void SIG_WriteFileToSocket(QString fileName);
public slots:

    void SLOT_StartTcpServerThread();
    void SLOT_StopTcpServerThread();
    void SLOT_HasNewConnection();
    void SLOT_ReadyReadAll();
    void SLOT_WriteToTcpSocket(QByteArray);
    void SLOT_SocketError(QAbstractSocket::SocketError);
    void SLOT_WriteFileToSocket(QString filename);
};

#endif // IVFDTCPSERVER_H
