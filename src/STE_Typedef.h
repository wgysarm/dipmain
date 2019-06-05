/********************************************************************
	created:	2014/01/30
	created:	30:1:2014   11:49
	filename: 	D:\work\project\VSV\STEvaluation\STEvaluation\STE_Typedef.h
	file path:	D:\work\project\VSV\STEvaluation\STEvaluation
	file base:	STE_Typedef
	file ext:	h
	author:		SUNNAN
	
	purpose:	
*********************************************************************/
#ifndef __STE_TYPEDEF_H__
#define __STE_TYPEDEF_H__

//���巵������
#define STE_RES_OK			0
#define STE_RES_ERROR			1		//ͨ�ô���

#define STE_MODE_CAPFILE		0
#define STE_MODE_CAPCAM			1
#define STE_MODE_PLAYBACK		2


#define STE_IMAGE_WIDTH			1920//704//1920
#define STE_IMAGE_HEIGH			1080//288//1080


//����������	��	0x2280
#define STE_SYSEVENT_FIRE_S              233
//����������	��	0x2281
#define STE_SYSEVENT_SMOKE_S		 234

#define STE_SYSEVENT_FIRE_E              263
//����������	��	0x2281
#define STE_SYSEVENT_SMOKE_E		 264

//����RGBͼ��ṹ
typedef struct  tagIVFD_RgbImage
{
	int        width;                           //  ͼ����
	int        height;                         //  ͼ��߶�
	unsigned int  frame_mun;        //  ͼ����ţ�0��ʼ
	unsigned int  time;                  //  
	unsigned char * data_r;            //  ����ָ��
	unsigned char * data_g;           //  ����ָ��
	unsigned char * data_b;           //  ����ָ��
} IVFD_RgbImage;

//����YUVͼ��ṹ
typedef struct  tagIVFD_YuvImage
{
	int       width;    //  ͼ����
	int       height;   //  ͼ��߶�
	unsigned int  frame_mun;  //  ͼ����ţ�0��ʼ
	unsigned int  time;   //  
	unsigned char * data_y;   //  ����ָ��
	unsigned char * data_u;   //  ����ָ��
	unsigned char * data_v;   //  ����ָ��
} IVFD_YuvImage;

//����Ҷ�ͼ��ṹ
typedef struct  tagIVFD_Image
{
	int       width;    //  ͼ����
	int       height;   //  ͼ��߶�
	unsigned int	time;
	unsigned int	frame;
	unsigned char * data;   //  ����ָ��
} IVFD_Image;

//�����ṹ
typedef struct  tagIVFD_Point
{
	short   x;      //ˮƽ����
	short   y;      //��ֱ����
} IVFD_Point;

//�����߶νṹ
typedef struct  tagIVFD_Line
{
	IVFD_Point  point_start;    //�߶���ʼ��
	IVFD_Point  point_end;      //�߶���ֹ��
} IVFD_Line;

//������νṹ��Ĭ������Ϊ����ԭ�㣬��assert(top>bottom) && assert(right>left)
typedef struct  tagIVFD_Rect
{
	short   left;
	short   bottom;
	short   right;
	short   top;
} IVFD_Rect; 

typedef struct  tagIVFD_Target
{
	unsigned int type;
	IVFD_Rect rect;
} IVFD_Target; 

#define STE_TARGET_MAX_NUM		8
typedef struct  tagIVFD_TargetSet
{
	unsigned int frame;
	unsigned int time;
	int num;
	IVFD_Target targets[STE_TARGET_MAX_NUM];
} IVFD_TargetSet; 

typedef struct  tagIVFD_Event
{
	unsigned int type;
	unsigned int time;
	unsigned int frame;
	unsigned int status;
} IVFD_Event; 

#define STE_EVENT_MAX_NUM		8
typedef struct  tagIVFD_EventSet
{
	int num;
	IVFD_Event events[STE_EVENT_MAX_NUM];
} IVFD_EventSet; 
//config for preset
typedef struct tagST_AlgoConfig
{
	int val_sense;	//Sensitivity	0~99,
	int val_delay;	//delay time seconds	0~99,
	int val_fov;	//field of view, 
	int val_static_det;
	int area_min;	//min area for detection;	0~99
        int val_y_level;
        int val_thrld_loss;
        int val_alarmdelay;
        int val_overexpose_ratio;
        int val_consist_ratio;
        int val_alarm_level;
        int val_aware_thrld;
        int val_static_thrld;

	char scene[STE_IMAGE_WIDTH*STE_IMAGE_HEIGH];
}ST_AlgoConfig;//wanggy add some para here

typedef struct  
{	
	int frame_index;
	int frame_num;
	int flg_used;	//��ʶ�������Ѿ����ù�һ����
	IVFD_Image image;
	IVFD_TargetSet target_set;
	IVFD_EventSet  event_set;
}STE_ImageBuf;

#ifdef __cplusplus
extern "C"	{
#endif




	//declare




#ifdef __cplusplus
	}
#endif






#endif //__STE_TYPEDEF_H__

