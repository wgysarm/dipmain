/****************************************************************************
** Meta object code from reading C++ file 'IVFDEventManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/IVFDEventManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'IVFDEventManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_IVFDEventManager_t {
    QByteArrayData data[8];
    char stringdata[122];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IVFDEventManager_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IVFDEventManager_t qt_meta_stringdata_IVFDEventManager = {
    {
QT_MOC_LITERAL(0, 0, 16), // "IVFDEventManager"
QT_MOC_LITERAL(1, 17, 14), // "SIG_ThreadQuit"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 15), // "SIG_ThreadStart"
QT_MOC_LITERAL(4, 49, 18), // "SIG_DoEventManager"
QT_MOC_LITERAL(5, 68, 16), // "SIG_SendToClient"
QT_MOC_LITERAL(6, 85, 19), // "SLOT_DoEventManager"
QT_MOC_LITERAL(7, 105, 16) // "SLOT_ThreadStart"

    },
    "IVFDEventManager\0SIG_ThreadQuit\0\0"
    "SIG_ThreadStart\0SIG_DoEventManager\0"
    "SIG_SendToClient\0SLOT_DoEventManager\0"
    "SLOT_ThreadStart"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IVFDEventManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,
       5,    2,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   52,    2, 0x0a /* Public */,
       7,    0,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::QByteArray,    2,    2,

 // slots: parameters
    QMetaType::Int,
    QMetaType::Int,

       0        // eod
};

void IVFDEventManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IVFDEventManager *_t = static_cast<IVFDEventManager *>(_o);
        switch (_id) {
        case 0: _t->SIG_ThreadQuit(); break;
        case 1: _t->SIG_ThreadStart(); break;
        case 2: _t->SIG_DoEventManager(); break;
        case 3: _t->SIG_SendToClient((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 4: { int _r = _t->SLOT_DoEventManager();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 5: { int _r = _t->SLOT_ThreadStart();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (IVFDEventManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDEventManager::SIG_ThreadQuit)) {
                *result = 0;
            }
        }
        {
            typedef void (IVFDEventManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDEventManager::SIG_ThreadStart)) {
                *result = 1;
            }
        }
        {
            typedef void (IVFDEventManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDEventManager::SIG_DoEventManager)) {
                *result = 2;
            }
        }
        {
            typedef void (IVFDEventManager::*_t)(QByteArray , QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDEventManager::SIG_SendToClient)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject IVFDEventManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_IVFDEventManager.data,
      qt_meta_data_IVFDEventManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *IVFDEventManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IVFDEventManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_IVFDEventManager.stringdata))
        return static_cast<void*>(const_cast< IVFDEventManager*>(this));
    return QObject::qt_metacast(_clname);
}

int IVFDEventManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void IVFDEventManager::SIG_ThreadQuit()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void IVFDEventManager::SIG_ThreadStart()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void IVFDEventManager::SIG_DoEventManager()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void IVFDEventManager::SIG_SendToClient(QByteArray _t1, QByteArray _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
