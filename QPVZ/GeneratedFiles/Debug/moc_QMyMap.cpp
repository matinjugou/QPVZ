/****************************************************************************
** Meta object code from reading C++ file 'QMyMap.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QMyMap.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QMyMap.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QMyMap_t {
    QByteArrayData data[11];
    char stringdata0[135];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QMyMap_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QMyMap_t qt_meta_stringdata_QMyMap = {
    {
QT_MOC_LITERAL(0, 0, 6), // "QMyMap"
QT_MOC_LITERAL(1, 7, 11), // "RequestDone"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 7), // "addItem"
QT_MOC_LITERAL(4, 28, 11), // "objectNames"
QT_MOC_LITERAL(5, 40, 18), // "Plantrequest_Ready"
QT_MOC_LITERAL(6, 59, 19), // "Plantrequest_Update"
QT_MOC_LITERAL(7, 79, 16), // "Plantrequest_Try"
QT_MOC_LITERAL(8, 96, 17), // "Plantrequest_Done"
QT_MOC_LITERAL(9, 114, 9), // "Itemadded"
QT_MOC_LITERAL(10, 124, 10) // "QMyObject*"

    },
    "QMyMap\0RequestDone\0\0addItem\0objectNames\0"
    "Plantrequest_Ready\0Plantrequest_Update\0"
    "Plantrequest_Try\0Plantrequest_Done\0"
    "Itemadded\0QMyObject*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QMyMap[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    2,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    2,   55,    2, 0x0a /* Public */,
       6,    1,   60,    2, 0x0a /* Public */,
       7,    0,   63,    2, 0x0a /* Public */,
       8,    0,   64,    2, 0x0a /* Public */,
       9,    1,   65,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, QMetaType::QPointF,    2,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4, QMetaType::QPointF,    2,    2,
    QMetaType::Void, QMetaType::QPointF,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,    2,

       0        // eod
};

void QMyMap::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QMyMap *_t = static_cast<QMyMap *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->RequestDone(); break;
        case 1: _t->addItem((*reinterpret_cast< objectNames(*)>(_a[1])),(*reinterpret_cast< QPointF(*)>(_a[2]))); break;
        case 2: _t->Plantrequest_Ready((*reinterpret_cast< objectNames(*)>(_a[1])),(*reinterpret_cast< QPointF(*)>(_a[2]))); break;
        case 3: _t->Plantrequest_Update((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 4: _t->Plantrequest_Try(); break;
        case 5: _t->Plantrequest_Done(); break;
        case 6: _t->Itemadded((*reinterpret_cast< QMyObject*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QMyMap::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QMyMap::RequestDone)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QMyMap::*_t)(objectNames , QPointF );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QMyMap::addItem)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject QMyMap::staticMetaObject = {
    { &QMyObject::staticMetaObject, qt_meta_stringdata_QMyMap.data,
      qt_meta_data_QMyMap,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QMyMap::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QMyMap::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QMyMap.stringdata0))
        return static_cast<void*>(const_cast< QMyMap*>(this));
    return QMyObject::qt_metacast(_clname);
}

int QMyMap::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMyObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void QMyMap::RequestDone()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void QMyMap::addItem(objectNames _t1, QPointF _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE