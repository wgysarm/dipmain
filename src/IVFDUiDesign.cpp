#include "IVFDUiDesign.h"
#include "CPlayWindow.h"
#include <QPushButton>
#include <QHBoxLayout>

#include <QString>
#include <QFile>
#include <QDebug>
#include <QThread>
#include <QFile>
#include <QProcess>
#include <QRegExp>
#include <QRegExpValidator>

#include "IvfdLogger.h"
#include "IVFDEvent.h"

#include <stdio.h>
#include <stdlib.h>
#include <linux/videodev2.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <string.h>

int fd;/*设备号*/
//#define IVFDINIT_INI "/data/ivfdinit.ini"
#define IVFDINIT_INI "/ivfdinit.ini"
#define IVFDCAM_INI "/ivfdcam.ini"
/*设备文件*/
#define CAMERA_DEVICE0 "/dev/video0"
#define CAMERA_DEVICE1 "/dev/video1"

enum CAMERAARGTYPE{BRIGHTNESS, GAIN, EXPOSURE, SATURATION, CONTRAST, WBALANCE, VFLIP};

 SeqQueue* IVFDUiDesign::m_queueevent = SeqQueue_Create(MAXEVENTNUM);

int cameraSetParam(int id, int val)
{
    switch(id)
    {
    case 0:
    {
        int ret;
        // Open Device
        fd = open(CAMERA_DEVICE0, O_RDWR);
        if (fd < 0) {
            qDebug("Open %s failed\n", CAMERA_DEVICE0);
            return -1;
        }
        else
        {
            qDebug("Open %s ok!!\n", CAMERA_DEVICE0);
        }
        //Query Capability
        struct v4l2_capability cap;

        ret = ioctl(fd, VIDIOC_QUERYCAP, &cap);
        if (ret < 0) {
            qDebug("VIDIOC_QUERYCAP failed (%d)\n", ret);
            return ret;
        }
        else
        {
            qDebug("VIDIOC_QUERYCAP ok!! (%d)\n", ret);
        }
        // Print capability infomations
        qDebug("Capability Informations:\n");
        qDebug("driver: %s\n", cap.driver);
        qDebug("card: %s\n", cap.card);
        qDebug("bus_info: %s\n", cap.bus_info);
        qDebug("version: %08X\n", cap.version);
        qDebug("capabilities: %08X\n", cap.capabilities);

        int input = 0;
        ret = ioctl(fd, VIDIOC_S_INPUT, &input);
        //enum format
        struct v4l2_fmtdesc fmt;

        memset(&fmt, 0, sizeof(fmt));

        sleep(3);
        //set control
        struct v4l2_control ctrl;

        ctrl.id = V4L2_CID_EXPOSURE;
        qDebug("set exposure auto informations:\n");
        qDebug("id = %d\t \n", ctrl.id);
        ret = ioctl(fd, VIDIOC_G_CTRL, &ctrl);
        if (ret < 0) {
            qDebug("set exposure auto failed (%d)\n", ret);
            return ret;
        }else{
            qDebug("VIDIOC_G_CTRL ok!! (%d)\n", ret);
        }

        ctrl.id = V4L2_CID_GAIN;
        ctrl.value = -4;
        qDebug("set gain informations:\n");
        qDebug("id = %d\t \n", ctrl.id);
        ret = ioctl(fd, VIDIOC_S_CTRL, &ctrl);
        if (ret < 0) {
            qDebug("set gain failed (%d)\n", ret);
            return ret;
        }else{
            qDebug("VIDIOC_G_CTRL ok!! (%d)\n", ret);
        }

        ctrl.id = V4L2_CID_BRIGHTNESS;
        ctrl.value = 4;
        qDebug("set brightness informations:\n");
        qDebug("id = %d\t \n", ctrl.id);
        ret = ioctl(fd, VIDIOC_S_CTRL, &ctrl);
        if (ret < 0) {
            qDebug("set brightness failed (%d)\n", ret);
            return ret;
        }else{
            qDebug("VIDIOC_G_CTRL ok!! (%d)\n", ret);
        }

        break;
    }
    case 1:
    {
        int ret;
        // Open Device
        fd = open(CAMERA_DEVICE1, O_RDWR);
        if (fd < 0) {
            qDebug("Open %s failed\n", CAMERA_DEVICE1);
            return -1;
        }
        else
        {
            qDebug("Open %s ok!!\n", CAMERA_DEVICE1);
        }
        //Query Capability
        struct v4l2_capability cap;

        ret = ioctl(fd, VIDIOC_QUERYCAP, &cap);
        if (ret < 0) {
            qDebug("VIDIOC_QUERYCAP failed (%d)\n", ret);
            return ret;
        }
        else
        {
            qDebug("VIDIOC_QUERYCAP ok!! (%d)\n", ret);
        }
        // Print capability infomations
        qDebug("Capability Informations:\n");
        qDebug("driver: %s\n", cap.driver);
        qDebug("card: %s\n", cap.card);
        qDebug("bus_info: %s\n", cap.bus_info);
        qDebug("version: %08X\n", cap.version);
        qDebug("capabilities: %08X\n", cap.capabilities);


        int input = 0;
        ret = ioctl(fd, VIDIOC_S_INPUT, &input);
        //enum format
        struct v4l2_fmtdesc fmt;

        memset(&fmt, 0, sizeof(fmt));

        sleep(3);
        //set control
        struct v4l2_control ctrl;

        ctrl.id = V4L2_CID_EXPOSURE;
        ctrl.value = 4000;
        qDebug("set exposure auto informations:\n");
        qDebug("id = %d\t \n", ctrl.id);
        ret = ioctl(fd, VIDIOC_G_CTRL, &ctrl);
        if (ret < 0) {
            qDebug("set exposure auto failed (%d)\n", ret);
            return ret;
        }else{
            qDebug("VIDIOC_G_CTRL ok!! (%d)\n", ret);
        }

        ctrl.id = V4L2_CID_BRIGHTNESS;
        ret = ioctl(fd, VIDIOC_G_CTRL, &ctrl);
        qDebug("read the reg:ret = %d, value = %d, id = %d", ret , ctrl.value, ctrl.id);
        QThread::msleep(100);
        ctrl.value = val;
        qDebug("set brightness informations:\n");
        qDebug("id = %d\t \n", ctrl.id);
        ret = ioctl(fd, VIDIOC_S_CTRL, &ctrl);
        if (ret < 0) {
            qDebug("set brightness failed (%d)\n", ret);
            return ret;
        }else{
            qDebug("VIDIOC_G_CTRL ok!! (%d)\n", ret);
        }
        QThread::msleep(100);
        ret = ioctl(fd, VIDIOC_G_CTRL, &ctrl);
        qDebug("after write, read the reg :ret = %d, value = %d, id = %d", ret , ctrl.value, ctrl.id);
        break;
    }

    }

    close(fd);
    qDebug("Camera set test Done.") ;
    return 0;
}

static enum ECMDTYPE GetCmdType(QString cmd)
{

}

IVFDUiDesign::IVFDUiDesign(QWidget *parent)
	: QMainWindow(parent)
{
    InitThis();
    qDebug() << "InitThis end";
}

IVFDUiDesign::~IVFDUiDesign()
{
    if(m_alarmdatainfo != NULL){
        free(m_alarmdatainfo);
        m_alarmdatainfo = (ALARMDATAINFO *)NULL;
    }

    for(int i = 0; i < MAXEVENTNUM; i++){
        if(m_alarmarray[i].alamdatainfo != NULL){
            free(m_alarmarray[i].alamdatainfo);
            m_alarmarray[i].alamdatainfo = NULL;
        }
    }
}

void IVFDUiDesign::SLOT_RecreateCPlayWindow()
{
    qDebug() << "3 IVFDUiDesign::SLOT_RecreateCPlayWindow()";
    emit SIG_OpenCPlayWindow();
}

void IVFDUiDesign::SLOT_CreateCPlayWindow()//this is for the post submit key of the webpage.
{
    qDebug() << "capture start";
    this->setHidden(true);
    m_videoCapture = new CPlayWindow(this, &m_campara0, &m_campara1);

    if(m_videoCapture == NULL)
    {
        QLog_("init", ErrorLevel, QString("CPlayWindow create error"));
        return;
    }

    QThread::msleep(1000);
    m_videoCapture->showNormal();
    qDebug() << "video show excute";

    //since be in a differnt thread,should be queconnection, this is wrong.they are all in the main thread;
    QObject::connect(this, SIGNAL(SIG_CaptureAndDIP()), m_videoCapture, SLOT(SLOT_CaptureAndDIP()));
    QObject::connect(this, SIGNAL(SIG_GetTimeStamp_0()), m_videoCapture, SIGNAL(SIG_GetTimeStamp0()));
    QObject::connect(m_videoCapture,SIGNAL(SIG_MsgToTopUi(QByteArray)), this, SLOT(SLOT_DoProcessMsgFromCPlayW(QByteArray)));
    QObject::connect(m_videoCapture, SIGNAL(SIG_UpdateTimeStamp(qlonglong)), this, SIGNAL(SIG_UpdateTimeStamp(qlonglong)));
    QObject::connect(this, SIGNAL(SIG_SetCameraParameter(int, int, int, int)), m_videoCapture, SIGNAL(SIG_SetCameraParameter(int, int, int, int)));
    QObject::connect(this, SIGNAL(SIG_StartAlgDet(int)), m_videoCapture, SIGNAL(SIG_StartAlgDet(int)));
//    QObject::connect(this, SIGNAL(SIG_SetGPIOOUT(int,int)), m_videoCapture, SIGNAL(SIG_SetGPIOPin(int,int)));//wanggy 190529
    QObject::connect(m_videoCapture, SIGNAL(SIG_SendMsgToUITcpClient(QByteArray ,QByteArray)), this, SIGNAL(SIG_SendMsgToTcpServer(QByteArray, QByteArray)));
    QObject::connect(this, SIGNAL(SIG_StartAlgFireDet(int)), m_videoCapture, SIGNAL(SIG_StartAlgFireDet(int)));
    QObject::connect(this, SIGNAL(SIG_StopAlgFireDet()), m_videoCapture, SIGNAL(SIG_StopAlgFireDet()));
    QObject::connect(this, SIGNAL(SIG_CapureYUVFile(int)), m_videoCapture, SIGNAL(SIG_CaptureYUVFile(int)));
    QObject::connect(this, SIGNAL(SIG_QueryAlgStatus(int)), m_videoCapture, SIGNAL(SIG_QueryVal(int)));

//    QObject::connect(this, SIGNAL(SIG_InitCamera()), m_videoCapture, SIGNAL(SIG_InitCamera()));

//    emit SIG_CaptureAndDIP();


}

bool IVFDUiDesign::event(QEvent *event)
{
    if(event->type() == static_cast<QEvent::Type>(IVFDEvent::getType(E_CANCLERTSP)))
    {
        IVFDEvent *m_e = (IVFDEvent *)event;
        qDebug() << "in IVFDUidesign httpserver event is dealed!-------" << m_e->getId();
    }
    return QMainWindow::event(event);

}


void IVFDUiDesign::SLOT_BtnCloseClick()
{
    qDebug() << "IVFDUiDesign close";
    this->close();
}


void IVFDUiDesign::SLOT_CmdFromBrowser(QString module, QString cmd)
{
    qDebug() << "-------- IVFDUiDesign::SLOT_CmdFromBrowser -----" << QThread::currentThread();
    qDebug() << "module = " << module  << "cmd = " << cmd;
    CmdPara mycmdpara = CtlCmdFind(cmd);
    DoCtlCmdFind(mycmdpara);
}


