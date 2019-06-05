#include "IVFDAlgProcessModule.h"
#include "CPlayWindow.h"
#include <QDebug>

//using namespace cv;


//void algImageSmooth(IplImage *image);
//void algResize(Mat srcImage, Mat *dstImage, cv::Size size);


quint32 IVFDAlgProcessModule::m_queMesgLeft = 0;


IVFDAlgProcessModule::IVFDAlgProcessModule(QObject *parent, void *image) : QObject(parent)
{
    if(image == NULL)
    {
        qDebug() << "IVFDAlgProcess Module image = NULL";
        return;
    }
//    m_algqueuemutex = *mutex;
    m_scalerImage = (ImageDataScalem *)image;
    ProcessModuleInit();
}


void IVFDAlgProcessModule::ProcessModuleInit()
{
    m_algProcessThread.start();
    this->moveToThread(&m_algProcessThread);

    QObject::connect(this, SIGNAL(SIG_StartAlgProcess(void *)), this, SLOT(SLOT_StartAlgProcess(void *)));
    QObject::connect(this, SIGNAL(SIG_StopAlgProcess()), this, SLOT(SLOT_StopAlgProcess()));
    QObject::connect(&m_algProcessThread, SIGNAL(finished()), this, SLOT(deleteLater()));


}

void IVFDAlgProcessModule::SLOT_StartAlgProcess(void *queueHandle)
{
    if(queueHandle == NULL)
    {
        qDebug() << "error queueHandle is NULL";
        return;
    }
    SeqQueue *handle = (SeqQueue *)queueHandle;

    while(1)
    {
        IMGYData *mdata = (IMGYData *)Do_DeQue(handle);
        if(mdata)
        {
            qDebug("--QThread id is: %x-------Do_Deque--mid = %d --flag = %d---stamp = %lld ---address = %x", QThread::currentThread(), mdata->mid , mdata->stamp, mdata->mrwFlag, mdata->data);
//            mdata->mrwFlag = 0;//set to unused
        }else
        {
            continue;
        }


    QThread::msleep(100);
    }
}

void IVFDAlgProcessModule::SLOT_StopAlgProcess()
{
    qDebug() << "3 IVFDAlgProcessModule::SLOT_StopAlgProcess()";
    m_algProcessThread.quit();

}


//void* IVFDAlgProcessModule::Do_DeQue(void *queueHandle)
//{
//    QMutexLocker m_locker(&m_algqueuemutex);
//    SeqQueue *pqueue = (SeqQueue *)queueHandle;
//    IMGYData *imgydata = (IMGYData *)SeqQueue_Retrieve(pqueue);

//    void *rettmp = NULL;
//    if(imgydata != NULL)
//    {
//        if(imgydata->data != NULL && imgydata->mrwFlag == 1)
//        {
//            imgydata->mrwFlag = 0;
//            CvSize m_size = cvSize(1280, 720);
//            CvSize m_resize = cvSize(640, 360);
//            CvMat m_cvmat = cvMat(720, 1280, CV_8UC1, imgydata->data);


//            Mat src(&m_cvmat);
//            Mat dst;

//            GaussianBlur(src, dst, cv::Size(5,5), 0, 0);
//            Mat kernel = (Mat_<float>(3,3) << 0, -1, 0, 0, 5, 0, 0, -1, 0);
//            filter2D(dst, dst, CV_8UC1, kernel);
//            Canny(dst, dst, 25, 75, 3);
//            CvMat m_dstmat = dst;
//            memcpy((uchar *)(&(m_scalerImage->mImageData)), (uchar *)(m_dstmat.data.ptr), 1280*720);
//        }

//    }
//    rettmp = (void *)imgydata;
//}

//void algImageSmooth(IplImage *image)
//{
//    IplImage *out = cvCreateImage(cvGetSize(image), IPL_DEPTH_8U, 1);

//}

//void algResize(Mat srcImage, Mat *dstImage, cv::Size size)
//{

//    cv::resize(srcImage, *dstImage, size);

//}

