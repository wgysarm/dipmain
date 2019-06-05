/********************************************************************
	created:	2014/02/26
	created:	26:2:2014   17:34
	filename: 	D:\work\project\IVFD\4Development\STEvaluationVFD\STEvaluation\AlgoApi.h
	file path:	D:\work\project\IVFD\4Development\STEvaluationVFD\STEvaluation
	file base:	AlgoApi
	file ext:	h
	author:		sunnan
	
	purpose:	
*********************************************************************/

#include "STE_Typedef.h"

#include "AlgoVFD_IF.h"


typedef void* VSV_Handle;


#define  VSV_MAX_STR_SIZE 256
//extern char _vsv_dll_path[VSV_MAX_STR_SIZE];//算法库用的默认路径

extern  VSV_Handle ALGO_VSD_create(int img_w, int img_h, ST_AlgoConfig* cfg);
extern void ALGO_VSD_destroy(VSV_Handle handle, int img_w, int img_h);
extern  void ALGO_VSD_setConfig(VSV_Handle handle, ST_AlgoConfig * cfg);
extern int ALGO_VSD_Process( VSV_Handle hModule, IVFD_YuvImage  *pImageYUV );
extern int ALGO_VSD_GetResults(  VSV_Handle algo_handle, VARESULT *va_result );

extern  int ALGO_VFD_create(int img_w, int img_h, ST_AlgoConfig* cfg, void *handle);
extern void ALGO_VFD_destroy(VSV_Handle handle, int img_w, int img_h);
extern  void ALGO_VFD_setConfig(VSV_Handle handle, ST_AlgoConfig * cfg);
extern int ALGO_VFD_Process( VSV_Handle hModule, IVFD_YuvImage  *pImageYUV );
extern int ALGO_VFD_GetResults(  VSV_Handle algo_handle, VARESULT *va_result );
