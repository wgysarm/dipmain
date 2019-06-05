#ifndef IVFDLOCALCAPTURE_H
#define IVFDLOCALCAPTURE_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QFile>
#include <QTimer>
#include <QString>
#include <QIODevice>
#include <QByteArray>

#include <stdlib.h>
#include <stdio.h>

#include "IVFDSeqLinkList.h"
#include "IVFDSeqQueue.h"


typedef struct CAPImage{
    int width;
    int height;
    unsigned char *pAlgY;
    unsigned char *pAlgC;

}CAPImage;


typedef struct CAPIMGYData{
    int mrwFlag;//flag of used/unused
    int mid; //current id
    uchar *data; // data ptr;
    qlonglong stamp; //stamp of time
}CAPIMGYData;


class IVFDLocalCapture : public QObject
{
    Q_OBJECT
public:
    explicit IVFDLocalCapture(QObject *parent = 0, QString srcPath = QString("/mnt/sdcard/mmcblk1p1/1/yuvcapt.yuv"), void *queHandle = NULL, int queBuffern = 0);
    ~IVFDLocalCapture();

    SeqQueue* m_imgeSequeue;
    QThread *m_localCaptureThread;
    QTimer *m_captureTimer;
    QString m_srcFile;
    CAPImage *m_captureImage;
    CAPIMGYData *m_capImgYData;

    int m_buffern;


signals:
    void SIG_StartLocalCaptureThread();
    void SIG_StopLocalCatureThread();



public slots:
    void SLOT_StartLocalCaptureThread();
    void SLOT_StopLocalCaptureThread();
    void SLOT_DoCaptureImage();

private:
    void InitThis();


};

#endif // IVFDLOCALCAPTURE_H
