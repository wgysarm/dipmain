#include "IVFDAlgFire.h"
//#include "IVFDRtspThread.h"
#include "CPlayWindow.h"
#include "vfd_processor_i.h"

//static CPlayWindow * pFather;
//#define IVFDINIT_INI "/data/ivfdinit.ini"
#define IVFDINIT_INI "/ivfdinit.ini"
#if defined(Q_OS_LINUX)
using namespace android;
#endif

#if defined(OPENCVYES)
//using namespace cv;
#endif

//quint32 IVFDAlgFire::m_queMesgLeft = 0;
/*********************************************************************************************************************************************************
*函数描述：  brightnessException     计算并返回一幅图像的色偏度以及，色偏方向
*函数参数：  grayImg    需要计算的图片
*           cast        计算出的偏差值，小于1表示比较正常，大于1表示存在亮度异常；当cast异常时，da大于0表示过亮，da小于0表示过暗
*函数返回值： 返回值通过cast、da两个引用返回，无显式返回值
**********************************************************************************************************************************************************/
//static void BrightnessException(Mat& grayImg, float& cast, float& da);

/*********************************************************************************************************************************************************
*Describe:  Deque the image from the queque, and process it per frame
*Arguments: queueHandle :pointer of the queue
*           flag: need reverse or inverser image prosess flag
*           result: typedef struct {
                                    VATGT_SET	target_set;		// 目标
                                    VAEVT_SET	event_set;		// 事件
                                    VACMD_SET	command_set;	// 命令
                                    ZSTRING		privacy;		// 特定算法模块私有数据
                                    } VARESULT;

* Return:int 1:wrong, 0:right.
**********************************************************************************************************************************************************/

