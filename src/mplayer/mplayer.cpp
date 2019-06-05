#include "mplayer.h"
#include "playerlist.h"
#include <QtGui>
#include <QProcess>
#include <iostream>
#include <QtCore>
#include <QtDebug>
#include <sys/types.h>
#include <sys/stat.h>
//#include <ioctl.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <QString>
#include <QMessageBox>
//#include <linux/soundcard.h>

//#define ARM_LINUX
#if defined(Q_OS_LINUX)
#define AUTPLAYER 1
#endif
MyPlayer::MyPlayer(QWidget *parent)														//���캯��
{
	QIcon volumeIcon(":/images/volume.png");										//����ͼ��
	QIcon muteIcon(":/images/mute.png");												//����ͼ��
	
	MyPlayerCreate();																//��������
	MyPlayerConnect();															//���Ӻ���
	MyPlayerLayout();																//���ֺ���
	
	isPlaying = false;															//Ĭ��û�в���

	QSettings volumeconfig("../settings/volume.ini", QSettings::IniFormat);	//��������
	isMute = volumeconfig.value("isMute").toBool();													//�Ƿ���
	currentVolume = volumeconfig.value("volume").toInt();										//��ǰ����
	volumeSlider->setValue(currentVolume);																	//���ݵ�ǰ������������������ֵ
	
	if(isMute)								//�Ƿ���
	{
		set_volume(0);					//����Ǿ����Ļ��ͽ���������Ϊ0
		VolumeButton->setIcon(muteIcon);//��ͼ������Ϊ������
	}
	else
	{
		set_volume(currentVolume);					//������������Ϊ��ǰ����
		VolumeButton->setIcon(volumeIcon);	//��ͼ������Ϊ����ͼ��
	}
	

	
    setGeometry(0,0,800,480);							//��������
	
	setWindowFlags(Qt::FramelessWindowHint);//�����ޱ߿�
#if defined(AUTPLAYER)
    ap=new AUTPlayer();
#endif
    printf("MyPlayer\r\n");
}
MyPlayer::~MyPlayer()
{
    printf("~MyPlayer\r\n");
#if defined(AUTPLAYER)
    delete ap;
#endif

}
void MyPlayer::MyPlayerCreate()															//����MPlayer
{

	showlabel = new QLabel;					//������ʾ��ǩ
    //showlabel->setBackgroundRole(QPalette::Dark);			//���ñ���ɫΪ��ɫ
    //showlabel->setStyleSheet();
    showlabel->setStyleSheet(QStringLiteral("background-color: rgba(112, 200, 11, 0);"));
    showlabel->resize(800,480);												//���ô�С
	showlabel->setAutoFillBackground(true);						//�����Զ����
	showlabel->setAlignment(Qt::AlignLeft | Qt::AlignTop);	//���ö��뷽ʽΪ���ϽǶ���
	
	process = new QProcess(this);			//��������

	StartButton = new QPushButton;		//��ʼ��ť
	StopButton = new QPushButton;			//ֹͣ��ť
	NextButton = new QPushButton;			//�����ť
	BackButton = new QPushButton;			//���˰�ť
	OpenButton = new QPushButton;			//�򿪰�ť
	VolumeButton = new QPushButton;		//������ť
	hideButton = new QPushButton;			//���ذ�ť
	closeButton = new QPushButton;		//�رհ�ť
	NextVidioButton  = new QPushButton;	//��һ����ť
	BackVidioButton  = new QPushButton;	//��һ����ť
	
	QIcon playIcon(":/images/play.png");		//����ͼ��
	QIcon pauseIcon(":/images/pause.png");	//��ͣͼ��
	QIcon nextIcon(":/images/next.png");		//���ͼ��
	QIcon backIcon(":/images/prev.png");		//����ͼ��
	QIcon stopIcon(":/images/stop.gif");		//ֹͣͼ��
	QIcon openIcon(":/images/open.png");		//��ͼ��
	QIcon volumeIcon(":/images/volume.png");//����ͼ��
	QIcon muteIcon(":/images/mute.png");		//����ͼ��
	QIcon hideIcon(":/images/back1.png");		//����ͼ��
	QIcon closeIcon(":/images/close.png");	//�ر�ͼ��
	QIcon nextvidioIcon(":/images/next.gif");	//��һ��ͼ��
	QIcon backvidioIcon(":/images/back.gif");	//��һ��ͼ��

	showtimeLabel = new QLabel;								//��ʾʱ���ǩ
	showtimeLabel->setFixedSize(80,6);				//������ʾʱ���ǩ�Ĵ�С
	QFont font("Helvetica", 7, QFont::Bold);	//��������
	showtimeLabel->setFont(font);							//������ʾʱ���ǩ������

	StartButton->setIcon(pauseIcon);					//����ʼ��ť��ͼ������Ϊ��ͣͼ��
    StartButton->setIconSize(QSize(50,50));		//���ÿ�ʼͼ��Ĵ�С
    StartButton->setFixedSize(50,50);					//���ù̶���С
	StartButton->setFlat(true);								//���ñ�ƽ

	StopButton->setIcon(stopIcon);						//��ֹͣ��ť��ͼ������Ϊֹͣͼ��
    StopButton->setIconSize(QSize(50,50));		//���ô�С
    StopButton->setFixedSize(50,50);					//���ù̶���С
	StopButton->setFlat(true);								//���ñ�ƽ
	//Flat :If this property is set, most styles will not paint the button background unless the button is being pressed

	NextButton->setIcon(nextIcon);						//���ÿ����ť��ͼ��Ϊ���ͼ��
    NextButton->setIconSize(QSize(50,50));		//���ô�С
    NextButton->setFixedSize(50,50);					//���ù̶���С
	NextButton->setFlat(true);								//���ñ�ƽ

	BackButton->setIcon(backIcon);						//���ÿ��˰�ť��ͼ��Ϊ����ͼ��
    BackButton->setIconSize(QSize(50,50));		//���ô�С
    BackButton->setFixedSize(50,50);					//���ù̶���С
	BackButton->setFlat(true);								//���ñ�ƽ

	OpenButton->setIcon(openIcon);						//���ô򿪰�ť��ͼ��
    OpenButton->setIconSize(QSize(50,50));		//���ô�С
    OpenButton->setFixedSize(50,50);					//���ô�С�̶�
	OpenButton->setFlat(true);								//���ñ�ƽ

	VolumeButton->setIcon(volumeIcon);				//����������ť��ͼ��Ϊ����
    VolumeButton->setIconSize(QSize(50,50));	//���ô�С
    VolumeButton->setFixedSize(50,50);				//���ù̶���С
	VolumeButton->setFlat(true);							//���ñ�ƽ

	hideButton->setIcon(hideIcon);						//�������ذ�ť��ͼ��
    hideButton->setIconSize(QSize(50,50));		//����ͼ���С
    hideButton->setFixedSize(50,50);					//���ù̶���С
	hideButton->setFlat(true);								//���ñ�ƽ

	closeButton->setIcon(closeIcon);					//���ùرհ�ť��ͼ��
    closeButton->setIconSize(QSize(50,50));		//����ͼ���С
    closeButton->setFixedSize(50,50);					//���ù̶���С
	closeButton->setFlat(true);								//���ñ�ƽ

	NextVidioButton->setIcon(nextvidioIcon);			//������һ����ť��ͼ��
    NextVidioButton->setIconSize(QSize(50,50));		//����ͼ���С
    NextVidioButton->setFixedSize(50,50);					//���ù̶���С
	NextVidioButton->setFlat(true);								//���ñ�ƽ

	BackVidioButton->setIcon(backvidioIcon);			//������һ����ť��ͼ��
    BackVidioButton->setIconSize(QSize(50,50));		//����ͼ���С
    BackVidioButton->setFixedSize(50,50);					//���ù̶���С
	BackVidioButton->setFlat(true);								//���ñ�ƽ
	

	TimeLineSlider = new QSlider(Qt::Horizontal);	//���ý�����Ϊˮƽ��
    TimeLineSlider->setRange(0,1020);							//���ý�������Χ
	volumeSlider = new QSlider(Qt::Horizontal);		//����������Ϊˮƽ
	volumeSlider->setRange(0,100);								//���÷�Χ
	volumeSlider->setValue(10);										//����Ĭ��ֵ
	volumeSlider->setFixedSize(60,4);							//���ù̶���С


	splitter = new QSplitter(Qt::Horizontal);			//���ù�����Ϊˮƽ
	mylist = new PlayerList;											//���첥���б�
	playIndex = 0;																//��ʼ����������Ϊ0

}


void MyPlayer::MyPlayerConnect()							//�źźͲ۵�����
{

	connect(this,SIGNAL(GetcurrentTimePos(int)),this,SLOT(changeTimeSlider(int)));	//��������λ��
	connect(this,SIGNAL(GetvidioLength(int)),this,SLOT(setTimeSliderRange(int)));		//�������ĳ���

	connect(StartButton,SIGNAL(clicked()),this,SLOT(resume()));			//��ʼ��ť����󲥷�
	connect(StopButton,SIGNAL(clicked()),this,SLOT(stop()));				//ֹͣ��ť�����ֹͣ
	connect(OpenButton,SIGNAL(clicked()),this,SLOT(slotOpenButton()));	//�򿪰�ť������
	
	connect(TimeLineSlider,SIGNAL(sliderPressed()),this,SLOT(slotTimeLineSliderpress()));//���½�����
	connect(TimeLineSlider,SIGNAL(sliderReleased()),this,SLOT(slotTimeLineSliderreleased()));//�ͷ�������

	connect(NextButton,SIGNAL(clicked()),this,SLOT(slotNextButton()));				//���¿����ť
	connect(BackButton,SIGNAL(clicked()),this,SLOT(slotBackButton()));				//���¿��˰�ť

	connect(NextVidioButton,SIGNAL(clicked()),this,SLOT(slotNextVidioButton()));	//������һ����ť
	connect(BackVidioButton,SIGNAL(clicked()),this,SLOT(slotBackVidioButton()));	//������һ����ť

	connect(VolumeButton,SIGNAL(clicked()),this,SLOT(slotVolumeButton()));				//����������ť
	connect(volumeSlider,SIGNAL(valueChanged(int)),this,SLOT(slotVolumeChange(int)));	//�ı���������ֵ
	connect(hideButton,SIGNAL(clicked()),this,SLOT(slotHideButton()));						//���ذ�ť�����
	connect(closeButton,SIGNAL(clicked()),this,SLOT(slotCloseButton()));					//�رհ�ť�����

	connect(mylist,SIGNAL(playmyList(int)),this,SLOT(slotmyListSIGNAL(int)));			//��������б�

	
	//connect(process, SIGNAL(readyRead()), this, SLOT(receivedData())); 
    #if defined(AUTPLAYER)
#else
	connect(process, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(end(int, QProcess::ExitStatus)));
#endif																																			//����ִ���꣬�˳�
}

void MyPlayer::MyPlayerLayout()					//���ֹ���
{

	splitter->addWidget(showlabel);				//�����ʾ��ǩ
	//splitter->addWidget(mylist);					//����б�

	QHBoxLayout *buttonLayout = new QHBoxLayout;		//��ť���ֹ����������ڲ��ָոմ����İ�ť
	buttonLayout->addWidget(OpenButton);
	buttonLayout->addWidget(StopButton);
	//buttonLayout->addWidget(BackVidioButton);
	buttonLayout->addWidget(BackButton);
	buttonLayout->addWidget(StartButton);
	buttonLayout->addWidget(NextButton);
	//buttonLayout->addWidget(NextVidioButton);
	//buttonLayout->addWidget(hideButton);
	//buttonLayout->addWidget(closeButton);
	buttonLayout->addWidget(VolumeButton);
	buttonLayout->addWidget(volumeSlider);					//���������
    //buttonLayout->addStretch();
	buttonLayout->addWidget(closeButton);
	

	QHBoxLayout *lineLayout = new QHBoxLayout;			//���������ֹ���
	lineLayout->addWidget(TimeLineSlider);
	lineLayout->addWidget(showtimeLabel);

	QVBoxLayout *layout = new QVBoxLayout;					//���岼�ֹ�����
	layout->addWidget(splitter);							//��ӹ�����
	layout->addLayout(lineLayout);						//��ӽ��������ֹ�����
	layout->addLayout(buttonLayout);					//��Ӱ�ť���ֹ�����
	
	setLayout(layout);	//�����ܵĲ��ֹ���

	
}
int MyPlayer::informerr()
{
    QMessageBox* box = new QMessageBox;
    QTimer::singleShot(1000, box, SLOT(close()));

    box->setWindowTitle(tr("takepic"));
    box->setStyleSheet(QStringLiteral("background-color: rgb(0, 200, 11);"));
    box->setIcon(QMessageBox::Warning);
    box->move(30,430);
    box->show();
    return 0;
}
void MyPlayer::MyPlayerStart(const QString &filename,const QString &wid)		//mplayer����
{

	QStringList args;				//MPlayer���������б�
#if defined(AUTPLAYER)
    printf("mplayer start is %s \r\n",filename.toStdString().c_str());
   int ret = ap->setUrl((char*)filename.toStdString().c_str());
    if(ret<0){
        printf("------set url err\r\n");
        informerr();
        return;
    }
   ap->setViewWindow(0,0,ap->getDispwidth(),ap->getDispheigth()-80);
   //sleep(1);
   ap->setUserCb(end,this);
   ret=ap->play();
   if(ret<0){
       printf("------set url err\r\n");
       informerr();
       return;
   }
    isPlaying = true;			//�������ڲ���
    isMute = false;				//���ò��Ǿ���
    receivedData();				//�������
    getTimeLength();			//���ʱ�䳤��
   mytimerID = startTimer(500);		//���ʱ��ID
#else
	args << "-slave";
	args << "-quiet";
	
#ifdef ARM_LINUX

	args << "-ac";   
	args << "mad";
#endif	
	args << "-zoom";
	args << "-aspect"; //screen rate command
	args << "16:9";     //screen rate
	args << "-wid";    //play window path   
	args << wid;   
	args << "-autosync" << "100";
	args << filename;  

	isPlaying = true;			//�������ڲ���
	isMute = false;				//���ò��Ǿ���
	process->start("mplayer",args);	//����ִ��

	receivedData();				//�������
	getTimeLength();			//���ʱ�䳤��
	mytimerID = startTimer(20);		//���ʱ��ID


#endif
	
}






