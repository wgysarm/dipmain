#ifndef IVFDALGPROCESSMODULE_H
#define IVFDALGPROCESSMODULE_H

#include <QObject>
#include <QThread>
#include <QMutex>
#include <QMutexLocker>
#include <QDebug>

#include "OSAL_Queue.h"
#include "OSAL_Mutex.h"
#include "IVFDSeqQueue.h"
//#include <opencv2/core/core.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/highgui/highgui.hpp>
#include <Mutex.h>
//#include <cv.h>
using namespace android;

#define imgwidth 1920//1280
#define imgheight 1080//720
#define imgsizetmp imgwidth*imgheight

typedef struct ImageDataScalem{
    uchar mImageData[imgsizetmp];//    uchar mImageData[1280*720]
    qlonglong stamp;
    ImageDataScalem(qlonglong msec, size_t size){
        stamp = msec;
        memset((uchar *)mImageData, 0, size);
    }
}ImageDataScalem;


class IVFDAlgProcessModule : public QObject
{
    Q_OBJECT
public:
    explicit IVFDAlgProcessModule(QObject *parent = 0, void *image = 0);

    QThread m_algProcessThread;

//    Mutex m_algqueuemutex;

    ImageDataScalem* m_scalerImage;

    static quint32 m_queMesgLeft;
    void ProcessModuleInit(void);

    virtual void* Do_DeQue(void *queueHandle) = 0;


signals:
    void SIG_StartAlgProcess(void *queueHandle);
    void SIG_StopAlgProcess(void);


public slots:
    void SLOT_StartAlgProcess(void *queueHandle);
    void SLOT_StopAlgProcess(void);


};

#endif // IVFDALGPROCESSMODULE_H