int IVFDAlgFire::Do_DeQue(void *queueHandle , int flag, VARESULT *result)
{
    if(queueHandle == NULL)
    {
        qDebug() << "Do_Deque has no image data!,return 1.";
        return 1;
    }
    SeqQueue *pqueue = (SeqQueue *)queueHandle;
    TSeqLinkList *pqueuelist = (TSeqLinkList *)queueHandle;
    //if queue is empty please wait for 50ms;
    if(pqueuelist->length == 0){
        QEventLoop loop;
        QTimer::singleShot(50, &loop, SLOT(quit()));
        loop.exec();
    }

    IMGYData *imgydata = (IMGYData *)SeqQueue_Retrieve(pqueue);//queue at the position 0;
//  printf("%s:%d:%s:malloc(%ld):p=0x%lx\n", __FILE__, __LINE__, __func__, 1280*720, (unsigned long)imgydata);
    int rettmp = 0;
    int res = 0;

    if(imgydata != NULL)
    {
        if(imgydata->data != NULL && imgydata->mrwFlag == 1)
        {
            m_frame_index ++;
            //fire det
            memcpy(m_img_src->data_y, imgydata->data, IMAGESIZE);
            m_img_src->time = (unsigned int)(m_frame_index);//the time is ++, with per imgydata get
            if(m_algo_handle != NULL)
            {
                res = ALGO_VFD_Process(m_algo_handle, m_img_src);
            }
            //end det
            if (res == VASTATUS_OK)
            {
                //                printf("res = VASTATUS_OK\n");
                memset(m_varesult, 0, sizeof(VARESULT));
                //5 get result from algo
                ALGO_VFD_GetResults( m_algo_handle, m_varesult );
                //只有当处理过图像时，才说明result有更新
                this->m_proc_result_buf.flg_used = FALSE_;
            }
            //            m_varesult->event_set.events
            this->m_proc_result_buf.image.width = STE_IMAGE_WIDTH;
            this->m_proc_result_buf.image.height = STE_IMAGE_HEIGH;
            this->m_proc_result_buf.frame_index = m_frame_index;

            //save target
            if (m_varesult->target_set.target_num > STE_TARGET_MAX_NUM)
            {
                m_varesult->target_set.target_num = STE_TARGET_MAX_NUM;
            }
            this->m_proc_result_buf.target_set.num = m_varesult->target_set.target_num;
            this->m_proc_result_buf.target_set.frame = m_frame_index;

            for (int i=0; i<m_varesult->target_set.target_num; i++)
            {
                this->m_proc_result_buf.target_set.targets[i].type = STE_SYSEVENT_FIRE_S;
                this->m_proc_result_buf.target_set.targets[i].rect.left = m_varesult->target_set.targets[i].rect.lb_x;
                this->m_proc_result_buf.target_set.targets[i].rect.bottom = m_varesult->target_set.targets[i].rect.lb_y;
                this->m_proc_result_buf.target_set.targets[i].rect.right = m_varesult->target_set.targets[i].rect.ru_x;
                this->m_proc_result_buf.target_set.targets[i].rect.top = m_varesult->target_set.targets[i].rect.ru_y;
            }
            //save event
            if (m_varesult->event_set.event_num > STE_EVENT_MAX_NUM)
            {
                m_varesult->event_set.event_num = STE_EVENT_MAX_NUM;
            }
            this->m_proc_result_buf.event_set.num = m_varesult->event_set.event_num;
            for (int i=0; i<m_varesult->event_set.event_num; i++)
            {
                if (m_varesult->event_set.events[i].type == VAEVT_TYPE_AlarmFire)
                {
//                    printf("-----------------------------------------find fire----------------------------\n");
                    QRect firedetArea(this->m_proc_result_buf.target_set.targets[i].rect.left,
                                      this->m_proc_result_buf.target_set.targets[i].rect.bottom,
                                      this->m_proc_result_buf.target_set.targets[i].rect.right - this->m_proc_result_buf.target_set.targets[i].rect.left,
                                      this->m_proc_result_buf.target_set.targets[i].rect.top - this->m_proc_result_buf.target_set.targets[i].rect.bottom);
                    this->m_proc_result_buf.event_set.events[i].type = STE_SYSEVENT_FIRE_S;
                    emit SIG_HasOutcome(FIREDET, firedetArea, m_frame_index);
                }
                if (m_varesult->event_set.events[i].status == VAEVT_STATUS_END)//wanggy modify old is 2
                {
//                    printf("-----------------------------------------end fire----------------------------\n");
                    QRect firedetArea(this->m_proc_result_buf.target_set.targets[i].rect.left,
                                      this->m_proc_result_buf.target_set.targets[i].rect.bottom,
                                      0,
                                      0);
                    this->m_proc_result_buf.event_set.events[i].type = STE_SYSEVENT_FIRE_E;//wanggy modify
                    emit SIG_HasOutcome(FIREDETEND, firedetArea, m_frame_index);
                }
                this->m_proc_result_buf.event_set.events[i].frame = m_frame_index;
            }
            //save image;
            imgydata->mrwFlag = 0;
            rettmp = 0;
        }else if(imgydata->data != NULL && imgydata->mrwFlag == 0)
        {
            qDebug() << "IVFDAlgFire::Do_DeQue:imgydata->mrwFlag == 1 || imgydata->data != NULL" ;
//            printf("%s:%d:%s: imgydata->mrwFlag=%d ,imgydata->data=0x%lx\n", __FILE__, __LINE__, __func__, (int)imgydata->mrwFlag,(unsigned long)imgydata->data);
            rettmp = 0;
            QEventLoop loop;
            QTimer::singleShot(10, &loop, SLOT(quit()));
            loop.exec();
        }else if(imgydata->data == NULL){
            qDebug() << "IVFDAlgFire::Do_DeQueimgydata->data == NULL, so we have to reset the application!" ;
            rettmp = 1;
            printf("%s:%d:%s: imgydata->mrwFlag=%d ,imgydata->data=0x%lx\n", __FILE__, __LINE__, __func__, (int)imgydata->mrwFlag,(unsigned long)imgydata->data);
            QEventLoop loop;
            QTimer::singleShot(10, &loop, SLOT(quit()));
            loop.exec();
        }
    }else{
        qDebug() << "3 IVFDAlgFire::Do_DeQue:imgydata == null , queue is empty, wait for 10ms";
        rettmp = 1;
        QEventLoop loop;
        QTimer::singleShot(20, &loop, SLOT(quit()));
        loop.exec();
    }
    return rettmp;
}

