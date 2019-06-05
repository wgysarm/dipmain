#ifndef MPLAY_HH_HH_H
#define MPLAY_HH_HH_H

#include <QWidget>
#include <QProcess>
#include <QDialog>
#include <QLCDNumber>
#include <QWidget>
#include<QTextEdit>
#include<QApplication>
#include<QSystemTrayIcon>
#include <QDialog>
#include <QAction>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QSplitter>
#include <QSlider>
#include <QListView>
#include <QFileDialog>

class QProcess;
class QLabel;
class QString;
class QPushButton;
class QSlider;
class QTimerEvent;
class QIcon;
class QLabel;
class QSplitter;
class PlayerList;
#if defined(Q_OS_LINUX)
#define AUTPLAYER 1
#endif

#if defined(AUTPLAYER)
#include "AutPlayer.h"

using namespace android;
#endif
class MyPlayer:public QWidget
{
	Q_OBJECT;
	
	public:
		MyPlayer(QWidget *parent=0);
        ~MyPlayer();

		void timerEvent(QTimerEvent *event);												//ʱ���¼�
#if defined(AUTPLAYER)
        AUTPlayer *ap;
#endif
        int informerr();
	private:
		void MyPlayerCreate();																			//����Mplayer
		void MyPlayerConnect();																			//����Mplayer
		void MyPlayerLayout();																			//���ֹ���

		void MyPlayerStart(const QString &filename,const QString &wid);		//��ʼ����
		void sendCommand(const QString& command);													//�����

		

	private:
		void getCurTimePos();																							//��õ�ǰʱ���λ��
		void getTimeLength();																							//���ʱ�䳤��
		void receivedData();																							//�������
		void seek(int value, int type);																		//��λ
		int set_volume(int value);																				//��������
		QString TimetoString(int seconds);																//��ʱ��ת��Ϊ�ַ���
		void replay();																										//���²���

	signals:
		void GetcurrentTimePos(int pos);																	//��õ�ǰʱ��λ��
		void GetvidioLength(int timeLength);															//�������������ʱ��

	private slots:
		void changeTimeSlider(int pos);																		//�ı�ʱ�������
		void setTimeSliderRange(int length);															//���ý�������Χ

		void resume();																										//����
		void stop();																											//ֹͣ
#if defined(AUTPLAYER)
        static int end(int32_t msgType, void *user);															//����
#endif
     void end(int, QProcess::ExitStatus);

        void slotTimeLineSliderpress();																		//���½������Ĳ�
		void slotTimeLineSliderreleased();																//�ͷŽ������Ĳ�
		void slotVolumeChange(int volume);																//�ı�����
		void slotNextButton();																						//���
		void slotBackButton();																						//����
		void slotOpenButton();																						//�򿪰�ť
		void slotVolumeButton();																					//������ť
		void slotHideButton();																						//���ذ�ť
		void slotCloseButton();																						//�رհ�ť			

		void slotNextVidioButton();																				//��һ��
		void slotBackVidioButton();																				//��һ��

		void slotmyListSIGNAL(int Index);																	//�����б��ź�
	private:
		bool isPlaying;									//�Ƿ��ڲ���
		bool isPause;										//�Ƿ�ֹͣ
		bool isMute;										//�Ƿ���										
		QString currentfile;						//��ǰ�ļ�
		int currentpos;									//��ǰλ��
		int currentVolume;							//��ǰ����
		QString fileLength;							//�ļ�����

	private:
		QProcess *process;							//����ָ��
		QLabel *showlabel;							//��ʾ��ǩ
		QString wid;										//
		int mytimerID;									//��ʱ�����
		int playIndex;									//��������

	private:
		QPushButton *StartButton;				//��ʼ��ť
		QPushButton *StopButton;				//ֹͣ��ť
		QPushButton *NextButton;				//�����ť
		QPushButton *BackButton;				//���˰�ť
		QPushButton *OpenButton;				//�򿪰�ť
		QPushButton *VolumeButton;			//������ť
		QPushButton *hideButton;				//���ذ�ť
		QPushButton *closeButton;				//�رհ�ť
		QPushButton *NextVidioButton;		//��һ����ť
		QPushButton *BackVidioButton;		//��һ����ť

		QSlider *TimeLineSlider;				//ʱ�������
		QLabel *showtimeLabel;					//��ʾʱ���ǩ
		QSlider *volumeSlider;					//����������
		
		QSplitter *splitter;						//������
		PlayerList *mylist;							//�б����ڷ�������ѡ�е��ļ�����Ϣ
};


#endif
