#include <QApplication>
#include <QWidget>
//#include "mainwindowimpl.h"
#include <QTextCodec>
//#include "frminput.h"
//#include "frmnum.h"
#include <QSplashScreen>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "IVFDUiDesign.h"
#include "CPlayWindow.h"
#include "IvfdHttpC.h"
#include "IvfdLogger.h"
#include "CIVFDFtp.h"
#include "IVFDBroadCast.h"
#include <QThread>
#include <pthread.h>
#include <QElapsedTimer>

//#include "IVFDFtpSever.h"

//CModallessDialog  *toastdialog;  //最好定义成全局变量
//MainWindowImpl *pMainWindowImpl;

IVFDUiDesign *pIVFDUiDesign;

#if defined(Q_OS_LINUX)

void testStopN(int signo)
{
    printf("oops! stop!!! %d\n",signo);
    if(pIVFDUiDesign->m_videoCapture!=NULL)
    {
        printf("oops! stop preview!!! %d\n",signo);
        pIVFDUiDesign->m_videoCapture->stopRecord();

    }
    //abort();
    _exit(0);
}

#endif

void forChinese(QApplication *app)
{
#if defined(Q_OS_LINUX)
    signal(SIGINT, testStopN);
#endif
    //QApplication::setStyle("macintosh");


#if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
    //QT5版本以上默认就是采用UTF-8编码
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
#endif
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
    qApp->setFont(QFont("WenQuanYi Zen Hei", 12));

#ifndef __arm__
    //如果输入法字库文件不存在,自动拷贝字库文件
    QString path = qApp->applicationDirPath();
    QFile file(path + "/py.db");
    if (!file.exists() || file.size()==0) {
        QStringList list = path.split("/");
        QString fileName, newName;
        for (int i = 0; i < list.count() - 2; i++) {
            fileName = fileName + list.at(i) + "/";
        }
        fileName += "InputTool/py.db";
        newName = path + "/py.db";
        file.remove();
        QFile::copy(fileName, newName);
        qDebug() << "print py copy";
    }
#endif
}

enum ALGTYPE{INTRUDE, FIRE, SMOKE};

int main(int argc, char ** argv)
{
    QApplication app( argc, argv );

    IVFDUiDesign w;
    pIVFDUiDesign = &w;
    forChinese(&app);

    qDebug() << "-------main thread-------"<< QThread::currentThread();
    qApp->setProperty("noinput",true);
    QSplashScreen splash(QPixmap(":/images/image/bandweaver.png"));
    splash.setDisabled(true); //禁用用户的输入事件响应
    splash.show();

    splash.showMessage(QObject::tr("asteroid 正在启动中...."),
                       Qt::AlignLeft|Qt::AlignBottom,Qt::green);
    QElapsedTimer t;
    t.start();

     while(t.elapsed()<500)
     {
         QCoreApplication::processEvents();
     }

    printf("wind show---test---!\r\n");

//here designe to start in right order;
//    step1:broad cast to the network, get the client address;
//    emit w.SIG_StartBroadCast();

//    step2:start the httpserver;
//    w.SLOT_Send_SigCreateIVFDHttpServer();
//    QThread::msleep(1000);

//    step3: create the CPlayWindow;
    w.SIG_OpenCPlayWindow();
    QThread::msleep(10);

//    step4: start rtsp;
    w.SIG_CaptureAndDIP();
    QThread::msleep(10);
//    w.m_videoCapture->SIG_InitCamera();
//    step5: start algorithm detect
    enum ALGTYPE type = FIRE;
    w.SIG_StartAlgFireDet((int)type);//alg aread exist ,this only to call the process function
//    steo6: start tcpserver;
    QThread::msleep(10);
    w.SIG_StartTcpServerThread();//create a thread to run local tcpserver thread
    QThread::msleep(10);
    w.SIG_StartThreadIVFDEventManager();//create a thread to run event manager
    QThread::msleep(10);
    w.SIG_StartIVFDEventManager();//send a sig to do event manager,notice that in different thread.

    w.show();
    splash.finish(w.m_videoCapture);

    qApp->setProperty("noinput",true);

    app.connect( &app, SIGNAL(lastWindowClosed() ), &app, SLOT( quit() ) );
    //QTimer::singleShot(1000, &win, SLOT(startRecorder()));
	return app.exec();
}
