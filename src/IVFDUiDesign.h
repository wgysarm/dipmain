#ifndef IVFDUIDESIGN_H
#define IVFDUIDESIGN_H

#include <QtWidgets/QMainWindow>
#include "ui_IVFDUiDesign.h"
#include <QProcess>
#include <QTcpSocket>
#include <QTcpServer>
#include <QRunnable>
#include <QThreadPool>
#include <QString>
#include <QString>
#include <QStringList>
#include <QDebug>
#include <QSettings>
#include <QMap>

#include "CPlayWindow.h"
#include "UartServer.h"
#include "IvfdHttpC.h"
#include "IVFDHttpServer.h"
#include "IvfdLogger.h"
#include "CIVFDFtp.h"
#include "IVFDFtpSever.h"
#include "IVFDBroadCast.h"
#include "IVFDTcpServer.h"
#include "IVFDTcpClient.h"
#include "IVFDEventManager.h"

#define MAXEVENTNUM 6
using namespace IvfdLogNameSpace;


enum ECMDTYPE {CMD_CONTROL, \
               CMD_CREATECPLAYW, \
               CMD_DOWNLOADLOG, \
               CMD_GETBRIGHT0, \
               CMD_GETBRIGHT1, \
               CMD_GETBRIGHTBALANCE0, \
               CMD_GETBRIGHTBALANCE1, \
               CMD_GETCONTRAST0, \
               CMD_GETCONTRAST1, \
               CMD_CURRENTSTATUS, \
               CMD_GETDIARYINFO, \
               CMD_GETGAIN0, \
               CMD_GETGAIN1, \
               CMD_GETNETINFO, \
               CMD_GETSATRUATION0, \
               CMD_GETSATRUATION1, \
               CMD_GETUSERINFO, \
               CMD_GETSYSINFO, \
               CMD_LOGIN, \
               CMD_SETALGPARA, \
               CMD_SETBRIGHT, \
               CMD_SETBRIGHTBALANCE, \
               CMD_SETBYTEARRAY, \
               CMD_SETEXPOSURE, \
               CMD_SETGAIN, \
               CMD_SETGPIO, \
               CMD_SETNETINFO, \
               CMD_SETSATURATION, \
               CMD_STARTALGDET, \
               CMD_STARTALL, \
               CMD_STARTRTSP0, \
               CMD_STARTRTSP1,\
               CMD_STOPALL, \
               CMD_STOPRTSP0, \
               CMD_STOPRTSP1, \
               CMD_SWITCH, \
               CMD_SWITCHRTSP, \
               CMD_SYNCTIMESTAMP, \
               CMD_UPLOADFILE, \
               NOCOMMAND
              };

enum EHWVAL{
    EHWCAM0/*0*/, EHWCAM1/*1*/, EHWSGPIO/*2*/, EHWTODEFINE/*3*/, ALGARGWEIGHT1/*4*/, ALGARGALPHA/*5*/, ALGARGBETA/*6*/, \
    SYSTEMRESET/*7*/, SETNETCONFIG/*8*/, LOGIN/*9*/, RESETSTATUS/*10*/, ALARMENABLE/*11*/, \
    CALIBRATE/*12*/, ALGFIREONOFF/*13*/, ALGSMOKEONOFF/*14*/, INITCAMERA/*15*/, SDCARD/*16*/
};

//定义一个函数指针
typedef void (*callback)(void);
//定义命令结构体
typedef struct cmd{
    QString name;  //命令的名字
    callback func;  //与命令相对应的函数指针
}cmd_table;


typedef struct CmdPara{
    enum ECMDTYPE cmdtype;
    qint32 cmdval;
    EHWVAL id;
}CmdPara;

typedef struct CameraPara{
    int id;
    int bright;
    int gain;
    int whitebalance;
}CameraPara;

typedef struct ALARMEVENT{
    int status;
    int memid;
    ALARMDATAINFO *alamdatainfo;
}ALARMEVENT;

class CPlayWindow;
class UartServer;


class IVFDUiDesign : public QMainWindow
{
	Q_OBJECT

public:
	IVFDUiDesign(QWidget *parent = 0);
	~IVFDUiDesign();

    void DoDownLoadFile(QFile *file);
    void DoCmdType(enum ECMDTYPE cmdtype, QString cmd);
    bool event(QEvent *event);

