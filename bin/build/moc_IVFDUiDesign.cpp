/****************************************************************************
** Meta object code from reading C++ file 'IVFDUiDesign.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/IVFDUiDesign.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'IVFDUiDesign.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_IVFDUiDesign_t {
    QByteArrayData data[68];
    char stringdata[1098];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IVFDUiDesign_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IVFDUiDesign_t qt_meta_stringdata_IVFDUiDesign = {
    {
QT_MOC_LITERAL(0, 0, 12), // "IVFDUiDesign"
QT_MOC_LITERAL(1, 13, 24), // "SIG_StartTcpServerThread"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 18), // "SIG_CmdFromBrowser"
QT_MOC_LITERAL(4, 58, 19), // "SIG_OpenCPlayWindow"
QT_MOC_LITERAL(5, 78, 23), // "SIG_RecreateCPlayWindow"
QT_MOC_LITERAL(6, 102, 15), // "SIG_StartAlgDet"
QT_MOC_LITERAL(7, 118, 5), // "algId"
QT_MOC_LITERAL(8, 124, 19), // "SIG_StartAlgFireDet"
QT_MOC_LITERAL(9, 144, 17), // "SIG_CapureYUVFile"
QT_MOC_LITERAL(10, 162, 3), // "num"
QT_MOC_LITERAL(11, 166, 18), // "SIG_StopAlgFireDet"
QT_MOC_LITERAL(12, 185, 17), // "SIG_CaptureAndDIP"
QT_MOC_LITERAL(13, 203, 31), // "SIG_StartThreadIVFDEventManager"
QT_MOC_LITERAL(14, 235, 25), // "SIG_StartIVFDEventManager"
QT_MOC_LITERAL(15, 261, 14), // "SIG_GetSysInfo"
QT_MOC_LITERAL(16, 276, 14), // "SIG_UploadFile"
QT_MOC_LITERAL(17, 291, 17), // "SIG_CurrentStatus"
QT_MOC_LITERAL(18, 309, 19), // "SIG_SyncTimeStamp_0"
QT_MOC_LITERAL(19, 329, 18), // "SIG_GetTimeStamp_0"
QT_MOC_LITERAL(20, 348, 18), // "SIG_GetTimeStamp_1"
QT_MOC_LITERAL(21, 367, 25), // "SIG_AnswerCmdToHttpServer"
QT_MOC_LITERAL(22, 393, 6), // "answer"
QT_MOC_LITERAL(23, 400, 24), // "SIG_SendTcpServerContent"
QT_MOC_LITERAL(24, 425, 7), // "content"
QT_MOC_LITERAL(25, 433, 16), // "SIG_SendToClient"
QT_MOC_LITERAL(26, 450, 19), // "SIG_UpdateTimeStamp"
QT_MOC_LITERAL(27, 470, 18), // "SIG_SetCameraParam"
QT_MOC_LITERAL(28, 489, 6), // "ctl_id"
QT_MOC_LITERAL(29, 496, 19), // "SIG_SetInitFilesVal"
QT_MOC_LITERAL(30, 516, 8), // "ECMDTYPE"
QT_MOC_LITERAL(31, 525, 6), // "EHWVAL"
QT_MOC_LITERAL(32, 532, 2), // "id"
QT_MOC_LITERAL(33, 535, 3), // "val"
QT_MOC_LITERAL(34, 539, 17), // "SIG_NoIdentityCmd"
QT_MOC_LITERAL(35, 557, 11), // "SIG_Control"
QT_MOC_LITERAL(36, 569, 22), // "SIG_SetCameraParameter"
QT_MOC_LITERAL(37, 592, 4), // "name"
QT_MOC_LITERAL(38, 597, 4), // "val1"
QT_MOC_LITERAL(39, 602, 4), // "val2"
QT_MOC_LITERAL(40, 607, 4), // "val3"
QT_MOC_LITERAL(41, 612, 14), // "SIG_SetGPIOOUT"
QT_MOC_LITERAL(42, 627, 3), // "pin"
QT_MOC_LITERAL(43, 631, 22), // "SIG_SendMsgToTcpServer"
QT_MOC_LITERAL(44, 654, 3), // "cmd"
QT_MOC_LITERAL(45, 658, 17), // "SIG_TestTcpClient"
QT_MOC_LITERAL(46, 676, 28), // "SIG_GetCmdFromLocalTcpServer"
QT_MOC_LITERAL(47, 705, 18), // "SIG_QueryAlgStatus"
QT_MOC_LITERAL(48, 724, 16), // "SIG_GetAlgStatus"
QT_MOC_LITERAL(49, 741, 22), // "SLOT_CreateCPlayWindow"
QT_MOC_LITERAL(50, 764, 24), // "SLOT_RecreateCPlayWindow"
QT_MOC_LITERAL(51, 789, 18), // "SLOT_BtnCloseClick"
QT_MOC_LITERAL(52, 808, 19), // "SLOT_CmdFromBrowser"
QT_MOC_LITERAL(53, 828, 18), // "SLOT_CurrentStatus"
QT_MOC_LITERAL(54, 847, 20), // "SLOT_SyncTimeStamp_0"
QT_MOC_LITERAL(55, 868, 27), // "SLOT_DoProcessMsgFromCPlayW"
QT_MOC_LITERAL(56, 896, 3), // "msg"
QT_MOC_LITERAL(57, 900, 20), // "SLOT_UpdateTimeStamp"
QT_MOC_LITERAL(58, 921, 19), // "SLOT_SetCameraParam"
QT_MOC_LITERAL(59, 941, 6), // "ctr_id"
QT_MOC_LITERAL(60, 948, 8), // "setvalue"
QT_MOC_LITERAL(61, 957, 20), // "SLOT_SetInitFilesVal"
QT_MOC_LITERAL(62, 978, 18), // "SLOT_NoIdentityCmd"
QT_MOC_LITERAL(63, 997, 12), // "SLOT_Control"
QT_MOC_LITERAL(64, 1010, 15), // "SLOT_SetGPIOOUT"
QT_MOC_LITERAL(65, 1026, 23), // "SLOT_SendMsgToTcpServer"
QT_MOC_LITERAL(66, 1050, 29), // "SLOT_GetCmdFromLocalTcpServer"
QT_MOC_LITERAL(67, 1080, 17) // "SLOT_GetAlgStatus"

    },
    "IVFDUiDesign\0SIG_StartTcpServerThread\0"
    "\0SIG_CmdFromBrowser\0SIG_OpenCPlayWindow\0"
    "SIG_RecreateCPlayWindow\0SIG_StartAlgDet\0"
    "algId\0SIG_StartAlgFireDet\0SIG_CapureYUVFile\0"
    "num\0SIG_StopAlgFireDet\0SIG_CaptureAndDIP\0"
    "SIG_StartThreadIVFDEventManager\0"
    "SIG_StartIVFDEventManager\0SIG_GetSysInfo\0"
    "SIG_UploadFile\0SIG_CurrentStatus\0"
    "SIG_SyncTimeStamp_0\0SIG_GetTimeStamp_0\0"
    "SIG_GetTimeStamp_1\0SIG_AnswerCmdToHttpServer\0"
    "answer\0SIG_SendTcpServerContent\0content\0"
    "SIG_SendToClient\0SIG_UpdateTimeStamp\0"
    "SIG_SetCameraParam\0ctl_id\0SIG_SetInitFilesVal\0"
    "ECMDTYPE\0EHWVAL\0id\0val\0SIG_NoIdentityCmd\0"
    "SIG_Control\0SIG_SetCameraParameter\0"
    "name\0val1\0val2\0val3\0SIG_SetGPIOOUT\0"
    "pin\0SIG_SendMsgToTcpServer\0cmd\0"
    "SIG_TestTcpClient\0SIG_GetCmdFromLocalTcpServer\0"
    "SIG_QueryAlgStatus\0SIG_GetAlgStatus\0"
    "SLOT_CreateCPlayWindow\0SLOT_RecreateCPlayWindow\0"
    "SLOT_BtnCloseClick\0SLOT_CmdFromBrowser\0"
    "SLOT_CurrentStatus\0SLOT_SyncTimeStamp_0\0"
    "SLOT_DoProcessMsgFromCPlayW\0msg\0"
    "SLOT_UpdateTimeStamp\0SLOT_SetCameraParam\0"
    "ctr_id\0setvalue\0SLOT_SetInitFilesVal\0"
    "SLOT_NoIdentityCmd\0SLOT_Control\0"
    "SLOT_SetGPIOOUT\0SLOT_SendMsgToTcpServer\0"
    "SLOT_GetCmdFromLocalTcpServer\0"
    "SLOT_GetAlgStatus"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IVFDUiDesign[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      48,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      32,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  254,    2, 0x06 /* Public */,
       3,    2,  255,    2, 0x06 /* Public */,
       4,    0,  260,    2, 0x06 /* Public */,
       5,    0,  261,    2, 0x06 /* Public */,
       6,    1,  262,    2, 0x06 /* Public */,
       8,    1,  265,    2, 0x06 /* Public */,
       9,    1,  268,    2, 0x06 /* Public */,
      11,    0,  271,    2, 0x06 /* Public */,
      12,    0,  272,    2, 0x06 /* Public */,
      13,    0,  273,    2, 0x06 /* Public */,
      14,    0,  274,    2, 0x06 /* Public */,
      15,    0,  275,    2, 0x06 /* Public */,
      16,    0,  276,    2, 0x06 /* Public */,
      17,    0,  277,    2, 0x06 /* Public */,
      18,    0,  278,    2, 0x06 /* Public */,
      19,    0,  279,    2, 0x06 /* Public */,
      20,    0,  280,    2, 0x06 /* Public */,
      21,    1,  281,    2, 0x06 /* Public */,
      23,    1,  284,    2, 0x06 /* Public */,
      25,    2,  287,    2, 0x06 /* Public */,
      26,    1,  292,    2, 0x06 /* Public */,
      27,    1,  295,    2, 0x06 /* Public */,
      29,    3,  298,    2, 0x06 /* Public */,
      34,    3,  305,    2, 0x06 /* Public */,
      35,    3,  312,    2, 0x06 /* Public */,
      36,    4,  319,    2, 0x06 /* Public */,
      41,    2,  328,    2, 0x06 /* Public */,
      43,    2,  333,    2, 0x06 /* Public */,
      45,    0,  338,    2, 0x06 /* Public */,
      46,    1,  339,    2, 0x06 /* Public */,
      47,    1,  342,    2, 0x06 /* Public */,
      48,    1,  345,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      49,    0,  348,    2, 0x0a /* Public */,
      50,    0,  349,    2, 0x0a /* Public */,
      51,    0,  350,    2, 0x0a /* Public */,
      52,    2,  351,    2, 0x0a /* Public */,
      53,    0,  356,    2, 0x0a /* Public */,
      54,    0,  357,    2, 0x0a /* Public */,
      55,    1,  358,    2, 0x0a /* Public */,
      57,    1,  361,    2, 0x0a /* Public */,
      58,    2,  364,    2, 0x0a /* Public */,
      61,    3,  369,    2, 0x0a /* Public */,
      62,    3,  376,    2, 0x0a /* Public */,
      63,    3,  383,    2, 0x0a /* Public */,
      64,    2,  390,    2, 0x0a /* Public */,
      65,    2,  395,    2, 0x0a /* Public */,
      66,    1,  400,    2, 0x0a /* Public */,
      67,    0,  403,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   22,
    QMetaType::Void, QMetaType::QByteArray,   24,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::QByteArray,    2,    2,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::Int,   28,
    QMetaType::Void, 0x80000000 | 30, 0x80000000 | 31, QMetaType::Int,    2,   32,   33,
    QMetaType::Void, 0x80000000 | 30, 0x80000000 | 31, QMetaType::Int,    2,   32,   33,
    QMetaType::Void, 0x80000000 | 30, 0x80000000 | 31, QMetaType::Int,    2,   32,   33,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   37,   38,   39,   40,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   42,   33,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::QByteArray,   44,   33,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::Int,   33,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   56,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   59,   60,
    QMetaType::Void, 0x80000000 | 30, 0x80000000 | 31, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 30, 0x80000000 | 31, QMetaType::Int,    2,   32,   33,
    QMetaType::Void, 0x80000000 | 30, 0x80000000 | 31, QMetaType::Int,    2,   32,   33,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   42,   33,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::QByteArray,   44,   33,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void,

       0        // eod
};

void IVFDUiDesign::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IVFDUiDesign *_t = static_cast<IVFDUiDesign *>(_o);
        switch (_id) {
        case 0: _t->SIG_StartTcpServerThread(); break;
        case 1: _t->SIG_CmdFromBrowser((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->SIG_OpenCPlayWindow(); break;
        case 3: _t->SIG_RecreateCPlayWindow(); break;
        case 4: _t->SIG_StartAlgDet((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->SIG_StartAlgFireDet((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->SIG_CapureYUVFile((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->SIG_StopAlgFireDet(); break;
        case 8: _t->SIG_CaptureAndDIP(); break;
        case 9: _t->SIG_StartThreadIVFDEventManager(); break;
        case 10: _t->SIG_StartIVFDEventManager(); break;
        case 11: _t->SIG_GetSysInfo(); break;
        case 12: _t->SIG_UploadFile(); break;
        case 13: _t->SIG_CurrentStatus(); break;
        case 14: _t->SIG_SyncTimeStamp_0(); break;
        case 15: _t->SIG_GetTimeStamp_0(); break;
        case 16: _t->SIG_GetTimeStamp_1(); break;
        case 17: _t->SIG_AnswerCmdToHttpServer((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 18: _t->SIG_SendTcpServerContent((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 19: _t->SIG_SendToClient((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 20: _t->SIG_UpdateTimeStamp((*reinterpret_cast< qlonglong(*)>(_a[1]))); break;
        case 21: _t->SIG_SetCameraParam((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->SIG_SetInitFilesVal((*reinterpret_cast< ECMDTYPE(*)>(_a[1])),(*reinterpret_cast< EHWVAL(*)>(_a[2])),(*reinterpret_cast< qint32(*)>(_a[3]))); break;
        case 23: _t->SIG_NoIdentityCmd((*reinterpret_cast< ECMDTYPE(*)>(_a[1])),(*reinterpret_cast< EHWVAL(*)>(_a[2])),(*reinterpret_cast< qint32(*)>(_a[3]))); break;
        case 24: _t->SIG_Control((*reinterpret_cast< ECMDTYPE(*)>(_a[1])),(*reinterpret_cast< EHWVAL(*)>(_a[2])),(*reinterpret_cast< qint32(*)>(_a[3]))); break;
        case 25: _t->SIG_SetCameraParameter((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 26: _t->SIG_SetGPIOOUT((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 27: _t->SIG_SendMsgToTcpServer((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 28: _t->SIG_TestTcpClient(); break;
        case 29: _t->SIG_GetCmdFromLocalTcpServer((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 30: _t->SIG_QueryAlgStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 31: _t->SIG_GetAlgStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: _t->SLOT_CreateCPlayWindow(); break;
        case 33: _t->SLOT_RecreateCPlayWindow(); break;
        case 34: _t->SLOT_BtnCloseClick(); break;
        case 35: _t->SLOT_CmdFromBrowser((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 36: _t->SLOT_CurrentStatus(); break;
        case 37: _t->SLOT_SyncTimeStamp_0(); break;
        case 38: _t->SLOT_DoProcessMsgFromCPlayW((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 39: _t->SLOT_UpdateTimeStamp((*reinterpret_cast< qlonglong(*)>(_a[1]))); break;
        case 40: _t->SLOT_SetCameraParam((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 41: _t->SLOT_SetInitFilesVal((*reinterpret_cast< ECMDTYPE(*)>(_a[1])),(*reinterpret_cast< EHWVAL(*)>(_a[2])),(*reinterpret_cast< qint32(*)>(_a[3]))); break;
        case 42: _t->SLOT_NoIdentityCmd((*reinterpret_cast< ECMDTYPE(*)>(_a[1])),(*reinterpret_cast< EHWVAL(*)>(_a[2])),(*reinterpret_cast< qint32(*)>(_a[3]))); break;
        case 43: _t->SLOT_Control((*reinterpret_cast< ECMDTYPE(*)>(_a[1])),(*reinterpret_cast< EHWVAL(*)>(_a[2])),(*reinterpret_cast< qint32(*)>(_a[3]))); break;
        case 44: _t->SLOT_SetGPIOOUT((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 45: _t->SLOT_SendMsgToTcpServer((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 46: _t->SLOT_GetCmdFromLocalTcpServer((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 47: _t->SLOT_GetAlgStatus(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (IVFDUiDesign::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDUiDesign::SIG_StartTcpServerThread)) {
                *result = 0;
            }
        }
        {
            typedef void (IVFDUiDesign::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDUiDesign::SIG_CmdFromBrowser)) {
                *result = 1;
            }
        }
        {
            typedef void (IVFDUiDesign::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDUiDesign::SIG_OpenCPlayWindow)) {
                *result = 2;
            }
        }
        {
            typedef void (IVFDUiDesign::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDUiDesign::SIG_RecreateCPlayWindow)) {
                *result = 3;
            }
        }
        {
            typedef void (IVFDUiDesign::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDUiDesign::SIG_StartAlgDet)) {
                *result = 4;
            }
        }
        {
            typedef void (IVFDUiDesign::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDUiDesign::SIG_StartAlgFireDet)) {
                *result = 5;
            }
        }
        {
            typedef void (IVFDUiDesign::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDUiDesign::SIG_CapureYUVFile)) {
                *result = 6;
            }
        }
        {
            typedef void (IVFDUiDesign::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDUiDesign::SIG_StopAlgFireDet)) {
                *result = 7;
            }
        }
        {
            typedef void (IVFDUiDesign::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDUiDesign::SIG_CaptureAndDIP)) {
                *result = 8;
            }
        }
        {
            typedef void (IVFDUiDesign::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDUiDesign::SIG_StartThreadIVFDEventManager)) {
                *result = 9;
            }
        }
        {
            typedef void (IVFDUiDesign::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDUiDesign::SIG_StartIVFDEventManager)) {
                *result = 10;
            }
        }
        {
            typedef void (IVFDUiDesign::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDUiDesign::SIG_GetSysInfo)) {
                *result = 11;
            }
        }
        {
            typedef void (IVFDUiDesign::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDUiDesign::SIG_UploadFile)) {
                *result = 12;
            }
        }
        {
            typedef void (IVFDUiDesign::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDUiDesign::SIG_CurrentStatus)) {
                *result = 13;
            }
        }
        {
            typedef void (IVFDUiDesign::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDUiDesign::SIG_SyncTimeStamp_0)) {
                *result = 14;
            }
        }
        {
            typedef void (IVFDUiDesign::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDUiDesign::SIG_GetTimeStamp_0)) {
                *result = 15;
            }
        }
        {
            typedef void (IVFDUiDesign::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDUiDesign::SIG_GetTimeStamp_1)) {
                *result = 16;
            }
        }
        {
            typedef void (IVFDUiDesign::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDUiDesign::SIG_AnswerCmdToHttpServer)) {
                *result = 17;
            }
        }
        {
            typedef void (IVFDUiDesign::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDUiDesign::SIG_SendTcpServerContent)) {
                *result = 18;
            }
        }
        {
            typedef void (IVFDUiDesign::*_t)(QByteArray , QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDUiDesign::SIG_SendToClient)) {
                *result = 19;
            }
        }
        {
            typedef void (IVFDUiDesign::*_t)(qlonglong );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDUiDesign::SIG_UpdateTimeStamp)) {
                *result = 20;
            }
        }
        {
            typedef void (IVFDUiDesign::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDUiDesign::SIG_SetCameraParam)) {
                *result = 21;
            }
        }
        {
            typedef void (IVFDUiDesign::*_t)(ECMDTYPE , EHWVAL , qint32 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDUiDesign::SIG_SetInitFilesVal)) {
                *result = 22;
            }
        }
        {
            typedef void (IVFDUiDesign::*_t)(ECMDTYPE , EHWVAL , qint32 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDUiDesign::SIG_NoIdentityCmd)) {
                *result = 23;
            }
        }
        {
            typedef void (IVFDUiDesign::*_t)(ECMDTYPE , EHWVAL , qint32 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDUiDesign::SIG_Control)) {
                *result = 24;
            }
        }
        {
            typedef void (IVFDUiDesign::*_t)(int , int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDUiDesign::SIG_SetCameraParameter)) {
                *result = 25;
            }
        }
        {
            typedef void (IVFDUiDesign::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDUiDesign::SIG_SetGPIOOUT)) {
                *result = 26;
            }
        }
        {
            typedef void (IVFDUiDesign::*_t)(QByteArray , QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDUiDesign::SIG_SendMsgToTcpServer)) {
                *result = 27;
            }
        }
        {
            typedef void (IVFDUiDesign::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDUiDesign::SIG_TestTcpClient)) {
                *result = 28;
            }
        }
        {
            typedef void (IVFDUiDesign::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDUiDesign::SIG_GetCmdFromLocalTcpServer)) {
                *result = 29;
            }
        }
        {
            typedef void (IVFDUiDesign::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDUiDesign::SIG_QueryAlgStatus)) {
                *result = 30;
            }
        }
        {
            typedef void (IVFDUiDesign::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDUiDesign::SIG_GetAlgStatus)) {
                *result = 31;
            }
        }
    }
}

const QMetaObject IVFDUiDesign::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_IVFDUiDesign.data,
      qt_meta_data_IVFDUiDesign,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *IVFDUiDesign::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IVFDUiDesign::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_IVFDUiDesign.stringdata))
        return static_cast<void*>(const_cast< IVFDUiDesign*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int IVFDUiDesign::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 48)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 48;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 48)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 48;
    }
    return _id;
}

