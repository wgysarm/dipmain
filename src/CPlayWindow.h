#ifndef CPLAYWINDOW_H
#define CPLAYWINDOW_H

#include <QWidget>
#include <QtWidgets/QMainWindow>
#include "ui_CPlayWindow.h"
#if defined(Q_OS_LINUX)

#include <sdklog.h>
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
#include <Mutex.h>
#include <QVariant>

#include "CameraDebug.h"
#include "OSAL_Queue.h"
#include "V4L2CameraDevice2.h"
#include "CallbackNotifier.h"
#include "PreviewWindow.h"
#include "CameraHardware2.h"
#include "HALCameraFactory.h"
#include "CameraHardwareInterface.h"
#include "DvrFactory.h"
#include "IVFDAlgFire.h"
#include "IVFDAlgSmoke.h"
#include "IVFDSeqLinkList.h"
#include "IVFDSeqQueue.h"
#include "TestThread.h"
#include "IVFDLocalCapture.h"

//#include "IVFDUiDesign.h"
using namespace android;
#endif

#if defined(Q_OS_LINUX)

#define SUPPORT_CAMERA_NUM 2
#define MAXBUFFER 6
#define MINBUFFER 6
#define IMGWIDTH 1920//1920//1280
#define IMGHEIGHT 1080//1080//720
#define IMAGESIZE IMGWIDTH*IMGHEIGHT

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
    uchar mImageData[IMAGESIZE];
    qlonglong stamp;
}ImageDataWithStamp;

typedef struct ImageDataScale{
    uchar mImageData[IMAGESIZE];
    qlonglong stamp;
    ImageDataScale(qlonglong msec, size_t size){
        stamp = msec;
        memset((uchar *)mImageData, 0, size);
    }
}ImageDataScale;




typedef struct CameraStatus{
    int bright;
    int gain;
    int exposure;
    int saturation;
}CameraStatus;

typedef struct GeneralMsg{
    int source;//0=main 1=http, 2=ftp, 3=dip 4=client
    int dest;//0=main 1=http, 2=ftp, 3=dip 4=client
    int type;//0=cmd,1=status;
    int msgid;//defined by user;
    int val;//defined by user;
}GeneralMsg;


typedef struct CameraParaN{
    int id;
    int bright;
    int gain;
    int whitebalance;
}CameraParaN;

enum EGPIOSTATUS{LOW, HIGH};

typedef struct GPIOStatus{
    EGPIOSTATUS led1;
    EGPIOSTATUS led2;
    EGPIOSTATUS led3;
    EGPIOSTATUS relayout1;
    EGPIOSTATUS relayout2;
    EGPIOSTATUS buzz;
}GPIOStatus;

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
    CPlayWindow(QWidget *parent = 0);
    explicit CPlayWindow(QWidget *parent = 0, void* pCamera0 = NULL, void* pCamera1 = NULL);
	~CPlayWindow();
    int m_imageSize;
    int m_flagCameraSetChanged;
    static int m_onwatchstatus;
    CameraParaN m_campara0, m_campara1;
    //for alg---
    IVFDAlgFire *m_algProcessModule_0 ;
    IVFDAlgSmoke *m_algProcessModule_1 ;

    IVFDLocalCapture *m_localCapture;

    IMGYData m_IMGYData_0[MAXBUFFER];
    IMGYData m_IMGYData_1[MAXBUFFER];
    IMGYData m_IMGYData_2[MINBUFFER];

    QImage m_ImageAlg_0, m_ImageOrigin_0;
    QImage m_ImageAlg_1, m_ImageOrigin_1;
    QImage m_ImageAlg_2, m_ImageOrigin_2;

    OSAL_QUEUE m_imageDataQue_0;
    TestThread *m_testthread;

    static SeqQueue *m_queue_0;
    static SeqQueue *m_queue_1;
    static SeqQueue *m_queue_2;//for image capture file
    QMutex m_queuemutex;