void IVFDAlgFire::SLOT_NoCaptureData(){
    emit SIG_StopAlgProcess();
}


IVFDAlgFire::IVFDAlgFire(QObject *parent) : QObject(parent)
{
    m_onwatch = CPlayWindow::m_onwatchstatus;

    m_algo_cfg = (ST_AlgoConfig *)malloc(sizeof(ST_AlgoConfig));

    m_algo_cfg->val_delay = 2;//delay 2 s
    m_algo_cfg->val_fov = 1;//field of view
    m_algo_cfg->val_static_det = 1;
    m_algo_cfg->val_sense = 60; //sensitivity 0~100
    m_algo_cfg->area_min = 30;//0~99
    m_algo_cfg->val_alarmdelay = 10;
    m_algo_cfg->val_alarm_level = 120;//160
    m_algo_cfg->val_consist_ratio = 95;
    m_algo_cfg->val_overexpose_ratio = 20;
    m_algo_cfg->val_thrld_loss = 10;//20
    //
    m_varesult = (VARESULT*)malloc(sizeof(VARESULT));

    m_img_src = (IVFD_YuvImage *)malloc(sizeof(IVFD_YuvImage));

    m_img_src->width = STE_IMAGE_WIDTH;
    m_img_src->height = STE_IMAGE_HEIGH;
    m_img_src->data_y = (unsigned char*)malloc(IMAGESIZE);
    m_img_src->data_u = (unsigned char*)malloc(IMAGESIZE*1/4);
    m_img_src->data_v = (unsigned char*)malloc(IMAGESIZE*1/4);
    m_img_src->width = STE_IMAGE_WIDTH;
    m_img_src->height = STE_IMAGE_HEIGH;

    m_frame_index = 0;
    //
    m_algo_handle = (void *)malloc(sizeof(MODULE_VFD));
    //
    memset(&m_proc_result_buf, 0, sizeof(m_proc_result_buf));
    m_proc_result_buf.image.data = (unsigned char *)malloc(STE_IMAGE_HEIGH*STE_IMAGE_WIDTH*4);
    assert(m_proc_result_buf.image.data);

    if(m_varesult == NULL || m_img_src == NULL)
    {
        qDebug() << "m_varesult == NULL || m_img_src == NULL";
    }

    ProcessModuleInit(m_algo_cfg);
}

IVFDAlgFire::~IVFDAlgFire()
{
    printf("destroy algo\r\n");
    ALGO_VFD_destroy(m_algo_handle,STE_IMAGE_WIDTH, STE_IMAGE_HEIGH);
    if(m_algProcessThread != NULL)

    {
        delete m_algProcessThread;
        m_algProcessThread = (QThread *)NULL;
    }
}


void IVFDAlgFire::ProcessModuleInit(ST_AlgoConfig *m_algo_cfg)
{
//    m_algProcessThread = NULL;
    m_algProcessThread = new QThread(this);
    if(m_algProcessThread != NULL)
    {
        m_algProcessThread->start();
    }else
    {
        return;
    }

    this->moveToThread(m_algProcessThread);

    QObject::connect(m_algProcessThread, SIGNAL(finished()), this, SLOT(deleteLater()));
    QObject::connect(m_algProcessThread, SIGNAL(finished()), m_algProcessThread, SLOT(deleteLater()));

    QObject::connect(this, SIGNAL(SIG_StartAlgProcess(int)), this, SLOT(SLOT_StartAlgProcess(int)));
    QObject::connect(this, SIGNAL(SIG_StopAlgProcess()), this, SLOT(SLOT_StopAlgProcess()));
    QObject::connect(this, SIGNAL(SIG_HasOutcome(EOUTCOMETYPE,QRect,int)), this, SLOT(SLOT_HasOutcome(EOUTCOMETYPE,QRect,int)));
    QObject::connect(this, SIGNAL(SIG_CaptureYUVDataFile(int)), this, SLOT(SLOT_CaptureYUVFile(int)));
    QObject::connect(this, SIGNAL(SIG_OnWatchSet(int)), this, SLOT(SLOT_OnWatchSet(int)));
    QObject::connect(this, SIGNAL(SIG_TellOnWatch()), this, SLOT(SLOT_TellOnWatch()));
    QObject::connect(this, SIGNAL(SIG_QueryStatus(int)), this, SLOT(SLOT_QueryStatus(int)));
    QObject::connect(this, SIGNAL(SIG_SetAlgparameter(void*,int,int)), this, SLOT(SLOT_SetAlgparameter(void*,int,int)));
    QObject::connect(this, SIGNAL(SIG_ControlAlgStatus(int,int)), this, SLOT(SLOT_ControlAlgStatus(int,int)));
    QObject::connect(this, SIGNAL(SIG_NoCaptureData()), this, SLOT(SLOT_NoCaptureData()));
}

