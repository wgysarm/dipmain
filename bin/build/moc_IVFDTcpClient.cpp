/****************************************************************************
** Meta object code from reading C++ file 'IVFDTcpClient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/IVFDTcpClient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'IVFDTcpClient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_IVFDTcpClient_t {
    QByteArrayData data[22];
    char stringdata[326];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IVFDTcpClient_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IVFDTcpClient_t qt_meta_stringdata_IVFDTcpClient = {
    {
QT_MOC_LITERAL(0, 0, 13), // "IVFDTcpClient"
QT_MOC_LITERAL(1, 14, 17), // "SIG_ConnectToHost"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 4), // "addr"
QT_MOC_LITERAL(4, 38, 5), // "portn"
QT_MOC_LITERAL(5, 44, 15), // "SIG_ClearClient"
QT_MOC_LITERAL(6, 60, 13), // "SIG_HeartBeat"
QT_MOC_LITERAL(7, 74, 19), // "SIG_SendMsgToServer"
QT_MOC_LITERAL(8, 94, 3), // "cmd"
QT_MOC_LITERAL(9, 98, 3), // "val"
QT_MOC_LITERAL(10, 102, 20), // "SIG_StopClientThread"
QT_MOC_LITERAL(11, 123, 20), // "SIG_TcpSocketSendMsg"
QT_MOC_LITERAL(12, 144, 12), // "SLOT_ReadMsg"
QT_MOC_LITERAL(13, 157, 15), // "SLOT_NewConnect"
QT_MOC_LITERAL(14, 173, 17), // "SLOT_DisplayError"
QT_MOC_LITERAL(15, 191, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(16, 220, 16), // "SLOT_ClearClient"
QT_MOC_LITERAL(17, 237, 14), // "SLOT_HeartBeat"
QT_MOC_LITERAL(18, 252, 20), // "SLOT_SendMsgToServer"
QT_MOC_LITERAL(19, 273, 21), // "SLOT_TcpSocketSendMsg"
QT_MOC_LITERAL(20, 295, 9), // "SLOT_Test"
QT_MOC_LITERAL(21, 305, 20) // "SLOT_ClientConnected"

    },
    "IVFDTcpClient\0SIG_ConnectToHost\0\0addr\0"
    "portn\0SIG_ClearClient\0SIG_HeartBeat\0"
    "SIG_SendMsgToServer\0cmd\0val\0"
    "SIG_StopClientThread\0SIG_TcpSocketSendMsg\0"
    "SLOT_ReadMsg\0SLOT_NewConnect\0"
    "SLOT_DisplayError\0QAbstractSocket::SocketError\0"
    "SLOT_ClearClient\0SLOT_HeartBeat\0"
    "SLOT_SendMsgToServer\0SLOT_TcpSocketSendMsg\0"
    "SLOT_Test\0SLOT_ClientConnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IVFDTcpClient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   89,    2, 0x06 /* Public */,
       5,    0,   94,    2, 0x06 /* Public */,
       6,    0,   95,    2, 0x06 /* Public */,
       7,    2,   96,    2, 0x06 /* Public */,
      10,    0,  101,    2, 0x06 /* Public */,
      11,    2,  102,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,  107,    2, 0x0a /* Public */,
      13,    2,  108,    2, 0x0a /* Public */,
      14,    1,  113,    2, 0x0a /* Public */,
      16,    0,  116,    2, 0x0a /* Public */,
      17,    0,  117,    2, 0x0a /* Public */,
      18,    2,  118,    2, 0x0a /* Public */,
      19,    2,  123,    2, 0x0a /* Public */,
      20,    0,  128,    2, 0x0a /* Public */,
      21,    0,  129,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::UShort,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::QByteArray,    8,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::QByteArray,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::UShort,    3,    4,
    QMetaType::Void, 0x80000000 | 15,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::QByteArray,    8,    9,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::QByteArray,    2,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void IVFDTcpClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IVFDTcpClient *_t = static_cast<IVFDTcpClient *>(_o);
        switch (_id) {
        case 0: _t->SIG_ConnectToHost((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2]))); break;
        case 1: _t->SIG_ClearClient(); break;
        case 2: _t->SIG_HeartBeat(); break;
        case 3: _t->SIG_SendMsgToServer((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 4: _t->SIG_StopClientThread(); break;
        case 5: _t->SIG_TcpSocketSendMsg((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 6: _t->SLOT_ReadMsg(); break;
        case 7: _t->SLOT_NewConnect((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2]))); break;
        case 8: _t->SLOT_DisplayError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 9: _t->SLOT_ClearClient(); break;
        case 10: _t->SLOT_HeartBeat(); break;
        case 11: _t->SLOT_SendMsgToServer((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 12: _t->SLOT_TcpSocketSendMsg((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 13: _t->SLOT_Test(); break;
        case 14: _t->SLOT_ClientConnected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (IVFDTcpClient::*_t)(QString , quint16 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDTcpClient::SIG_ConnectToHost)) {
                *result = 0;
            }
        }
        {
            typedef void (IVFDTcpClient::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDTcpClient::SIG_ClearClient)) {
                *result = 1;
            }
        }
        {
            typedef void (IVFDTcpClient::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDTcpClient::SIG_HeartBeat)) {
                *result = 2;
            }
        }
        {
            typedef void (IVFDTcpClient::*_t)(QByteArray , QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDTcpClient::SIG_SendMsgToServer)) {
                *result = 3;
            }
        }
        {
            typedef void (IVFDTcpClient::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDTcpClient::SIG_StopClientThread)) {
                *result = 4;
            }
        }
        {
            typedef void (IVFDTcpClient::*_t)(QByteArray , QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDTcpClient::SIG_TcpSocketSendMsg)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject IVFDTcpClient::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_IVFDTcpClient.data,
      qt_meta_data_IVFDTcpClient,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *IVFDTcpClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IVFDTcpClient::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_IVFDTcpClient.stringdata))
        return static_cast<void*>(const_cast< IVFDTcpClient*>(this));
    return QObject::qt_metacast(_clname);
}

int IVFDTcpClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void IVFDTcpClient::SIG_ConnectToHost(QString _t1, quint16 _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void IVFDTcpClient::SIG_ClearClient()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void IVFDTcpClient::SIG_HeartBeat()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void IVFDTcpClient::SIG_SendMsgToServer(QByteArray _t1, QByteArray _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void IVFDTcpClient::SIG_StopClientThread()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void IVFDTcpClient::SIG_TcpSocketSendMsg(QByteArray _t1, QByteArray _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
