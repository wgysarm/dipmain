#include "TestThread.h"
#include <QDebug>

TestThread::TestThread(QObject *parent) : QObject(parent)
{

    m_thread.start();

    this->moveToThread(&m_thread);
    QObject::connect(&m_thread, SIGNAL(finished()), this, SLOT(deleteLater()));
    QObject::connect(this, SIGNAL(SIG_StartThread()), this, SLOT(SLOT_StartThread()));
    QObject::connect(this, SIGNAL(SIG_StopThread()), this, SLOT(SLOT_StopThread()));

}



void TestThread::SLOT_StartThread()
{
    while(1)
    {
        qDebug() << "thread------" << QThread::currentThread();
        QThread::msleep(500);
    }

}

void TestThread::SLOT_StopThread()
{
    m_thread.quit();

}