void IVFDUiDesign::DoDownLoadFile(QFile *file)
{

    qDebug() << "downloading file: " <<  file->fileName();
    QProcess downLoadFileProcess(0);

    QString cmd = "tftp";
    QStringList args;
    args.append("-p");
    args.append("-l");
    args.append("1.txt");
    args.append("192.168.120.216");
    downLoadFileProcess.start(cmd, args);
    downLoadFileProcess.waitForFinished();
//    qDebug() << QString::fromLocal8Bit(downLoadFileProcess.readAllStandardOutput());
    qDebug() << QString::fromLocal8Bit(downLoadFileProcess.readAllStandardError());

}


cmd_table* IVFDUiDesign::cmd_find(QString &cmdname){
    int i;
    for(i = 0; i < sizeof(cmd_tbl)/sizeof(cmd_tbl[0]); i++){
        if(cmdname == cmd_tbl[i].name){
            return &cmd_tbl[i];
            qDebug() << i;
        }
    }
    qDebug("cant find a command");
    return 0;
}


void IVFDUiDesign::SendSigSwitchRtsp()
{
    qDebug() << "send a signal SIG_CaptureAndDIP";//

    emit this->SIG_CaptureAndDIP();

}


void IVFDUiDesign::DoCmdType(enum ECMDTYPE cmdtype, QString cmd)
{

}

void IVFDUiDesign::SLOT_DoProcessMsgFromCPlayW(QByteArray msg)
{
    qDebug() << "do process msg from cplaywindow---in topui---" << QThread::currentThread();
    qlonglong timeStamp = msg.toLongLong();
    qDebug() << timeStamp;

    emit SIG_AnswerCmdToHttpServer(msg);
    qDebug() << "end do processmsgfrom CPlayW in Topui";
}

void IVFDUiDesign::SLOT_SyncTimeStamp_0()
{
    if(m_videoCapture != NULL)
    {
        qDebug() << "m_videoCapture is not null";
        emit SIG_GetTimeStamp_0();
    }

    qDebug("do start synctimestamp");

}

void IVFDUiDesign::SLOT_CurrentStatus()
{
    qDebug("do start get currentstatus");
}
//by the cmd from browser to find the CMDTYPE
CmdPara IVFDUiDesign::CtlCmdFind(QString cmd)
{
    CmdPara cmdpararet = {NOCOMMAND, 0, EHWTODEFINE};
    enum ECMDTYPE reterror = NOCOMMAND;
    QStringList strlist = m_cmdlist;
    if(cmd.isEmpty())
    {
        return cmdpararet;
    }

    for(int index = 0; index < strlist.length(); index++)
    {
        qDebug() << strlist.at(index);

    }
    for(int index = 0; index < strlist.length(); index++)
    {
        QString mycmd("");
        QString mycmdpara("0");

        if(cmd.contains("$"))
        {
            QStringList mycmdlist = cmd.split("$");
            if(mycmdlist.length() > 2)
            {
                qDebug() << "parameter too much";
                cmdpararet.cmdtype = reterror;
                cmdpararet.cmdval = 0;
                return cmdpararet;
            }
            mycmd = mycmdlist.at(0);
            if(mycmd == strlist.at(index))
            {
                cmdpararet.cmdtype = ECMDTYPE(index);
                if(mycmdlist.at(1).contains("@"))
                {
                    QStringList valuelist = mycmdlist.at(1).split("@");
                    mycmdpara = valuelist.at(0);
                    cmdpararet.cmdval = mycmdpara.toInt();
                    cmdpararet.id = (EHWVAL)valuelist.at(1).toInt();
                    return cmdpararet;
                }else
                {
                    mycmdpara = mycmdlist.at(1);
                    cmdpararet.cmdval = mycmdpara.toInt();
                    cmdpararet.id = EHWTODEFINE;
                    return cmdpararet;
                }
            }else
            {
                continue;
            }

        }else{
            mycmd = cmd;
            if(strlist.at(index) == mycmd)
            {
                qDebug() << index;
                cmdpararet.cmdtype = ECMDTYPE(index);
                return cmdpararet;
            }
        }
    }
    qDebug("cmd not found");
    cmdpararet.cmdtype = reterror;
    return cmdpararet;
}

void IVFDUiDesign::DoCtlCmdFind(CmdPara cmd)//no used now!!!!!
{
    qDebug() << "IVFDUiDesign::DoCtlCmdFind cmd.cmdtype = "  <<  cmd.cmdtype;
    int index = (int)(cmd.cmdtype);

    qDebug() << "IVFDUiDesign::DoCtlCmdFind length = " << m_cmdlist.length() << "index = " << index;
    if(index < 0 || index > m_cmdlist.length() - 1)
    {
        qDebug() << "index out of range";
        return;
    }

    enum ECMDTYPE cmdtype = ECMDTYPE(index);
    qDebug() << "IVFDUiDesign::DoCtlCmdFind:" << cmdtype;
    switch(cmdtype)
    {
    case CMD_CONTROL:
    {
        qDebug() << m_cmdlist.at(index);
        emit SIG_Control(cmdtype, cmd.id ,cmd.cmdval);
        break;
    }
    case CMD_GETSYSINFO:
    {
        emit SIG_GetSysInfo();
        qDebug() << m_cmdlist.at(index);
        break;
    }

    case CMD_CREATECPLAYW:
    {
        emit SIG_OpenCPlayWindow();
        qDebug() << m_cmdlist.at(index);
        break;
    }

    case CMD_STARTALL:
    {
        qDebug() << m_cmdlist.at(index);
        break;
    }

    case CMD_STARTRTSP0:
    {
        qDebug() << m_cmdlist.at(index);
        break;
    }
    case CMD_STARTRTSP1:
    {
        qDebug() << m_cmdlist.at(index);
        break;
    }

    case CMD_STOPRTSP0:
    {
        qDebug() << m_cmdlist.at(index);
//        emit SIG_SwitchVideoPlay();
        break;
    }
    case CMD_STOPRTSP1:
    {
        qDebug() << m_cmdlist.at(index);
        break;
    }

    case CMD_SWITCHRTSP:
    {
        emit SIG_CaptureAndDIP();
        qDebug() << m_cmdlist.at(index);
        break;
    }
    case CMD_UPLOADFILE:
    {
        emit SIG_UploadFile();
        qDebug() << m_cmdlist.at(index);
        break;
    }

    case CMD_SWITCH:
    {
        qDebug() << m_cmdlist.at(index);

        break;
    }
    case NOCOMMAND:
    {
        qDebug() << m_cmdlist.at(index);
        emit SIG_NoIdentityCmd(cmdtype, cmd.id ,cmd.cmdval);
        break;
    }

    case CMD_CURRENTSTATUS:
    {
        qDebug() << m_cmdlist.at(index);
        emit SIG_CurrentStatus();
        break;
    }
    case CMD_SYNCTIMESTAMP:
    {
        qDebug() << m_cmdlist.at(index);
        emit SIG_SyncTimeStamp_0();
//        emit SIG_TestTcpClient();
        break;
    }

    case CMD_DOWNLOADLOG:
    {
        qDebug() << m_cmdlist.at(index);
        break;
    }
    case CMD_GETBRIGHT0:
    {
        qDebug() << "ready to write the bright value to client" << m_cmdlist.at(index);
        emit SIG_AnswerCmdToHttpServer("20");
        break;
    }
    case CMD_GETBRIGHTBALANCE0:
    {
        qDebug() << m_cmdlist.at(index);
        break;
    }
    case CMD_GETDIARYINFO:
    {
        qDebug() << m_cmdlist.at(index);
        break;
    }
    case CMD_GETGAIN0:
    {
        qDebug() << m_cmdlist.at(index);
        break;
    }
    case CMD_GETNETINFO:
    {
        qDebug() << m_cmdlist.at(index);
        break;
    }
    case CMD_GETSATRUATION0:
    {
        qDebug() << m_cmdlist.at(index);
        break;
    }
    case CMD_GETUSERINFO:
    {
        qDebug() << m_cmdlist.at(index);
        break;
    }
    case CMD_LOGIN:
    {
        qDebug() << m_cmdlist.at(index);
        break;
    }
    case CMD_SETALGPARA:
    {
        qDebug() << m_cmdlist.at(index);
        emit SIG_SetInitFilesVal(cmdtype, cmd.id, cmd.cmdval);
        break;
    }
    case CMD_SETBRIGHT:
    {
        qDebug() << m_cmdlist.at(index);
        emit SIG_SetInitFilesVal(cmdtype, cmd.id, cmd.cmdval);
        break;
    }
    case CMD_SETEXPOSURE:
    {
        qDebug() << m_cmdlist.at(index);
        emit SIG_SetInitFilesVal(cmdtype, cmd.id, cmd.cmdval);
        break;
    }
    case CMD_SETBRIGHTBALANCE:
    {
        qDebug() << m_cmdlist.at(index);
        emit SIG_SetInitFilesVal(cmdtype, cmd.id, cmd.cmdval);
        break;
    }
    case CMD_SETGAIN:
    {
        qDebug() << m_cmdlist.at(index);
        emit SIG_SetInitFilesVal(cmdtype, cmd.id, cmd.cmdval);
        break;
    }
    case CMD_SETSATURATION:
    {
        qDebug() << "----in DoCtlCmdFind---"  <<  m_cmdlist.at(index);
        emit SIG_SetInitFilesVal(cmdtype, cmd.id ,cmd.cmdval);
        break;
    }
    case CMD_SETNETINFO:
    {
        qDebug() << m_cmdlist.at(index);
        emit SIG_SetInitFilesVal(cmdtype, cmd.id, cmd.cmdval);
        break;
    }

    case CMD_STARTALGDET:
    {
        qDebug() << "get the cmd ----in DoCtlCmdFind---"  <<  m_cmdlist.at(index);
        emit SIG_StartAlgDet(1);
        break;
    }
    case CMD_SETGPIO:
    {
        qDebug() << "get the cmd -----int DoCtlCmdFind setgpio----" << m_cmdlist.at(index);
        emit SIG_SetInitFilesVal(cmdtype, cmd.id ,cmd.cmdval);
        break;
    }

    default:
    {
        qDebug() << "get the cmd -----int DoCtlCmdFind wrong----" << m_cmdlist.at(index);
    }

    }
    return;
}
void IVFDUiDesign::SLOT_NoIdentityCmd(ECMDTYPE, EHWVAL id, qint32 val)
{
    qDebug() << "3 IVFDUiDesign::SLOT_NoIdentityCmd------NOCOMMAND FIND ";
}

void IVFDUiDesign::SLOT_UpdateTimeStamp(qlonglong timestamp)

{
    m_timeStamp = timestamp;
}

void IVFDUiDesign::CreateEnviorment()
{
    m_timeStamp = 0;
    m_localIpAddr = QString("192.168.120.166");
    m_portUDPServer = 0;
    m_portUDPClient = 0;
    m_portTCPServer = 0;
    m_portTCPClient = 0;
    //声明命令数组
    m_settings = new QSettings(this);
    QFile inifile(IVFDINIT_INI);

    if(!inifile.exists())
    {
        QLog_("init", ErrorLevel, QString("/tmp/ivfdrun/ivfdinit.ini not exisit"));
        qDebug() << "In IVFDUIDesign::InitThis ---inifile not exist";
        return;
    }

    QSettings initsetting(IVFDINIT_INI, QSettings::IniFormat);
    initsetting.beginGroup("command");
    QStringList keylist = initsetting.allKeys();
    foreach(QString key, keylist)
    {
        if(initsetting.value(key) != false)
        {
            m_cmdlist.append(key);
        }
    }
    initsetting.endGroup();
    m_cmdlist.sort();

    initsetting.beginGroup("cameraset");
    keylist = initsetting.allKeys();
    foreach(QString key, keylist)
    {
        qDebug() << key << "-----" << initsetting.value(key);
    }

    QSettings caminitsetting(IVFDCAM_INI, QSettings::IniFormat);
    QString strbright0("brightness0");
    QString strgain0("gain0");
    QString strwhitebalance0("brightbalance0");
    QString strbright1("brightness1");
    QString strgain1("gain1");
    QString strwhitebalance1("brightbalance1");

    m_campara0.id = 0;
    m_campara0.bright = caminitsetting.value(strbright0).toInt();
    m_campara0.gain = caminitsetting.value(strgain0).toInt();
    m_campara0.whitebalance = caminitsetting.value(strwhitebalance0).toInt();
    m_campara1.id = 1;
    m_campara1.bright = caminitsetting.value(strbright1).toInt();
    m_campara1.gain = caminitsetting.value(strgain1).toInt();
    m_campara1.whitebalance = caminitsetting.value(strwhitebalance1).toInt();
    caminitsetting.endGroup();

    qDebug() << "m_camera0.bright = " << m_campara0.bright;
    qDebug() << "m_camera1.bright = " << m_campara1.bright;
}


void IVFDUiDesign::InitThis()
{
    int i = 0;
    ui.setupUi(this);

//    this->setAttribute(Qt::WA_TranslucentBackground,true);
    this->setAttribute(Qt::WA_TranslucentBackground,false);
    //
    CreateEnviorment();
    m_onwatchstatus = 0;
    m_alarmdatainfo = (ALARMDATAINFO *)malloc(sizeof(ALARMDATAINFO));
    memset(m_alarmdatainfo, 0, sizeof(m_alarmdatainfo));

    for(int i = 0; i < MAXEVENTNUM; i++){
        m_alarmarray[i].status = 0;
        m_alarmarray[i].memid = i;
        m_alarmarray[i].alamdatainfo = (ALARMDATAINFO *)malloc(sizeof(ALARMDATAINFO));
//        memset(m_alarmarray[i].alamdatainfo, 0, sizeof(ALARMDATAINFO));
//        m_alarmarray[i].
    }

    m_IVFDTcpServer = new IVFDTcpServer(0);
    if(m_IVFDTcpServer == NULL)
    {
        QLog_("init",ErrorLevel,QString("Tcpserver Create error"));
//        qDebug() << "In IVFDUIDesign::InitThis ---Tcpserver Create error ";
        return;
    }
    qDebug() << "IVFDTcpServer create success";
    m_IVFDTcpClient = new IVFDTcpClient(0);
    if(m_IVFDTcpClient == NULL)
    {
        QLog_("init",ErrorLevel,QString("TcpClient Create error"));
//        qDebug() << "In IVFDUIDesign::InitThis ---TcpClient Create error ";
        return;
    }
    qDebug() << "IVFDTcpClient create success";

//    not create CPlayWindow right now
    m_videoCapture = NULL;
    m_IVFDEventManager = new IVFDEventManager(0);
    if(m_IVFDEventManager == NULL){
        return;
    }

    setWindowTitle("BandWeaver - IVFD2.0");
    setGeometry(20, 20, 1024, 600);
    setMaximumSize(1024, 600);
    setMinimumSize(1024, 600);
    ui.splitter->setGeometry(ui.centralWidget->x(), ui.centralWidget->y(), ui.centralWidget->window()->width(), ui.listWidget->window()->height());

    ui.splitter->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui.splitter->setStyleSheet("QSplitter::handle{background-color:rgb(85,170,255)}");

    ui.splitter->setHandleWidth(5);
    ui.splitter->setStretchFactor(0, -2);
    ui.splitter->setStretchFactor(1, -4);

    for(i = 0; i < 8; i++)
    {
        ui.listWidget->item(i)->setSizeHint(QSize(60,60));
        ui.listWidget->insertItem(i, ui.listWidget->item(i));
    }
    ui.listWidget->setMaximumHeight(ui.centralWidget->window()->height());
    ui.listWidget->setStyleSheet("QListWidget{border:1px solid gray; color:black; }"
        "QListWidget::Item{padding-top:20px; padding-bottom:4px; }"
        "QListWidget::Item:hover{background:skyblue; }"
        "QListWidget::item:selected{background:lightgray; color:red; }"
        "QListWidget::item:selected:!active{border-width:0px; background:lightgreen; }"
        );

    ui.stackedWidget->setMaximumSize(ui.centralWidget->window()->width(),ui.listWidget->window()->height());

    QObject::connect(ui.listWidget, SIGNAL(currentRowChanged(int)), ui.stackedWidget, SLOT(setCurrentIndex(int)));
    QObject::connect(this, SIGNAL(SIG_OpenCPlayWindow()), this, SLOT(SLOT_CreateCPlayWindow()));
    QObject::connect(this, SIGNAL(SIG_CurrentStatus()), this, SLOT(SLOT_CurrentStatus()));
    QObject::connect(this, SIGNAL(SIG_SyncTimeStamp_0()), this, SLOT(SLOT_SyncTimeStamp_0()));
    QObject::connect(this, SIGNAL(SIG_UpdateTimeStamp(qlonglong)), this, SLOT(SLOT_UpdateTimeStamp(qlonglong)));
//emit in main thread.
    QObject::connect(this, SIGNAL(SIG_StartTcpServerThread()), m_IVFDTcpServer, SIGNAL(SIG_StartTcpServerThread()));
    QObject::connect(this, SIGNAL(SIG_StartThreadIVFDEventManager()), m_IVFDEventManager, SIGNAL(SIG_ThreadStart()));//now in same thread
//emit in main thread
    QObject::connect(this, SIGNAL(SIG_StartIVFDEventManager()), m_IVFDEventManager, SLOT(SLOT_DoEventManager()), Qt::QueuedConnection);//now in different thread

    QObject::connect(this, SIGNAL(SIG_SetInitFilesVal(enum ECMDTYPE, enum EHWVAL, qint32)), this, SLOT(SLOT_SetInitFilesVal(enum ECMDTYPE, enum EHWVAL, qint32)));
    QObject::connect(this, SIGNAL(SIG_Control(ECMDTYPE,EHWVAL,qint32)), this, SLOT(SLOT_Control(ECMDTYPE,EHWVAL,qint32)));
    QObject::connect(this, SIGNAL(SIG_SetGPIOOUT(int,int)), this, SLOT(SLOT_SetGPIOOUT(int,int)));
    QObject::connect(m_IVFDEventManager, SIGNAL(SIG_SendToClient(QByteArray,QByteArray)), m_IVFDTcpClient, SIGNAL(SIG_SendMsgToServer(QByteArray,QByteArray)), Qt::QueuedConnection);
    QObject::connect(this, SIGNAL(SIG_SendMsgToTcpServer(QByteArray,QByteArray)), this, SLOT(SLOT_SendMsgToTcpServer(QByteArray,QByteArray)));

    QObject::connect(this, SIGNAL(SIG_NoIdentityCmd(ECMDTYPE,EHWVAL,qint32)), this, SLOT(SLOT_NoIdentityCmd(ECMDTYPE,EHWVAL,qint32)));

    QObject::connect(m_IVFDTcpServer, SIGNAL(SIG_TellTop(QByteArray)), this, SIGNAL(SIG_GetCmdFromLocalTcpServer(QByteArray)), Qt::QueuedConnection);
    QObject::connect(this, SIGNAL(SIG_GetCmdFromLocalTcpServer(QByteArray)), this, SLOT(SLOT_GetCmdFromLocalTcpServer(QByteArray)));

    QObject::connect(this, SIGNAL(SIG_SendToClient(QByteArray,QByteArray)), m_IVFDTcpClient, SIGNAL(SIG_SendMsgToServer(QByteArray,QByteArray)),Qt::QueuedConnection);


    ui.pushButton_capture->setDisabled(true);
    QThread::msleep(100);
    QLog_(QString("init"),DebugLevel,"IVFDUiDesign construct");

}


