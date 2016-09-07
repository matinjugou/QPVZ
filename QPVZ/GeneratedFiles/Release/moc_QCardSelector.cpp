/****************************************************************************
** Meta object code from reading C++ file 'QCardSelector.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QCardSelector.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QCardSelector.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QCardSelector_t {
    QByteArrayData data[9];
    char stringdata0[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QCardSelector_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QCardSelector_t qt_meta_stringdata_QCardSelector = {
    {
QT_MOC_LITERAL(0, 0, 13), // "QCardSelector"
QT_MOC_LITERAL(1, 14, 11), // "moveRequest"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 8), // "QMyCard*"
QT_MOC_LITERAL(4, 36, 12), // "removeInform"
QT_MOC_LITERAL(5, 49, 12), // "startGameNow"
QT_MOC_LITERAL(6, 62, 12), // "moveAccepted"
QT_MOC_LITERAL(7, 75, 7), // "resetIn"
QT_MOC_LITERAL(8, 83, 3) // "pos"

    },
    "QCardSelector\0moveRequest\0\0QMyCard*\0"
    "removeInform\0startGameNow\0moveAccepted\0"
    "resetIn\0pos"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QCardSelector[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       1,   54, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,
       5,    0,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    2,   46,    2, 0x0a /* Public */,
       7,    1,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QPointF, 0x80000000 | 3,    2,    2,
    QMetaType::Void, 0x80000000 | 3,    2,

 // properties: name, type, flags
       8, QMetaType::QPointF, 0x00095103,

       0        // eod
};

void QCardSelector::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QCardSelector *_t = static_cast<QCardSelector *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->moveRequest((*reinterpret_cast< QMyCard*(*)>(_a[1]))); break;
        case 1: _t->removeInform((*reinterpret_cast< QMyCard*(*)>(_a[1]))); break;
        case 2: _t->startGameNow(); break;
        case 3: _t->moveAccepted((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< QMyCard*(*)>(_a[2]))); break;
        case 4: _t->resetIn((*reinterpret_cast< QMyCard*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QCardSelector::*_t)(QMyCard * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QCardSelector::moveRequest)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QCardSelector::*_t)(QMyCard * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QCardSelector::removeInform)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (QCardSelector::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QCardSelector::startGameNow)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        QCardSelector *_t = static_cast<QCardSelector *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QPointF*>(_v) = _t->pos(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QCardSelector *_t = static_cast<QCardSelector *>(_o);
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

const QMetaObject QCardSelector::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QCardSelector.data,
      qt_meta_data_QCardSelector,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QCardSelector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QCardSelector::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QCardSelector.stringdata0))
        return static_cast<void*>(const_cast< QCardSelector*>(this));
    if (!strcmp(_clname, "QGraphicsItemGroup"))
        return static_cast< QGraphicsItemGroup*>(const_cast< QCardSelector*>(this));
    return QObject::qt_metacast(_clname);
}

int QCardSelector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void QCardSelector::moveRequest(QMyCard * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QCardSelector::removeInform(QMyCard * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QCardSelector::startGameNow()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
