#ifndef IVFDEVENTMANAGER_H
#define IVFDEVENTMANAGER_H

#include <QObject>
#include <QThread>
#include "IVFDAlgFire.h"

class IVFDEventManager : public QObject
{
    Q_OBJECT
public:
    explicit IVFDEventManager(QObject *parent = 0);
    ~IVFDEventManager();
    QThread m_thread;
    void InitThis();
    ALARMDATAINFO *m_alarmdatainfo;

signals:
    void SIG_ThreadQuit();
    void SIG_ThreadStart();
    void SIG_DoEventManager();
    void SIG_SendToClient(QByteArray, QByteArray);//Tell the father to send to client;

public slots:
    int SLOT_DoEventManager();
    int SLOT_ThreadStart();
};

#endif // IVFDEVENTMANAGER_H

