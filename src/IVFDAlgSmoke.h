#ifndef IVFDALGSMOKE_H
#define IVFDALGSMOKE_H
#include "IVFDAlgProcessModule.h"
#include <Mutex.h>
#if defined(Q_OS_LINUX)
using namespace android;
#endif

#if defined(OPENCVYES)
//using namespace cv;
#endif


class IVFDAlgSmoke : public IVFDAlgProcessModule
{
public:
    explicit IVFDAlgSmoke(QObject *parent = 0, void *image = 0);

    void* Do_DeQue(void *queueHandle);
};

#endif // IVFDALGSMOKE_H
