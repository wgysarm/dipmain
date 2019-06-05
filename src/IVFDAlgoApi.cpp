

#include "IVFDAlgoApi.h"

#include "vfd_processor_i.h"
#include <QDebug>

char _vsv_dll_path[VSV_MAX_STR_SIZE] = "/var/tmp/";//算法库用的默认路径

//config path
#define PATH_zone_vfd 		"/algocfg/par_ps1_zone_vfd.dat"
#define PATH_vana_vfd 		"/algocfg/par_ps1_vana_vfd.txt"
#define PATH_vfdet_conf		"/algocfg/par_vfdet_conf.txt"

static char parfil_ps_zone_vfd[VSV_MAX_STR_SIZE] = "/algocfg/par_ps1_zone_vfd.dat";
static char parfil_ps_vana_vfd[VSV_MAX_STR_SIZE] = "/algocfg/par_ps1_vana_vfd.txt";
static char parfil_vfdet_conf[VSV_MAX_STR_SIZE]	= "/algocfg/par_vfdet_conf.txt";


int ALGO_VFD_create(int img_w, int img_h, ST_AlgoConfig* cfg, void *handle)
{
    VSV_Handle res = NULL;
    uint32_t ver;
    MODULE_VFD* algo_handle;
    if(handle == NULL)
    {
        return 1;
    }
    algo_handle = (MODULE_VFD *)handle;
    VAMEM_SET algo_mem_req;
    char cfg_file_path[VSV_MAX_STR_SIZE];

    qDebug() << "ALGO_VFD_create ";
//    algo_handle = (MODULE_VFD*)malloc(sizeof(MODULE_VFD));


    if (img_w!= STE_IMAGE_WIDTH || img_h != STE_IMAGE_HEIGH)
    {
        printf("image size %d:%d is not supported \r\n", img_w,img_h);
    }

    printf("create algo \r\n");

    //read version
    VFD_GetVersion(algo_handle, &ver);
    printf("Algo Version: V%d.%d.%d \r\n", (ver&0x0f0000)>>16, (ver&0xf00000)>>20, (ver&0xff000000)>>24);
    //get algo mem requirement
    algo_mem_req.img_w = img_w;
    algo_mem_req.img_h = img_h;
    VFD_GetMemReq(algo_handle, &algo_mem_req);

    qDebug() << "VFD_GetMemReq";
    qDebug("alog_mem_req:mem_num=%d,%d,%d,%d\n",algo_mem_req.mem_num, algo_mem_req.mems[0].size, algo_mem_req.mems[1].size,algo_mem_req.mems[2].size);

    VAMEMS_alloc(&algo_mem_req);
    qDebug() << "VAMEMS_alloc";
    VFD_Initialize(algo_handle, &algo_mem_req);//here we really initialize the vfd
    qDebug() << "VFD_Initialize end";
    //read config files for debug
    {
        VAPARA *vapara = VAPARA_alloc( VAPARA_CLBR_BUFLEN, VAPARA_VANA_BUFLEN,
            VAPARA_ADVBUF_BUFCNT, VAPARA_ADVBUF_BUFLEN, NULL );

        VAPARA_STRARRAY fils_scene, fils_advance;
        memset(&fils_scene, 0, sizeof(VAPARA_STRARRAY) );
        memset(&fils_advance, 0, sizeof(VAPARA_STRARRAY) );

        qDebug() << "start strncpy";
        //init temp str first
        strncpy(parfil_ps_vana_vfd,PATH_vana_vfd, VSV_MAX_STR_SIZE);
        strncpy(parfil_ps_zone_vfd,PATH_zone_vfd, VSV_MAX_STR_SIZE);
        strncpy(parfil_vfdet_conf,PATH_vfdet_conf, VSV_MAX_STR_SIZE);
        qDebug() << "parfil_ps_vana_vfd is" << QString(parfil_ps_vana_vfd);
        qDebug() << "parfil_ps_zone_vfd is" << QString(parfil_ps_zone_vfd);
        qDebug() << "parfil_vfdet_conf is" << QString(parfil_vfdet_conf);

        fils_scene.strings[VPARASCNBUFNUM_CLBR] = (char *)NULL;
        fils_scene.strings[VPARASCNBUFNUM_ZONE_CLBR] = (char *)NULL;
//        strncpy(cfg_file_path, _vsv_dll_path, VSV_MAX_STR_SIZE);//no dll used here
//        strncat(cfg_file_path, parfil_ps_vana_vfd, VSV_MAX_STR_SIZE);
//        strncpy(parfil_ps_vana_vfd, cfg_file_path, VSV_MAX_STR_SIZE);
        fils_scene.strings[VPARASCNBUFNUM_VANA] = parfil_ps_vana_vfd ;

//        strncpy(cfg_file_path, _vsv_dll_path, VSV_MAX_STR_SIZE);
//        strncat(cfg_file_path, parfil_ps_zone_vfd, VSV_MAX_STR_SIZE);
//        strncpy(parfil_ps_zone_vfd, cfg_file_path, VSV_MAX_STR_SIZE);
        fils_scene.strings[VPARASCNBUFNUM_ZONE_VANA] = parfil_ps_zone_vfd;

//        strncpy(cfg_file_path, _vsv_dll_path, VSV_MAX_STR_SIZE);
//        strncat(cfg_file_path, parfil_vfdet_conf, VSV_MAX_STR_SIZE);
//        strncpy(parfil_vfdet_conf, cfg_file_path, VSV_MAX_STR_SIZE);
        fils_advance.strings[VPARAADVBUFNUM_VFD] = parfil_vfdet_conf;

        qDebug() << QString(fils_scene.strings[VPARASCNBUFNUM_VANA]);
        qDebug() << QString(fils_scene.strings[VPARASCNBUFNUM_ZONE_VANA]);
        qDebug() << QString(fils_advance.strings[VPARAADVBUFNUM_VFD]);
        qDebug() << "end strncpy";
        VFD_InitParaVAPARA(vapara, &fils_scene, &fils_advance, img_w, img_h, NULL);
        qDebug() << "VFD_InitParaVAPARA";
        VFD_ConfigParameter(algo_handle, vapara);//in this function the sense and mindetarea is changed wanggy1123
        qDebug() << "VFD_ConfigParameter---fire_alarm_level" << algo_handle->fsdet_para->para_fire.fire_alarm_level;
        qDebug() << "VFD_ConfigParameter---fire_aware_thrld" << algo_handle->fsdet_para->para_fire.fire_aware_thrld;
        qDebug() << "VFD_ConfigParameter---fire_consist_ratio" << algo_handle->fsdet_para->para_fire.fire_consist_ratio;
        qDebug() << "VFD_ConfigParameter---fire_y_levell" << algo_handle->fsdet_para->para_fire.fire_y_levell;
        qDebug() << "VFD_ConfigParameter---fire_sense" << algo_handle->fsdet_para->para_fire.fire_sense;
        qDebug() << "VFD_ConfigParameter---fire_edgelength_min" << algo_handle->fsdet_para->para_fire.fire_edgelength_min;
        qDebug() << "VFD_ConfigParameter---fire_thrld_loss" << algo_handle->fsdet_para->para_fire.fire_thrld_loss;
        qDebug() << "VFD_ConfigParameter---fire_alarmdelay" << algo_handle->fsdet_para->para_fire.fire_alarmdelay;
        qDebug() << "VFD_ConfigParameter---fire_overexpose_ratio" << algo_handle->fsdet_para->para_fire.fire_overexpose_ratio;
        qDebug() << "VFD_ConfigParameter---fire_det_type" << algo_handle->fsdet_para->para_fire.fire_det_type;
        VAPARA_free(vapara, VAPARA_ADVBUF_BUFCNT, NULL );
        qDebug() << "VAPARA_free";
//        *handle = *algo_handle;
//        memcpy(handle, algo_handle, sizeof(MODULE_VFD));

    }
//    res = algo_handle;
    return 0;
//    return NULL;
}



