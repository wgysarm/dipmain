/****************************************************************************
** Meta object code from reading C++ file 'IVFDTcpClientWorker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/IVFDTcpClientWorker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'IVFDTcpClientWorker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_IVFDTcpClientWorker_t {
    QByteArrayData data[17];
    char stringdata[243];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IVFDTcpClientWorker_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IVFDTcpClientWorker_t qt_meta_stringdata_IVFDTcpClientWorker = {
    {
QT_MOC_LITERAL(0, 0, 19), // "IVFDTcpClientWorker"
QT_MOC_LITERAL(1, 20, 22), // "SIG_SendData2TcpSocket"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 4), // "data"
QT_MOC_LITERAL(4, 49, 2), // "id"
QT_MOC_LITERAL(5, 52, 23), // "SIG_DisConnectTcpSocket"
QT_MOC_LITERAL(6, 76, 10), // "SIG_Result"
QT_MOC_LITERAL(7, 87, 14), // "SIG_Disconnect"
QT_MOC_LITERAL(8, 102, 21), // "SIG_RevDataFromServer"
QT_MOC_LITERAL(9, 124, 25), // "SLOT_RevMessageFromServer"
QT_MOC_LITERAL(10, 150, 21), // "SLOT_ServerDisConnect"
QT_MOC_LITERAL(11, 172, 13), // "SLOT_SendData"
QT_MOC_LITERAL(12, 186, 15), // "SLOT_DisConnect"
QT_MOC_LITERAL(13, 202, 18), // "SLOT_ConnectServer"
QT_MOC_LITERAL(14, 221, 8), // "hostName"
QT_MOC_LITERAL(15, 230, 4), // "port"
QT_MOC_LITERAL(16, 235, 7) // "timeout"

    },
    "IVFDTcpClientWorker\0SIG_SendData2TcpSocket\0"
    "\0data\0id\0SIG_DisConnectTcpSocket\0"
    "SIG_Result\0SIG_Disconnect\0"
    "SIG_RevDataFromServer\0SLOT_RevMessageFromServer\0"
    "SLOT_ServerDisConnect\0SLOT_SendData\0"
    "SLOT_DisConnect\0SLOT_ConnectServer\0"
    "hostName\0port\0timeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IVFDTcpClientWorker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   64,    2, 0x06 /* Public */,
       5,    1,   69,    2, 0x06 /* Public */,
       6,    1,   72,    2, 0x06 /* Public */,
       7,    0,   75,    2, 0x06 /* Public */,
       8,    1,   76,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   79,    2, 0x0a /* Public */,
      10,    0,   80,    2, 0x0a /* Public */,
      11,    2,   81,    2, 0x0a /* Public */,
      12,    0,   86,    2, 0x0a /* Public */,
      13,    3,   87,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,   14,   15,   16,

       0        // eod
};

void IVFDTcpClientWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IVFDTcpClientWorker *_t = static_cast<IVFDTcpClientWorker *>(_o);
        switch (_id) {
        case 0: _t->SIG_SendData2TcpSocket((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->SIG_DisConnectTcpSocket((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->SIG_Result((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->SIG_Disconnect(); break;
        case 4: _t->SIG_RevDataFromServer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->SLOT_RevMessageFromServer(); break;
        case 6: _t->SLOT_ServerDisConnect(); break;
        case 7: _t->SLOT_SendData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->SLOT_DisConnect(); break;
        case 9: _t->SLOT_ConnectServer((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (IVFDTcpClientWorker::*_t)(QString , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDTcpClientWorker::SIG_SendData2TcpSocket)) {
                *result = 0;
            }
        }
        {
            typedef void (IVFDTcpClientWorker::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDTcpClientWorker::SIG_DisConnectTcpSocket)) {
                *result = 1;
            }
        }
        {
            typedef void (IVFDTcpClientWorker::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDTcpClientWorker::SIG_Result)) {
                *result = 2;
            }
        }
        {
            typedef void (IVFDTcpClientWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDTcpClientWorker::SIG_Disconnect)) {
                *result = 3;
            }
        }
        {
            typedef void (IVFDTcpClientWorker::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDTcpClientWorker::SIG_RevDataFromServer)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject IVFDTcpClientWorker::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_IVFDTcpClientWorker.data,
      qt_meta_data_IVFDTcpClientWorker,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *IVFDTcpClientWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IVFDTcpClientWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_IVFDTcpClientWorker.stringdata))
        return static_cast<void*>(const_cast< IVFDTcpClientWorker*>(this));
    return QObject::qt_metacast(_clname);
}

int IVFDTcpClientWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void IVFDTcpClientWorker::SIG_SendData2TcpSocket(QString _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void IVFDTcpClientWorker::SIG_DisConnectTcpSocket(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void IVFDTcpClientWorker::SIG_Result(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void IVFDTcpClientWorker::SIG_Disconnect()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void IVFDTcpClientWorker::SIG_RevDataFromServer(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
