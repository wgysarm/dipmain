#ifndef CPLAYWINDOW_H
#define CPLAYWINDOW_H

#include <QWidget>
#include <QtWidgets/QMainWindow>
#include "ui_CPlayWindow.h"
#if defined(Q_OS_LINUX)
#include "CameraDebug.h"
#include "OSAL_Queue.h"
#include <sdklog.h>

#include "V4L2CameraDevice2.h"
#include "CallbackNotifier.h"
#include "PreviewWindow.h"
#include "CameraHardware2.h"
#include "HALCameraFactory.h"
#include "CameraHardwareInterface.h"
#include "DvrFactory.h"
#include "IVFDAlgProcessModule.h"
#include "IVFDSeqLinkList.h"
#include "IVFDSeqQueue.h"
#include <QThread>
#include <QImage>
#include <QPainter>
#include <QColor>
#include <QPen>
#include <QVector>
#include <QRgb>
#include <QFont>
#include <QMutexLocker>
#include <QMutex>
#include <QByteArray>

using namespace android;
#endif

#if defined(Q_OS_LINUX)
#define SUPPORT_CAMERA_NUM 2
#define MAXBUFFER 30
typedef struct ALGImage{
    int width;
    int height;
    unsigned char *pAlgY;
    unsigned char *pAlgC;

}ALGImage;
typedef struct IMGYData{
    int mrwFlag;//flag of used/unused
    int mid; //current id
    uchar *data; // data ptr;
    qlonglong stamp; //stamp of time
}IMGYData;

typedef struct ImageDataWithStamp{
    uchar mImageData[1280*720];
    qlonglong stamp;
}ImageDataWithStamp;



typedef struct ImageDataScale{
    uchar mImageData[1280*720];
    qlonglong stamp;
    ImageDataScale(qlonglong msec, size_t size){
        stamp = msec;
        memset((uchar *)mImageData, 0, size);
    }
}ImageDataScale;

class MyCamera :public QObject
{

public:
    dvr_factory *dvr;
    int setRecord(bool flag ){isRecord=flag;return 0;}
    int setPaused(bool flag){isPaused=flag;return 0;}
    int setPreview(bool flag){isPreview=flag;return 0;}

    bool getRecord(){return isRecord;}
    bool getPaused(){return isPaused;}
    bool getPreview(){return isPreview;}
    MyCamera()
    {
        isRecord=false;
        isPaused=false;
        isPreview=false;
    }
 private:
    bool isRecord;
    bool isPaused;
    bool isPreview;
};
#endif

class CPlayWindow : public QWidget
{
	Q_OBJECT

public:
    explicit CPlayWindow(QWidget *parent = 0);
	~CPlayWindow();
    //for alg---
     IVFDAlgProcessModule *m_algProcessModule;

    IMGYData m_IMGYData[MAXBUFFER];

    QImage m_ImageAlg, m_ImageOrigin, m_ImageBg, m_ImageTarget;
    OSAL_QUEUE m_imageDataQue;
    SeqQueue *m_queue;
    QMutex m_queuemutex;

//    static uchar m_ImageAlgDat[1280*720];
//    static uchar m_ImageScaleDat[640*360];
    struct ImageDataWithStamp m_ImgWithStamp;
    static struct ImageDataScale m_ImgScale;
    QVector<QRgb> m_grayTable;


    //end alg

    #if defined(Q_OS_LINUX)
    struct view_info mvv;
    MyCamera dvrCamera[SUPPORT_CAMERA_NUM];
    int setCameraDispRect(){
        //mvv.x=
        //mvv.y=
        //mvv.w=
        //mvv.h=
    }
    #endif

    int  startAllCameraWithPreview(int camera_no /* nouse now*/);
    int cur_camera;
    bool isaf;

    #if defined(Q_OS_LINUX)
    Mutex mObjectLock;
    Mutex mDisplayLock;

    #endif

//    ALGImage *m_imageBuffer;

    void CPlayInit();
    void CPlayCallbackTimestamp(nsecs_t timestamp,
                                   int32_t msgType, char* dataPtr, void* user);

    qlonglong CPlayGetCurrentUTCStamp();

    void doUpdate(void);
    void videoshow();
    void startCurCamera();
    void startRecord();
    void stopRecord();
    void startRtspServer1(int num);
    void startRtspServer2(int num);
    void switchRtspServer();


signals:
    void SIG_PlayStop();
    void SIG_PlayStartAll();
    void SIG_PlaySwitch();
    void SIG_PlayStopAll();
    void SIG_DownLoadFile();
    void SIG_RtspSwitch();
    void SIG_StopRtsp1();
    void SIG_GetTimeStamp0();
    void SIG_GetTimeStamp1(long long);
    void SIG_MsgToTopUi(QByteArray msg);//message to send to ivfduidesign
    void SIG_UpdateTimeStamp(qlonglong);

private:

    Ui::CPlayWindow ui;

public slots:
    void SLOT_BtnPreview();
    void SLOT_BtnStop();
    void SLOT_BtnSwitch();
    void SLOT_BtnCam0();
    void SLOT_BtnCam1();
    void SLOT_BtnReturn();
    void SLOT_CmdFromBrowser(QString,QString);
    void SLOT_BtnRtsp1();
    void SLOT_BtnRtsp2();
    void SLOT_BtnRtspSwitch();
    void SLOT_StopRtsp1();
    void SLOT_GetTimeStamp0(void);

protected:
    void paintEvent(QPaintEvent *event);

};

#endif // CPLAYWINDOW_H