void MyPlayer::changeTimeSlider(int pos)			//�ı������
{
	QString s;
	if((pos<TimeLineSlider->maximum() )&& (pos >0))		//�ж�ʱ��λ���Ƿ���ȷ
	{
		currentpos = pos;										//��ǰλ��
		TimeLineSlider->setValue(pos);			//���ý�������ֵ
		s = TimetoString(pos);							//��ò��ŵ���ʱ��
		s += "/";														
		s += fileLength;
		showtimeLabel->setText(s);					//����ʱ���ǩ������
	}
	
}

void MyPlayer::setTimeSliderRange(int length)		//���ý������ķ�Χ
{
	QString s;
	TimeLineSlider->setRange(0,length);						
	fileLength = TimetoString(length);
	s = "00:00 / ";
	s += fileLength;
	showtimeLabel->setText(s);
}

void MyPlayer::timerEvent(QTimerEvent *event)		//�������¼�
{
    if(event->timerId() == mytimerID)				//������Լ���õ�ID
	{	
		getCurTimePos();							//��õ�ǰʱ��λ��
		receivedData();								//�������
	}
	else
		QWidget::timerEvent(event);		//���¼�������������
}


void MyPlayer::slotTimeLineSliderpress()		//��������������¼�
{
	isPause = false;													//��ͣ��
	resume();																	//���²���
}
void MyPlayer::slotTimeLineSliderreleased()	//�½������ͷź���
{
	isPause = true;														//��ͣ��
	resume();																	//���²���
	int movetime;															//Ҫ�ƶ�����ʱ��
	movetime = TimeLineSlider->value();				//���Ҫ�ƶ�����ʱ��ֵ
	seek(movetime,2);													//��λ

}

void MyPlayer::slotNextButton()							//��������ť
{
	if(isPlaying)											//������ڲ���
	{
		isPause = false;
		resume();
		
		seek(4,0);			//���¶�λ
		
		isPause = true;
		resume();
	}
}

void MyPlayer::slotBackButton()							//������˰�ť
{
	if(isPlaying)											//������ڲ���
	{
		isPause = false;
		resume();
		
		seek(-4,0);		//���¶�λ
		
		isPause = true;
		resume();
	}
}


void MyPlayer::replay()						//���²���
{
    printf("--------------replay \r\n");
	//QTest::qSleep(1000);				//˯һ��	
	sleep(1000);		
	stop();									//ֹͣ����
	qDebug("replay stop");
		
	wid =QString::number(showlabel->winId()) ;				//�����ʾ��ǩ��ID

	MyPlayerStart(currentfile,wid);					//����mplayer
	
}


