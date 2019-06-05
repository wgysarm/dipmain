/****************************************************************************
** Meta object code from reading C++ file 'mplayer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/mplayer/mplayer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mplayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyPlayer_t {
    QByteArrayData data[27];
    char stringdata[369];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyPlayer_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyPlayer_t qt_meta_stringdata_MyPlayer = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MyPlayer"
QT_MOC_LITERAL(1, 9, 17), // "GetcurrentTimePos"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 3), // "pos"
QT_MOC_LITERAL(4, 32, 14), // "GetvidioLength"
QT_MOC_LITERAL(5, 47, 10), // "timeLength"
QT_MOC_LITERAL(6, 58, 16), // "changeTimeSlider"
QT_MOC_LITERAL(7, 75, 18), // "setTimeSliderRange"
QT_MOC_LITERAL(8, 94, 6), // "length"
QT_MOC_LITERAL(9, 101, 6), // "resume"
QT_MOC_LITERAL(10, 108, 4), // "stop"
QT_MOC_LITERAL(11, 113, 3), // "end"
QT_MOC_LITERAL(12, 117, 20), // "QProcess::ExitStatus"
QT_MOC_LITERAL(13, 138, 23), // "slotTimeLineSliderpress"
QT_MOC_LITERAL(14, 162, 26), // "slotTimeLineSliderreleased"
QT_MOC_LITERAL(15, 189, 16), // "slotVolumeChange"
QT_MOC_LITERAL(16, 206, 6), // "volume"
QT_MOC_LITERAL(17, 213, 14), // "slotNextButton"
QT_MOC_LITERAL(18, 228, 14), // "slotBackButton"
QT_MOC_LITERAL(19, 243, 14), // "slotOpenButton"
QT_MOC_LITERAL(20, 258, 16), // "slotVolumeButton"
QT_MOC_LITERAL(21, 275, 14), // "slotHideButton"
QT_MOC_LITERAL(22, 290, 15), // "slotCloseButton"
QT_MOC_LITERAL(23, 306, 19), // "slotNextVidioButton"
QT_MOC_LITERAL(24, 326, 19), // "slotBackVidioButton"
QT_MOC_LITERAL(25, 346, 16), // "slotmyListSIGNAL"
QT_MOC_LITERAL(26, 363, 5) // "Index"

    },
    "MyPlayer\0GetcurrentTimePos\0\0pos\0"
    "GetvidioLength\0timeLength\0changeTimeSlider\0"
    "setTimeSliderRange\0length\0resume\0stop\0"
    "end\0QProcess::ExitStatus\0"
    "slotTimeLineSliderpress\0"
    "slotTimeLineSliderreleased\0slotVolumeChange\0"
    "volume\0slotNextButton\0slotBackButton\0"
    "slotOpenButton\0slotVolumeButton\0"
    "slotHideButton\0slotCloseButton\0"
    "slotNextVidioButton\0slotBackVidioButton\0"
    "slotmyListSIGNAL\0Index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyPlayer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  109,    2, 0x06 /* Public */,
       4,    1,  112,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,  115,    2, 0x08 /* Private */,
       7,    1,  118,    2, 0x08 /* Private */,
       9,    0,  121,    2, 0x08 /* Private */,
      10,    0,  122,    2, 0x08 /* Private */,
      11,    2,  123,    2, 0x08 /* Private */,
      13,    0,  128,    2, 0x08 /* Private */,
      14,    0,  129,    2, 0x08 /* Private */,
      15,    1,  130,    2, 0x08 /* Private */,
      17,    0,  133,    2, 0x08 /* Private */,
      18,    0,  134,    2, 0x08 /* Private */,
      19,    0,  135,    2, 0x08 /* Private */,
      20,    0,  136,    2, 0x08 /* Private */,
      21,    0,  137,    2, 0x08 /* Private */,
      22,    0,  138,    2, 0x08 /* Private */,
      23,    0,  139,    2, 0x08 /* Private */,
      24,    0,  140,    2, 0x08 /* Private */,
      25,    1,  141,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 12,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   26,

       0        // eod
};

void MyPlayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyPlayer *_t = static_cast<MyPlayer *>(_o);
        switch (_id) {
        case 0: _t->GetcurrentTimePos((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->GetvidioLength((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->changeTimeSlider((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setTimeSliderRange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->resume(); break;
        case 5: _t->stop(); break;
        case 6: _t->end((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 7: _t->slotTimeLineSliderpress(); break;
        case 8: _t->slotTimeLineSliderreleased(); break;
        case 9: _t->slotVolumeChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->slotNextButton(); break;
        case 11: _t->slotBackButton(); break;
        case 12: _t->slotOpenButton(); break;
        case 13: _t->slotVolumeButton(); break;
        case 14: _t->slotHideButton(); break;
        case 15: _t->slotCloseButton(); break;
        case 16: _t->slotNextVidioButton(); break;
        case 17: _t->slotBackVidioButton(); break;
        case 18: _t->slotmyListSIGNAL((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyPlayer::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyPlayer::GetcurrentTimePos)) {
                *result = 0;
            }
        }
        {
            typedef void (MyPlayer::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyPlayer::GetvidioLength)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject MyPlayer::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MyPlayer.data,
      qt_meta_data_MyPlayer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyPlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyPlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyPlayer.stringdata))
        return static_cast<void*>(const_cast< MyPlayer*>(this));
    return QWidget::qt_metacast(_clname);
}

int MyPlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void MyPlayer::GetcurrentTimePos(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyPlayer::GetvidioLength(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
