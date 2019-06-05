
#include "IVFDRtspThread.h"

#include <QImage>
//using namespace std;
//
//old
//#include<opencv/cv.hpp>
//#include<opencv/highgui.h>
//
#define LOG_BUF_SIZE	1024
#define VIEW_WEITH 96//480 //720
#define VIEW_HEIGHT 64//320 //480
#define WATERMARKORI 1


extern IVFDUiDesign *pIVFDUiDesign;

#define CAM0 0;
#define CAM1 1;


#define RECORD_TEST 1
//#define ANOTHER_CAMERA_TEST 1

#define TEST_CAMERA_ID 0
#define TEST_CAMERA_ID2 1

#define TEST_CAMERA_ID_T1 0
#define TEST_CAMERA_ID_T2 1

static FILE* h264fp;

ImageDataScale CPlayWindow::m_ImgScale = ImageDataScale(0, 1280*720);


pthread_t currentpthread = -1;
char header[] = {
    0x00, 0x00, 0x00, 0x01, 0x67, 0x4d, 0x00,0x1f,
    0xe5, 0x40, 0x28, 0x02, 0xd8, 0x80, 0x00,0x00,
    0x00, 0x01, 0x68, 0xee, 0x31, 0x12};


using namespace std;

#define HAVA_TWO_CAMERA 1  //While move to cfg
#define CAMERA_FONT 0  //While move to cfg
#define CAMERA_BACK 1 //While move to cfg


static VencInputBuffer inputBuffer;

QMutex m_queuemutex(QMutex::NonRecursive);

QWaitCondition m_queuecond;

#if defined(Q_OS_LINUX)
using namespace android;
#endif

#if defined(OPENCVYES)
using namespace cv;
#endif

nsecs_t nsStamp;

#if defined(Q_OS_LINUX)

static long long GetNowUs()
{
    struct timeval now;
    gettimeofday(&now, NULL);
    return now.tv_sec * 1000000 + now.tv_usec;
}

static int set_socket_timeout(int socket, int time)
{

    int ret;
    struct timeval tv;
    tv.tv_sec = time;
    tv.tv_usec = 0;
    if(socket == -1 || time <= 0)
    {
        return -1;
    }

    //½ÓÊÕ³¬Ê±
    ret = setsockopt(socket, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));
    if(ret < 0)
    {
        perror("setsockopt error");
        return -1;
    }

    //·¢ËÍ³¬Ê±
    ret = setsockopt(socket, SOL_SOCKET, SO_SNDTIMEO, &tv, sizeof(tv));
    if(ret < 0)
    {
        perror("setsockopt error");
        return -1;
    }

    return 0;
}

static void send_h264_header(int send_sock)
{

    tFrameHead rtspheader;
    rtspheader.bySync = FRAME_HEAD_SYNC;
    rtspheader.byType = FRAME_DATA_TYPE;
    rtspheader.dwDataLen = sizeof(header);

    int send_length;
    send_length = send(send_sock, &rtspheader, sizeof(rtspheader), 0);
    if (send_length != sizeof(rtspheader))
    {
        LOGE("send data head fail eager %d real %d\n", sizeof(rtspheader), send_length);
        return;
    }

    send_length = send(send_sock, &header, rtspheader.dwDataLen, 0);

    int data_length = rtspheader.dwDataLen;
    while(send_length < data_length)
    {
        int ret;
        ret = send(send_sock, &header+send_length, data_length - send_length, 0);
        if(ret < 0)
        {
            perror("send stream rtsp data");
            break;
        }
        else if(ret == 0)
        {
            break;
        }
        else
        {
            send_length += ret;
        }
    }

}


static void *testcallback(void *arg)
{
    qDebug() << "testcallback is " << arg;
}

static pthread_mutex_t   m_quemutex;
static pthread_cond_t    m_quecond;

//static OSAL_QUEUE m_alarmTimeStamp;
//static OSAL_QUEUE m_imageDataQue;
//static element should be initialized outside the class;
//IMGYData CPlayWindow::m_IMGYData[MAXBUFFER] = {0};

//char CPlayWindow::m_ImageAlgDat[1280*720] = {0};
//char CPlayWindow::m_ImageScaleDat[640*360] = {0};


static void *thread_imgprocess(void *)
{
    pthread_mutex_lock(&m_quemutex);
    while(is_exit == 0)
    {
        pthread_cond_wait(&m_quecond, &m_quemutex);
        qDebug() << "do image process";

        IMGYData *imgydata = NULL;//(IMGYData *)OSAL_Dequeue(&m_imageDataQue);


//        qDebug() << mesg->timestamp;
//        qDebug() << "nPts =" << imgdata->nPts \
//                 << "nid = " << imgdata->nID \
//                 << "PhyC =" << imgdata->pAddrPhyC \
//                 << "PhyY =" << imgdata->pAddrPhyY \
//                 << "VirC =" << imgdata->pAddrVirC \
//                 << "VirY =" << imgdata->pAddrVirY ;
        qDebug() << imgydata->mrwFlag;
        if(imgydata != NULL)
        {
            qDebug() << imgydata;
            qDebug("address = %x", imgydata->data);
            imgydata->mrwFlag = 0;
//            memset(imgydata->data, 0, 1280*720);
//            QImage tmpImg((uchar *)(imgydata->data), 1280, 720, QImage::Format_Indexed8);
//            QImage mImgtemp(1280, 720, QImage::Format_Indexed8);
//            mImgtemp = tmpImg.copy(0, 0, 1280, 720);
//            CPlayWindow::m_ImageAlg = tmpImg.copy(0, 0, 1280, 720);
//            memcpy((uchar *)&m_ImgWithStamp.mImageData, (uchar *)(imgydata->data), 1280*720);

            qDebug() << imgydata->mrwFlag ;
            for(int i = 0; i < 30; i++)
            {
//                 qDebug("--%x--", m_ImgWithStamp.mImageData[i]);
            }
            free(imgydata->data);
            imgydata->data = NULL;
            qDebug() << "free(imgydata->data)----------" << QThread::currentThread();/* << imgydata->data*/;
//            pstaticthis->SIG_GetTimeStamp0();
        }

//        QThread::msleep(100);

    }
    pthread_mutex_unlock(&m_quemutex);
}


