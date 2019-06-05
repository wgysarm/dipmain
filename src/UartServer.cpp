#include "UartServer.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define SERIAL "/dev/ttyS0"



UartServer::UartServer(QObject *parent) : QObject(parent)
{
//    m_cmdList = new QList<QByteArray>();
//    QByteArray baOpen ;
//    QByteArray baClose;
//    memccpy(baOpen.data(), "open", 4, 4);
//    qDebug() << baOpen.at(0) ;
//    qDebug() << baOpen.at(1) ;
//    qDebug() << baOpen.at(2) ;
//    qDebug() << baOpen.at(3) ;


//    memccpy(baClose.data(), "close", 5, 5);
//    qDebug() << baOpen.at(0) ;
//    qDebug() << baOpen.at(1) ;
//    qDebug() << baOpen.at(2) ;
//    qDebug() << baOpen.at(3) ;
//    qDebug() << baOpen.at(4) ;
//    m_cmdList->append(baOpen);
//    m_cmdList->append(baClose);
//    qDebug() << m_cmdList.at(0);
//    qDebug() << m_cmdList.at(1);

    m_readBuf = (char*)malloc(1024);

    qDebug() << "--------uart server construct------" << QThread::currentThread();

    QObject::connect(&m_uartThread, SIGNAL(finished()), this, SLOT(deleteLater()));

    QObject::connect(this, SIGNAL(SIG_Finished()), &m_uartThread, SLOT(quit()));

    QObject::connect(this, SIGNAL(SIG_Error(QString)), this, SLOT(SLOT_Error(QString)));

}

UartServer::~UartServer()
{
//    if(m_readBuf != NULL)
//    {
//        free(m_readBuf);
//        m_readBuf = NULL;
//    }
}


void UartServer::SLOT_Error(QString err)
{
    qDebug() << err;

}


void UartServer::SLOT_ReadUart()
{

    qDebug() << "------uart thread------"  <<QThread::currentThread();
    int fd = open(SERIAL, O_RDWR, 1);
    if(fd < 0)
    {
        emit SIG_Error(QString("opne serial ttyS0 error"));
    }

    for(;;)
    {

        int ret = read(fd, m_readBuf, 1024);
        if(ret)
        {
//            const QString &str = QString(m_readBuf);

//            if(QString::compare(str,strclose) == 0)
//            {
//                emit SIG_CloseCPlayWindow();
//                qDebug() << "close" ;
//            }else if(QString::compare(str,stropen) == 0)
//            {
//                emit SIG_OpenCPlayWindow();
//                qDebug() << "open";
//            }


        }
        QThread::msleep(20);
    }


}

void UartServer::SLOT_KillSelf()
{

    emit SIG_Finished();
}
