#include "IVFDAlgSmoke.h"
#include "CPlayWindow.h"

//using namespace cv;
using namespace android;

//extern Mutex mDisplayLock_1;
IVFDAlgSmoke::IVFDAlgSmoke(QObject *parent, void *image):IVFDAlgProcessModule(parent, image)
{


}

void* IVFDAlgSmoke::Do_DeQue(void *queueHandle)
{
    if(queueHandle == NULL)
    {
        return NULL;
    }

//    android::Mutex::Autolock lock(m_algqueuemutex);
//    IMGYData *imgydata = (IMGYData *)OSAL_Dequeue(queueHandle);
    SeqQueue *pqueue = (SeqQueue *)queueHandle;
    IMGYData *imgydata = (IMGYData *)SeqQueue_Retrieve(pqueue);

    void *rettmp = NULL;
    if(imgydata != NULL)
    {
        if(imgydata->data != NULL && imgydata->mrwFlag == 1)
        {

            imgydata->mrwFlag = 0;
            qDebug("smoke det -----do deque mid = %d mflag = %d", imgydata->mid, imgydata->mrwFlag);

//            CvSize m_size = cvSize(1280, 720);
//            CvSize m_resize = cvSize(640, 360);
//            CvMat m_cvmat = cvMat(720, 1280, CV_8UC1, imgydata->data);


//            Mat src(&m_cvmat);
//            Mat dst;

//            GaussianBlur(src, dst, cv::Size(5,5), 0, 0);
//            Mat kernel = (Mat_<float>(3,3) << 0, -1, 0, 0, 5, 0, 0, -1, 0);
//            filter2D(dst, dst, CV_8UC1, kernel);
////            medianBlur(src, dst, 3);
////            blur(src, dst, cv::Size(3, 3), cv::Point(-1, -1));
////            bilateralFilter(src, dst, 5, 10.0, 2.0);
////            resize(src, dst, cv::Size(), 0.5, 0.5);
////            CvMat m_srcmat = src;
////            Sobel(dst, dst ,-1, 0, 1, 3, 1, 1, BORDER_DEFAULT);
//            Canny(dst, dst, 25, 75, 3);
////            Laplacian(dst, dst, -1, 3);//

////            GaussianBlur(dst, dst, cv::Size(5,5), 0, 0);
//            CvMat m_dstmat = dst;

//            memcpy((uchar *)&(m_scalerImage->mImageData), (uchar *)(imgydata->data), 1280*720);
//            memcpy((uchar *)(&(m_scalerImage->mImageData)), (uchar *)(m_dstmat.data.ptr), 1280*720);

        }

    }
    rettmp = (void *)imgydata;


}