void IVFDUiDesign::SLOT_SetCameraParam(int cameraid, int setvalue)
{
    int ret = cameraSetParam(cameraid, setvalue);
    qDebug() << "3 IVFDUiDesign::SLOT_SetCameraParam(:set the param of cameraset ret = " << ret;
}


void IVFDUiDesign::SLOT_SetInitFilesVal(enum ECMDTYPE cmdtype, EHWVAL id, qint32 cmdval)
{
    qDebug("3 IVFDUiDesign::SLOT_SetInitFilesVal:CMDTYPE = %d, HWID= %d  HWVALSET = %d", cmdtype, id, cmdval);
    enum ECMDTYPE mycmdtype = cmdtype;
//    QSettings mysettings(IVFDINIT_INI, QSettings::IniFormat);
    QSettings *mysetting = new QSettings(IVFDINIT_INI, QSettings::IniFormat);
    if(mysetting == NULL)
    {
        qDebug() << "mysetting = NULL";
        return;
    }

    switch(mycmdtype)
    {
    qDebug() << "begin to write the value to /tmp/ivfdrun/ivfdinit.ini";
    case CMD_SETBRIGHT:
    {
        QString keybright = QString("brightness").append(QString::number(id));
        mysetting->beginGroup("cameraset");
        qDebug() << "brightness = " << mysetting->value(keybright);
        qDebug() << "after write now read the bright val =" << mysetting->value(keybright);
        int val1 = 0;
        int val2 = mysetting->value(keybright).toInt();//mysetting->value(keyexposure).toInt();
        int val3 = 0;
        qDebug() << keybright << "=" << val1;
        emit SIG_SetCameraParameter(id, val1, val2, val3);
        mysetting->endGroup();
        break;
    }

    case CMD_SETGAIN:
    {
        QString keygain = QString("gain").append(QString::number(id));
        mysetting->beginGroup("cameraset");
        qDebug() << "gain = " << mysetting->value(keygain);
        qDebug() << "after write now read the gain val =" << mysetting->value(keygain);
        int val1 = 1;
        int val2 = mysetting->value(keygain).toInt();
        int val3 = 0;
        qDebug() << keygain << "=" << val1;
        emit SIG_SetCameraParameter(id, val1, val2, val3);
        mysetting->endGroup();
        break;
    }
    case CMD_SETEXPOSURE:
    {
        QString keyexposure = QString("exposure").append(QString::number(id));
        mysetting->beginGroup("cameraset");
        qDebug() << "brightness = " << mysetting->value(keyexposure);
        qDebug() << "after write now read the exposure val =" << mysetting->value(keyexposure);
        int val1 = 2;
        int val2 = mysetting->value(keyexposure).toInt();
        int val3 = 0;
        qDebug() << keyexposure << "=" << val1;
        emit SIG_SetCameraParameter(id, val1, val2, val3);
        mysetting->endGroup();

        break;
    }

    case CMD_SETSATURATION:
    {
        QString keysaturation = QString("saturation").append(QString::number(id));
        mysetting->beginGroup("cameraset");
        qDebug() << "gain = " << mysetting->value(keysaturation);
        qDebug() << "after write now read the saturation val =" << mysetting->value(keysaturation);
        int val1 = 3;
        int val2 = mysetting->value(keysaturation).toInt();
        int val3 = 0;
        qDebug() << keysaturation << "=" << val1;
        emit SIG_SetCameraParameter(id, val1, val2, val3);
        mysetting->endGroup();
        break;
    }
    case CMD_SETBRIGHTBALANCE:
    {
        QString keybal = QString("brightbalance").append(QString::number(id));
        mysetting->beginGroup("cameraset");
        qDebug() << "gain = " << mysetting->value(keybal);
        qDebug() << "after write now read the saturation val =" << mysetting->value(keybal);
        int val1 = 5;
        int val2 = mysetting->value(keybal).toInt();
        int val3 = 0;
        qDebug() << keybal << "=" << val1;
        emit SIG_SetCameraParameter(id, val1, val2, val3);
        mysetting->endGroup();
        break;
    }

    case CMD_SETALGPARA:
    {


        break;
    }

    case CMD_SETGPIO:
    {
        qDebug() << "IVFDUiDesign::SLOT_SetInitFilesVal:CMD_SETGPIO " ;
        emit SIG_SetGPIOOUT(id, cmdval);
        break;
    }
    }
    delete mysetting;
}

