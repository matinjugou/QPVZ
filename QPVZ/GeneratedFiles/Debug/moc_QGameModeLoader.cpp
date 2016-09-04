/****************************************************************************
** Meta object code from reading C++ file 'QGameModeLoader.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QGameModeLoader.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QGameModeLoader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QGameModeLoader_t {
    QByteArrayData data[13];
    char stringdata0[141];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGameModeLoader_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGameModeLoader_t qt_meta_stringdata_QGameModeLoader = {
    {
QT_MOC_LITERAL(0, 0, 15), // "QGameModeLoader"
QT_MOC_LITERAL(1, 16, 15), // "exchangetoScene"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 15), // "QGraphicsScene*"
QT_MOC_LITERAL(4, 49, 7), // "addItem"
QT_MOC_LITERAL(5, 57, 11), // "objectNames"
QT_MOC_LITERAL(6, 69, 9), // "Itemadded"
QT_MOC_LITERAL(7, 79, 10), // "QMyObject*"
QT_MOC_LITERAL(8, 90, 4), // "Load"
QT_MOC_LITERAL(9, 95, 13), // "LoadAdventure"
QT_MOC_LITERAL(10, 109, 8), // "QuitMode"
QT_MOC_LITERAL(11, 118, 7), // "setView"
QT_MOC_LITERAL(12, 126, 14) // "QGraphicsView*"

    },
    "QGameModeLoader\0exchangetoScene\0\0"
    "QGraphicsScene*\0addItem\0objectNames\0"
    "Itemadded\0QMyObject*\0Load\0LoadAdventure\0"
    "QuitMode\0setView\0QGraphicsView*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGameModeLoader[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    2,   52,    2, 0x06 /* Public */,
       6,    1,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   60,    2, 0x0a /* Public */,
       9,    0,   63,    2, 0x0a /* Public */,
      10,    0,   64,    2, 0x0a /* Public */,
      11,    1,   65,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5, QMetaType::QPointF,    2,    2,
    QMetaType::Void, 0x80000000 | 7,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,    2,

       0        // eod
};

void QGameModeLoader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QGameModeLoader *_t = static_cast<QGameModeLoader *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->exchangetoScene((*reinterpret_cast< QGraphicsScene*(*)>(_a[1]))); break;
        case 1: _t->addItem((*reinterpret_cast< objectNames(*)>(_a[1])),(*reinterpret_cast< QPointF(*)>(_a[2]))); break;
        case 2: _t->Itemadded((*reinterpret_cast< QMyObject*(*)>(_a[1]))); break;
        case 3: _t->Load((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->LoadAdventure(); break;
        case 5: _t->QuitMode(); break;
        case 6: _t->setView((*reinterpret_cast< QGraphicsView*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsScene* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsView* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QGameModeLoader::*_t)(QGraphicsScene * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QGameModeLoader::exchangetoScene)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QGameModeLoader::*_t)(objectNames , QPointF );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QGameModeLoader::addItem)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (QGameModeLoader::*_t)(QMyObject * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QGameModeLoader::Itemadded)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject QGameModeLoader::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QGameModeLoader.data,
      qt_meta_data_QGameModeLoader,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QGameModeLoader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGameModeLoader::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QGameModeLoader.stringdata0))
        return static_cast<void*>(const_cast< QGameModeLoader*>(this));
    return QObject::qt_metacast(_clname);
}

int QGameModeLoader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void QGameModeLoader::exchangetoScene(QGraphicsScene * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QGameModeLoader::addItem(objectNames _t1, QPointF _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QGameModeLoader::Itemadded(QMyObject * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
