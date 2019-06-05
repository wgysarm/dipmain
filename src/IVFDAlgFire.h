#ifndef IVFDALGFIRE_H
#define IVFDALGFIRE_H

#include <QObject>
#include <QThread>
#include <QMutex>
#include <QMutexLocker>
#include <QDebug>
#include <QEventLoop>
#include <QTimer>
#include <QSettings>
#include <QFile>
#include <QVariant>

#include "OSAL_Queue.h"
#include "OSAL_Mutex.h"
#include "IVFDSeqQueue.h"
#include "IVFDSeqLinkList.h"
//#include <opencv2/core/core.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/highgui/highgui.hpp>
#include <Mutex.h>
#include <QRect>
#include <QPoint>
#include <QSize>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IVFDAlgoApi.h"
//#include "IVFDRtspThread.h"
#include "STE_Typedef.h"
#include "AlgoVFD_IF.h"

#define OPENCVYES 0
#define ALARMMARK QRect(QPoint(200,100), QPoint(400,200))
#define IMAGESIZE STE_IMAGE_WIDTH*STE_IMAGE_HEIGH
using namespace android;

enum EOUTCOMETYPE{NOEVENT, TOOLIGHT, TOODARK, FIREDET, FIREDETEND, VLOST, RUNSTATUS};
enum EALGPARA{SENSE, DELAY, FOV, STATICDET, MINAREA, YLEVEL, LOSS, ALARMDELAY, OVEREXPOS, CONSIST, ALARMLEVEL, AWARETHRLD, STATICTHRLD};

typedef struct ImageDataScaleFire{
    uchar mImageData[IMAGESIZE];
    qlonglong stamp;
    ImageDataScaleFire(qlonglong msec, size_t size){
        stamp = msec;
        memset((uchar *)mImageData, 0, size);
    }
}ImageDataScaleFire;


typedef struct ALARMDATAINFO{
    int alarmType;
    int alarmTime;
    int pTOPLx;
    int pTOPLy;
    int recHeight;
    int recWidth;
}ALARMDATAINFO;



class IVFDAlgFire : public QObject
{
    Q_OBJECT
public:
    explicit IVFDAlgFire(QObject *parent = 0);
    ~IVFDAlgFire();

    QThread *m_algProcessThread;
    ST_AlgoConfig *m_algo_cfg;
    IVFD_YuvImage *m_img_src;
    VARESULT *m_varesult;
    VSV_Handle m_algo_handle;
    STE_ImageBuf	m_proc_result_buf;//算法处理结果的交换内存
    int m_frame_index;
    int m_onwatch;
    ALARMDATAINFO *m_alarmdatainfo;

//    void ProcessModuleInit(void);
    void ProcessModuleInit(ST_AlgoConfig *m_algo_cfg);
    int Do_DeQue(void *queueHandle, int flag, VARESULT *result);
    void* CaptureYUVWriteToFile(void *queueHandle, FILE *fp, int framesize);
    void ImageReverse(uchar *pSrc, uchar *pDest);
signals:
    void SIG_StartAlgProcess(int reverseFlag /**queueHandle*/);
    void SIG_StopAlgProcess(void);
    void SIG_HasOutcome(enum EOUTCOMETYPE type, QRect position, int frame_index);
//    void SIG_SendOutcomeToCPW(QString msg);
    void SIG_SendOutcomeToCPW(QByteArray);
    void SIG_CaptureYUVDataFile(int num);
    void SIG_NoCaptureData();//notify the CPlayWindow ,there is no data to deal with
    void SIG_OnWatchSet(int status);
    void SIG_TellOnWatch();
    void SIG_TellUpper(int val); // notify the CPlayWindow ,val;
    void SIG_QueryStatus(int type);
    void SIG_SetAlgparameter(void *, int id, int val);
    void SIG_ControlAlgStatus(int cmdid, int val);
//    void SIG_SetAlg(int id, int val);//

public slots:
    void SLOT_StartAlgProcess(int reverseFlag/* *queueHandle*/);
    void SLOT_StopAlgProcess(void);
    void SLOT_HasOutcome(enum EOUTCOMETYPE type, QRect position, int frame_index);
    void SLOT_CaptureYUVFile(int num);
    void SLOT_OnWatchSet(int status);
    void SLOT_TellOnWatch();
    void SLOT_QueryStatus(int type);
    void SLOT_SetAlgparameter(void *, int id, int val);
    void SLOT_ControlAlgStatus(int cmdid, int val);
    void SLOT_NoCaptureData();
};

#endif // IVFDALGFIRE_H
