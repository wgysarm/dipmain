#include "IVFDFtpSever.h"
#include "IvfdLogger.h"
#include <QDebug>


IVFDFtpSever::IVFDFtpSever(QObject *parent) : QObject(parent)
{
    qDebug() << "----------------------------------------Construct ftp thread----------------------------";

    m_ftp = CIVFDFtp::GetInstance();
    m_ftpThread = new QThread(0);

    if(m_ftpThread == NULL)
    {
        return;
    }

    m_ftpThread->start();

    qDebug() << "----------------------------------------start ftp thread----------------------------";


    moveToThread(m_ftpThread);
    QObject::connect(m_ftpThread, SIGNAL(finished()), this, SLOT(deleteLater()));
    QObject::connect(this, SIGNAL(SIG_StopFtpThread()), this, SLOT(SLOT_StopFtpThread()));

}


IVFDFtpSever::~IVFDFtpSever()
{
    if(m_ftp != NULL)
    {
        delete m_ftp;
        m_ftp = NULL;
    }
    if(m_ftpThread != NULL)
    {
        delete m_ftpThread;
        m_ftpThread = NULL;
    }

}

IVFDFtpSever::SLOT_StopFtpThread()
{
    if(m_ftpThread != NULL)
    {
        m_ftpThread->quit();
        delete m_ftpThread;
        m_ftpThread = NULL;
        return;
    }

    return;

}
