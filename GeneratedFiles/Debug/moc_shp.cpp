/****************************************************************************
** Meta object code from reading C++ file 'shp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../shp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'shp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SHP_t {
    QByteArrayData data[12];
    char stringdata0[83];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SHP_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SHP_t qt_meta_stringdata_SHP = {
    {
QT_MOC_LITERAL(0, 0, 3), // "SHP"
QT_MOC_LITERAL(1, 4, 11), // "startToTran"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 3), // "set"
QT_MOC_LITERAL(4, 21, 8), // "fecthShp"
QT_MOC_LITERAL(5, 30, 4), // "tran"
QT_MOC_LITERAL(6, 35, 7), // "setting"
QT_MOC_LITERAL(7, 43, 4), // "open"
QT_MOC_LITERAL(8, 48, 4), // "help"
QT_MOC_LITERAL(9, 53, 8), // "jumppage"
QT_MOC_LITERAL(10, 62, 11), // "setBarValue"
QT_MOC_LITERAL(11, 74, 8) // "tranOver"

    },
    "SHP\0startToTran\0\0set\0fecthShp\0tran\0"
    "setting\0open\0help\0jumppage\0setBarValue\0"
    "tranOver"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SHP[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    1,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   68,    2, 0x0a /* Public */,
       5,    0,   69,    2, 0x0a /* Public */,
       6,    0,   70,    2, 0x0a /* Public */,
       7,    0,   71,    2, 0x0a /* Public */,
       8,    0,   72,    2, 0x0a /* Public */,
       9,    1,   73,    2, 0x0a /* Public */,
      10,    1,   76,    2, 0x0a /* Public */,
      11,    0,   79,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void SHP::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SHP *_t = static_cast<SHP *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startToTran(); break;
        case 1: _t->set((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->fecthShp(); break;
        case 3: _t->tran(); break;
        case 4: _t->setting(); break;
        case 5: _t->open(); break;
        case 6: _t->help(); break;
        case 7: _t->jumppage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setBarValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->tranOver(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SHP::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SHP::startToTran)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SHP::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SHP::set)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject SHP::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SHP.data,
      qt_meta_data_SHP,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SHP::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SHP::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SHP.stringdata0))
        return static_cast<void*>(const_cast< SHP*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int SHP::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
void SHP::startToTran()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void SHP::set(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
