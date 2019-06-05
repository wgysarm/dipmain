#include "IVFDFtpSever.h"
#include "IvfdLogger.h"
#include <QDebug>


IVFDFtpSever::IVFDFtpSever(QObject *parent) : QObject(parent)
{
    qDebug() << "----------------------------------------Construct ftp thread----------------------------" << QThread::currentThread();

    m_ftp = NULL;
    m_hostAddr = QString("192.168.120.166");
    m_password = QString("password");
    m_portn = QString("2000");
    m_rootpath = QString("\/mnt\/sdcard\/mmcblk1p1\/1\/");
    m_username = QString("username");
    m_ftpThread = new QThread(0);

    if(m_ftpThread == NULL)
    {
        return;
    }

    m_ftpThread->start();

    qDebug() << "----------------------------------------start ftp thread----------------------------" << QThread::currentThread();


    moveToThread(m_ftpThread);
    QObject::connect(m_ftpThread, SIGNAL(finished()), this, SLOT(deleteLater()));
    QObject::connect(m_ftpThread, SIGNAL(finished()), m_ftpThread, SLOT(deleteLater()));
//    QObject::connect(this, SIGNAL(SIG_StopFtpThread()), this, SLOT(SLOT_StopFtpThread()));
    QObject::connect(this, SIGNAL(SIG_StartFtpThread()), this, SLOT(SLOT_StartFtpThread()));
}


IVFDFtpSever::~IVFDFtpSever()
{
    if(m_ftp != NULL)
    {
        delete m_ftp;
        m_ftp = NULL;
    }
//    if(m_ftpThread != NULL)
//    {
//        delete m_ftpThread;
//        m_ftpThread = NULL;
//    }

}

//void IVFDFtpSever::SLOT_StopFtpThread()
//{
//    if(m_ftpThread != NULL)
//    {
//        m_ftpThread->quit();
//        delete m_ftpThread;
//        m_ftpThread = NULL;
//        return;
//    }

//    return;

//}


void IVFDFtpSever::SLOT_StartFtpThread()
{
    m_ftp = CIVFDFtp::GetInstance(m_hostAddr, m_portn, m_username, m_password, m_rootpath);
    if(m_ftp != NULL)
    {
        qDebug() << "------------------m_ftp->m_FTPPlugin->start--------------" << QThread::currentThread();
        m_ftp->m_FTPPlugin->Start();
    }else
    {
        qDebug() << "m_ftp = NULL" ;
        qDebug() << "------------------m_ftp->m_FTPPlugin->start--------------" << QThread::currentThread();
    }

}