void MyPlayer::slotNextVidioButton()			//������һ����ť�����¼�
{
	
	int Countrow = mylist->model->rowCount()-1;				//����б��е���������Ϊ������0��ʼ����Ҫ��1
	if (playIndex < Countrow)							//�����������С������
	{
		playIndex++;												//������������
		
		if(playIndex > Countrow)						//��������������ڵ�ǰ�����������»ص���ʼ��
		{
			playIndex = 0;			//���»ص���ʼ��
		}
	}

	if(isPlaying)		//������ڲ�����Ҫֹͣ
	{
		stop();
	}
	
	if(playIndex >=0)			//�жϲ��������Ƿ�Ϸ�
	{
		currentfile = mylist->myPlayList.at(playIndex);			//���õ�ǰ�ļ�

		wid =QString::number(showlabel->winId()) ;					//�����ʾ��ǩID

		QModelIndex index = mylist->model->index(playIndex);	//����ģʽ����
		mylist->listView->setCurrentIndex(index);							//���õ�ǰ����
		MyPlayerStart(currentfile,wid);												//��ʼ����
	}
	else
		stop();										//��������ֵ���Ϸ�ʱֹͣ����
}

void MyPlayer::slotBackVidioButton()				//��һ����ť
{
     printf("--------------slotBackVidioButton \r\n");
	int Countrow = mylist->model->rowCount()-1;			//�������
	if (playIndex < Countrow)				//�жϲ��������Ƿ�Ϸ�
	{
		playIndex--;									//����ֵ��
		if(playIndex < 0)							//�����������ֵС��0�ˣ����������һ��
			playIndex = Countrow;
	}

	if(isPlaying)									//������ڲ�����Ҫֹͣ
	{
		stop();
	}
	
	if(playIndex >=0)							//�ж�����ֵ�Ƿ�Ϸ�
	{
		currentfile = mylist->myPlayList.at(playIndex);		//���õ�ǰ�ļ�

		wid =QString::number(showlabel->winId()) ;				//�����ʾ��ǩ���б�

		QModelIndex index = mylist->model->index(playIndex);		//����ģʽ����
		mylist->listView->setCurrentIndex(index);								//���õ�ǰ����

		MyPlayerStart(currentfile,wid);										//����MPlayer����
	}
	else
		stop();											//����ֵ���Ϸ�Ҫֹͣ
		
}

void MyPlayer::slotOpenButton()				//����򿪰�ť�¼�
{
    printf("--------------slotOpenButton \r\n");
	QString fileName = QFileDialog::getOpenFileName(this,				//���Ҫ�򿪵��ļ�����Ϣ
                                   tr("Open video"), ".",
                                  tr("video files (*.wmv *.avi *.mp3 *.mp4)"));
	if(!fileName.isEmpty())					//����ļ�����Ϊ�յĻ�
	{
				
		if(isPlaying)					//������ڲ��ž�Ӧ��ֹͣ
		{
			stop();
		}
		currentfile = fileName;				//��ǰ�ļ�Ϊ�ոջ�õ��ļ���
				
		wid =QString::number(showlabel->winId()) ;			//�����ʾ��ǩ��ID

		//qDebug("Start 1111");
		MyPlayerStart(currentfile,wid);									//����MPlayer

		
		mylist->myPlayList.append(fileName);						//�����ļ���ӵ�������ȥ
		mylist->strlist<<QFileInfo(fileName).fileName();//		QStringList strlist;
																										//	QVector<QString> myPlayList;	
		mylist->model->setStringList(mylist->strlist);	//������ʾ���б�
		int row = mylist->model->rowCount()-1;					//�������

		if(row>=0)			//��������Ϸ��Ļ�
		{
			QModelIndex index = mylist->model->index(row);			//����ģʽ����
		
			mylist->listView->setCurrentIndex(index);						//���õ�ǰ����
		}
		
	}
}


void MyPlayer::slotVolumeButton()								//������ť����Ĳ�
{
	QSettings volumeconfig("../settings/volume.ini", QSettings::IniFormat);	//�����������ü���
	
	QIcon volumeIcon(":/images/volume.png");		//������ťͼ��
	QIcon muteIcon(":/images/mute.png");				//����ͼ��


	if(isMute)							//����������Ǿ����Ļ�����������������������������������������������������
	{
		set_volume(currentVolume);							//��������Ϊ��ǰ����
		VolumeButton->setIcon(volumeIcon);			//����ͼ��
		isMute = false;													//���Ǿ���
	}
	else
	{
		set_volume(0);													//��������Ϊ0
		VolumeButton->setIcon(muteIcon);				//���þ���ͼ��
		isMute = true;
	}
	volumeconfig.setValue("isMute",isMute);			//�ı��¼���е��Ƿ���ֵ
	volumeconfig.setValue("volume",currentVolume);//�ı��¼���е�������Сֵ
}

