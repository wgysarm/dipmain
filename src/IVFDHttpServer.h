#ifndef IVFDHTTPSERVER_H
#define IVFDHTTPSERVER_H

#include <QObject>
#include <QThread>
#include <QEvent>
#include <QByteArray>

#include "IVFDEvent.h"


class IVFDHttpServer : public QObject
{
    Q_OBJECT
public:
    explicit IVFDHttpServer(QObject *parent = 0);
    ~IVFDHttpServer();
    QThread m_httpThread;
    bool event(QEvent *);
    IVFDEvent *m_event;
    void *m_pReceiver;
    qlonglong m_timeStamp;

signals:
    void SIG_OpenCPlayWindow();
    void SIG_CmdFromBrowser(QString,QString);
    void SIG_CmdAnswerFromTopUi(QByteArray);
    void SIG_UpdateTimeStamp(qlonglong);//from top ui to update timestamp

public slots:
    void SLOT_CreatNewHttpServer();
    void SLOT_StartHttpServer();
    void SLOT_PrintCmd(QString,QString);
    void SLOT_UpdateTimeStamp(qlonglong);

};

#endif // IVFDHTTPSERVER_H
