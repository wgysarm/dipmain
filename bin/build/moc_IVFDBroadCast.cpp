/****************************************************************************
** Meta object code from reading C++ file 'IVFDBroadCast.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/IVFDBroadCast.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'IVFDBroadCast.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_IVFDBroadCast_t {
    QByteArrayData data[11];
    char stringdata[201];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IVFDBroadCast_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IVFDBroadCast_t qt_meta_stringdata_IVFDBroadCast = {
    {
QT_MOC_LITERAL(0, 0, 13), // "IVFDBroadCast"
QT_MOC_LITERAL(1, 14, 17), // "Sig_SendBroadCast"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 24), // "Sig_StartBroadCastThread"
QT_MOC_LITERAL(4, 58, 23), // "Sig_StopBroadCastThread"
QT_MOC_LITERAL(5, 82, 25), // "SLOT_StartBroadCastThread"
QT_MOC_LITERAL(6, 108, 18), // "SLOT_SendBroadCast"
QT_MOC_LITERAL(7, 127, 24), // "SLOT_StopBroadCastThread"
QT_MOC_LITERAL(8, 152, 12), // "SLOT_DoTimer"
QT_MOC_LITERAL(9, 165, 17), // "SLOT_UdpConnected"
QT_MOC_LITERAL(10, 183, 17) // "SLOT_UdpReadyRead"

    },
    "IVFDBroadCast\0Sig_SendBroadCast\0\0"
    "Sig_StartBroadCastThread\0"
    "Sig_StopBroadCastThread\0"
    "SLOT_StartBroadCastThread\0SLOT_SendBroadCast\0"
    "SLOT_StopBroadCastThread\0SLOT_DoTimer\0"
    "SLOT_UdpConnected\0SLOT_UdpReadyRead"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IVFDBroadCast[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       3,    0,   62,    2, 0x06 /* Public */,
       4,    0,   63,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   64,    2, 0x0a /* Public */,
       6,    1,   65,    2, 0x0a /* Public */,
       7,    0,   68,    2, 0x0a /* Public */,
       8,    0,   69,    2, 0x0a /* Public */,
       9,    0,   70,    2, 0x0a /* Public */,
      10,    0,   71,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Int,
    QMetaType::Int, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void IVFDBroadCast::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IVFDBroadCast *_t = static_cast<IVFDBroadCast *>(_o);
        switch (_id) {
        case 0: _t->Sig_SendBroadCast((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->Sig_StartBroadCastThread(); break;
        case 2: _t->Sig_StopBroadCastThread(); break;
        case 3: { int _r = _t->SLOT_StartBroadCastThread();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 4: { int _r = _t->SLOT_SendBroadCast((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 5: _t->SLOT_StopBroadCastThread(); break;
        case 6: _t->SLOT_DoTimer(); break;
        case 7: _t->SLOT_UdpConnected(); break;
        case 8: _t->SLOT_UdpReadyRead(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (IVFDBroadCast::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDBroadCast::Sig_SendBroadCast)) {
                *result = 0;
            }
        }
        {
            typedef void (IVFDBroadCast::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDBroadCast::Sig_StartBroadCastThread)) {
                *result = 1;
            }
        }
        {
            typedef void (IVFDBroadCast::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDBroadCast::Sig_StopBroadCastThread)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject IVFDBroadCast::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_IVFDBroadCast.data,
      qt_meta_data_IVFDBroadCast,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *IVFDBroadCast::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IVFDBroadCast::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_IVFDBroadCast.stringdata))
        return static_cast<void*>(const_cast< IVFDBroadCast*>(this));
    return QObject::qt_metacast(_clname);
}

int IVFDBroadCast::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void IVFDBroadCast::Sig_SendBroadCast(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void IVFDBroadCast::Sig_StartBroadCastThread()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void IVFDBroadCast::Sig_StopBroadCastThread()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