void MyPlayer::slotVolumeChange(int volume)			//�������ı�
{
	QSettings volumeconfig("../settings/volume.ini", QSettings::IniFormat);	//��Ĭ������ֵ
	
	if(volume > 100)		//��ֹ����ֵ���Ϸ�
		volume = 100;
	if(volume < 0)
		volume = 0;
	
	set_volume(volume);			//��������ֵΪ�ո����õ�����
	currentVolume = volume;	//���õ�ǰ����ֵΪ�ո����õ�����
	volumeconfig.setValue("volume",currentVolume);//д��ǰ�������������ü�����
}

void MyPlayer::slotHideButton()			//�������ذ�ť
{
	this->hide();	
}

void MyPlayer::slotCloseButton()		//����رհ�ť
{
	
	stop();								//����ֹͣ����
	
	this->close();

}


QString MyPlayer::TimetoString(int seconds)				//��ʱ��ֵ����ַ���
{
	QString s;
	int hour = seconds / 3600;											//Сʱ
	int minute = (seconds - 3600 * hour) / 60;			//����
	int second = seconds - 3600 * hour - 60 * minute;			//����
	if(!hour)
	{
		s.sprintf("%02d%c%02d%c%02d", hour, ':', minute, ':', second);//���СʱΪ0
	}
	else
	{
		s.sprintf("02d%c%02d", minute, ':', second);
	}

	return s;
}


void MyPlayer::slotmyListSIGNAL(int Index)		//�����б��ϵ��ź�
{
 printf("--------------slotmyListSIGNAL \r\n");
	if(isPlaying)				//������ڲ��ŵĻ���Ҫֹͣ
	{
		stop();							
	}
	if(Index>=0)				//�������ֵ�Ϸ�
	{
		currentfile = mylist->myPlayList.at(Index);		//��õ�ǰ�ļ�

		wid =QString::number(showlabel->winId()) ;		//��ñ��

		MyPlayerStart(currentfile,wid);								//����MPlayer
	}
	else
		stop();
}

#if defined(Q_OS_LINUX)
int  MyPlayer::end(int32_t msgType, void *user)		//����MPlayer
{
    MyPlayer *p = (MyPlayer*)user;
printf("call end \r\n");

    if (msgType == NOTIFY_PLAYBACK_COMPLETE)
    {p->stop();
        //qDebug("End 1111");
        if(p->mylist->loopAroundAll)
        {
            p->slotNextVidioButton();

        }
        else
        {
            //replay();
        }
    }
}
#endif

void MyPlayer::end(int exitCode, QProcess::ExitStatus exitStatus)		//����MPlayer
{
    stop();

	if (exitStatus == QProcess::NormalExit)
    {
		//qDebug("End 1111");
		if(mylist->loopAroundAll)
		{
			slotNextVidioButton();
			
		}
		else
		{
			//replay();
		}
	}
}





/*********************************************************
 **	����   : ��ͣ����			 
 *********************************************************/
void MyPlayer::resume()
{
printf("--------------resume \r\n");
	QIcon playIcon(":/images/play.png");							//����ͼ��
	QIcon pauseIcon(":/images/pause.png");						//��ͣͼ��
	
	if(isPlaying)						//������ڲ���
	{
		if(isPause)						//�����ͣ�˵Ļ�
		{
			isPause = false;		//����Ϊ������ͣ
            mytimerID = startTimer(500);					//��ü�ʱ��ID
			StartButton->setIcon(pauseIcon);		//���ÿ�ʼ��ť��ͼ��Ϊ��ͣͼ��
		}
		else
		{
			isPause = true;				//�����û����ͣ��������ͣ
			killTimer(mytimerID);	//ֹͣ��ʱ��
			StartButton->setIcon(playIcon);			//���ÿ�ʼ��ťͼ��Ϊ����
		}
#if defined(AUTPLAYER)
        ap->pause();
#else
   		sendCommand("pause"); //send contine command    
   		//qDebug("playing");
#endif
	}
	else
	{
		if(!currentfile.isEmpty())			//�����ǰ�ļ��ǿյĵĻ�
		{				
			wid =QString::number(showlabel->winId()) ;		//�����ʾ��ǩID
			StartButton->setIcon(pauseIcon);							//���ÿ�ʼ��ťΪ��ͣ
			
			MyPlayerStart(currentfile,wid);								//����MPlayer
		}
	}
}