static void *thread_local_socket(void *arg)
{
    int socket_id = -1;
    int ret;
    int optval = 1;
//	struct sockaddr_in servaddr;
    struct sockaddr_un servaddr;
    int seconds = RECV_TIMEOUT;

    struct sockaddr_un client_addr;

    int client_id;
    int addr_size;

    int streamnum = *(int *)arg;

    unsigned char buff[BUF_SIZE] = {0};

//    FILE * file_fd;
//    file_fd = fopen("venc.h264", "rb");
//    if (file_fd == NULL)
//    {
//    	perror("open file");
//    	return  (void *)-1;
//    }
    currentpthread = pthread_self();
    qDebug() << "------------------------in thread_local socket-------------currentpthread = " << currentpthread;


    socket_id = socket(PF_UNIX, SOCK_STREAM, 0);
    if (socket_id < 0)
    {
        perror("socket error");
        return (void *)-1;
    }

    ret = setsockopt(socket_id, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
    if(ret < 0)
    {
        perror("setsockopt error");
        return (void *)-1;
    }

    ret = set_socket_timeout(socket_id, seconds);
    if(ret == -1)
    {
        return (void *)-1;
    }

    memset(&servaddr, 0, sizeof(servaddr));


    char UNIX_DOMAIN[256];
    if (streamnum == 0) {
        strcpy(UNIX_DOMAIN, UNIX_DOMAIN_0);
    } else {
        strcpy(UNIX_DOMAIN, UNIX_DOMAIN_1);
    }


    servaddr.sun_family = AF_UNIX;
    strncpy(servaddr.sun_path, UNIX_DOMAIN, sizeof(servaddr.sun_path)-1);
    unlink(UNIX_DOMAIN);

    ret = bind(socket_id, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if (ret < 0)
    {
        printf("bind error");
        unlink(UNIX_DOMAIN);
        return (void *)-1;
    }

    ret = listen(socket_id, 5);
    if (ret < 0)
    {
        perror("listen error");
        unlink(UNIX_DOMAIN);
        return (void *)-1;
    }

    addr_size = sizeof(client_addr);

    while(is_exit == 0)
    {
        client_id = accept(socket_id, (struct sockaddr *)&client_addr, (socklen_t *)&addr_size);
        if (client_id < 0)
        {
            if(errno == EAGAIN || errno == EINTR)
            {
                continue;
            }
            else
            {
                perror("accept error");
                break;
            }
        }

        ret = set_socket_timeout(socket_id, seconds);
        if(ret == -1)
        {
            close(socket_id);
            continue;
        }


        if (streamnum == 0) {
            send_sock_rtsp_0 = client_id;
        } else {
            send_sock_rtsp_1 = client_id;
        }



        while(is_exit == 0)
        {
            ret = recv(client_id, buff, BUF_SIZE, 0);	//ÓÃÓÚÅÐ¶ÏÊÇ·ñ¶Ï¿ªÁ¬½Ó
            if (ret < 0)
            {
                if(errno == EAGAIN || errno == EINTR)
                {
                    continue;
                }
                else
                {
                    perror("recv error");
                    break;
                }
            }
            else if (ret == 0)
            {
                printf(" disconnected\n");
                break;
            }

            // process
//			send_h264(file_fd, client_id);
//			send_h264_header();
        }

        if (streamnum == 0) {
            send_sock_rtsp_0 = -1;
        } else {
            send_sock_rtsp_1 = -1;
        }

        close(client_id);
    }

//	fclose(file_fd);

    close(socket_id);

    return (void *)(0);
}




static void InitInputBuffer(VencInputBuffer inbuf)
{
    inputBuffer = inbuf;
}


void mycallback(void *func(void *), void *ptr)
{
    func(ptr);
}

class CRTSPThread : public QThread//by wgy
{
public:
    explicit CRTSPThread(QObject *parent = 0): QThread(parent)
    {
        qDebug() << "construct CRTSPThread" ;
    }

protected:
    void run()
    {
//        qDebug() << "run CRTSPThread";
        mycallback(testcallback, NULL);
//        while(1)
//        {
//         sleep(1);
//         mycallbSack(testcallback, NULL);
//         qDebug() << "run CRTSPThread" << QThread::currentThread();
//        }
    }
};

static void usernotifyCallback(int32_t msgType, int32_t ext1,
                        int32_t ext2, void* user)
{
//printf("cb------------------%p",user);
    if ((msgType&CAMERA_MSG_ERROR) ==CAMERA_MSG_ERROR)
    {
        ALOGE("(msgType =CAMERA_MSG_ERROR)");

    }

    if ((msgType&CAMERA_MSG_DVR_STORE_ERR) ==CAMERA_MSG_DVR_STORE_ERR)
    {
        ALOGE("msgType =CAMERA_MSG_DVR_STORE_ERR)");

        dvr_factory *p_dvr=(dvr_factory *)user;
        p_dvr->storage_state=0;//tmp
        p_dvr->stopRecord();
        if(pstaticthis!=NULL)
        {
            if(p_dvr->mCameraId<SUPPORT_CAMERA_NUM)
            {
                if(pstaticthis->dvrCamera[p_dvr->mCameraId].getRecord())
                    pstaticthis->dvrCamera[p_dvr->mCameraId].setRecord(false);//this is needed ,usrs must sync this ctrl status by self
            }else
            {
                int i;
                for(i=0;i<SUPPORT_CAMERA_NUM;i++){
                    if(p_dvr->mCameraId==pstaticthis->dvrCamera[i].dvr->mCameraId){
                        if(pstaticthis->dvrCamera[i].getRecord())
                            pstaticthis->dvrCamera[i].setRecord(false);//this is needed ,usrs must sync this ctrl status by self
                    }
                }
            }
        }

    }
    //return NO_ERROR;

}

static void userdataCallback(int32_t msgType,
                      char* dataPtr, camera_frame_metadata_t *metadata, void* user)
{
    if ((msgType&CAMERA_MSG_VIDEO_FRAME) ==CAMERA_MSG_VIDEO_FRAME)
    {
        ALOGV("now msgtype is 1-%d", msgType);
    }
    if ((msgType&CAMERA_MSG_PREVIEW_FRAME) ==CAMERA_MSG_PREVIEW_FRAME)
    {
//        ALOGV("now msgtype is 2-%d timestam = %d", msgType,  nsStamp);
    }
    if ((msgType&CAMERA_MSG_POSTVIEW_FRAME) ==CAMERA_MSG_POSTVIEW_FRAME)
    {
        ALOGV("now msgtype is 3-%d", msgType);
    }
    if ((msgType&CAMERA_MSG_RAW_IMAGE) ==CAMERA_MSG_RAW_IMAGE)
    {
        ALOGV("now msgtype is 4-%d", msgType);
    }

    if ((msgType&CAMERA_MSG_COMPRESSED_IMAGE) ==CAMERA_MSG_COMPRESSED_IMAGE)
    {
        ALOGV("now msgtype is 5-%d", msgType);
    }
    char *p = (char *)dataPtr;
    VencInputBuffer *pImage = (VencInputBuffer *)(p +4);


//    dvr_factory *pdvr = (dvr_factory *)user;
//    char bufname[512];
//    sprintf(bufname,"64,64,0,64,250,123456 SDK,64,450,haha V1 alpha");
//    pdvr->enableWaterMark();
//    pdvr->setWaterMarkMultiple(bufname);
//    if(p != NULL)
//    {
//        int time = metadata->faces->id;
//    }
//    ALOGV("now timestamp is %d", msgType);


//    V4L2BUF_t *pAlgImg = (V4L2BUF_t *)p;
//    ALOGV("the frame in us %f", pAlgImg->timeStamp);

//    if(msgType & CAMERA_MSG_COMPRESSED_IMAGE)
//    {
//        ALOGV("store picture us time %p us size = %d",dataPtr, metadata->number_of_faces );
//    }


//    inputBuffer.pAddrPhyY = (unsigned char*)malloc(1280*720);
//    memset(inputBuffer.pAddrPhyY, 64, 1280*720);
//    dvr_factory *p_dvr=(dvr_factory *)user;
//    char *ptp = (char *)dataPtr;
//    VencInputBuffer *p = (VencInputBuffer *)(ptp +4);//all 10, this means only 10-4=6 farame be used
//    memcpy(inputBuffer.pAddrVirY,(unsigned char*)p->pAddrVirY,1280*720);
//    memcpy(inputBuffer.pAddrVirC,(unsigned char*)p->pAddrVirY+encode_param.src_width*encode_param.src_height,encode_param.src_width*encode_param.src_height/2);

    //this is for our own callback to process yuv data that from the v4l2buf.

    //return NO_ERROR;
}


static char bufname1[512];

//static struct mymesg *mesg = (struct mymesg *)malloc(sizeof(struct mymesg));
int queDepth = 0;
static QMutex m_algMesgMutex ;


static void userdataCallbackTimestamp(nsecs_t timestamp,
                               int32_t msgType, char* dataPtr, void* user)
{
    if(pstaticthis != NULL)
    {

        pstaticthis->CPlayCallbackTimestamp(timestamp, msgType, dataPtr, user);
//        qDebug() << "userdataCallbackTimestamp------" << QThread::currentThread();

    }
}

//for preview SetDataCB
static status_t usr_h264datacb(int32_t msgType,
                        char *dataPtr,int dalen,
                        void *user)
{


}


//for rtsp set SetDataCB0
static status_t usr_datacb(int32_t msgType,
                           char *dataPtr,int dalen,
                           void *user)
{

    //LOGE("===========msgType =%d-----dataPtr=%p-----dalen %d)",msgType,dataPtr,dalen);
    if (send_sock_rtsp_0 != -1)
    {
        if (connect_0_once == 0) {
            send_h264_header(send_sock_rtsp_0);
            connect_0_once = 1;
            LOGE("===========   connect streamer 0 !\n");
        }


        tFrameHead header;
        header.bySync = FRAME_HEAD_SYNC;
        header.byType = FRAME_DATA_TYPE;
        header.dwDataLen = dalen;

        int send_length;
        send_length = send(send_sock_rtsp_0, &header, sizeof(header), 0);
        if (send_length != sizeof(header))
        {
            //			printf("send data fail\n");
            LOGE("send data head fail eager %d real %d\n", sizeof(header), send_length);
            return 0;
        }

        send_length = send(send_sock_rtsp_0, dataPtr, header.dwDataLen, 0);

        int data_length = header.dwDataLen;
        while(send_length < data_length)
        {
            int ret;
            ret = send(send_sock_rtsp_0, dataPtr+send_length, data_length - send_length, 0);
            if(ret < 0)
            {
                perror("send stream rtsp data");
                break;
            }
            else if(ret == 0)
            {
                break;
            }
            else
            {
                send_length += ret;
            }
        }

    }
    return 0;
}


static status_t usr_datacb_1(int32_t msgType,
                      char *dataPtr,int dalen,
                      void *user)
{
    if (send_sock_rtsp_1 != -1)
    {
        //		LOGE("===========   connect send_sock_rtsp_1 !\n");

        if (connect_1_once == 0) {
            send_h264_header(send_sock_rtsp_1);
            connect_1_once = 1;
            LOGE("===========   connect streamer 1 !\n");
        }

        tFrameHead header;
        header.bySync = FRAME_HEAD_SYNC;
        header.byType = FRAME_DATA_TYPE;
        header.dwDataLen = dalen;
        int send_length;
        send_length = send(send_sock_rtsp_1, &header, sizeof(header), 0);
        if (send_length != sizeof(header))
        {
            //			printf("send data fail\n");
            LOGE("send data head fail eager %d real %d\n", sizeof(header), send_length);
            return 0;
        }

        send_length = send(send_sock_rtsp_1, dataPtr, header.dwDataLen, 0);

        int data_length = header.dwDataLen;
        while(send_length < data_length)
        {
            int ret;
            ret = send(send_sock_rtsp_1, dataPtr+send_length, data_length - send_length, 0);
            if(ret < 0)
            {
                perror("send stream rtsp data");
                break;
            }
            else if(ret == 0)
            {
                break;
            }
            else
            {
                send_length += ret;
            }
        }
    }


}

#endif

#define HEIGHT 720
#define WEITH  1280


CPlayWindow::CPlayWindow(QWidget *parent)
    : QWidget(parent)
{
    CPlayInit();

    for(int i = 0; i < 30; i++)
    {
        m_IMGYData[i].mid = i;
        m_IMGYData[i].data = (uchar *)malloc(1280*720);
        m_IMGYData[i].mrwFlag = 0;
        m_IMGYData[i].stamp = 0;
    }
    m_ImageAlg = QImage(1280, 720, QImage::Format_Indexed8);
    for(int i = 0; i < 255; i++)
    {
        m_grayTable.push_back(qRgb(i, i, i));
    }
    m_ImageAlg.setColorTable(m_grayTable);


}

CPlayWindow::~CPlayWindow()
{
    qDebug("~Play--------------\r\n");

    #if defined(Q_OS_LINUX)
    //delete dvr;
    int i;
    for(i=0;i<SUPPORT_CAMERA_NUM;i++)
        delete dvrCamera[i].dvr;
    if(pgEmulatedCameraFactory != NULL)
    {
        delete pgEmulatedCameraFactory;
        pgEmulatedCameraFactory = NULL;
    }

//    OSAL_QueueTerminate(&m_alarmTimeStamp);
    OSAL_QueueTerminate(&m_imageDataQue);
    SeqQueue_Destroy(m_queue);

    for(int i = 0; i < 30; i++)
    {
        free(m_IMGYData[i].data);
        m_IMGYData[i].data = NULL;

    }
//    if(m_imageBuffer != NULL && m_imageBuffer->pAlgC != NULL && m_imageBuffer->pAlgY != NULL)
//    {
//        free(m_imageBuffer->pAlgC);
//        m_imageBuffer->pAlgC = NULL;
//        free(m_imageBuffer->pAlgY);
//        m_imageBuffer->pAlgY = NULL;
//        free(m_imageBuffer);
//        m_imageBuffer = NULL;
//    }

    #endif
}

void CPlayWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    QFont mfont;

    QPen pen;
    pen.setWidth(5);
    mfont.setPointSize(24);

    painter.setPen(pen);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setFont(mfont);

    painter.setPen(QColor(255, 255, 255));

    android::Mutex::Autolock lock(&mDisplayLock);
    m_ImageOrigin = QImage((uchar *)&m_ImgWithStamp.mImageData, 1280, 720, QImage::Format_Indexed8);
    m_ImageAlg = QImage((uchar *)&CPlayWindow::m_ImgScale.mImageData, 1280, 720, QImage::Format_Indexed8);

    m_ImageOrigin.setColorTable(m_grayTable);
    m_ImageAlg.setColorTable(m_grayTable);

    qlonglong stamp = m_ImgWithStamp.stamp/1000;
    QString strstamp = QString::number(stamp);

    QPixmap pixalg, pixorigin;
//    pix.load(":/images/image/home.png");
    pixorigin = QPixmap::fromImage(m_ImageOrigin);
    pixalg = QPixmap::fromImage(m_ImageAlg);


//    painter.drawPixmap(100,100,640,360, pix);
    painter.drawPixmap(480,100,320,180, pixorigin);
    painter.drawPixmap(100,100,320,180, pixalg);

    painter.drawText(480, 200, strstamp);

//    QImage img = QImage((uchar *)m_ImageAlgDat, 1280, 720, QImage::Format_Indexed8);
//    QImage imgtmp = img.scaled(this->ui.label_algVideo->width(), this->ui.label_algVideo->height(), Qt::KeepAspectRatio);

//    QPixmap bgPic;
//    bgPic.load(":/images/image/home.png");
//    painter.drawPixmap(0, 0, this->ui.label_algVideo->width(), this->ui.label_algVideo->height(), bgPic);

//    painter.drawImage(0, 0, m_ImageAlg);


//    qDebug() << "paint update ------------------------------";

}

void CPlayWindow::CPlayInit()
{
//    QPushButton *button = new QPushButton("play()", this);
    memset(m_ImgWithStamp.mImageData, 0, 1280*720);

    m_ImgWithStamp.stamp = 0;
//    memset(m_ImgScale.mImageData, 0, 1280*720);
//    m_ImgScale.stamp = 0;
//    QPainter painter(this->ui.label_algVideo);
    ui.setupUi(this);
//    QPixmap bgPic;
//    bgPic.load(":/images/image/home.png");
//    painter.drawPixmap(0, 0, this->ui.label_algVideo->width(), this->ui.label_algVideo->height(), bgPic);

//    OSAL_QueueCreate(&m_alarmTimeStamp, 96);
    OSAL_QueueCreate(&m_imageDataQue, MAXBUFFER);

    m_queue = SeqQueue_Create(MAXBUFFER);

    m_algProcessModule = new IVFDAlgProcessModule(0);


//    emit m_algProcessModule->SIG_StartAlgProcess(&m_imageDataQue);
    emit m_algProcessModule->SIG_StartAlgProcess(m_queue);


    setProperty("noinput",false);//true?
    isaf=false;

    this->setAttribute(Qt::WA_TranslucentBackground,false);//true
#if defined(Q_OS_LINUX)
    //old
    //    HwDisplay* mcd=NULL;
    //    //test screen mode
    //    //0 disable
    //    int tvmode=0;
    //    //config_set_tvout(0,tvmode);
    //    mcd=HwDisplay::getInstance();
    //    tvmode=config_get_tvout(0);
    //    printf("--------------tvmode =%d \r\n",tvmode);
    //    mcd->hwd_screen1_mode(tvmode);
    //    //mcd->hwd_tvout();
    //old
    HwDisplay* mcd=NULL;
    //test screen mode
    //0 disable
    int tvmode = 3;
    config_set_tvout(0,tvmode);
    mcd=HwDisplay::getInstance();
    tvmode = config_get_tvout(0);
    printf("--------------tvmode =%d \r\n",tvmode);
    mcd->hwd_screen1_mode(tvmode);
    cur_camera = 0 ;
    pgEmulatedCameraFactory = new HALCameraFactory();
    //sleep(4);
    int i;
    for(i=0;i<SUPPORT_CAMERA_NUM;i++)
    {
        dvrCamera[i].dvr=new dvr_factory();
    }
#endif

    QObject::connect(ui.pushButton_preview, SIGNAL(clicked()), this, SLOT(SLOT_BtnPreview()));
    QObject::connect(ui.pushButton_stop, SIGNAL(clicked()), this, SLOT(SLOT_BtnStop()));
    QObject::connect(ui.pushButton_switch, SIGNAL(clicked()), this, SLOT(SLOT_BtnSwitch()));

    QObject::connect(ui.pushButton_cam1, SIGNAL(clicked()), this, SLOT(SLOT_BtnCam0()));

    QObject::connect(ui.pushButton_cam2, SIGNAL(clicked()), this, SLOT(SLOT_BtnCam1()));
    QObject::connect(ui.pushButton_return, SIGNAL(clicked()), this, SLOT(SLOT_BtnReturn()));

    QObject::connect(this, SIGNAL(SIG_PlaySwitch()), this, SLOT(SLOT_BtnSwitch()));
    QObject::connect(ui.pushButton_rtsp1, SIGNAL(clicked()), this, SLOT(SLOT_BtnRtsp1()));
    QObject::connect(ui.pushButton_rtsp2, SIGNAL(clicked()), this, SLOT(SLOT_BtnRtsp2()));
    QObject::connect(ui.pushButton_rtspsw, SIGNAL(clicked()), this, SLOT(SLOT_BtnRtspSwitch()));
    QObject::connect(this, SIGNAL(SIG_RtspSwitch()), this, SLOT(SLOT_BtnRtspSwitch()));
    QObject::connect(this, SIGNAL(SIG_StopRtsp1()), this, SLOT(SLOT_StopRtsp1()));
    QObject::connect(this, SIGNAL(SIG_GetTimeStamp0()), this, SLOT(SLOT_GetTimeStamp0()));


    printf("Play----------%p----\r\n",this);
    pstaticthis=this;//fucking bad,single obj only
}


void CPlayWindow::startRecord()
{
#if defined(Q_OS_LINUX)
    //int cycltime;
    char bufname[512];
   // int cx,cy;
    printf("startRecord--------------\r\n");
    android::Mutex::Autolock locker(&mObjectLock);

    dvr_factory * p_dvr;//=dvrCamera[i].dvr;
    int i;
    for(i=0;i<SUPPORT_CAMERA_NUM;i++)
    {
        p_dvr=dvrCamera[i].dvr;
        printf("get camera startup flag=%d \r\n",config_get_startup(i));
        if(1==config_get_startup(i))
        {
            if(dvrCamera[i].getPreview()){
                p_dvr->startRecord();
                isaf=true;
                dvrCamera[i].setRecord(true);
            }else{
                int rt ;
                if(dvrCamera[i].getRecord())
                 {continue ;}
            #ifdef USE_AW_360
                //config_set_heigth(360,960);
                //config_set_weith(360,1440);
                rt= p_dvr->recordInit("360");
            #else
                //config_set_heigth(0,720);
                //config_set_weith(0,1280);
                sprintf(bufname,"camera %d",i);
                rt= p_dvr->recordInit(bufname);
            #endif
                if(rt <0){
                    printf("init record fail camera[%s] ret =%d \r\n",bufname,rt);
                    continue;
                }
                p_dvr->SetDataCB(usr_h264datacb,p_dvr);
                p_dvr->setCallbacks(usernotifyCallback,userdataCallback,userdataCallbackTimestamp,p_dvr/* must dvr obj*/ /*dump*/);
                //dvr->prepare();
                p_dvr->start();
//                p_dvr->disableWaterMark();
#ifdef WATERMARKORI
                p_dvr->enableWaterMark();
                sprintf(bufname,"64,64,0,64,250,BandWeaver SDK,64,450,ASTEROID V1 alpha");
                p_dvr->setWaterMarkMultiple(bufname);
#endif
        #ifdef SUPPORT_RTSP
                p_dvr->set_rtsp_to_file(0);//test !!!! if 1 wirite to encode stream to file . must start before start_rtsp

                p_dvr->start_rtsp();
        #endif
                p_dvr->startRecord();
                isaf = true;
                dvrCamera[i].setRecord(true);
            }
        }
    }

#endif
}


int CPlayWindow::startAllCameraWithPreview(int camera_no /* nouse now*/)
{
    //sp<CameraHardwareInterface>     mHardware;
    printf("startAllCameraWithPreview play %p\r\n",this);
    camera_no=camera_no;
    cur_camera = camera_no;
#if defined(Q_OS_LINUX)
   startRecord();
   printf("startAllCameraWithPreview play %d\r\n",cur_camera);
   dvr_factory *p_dvr=dvrCamera[cur_camera].dvr;
   ALOGV("cur_camera = %d getpreview = %s getrecord = %s", cur_camera, dvrCamera[cur_camera].getPreview()==false?"FALSE":"TRUE",dvrCamera[cur_camera].getRecord()==false?"FALSE":"TRUE");

    if((!dvrCamera[cur_camera].getPreview())&&(dvrCamera[cur_camera].getRecord()))
    {
        ALOGV("cur_camera = %d getpreview = %s getrecord = %s", cur_camera, dvrCamera[cur_camera].getPreview()==false?"FALSE":"TRUE",dvrCamera[cur_camera].getRecord()==false?"FALSE":"TRUE");
        struct view_info vv= {340,0,VIEW_WEITH,VIEW_HEIGHT};
//        ALOGV("vx=%d vy=%d sx=%d sy%d",mcd->lcdxres,mcd->lcdyres,dvr->recordwith,dvr->recordheith);
        p_dvr->startPriview(vv);
        #ifdef AAA
        setStyleSheet(QStringLiteral("background-color: rgba(112, 200, 11, 0);"));
#endif
        dvrCamera[cur_camera].setPreview(true);
    }

#endif
    return 0;
}




void CPlayWindow::videoshow()
{
    //on_pushButton_play_clicked();
    qDebug() << "current camera is:----";
    startAllCameraWithPreview(0);
}

void CPlayWindow::startCurCamera()
{

}

void CPlayWindow::stopRecord()
{


}

void CPlayWindow::startRtspServer1(int num)
{
    qDebug() << "start RtspServer------" << num << QThread::currentThread();

    HwDisplay* mcd=NULL;
    //test screen mode
    //0 disable ,1 tvout pal ;2 tvout ntsc;3 hdmi 1280x720;4 hdmi 1920x1080
    int tvmode=3;
    //config_set_tvout(TEST_CAMERA_ID,tvmode);

    mcd=HwDisplay::getInstance();

//    pgEmulatedCameraFactory=new HALCameraFactory();
    //sleep(4);
    dvr_factory *pdvr=dvrCamera[0].dvr;
//    pdvr=new dvr_factory();

    //int result;

    tvmode=config_get_tvout(TEST_CAMERA_ID);
    printf("--------------tvmode =%d \r\n",tvmode);
    mcd->hwd_screen1_mode(tvmode);//for dual disp at the same time

    int i=1;
    int flag360=0;
    printf("get bootup param 1st is %d \r\n",config_get_startup(0));
    config_set_startup(TEST_CAMERA_ID,1);
    printf("get bootup param 2nd is %d \r\n",config_get_startup(0));
    config_set_startup(TEST_CAMERA_ID,0);
    printf("get bootup param 3rd is %d \r\n",config_get_startup(0));
    //aut_adb_main(0, 0);

//int cycltime;
    char bufname[512];
     int rt ;
//int cx,cy;
    while(i>0)
    {
        i--;

//#ifdef USE_AW_360
        if(flag360){
            #ifdef DEFAULT_CVBS_CAMERA_TYPE_PAL
                config_set_heigth(360,1152);//1152 pal
            #else
                config_set_heigth(360,960);//960 ntsc
            #endif
                   config_set_weith(360,1440);
                   rt= pdvr->recordInit("360");

        }else{
//#else
                   config_set_heigth(TEST_CAMERA_ID,720);//720
                   config_set_weith(TEST_CAMERA_ID,1280);//1280
                   rt= pdvr->recordInit("0");
                   #ifdef ANOTHER_CAMERA_TEST
                   config_set_heigth(1,720);//720
                   config_set_weith(1,1280);//1280
                   rt= pdvr1->recordInit("1");
                   #endif
        }
//#endif

        if(rt!=0)
        {
            sleep(1);
            continue;
        }

        pdvr->SetDataCB(usr_datacb,pdvr);
        pdvr->setCallbacks(usernotifyCallback,userdataCallback,userdataCallbackTimestamp,pdvr /*dump*/);
        pdvr->prepare();
        pdvr->start();
//        pdvr->disableWaterMark();
#ifdef WATERMARKORI
        pdvr->enableWaterMark();
        sprintf(bufname,"18,18,0,720,18,CAPTURE COLOR,1000,18,IVFD V2_0a");
        pdvr->setWaterMarkMultiple(bufname);
#endif
        //dvr.set_rtsp_to_file(0);//test !!!! if 1 wirite to encode stream to file . must start before start_rtsp
        //dvr.start_rtsp(); //not support now

        //vv for viewer's view
       // struct view_info vv= {0,0,mcd->lcdxres,mcd->lcdyres};
        struct view_info vv= {0,0,720,480};
        ALOGV("vx=%d vy=%d sx=%d sy%d",mcd->lcdxres,mcd->lcdyres,pdvr->recordwith,pdvr->recordheith);
        pdvr->startPriview(vv);


#ifdef RECORD_TEST
        pdvr->startRecord();
#endif

//	sleep(60);
// by wangnc
#ifdef 	WANGGY
    int result = 0;
    pthread_t tid_lock_socket;
    pthread_t tid_send_h264;

    printf("start!\n");

    pthread_create(&tid_lock_socket, NULL, thread_local_socket, NULL);

    while(1) {
        sleep(1);
    }
    pthread_detach(tid_lock_socket);
    pthread_join(tid_lock_socket, (void**)&result);
    //for imageprocess




#else
    sleep(800);
#endif

#ifdef RECORD_TEST
        pdvr->stopRecord();
#endif
        F_LOG;
        pdvr->stop();
        F_LOG;
        pdvr->enc_de_init();
        F_LOG;
        pdvr->uninitializeDev();
        F_LOG;
        sleep(2); //now this needed fix next version
        //pthread_create();
    }
    delete pdvr;
//    delete pgEmulatedCameraFactory;
    return ;
}

void CPlayWindow::startRtspServer2(int num)
{
    qDebug() << "start RtspServer------" << num << QThread::currentThread();
//old
//    HwDisplay* mcd=NULL;
//    //test screen mode
//    //0 disable ,1 tvout pal ;2 tvout ntsc;3 hdmi 1280x720;4 hdmi 1920x1080
//    int tvmode=3;
//    //config_set_tvout(TEST_CAMERA_ID,tvmode);
//    mcd=HwDisplay::getInstance();
//    tvmode=config_get_tvout(TEST_CAMERA_ID);
//    printf("--------------tvmode =%d \r\n",tvmode);
//    mcd->hwd_screen1_mode(tvmode);//for dual disp at the same time
//old


    HwDisplay* mcd=NULL;
    //test screen mode
    //0 disable ,1 tvout pal ;2 tvout ntsc;3 hdmi 1280x720;4 hdmi 1920x1080
    int tvmode=3;
    //config_set_tvout(TEST_CAMERA_ID,tvmode);
    mcd=HwDisplay::getInstance();
    tvmode=config_get_tvout(TEST_CAMERA_ID);
    printf("--------------tvmode =%d \r\n",tvmode);
    mcd->hwd_screen1_mode(tvmode);//for dual disp at the same time

//    pgEmulatedCameraFactory=new HALCameraFactory();
//    sleep(4);
    dvr_factory *pdvr=dvrCamera[1].dvr;
//    pdvr=new dvr_factory();

    //int result;



    int i=1;
    int flag360=0;
    printf("get bootup param 1st is %d \r\n",config_get_startup(1));
    config_set_startup(TEST_CAMERA_ID2,1);
    printf("get bootup param 2nd is %d \r\n",config_get_startup(1));
    config_set_startup(TEST_CAMERA_ID2,0);
    printf("get bootup param 3rd is %d \r\n",config_get_startup(1));
    //aut_adb_main(0, 0);

//int cycltime;
    char bufname[512];
     int rt ;
//int cx,cy;
    while(i>0)
    {
        i--;

//#ifdef USE_AW_360
        if(flag360){
            #ifdef DEFAULT_CVBS_CAMERA_TYPE_PAL
                config_set_heigth(360,1152);//1152 pal
            #else
                config_set_heigth(360,960);//960 ntsc
            #endif
                   config_set_weith(360,1440);
                   rt= pdvr->recordInit("360");

        }else{
//#else
                   config_set_heigth(TEST_CAMERA_ID2,720);//720
                   config_set_weith(TEST_CAMERA_ID2,1280);//1280
                   rt= pdvr->recordInit("1");
                   #ifdef ANOTHER_CAMERA_TEST
                   config_set_heigth(1,720);//720
                   config_set_weith(1,1280);//1280
                   rt= pdvr1->recordInit("1");
                   #endif
        }
//#endif

        if(rt!=0)
        {
            sleep(1);
            continue;
        }

        pdvr->SetDataCB(usr_datacb,pdvr);
        pdvr->setCallbacks(usernotifyCallback,userdataCallback,userdataCallbackTimestamp,pdvr /*dump*/);
        pdvr->prepare();
        pdvr->start();
//        pdvr->disableWaterMark();
#ifdef WATERMARKORI
        pdvr->enableWaterMark();
        sprintf(bufname,"18,18,0,720,18,CAPTURE MONO,1000,18,IVFD V2_0a");
        pdvr->setWaterMarkMultiple(bufname);
#endif
        //dvr.set_rtsp_to_file(0);//test !!!! if 1 wirite to encode stream to file . must start before start_rtsp
        //dvr.start_rtsp(); //not support now

        //vv for viewer's view
       // struct view_info vv= {0,0,mcd->lcdxres,mcd->lcdyres};
        struct view_info vv= {0,0,720,480};
        ALOGV("vx=%d vy=%d sx=%d sy%d",mcd->lcdxres,mcd->lcdyres,pdvr->recordwith,pdvr->recordheith);
        pdvr->startPriview(vv);


#ifdef RECORD_TEST
        pdvr->startRecord();
#endif

//	sleep(60);
// by wangnc
#ifdef 	WANGGY
    int result = 0;
    pthread_t tid_lock_socket;
    pthread_t tid_send_h264;

    printf("start!\n");

    pthread_create(&tid_lock_socket, NULL, thread_local_socket, NULL);

    while(1) {
        sleep(1);
    }
    pthread_detach(tid_lock_socket);
    pthread_join(tid_lock_socket, (void**)&result);
#else
    sleep(800);
#endif

#ifdef RECORD_TEST
        pdvr->stopRecord();
#endif
        F_LOG;
        pdvr->stop();
        F_LOG;
        pdvr->enc_de_init();
        F_LOG;
        pdvr->uninitializeDev();
        F_LOG;
        sleep(2); //now this needed fix next version
        //pthread_create();
    }
    delete pdvr;
//    delete pgEmulatedCameraFactory;
    sleep(10);
    return ;
}

void CPlayWindow::switchRtspServer()
{

#if 1
    qDebug() << "current camera is:" << cur_camera << "---------switch the camera";
#if defined(Q_OS_LINUX)

    if(SUPPORT_CAMERA_NUM<2)
        return;
    dvr_factory* p_dvr0;
    dvr_factory* p_dvr1;
    int cam0 = 0;
    int cam1 = 1;
    p_dvr0=dvrCamera[0].dvr;
    if(dvrCamera[0].getPreview()){
        p_dvr0->stopPriview();
        dvrCamera[0].setPreview(false);
    }
    p_dvr0 = dvrCamera[0].dvr;
    printf("get bootup param 1st is %d \r\n",config_get_startup(0));
    config_set_startup(0,1);
    printf("get bootup param 2nd is %d \r\n",config_get_startup(0));
    config_set_startup(0,0);
    printf("get bootup param 3rd is %d \r\n",config_get_startup(0));
    //aut_adb_main(0, 0);

    char bufname[512];
    int rt;
    int i = 1;
    int flag360 = 0;
    while(i>0)
    {
        i--;
        if(!dvrCamera[cam0].getRecord())
        {
            int rt ;
#ifdef USE_AW_360
            config_set_heigth(360,960);
            config_set_weith(360,1440);
            rt= p_dvr0->recordInit("360");
#else
            //config_set_heigth(0,720);
            //config_set_weith(0,1280);
            sprintf(bufname,"%d",0);
            rt= p_dvr0->recordInit(bufname);

            config_set_heigth(0, 720);//720
            config_set_weith(0, 1280);//1280

            rt= p_dvr1->recordInit("1");


#endif
            //            if(rt <0)
            //                return;

            if(rt!=0)
            {
                sleep(1);
                continue;
            }
            p_dvr0->SetDataCB(usr_datacb,p_dvr0);
            p_dvr0->setCallbacks(usernotifyCallback,userdataCallback,userdataCallbackTimestamp,p_dvr0 /*dump*/);

            p_dvr0->prepare();
            p_dvr0->start();
#ifdef WATERMARKORI
            //            p_dvr0->disableWaterMark();
            p_dvr0->enableWaterMark();
            sprintf(bufname,"64,64,0,64,250,CAPTURE SDK,64,450,IVFD V2.0a");
            p_dvr0->setWaterMarkMultiple(bufname);
#endif
#ifdef AAA
            setStyleSheet(QStringLiteral("background-color: rgba(112, 200, 11, 0);"));
#endif
#ifdef SUPPORT_RTSP
            p_dvr0->set_rtsp_to_file(0);//test !!!! if 1 wirite to encode stream to file . must start before start_rtsp
            p_dvr0->start_rtsp();
#endif
            p_dvr0->startRecord();
            isaf=true;
            dvrCamera[0].setRecord(true);
        }

        if(!dvrCamera[0].getPreview())
        {
            struct view_info vv= {0,0,VIEW_WEITH,VIEW_HEIGHT};

            p_dvr0->startPriview(vv);
#ifdef AAA
            setStyleSheet(QStringLiteral("background-color: rgba(112, 200, 11, 0);"));
#endif
            dvrCamera[0].setPreview(true);
        }
        sleep(1);//temp add here,must use timestamp for response gap,i will impl next version



#ifdef RECORD_TEST
        p_dvr0->startRecord();
#endif

#ifdef RTSPENABLE

        pthread_t tid_lock_socket_0;
//        pthread_t tid_lock_socket_1;
        int streamnum0 = 0;
//        int streamnum1 = 1;

        pthread_attr_t attr;
        pthread_attr_init(&attr);
        pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

        printf("start!\n");
        pthread_create(&tid_lock_socket_0, &attr, thread_local_socket, &streamnum0);
//        pthread_create(&tid_lock_socket_1, &attr, thread_local_socket, &streamnum1);
        pthread_detach(tid_lock_socket_0);
//        pthread_detach(tid_lock_socket_1);
#endif
        sleep(1);
    }
#endif
#endif
    return ;
}


void CPlayWindow::SLOT_BtnPreview()
{
    qDebug() << "privew";
    videoshow();
    ui.pushButton_preview->setDisabled(true);
}

void CPlayWindow::SLOT_BtnStop()
{

    qDebug() << "stop";
    ui.pushButton_preview->setEnabled(true);
    printf("camera stop \r\n");
    if(isaf)
    {
#ifdef AAA
        setStyleSheet(QStringLiteral("background-color: rgb(112, 200, 11);"));
#endif
        isaf=false;
    }
#if defined(Q_OS_LINUX)
    android::Mutex::Autolock locker(&mObjectLock);
    dvr_factory * p_dvr;
    int i;
    for(i=0;i<SUPPORT_CAMERA_NUM;i++)
    {
        p_dvr=dvrCamera[i].dvr;
        if(dvrCamera[i].getRecord()||dvrCamera[i].getPreview())
        {
            printf("camera stop ----\r\n");
    #ifdef SUPPORT_RTSP
            p_dvr->stop_rtsp();
    #endif
            if(dvrCamera[i].getPreview())
            {
                p_dvr->stopPriview();
                //isPreview=false;
                dvrCamera[i].setPreview(false);
            }

            if(dvrCamera[i].getRecord())
            {
                p_dvr->stopRecord();
                //isRecord=false;
                dvrCamera[i].setRecord(false);
            }

            p_dvr->stop();
            p_dvr->enc_de_init();
            p_dvr->uninitializeDev();

            //isRecord=false;
            //isPreview=false;
            dvrCamera[i].setPreview(false);
            dvrCamera[i].setRecord(false);
        }
    }
#endif

}

void CPlayWindow::SLOT_BtnSwitch()
{

    qDebug() << "current camera is:" << cur_camera << "---------switch the camera";

#if defined(Q_OS_LINUX)
    if(SUPPORT_CAMERA_NUM<2)
        return;
    dvr_factory * p_dvr=dvrCamera[cur_camera].dvr;
    if(dvrCamera[cur_camera].getPreview()){
        p_dvr->stopPriview();
        dvrCamera[cur_camera].setPreview(false);
    }
    cur_camera = (cur_camera==0)?1:0;

    //int cycltime;
    char bufname[512];
    //int cx,cy;
    bool rt;
    p_dvr=dvrCamera[cur_camera].dvr;
    if(!dvrCamera[cur_camera].getRecord())
    {
           int rt ;
        #ifdef USE_AW_360
            config_set_heigth(360,960);
            config_set_weith(360,1440);
            rt= p_dvr->recordInit("360");
        #else
            //config_set_heigth(0,720);
            //config_set_weith(0,1280);
            sprintf(bufname,"%d",cur_camera);
            rt= p_dvr->recordInit(bufname);
        #endif
            if(rt <0)
                return;
            p_dvr->SetDataCB(usr_h264datacb,p_dvr);

            //dvr->prepare();
            p_dvr->start();
//            p_dvr->disableWaterMark();
#ifdef WATERMARKORI
            p_dvr->enableWaterMark();
            sprintf(bufname,"64,64,0,64,250,CAPTURE SDK,64,450,IVFD V2.0a");
            p_dvr->setWaterMarkMultiple(bufname);
#endif
    #ifdef AAA
            setStyleSheet(QStringLiteral("background-color: rgba(112, 200, 11, 0);"));
    #endif
    #ifdef SUPPORT_RTSP
            p_dvr->set_rtsp_to_file(0);//test !!!! if 1 wirite to encode stream to file . must start before start_rtsp
            p_dvr->start_rtsp();
    #endif
            p_dvr->startRecord();
            isaf=true;
            dvrCamera[cur_camera].setRecord(true);
    }


    if(!dvrCamera[cur_camera].getPreview())
    {
        struct view_info vv= {0,0,VIEW_WEITH,VIEW_HEIGHT};
        //ALOGV("vx=%d vy=%d sx=%d sy%d",mcd->lcdxres,mcd->lcdyres,dvr->recordwith,dvr->recordheith);
        p_dvr->startPriview(vv);
        #ifdef AAA
        setStyleSheet(QStringLiteral("background-color: rgba(112, 200, 11, 0);"));
#endif

        dvrCamera[cur_camera].setPreview(true);
    }
    sleep(1);//temp add here,must use timestamp for response gap,i will impl next version
#endif


}

void CPlayWindow::SLOT_BtnCam0()
{
    qDebug() << "start cam0 capture" ;

#if defined(Q_OS_LINUX)
    if(SUPPORT_CAMERA_NUM<2)
        return;
    dvr_factory * p_dvr=dvrCamera[1].dvr;
    if(dvrCamera[1].getPreview()){
        p_dvr->stopPriview();
        dvrCamera[1].setPreview(false);
    }

    //int cycltime;
    char bufname[512];
    //int cx,cy;
    bool rt;
    p_dvr=dvrCamera[0].dvr;
    if(!dvrCamera[0].getRecord())
    {
           int rt ;
        #ifdef USE_AW_360
            config_set_heigth(360,960);
            config_set_weith(360,1440);
            rt= p_dvr->recordInit("360");
        #else
            //config_set_heigth(0,720);
            //config_set_weith(0,1280);
            sprintf(bufname,"%d",0);
            rt= p_dvr->recordInit(bufname);
        #endif
            if(rt <0)
                return;
            p_dvr->SetDataCB(usr_h264datacb,p_dvr);

            //dvr->prepare();
            p_dvr->start();
//            p_dvr->disableWaterMark();
#ifdef WATERMARKORI
            p_dvr->enableWaterMark();
            sprintf(bufname,"64,64,0,64,250,CAMERA0 SDK,64,450,IVFD V2.0a");
            p_dvr->setWaterMarkMultiple(bufname);
#endif
    #ifdef AAA
            setStyleSheet(QStringLiteral("background-color: rgba(112, 200, 11, 0);"));
    #endif
    #ifdef SUPPORT_RTSP
            p_dvr->set_rtsp_to_file(0);//test !!!! if 1 wirite to encode stream to file . must start before start_rtsp
            p_dvr->start_rtsp();
    #endif
            p_dvr->startRecord();
            isaf=true;
            dvrCamera[0].setRecord(true);
    }


    if(!dvrCamera[0].getPreview())
    {
        struct view_info vv= {0,0,VIEW_WEITH,VIEW_HEIGHT};
        //ALOGV("vx=%d vy=%d sx=%d sy%d",mcd->lcdxres,mcd->lcdyres,dvr->recordwith,dvr->recordheith);
        p_dvr->startPriview(vv);
        #ifdef AAA
        setStyleSheet(QStringLiteral("background-color: rgba(112, 200, 11, 0);"));
#endif

        dvrCamera[0].setPreview(true);
    }
    sleep(1);//temp add here,must use timestamp for response gap,i will impl next version
#endif

}


void CPlayWindow::SLOT_BtnCam1()
{
    qDebug() << "start cam1 capture" ;

#if defined(Q_OS_LINUX)
    if(SUPPORT_CAMERA_NUM<2)
        return;
    dvr_factory * p_dvr=dvrCamera[0].dvr;
    if(dvrCamera[0].getPreview()){
        p_dvr->stopPriview();
        dvrCamera[0].setPreview(false);
    }

    //int cycltime;
    char bufname[512];
    //int cx,cy;
    bool rt;
    p_dvr=dvrCamera[1].dvr;
    if(!dvrCamera[1].getRecord())
    {
           int rt ;
        #ifdef USE_AW_360
            config_set_heigth(360,960);
            config_set_weith(360,1440);
            rt= p_dvr->recordInit("360");
        #else
            //config_set_heigth(0,720);
            //config_set_weith(0,1280);
            sprintf(bufname,"%d",1);
            rt= p_dvr->recordInit(bufname);
        #endif
            if(rt <0)
                return;
            p_dvr->SetDataCB(usr_h264datacb,p_dvr);

            //dvr->prepare();
            p_dvr->start();
//            p_dvr->disableWaterMark();
#ifdef WATERMARKORI
            p_dvr->enableWaterMark();
            sprintf(bufname,"64,64,0,64,250,CAMERA1 CAPTURE,64,450,IVFD V2.0a");
            p_dvr->setWaterMarkMultiple(bufname);
#endif
    #ifdef AAA
            setStyleSheet(QStringLiteral("background-color: rgba(112, 200, 11, 0);"));
    #endif
    #ifdef SUPPORT_RTSP
            p_dvr->set_rtsp_to_file(0);//test !!!! if 1 wirite to encode stream to file . must start before start_rtsp
            p_dvr->start_rtsp();
    #endif
            p_dvr->startRecord();
            isaf=true;
            dvrCamera[1].setRecord(true);
    }


    if(!dvrCamera[cur_camera].getPreview())
    {
        struct view_info vv= {340,0,VIEW_WEITH,VIEW_HEIGHT};
        //ALOGV("vx=%d vy=%d sx=%d sy%d",mcd->lcdxres,mcd->lcdyres,dvr->recordwith,dvr->recordheith);
        p_dvr->startPriview(vv);
        #ifdef AAA
        setStyleSheet(QStringLiteral("background-color: rgba(112, 200, 11, 0);"));
#endif

        dvrCamera[1].setPreview(true);
    }
    sleep(1);//temp add here,must use timestamp for response gap,i will impl next version
#endif

}

void CPlayWindow::SLOT_BtnReturn()
{
    printf("camera home \r\n");
#if defined(Q_OS_LINUX)
    android::Mutex::Autolock locker(&mObjectLock);
    dvr_factory * p_dvr=dvrCamera[cur_camera].dvr;
    if(dvrCamera[cur_camera].getPreview())
    {
        p_dvr->stopPriview();
        dvrCamera[cur_camera].setPreview(false);
    }
#endif
    pIVFDUiDesign->setHidden(false);
    this->close();
}

void CPlayWindow::SLOT_CmdFromBrowser(QString module, QString cmd)
{
    qDebug() << "-------- CPlayWindow Get the cmd from Browser-----" << QThread::currentThread();
    qDebug() << module;
    enum ECMDTYPE cmdtype;
//    if(cmd == "startAll")
//    {
//        cmdtype = CMD_STARTALL;
//    }else if(cmd == "stopAll")
//    {
//        cmdtype = CMD_S;
//    }else if(cmd == "switch")
//    {
//        cmdtype = SWITCH;
//    }else if(cmd == "downloadLog")
//    {
//        cmdtype = DOWNLOADLOG;
//    }else if(cmd == "switchRtsp")
//    {
//        cmdtype = RTSPSWITCH;
//    }else if(cmd == "stoprtsp1")
//    {
//        qDebug() << "-------- CPlayWindow Get the cmd from Browser-----" << QThread::currentThread() << "---stoprtsp1-" ;
//        cmdtype = STOPRTSP1;
//    }

//    switch (cmdtype) {
//    case STARTALL:
//        {
//            qDebug() << cmd;
//            break;
//        }
//    case SWITCH:
//        {
//            qDebug() << "----In CPlayWindow cmdtype---" << QThread::currentThread() <<cmd;
////            emit SIG_PlaySwitch();
//            break;
//        }
//    case STOPALL:
//        {
//            qDebug() << cmd;
//            break;
//        }
//    case DOWNLOADLOG:
//        {
//            qDebug() << cmd;
////            emit SIG_DownLoadFile();
//            break;
//        }
//    case RTSPSWITCH:
//        {
//            qDebug() << cmd;
////            emit SIG_RtspSwitch();
//            break;
//        }
//    case STOPRTSP1:
//    {
//            qDebug() << cmd;
//            SLOT_StopRtsp1();
//    }

//    default:
//        break;
//    }

}


void CPlayWindow::SLOT_BtnRtsp1()
{
    qDebug() << "-------CPlayWindow BtnRtsp1 clicked----------------" << QThread::currentThread();
    startRtspServer1(0);

}


void CPlayWindow::SLOT_BtnRtsp2()
{
    qDebug() << "-------CPlayWindow BtnRtsp1 clicked----------------" << QThread::currentThread();
    startRtspServer2(1);

}

void CPlayWindow::SLOT_BtnRtspSwitch()
{

    qDebug() << "-------CPlayWindow BtnRtsp switch clicked---------------"<< QThread::currentThread();
    switchRtspServer();
}

void CPlayWindow::SLOT_StopRtsp1()
{
    qDebug() << "-------CPlayWindow BtnRtsp stop Rtsp1---------------"<< QThread::currentThread() << "----currentpthread= " << QThread::currentThread();

//    qDebug() << "------CPlayWindow BtnRtsp stop Rtsp1--------------currentpthread = " << currentpthread;

//    if(currentpthread == -1)
//    {
//        return;
//    }
//    qDebug() << "return of pthread_cancle:"   <<  pthread_cancel(currentpthread);


}

void CPlayWindow::CPlayCallbackTimestamp(nsecs_t timestamp, int32_t msgType, char *dataPtr, void *user)
{

    int retqueData = 0 ;
    char *ptemp = dataPtr;
    VencInputBuffer *myData = (VencInputBuffer *)(ptemp + 4);
    android::Mutex::Autolock lock(&mDisplayLock);
    memcpy((uchar *)&(m_ImgWithStamp.mImageData), (uchar *)(myData->pAddrVirY), (myData->nFlag)*2/3);
    m_ImgWithStamp.stamp = myData->nPts;
    emit SIG_UpdateTimeStamp(myData->nPts);

    IMGYData *imgYData = (IMGYData *)&(m_IMGYData[0]);//make imgYData point to the first address of m_IMGYData[]

    if(myData == NULL || imgYData == NULL)
        return;
    //find the unused address and o malloc
    for(int i = 0; i < (MAXBUFFER - 1); i++)
    {
//        qDebug("mid = %d , mrflag = %d", imgYData->mid, imgYData->mrwFlag) ;
        if(imgYData->mrwFlag == 0 && imgYData->mid == i)
        {
//            imgYData->data = (uchar *)malloc((myData->nFlag)*2/3);

            if(imgYData->data != NULL)
            {
//                qDebug("the address malloced = %x mid = %d ", imgYData->data, imgYData->mid);
//                memset(imgYData->data, 0, 1280*720);
                memcpy(imgYData->data, myData->pAddrVirY, 1280*720);
                imgYData->stamp = myData->nPts;
                //           qDebug() << myData->nPts << "------" << myData->nFlag;
                //           memset(imgYData->data, 1, m_videosize); //m_videosize is not trustable
                //           qDebug() <<  myData->nFlag << "---No.--" << i << "---mrwFlag:---" << imgYData->mrwFlag << " mid = " <<imgYData->mid;
                imgYData->mrwFlag = 1;
                retqueData = SeqQueue_Append(m_queue, imgYData);
                break;
            }

        }
        imgYData++;
    }
    //push into the que
#if 0
    if(imgYData->mid == 29)
    {
        if(imgYData->mrwFlag == 0)
        {
//            imgYData->data = (uchar *)malloc(1280*720);
            if(imgYData->data != NULL)
            {
//                memset(imgYData->data, 0, 1280*720);s
                qDebug("almost full ,mrwFlag = 0, the address malloced = %x", imgYData->data);
                memcpy(imgYData->data, myData->pAddrVirY, 1280*720);
                imgYData->stamp = myData->nPts;
                imgYData->mrwFlag = 1;
            }
        }else if(imgYData->mrwFlag == 1)
        {
            if(imgYData->data != NULL)
            {
//                qDebug("now write again at position 29");
//                memset(imgYData->data, 0, 1280*720);
                memcpy(imgYData->data, myData->pAddrVirY, 1280*720);
                imgYData->stamp = myData->nPts;
                imgYData->mrwFlag = 1;
            }
        }

    }
#endif
//    m_queuemutex.lock();
//    int retqueData = OSAL_Queue(&m_imageDataQue, imgYData);
//    m_queuemutex.unlock();
    pstaticthis->update();
    if(retqueData != 0)
    {
//        m_queuemutex.lock();
//        qDebug() << "queue is now full" << OSAL_GetElemNum(&m_imageDataQue) << "-----" << QThread::currentThread();
//        pstaticthis->SIG_GetTimeStamp0(timestamp);
//        m_queuemutex.unlock();
        qDebug() << "retqueData !=0 =" << retqueData;
        if(retqueData == -2)//full
        {
//            SeqQueue_Clear(m_queue);
        }

        return;
    }

//    m_queuemutex.lock();
//    qDebug() << "queue is not full" << OSAL_GetElemNum(&m_imageDataQue) << "-----" << QThread::currentThread();
//    pstaticthis->SIG_GetTimeStamp0(timestamp);
//    m_queuemutex.unlock();


    QThread::msleep(1);

//    int retqueData = OSAL_Queue(&m_imageDataQue, imgYData);
//    if (retqueData != 0)
//    {
//        free(imgData);
//        qDebug() << "full queue image data";
//        pthread_mutex_lock(&m_quemutex);
//        pthread_cond_signal(&m_quecond);
//        pthread_mutex_unlock(&m_quemutex);
//        return;
//    }

//    LOGW("data queue not full");
//    pthread_mutex_lock(&m_quemutex);
//    pthread_cond_signal(&m_quecond);
//    pthread_mutex_unlock(&m_quemutex);

}

void CPlayWindow::SLOT_GetTimeStamp0()
{
    qDebug() << "Get a TimeStamp in the thread:-----" << QThread::currentThread() ;

    qlonglong timestamp = m_ImgWithStamp.stamp;

    QByteArray msg = QByteArray::number(timestamp, 10);


    qDebug() << "start to emit msgtotopui" << timestamp << "-----" << msg;
    emit SIG_MsgToTopUi(msg);
    return ;
}
void CPlayWindow::doUpdate()
{
    qDebug() << "do update -----------------do update-----------------------------";
////    this->update();
////    this->repaint();

}


qlonglong CPlayWindow::CPlayGetCurrentUTCStamp()
{
    if(m_ImgWithStamp.stamp != 0)
    {
        return m_ImgWithStamp.stamp;
    }
}