void IVFDAlgFire::SLOT_StartAlgProcess(int modeFlag/*void *queueHandle*/)
{
    qDebug() << "3 In IVFDAlgProcessModule-----slot start algprocess--" << QThread::currentThread();

    int res = 0;

    if(CPlayWindow::m_queue_1 == NULL)
    {
        qDebug("no cplaywindow created! because m_queue is null");
        return;
    }
    qDebug("IVFDAlgFire::SLOT_StartAlgProcess():modeFlag=%d", modeFlag);

//    SeqQueue *handle = (SeqQueue *)(CPlayWindow::m_queue_0);//video0
    SeqQueue *handle = (SeqQueue *)(CPlayWindow::m_queue_1);//video1;
    if(modeFlag == 2)
    {
        handle = (SeqQueue *)(CPlayWindow::m_queue_2);//video 1;
    }

    if(m_algo_handle == NULL)
    {
        qDebug() << "3 IVFDAlgFire::SLOT_StartAlgProcess:failed";
        return;
    }else
    {
        ALGO_VFD_create(STE_IMAGE_WIDTH, STE_IMAGE_HEIGH, m_algo_cfg, m_algo_handle);
        //to read the args from algofireconfig.ini
        QFile inifile("/ivfdalgfire.ini");

        if(!inifile.exists())
        {
//            QLog_("init", ErrorLevel, QString("/tmp/ivfdrun/ivfdinit.ini not exisit"));

        }else{
            QSettings initsetting(IVFDINIT_INI, QSettings::IniFormat);
            QVariant keyval;
            initsetting.beginGroup("algo");
            keyval = initsetting.value("sensefire");
            m_algo_cfg->val_sense = keyval.toInt();
            keyval = initsetting.value("mindetfactorfire");
            m_algo_cfg->area_min = keyval.toInt();
            initsetting.endGroup();
        }
        //to change the args
        ALGO_VFD_setConfig(m_algo_handle, m_algo_cfg);
    }

    m_img_src->width = STE_IMAGE_WIDTH;
    m_img_src->height = STE_IMAGE_HEIGH;

    while(1) //never quit
    {
        if(CPlayWindow::m_onwatchstatus == 0){
            QEventLoop loop;
            QTimer::singleShot(10, &loop, SLOT(quit()));
            loop.exec();
        }else if(CPlayWindow::m_onwatchstatus == 1){
            res = Do_DeQue(handle, modeFlag, m_varesult);
            if(res != 1)
            {
                QEventLoop loop;
                QTimer::singleShot(10, &loop, SLOT(quit()));
                loop.exec();
            }else
            {
                qDebug("mdata = NULL");
            }
        }else{
         qDebug() << CPlayWindow::m_onwatchstatus << " m_onwatch = " << m_onwatch;
         if(CPlayWindow::m_onwatchstatus > 1){
            CPlayWindow::m_onwatchstatus--;
         }
         QEventLoop loop;
         QTimer::singleShot(10, &loop, SLOT(quit()));
         loop.exec();
        }
    }
}

void IVFDAlgFire::SLOT_StopAlgProcess()
{
    qDebug() << "IVFDAlgFire::SLOT_StopAlgProcess()";
    if(m_algProcessThread != NULL)
    {
        qDebug() << "IVFDAlgFire::SLOT_StopAlgProcess()";
        m_algProcessThread->quit();
        m_algProcessThread->wait(3);//should in with a number para,or will block the main thread
    }
}