// SIGNAL 0
void IVFDUiDesign::SIG_StartTcpServerThread()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void IVFDUiDesign::SIG_CmdFromBrowser(QString _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void IVFDUiDesign::SIG_OpenCPlayWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void IVFDUiDesign::SIG_RecreateCPlayWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void IVFDUiDesign::SIG_StartAlgDet(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void IVFDUiDesign::SIG_StartAlgFireDet(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void IVFDUiDesign::SIG_CapureYUVFile(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void IVFDUiDesign::SIG_StopAlgFireDet()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}

// SIGNAL 8
void IVFDUiDesign::SIG_CaptureAndDIP()
{
    QMetaObject::activate(this, &staticMetaObject, 8, Q_NULLPTR);
}

// SIGNAL 9
void IVFDUiDesign::SIG_StartThreadIVFDEventManager()
{
    QMetaObject::activate(this, &staticMetaObject, 9, Q_NULLPTR);
}

// SIGNAL 10
void IVFDUiDesign::SIG_StartIVFDEventManager()
{
    QMetaObject::activate(this, &staticMetaObject, 10, Q_NULLPTR);
}

// SIGNAL 11
void IVFDUiDesign::SIG_GetSysInfo()
{
    QMetaObject::activate(this, &staticMetaObject, 11, Q_NULLPTR);
}

// SIGNAL 12
void IVFDUiDesign::SIG_UploadFile()
{
    QMetaObject::activate(this, &staticMetaObject, 12, Q_NULLPTR);
}

// SIGNAL 13
void IVFDUiDesign::SIG_CurrentStatus()
{
    QMetaObject::activate(this, &staticMetaObject, 13, Q_NULLPTR);
}

// SIGNAL 14
void IVFDUiDesign::SIG_SyncTimeStamp_0()
{
    QMetaObject::activate(this, &staticMetaObject, 14, Q_NULLPTR);
}

// SIGNAL 15
void IVFDUiDesign::SIG_GetTimeStamp_0()
{
    QMetaObject::activate(this, &staticMetaObject, 15, Q_NULLPTR);
}

// SIGNAL 16
void IVFDUiDesign::SIG_GetTimeStamp_1()
{
    QMetaObject::activate(this, &staticMetaObject, 16, Q_NULLPTR);
}

// SIGNAL 17
void IVFDUiDesign::SIG_AnswerCmdToHttpServer(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void IVFDUiDesign::SIG_SendTcpServerContent(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void IVFDUiDesign::SIG_SendToClient(QByteArray _t1, QByteArray _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void IVFDUiDesign::SIG_UpdateTimeStamp(qlonglong _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void IVFDUiDesign::SIG_SetCameraParam(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void IVFDUiDesign::SIG_SetInitFilesVal(ECMDTYPE _t1, EHWVAL _t2, qint32 _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void IVFDUiDesign::SIG_NoIdentityCmd(ECMDTYPE _t1, EHWVAL _t2, qint32 _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 23, _a);
}

// SIGNAL 24
void IVFDUiDesign::SIG_Control(ECMDTYPE _t1, EHWVAL _t2, qint32 _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 24, _a);
}

// SIGNAL 25
void IVFDUiDesign::SIG_SetCameraParameter(int _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 25, _a);
}

// SIGNAL 26
void IVFDUiDesign::SIG_SetGPIOOUT(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 26, _a);
}

// SIGNAL 27
void IVFDUiDesign::SIG_SendMsgToTcpServer(QByteArray _t1, QByteArray _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 27, _a);
}

// SIGNAL 28
void IVFDUiDesign::SIG_TestTcpClient()
{
    QMetaObject::activate(this, &staticMetaObject, 28, Q_NULLPTR);
}

// SIGNAL 29
void IVFDUiDesign::SIG_GetCmdFromLocalTcpServer(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 29, _a);
}

// SIGNAL 30
void IVFDUiDesign::SIG_QueryAlgStatus(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 30, _a);
}

// SIGNAL 31
void IVFDUiDesign::SIG_GetAlgStatus(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 31, _a);
}
QT_END_MOC_NAMESPACE
