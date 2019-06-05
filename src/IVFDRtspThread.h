#ifndef IVFDRTSPTHREAD
#define IVFDRTSPTHREAD
#include "CPlayWindow.h"
#include <QPushButton>
#include <QDebug>
#include "IVFDUiDesign.h"
#include <QThread>
#include <QMutex>
#include <QWaitCondition>
//#include <opencv/highgui.h>
//#include <opencv2/core/core.hpp>

#define	SDKLIB_TEST
#ifdef SDKLIB_TEST
#include <linux/videodev2.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <linux/fb.h>
#include "pthread.h"

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
#endif

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
#include <poll.h>
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

// by wanggy
#define WANGGY
#define RTSPENABLE 1
#define IMGPROCESS 0
#define OPENCVYES
#define CAMERA_PARAM

#ifdef WANGGY
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <sys/stat.h>
#include <time.h>
#include <pthread.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <errno.h>
#include <sys/un.h>

#define UNIX_DOMAIN_0 "/tmp/rtsph264.sock"
#define UNIX_DOMAIN_1 "/tmp/rtsph264Second.sock"
//#define UNIX_DOMAIN "/tmp/rtsph264.sock"
#define UNIX_DOMAIN_3 "/tmp/rtsph264Second.sock"

#define	H264_FILE_NALE "/mnt/sdcard/mmcblk1p1/1/yuv_file.h264"

typedef struct framehead
{
    char bySync;
    char byType;
    char byReserve[2];
    int dwTimeStamp;
    int dwDataLen;

#define FRAME_HEAD_SYNC 0x47
#define FRAME_DATA_TYPE 0x1

} tFrameHead;

#define RECV_TIMEOUT 2
#define BUF_SIZE 4096
//int is_exit = 0;
static int is_exit = 0;

static int send_sock_rtsp_0 = -1;
static int send_sock_rtsp_1 = -1;

static int send_sock = -1;
static int connect_0_once = 0;
static int connect_1_once = 0;
#endif




static void usernotifyCallback(int32_t msgType, int32_t ext1,
                        int32_t ext2, void* user);

static void userdataCallback(int32_t msgType,
                      char* dataPtr, camera_frame_metadata_t *metadata, void* user);
static void userdataCallbackTimestamp(nsecs_t timestamp,
                               int32_t msgType, char* dataPtr, void* user);
//for preview SetDataCB
static status_t usr_h264datacb(int32_t msgType,
                        char *dataPtr,int dalen,
                        void *user);
//for rtsp set SetDataCB
static status_t usr_datacb(int32_t msgType,
                    char *dataPtr,int dalen,
                    void *user);

static void *thread_local_socket(void *);

static void *thread_imgprocess(void *);

#endif // IVFDRTSPTHREAD

