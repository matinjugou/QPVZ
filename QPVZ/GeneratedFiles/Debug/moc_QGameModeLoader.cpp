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
    QByteArrayData data[9];
    char stringdata0[98];
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
QT_MOC_LITERAL(6, 69, 8), // "Position"
QT_MOC_LITERAL(7, 78, 10), // "QMyObject*"
QT_MOC_LITERAL(8, 89, 8) // "QuitMode"

    },
    "QGameModeLoader\0exchangetoScene\0\0"
    "QGraphicsScene*\0addItem\0objectNames\0"
    "Position\0QMyObject*\0QuitMode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGameModeLoader[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    2,   37,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 6,    2,    2,
    QMetaType::Void, 0x80000000 | 7,    2,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void QGameModeLoader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QGameModeLoader *_t = static_cast<QGameModeLoader *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->exchangetoScene((*reinterpret_cast< QGraphicsScene*(*)>(_a[1]))); break;
        case 1: _t->addItem((*reinterpret_cast< objectNames(*)>(_a[1])),(*reinterpret_cast< Position(*)>(_a[2]))); break;
        case 2: _t->addItem((*reinterpret_cast< QMyObject*(*)>(_a[1]))); break;
        case 3: _t->QuitMode(); break;
        default: ;
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
            typedef void (QGameModeLoader::*_t)(objectNames , Position );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QGameModeLoader::addItem)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (QGameModeLoader::*_t)(QMyObject * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QGameModeLoader::addItem)) {
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
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
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
void QGameModeLoader::addItem(objectNames _t1, Position _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QGameModeLoader::addItem(QMyObject * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