//    static android::Mutex mDisplayLock_0;
    static QMutex mDisplayLock_0;
    QMutex mDisplayLock_1;

    struct ImageDataWithStamp m_ImgWithStamp_0;
    struct ImageDataWithStamp m_ImgWithStamp_1;

    static struct ImageDataScale m_ImgScale_0;//for alg display
    static struct ImageDataScale m_ImgScale_1;//for alg display

    QVector<QRgb> m_grayTable;
    //end alg

#if defined(Q_OS_LINUX)
    struct view_info m_vv;
    MyCamera dvrCamera[SUPPORT_CAMERA_NUM];
    int setCameraDispRect(){
        //mvv.x=
        //mvv.y=
        //mvv.w=
        //mvv.h=
        return 0;
    }
#endif

    int  startAllCameraWithPreview(int camera_no /* nouse now*/);
    int cur_camera;
    bool isaf;

    #if defined(Q_OS_LINUX)
    QMutex mObjectLock;

    #endif

//    ALGImage *m_imageBuffer;

    void CPlayInit(void *pCamera0, void *pCamera1);
    void CPLaySetCamera(int idname);
    void CPlayCallbackTimestamp_0(nsecs_t timestamp,
                                   int32_t msgType, char* dataPtr, void* user);
    void CPlayCallbackTimestamp_1(nsecs_t timestamp,
                                   int32_t msgType, char* dataPtr, void* user);
    qlonglong CPlayGetCurrentUTCStamp_0();
    qlonglong CPlayGetCurrentUTCStamp_1();
    void startRecord();
    void stopRecord();
    void captureAndDIPAndRtsp();


signals:
    void SIG_CaptureAndDIP();
    void SIG_GetTimeStamp0();
    void SIG_GetTimeStamp1();
    void SIG_StartAlgFireDet(int/*void*//* *queueHandle*/);
    void SIG_StopAlgFireDet();
    void SIG_ControlAlg(int id, int val);
    void SIG_CaptureYUVFile(int num);
    void SIG_NewAlgFireDet();
    void SIG_StartAlgSmokeDet(void *queueHandle);
    void SIG_MsgToTopUi(QByteArray msg);//message to send to ivfduidesign
    void SIG_UpdateTimeStamp(qlonglong);
    void SIG_SetCameraParameter(int name, int val1, int val2, int val3);
    void SIG_TestThread(void);
    void SIG_StartAlgDet(int);
    void SIG_StopAlgDet();
    void SIG_GetOutcome(QByteArray msg);
    void SIG_SendMsgToUITcpClient(QByteArray cmd ,QByteArray val);
    void SIG_SetGPIOPin(int pin, int val);
    void SIG_DestroyCPlayWindow();
    void SIG_StartLocalCaptureThread();
    void SIG_StopLocalCaptureThread();
    //to algmodule0

    void SIG_QueryVal(int types);
    void SIG_AnswerQuery(int val);
private:

    Ui::CPlayWindow ui;
    dvr_factory *m_pdvr0, *m_pdvr1;

public slots:
    void SLOT_CmdFromBrowser(QString,QString);
    void SLOT_CaptureAndDIP();
    void SLOT_GetTimeStamp0(void);
    void SLOT_GetTimeStamp1(void);
    void SLOT_SetBrightness(void);
    void SLOT_SetCameraParam(int cameraname, int val1, int val2, int val3);
    void SLOT_StartAlgDet(int);
    void SLOT_NewAlgFireDet();
    void SLOT_StopAlgFireDet();
    void SLOT_GetOutcome(QByteArray msg);
    void SLOT_SetGPIOPin(int pin, int val);
    void SLOT_DestroyCPlayWindow();
    void SLOT_ControAlg(int id , int val);
    void SLOT_QueryVal(int);
    void SLOT_AnswerQuery(int val);
protected:
    void paintEvent(QPaintEvent *event);

};

#endif // CPLAYWINDOW_H
