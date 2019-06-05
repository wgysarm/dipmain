
#include "IVFDRtspThread.h"

#include <QImage>
//using namespace std;
//
//old
//#include<opencv/cv.hpp>
//#include<opencv/highgui.h>
//
#define LOG_BUF_SIZE	1024
#define VIEW_WEITH 480 //720
#define VIEW_HEIGHT 320 //480
#define WATERMARKORI 1

#define IVFDINIT_INI "/ivfdinit.ini"
#define IVFDNET_INI "/ivfdnet.ini"
#define IVFDCAM_INI "/ivfdcam.ini"
#define IVFDMFC_INI "/ivfdmfc.ini"
#define IVFDALG_INI "/ivfdalg.ini"
#define IVFDSTA_INI "/ivfdsta.ini"
extern IVFDUiDesign *pIVFDUiDesign;

#define CAM0 0;
#define CAM1 1;

#define GPIO_TEST
#define CAMERA_PARAM

#define GPIO_SDCDPIN 238 //PH14 sd cd pin
#define GPIO_OUTLED1 237 //PH13
#define GPIO_OUTLED2 239 //PH15
#define GPIO_OUTLED3 240 //PH16
#define GPIO_OUTBUZZ 244 //PH20

#define GPIO_RELAYOUT1 241 //PH17
#define GPIO_RELAYOUT2 242 //PH18

#define RECORD_TEST 1

#define TEST_CAMERA_ID 0
#define TEST_CAMERA_ID2 1

#define TEST_CAMERA_ID_T1 0
#define TEST_CAMERA_ID_T2 1

static FILE* h264fp;
static CPlayWindow *pstaticthis=NULL; // this is used to get the CPlayWindow pointer;static must
ImageDataScale CPlayWindow::m_ImgScale_0 = ImageDataScale(0, IMAGESIZE);
ImageDataScale CPlayWindow::m_ImgScale_1 = ImageDataScale(0, IMAGESIZE);
int CPlayWindow::m_onwatchstatus = 0;

SeqQueue* CPlayWindow::m_queue_0 = SeqQueue_Create(MAXBUFFER);
SeqQueue* CPlayWindow::m_queue_1 = SeqQueue_Create(MAXBUFFER);
SeqQueue* CPlayWindow::m_queue_2 = SeqQueue_Create(MINBUFFER);

QMutex CPlayWindow::mDisplayLock_0;
//android::Mutex CPlayWindow::mDisplayLock_0;
class IVFDAlgFire;
class IVFDAlgSmoke;

pthread_t currentpthread = -1;
//char header[] = {
//    0x00, 0x00, 0x00, 0x01, 0x67, 0x4d, 0x00,0x1f,
//    0xe5, 0x40, 0x28, 0x02, 0xd8, 0x80, 0x00,0x00,
//    0x00, 0x01, 0x68, 0xee, 0x31, 0x12};
char header[] = {
    0x00, 0x00, 0x00, 0x01, 0x67, 0x4d, 0x00,0x1f,
    0xe5, 0x40, 0x3c, 0x01, 0x12, 0xf2, 0xa0,0x00,
    0x00, 0x00, 0x01, 0x68, 0xee, 0x31, 0x12};

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
//using namespace cv;
#endif


#ifdef GPIO_TEST
//added by hxy

//函数声明
static int gpio_export(int pin)
{
    char buffer[64];
    int len;
    int fd;

    fd = open("/sys/class/gpio/export", O_WRONLY);
    if (fd < 0) {
        LOGE("Failed to open export for writing!\n");
        return(-1);
    }

    len = snprintf(buffer, sizeof(buffer), "%d", pin);
    if (write(fd, buffer, len) < 0) {
        LOGE("Failed to export gpio!");
        return -1;
    }
    qDebug() << "gpio_export";
    close(fd);
    return 0;
}

static int gpio_unexport(int pin)
{
    char buffer[64];
    int len;
    int fd;

    fd = open("/sys/class/gpio/unexport", O_WRONLY);
    if (fd < 0) {
        LOGE("Failed to open unexport for writing!\n");
        return -1;
    }

    len = snprintf(buffer, sizeof(buffer), "%d", pin);
    if (write(fd, buffer, len) < 0) {
        LOGE("Failed to unexport gpio!");
        return -1;
    }

    close(fd);
    return 0;
}

//dir: 0-->IN, 1-->OUT
static int gpio_direction(int pin, int dir)
{
    static const char dir_str[] = "in\0out";
    char path[64];
    int fd;

    snprintf(path, sizeof(path), "/sys/class/gpio/gpio%d/direction", pin);
    fd = open(path, O_WRONLY);
    if (fd < 0) {
        LOGE("Failed to open gpio direction for writing!\n");
        return -1;
    }

    if (write(fd, &dir_str[dir == 0 ? 0 : 3], dir == 0 ? 2 : 3) < 0) {
        LOGE("Failed to set direction!\n");
        return -1;
    }
    qDebug() << "gpio_direction";
    close(fd);
    return 0;
}

//value: 0-->LOW, 1-->HIGH
static int gpio_write(int pin, int value)
{
    static const char values_str[] = "01";
    char path[64];
    int fd;

    snprintf(path, sizeof(path), "/sys/class/gpio/gpio%d/value", pin);
    fd = open(path, O_WRONLY);
    if (fd < 0) {
        LOGE("Failed to open gpio value for writing!\n");
        return -1;
    }

    if (write(fd, &values_str[value == 0 ? 0 : 1], 1) < 0) {
        LOGE("Failed to write value!\n");
        return -1;
    }
    qDebug() << "gpio_write";
    close(fd);
    return 0;
}

static int gpio_read(int pin)
{
    char path[64];
    char value_str[3];
    int fd;

    snprintf(path, sizeof(path), "/sys/class/gpio/gpio%d/value", pin);
    fd = open(path, O_RDONLY);
    if (fd < 0) {
        LOGE("Failed to open gpio value for reading!\n");
        return -1;
    }

    if (read(fd, value_str, 3) < 0) {
        LOGE("Failed to read value!\n");
        return -1;
    }

    close(fd);
    return (atoi(value_str));
}

// none表示引脚为输入，不是中断引脚
// rising表示引脚为中断输入，上升沿触发
// falling表示引脚为中断输入，下降沿触发
// both表示引脚为中断输入，边沿触发
// 0-->none, 1-->rising, 2-->falling, 3-->both
static int gpio_edge(int pin, int edge)
{
    const char dir_str[] = "none\0rising\0falling\0both";
    char ptr;
    char path[64];
    int fd;
    switch(edge){
    case 0:
        ptr = 0;
        break;
    case 1:
        ptr = 5;
        break;
    case 2:
        ptr = 12;
        break;
    case 3:
        ptr = 20;
        break;
    default:
        ptr = 0;
    }

    snprintf(path, sizeof(path), "/sys/class/gpio/gpio%d/edge", pin);
    fd = open(path, O_WRONLY);
    if (fd < 0) {
        LOGE("Failed to open gpio edge for writing!\n");
        return -1;
    }

    if (write(fd, &dir_str[ptr], strlen(&dir_str[ptr])) < 0) {
        LOGE("Failed to set edge!\n");
        return -1;
    }

    close(fd);
    return 0;
}