    void SendSigSwitchRtsp();
    //声明命令数组
    cmd_table  cmd_tbl[3];

    int m_onwatchstatus;
    ALARMDATAINFO *m_alarmdatainfo;
    static SeqQueue *m_queueevent;
    ALARMEVENT m_alarmarray[MAXEVENTNUM];

    cmd_table* cmd_find(QString &cmdname);
    CmdPara CtlCmdFind(QString cmd);
    void DoCtlCmdFind(CmdPara cmd);
signals:
    void SIG_StartTcpServerThread();
    void SIG_CmdFromBrowser(QString,QString);

    void SIG_OpenCPlayWindow();
    void SIG_RecreateCPlayWindow();
    void SIG_StartAlgDet(int algId);
    void SIG_StartAlgFireDet(int);
    void SIG_CapureYUVFile(int num);
    void SIG_StopAlgFireDet();
    void SIG_CaptureAndDIP();
    void SIG_StartThreadIVFDEventManager();
    void SIG_StartIVFDEventManager();

    void SIG_GetSysInfo();
    void SIG_UploadFile();
    void SIG_CurrentStatus();
    void SIG_SyncTimeStamp_0();
    void SIG_GetTimeStamp_0();
    void SIG_GetTimeStamp_1();

    void SIG_AnswerCmdToHttpServer(QByteArray answer);

    void SIG_SendTcpServerContent(QByteArray content);
    void SIG_SendToClient(QByteArray, QByteArray);

    void SIG_UpdateTimeStamp(qlonglong);
    void SIG_SetCameraParam(int ctl_id);
    void SIG_SetInitFilesVal(enum ECMDTYPE, enum EHWVAL id, qint32 val);
    void SIG_NoIdentityCmd(enum ECMDTYPE, enum EHWVAL id, qint32 val);
    void SIG_Control(enum ECMDTYPE, enum EHWVAL id, qint32 val);

    void SIG_SetCameraParameter(int name, int val1, int val2, int val3);
    void SIG_SetGPIOOUT(int pin, int val);
    void SIG_SendMsgToTcpServer(QByteArray cmd ,QByteArray val);
    void SIG_TestTcpClient();

    void SIG_GetCmdFromLocalTcpServer(QByteArray);
    void SIG_QueryAlgStatus(int val);//send cmd get currentstatus to algmodule;
    void SIG_GetAlgStatus(int);

public slots:
    void SLOT_CreateCPlayWindow();
    void SLOT_RecreateCPlayWindow();
    void SLOT_BtnCloseClick();
    void SLOT_CmdFromBrowser(QString, QString);
    void SLOT_CurrentStatus();
    void SLOT_SyncTimeStamp_0();
    void SLOT_DoProcessMsgFromCPlayW(QByteArray msg);
    void SLOT_UpdateTimeStamp(qlonglong);

    void SLOT_SetCameraParam(int ctr_id, int setvalue);
    void SLOT_SetInitFilesVal(enum ECMDTYPE, enum EHWVAL, qint32);
    void SLOT_NoIdentityCmd(enum ECMDTYPE, enum EHWVAL id, qint32 val);
    void SLOT_Control(enum ECMDTYPE, enum EHWVAL id, qint32 val);
    void SLOT_SetGPIOOUT(int pin, int val);
    void SLOT_SendMsgToTcpServer(QByteArray cmd, QByteArray val);

    void SLOT_GetCmdFromLocalTcpServer(QByteArray);
    void SLOT_GetAlgStatus();

public:
    CPlayWindow *m_videoCapture;
    IVFDTcpServer *m_IVFDTcpServer;
    IVFDTcpClient *m_IVFDTcpClient;
    IVFDEventManager *m_IVFDEventManager;

    QString m_localIpAddr;
    quint16 m_portUDPServer;
    quint16 m_portUDPClient;
    quint16 m_portTCPServer;
    quint16 m_portTCPClient;
    qlonglong m_timeStamp;//be updated by every frame captured;
    void InitThis(void);
    void CreateEnviorment(void);

private:
	Ui::IVFDUiDesignClass ui;
    QSettings *m_settings;
    QStringList m_cmdlist;
    CameraPara m_campara0, m_campara1;
};

#endif // IVFDUIDESIGN_H
