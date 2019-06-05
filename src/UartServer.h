#ifndef UARTSERVER_H
#define UARTSERVER_H

#include <QObject>
#include <QThread>
#include <QString>
#include <QDebug>
#include <QByteArray>
#include <QList>


class UartServer : public QObject
{
    Q_OBJECT
public:
    explicit UartServer(QObject *parent = 0);
    ~UartServer();
    QThread m_uartThread;
//    QList<QByteArray> *m_cmdList;
    char *m_readBuf;



signals:
    void SIG_Finished();
    void SIG_Error(QString err);
    void SIG_CloseCPlayWindow();
    void SIG_OpenCPlayWindow();



public slots:
    void SLOT_ReadUart();

    void SLOT_Error(QString err);

    void SLOT_KillSelf();

};

#endif // UARTSERVER_H