void ALGO_VFD_destroy(VSV_Handle handle, int img_w, int img_h)
{
//    MODULE_VFD* algo_handle;
//    VAMEM_SET algo_mem_req;

//    algo_handle = (MODULE_VFD* )handle;


//    printf("destroy algo\r\n");


//    //get algo mem requirement
//    algo_mem_req.img_w = img_w;
//    algo_mem_req.img_h = img_h;
//    VFD_GetMemReq( algo_handle, &algo_mem_req );
//    algo_mem_req.mems[0].mem = algo_handle->m_sHwRes.mem_mgr.memmgrs[0].mem_addr;
//    algo_mem_req.mems[1].mem = algo_handle->m_sHwRes.mem_mgr.memmgrs[1].mem_addr;
//    algo_mem_req.mems[2].mem = algo_handle->m_sHwRes.mem_mgr.memmgrs[0].nodes;

//    VFD_Terminate( algo_handle );
//    VAMEMS_free( &algo_mem_req );


}



void ALGO_VFD_setConfig(VSV_Handle handle, ST_AlgoConfig * cfg)
{
    MODULE_VFD* algo_handle;

    algo_handle = (MODULE_VFD* )handle;
    qDebug() << " cfg->val_sense = " << cfg->val_sense;
    algo_handle->fsdet_para->para_fire.fire_sense = cfg->val_sense;
    algo_handle->fsdet_para->para_fire.fire_edgelength_min = cfg->area_min;
//    algo_handle->fsdet_para->para_fire.fire_alarm_level = cfg->val_alarm_level;//alarm_level less,easier to alarm.
//    algo_handle->fsdet_para->para_fire.fire_aware_thrld = cfg->val_aware_thrld;
//    algo_handle->fsdet_para->para_fire.fire_consist_ratio = cfg->val_consist_ratio;
//    algo_handle->fsdet_para->para_fire.fire_overexpose_ratio = cfg->val_overexpose_ratio;
//    algo_handle->fsdet_para->para_fire.fire_static_thrld = cfg->val_static_thrld;
//    algo_handle->fsdet_para->para_fire.fire_thrld_loss = cfg->val_thrld_loss;
//    algo_handle->fsdet_para->para_fire.fire_y_levell = cfg->val_y_level;

    qDebug() << "fire_sense = " << algo_handle->fsdet_para->para_fire.fire_sense;
    qDebug() << "fire_edgelength_min = " << algo_handle->fsdet_para->para_fire.fire_edgelength_min;
    qDebug() << "fire_alarm_level = " << algo_handle->fsdet_para->para_fire.fire_alarm_level;//alarm_level less,easier to alarm.
    qDebug() << "fire_aware_thrld = " << algo_handle->fsdet_para->para_fire.fire_aware_thrld;
    qDebug() << "fire_consist_ratio = " << algo_handle->fsdet_para->para_fire.fire_consist_ratio;
    qDebug() << "fire_overexpose_ratio = " << algo_handle->fsdet_para->para_fire.fire_overexpose_ratio;
    qDebug() << "fire_static_thrld = " << algo_handle->fsdet_para->para_fire.fire_static_thrld;
    qDebug() << "fire_thrld_loss = " << algo_handle->fsdet_para->para_fire.fire_thrld_loss;
    qDebug() << "fire_y_levell = " << algo_handle->fsdet_para->para_fire.fire_y_levell;




//	int i, j;
}