void IVFDUiDesign::SLOT_Control(ECMDTYPE, EHWVAL id, qint32 val)
{
    EHWVAL idrecv = EHWVAL(id);

    switch(idrecv)
    {
    case ALGARGALPHA:
    {
        qDebug() << "beging to set algalpha:" << val;
        break;
    }
    case ALGARGBETA:
    {
        qDebug() << "beging to set algbeta:" << val;
        break;
    }
    case ALGARGWEIGHT1:
    {
        qDebug() << "beging to set algweight1:" << val;
        break;
    }
    case SYSTEMRESET:
    {
        qDebug() << "being to reset the system:" << val;
        break;
    }
    case SETNETCONFIG:
    {
        qDebug() << "being to config net:" << val;
        break;
    }
    case LOGIN:
    {
        qDebug() << "being to login system:" << val;
        break;
    }
    case RESETSTATUS:
    {
        qDebug() << "being to reset status:" << val;
        break;
    }
    case ALARMENABLE:
    {
        qDebug() << "being to enable or disable alarm:" << val;
        break;
    }
    case CALIBRATE:
    {
        qDebug() << "being to calibrate the scene:" << val;
        break;
    }
    case ALGFIREONOFF://default is on ,this is off only for change current status ,not change the default status on.
    {
        qDebug() << "being to switch algfiredet status" << val;
        if(m_videoCapture != NULL)
        {
            qDebug() << "m_videoCapture != NULL";
            emit m_videoCapture->SIG_ControlAlg((int)ALGFIREONOFF, val);
        }
        break;
    }
    case INITCAMERA:
    {
        qDebug() << "being to stop init CameraBy initfile cfg" << val;
        if(m_videoCapture != NULL)
        {
            qDebug() << "m_videoCapture != NULL";
//            emit SIG_InitCamera();
        }
        break;
    }
    case SDCARD:
    {
        qDebug() << "being to operate sdcard " << val;
        if(m_videoCapture != NULL)
        {
            qDebug() << "m_videoCapture != NULL";
            emit SIG_CapureYUVFile(val);
        }
        break;
    }
    default:
    {
        qDebug() << "no operate";
    }

    }
}

void IVFDUiDesign::SLOT_SetGPIOOUT(int pin, int cmdval)
{
    qDebug() << "now receive the pin and val ,pin = " << pin << "------cmd val =" << cmdval;

}

void IVFDUiDesign::SLOT_SendMsgToTcpServer(QByteArray cmd, QByteArray val)
{
    int retqueData = 0 ;
    QByteArray alarminfo = val;

    if(alarminfo.size() == 11 || alarminfo.size() == 12 || alarminfo.size() == 13 ){
        //        emit SIG_XParseCMDFromHttpServer(ba);
    }else if(alarminfo.size() == 24){
        ALARMDATAINFO *recv_alarmDataInfo = (ALARMDATAINFO *)alarminfo.data();
        if(recv_alarmDataInfo == NULL){
            return;
        }
        int cnt = sizeof(*recv_alarmDataInfo);
        ALARMEVENT *cur_palarmarray = (ALARMEVENT *)&(m_alarmarray[0]);
        if(cur_palarmarray == NULL){
            return;
        }

        //        memcpy(m_alarmdataifo, alarmDataInfo, cnt);
        if(recv_alarmDataInfo->alarmType == FIREDET)
        {
            if((m_alarmdatainfo->alarmType == recv_alarmDataInfo->alarmType) && \
                    (-10 < m_alarmdatainfo->pTOPLx - recv_alarmDataInfo->pTOPLx < 10) && \
                    (-10 < m_alarmdatainfo->pTOPLy == recv_alarmDataInfo->pTOPLy < 10) && \
                    (-10 < m_alarmdatainfo->recWidth == recv_alarmDataInfo->recWidth < 10) &&\
                    (-10 < m_alarmdatainfo->recHeight == recv_alarmDataInfo->recHeight < 10))
            {}
            else{
                memcpy(m_alarmdatainfo, recv_alarmDataInfo, cnt);
                for(int i = 0; i < MAXEVENTNUM; i++)
                {
                    if(cur_palarmarray->status == 0 && cur_palarmarray->memid == i){
                        qDebug() << "fire det, push into the event queue;";
                        memcpy(cur_palarmarray->alamdatainfo, recv_alarmDataInfo, cnt);
                        cur_palarmarray->status = 1;
                        retqueData = SeqQueue_Append(IVFDUiDesign::m_queueevent, cur_palarmarray);
                        break;
                    }else{

                    }
                    cur_palarmarray ++;
                }
            }
        }else if(recv_alarmDataInfo->alarmType == FIREDETEND)
        {
            //event filter
            if(m_alarmdatainfo->alarmType == recv_alarmDataInfo->alarmType && \
                    (-10 < m_alarmdatainfo->pTOPLx - recv_alarmDataInfo->pTOPLx < 10) && \
                    (-10 < m_alarmdatainfo->pTOPLy == recv_alarmDataInfo->pTOPLy < 10) && \
                    (-10 < m_alarmdatainfo->recWidth == recv_alarmDataInfo->recWidth < 10) &&\
                    (-10 < m_alarmdatainfo->recHeight == recv_alarmDataInfo->recHeight < 10))
            {}else{
                memcpy(m_alarmdatainfo, recv_alarmDataInfo, cnt);
                for(int i = 0; i < MAXEVENTNUM; i++){
                    qDebug() << "fire end, push into the event queue;";
                    if(cur_palarmarray->status == 0 && cur_palarmarray->memid == i){
                        memcpy(cur_palarmarray->alamdatainfo, recv_alarmDataInfo, cnt);
                        cur_palarmarray->status = 1;
                        retqueData = SeqQueue_Append(IVFDUiDesign::m_queueevent, cur_palarmarray);
                        break;
                    }else{

                    }
                    cur_palarmarray ++;
                }
            }
            //            memset(m_alarmdatainfo, 0, cnt);
        }
//        qDebug() << m_alarmdatainfo->pTOPLx << " " << m_alarmdatainfo->pTOPLy << " " << m_alarmdatainfo->recHeight << " " << m_alarmdatainfo->pTOPLy;

    }else if(alarminfo.size() == 136){
        //        emit SIG_XParseMsgFromTerminalCLient(alarminfo);
    }else if(alarminfo.size() == 20){
        emit SIG_SendToClient(alarminfo, alarminfo);
    }
    QEventLoop loop;
    QTimer::singleShot(100, &loop, SLOT(quit()));
    loop.exec();

}


