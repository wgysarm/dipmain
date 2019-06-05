#ifdef SDKLIB_TEST
#include <linux/videodev2.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <poll.h>	//hxy
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <linux/fb.h>

//#include "drv_disp.h"
//#include "dragonboard_inc.h"
#include "hwdisp2.h"
#include "aw_ini_parser.h"

#include <sdklog.h>

#include "CameraDebug.h"
#include "hwdisp2.h"



#include "V4L2CameraDevice2.h"
#include "CallbackNotifier.h"
#include "PreviewWindow.h"
#include "CameraHardware2.h"
#include "HALCameraFactory.h"
#include "CameraHardwareInterface.h"
#ifdef REC_ENCODE
#include "awrecorder.h"

#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>

#include <sys/time.h>
#include "log.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vencoder.h"
#include "CdxMuxer.h"
#include <time.h>

#include "Rtc.h"
#include "StorageManager.h"
#include "DvrFactory.h"



using namespace android;
status_t usr_datacb(int32_t msgType,
                    char *dataPtr,int dalen,
                    void *user)
{

    return 0;
}
//dvr_factory dvr;
dvr_factory *pdvr=NULL;
dvr_factory *pdvr1=NULL;


//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////added by hxy/////////////////////////////////////////////////////////////
#define GPIO_TEST
#define CAMERA_PARAM

#define GPIO_EXAMPLE_OUT 238
#define GPIO_EXAMPLE_INT 244


#ifdef CAMERA_PARAM
static int set_camera_param(dvr_factory *dvr, int brightness,int contrast,int saturation)
{
    return dvr->setAnalogInputColor(brightness, contrast, saturation);
}
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
    gpio_export(GPIO_EXAMPLE_OUT);
    gpio_direction(GPIO_EXAMPLE_OUT, 1);
    gpio_write(GPIO_EXAMPLE_OUT, 1);

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
///////////////////////////////////end added/////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

void usernotifyCallback(int32_t msgType, int32_t ext1,
                        int32_t ext2, void* user)
{

    LOGE("msgType =%d-----data=%p-----%d)",msgType,user);

    if ((msgType&CAMERA_MSG_ERROR) ==CAMERA_MSG_ERROR)
    {
        LOGE("(msgType =CAMERA_MSG_ERROR)");

    }

    if ((msgType&CAMERA_MSG_DVR_STORE_ERR) ==CAMERA_MSG_DVR_STORE_ERR)
    {
        LOGE("msgType =CAMERA_MSG_DVR_STORE_ERR)");
        dvr_factory *p_dvr=(dvr_factory *)user;
        p_dvr->storage_state=0;//tmp
        p_dvr->stopRecord();
    }

//return NO_ERROR;

}
void userdataCallback(int32_t msgType,
                      char* dataPtr, camera_frame_metadata_t *metadata, void* user)
{
    //LOGE("userdataCallback=-----------)");

    //return NO_ERROR;
}

void userdataCallbackTimestamp(nsecs_t timestamp,
                                   int32_t msgType, char* dataPtr, void* user)
{

       char *ptp=(char *)dataPtr;
       VencInputBuffer *p=(VencInputBuffer *)(ptp+4);
      // memcpy(inputBuffer.pAddrVirY,(unsigned char*)p->pAddrVirY,encode_param.src_width*encode_param.src_height);
      // memcpy(inputBuffer.pAddrVirC,(unsigned char*)p->pAddrVirY+encode_param.src_width*encode_param.src_height,encode_param.src_width*encode_param.src_height/2);
}
#ifdef ADAS_ENABLE
void userAdasDataCallback(int32_t msgType,
                            char *dataPtr,
                            void *metadata,
                            void* user)

{
    if(CAMERA_MSG_ADAS_METADATA == msgType){
        ADASOUT_IF * padasResult=(ADASOUT_IF *)metadata;
        //LOGV("userAdasDataCallback ,hi i get some adas result vanishLine =%f",padasResult->ldw_result.autoCalVanishLine);
        //padasResult->ldw_result
        //padasResult->fcw_result

    }

}
#endif

extern "C" int aut_adb_main(int argc, char **argv);
#define USE_AW_360 1

int adb_service_main (void *param)
{
#if 0
    system("cat /sys/bus/platform/devices/usbc0.2/usb_device");
    system("echo 0 > /sys/class/android_usb/android0/enable");
    system("echo 1f3a > /sys/class/android_usb/android0/idVendor");
    system("echo 1002 > /sys/class/android_usb/android0/idProduct");
    system("echo \"mass_storage,adb\" > /sys/class/android_usb/android0/functions");
    system("echo 1 > /sys/class/android_usb/android0/enable");
#endif
    aut_adb_main(0, 0);
}
#define RECORD_TEST 1
//#define adb_service

#define TEST_CAMERA_ID 0

#define TEST_CAMERA_ID_T1 0
#define TEST_CAMERA_ID_T2 1


#ifdef adb_service
int main(int argc,char *argv[])
{

    aut_adb_main(0, 0);
}
#else
//#define ANOTHER_CAMERA_TEST 1



