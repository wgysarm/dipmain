#ifndef IVFDFTPSEVER_H
#define IVFDFTPSEVER_H

#include <QObject>

#include "CIVFDFtp.h"
#include <QThread>


class IVFDFtpSever : public QObject
{
    Q_OBJECT
public:
    explicit IVFDFtpSever(QObject *parent = 0);
    CIVFDFtp *m_ftp;
    QThread *m_ftpThread;
    ~IVFDFtpSever();
signals:
    void SIG_StartFtpThread();
    void SIG_StopFtpThread();

public slots:
    void SLOT_StopFtpThread();
};

#endif // IVFDFTPSEVER_H