void IVFDUiDesign::SLOT_GetCmdFromLocalTcpServer(QByteArray cmd)//now use !!!!
{
    CmdARG *recv_cmdarg = (CmdARG *)cmd.data();
    QSettings *mysetting = new QSettings(IVFDINIT_INI, QSettings::IniFormat);
    int id = recv_cmdarg->arg1;
    int val1 = recv_cmdarg->arg2;
    int val2 = recv_cmdarg->arg3;
    int val3 = recv_cmdarg->arg4;

    qDebug() << "3 IVFDUiDesign::SLOT_GetCmdFromLocalTcpServer:recv cmd arg = " << recv_cmdarg->cmdtype << " argnum = " << recv_cmdarg->argnum << " arg = " \
             << recv_cmdarg->arg1 << " " << recv_cmdarg->arg2 << " " << recv_cmdarg->arg3  << " " << recv_cmdarg->arg4;

    switch(recv_cmdarg->cmdtype)
    {
    case CMD_CREATECPLAYW:
    {
        qDebug() << "3 IVFDUiDesign::SLOT_GetCmdFromLocalTcpServer:createCPlayWindow";
        emit SIG_OpenCPlayWindow();
        break;
    }
    case CMD_SWITCHRTSP:
    {
        qDebug() << "3 IVFDUiDesign::SLOT_GetCmdFromLocalTcpServer:SIG_CaptureAndDIP";
        emit SIG_CaptureAndDIP();
        break;
    }

    case CMD_SETBRIGHT:
    {
        emit SIG_SetCameraParameter(id, VFLIP, val1, val3);
//        mysetting->endGroup();
        break;
    }

    case CMD_SETGAIN:
    {
        qDebug() << "3 IVFDUiDesign::SLOT_GetCmdFromLocalTcpServer:CMD_SETGAIN, id =" << id << "val1 = "<< val1;
        emit SIG_SetCameraParameter(id, GAIN, val1, val3);
//        mysetting->endGroup();
        break;
    }
    case CMD_SETEXPOSURE:
    {
        qDebug() << "3 IVFDUiDesign::SLOT_GetCmdFromLocalTcpServer:CMD_SETEXPOSURE id = " << id;
        emit SIG_SetCameraParameter(id, EXPOSURE, val1, val3);
//        mysetting->endGroup();

        break;
    }

    case CMD_SETSATURATION:
    {
        emit SIG_SetCameraParameter(id, SATURATION, val1, val3);
//        mysetting->endGroup();
        break;
    }
    case CMD_SETBRIGHTBALANCE:
    {
        emit SIG_SetCameraParameter(id, WBALANCE, val1, val3);
//        mysetting->endGroup();
        break;
    }
    case CMD_SETGPIO:
    {
        qDebug() << "3 IVFDUiDesign::SLOT_GetCmdFromLocalTcpServer:CMD_SETGPIO";
        int pin = recv_cmdarg->arg1;
        int val = recv_cmdarg->arg2;
        emit SIG_SetGPIOOUT(pin, val);
        break;
    }
    case CMD_CONTROL:
    {
        qDebug() << "3 IVFDUiDesign::SLOT_GetCmdFromLocalTcpServer:CMD_CONTROL";
        int id = recv_cmdarg->arg1;
        int val = recv_cmdarg->arg2;

        SLOT_Control(CMD_CONTROL, (EHWVAL)id, val);

        break;
    }
    case CMD_CURRENTSTATUS:
    {
        qDebug() << "3 IVFDUiDesign::SLOT_GetCmdFromLocalTcpServer:CMD_CURRENTSTATUS";
        emit SIG_QueryAlgStatus(0);

    }

    case CMD_STARTALGDET:
    {
        int algId = recv_cmdarg->arg1;
        qDebug() << "3 IVFDUiDesign::SLOT_GetCmdFromLocalTcpServer:CMD_STARTALGDET,algId = " << algId;

        emit SIG_StartAlgDet(algId);
        break;

    }
    case CMD_GETBRIGHT0:
    {

    }
    case CMD_SETALGPARA:
    {
        int algtype = recv_cmdarg->arg1;
        int algargid = recv_cmdarg->arg2;
        int algargval = recv_cmdarg->arg3;
        qDebug() << "3 IVFDUiDesign::SLOT_GetCmdFromLocalTcpServer:CMD_SETALGPARA,algtype = " << algtype;
        //if id < 10, fire; else if id > 10 ,smoke;
        if(algargid == 6){
            qDebug() << "3 dip: IVFDUiDesign::SLOT_GetCmdFromLocalTcpServer:CMD_SETALGPARA set the fire sense. val = " << algargval;
        }else if(algargid == 7){
            qDebug() << "3 dip: IVFDUiDesign::SLOT_GetCmdFromLocalTcpServer:CMD_SETALGPARA set the fire mindet. val = " << algargval;
        }

    }

    default:
        qDebug() << "3 IVFDUiDesign::SLOT_GetCmdFromLocalTcpServer:no command match";


    }
    delete mysetting;
}
void IVFDUiDesign::SLOT_GetAlgStatus(){
    qDebug() << "3 IVFDUiDesign::SLOT_GetAlgStatus";

}