int main(int argc,char *argv[])
{

    HwDisplay* mcd=NULL;
    //test screen mode
    //0 disable ,1 tvout pal ;2 tvout ntsc;3 hdmi 1280x720;4 hdmi 1920x1080
    int tvmode=3;
    //config_set_tvout(TEST_CAMERA_ID,tvmode);

    mcd=HwDisplay::getInstance();


#ifdef GPIO_TEST
    //hxy
    gpio_test();
#endif


    pgEmulatedCameraFactory=new HALCameraFactory();
    //sleep(4);
    pdvr=new dvr_factory();
#ifdef ANOTHER_CAMERA_TEST
    pdvr1=new dvr_factory();
#endif
    //int result;

    tvmode=config_get_tvout(TEST_CAMERA_ID);
    printf("--------------tvmode =%d \r\n",tvmode);
    mcd->hwd_screen1_mode(tvmode);//for dual disp at the same time
    //mcd->hwd_tvout();//tv ntsc
    //mcd->hwd_hdmiout();//720p
    //mcd->hwd_other_screen(0,DISP_OUTPUT_TYPE_HDMI,DISP_TV_MOD_1080P_60HZ);//1080p
    //mcd->hwd_other_screen(0,DISP_OUTPUT_TYPE_TV,DISP_TV_MOD_PAL);
    #if 0
    if(tvmode==6)
    {
        mcd->hwd_tvout();
    }
    else if (tvmode==3)
    {
        mcd->hwd_hdmiout();
    }
    #endif
    int i=1;
    int flag360=0;
    printf("--------------argc =%d \r\n",argc);
    if(argc >1)
    {
        flag360=1;
        printf("------------argv =%s \r\n",argv[1]);

    }
    printf("get bootup param 1st is %d \r\n",config_get_startup(0));
    config_set_startup(TEST_CAMERA_ID,1);
    printf("get bootup param 2nd is %d \r\n",config_get_startup(0));
    config_set_startup(TEST_CAMERA_ID,0);
    printf("get bootup param 3rd is %d \r\n",config_get_startup(0));
    //aut_adb_main(0, 0);

#if 0
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    errno = 0;
    pthread_t thread;
    int result = pthread_create(&thread, &attr,
                    (void* (*)(void*))adb_service_main, NULL);
    pthread_attr_destroy(&attr);
#endif

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
                   config_set_heigth(TEST_CAMERA_ID,720);
                   config_set_weith(TEST_CAMERA_ID,1280);
                   rt= pdvr->recordInit("0");
                   #ifdef ANOTHER_CAMERA_TEST
                   config_set_heigth(1,720);
                   config_set_weith(1,1280);
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
        //pdvr->prepare();
        pdvr->start();

#ifdef CAMERA_PARAM
        //hxy
        set_camera_param(pdvr, 50, 50, 50);
#endif


#ifdef ADAS_ENABLE

        // setAdasParameters(int key,int value);
        //pdvr->setAdasCallbacks(userAdasDataCallback);
        //pdvr->enableAdas();

#endif


        //dvr.set_rtsp_to_file(0);//test !!!! if 1 wirite to encode stream to file . must start before start_rtsp
        //dvr.start_rtsp(); //not support now

        //vv for viewer's view
       // struct view_info vv= {0,0,mcd->lcdxres,mcd->lcdyres};
        struct view_info vv= {0,0,720,480};
        ALOGV("vx=%d vy=%d sx=%d sy%d",mcd->lcdxres,mcd->lcdyres,pdvr->recordwith,pdvr->recordheith);
        pdvr->startPriview(vv);

        //sleep(10);
        #ifdef ANOTHER_CAMERA_TEST
        if(flag360){
                   sleep(5);
                   config_set_heigth(TEST_CAMERA_ID,720);
                   config_set_weith(TEST_CAMERA_ID,1280);
                   //F_LOG;
                   //sleep(10);

                   rt= pdvr1->recordInit("0");
                   F_LOG;
                   sleep(10);
            }

        pdvr1->SetDataCB(usr_datacb,pdvr1);
        F_LOG;
//sleep(10);
        pdvr1->setCallbacks(usernotifyCallback,userdataCallback,userdataCallbackTimestamp,pdvr1 /*dump*/);
        F_LOG;
//sleep(10);
        //pdvr->prepare();
        pdvr1->start();
#endif
#ifdef ADAS_ENABLE
#ifdef ANOTHER_CAMERA_TEST

        // setAdasParameters(int key,int value);
        pdvr1->setAdasCallbacks(userAdasDataCallback);
        pdvr1->enableAdas();
#endif
#endif

#ifdef RECORD_TEST
        pdvr->startRecord();

#ifdef ANOTHER_CAMERA_TEST
    pdvr1->startRecord();

#endif
#endif

#ifndef SONIX_USB
        pdvr->enableWaterMark();
        //sleep(1);
        sprintf(bufname,"64,64,0,64,250,T3L SDK,64,450,asteroid %d",i);
        pdvr->setWaterMarkMultiple(bufname);
#endif
//sleep(30);

#ifdef ANOTHER_CAMERA_TEST

    pdvr->stopPriview();
    sleep(5);
    pdvr->startPriview(vv);
    sleep(5);
    pdvr->stopPriview();

    sleep(5);
    pdvr1->startPriview(vv);
#endif

        sleep(800);

#ifdef ADAS_ENABLE
        pdvr1->disableAdas();
#endif

#ifdef RECORD_TEST
        pdvr->stopRecord();
#ifdef ANOTHER_CAMERA_TEST
    pdvr1->stopRecord();
    pdvr1->stopPriview();

#endif

#endif
        F_LOG;
        pdvr->stop();
        F_LOG;
        pdvr->enc_de_init();
        F_LOG;
        pdvr->uninitializeDev();
        F_LOG;
#ifdef ANOTHER_CAMERA_TEST
F_LOG;
pdvr1->stop();
F_LOG;
pdvr1->enc_de_init();
F_LOG;
pdvr1->uninitializeDev();
F_LOG;

#endif
        sleep(2); //now this needed fix next version
        //pthread_create();
    }
    delete pdvr;
#ifdef ANOTHER_CAMERA_TEST
delete pdvr1;

#endif
    delete pgEmulatedCameraFactory;
    return 0;


}
#endif
#endif


