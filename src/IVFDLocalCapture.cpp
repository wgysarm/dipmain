#include "IVFDLocalCapture.h"
#define imgwidth 1920//1280
#define imgheight 1080//720
#define imgsizetmp imgwidth*imgheight

IVFDLocalCapture::IVFDLocalCapture(QObject *parent, QString srcPath, void *queHandle, int queBuffern) : QObject(parent)
{
    m_imgeSequeue = queHandle;

    m_localCaptureThread = new QThread(this);
    m_captureTimer = new QTimer(this);

    m_srcFile = srcPath;
    m_buffern = queBuffern;
    m_captureImage = (CAPImage *)malloc(sizeof(CAPImage));
    m_captureImage->height = imgheight;//720
    m_captureImage->width = imgwidth;//1280
    int imagesize = m_captureImage->height*m_captureImage->width;
    m_captureImage->pAlgY = (unsigned char*)malloc(imagesize);
    m_captureImage->pAlgC = (unsigned char*)malloc(imagesize);

    m_capImgYData = (CAPIMGYData*)malloc(sizeof(CAPIMGYData));
    m_capImgYData->data = (unsigned char*)malloc(imagesize);
    m_capImgYData->mid = 0;
    m_capImgYData->mrwFlag = 0;
    m_capImgYData->stamp = 0;

    InitThis();


}

IVFDLocalCapture::~IVFDLocalCapture()
{

}

void IVFDLocalCapture::InitThis()
{
    m_captureTimer->setInterval(1000);
//    m_captureTimer->start();
    QObject::connect(m_localCaptureThread, SIGNAL(finished()), this, SLOT(deleteLater()));
//    QObject::connect()
    QObject::connect(this, SIGNAL(SIG_StartLocalCaptureThread()), this, SLOT(SLOT_StartLocalCaptureThread()));
    QObject::connect(this, SIGNAL(SIG_StopLocalCatureThread()), this, SLOT(SLOT_StopLocalCaptureThread()));
    QObject::connect(m_captureTimer, SIGNAL(timeout()), this, SLOT(SLOT_DoCaptureImage()));
}




void IVFDLocalCapture::SLOT_StartLocalCaptureThread()
{

    m_localCaptureThread->start();
    this->moveToThread(m_localCaptureThread);

}

void IVFDLocalCapture::SLOT_StopLocalCaptureThread()
{

    m_localCaptureThread->quit();
}

void IVFDLocalCapture::SLOT_DoCaptureImage()
{
//    qDebug("3 IVFDLocalCapture::SLOT_DoCaptureImage()---------excute a capture!");

    QFile imageFile(m_srcFile);
    if(!imageFile.exists())
    {
//        qDebug("3 IVFDLocalCapture::SLOT_DoCaptureImage()---no srcFile exist!");
        return;
    }

    FILE *yuv_file = fopen(m_srcFile.toLatin1().data(), "rb");
    if(!yuv_file)
    {
        qDebug("IVFDLocalCapture::SLOT_DoCaptureImage():open file error!");
        return;
    }
    int sequeret;

    fseek(yuv_file, 0L, SEEK_END);
    long len = ftell(yuv_file);
    int framenum = len/(imgsizetmp);//1280*720
    unsigned char buffer[imgsizetmp];

    qDebug("file size is %ld", len);
    rewind(yuv_file);
    qDebug("now first pos is %ld", ftell(yuv_file)) ;
    if(ftell(yuv_file) == 0)
    {
        for(int i = 0; i < framenum; i++)
        {
            fread(buffer, imgsizetmp, 1, yuv_file);//1280*720
            //package the data into m_capImgYData
            memcpy(m_capImgYData->data, buffer, (imgsizetmp));//1280*720
            m_capImgYData->mid++;
            m_capImgYData->mrwFlag = 1;
            m_capImgYData->stamp ++;
            //end package
            //push into queue
            sequeret = SeqQueue_Append(m_imgeSequeue, m_capImgYData);
        }
        long pos = ftell(yuv_file);
        qDebug("now pos is %ld!", pos);
        rewind(yuv_file);
    }
    fclose(yuv_file);
}