int ALGO_VFD_Process( VSV_Handle hModule, IVFD_YuvImage  *pImageYUV )
{
//    qDebug() << "ALGO_VFD_Process";
    YUVIMAGE422 image;
    memset(&image, 0, sizeof(image));
    image.dataY = pImageYUV->data_y;//per new image update
    image.height = pImageYUV->height;
    image.width = pImageYUV->width;
    image.time = pImageYUV->time;//time ++ per new image
    return VFD_ProcessImage( hModule, &image );
//    return 0;
}

int ALGO_VFD_GetResults(  VSV_Handle algo_handle, VARESULT *va_result )
{
//    printf("ALGO_VFD_GetResults\n");
	return VFD_GetResults( algo_handle, va_result );
}



VSV_Handle ALGO_VSD_create(int img_w, int img_h, ST_AlgoConfig* cfg)
{
	VSV_Handle res = NULL;
	uint32_t ver;
	return res;
}



void ALGO_VSD_destroy(VSV_Handle handle, int img_w, int img_h)
{


}



void ALGO_VSD_setConfig(VSV_Handle handle, ST_AlgoConfig * cfg)
{


}


int ALGO_VSD_Process( VSV_Handle hModule, IVFD_YuvImage  *pImageYUV )
{
	return 1;
}

int ALGO_VSD_GetResults(  VSV_Handle algo_handle, VARESULT *va_result )
{
	//return VSD_GetResults( algo_handle, va_result );
	return 1;
}
