/****************************************************************************
** Meta object code from reading C++ file 'QCardBanks.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QCardBanks.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QCardBanks.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QCardBank_t {
    QByteArrayData data[11];
    char stringdata0[139];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QCardBank_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QCardBank_t qt_meta_stringdata_QCardBank = {
    {
QT_MOC_LITERAL(0, 0, 9), // "QCardBank"
QT_MOC_LITERAL(1, 10, 12), // "moveAccepted"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 8), // "QMyCard*"
QT_MOC_LITERAL(4, 33, 12), // "ReadytoPlant"
QT_MOC_LITERAL(5, 46, 11), // "objectNames"
QT_MOC_LITERAL(6, 58, 16), // "plantRequestDone"
QT_MOC_LITERAL(7, 75, 13), // "moveRequested"
QT_MOC_LITERAL(8, 89, 13), // "removeConfirm"
QT_MOC_LITERAL(9, 103, 20), // "ReadytoPlantFromCard"
QT_MOC_LITERAL(10, 124, 14) // "Initconnection"

    },
    "QCardBank\0moveAccepted\0\0QMyCard*\0"
    "ReadytoPlant\0objectNames\0plantRequestDone\0"
    "moveRequested\0removeConfirm\0"
    "ReadytoPlantFromCard\0Initconnection"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QCardBank[] = {

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
       1,    2,   49,    2, 0x06 /* Public */,
       4,    2,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   59,    2, 0x0a /* Public */,
       7,    1,   60,    2, 0x0a /* Public */,
       8,    1,   63,    2, 0x0a /* Public */,
       9,    3,   66,    2, 0x0a /* Public */,
      10,    0,   73,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPointF, 0x80000000 | 3,    2,    2,
    QMetaType::Void, 0x80000000 | 5, QMetaType::QPointF,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5, QMetaType::QPointF, 0x80000000 | 3,    2,    2,    2,
    QMetaType::Void,

       0        // eod
};

void QCardBank::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QCardBank *_t = static_cast<QCardBank *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->moveAccepted((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< QMyCard*(*)>(_a[2]))); break;
        case 1: _t->ReadytoPlant((*reinterpret_cast< objectNames(*)>(_a[1])),(*reinterpret_cast< QPointF(*)>(_a[2]))); break;
        case 2: _t->plantRequestDone(); break;
        case 3: _t->moveRequested((*reinterpret_cast< QMyCard*(*)>(_a[1]))); break;
        case 4: _t->removeConfirm((*reinterpret_cast< QMyCard*(*)>(_a[1]))); break;
        case 5: _t->ReadytoPlantFromCard((*reinterpret_cast< objectNames(*)>(_a[1])),(*reinterpret_cast< QPointF(*)>(_a[2])),(*reinterpret_cast< QMyCard*(*)>(_a[3]))); break;
        case 6: _t->Initconnection(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QCardBank::*_t)(QPointF , QMyCard * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QCardBank::moveAccepted)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QCardBank::*_t)(objectNames , QPointF );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QCardBank::ReadytoPlant)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject QCardBank::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QCardBank.data,
      qt_meta_data_QCardBank,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QCardBank::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QCardBank::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QCardBank.stringdata0))
        return static_cast<void*>(const_cast< QCardBank*>(this));
    if (!strcmp(_clname, "QGraphicsItemGroup"))
        return static_cast< QGraphicsItemGroup*>(const_cast< QCardBank*>(this));
    return QObject::qt_metacast(_clname);
}

int QCardBank::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void QCardBank::moveAccepted(QPointF _t1, QMyCard * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QCardBank::ReadytoPlant(objectNames _t1, QPointF _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
