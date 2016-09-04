/****************************************************************************
** Meta object code from reading C++ file 'QMyObject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QMyObject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QMyObject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QMyObject_t {
    QByteArrayData data[15];
    char stringdata0[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QMyObject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QMyObject_t qt_meta_stringdata_QMyObject = {
    {
QT_MOC_LITERAL(0, 0, 9), // "QMyObject"
QT_MOC_LITERAL(1, 10, 8), // "addtomap"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 10), // "objectType"
QT_MOC_LITERAL(4, 31, 10), // "QMyObject*"
QT_MOC_LITERAL(5, 42, 13), // "removefrommap"
QT_MOC_LITERAL(6, 56, 6), // "moveTo"
QT_MOC_LITERAL(7, 63, 1), // "x"
QT_MOC_LITERAL(8, 65, 1), // "y"
QT_MOC_LITERAL(9, 67, 8), // "duration"
QT_MOC_LITERAL(10, 76, 18), // "QEasingCurve::Type"
QT_MOC_LITERAL(11, 95, 4), // "type"
QT_MOC_LITERAL(12, 100, 9), // "targetPos"
QT_MOC_LITERAL(13, 110, 12), // "setnewPixmap"
QT_MOC_LITERAL(14, 123, 3) // "pos"

    },
    "QMyObject\0addtomap\0\0objectType\0"
    "QMyObject*\0removefrommap\0moveTo\0x\0y\0"
    "duration\0QEasingCurve::Type\0type\0"
    "targetPos\0setnewPixmap\0pos"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QMyObject[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       1,   96, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06 /* Public */,
       5,    2,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    3,   64,    2, 0x0a /* Public */,
       6,    4,   71,    2, 0x0a /* Public */,
       6,    2,   80,    2, 0x0a /* Public */,
       6,    3,   85,    2, 0x0a /* Public */,
      13,    0,   92,    2, 0x0a /* Public */,
      13,    1,   93,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    7,    8,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, 0x80000000 | 10,    7,    8,    9,   11,
    QMetaType::Void, QMetaType::QPointF, QMetaType::Int,   12,    9,
    QMetaType::Void, QMetaType::QPointF, QMetaType::Int, 0x80000000 | 10,   12,    9,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

 // properties: name, type, flags
      14, QMetaType::QPointF, 0x00095103,

       0        // eod
};

void QMyObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QMyObject *_t = static_cast<QMyObject *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addtomap((*reinterpret_cast< objectType(*)>(_a[1])),(*reinterpret_cast< QMyObject*(*)>(_a[2]))); break;
        case 1: _t->removefrommap((*reinterpret_cast< objectType(*)>(_a[1])),(*reinterpret_cast< QMyObject*(*)>(_a[2]))); break;
        case 2: _t->moveTo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->moveTo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QEasingCurve::Type(*)>(_a[4]))); break;
        case 4: _t->moveTo((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->moveTo((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QEasingCurve::Type(*)>(_a[3]))); break;
        case 6: _t->setnewPixmap(); break;
        case 7: _t->setnewPixmap((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMyObject* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMyObject* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QMyObject::*_t)(objectType , QMyObject * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QMyObject::addtomap)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QMyObject::*_t)(objectType , QMyObject * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QMyObject::removefrommap)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        QMyObject *_t = static_cast<QMyObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QPointF*>(_v) = _t->pos(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QMyObject *_t = static_cast<QMyObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setPos(*reinterpret_cast< QPointF*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject QMyObject::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QMyObject.data,
      qt_meta_data_QMyObject,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QMyObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QMyObject::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QMyObject.stringdata0))
        return static_cast<void*>(const_cast< QMyObject*>(this));
    if (!strcmp(_clname, "QGraphicsPixmapItem"))
        return static_cast< QGraphicsPixmapItem*>(const_cast< QMyObject*>(this));
    return QObject::qt_metacast(_clname);
}

int QMyObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QMyObject::addtomap(objectType _t1, QMyObject * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QMyObject::removefrommap(objectType _t1, QMyObject * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
