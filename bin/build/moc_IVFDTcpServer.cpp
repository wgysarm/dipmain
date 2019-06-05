/****************************************************************************
** Meta object code from reading C++ file 'IVFDTcpServer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/IVFDTcpServer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'IVFDTcpServer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_IVFDTcpServer_t {
    QByteArrayData data[17];
    char stringdata[319];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IVFDTcpServer_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IVFDTcpServer_t qt_meta_stringdata_IVFDTcpServer = {
    {
QT_MOC_LITERAL(0, 0, 13), // "IVFDTcpServer"
QT_MOC_LITERAL(1, 14, 24), // "SIG_StartTcpServerThread"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 23), // "SIG_StopTcpServerThread"
QT_MOC_LITERAL(4, 64, 20), // "SIG_WriteToTcpSocket"
QT_MOC_LITERAL(5, 85, 11), // "SIG_TellTop"
QT_MOC_LITERAL(6, 97, 21), // "SIG_WriteFileToSocket"
QT_MOC_LITERAL(7, 119, 8), // "fileName"
QT_MOC_LITERAL(8, 128, 25), // "SLOT_StartTcpServerThread"
QT_MOC_LITERAL(9, 154, 24), // "SLOT_StopTcpServerThread"
QT_MOC_LITERAL(10, 179, 21), // "SLOT_HasNewConnection"
QT_MOC_LITERAL(11, 201, 17), // "SLOT_ReadyReadAll"
QT_MOC_LITERAL(12, 219, 21), // "SLOT_WriteToTcpSocket"
QT_MOC_LITERAL(13, 241, 16), // "SLOT_SocketError"
QT_MOC_LITERAL(14, 258, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(15, 287, 22), // "SLOT_WriteFileToSocket"
QT_MOC_LITERAL(16, 310, 8) // "filename"

    },
    "IVFDTcpServer\0SIG_StartTcpServerThread\0"
    "\0SIG_StopTcpServerThread\0SIG_WriteToTcpSocket\0"
    "SIG_TellTop\0SIG_WriteFileToSocket\0"
    "fileName\0SLOT_StartTcpServerThread\0"
    "SLOT_StopTcpServerThread\0SLOT_HasNewConnection\0"
    "SLOT_ReadyReadAll\0SLOT_WriteToTcpSocket\0"
    "SLOT_SocketError\0QAbstractSocket::SocketError\0"
    "SLOT_WriteFileToSocket\0filename"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IVFDTcpServer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    0,   75,    2, 0x06 /* Public */,
       4,    1,   76,    2, 0x06 /* Public */,
       5,    1,   79,    2, 0x06 /* Public */,
       6,    1,   82,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   85,    2, 0x0a /* Public */,
       9,    0,   86,    2, 0x0a /* Public */,
      10,    0,   87,    2, 0x0a /* Public */,
      11,    0,   88,    2, 0x0a /* Public */,
      12,    1,   89,    2, 0x0a /* Public */,
      13,    1,   92,    2, 0x0a /* Public */,
      15,    1,   95,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::QString,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, 0x80000000 | 14,    2,
    QMetaType::Void, QMetaType::QString,   16,

       0        // eod
};

void IVFDTcpServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IVFDTcpServer *_t = static_cast<IVFDTcpServer *>(_o);
        switch (_id) {
        case 0: _t->SIG_StartTcpServerThread(); break;
        case 1: _t->SIG_StopTcpServerThread(); break;
        case 2: _t->SIG_WriteToTcpSocket((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: _t->SIG_TellTop((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 4: _t->SIG_WriteFileToSocket((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->SLOT_StartTcpServerThread(); break;
        case 6: _t->SLOT_StopTcpServerThread(); break;
        case 7: _t->SLOT_HasNewConnection(); break;
        case 8: _t->SLOT_ReadyReadAll(); break;
        case 9: _t->SLOT_WriteToTcpSocket((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 10: _t->SLOT_SocketError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 11: _t->SLOT_WriteFileToSocket((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 10:
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
            typedef void (IVFDTcpServer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDTcpServer::SIG_StartTcpServerThread)) {
                *result = 0;
            }
        }
        {
            typedef void (IVFDTcpServer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDTcpServer::SIG_StopTcpServerThread)) {
                *result = 1;
            }
        }
        {
            typedef void (IVFDTcpServer::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDTcpServer::SIG_WriteToTcpSocket)) {
                *result = 2;
            }
        }
        {
            typedef void (IVFDTcpServer::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDTcpServer::SIG_TellTop)) {
                *result = 3;
            }
        }
        {
            typedef void (IVFDTcpServer::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDTcpServer::SIG_WriteFileToSocket)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject IVFDTcpServer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_IVFDTcpServer.data,
      qt_meta_data_IVFDTcpServer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *IVFDTcpServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IVFDTcpServer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_IVFDTcpServer.stringdata))
        return static_cast<void*>(const_cast< IVFDTcpServer*>(this));
    return QObject::qt_metacast(_clname);
}

int IVFDTcpServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void IVFDTcpServer::SIG_StartTcpServerThread()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void IVFDTcpServer::SIG_StopTcpServerThread()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void IVFDTcpServer::SIG_WriteToTcpSocket(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void IVFDTcpServer::SIG_TellTop(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void IVFDTcpServer::SIG_WriteFileToSocket(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
