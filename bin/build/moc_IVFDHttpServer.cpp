/****************************************************************************
** Meta object code from reading C++ file 'IVFDHttpServer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/IVFDHttpServer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'IVFDHttpServer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_IVFDHttpServer_t {
    QByteArrayData data[10];
    char stringdata[178];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IVFDHttpServer_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IVFDHttpServer_t qt_meta_stringdata_IVFDHttpServer = {
    {
QT_MOC_LITERAL(0, 0, 14), // "IVFDHttpServer"
QT_MOC_LITERAL(1, 15, 19), // "SIG_OpenCPlayWindow"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 18), // "SIG_CmdFromBrowser"
QT_MOC_LITERAL(4, 55, 22), // "SIG_CmdAnswerFromTopUi"
QT_MOC_LITERAL(5, 78, 19), // "SIG_UpdateTimeStamp"
QT_MOC_LITERAL(6, 98, 23), // "SLOT_CreatNewHttpServer"
QT_MOC_LITERAL(7, 122, 20), // "SLOT_StartHttpServer"
QT_MOC_LITERAL(8, 143, 13), // "SLOT_PrintCmd"
QT_MOC_LITERAL(9, 157, 20) // "SLOT_UpdateTimeStamp"

    },
    "IVFDHttpServer\0SIG_OpenCPlayWindow\0\0"
    "SIG_CmdFromBrowser\0SIG_CmdAnswerFromTopUi\0"
    "SIG_UpdateTimeStamp\0SLOT_CreatNewHttpServer\0"
    "SLOT_StartHttpServer\0SLOT_PrintCmd\0"
    "SLOT_UpdateTimeStamp"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IVFDHttpServer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    2,   55,    2, 0x06 /* Public */,
       4,    1,   60,    2, 0x06 /* Public */,
       5,    1,   63,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   66,    2, 0x0a /* Public */,
       7,    0,   67,    2, 0x0a /* Public */,
       8,    2,   68,    2, 0x0a /* Public */,
       9,    1,   73,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::LongLong,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::LongLong,    2,

       0        // eod
};

void IVFDHttpServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IVFDHttpServer *_t = static_cast<IVFDHttpServer *>(_o);
        switch (_id) {
        case 0: _t->SIG_OpenCPlayWindow(); break;
        case 1: _t->SIG_CmdFromBrowser((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->SIG_CmdAnswerFromTopUi((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: _t->SIG_UpdateTimeStamp((*reinterpret_cast< qlonglong(*)>(_a[1]))); break;
        case 4: _t->SLOT_CreatNewHttpServer(); break;
        case 5: _t->SLOT_StartHttpServer(); break;
        case 6: _t->SLOT_PrintCmd((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 7: _t->SLOT_UpdateTimeStamp((*reinterpret_cast< qlonglong(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (IVFDHttpServer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDHttpServer::SIG_OpenCPlayWindow)) {
                *result = 0;
            }
        }
        {
            typedef void (IVFDHttpServer::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDHttpServer::SIG_CmdFromBrowser)) {
                *result = 1;
            }
        }
        {
            typedef void (IVFDHttpServer::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDHttpServer::SIG_CmdAnswerFromTopUi)) {
                *result = 2;
            }
        }
        {
            typedef void (IVFDHttpServer::*_t)(qlonglong );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDHttpServer::SIG_UpdateTimeStamp)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject IVFDHttpServer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_IVFDHttpServer.data,
      qt_meta_data_IVFDHttpServer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *IVFDHttpServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IVFDHttpServer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_IVFDHttpServer.stringdata))
        return static_cast<void*>(const_cast< IVFDHttpServer*>(this));
    return QObject::qt_metacast(_clname);
}

int IVFDHttpServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void IVFDHttpServer::SIG_OpenCPlayWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void IVFDHttpServer::SIG_CmdFromBrowser(QString _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void IVFDHttpServer::SIG_CmdAnswerFromTopUi(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void IVFDHttpServer::SIG_UpdateTimeStamp(qlonglong _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