int gpio_test()
{
    int gpio_fd, ret;
    struct pollfd fds[1];
    char buff[10];
    unsigned char cnt = 0;
    char path[64];
    //LED引脚初始化
    for(int i = 0; i < 5; i++)
    {
        gpio_export(GPIO_OUTLED1);
        gpio_direction(GPIO_OUTLED1, 1);
        gpio_write(GPIO_OUTLED1, 1);
        gpio_export(GPIO_OUTLED2);
        gpio_direction(GPIO_OUTLED2, 1);
        gpio_write(GPIO_OUTLED2, 1);
        gpio_export(GPIO_OUTLED3);
        gpio_direction(GPIO_OUTLED3, 1);
        gpio_write(GPIO_OUTLED3, 1);
        QThread::msleep(500);
        gpio_write(GPIO_OUTLED1, 0);
        gpio_write(GPIO_OUTLED2, 0);
        gpio_write(GPIO_OUTLED3, 0);
    }
    gpio_write(GPIO_OUTLED2, 1);
    gpio_write(GPIO_OUTLED3, 1);

    gpio_export(GPIO_OUTBUZZ);
    gpio_direction(GPIO_OUTBUZZ, 1);
    gpio_write(GPIO_OUTBUZZ, 0);
    QThread::msleep(1000);
    gpio_write(GPIO_OUTBUZZ, 1);
    gpio_export(GPIO_RELAYOUT1);
    gpio_direction(GPIO_RELAYOUT1, 1);
    gpio_write(GPIO_RELAYOUT1, 0);
    gpio_export(GPIO_RELAYOUT2);
    gpio_direction(GPIO_RELAYOUT2, 1);
    gpio_write(GPIO_RELAYOUT2, 1);

#if 0//中断测试部分
    //按键引脚初始化
    gpio_export(GPIO_EXAMPLE_INT);
    gpio_direction(GPIO_EXAMPLE_INT, 0);
    gpio_edge(GPIO_EXAMPLE_INT,1);


    snprintf(path, sizeof(path), "/sys/class/gpio/gpio%d/value", GPIO_EXAMPLE_INT);
    gpio_fd = open(path,O_RDONLY);
    if(gpio_fd < 0){
        LOGE("Failed to open %s!\n", path);
        return -1;
    }
    fds[0].fd = gpio_fd;
    fds[0].events = POLLPRI;
    ret = read(gpio_fd,buff,10);
    if( ret == -1 )	LOGE("read\n");
    while(1){
        ret = poll(fds,1,0);
        if( ret == -1 )		LOGE("poll\n");

        if( fds[0].revents & POLLPRI)
        {
            ret = lseek(gpio_fd,0,SEEK_SET);
            if( ret == -1 )		LOGE("lseek\n");


            ret = read(gpio_fd,buff,10);
            if( ret == -1 )		LOGE("read\n");

            gpio_write(GPIO_EXAMPLE_OUT, cnt++%2);
        }
        usleep(100000);
    }
    return 0;
#endif
}
//end
#endif


#ifdef CAMERA_PARAM
static int set_camera_param_bge(dvr_factory *dvr, int type,int val,int opt)
{
    return dvr->setAnalogInputColor(type, val, opt);
}
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


static int InitFileExist(QString filepath)
{
    QFile inifile(filepath);

    if(!inifile.exists())
    {
        QLog_("DIP", ErrorLevel, QString("%1.ini not exisit").arg(filepath));
        qDebug() << "1 In Main::InitThis ---inifile not exist";
        return 0;
    }else
    {
        return 1;
    }
}
static int GetEnviroment(QString mainkey, QString subkey, QVariant *subkeyval)
{

    if(!InitFileExist(QString(IVFDINIT_INI)))
    {
        return 0;
    }

    QSettings initsetting(IVFDINIT_INI, QSettings::IniFormat);
    QStringList mainkeylist = initsetting.childGroups();

    foreach(QString str, mainkeylist)
    {
        if(str == mainkey)
        {
            qDebug() << "mainkey found is: " << str;
            initsetting.beginGroup(mainkey);

            QStringList keylist = initsetting.allKeys();

            foreach(QString key, keylist)
            {
                if(subkey == key)
                {
                    *subkeyval = initsetting.value(key);
                    qDebug() << subkey << " :subkey found value is-----" << *subkeyval;
                    return 1;
                }else
                {
                    continue;
                }
            }
            initsetting.endGroup();
            break;
        }else
        {
            continue;
        }
    }
    qDebug() << "not right found mainkey or subkey";
    return 0;
}

static int GetCFG(QString filename, QString mainkey, QString subkey, QVariant *subkeyval)
{
    if(!InitFileExist(filename))
    {
        return 0;
    }
    QSettings initsetting(filename, QSettings::IniFormat);
    QStringList mainkeylist = initsetting.childGroups();

    foreach(QString str, mainkeylist)
    {
        if(str == mainkey)
        {
            qDebug() << "mainkey found is: " << str;
            initsetting.beginGroup(mainkey);

            QStringList keylist = initsetting.allKeys();

            foreach(QString key, keylist)
            {
                if(subkey == key)
                {
                    *subkeyval = initsetting.value(key);
                    qDebug() << subkey << " :subkey found value is-----" << *subkeyval;
                    return 1;
                }else
                {
                    continue;
                }
            }
            initsetting.endGroup();
            break;
        }else
        {
            continue;
        }
    }
    return 0;
}
int process_h264(FILE *file_fd, int client_id)
{
    int read_length;
    int send_length;
    int data_length;
    tFrameHead header;

    read_length = fread(&header, 1, sizeof(header), file_fd);
    if (read_length != sizeof(header))
    {
        if (!feof(file_fd))
        {
            perror("read file header");
        }
        fseek(file_fd, 0, SEEK_SET);
        return -1;
    }

    char *data_buf = (char *)malloc(sizeof(header)+header.dwDataLen);
    printf("%s:%d:%s:malloc(%ld):p=0x%lx\n", __FILE__, __LINE__, __func__, sizeof(header)+header.dwDataLen, (unsigned long)data_buf);
    memcpy(data_buf, &header, sizeof(header));
    read_length = fread(data_buf+sizeof(header), 1, header.dwDataLen, file_fd);
    if (read_length != header.dwDataLen)
    {
        perror("read file data");
        fseek(file_fd, 0, SEEK_SET);
        free(data_buf);
        return -1;
    }

//	printf("%s >> %d\n", __FUNCTION__, __LINE__);

    send_length = 0;
    data_length = sizeof(header)+header.dwDataLen;

    while(send_length < data_length)
    {
        int ret = send(client_id, data_buf+send_length, data_length-send_length, MSG_NOSIGNAL);
        if(ret == -1)
        {
            perror("send stream rtsp data");
            return -2;
        }
        else
        {
            send_length += ret;
        }
    }

    free(data_buf);

    return 0;

}


static void *testcallback(void *arg)
{
    qDebug() << "testcallback is " << arg;
}

static pthread_mutex_t   m_quemutex;
static pthread_cond_t    m_quecond;