int MyPlayer::set_volume(int value)				//��������
{
	int new_vol;									//�洢������ֵ

/*volume value from 0 to 100*/
	if (value > 100)			//�������ܳ���100Ҳ����С��0
	{
	    value = 100;
	}
	if (value < 0)
	{
	    value = 0;
	}

	new_vol = value | (value << 8); //new_vol storage current volume
#if 0
	int mixerfd = open("/dev/mixer",O_WRONLY);//open device driver///dev/dsp", O_RDWR
	if (mixerfd < 0)
	{
		qDebug("Unable to open mixer device.");
		qDebug("\nqDebug:%s,%d",__FILE__,__LINE__);
		return -1;
	}
	if (ioctl(mixerfd, MIXER_WRITE(SOUND_MIXER_VOLUME), &new_vol) == -1)			//�����µ�����ֵ
	{	 
	   qDebug("Unable to ioctl set volume.");
	   qDebug("\nqDebug:%s,%d",__FILE__,__LINE__);
	}
	::close(mixerfd);
#endif
	return value;
}



void MyPlayer::stop( )			//ֹͣ����MPlayer
{
    printf("--------------stop \r\n");
	if(isPlaying)					//������ڲ���
	{
		
		isPlaying = false;	//�������ڲ���Ϊ��
		
		killTimer(mytimerID);		//������ʱ��
		
		QIcon playIcon(":/images/play.png");	//���첥��ͼ��
		StartButton->setIcon(playIcon);				//����ͼ��Ϊ����
		TimeLineSlider->setValue(0);					//����������Ϊ0
#if defined(AUTPLAYER)
        ap->stop();
#else
		sendCommand(QString("quit "));				//�����˳�����

		if(!process->waitForFinished(100))    // su		�ȴ����̽���
		{
		    if(process->state() == QProcess::Running)	//������̵�״̬Ϊ����ִ��
		    {
			    process->close(); //close process
		    }
		}
#endif
	}
}


void MyPlayer::seek(int value, int type)//value was moved value,type is play variety     //su
{
   QString command;
   if(isPlaying)
   {
#if defined(AUTPLAYER)
    ap->seekto(value+ap->getCurrentPosition());
#else
       sendCommand(command.sprintf("seek %d %d", value, type));//send command
#endif
   }
}


void MyPlayer::getCurTimePos()										//��õ�ǰ������λ��
{
#if defined(AUTPLAYER)
    int pos =  ap->getCurrentPosition();
    //cout<<pos<<endl;
    emit GetcurrentTimePos(pos);//send command for get current time
#else
	sendCommand("get_time_pos");//send command for get current time as file to playing
#endif
}

void MyPlayer::getTimeLength()										//��ò���ʱ��ĳ���
{
#if defined(AUTPLAYER)
    int timeLength = ap->getDuration();
    //cout<<timeLength<<endl;
    emit GetvidioLength(timeLength);//send command for get file all time
#else
	sendCommand("get_time_length");		//send command for get all length as file to playing
#endif
}


void MyPlayer::sendCommand(const QString& command)		//��������
{
    QByteArray commandByteArray = command.toLatin1();
	commandByteArray.append(0x0a);
	if(process->write(commandByteArray) != (command.length() + 1))
	{
		qDebug("\nPlayer sendCommand failed");
		qDebug("\nqDebug:%s,%d",__FILE__,__LINE__);
	}
}


void MyPlayer::receivedData()																		//�������
{
#if defined(AUTPLAYER)

#else
	while(process->canReadLine())
	{
		QByteArray output(process->readLine());
        QString str = QString::fromLatin1(output.data());
		//cout<<str.toStdString()<<endl;
		if(str.startsWith(tr("ANS_TIME_POSITION")))
		{
			QString sstr = str.mid(tr("ANS_TIME_POSITION=").length());
			int pos = static_cast<int>(sstr.toFloat()); 
			//cout<<pos<<endl;
			emit GetcurrentTimePos(pos);//send command for get current time
		}
		if(str.startsWith(tr("ANS_LENGTH")))
		{			
			QString sstr = str.mid(tr("ANS_LENGTH=").length());
			int timeLength = static_cast<int>(sstr.toFloat());
			//cout<<timeLength<<endl;
			emit GetvidioLength(timeLength);//send command for get file all time
		}		
	}
#endif
}