void IVFDAlgFire::SLOT_HasOutcome(EOUTCOMETYPE type, QRect position, int frame_index)
{
    QString range = QString("%1,%2,%3,%4").arg(QString::number(position.topLeft().rx()))\
                                             .arg(QString::number(position.topLeft().ry()))\
                                             .arg(QString::number(position.width()))\
                                             .arg(QString::number(position.height()));
    QString msg = QString("C2S$%1$%2$%3").arg(QString::number((int)type)).arg(range).arg(QString::number(frame_index));

    QByteArray alarminfo;
    ALARMDATAINFO alarmDataInfo;
    alarmDataInfo.alarmTime = frame_index;
    alarmDataInfo.alarmType = (int)type;
    alarmDataInfo.pTOPLx = position.topLeft().rx();
    alarmDataInfo.pTOPLy = position.topLeft().ry();
    alarmDataInfo.recHeight = position.height();
    alarmDataInfo.recWidth = position.width();
    alarminfo.resize(sizeof(alarmDataInfo));
    memcpy(alarminfo.data(), &alarmDataInfo, sizeof(alarmDataInfo));

    emit SIG_SendOutcomeToCPW(alarminfo);
}

//static void BrightnessException(Mat &grayImg, float &cast, float &da)
//{
//    float a=0;
//    int Hist[256];
//    for(int i=0;i<256;i++)
//    Hist[i]=0;
//    qDebug() << "rows = " << grayImg.rows << "  cols =" << grayImg.cols << "val(640,360) = " << grayImg.at<uchar>(640,320);
//    for(int i=0;i<grayImg.rows;i++)
//    {
//        for(int j=0;j<grayImg.cols;j++)
//        {
//            a += float(grayImg.at<uchar>(i,j)-128);//在计算过程中，考虑128为亮度均值点
//            int x = grayImg.at<uchar>(i,j);
//            Hist[x]++;
//        }
//    }
//    da=a/float(grayImg.rows*grayImg.cols);
//    float D =abs(da);
//    float Ma=0;
//    for(int i=0;i<256;i++)
//    {
//        Ma+=abs(i-128-da)*Hist[i];
//    }
//    Ma/=float((grayImg.rows*grayImg.cols));
//    float M=abs(Ma);
//    float K=D/M;
//    cast = K;
//    return;

//}

void IVFDAlgFire::SLOT_CaptureYUVFile(int num)//num is the frame number
{
    if(CPlayWindow::m_queue_0 == NULL)
    {
        qDebug("no cplaywindow created! because m_queue is null");
        return;
    }
    if(num > 386)
    {
        qDebug() << "too large frame numer, should small than 386";
        return;
    }

    SeqQueue *handle = (SeqQueue *)(CPlayWindow::m_queue_0);

    QString filename("/mnt/sdcard/mmcblk1p1/1/yuvcapt.yuv");
    FILE *yuv_file = fopen(filename.toLatin1().data(), "ab");
    int height = STE_IMAGE_HEIGH;
    int width = STE_IMAGE_WIDTH;
    int framesize = height * width * 3 / 2;
    for(int i = 0; i < num; i++) //never quit
    {
        qDebug() << i;
        IMGYData *mdata = (IMGYData *)CaptureYUVWriteToFile(handle, yuv_file, framesize);

        if(mdata != NULL)
        {
            QThread::msleep(10);
        }else
        {
            qDebug("mdata = NULL");
            QThread::msleep(10);
            continue;
        }
    }
    return;
}


