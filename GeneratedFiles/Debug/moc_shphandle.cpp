/****************************************************************************
** Meta object code from reading C++ file 'shphandle.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../shphandle.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'shphandle.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ShpHandle_t {
    QByteArrayData data[7];
    char stringdata0[67];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ShpHandle_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ShpHandle_t qt_meta_stringdata_ShpHandle = {
    {
QT_MOC_LITERAL(0, 0, 9), // "ShpHandle"
QT_MOC_LITERAL(1, 10, 11), // "operateOver"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 14), // "isOpenDataBase"
QT_MOC_LITERAL(4, 38, 11), // "transformed"
QT_MOC_LITERAL(5, 50, 6), // "doWork"
QT_MOC_LITERAL(6, 57, 9) // "openDBase"

    },
    "ShpHandle\0operateOver\0\0isOpenDataBase\0"
    "transformed\0doWork\0openDBase"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ShpHandle[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    1,   40,    2, 0x06 /* Public */,
       4,    1,   43,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   46,    2, 0x0a /* Public */,
       6,    1,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void ShpHandle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ShpHandle *_t = static_cast<ShpHandle *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->operateOver(); break;
        case 1: _t->isOpenDataBase((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->transformed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->doWork(); break;
        case 4: _t->openDBase((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ShpHandle::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ShpHandle::operateOver)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ShpHandle::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ShpHandle::isOpenDataBase)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ShpHandle::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ShpHandle::transformed)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject ShpHandle::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ShpHandle.data,
      qt_meta_data_ShpHandle,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ShpHandle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ShpHandle::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ShpHandle.stringdata0))
        return static_cast<void*>(const_cast< ShpHandle*>(this));
    return QObject::qt_metacast(_clname);
}

int ShpHandle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ShpHandle::operateOver()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void ShpHandle::isOpenDataBase(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ShpHandle::transformed(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
