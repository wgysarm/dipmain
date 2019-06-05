/****************************************************************************
** Meta object code from reading C++ file 'eventhistory.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/eventhistory.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'eventhistory.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_EventListModel_t {
    QByteArrayData data[1];
    char stringdata[15];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EventListModel_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EventListModel_t qt_meta_stringdata_EventListModel = {
    {
QT_MOC_LITERAL(0, 0, 14) // "EventListModel"

    },
    "EventListModel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EventListModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void EventListModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject EventListModel::staticMetaObject = {
    { &QAbstractTableModel::staticMetaObject, qt_meta_stringdata_EventListModel.data,
      qt_meta_data_EventListModel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *EventListModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EventListModel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_EventListModel.stringdata))
        return static_cast<void*>(const_cast< EventListModel*>(this));
    return QAbstractTableModel::qt_metacast(_clname);
}

int EventListModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractTableModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_EventHistory_t {
    QByteArrayData data[9];
    char stringdata[75];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EventHistory_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EventHistory_t qt_meta_stringdata_EventHistory = {
    {
QT_MOC_LITERAL(0, 0, 12), // "EventHistory"
QT_MOC_LITERAL(1, 13, 9), // "addEvents"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 10), // "WpaMsgList"
QT_MOC_LITERAL(4, 35, 4), // "msgs"
QT_MOC_LITERAL(5, 40, 8), // "addEvent"
QT_MOC_LITERAL(6, 49, 6), // "WpaMsg"
QT_MOC_LITERAL(7, 56, 3), // "msg"
QT_MOC_LITERAL(8, 60, 14) // "languageChange"

    },
    "EventHistory\0addEvents\0\0WpaMsgList\0"
    "msgs\0addEvent\0WpaMsg\0msg\0languageChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EventHistory[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       5,    1,   32,    2, 0x0a /* Public */,
       8,    0,   35,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,

       0        // eod
};

void EventHistory::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EventHistory *_t = static_cast<EventHistory *>(_o);
        switch (_id) {
        case 0: _t->addEvents((*reinterpret_cast< WpaMsgList(*)>(_a[1]))); break;
        case 1: _t->addEvent((*reinterpret_cast< WpaMsg(*)>(_a[1]))); break;
        case 2: _t->languageChange(); break;
        default: ;
        }
    }
}

const QMetaObject EventHistory::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_EventHistory.data,
      qt_meta_data_EventHistory,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *EventHistory::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EventHistory::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_EventHistory.stringdata))
        return static_cast<void*>(const_cast< EventHistory*>(this));
    if (!strcmp(_clname, "Ui::EventHistory"))
        return static_cast< Ui::EventHistory*>(const_cast< EventHistory*>(this));
    return QDialog::qt_metacast(_clname);
}

int EventHistory::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