void* IVFDAlgFire::CaptureYUVWriteToFile(void *queueHandle, FILE *fp, int framesize)
{
    if(queueHandle == NULL)
    {
        qDebug() << "data error";
        return NULL;
    }
    void *rettmp = NULL;
    int ysize = framesize * 2 /3;
    int uvsize = ysize * 1 / 2;
    char* bufFrame = new char[framesize];
    char* bufUVData = new char[uvsize];
    memset(bufFrame, 0, framesize);
    memset(bufUVData, 0, uvsize);

    SeqQueue *pqueue = (SeqQueue *)queueHandle;
    IMGYData *imgydata = (IMGYData *)SeqQueue_Retrieve(pqueue);
    if(imgydata != NULL)
    {
        if(imgydata->data != NULL && imgydata->mrwFlag == 1)
        {
            qDebug() << "IVFDAlgFire::CaptureYUVWriteToFile:imgydata->mrwFlag == 1";

            char *pYData = (char *)imgydata->data;
            memcpy(bufFrame, pYData, ysize);
            memcpy(bufFrame + ysize, bufUVData, uvsize);

            fwrite(bufFrame, 1, framesize, fp);
            imgydata->mrwFlag = 0;
        }else
        {
            qDebug() << "IVFDAlgFire::CaptureYUVWriteToFile:imgydata->mrwFlag != 1";
        }
        rettmp = (void *)imgydata;
    }
    if(bufFrame != NULL)
    {
        free(bufFrame);
        bufFrame = (char *)NULL;
    }

    if(bufUVData != NULL)
    {
        free(bufUVData);

        bufUVData = (char *)NULL;
    }
    return rettmp;
}


void IVFDAlgFire::ImageReverse(uchar *pSrc, uchar *pDest)
{
    qDebug() << "IVFDAlgFire::SLOT_ImagReverse()";
}


void IVFDAlgFire::SLOT_OnWatchSet(int status){
    m_onwatch = status;
}

void IVFDAlgFire::SLOT_TellOnWatch()
{
    QByteArray alarminfo;
    ALARMDATAINFO alarmDataInfo;
    alarmDataInfo.alarmTime = 0;
    alarmDataInfo.alarmType = (int)RUNSTATUS;
    alarmDataInfo.pTOPLx = 0;
    alarmDataInfo.pTOPLy = 0;
    alarmDataInfo.recHeight = 0;
    alarmDataInfo.recWidth = m_onwatch;
    alarminfo.resize(sizeof(alarmDataInfo));
    memcpy(alarminfo.data(), &alarmDataInfo, sizeof(alarmDataInfo));
    emit SIG_SendOutcomeToCPW(alarminfo);
}

void IVFDAlgFire::SLOT_QueryStatus(int type)
{
    if(type == 0){
        qDebug() << "type = " << 0; //
        emit SIG_TellOnWatch();
    }

}
void IVFDAlgFire::SLOT_SetAlgparameter(void *para, int id, int val){
    ST_AlgoConfig *cfg = (ST_AlgoConfig *)para;
    switch(id){
    case SENSE:
    {
        cfg->val_sense = val;
        break;
    }
    case DELAY:
    {
        cfg->val_delay = val;
        break;
    }
    case FOV:
    {
        cfg->val_fov = val;
        break;
    }
    case STATICDET:
    {
        cfg->val_static_det = val;
        break;
    }
    case MINAREA:
    {
        cfg->area_min = val;
        break;
    }
    case YLEVEL:
    {
        cfg->val_y_level = val;
        break;
    }
    case LOSS:
    {
        cfg->val_thrld_loss = val;
        break;
    }
    case ALARMDELAY:
    {
        cfg->val_alarmdelay = val;
        break;
    }
    case OVEREXPOS:
    {
        cfg->val_overexpose_ratio = val;
        break;
    }
    case CONSIST:
    {
        cfg->val_consist_ratio = val;
        break;
    }
    case ALARMLEVEL:
    {
        cfg->val_alarmdelay = val;
        break;
    }
    case AWARETHRLD:
    {
        cfg->val_aware_thrld = val;
        break;
    }
    case STATICTHRLD:
    {
        cfg->val_static_thrld = val;
        break;
    }
    default:
    {
    }
    }

}

void IVFDAlgFire::SLOT_ControlAlgStatus(int cmdid, int val)
{
    switch(cmdid){
    case 13:{
        emit SIG_OnWatchSet(val);
        break;
    }
    case 12:{
        break;
    }
    default:{}
    }
}
