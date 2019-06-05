#ifndef TESTTHREAD_H
#define TESTTHREAD_H

#include <QObject>
#include <QThread>

class TestThread : public QObject
{
    Q_OBJECT
public:
    explicit TestThread(QObject *parent = 0);
    QThread m_thread;
signals:
    void SIG_StartThread(void);
    void SIG_StopThread(void);

public slots:
    void SLOT_StartThread(void);
    void SLOT_StopThread(void);


public slots:
};

#endif // TESTTHREAD_H