static void *thread_local_file(void *arg)
{
    int socket_id = -1;
    int ret;
    int optval = 1;
    struct sockaddr_un servaddr;
    int seconds = RECV_TIMEOUT;

    struct sockaddr_un client_addr;

    int client_id;
    int addr_size;

    unsigned char buff[BUF_SIZE] = {0};

    FILE * file_fd;
    file_fd = fopen(H264_FILE_NALE, "rb");
    if (file_fd == NULL)
    {
        perror("open file");
        return  (void *)(-1);
    }

    socket_id = socket(PF_UNIX, SOCK_STREAM, 0);
    if (socket_id < 0)
    {
        perror("socket error");
        return (void *)(-1);
    }

    ret = setsockopt(socket_id, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
    if(ret < 0)
    {
        perror("setsockopt error");
        return (void *)(-1);
    }

    ret = set_socket_timeout(socket_id, seconds);
    if(ret == -1)
    {
        return (void *)(-1);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sun_family = AF_UNIX;
    strncpy(servaddr.sun_path, UNIX_DOMAIN_3, sizeof(servaddr.sun_path)-1);
    unlink(UNIX_DOMAIN_3);

    ret = bind(socket_id, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if (ret < 0)
    {
        printf("bind error");
        unlink(UNIX_DOMAIN_3);
        return (void *)(-1);
    }

    ret = listen(socket_id, 5);
    if (ret < 0)
    {
        perror("listen error");
        unlink(UNIX_DOMAIN_3);
        return (void *)(-1);
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

        ret = set_socket_timeout(client_id, seconds);
        if(ret == -1)
        {
            close(client_id);
            continue;
        }

        printf(" === >>> connect\n");

        while(is_exit == 0)
        {
            // process
//			printf("==> process %d\n", __LINE__);
            int ret = process_h264(file_fd, client_id);
            if (ret == -2)
            {
                printf("client disconnet!!\n");
                break;
            }

            usleep(30*1000);

        }

        close(client_id);

    }

    fclose(file_fd);

    close(socket_id);

    return (void*)(0);
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

//        send_sock_rtsp_0 = client_id;

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
}


static char bufname1[512];

//static struct mymesg *mesg = (struct mymesg *)malloc(sizeof(struct mymesg));
int queDepth = 0;
static QMutex m_algMesgMutex ;


static void userdataCallbackTimestamp_0(nsecs_t timestamp,
                               int32_t msgType, char* dataPtr, void* user)
{
    if(pstaticthis != NULL)
    {

        pstaticthis->CPlayCallbackTimestamp_0(timestamp, msgType, dataPtr, user);
//        qDebug() << "userdataCallbackTimestamp------" << QThread::currentThread();

    }
}

static void userdataCallbackTimestamp_1(nsecs_t timestamp,
                               int32_t msgType, char* dataPtr, void* user)
{
    if(pstaticthis != NULL)
    {

        pstaticthis->CPlayCallbackTimestamp_1(timestamp, msgType, dataPtr, user);
//        qDebug() << "userdataCallbackTimestamp------" << QThread::currentThread();

    }
}

//for preview SetDataCB
static status_t usr_h264datacb(int32_t msgType,
                        char *dataPtr,int dalen,
                        void *user)
{


}


//for rtsp0 set SetDataCB
static status_t usr_datacb_0(int32_t msgType,
                    char *dataPtr,int dalen,
                    void *user)
{

    if (send_sock_rtsp_0 == -1)
    {

//        LOGE("=========== not connect!\n");
        return 0;
    }


    if (connect_0_once == 0)
    {
        send_h264_header(send_sock_rtsp_0);
        connect_0_once = 1;
        LOGE("===========   connect streamer 0 !\n");
    }

//    send_h264_header(send_sock_rtsp_0);

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


    return 0;
}


status_t usr_datacb_1(int32_t msgType,
                    char *dataPtr,int dalen,
                    void *user)
{
    if (send_sock_rtsp_1 == -1)
    {
//        LOGE("=========== send_sock_rtsp_1 not connect!\n");
        return 0;
    }


    if (connect_1_once == 0)
    {
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
#endif




//static int SetEnviroment(QString mainkey, QString subkey, QVariant subkeyval)
//{
//    if(!InitFileExist(QString(IVFDINIT_INI)))
//    {
//        return 0;
//    }

//    QStringList keylist;
//    QSettings initsetting(IVFDINIT_INI, QSettings::IniFormat);
//    initsetting.beginGroup(mainkey);
//    keylist = initsetting.allKeys();
//    foreach(QString key, keylist)
//    {
//        qDebug() << key << "-----" << initsetting.value(key);
//    }

//    initsetting.setValue(subkey, subkeyval);
//    initsetting.endGroup();
//    return 1;
//}

//static int modifyInitFile(QString filename, QString findstr, QString altstr)
//{
//    QFile IniFile(filename);
//    if(!IniFile.exists())
//    {
//        return 0;
//    }

//    if(!IniFile.open(QIODevice::ReadWrite | QIODevice::Text))
//    {
//        return 0;
//    }

//    QString strAll;
//    QStringList strList;

//    QFile readFile(filename);
//    if(readFile.open((QIODevice::ReadOnly|QIODevice::Text)))
//    {
//        QTextStream stream(&readFile);
//        stream.setCodec(QTextCodec::codecForName("UTF-8"));

//        strAll = stream.readAll();

//        strList = strAll.split("\n");
//        for(int i = 0; i < strList.length(); i++)
//        {
////            qDebug() << strList.at(i);
//        }
//    }
//    readFile.close();

//    qDebug() << "1 modifyAutoRunFile:now begin to write the autorun.sh";
//    QFile writeFile(filename);
//    if(writeFile.open(QIODevice::WriteOnly|QIODevice::Text))
//    {
//        QTextStream stream(&writeFile);
//        stream.setCodec(QTextCodec::codecForName("UTF-8"));
////        strList=strAll.split("\n");
//        qDebug() << "2 strList.length is:" << strList.length();
//        for(int i = 0;i < strList.length();i++)
//        {
//            QString tempStr = strList.at(i);

//            if(strList.at(i).contains(findstr) && i!= strList.length()-1)
//            {
////                qDebug() << "1 strList.at " << i << " is:" << strList.at(i);
//                tempStr = altstr;
//                stream << tempStr << '\n';
////                i+=1;
//            }else if(strList.at(i).contains(findstr) && i == strList.length() - 1)
//            {
////                qDebug() << "1 strList.at " << i << " is:" << strList.at(i);
//                tempStr = altstr;
//                stream << tempStr;
//            }else if(!strList.at(i).contains(findstr) && i != strList.length() -1)
//            {
////                qDebug() << "1 strList.at " << i << " is:" << strList.at(i);
//                stream << tempStr << '\n';
//            }else if(!strList.at(i).contains(findstr) && i == strList.length() -1)
//            {
////                qDebug() << "1 strList.at " << i << " is:" << strList.at(i);
//                stream << tempStr ;
//            }
//        }
//    }
//    writeFile.close();

//    return 1;
//}


static int ConvertStructGMToByteArray(void *input, QByteArray *output)
{
    if(input == NULL || output == NULL)
    {
        qDebug() << "Error data in or out!";
        return -1;
    }

    QByteArray ba;
    GeneralMsg *in = (GeneralMsg*)input;
    qDebug() << in->dest << in->msgid << in->source << in->type << in->val << "dmstv";
    ba.resize(sizeof(*in));
    output->resize(sizeof(*in));
    memcpy(output->data(), in, sizeof(*in));

    GeneralMsg *msg = (GeneralMsg *)output->data();
    qDebug() << msg->dest << msg->msgid << msg->source << msg->type << msg->val << "dmstv";
    return 0;
}


static void ConvertGenalMsgToByteArray(GeneralMsg *msg, QByteArray *ba)
{
    if(msg == NULL || ba == NULL)
        return;
    ConvertStructGMToByteArray(msg, ba);
}

CPlayWindow::CPlayWindow(QWidget *parent)
    : QWidget(parent)
{
    CPlayInit(NULL, NULL);

    for(int i = 0; i < MAXBUFFER; i++)
    {
        m_IMGYData_0[i].mid = i;
        m_IMGYData_0[i].data = (uchar *)malloc(m_imageSize);
        m_IMGYData_0[i].mrwFlag = 0;
        m_IMGYData_0[i].stamp = 0;
        m_IMGYData_1[i].mid = i;
        m_IMGYData_1[i].data = (uchar *)malloc(m_imageSize);
        m_IMGYData_1[i].mrwFlag = 0;
        m_IMGYData_1[i].stamp = 0;
    }

    for(int i = 0; i < 255; i++)
    {
        m_grayTable.push_back(qRgb(i, i, i));
    }

    m_ImageAlg_0 = QImage(IMGWIDTH, IMGHEIGHT, QImage::Format_Indexed8);
    m_ImageAlg_0.setColorTable(m_grayTable);

    m_ImageAlg_1 = QImage(IMGWIDTH, IMGHEIGHT, QImage::Format_Indexed8);
    m_ImageAlg_1.setColorTable(m_grayTable);

    QThread::msleep(100);
}

CPlayWindow::CPlayWindow(QWidget *parent, void *pCamera0, void *pCamera1)
    : QWidget(parent)
{

    CPlayInit(pCamera0, pCamera1);

//malloc the mem
    for(int i = 0; i < MAXBUFFER; i++)
    {
        m_IMGYData_0[i].mid = i;
        m_IMGYData_0[i].data = (uchar *)malloc(m_imageSize);
        m_IMGYData_0[i].mrwFlag = 0;
        m_IMGYData_0[i].stamp = 0;
        m_IMGYData_1[i].mid = i;
        m_IMGYData_1[i].data = (uchar *)malloc(m_imageSize);
        m_IMGYData_1[i].mrwFlag = 0;
        m_IMGYData_1[i].stamp = 0;
    }

    for(int i = 0; i < MINBUFFER; i++)
    {
        m_IMGYData_2[i].mid = i;
        m_IMGYData_2[i].data = (uchar *)malloc(m_imageSize);
        m_IMGYData_2[i].mrwFlag = 0;
        m_IMGYData_2[i].stamp = 0;
    }

    for(int i = 0; i < 255; i++)
    {
        m_grayTable.push_back(qRgb(i, i, i));
    }

    m_ImageAlg_0 = QImage(IMGWIDTH, IMGHEIGHT, QImage::Format_Indexed8);
    m_ImageAlg_0.setColorTable(m_grayTable);

    m_ImageAlg_1 = QImage(IMGWIDTH, IMGHEIGHT, QImage::Format_Indexed8);
    m_ImageAlg_1.setColorTable(m_grayTable);

    m_ImageAlg_2 = QImage(IMGWIDTH, IMGHEIGHT, QImage::Format_Indexed8);
    m_ImageAlg_2.setColorTable(m_grayTable);
//



    QThread::msleep(100);
}



void CPlayWindow::CPlayInit(void *pCamera0, void *pCamera1)
{
    ui.setupUi(this);

    if(SUPPORT_CAMERA_NUM<2)
        return;
    QVariant keyval;
    GetCFG(IVFDSTA_INI, "status","onwatch", &keyval);

    setProperty("noinput",false);//true?
    isaf=false;
    this->setAttribute(Qt::WA_TranslucentBackground,false);//true
    CPlayWindow::m_onwatchstatus = keyval.toInt();

    GetCFG(IVFDSTA_INI, "status", "camerasetchange", &keyval);
    m_flagCameraSetChanged = keyval.toInt();

    m_imageSize = IMAGESIZE;
    memset(m_ImgWithStamp_0.mImageData, 0, m_imageSize);
    m_ImgWithStamp_0.stamp = 0;
    memset(m_ImgWithStamp_1.mImageData, 0, m_imageSize);
    m_ImgWithStamp_1.stamp = 0;

    m_campara0 = *(CameraParaN *)pCamera0;
    m_campara1 = *(CameraParaN *)pCamera1;
    qDebug() << "CPlayWindow::CPlayInit m_camera0.bright = " << m_campara0.bright;
    qDebug() << "CPlayWindow::CPlayInit m_camera1.bright = " << m_campara1.bright;

#if defined(Q_OS_LINUX)
    HwDisplay* mcd=NULL;
    //test screen mode
    //0 disable
    int tvmode = 3;

//    config_set_tvout(0,tvmode);

    mcd=HwDisplay::getInstance();

    tvmode = config_get_tvout(0);
    printf("--------------tvmode =%d \r\n",tvmode);
    mcd->hwd_screen1_mode(tvmode);
    if(tvmode == 3)
    {
        mcd->hwd_hdmiout();
    }

    cur_camera = 0 ;
    pgEmulatedCameraFactory = new HALCameraFactory();
    //sleep(4);
    int i;
    for(i=0;i<SUPPORT_CAMERA_NUM;i++)
    {
        dvrCamera[i].dvr=new dvr_factory();
    }
    m_pdvr0 = dvrCamera[0].dvr;
    m_pdvr1 = dvrCamera[1].dvr;
#endif

    m_testthread = new TestThread(0);
    m_localCapture = new IVFDLocalCapture(0);
    m_algProcessModule_0 = new IVFDAlgFire(0);
    if(m_algProcessModule_0 == NULL || m_queue_0 == NULL)
    {
        return;
    }

    if(m_localCapture != NULL || m_queue_2 != NULL)
    {
        QObject::connect(this, SIGNAL(SIG_StartLocalCaptureThread()), m_localCapture, SIGNAL(SIG_StartLocalCaptureThread()));
        QObject::connect(this, SIGNAL(SIG_StopLocalCaptureThread()), m_localCapture, SIGNAL(SIG_StopLocalCatureThread()), Qt::QueuedConnection);
    }

    QObject::connect(this, SIGNAL(SIG_CaptureAndDIP()), this, SLOT(SLOT_CaptureAndDIP()));
    QObject::connect(this, SIGNAL(SIG_GetTimeStamp0()), this, SLOT(SLOT_GetTimeStamp0()));
    QObject::connect(this, SIGNAL(SIG_GetTimeStamp1()), this, SLOT(SLOT_GetTimeStamp1()));
    QObject::connect(this, SIGNAL(SIG_NewAlgFireDet()), this, SLOT(SLOT_NewAlgFireDet()));
    QObject::connect(this, SIGNAL(SIG_StopAlgFireDet()), this, SLOT(SLOT_StopAlgFireDet()));
    QObject::connect(this, SIGNAL(SIG_ControlAlg(int,int)), this, SLOT(SLOT_ControAlg(int,int)));
    QObject::connect(this, SIGNAL(SIG_QueryVal(int)), this, SLOT(SLOT_QueryVal(int)));
    QObject::connect(this, SIGNAL(SIG_QueryVal(int)), m_algProcessModule_0, SIGNAL(SIG_QueryStatus(int)), Qt::QueuedConnection);
    QObject::connect(this, SIGNAL(SIG_ControlAlg(int,int)), m_algProcessModule_0, SIGNAL(SIG_ControlAlgStatus(int,int)), Qt::QueuedConnection);
    QObject::connect(this, SIGNAL(SIG_AnswerQuery(int)), this, SLOT(SLOT_AnswerQuery(int)));

    QObject::connect(this, SIGNAL(SIG_StartAlgFireDet(int)), m_algProcessModule_0, SIGNAL(SIG_StartAlgProcess(int)), Qt::QueuedConnection);//old alg module
    QObject::connect(this, SIGNAL(SIG_StopAlgFireDet()), m_algProcessModule_0, SIGNAL(SIG_StopAlgProcess()), Qt::QueuedConnection);
    QObject::connect(this, SIGNAL(SIG_CaptureYUVFile(int)), m_algProcessModule_0, SIGNAL(SIG_CaptureYUVDataFile(int)),Qt::QueuedConnection);
    QObject::connect(m_algProcessModule_0, SIGNAL(SIG_TellUpper(int)), this, SIGNAL(SIG_AnswerQuery(int)), Qt::QueuedConnection);

    //this is the old init of getoutcome with the signal outcomesend to cpw.
    QObject::connect(m_algProcessModule_0, SIGNAL(SIG_SendOutcomeToCPW(QByteArray)), this, SIGNAL(SIG_GetOutcome(QByteArray)), Qt::QueuedConnection);
//    QObject::connect(this, SIGNAL(SIG_StartAlgSmokeDet(void*)), m_algProcessModule_1, SIGNAL(SIG_StartAlgProcess(void*)), Qt::QueuedConnection);

    QObject::connect(this, SIGNAL(SIG_TestThread()), m_testthread, SIGNAL(SIG_StartThread()), Qt::QueuedConnection);

    QObject::connect(ui.pushButton_brightset, SIGNAL(clicked()), this, SLOT(SLOT_SetBrightness()));
    QObject::connect(this, SIGNAL(SIG_SetCameraParameter(int,int, int ,int)), this, SLOT(SLOT_SetCameraParam(int,int,int, int)));
    QObject::connect(this, SIGNAL(SIG_StartAlgDet(int)), this, SLOT(SLOT_StartAlgDet(int)));

    QObject::connect(this, SIGNAL(SIG_GetOutcome(QByteArray)), this, SLOT(SLOT_GetOutcome(QByteArray)));
    QObject::connect(this, SIGNAL(SIG_SetGPIOPin(int,int)), this, SLOT(SLOT_SetGPIOPin(int,int)));

    QObject::connect(this, SIGNAL(SIG_DestroyCPlayWindow()), this, SLOT(SLOT_DestroyCPlayWindow()));
//    QObject::connect(this, SIGNAL(SIG_InitCamera()), this, SLOT(SLOT_InitCamera()));
    printf("Play----------%p----\r\n",this);
    pstaticthis=this;//fucking bad,single obj only

//    gpio_test();

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
//    OSAL_QueueTerminate(&m_imageDataQue_0);

    SeqQueue_Destroy(m_queue_0);
    SeqQueue_Destroy(m_queue_1);
    SeqQueue_Destroy(m_queue_2);
    for(int i = 0; i < MAXBUFFER; i++)
    {
        free(m_IMGYData_0[i].data);
        m_IMGYData_0[i].data = NULL;
        free(m_IMGYData_1[i].data);
        m_IMGYData_1[i].data = NULL;
    }
    for(int i = 0; i < MAXBUFFER; i++)
    {
        free(m_IMGYData_2[i].data);
        m_IMGYData_2[i].data = NULL;
    }

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

//    QMutexLocker lock(&mDisplayLock_0);
    m_ImageOrigin_0 = QImage((uchar *)&m_ImgWithStamp_0.mImageData, IMGWIDTH, IMGHEIGHT, QImage::Format_Indexed8);
    m_ImageAlg_0 = QImage((uchar *)&CPlayWindow::m_ImgScale_0.mImageData, IMGWIDTH, IMGHEIGHT, QImage::Format_Indexed8);

    m_ImageOrigin_1 = QImage((uchar *)&m_ImgWithStamp_1.mImageData, IMGWIDTH, IMGHEIGHT, QImage::Format_Indexed8);
    m_ImageAlg_1 = QImage((uchar *)&CPlayWindow::m_ImgScale_1.mImageData, IMGWIDTH, IMGHEIGHT, QImage::Format_Indexed8);

    m_ImageOrigin_0.setColorTable(m_grayTable);
    m_ImageAlg_0.setColorTable(m_grayTable);


    m_ImageOrigin_1.setColorTable(m_grayTable);
    m_ImageAlg_1.setColorTable(m_grayTable);

    qlonglong stamp_0 = m_ImgWithStamp_0.stamp/1000;
    qlonglong stamp_1 = m_ImgWithStamp_1.stamp/1000;

    QString strstamp_0 = QString::number(stamp_0);
    QString strstamp_1 = QString::number(stamp_1);

    QPixmap pixalg_0, pixorigin_0;
//    pix.load(":/images/image/home.png");
    pixorigin_0 = QPixmap::fromImage(m_ImageOrigin_0);
    pixalg_0 = QPixmap::fromImage(m_ImageAlg_0);

    QPixmap pixalg_1, pixorigin_1;
    pixorigin_1 = QPixmap::fromImage(m_ImageOrigin_1);
    pixalg_1 = QPixmap::fromImage(m_ImageAlg_1);

    painter.drawPixmap(480,100,320,180, pixorigin_0);
    painter.drawPixmap(100,100,320,180, pixalg_0);
    painter.drawText(480, 200, strstamp_0);

    painter.drawPixmap(480,320,320,180, pixorigin_1);
    painter.drawPixmap(100,320,320,180, pixalg_1);
    painter.drawText(480, 420, strstamp_1);

}

void CPlayWindow::SLOT_DestroyCPlayWindow()
{

    qDebug() << "3 CPlayWindow::SLOT_DestroyCPlayWindow()";
    if(m_algProcessModule_0 != 0)
    {
        qDebug() << "3 CPlayWindow::SLOT_DestroyCPlayWindow()---emit SIG_StopAlgFireDet()";
        emit SIG_StopAlgFireDet();
    }

    if(m_algProcessModule_1 != 0)
    {

    }

    this->deleteLater();
}

void CPlayWindow::startRecord()
{
#if defined(Q_OS_LINUX)
    //int cycltime;
    char bufname[512];
   // int cx,cy;
    printf("startRecord--------------\r\n");
    QMutexLocker locker(&mObjectLock);

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
                p_dvr->setCallbacks(usernotifyCallback,userdataCallback,userdataCallbackTimestamp_0,p_dvr/* must dvr obj*/ /*dump*/);
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



void CPlayWindow::stopRecord()
{
    dvr_factory *pdvr0 = dvrCamera[0].dvr;
    dvr_factory *pdvr1 = dvrCamera[1].dvr;
    if(pdvr0 != NULL)
    {
        pdvr0->stopRecord();
    }
    if(pdvr1 != NULL)
    {
        pdvr1->stopRecord();
    }


}

void CPlayWindow::captureAndDIPAndRtsp()
{

#if 1
    qDebug() << "3 current camera is:" << cur_camera << "---------captureAndDIPAndRtsp";
#if defined(Q_OS_LINUX)

    if(SUPPORT_CAMERA_NUM<2)
        return;
//can't set camera here.
//    CPLaySetCamera(0);
//    CPLaySetCamera(1);
    dvr_factory * p_dvr_0=dvrCamera[0].dvr;
    dvr_factory * p_dvr_1=dvrCamera[1].dvr;

    if(dvrCamera[0].getPreview())
    {
        p_dvr_0->stopPriview();
        dvrCamera[0].setPreview(false);
    }

    if(dvrCamera[1].getPreview()){
        p_dvr_1->stopPriview();
        dvrCamera[1].setPreview(false);
    }

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
        if(!dvrCamera[0].getRecord())
        {
            sprintf(bufname,"%d",0);
            rt = p_dvr_0->recordInit(bufname);
            config_set_heigth(0, IMGHEIGHT);//720
            config_set_weith(0, IMGWIDTH);//1280

            p_dvr_0->SetDataCB(usr_datacb_0,p_dvr_0);
            p_dvr_0->setCallbacks(usernotifyCallback,userdataCallback,userdataCallbackTimestamp_0,p_dvr_0 /*dump*/);

            p_dvr_0->prepare();
            p_dvr_0->start();
//#ifdef WATERMARKORI
//            p_dvr_0->enableWaterMark();
//            sprintf(bufname,"64,64,0,64,250,CAPTURE SDK,64,450,IVFD V2.0a");
//            p_dvr_0->setWaterMarkMultiple(bufname);
//#endif
            p_dvr_0->enableWaterMark();
            p_dvr_0->startRecord();//test for not mmc20181101
            isaf=true;
            dvrCamera[0].setRecord(true);
        }

        if(!dvrCamera[0].getPreview())
        {
            struct view_info vv= {0,0,VIEW_WEITH,VIEW_HEIGHT};
            p_dvr_0->startPriview(vv);
            dvrCamera[0].setPreview(true);
        }

        if(!dvrCamera[1].getRecord())
        {
            sprintf(bufname,"%d",1);
            rt= p_dvr_1->recordInit(bufname);
            config_set_heigth(1, IMGHEIGHT);//720//1080
            config_set_weith(1, IMGWIDTH);//1280//1920
            rt= p_dvr_1->recordInit("1");

            p_dvr_1->SetDataCB(usr_datacb_1,p_dvr_1);
            p_dvr_1->setCallbacks(usernotifyCallback,userdataCallback,userdataCallbackTimestamp_1,p_dvr_1 /*dump*/);
            p_dvr_1->prepare();
            p_dvr_1->start();
#ifdef CAMERA_PARAM
//            CPLaySetCamera(0);
//            CPLaySetCamera(1);
            QThread::msleep(300);
        //hxy
//        set_camera_param_bge(p_dvr_0, 6, 50, 50);
//        set_camera_param_bge(p_dvr_1, 6, 50, 50);
//        QThread::msleep(3000);

#endif
            p_dvr_1->disableWaterMark();
//            p_dvr_1->enableWaterMark();
            p_dvr_1->startRecord();//test for not mmc
//            isaf=true;
            dvrCamera[1].setRecord(true);
        }

        if(!dvrCamera[1].getPreview())
        {
            struct view_info vv= {0,0,VIEW_WEITH,VIEW_HEIGHT};
            p_dvr_1->startPriview(vv);
            dvrCamera[1].setPreview(true);
        }

        if(rt!=0)
        {
            sleep(1);
            continue;
        }
        if(m_flagCameraSetChanged == 0){

        }else{//must first dark ,second others values wanggy 190530
            set_camera_param_bge(p_dvr_1, 1, 1, 0);
            QThread::msleep(100);
            set_camera_param_bge(p_dvr_1, 2, 1, 0);
            QThread::msleep(100);
            CPLaySetCamera(0);//this is the mono camera,test for cameraset 1107
            CPLaySetCamera(1);//this is the color camera
        }

        sleep(1);//temp add here,must use timestamp for response gap,i will impl next version

#ifdef RECORD_TEST
//        p_dvr_0->startRecord();
//        p_dvr_1->startRecord();
#endif

#ifdef RTSPENABLE
        int result = 0;
        pthread_t tid_lock_socket_0;
        pthread_t tid_lock_socket_1;
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

        pthread_t tid_send_h264;
        int streamnum_0 = 0;
        int streamnum_1 = 1;
        printf("start!\n");
        pthread_create(&tid_lock_socket_0, &attr, thread_local_socket, &streamnum_0);
        pthread_create(&tid_lock_socket_1, &attr, thread_local_socket, &streamnum_1);
//        pthread_create(&tid_lock_socket_1, &attr, thread_local_file, NULL);

        pthread_detach(tid_lock_socket_0);
        pthread_detach(tid_lock_socket_1);
#endif
        sleep(1);
    }
#endif
#endif
//    emit SIG_InitCamera();//
    return ;
}



void CPlayWindow::SLOT_CmdFromBrowser(QString module, QString cmd)
{
    qDebug() << "-------- CPlayWindow Get the cmd from Browser-----" << QThread::currentThread();
    qDebug() << module;
    enum ECMDTYPE cmdtype;
}



void CPlayWindow::SLOT_CaptureAndDIP()
{

    qDebug() << "-------CPlayWindow BtnRtsp switch clicked---------------"<< QThread::currentThread();
    captureAndDIPAndRtsp();

    QEventLoop loop;
    QTimer::singleShot(10, &loop, SLOT(quit()));
    loop.exec();

    QByteArray ba;
    GeneralMsg *gmsg = (GeneralMsg *)malloc(sizeof(GeneralMsg));
    gmsg->source = 3;
    gmsg->dest = 4;//4 = the client
    gmsg->msgid = 1;//0=tell the main weather dip is running
    gmsg->type = 2;//cmd
    if(m_onwatchstatus == 1){
        gmsg->val = 5;//0:not running;1:running;101,algtype&&xxx&&onwatchstatus
    }else {
        gmsg->val = 4;//100,last 0 means onwatchstatus == 0;
    }

    ConvertGenalMsgToByteArray(gmsg, &ba);
    GeneralMsg *msg = (GeneralMsg *)ba.data();

    qDebug() << msg->source << msg->dest << msg->msgid << msg->type << msg->val << " sdmtv";

    emit SIG_SendMsgToUITcpClient(ba, ba);
    QLog_("dip", InfoLevel, "begin a new capture and dip!");//directory is /mnt/.../sdcard/1/logs/
    free(gmsg);

    //send a signal to main local tcpserver
}



void CPlayWindow::CPlayCallbackTimestamp_0(nsecs_t timestamp, int32_t msgType, char *dataPtr, void *user)
{
    int retqueData = 0 ;
    char *ptemp = dataPtr;
    VencInputBuffer *myData = (VencInputBuffer *)(ptemp + 4);
//    android::Mutex::Autolock lock(mDisplayLock_0);
    QMutexLocker lock(&mDisplayLock_0);

    //old
    int imagesize = m_imageSize;
    memcpy((uchar *)&(m_ImgWithStamp_0.mImageData), (uchar *)(myData->pAddrVirY), imagesize/*(myData->nFlag)*2/3*/);

    m_ImgWithStamp_0.stamp = myData->nPts;
//    emit SIG_UpdateTimeStamp(myData->nPts);

    IMGYData *imgYData = (IMGYData *)&(m_IMGYData_0[0]);//make imgYData point to the first address of m_IMGYData_0[]

    if(myData == NULL || imgYData == NULL)
    {
        qDebug("no right address malloced---");
        return;
    }

    //find the unused address and o malloc
    for(int i = 0; i < (MAXBUFFER); i++)
    {
//        qDebug("mid = %d , mrflag = %d", imgYData->mid, imgYData->mrwFlag) ;
        if(imgYData->mrwFlag == 0 && imgYData->mid == i)
        {
            if(imgYData->data != NULL)
            {
//                qDebug("the address malloced = %x mid = %d ", imgYData->data, imgYData->mid);
                memcpy(imgYData->data, myData->pAddrVirY, m_imageSize);
                imgYData->stamp = myData->nPts;
                imgYData->mrwFlag = 1;
                retqueData = SeqQueue_Append(m_queue_0, imgYData);
                if(retqueData == -1){
                    qDebug() <<"list == NULL || node == NULL!";
                }else if(retqueData == -2){
                    qDebug() <<"pos<0 || pos>=tList->capacity,full!";
                }else if(retqueData == -3){
                    qDebug() <<"pos<0 || pos>=tList->capacity, pos wrong!";
                }
                break;
            }else
            {
//                qDebug() << "CPlayWindow::CPlayCallbackTimestamp_0:imgYData->data == NULL";
//                qDebug("%s:%d:%s: CPlayWindow::CPlayCallbackTimestamp_0:imgYData->data == NULL\n", __FILE__, __LINE__, __func__);
            }

        }else
        {
            //if enter this, means that the data still not be processed;
//            qDebug() << "CPlayWindow::CPlayCallbackTimestamp_0:imgYData->mrwFlag == "<< imgYData->mrwFlag << " imgYData->mid == " << imgYData->mid << "---" << i;
        }
        imgYData++;
    }
//    qDebug() << "update";
//    pstaticthis->update();
    if(retqueData != 0)
    {
        qDebug() << "retqueData !=0 =" << retqueData;
        if(retqueData == -2)//full
        {
//            SeqQueue_Clear(m_queue_0);
            qDebug() << "CPlayWindow::CPlayCallbackTimestamp_0:que is full ";
        }

        return;
    }

    //old
    QThread::msleep(1);

}

void CPlayWindow::CPlayCallbackTimestamp_1(nsecs_t timestamp, int32_t msgType, char *dataPtr, void *user)
{
//    qDebug() << "3 CPlayWindow::CPlayCallbackTimestamp_1";
    int retqueData = 0 ;
    char *ptemp = dataPtr;
    VencInputBuffer *myData = (VencInputBuffer *)(ptemp + 4);
    QMutexLocker lock(&mDisplayLock_1);
    int imgsize = m_imageSize;
    memcpy((uchar *)&(m_ImgWithStamp_1.mImageData), (uchar *)(myData->pAddrVirY), imgsize/*(myData->nFlag)*2/3*/);
    m_ImgWithStamp_1.stamp = myData->nPts;
//    emit SIG_UpdateTimeStamp(myData->nPts);

    IMGYData *imgYData = (IMGYData *)&(m_IMGYData_1[0]);//make imgYData point to the first address of m_IMGYData_1[]

    if(myData == NULL || imgYData == NULL)
        return;
    //find the unused address and o malloc
    for(int i = 0; i < (MAXBUFFER); i++)
    {
//        qDebug("mid = %d , mrflag = %d", imgYData->mid, imgYData->mrwFlag) ;
        if(imgYData->mrwFlag == 0 && imgYData->mid == i)
        {
            if(imgYData->data != NULL)
            {
                memcpy(imgYData->data, myData->pAddrVirY, m_imageSize);
                imgYData->stamp = myData->nPts;
                imgYData->mrwFlag = 1;
                retqueData = SeqQueue_Append(m_queue_1, imgYData);
                if(retqueData == -1){
                    qDebug() <<"list == NULL || node == NULL!";
                }else if(retqueData == -2){
                    qDebug() <<"pos<0 || pos>=tList->capacity,full!";
                }else if(retqueData == -3){
                    qDebug() <<"pos<0 || pos>=tList->capacity, pos wrong!";
                }
                break;
            }

        }
        imgYData++;
    }
    //push into the que

//    pstaticthis->update();
    if(retqueData != 0)
    {
        qDebug() << "retqueData !=0 =" << retqueData;
        if(retqueData == -2)//full
        {
            SeqQueue_Clear(m_queue_0);
        }

        return;
    }

    QThread::msleep(1);
}

void CPlayWindow::SLOT_GetTimeStamp0()
{
    qDebug() << "3 Get a TimeStamp in the thread:-----" << QThread::currentThread() ;

    qlonglong timestamp = m_ImgWithStamp_0.stamp;

    QByteArray msg = QByteArray::number(timestamp, 10);


    qDebug() << "0 start to emit msgtotopui" << timestamp << "-----" << msg;
    emit SIG_MsgToTopUi(msg);
    return ;
}

void CPlayWindow::SLOT_GetTimeStamp1()
{
    qDebug() << "3 Get a TimeStamp in the thread:-----" << QThread::currentThread() ;

    qlonglong timestamp = m_ImgWithStamp_1.stamp;

    QByteArray msg = QByteArray::number(timestamp, 10);


    qDebug() << "3 start to emit msgtotopui" << timestamp << "-----" << msg;
    emit SIG_MsgToTopUi(msg);
    return ;
}



qlonglong CPlayWindow::CPlayGetCurrentUTCStamp_0()
{
    if(m_ImgWithStamp_0.stamp != 0)
    {
        return m_ImgWithStamp_0.stamp;
    }
}

qlonglong CPlayWindow::CPlayGetCurrentUTCStamp_1()
{
    if(m_ImgWithStamp_1.stamp != 0)
    {
        return m_ImgWithStamp_1.stamp;
    }
}




void CPlayWindow::CPLaySetCamera(int idname)
{

    QVariant keyval;
    GetCFG(IVFDCAM_INI, "cameraset", "brightness0", &keyval);
    int brightness0 = keyval.toInt();
    GetCFG(IVFDCAM_INI, "cameraset", "gain0", &keyval);
    int gain0 = keyval.toInt();
    GetCFG(IVFDCAM_INI, "cameraset", "saturation0", &keyval);
    int saturation0 = keyval.toInt();
    GetCFG(IVFDCAM_INI, "cameraset", "exposure0", &keyval);
    int exposure0 = keyval.toInt();
    GetCFG(IVFDCAM_INI, "cameraset", "brightbalance0", &keyval);
    int brightbalance0 = keyval.toInt();

    GetCFG(IVFDCAM_INI, "cameraset", "brightness1", &keyval);
    int brightness1 = keyval.toInt();
    GetCFG(IVFDCAM_INI, "cameraset", "gain1", &keyval);
    int gain1 = keyval.toInt();
    GetCFG(IVFDCAM_INI, "cameraset", "saturation1", &keyval);
    int saturation1 = keyval.toInt();
    GetCFG(IVFDCAM_INI, "cameraset", "exposure1", &keyval);
    int exposure1 = keyval.toInt();
    GetCFG(IVFDCAM_INI, "cameraset", "brightbalance1", &keyval);
    int brightbalance1 = keyval.toInt();

    dvr_factory * p_dvr_0=dvrCamera[0].dvr;
    dvr_factory * p_dvr_1=dvrCamera[1].dvr;
    switch(idname)
    {
    case 0:
    {
        if(p_dvr_0 != NULL)
        {
            set_camera_param_bge(p_dvr_0, 0, brightness0, 0);
            QThread::msleep(100);
            set_camera_param_bge(p_dvr_0, 1, gain0, 0);
            QThread::msleep(100);
            set_camera_param_bge(p_dvr_0, 3, saturation0, 0);
            QThread::msleep(100);
            set_camera_param_bge(p_dvr_0, 2, exposure0, 0);
            QThread::msleep(100);
            set_camera_param_bge(p_dvr_0, 5, brightbalance0, 0);
            qDebug() << "3 CPlayWindow::CPLaySetCamera(0)";
        }
        break;
    }
    case 1://for mono
    {
        if(p_dvr_1 != NULL)
        {
            if(brightness1 != 1)
            {
                brightness1 = 1;//force to set 1;
            }
            set_camera_param_bge(p_dvr_1, 0, brightness1, 0);
            QThread::msleep(100);
            set_camera_param_bge(p_dvr_1, 1, gain1, 0);
            QThread::msleep(100);
            set_camera_param_bge(p_dvr_1, 3, saturation1, 0);
            QThread::msleep(100);
            set_camera_param_bge(p_dvr_1, 2, exposure1, 0);
            QThread::msleep(100);
            set_camera_param_bge(p_dvr_1, 5, brightbalance1, 0);
        }
        break;
    }
    default:
    {
        qDebug() << "2 CPlayWindow::CPLaySetCamera: not right id !";
    }
    }
}


void CPlayWindow::SLOT_SetBrightness(void)
{
    int brightval = ui.horizontalSlider_bn->value();
    int contrastval = ui.horizontalSlider_contrast->value();
    int saturationval = ui.horizontalSlider_saturation->value();
    qDebug() << brightval << "---" << contrastval << "-----" << saturationval;

    dvr_factory * p_dvr_0=dvrCamera[0].dvr;
    dvr_factory * p_dvr_1=dvrCamera[1].dvr;
#ifdef CAMERA_PARAM
        //hxy
        set_camera_param_bge(p_dvr_0, brightval, contrastval, saturationval);
        set_camera_param_bge(p_dvr_1, brightval, contrastval, saturationval);
#endif

}
//here to set the cameraparam,  this is response to the browser client request.
void CPlayWindow::SLOT_SetCameraParam(int cameraname, int val1, int val2, int val3)//this is cameraval from main tcpclient
{
    switch(cameraname)
    {
    case 0:
    {
        dvr_factory * p_dvr_0=dvrCamera[0].dvr;
        qDebug() << "start change the camer0 parameter";
#ifdef CAMERA_PARAM
        set_camera_param_bge(p_dvr_0, val1, val2, val3);
#endif
        break;
    }
    case 1:
    {
        qDebug() << "start change the camer1 parameter";
        dvr_factory * p_dvr_1=dvrCamera[1].dvr;
#ifdef CAMERA_PARAM
        set_camera_param_bge(p_dvr_1, val1, val2, val3);
#endif
    }
    case 2:
    {

        break;
    }
    }
}
//function to start algdet, algId = 1 for fire, 2 for smoke, 0 for intrude;
void CPlayWindow::SLOT_StartAlgDet(int algId)
{
    switch(algId)
    {
    case 1:
    {
        emit SIG_StartAlgFireDet(0);//0 for no reverse, 1 for reverse, reverse flag
        break;
    }
    case 2:
    {
        break;
    }
    }
}

void CPlayWindow::SLOT_GetOutcome(QByteArray msg)
{
//    emit SIG_SendMsgToUITcpClient(msg.toLatin1(), msg.toLatin1());
    emit SIG_SendMsgToUITcpClient(msg, msg);
}


void CPlayWindow::SLOT_SetGPIOPin(int pin, int val)
{
    qDebug() << "3 CPlayWindow::SLOT_SetGPIOPin";
//    gpio_export(pin);
    gpio_direction(pin, 1);
    gpio_write(pin, val);

}

void CPlayWindow::SLOT_NewAlgFireDet()
{
    qDebug() << "3 old algdet stopped, now create a new firedet!";
    if(m_algProcessModule_0 != NULL)
    {
        qDebug() << "algfire det is busy!";
        return;
    }

    m_algProcessModule_0 = new IVFDAlgFire(0);//this is the new alg module ,so should redo connect signal again.
    if(m_algProcessModule_0 != NULL)
    {
        QObject::connect(this, SIGNAL(SIG_StartAlgFireDet(int)), m_algProcessModule_0, SIGNAL(SIG_StartAlgProcess(int)), Qt::QueuedConnection);
        QObject::connect(this, SIGNAL(SIG_StopAlgFireDet()), m_algProcessModule_0, SIGNAL(SIG_StopAlgProcess()), Qt::QueuedConnection);
        QObject::connect(m_algProcessModule_0, SIGNAL(SIG_SendOutcomeToCPW(QByteArray)), this, SIGNAL(SIG_GetOutcome(QByteArray)), Qt::QueuedConnection);
        QObject::connect(m_algProcessModule_0, SIGNAL(SIG_NoCaptureData()), this, SLOT(SLOT_DestroyCPlayWindow()), Qt::QueuedConnection);
    }
}

void CPlayWindow::SLOT_StopAlgFireDet()
{

    qDebug() << "stop the algfiredet!";

}

void CPlayWindow::SLOT_ControAlg(int id, int val)//main send a cmd to open/close the dip alg process
{
    qDebug() << "3 CPlayWindow::SLOT_ControAlg(int id, int val):id = " << id << " val = " << val;
    if(id == 13){
        CPlayWindow::m_onwatchstatus = val;
        qDebug() << "m_onwatchstatus = " << val;
    }

}

void CPlayWindow::SLOT_QueryVal(int type){
    qDebug() << "3 CPlayWindow::SLOT_QueryVal(int type) type = " << type;

}

void CPlayWindow::SLOT_AnswerQuery(int val)//now use to tell main that dip process is ready,with some important info,
{

    qDebug() << "3 CPlayWindow::SLOT_AnswerQuery(int val) val = " << val;

    GeneralMsg dipreadymsg;
    QByteArray ba_dipready;
    dipreadymsg.source = 3;
    dipreadymsg.dest = 0;
    dipreadymsg.type = 1;
    dipreadymsg.msgid = 3;
    dipreadymsg.val = val;

//    int source;//0=main 1=http, 2=ftp, 3=dip 4=client
//    int dest;//0=main 1=http, 2=ftp, 3=dip 4=client
//    int type;//0=cmd,1=status;
//    int msgid;//defined by user;
//    int val;//defined by user;

    ConvertGenalMsgToByteArray(&dipreadymsg, &ba_dipready);

    emit SIG_SendMsgToUITcpClient(ba_dipready, ba_dipready);
}
