/****************************************************************************
** Meta object code from reading C++ file 'QGameMode.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QGameMode.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QGameMode.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QGameMode_t {
    QByteArrayData data[9];
    char stringdata0[89];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGameMode_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGameMode_t qt_meta_stringdata_QGameMode = {
    {
QT_MOC_LITERAL(0, 0, 9), // "QGameMode"
QT_MOC_LITERAL(1, 10, 4), // "exit"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 15), // "exchangetoScene"
QT_MOC_LITERAL(4, 32, 15), // "QGraphicsScene*"
QT_MOC_LITERAL(5, 48, 7), // "addItem"
QT_MOC_LITERAL(6, 56, 11), // "objectNames"
QT_MOC_LITERAL(7, 68, 9), // "Itemadded"
QT_MOC_LITERAL(8, 78, 10) // "QMyObject*"

    },
    "QGameMode\0exit\0\0exchangetoScene\0"
    "QGraphicsScene*\0addItem\0objectNames\0"
    "Itemadded\0QMyObject*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGameMode[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    1,   35,    2, 0x06 /* Public */,
       5,    2,   38,    2, 0x06 /* Public */,
       7,    1,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 6, QMetaType::QPointF,    2,    2,
    QMetaType::Void, 0x80000000 | 8,    2,

       0        // eod
};

void QGameMode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QGameMode *_t = static_cast<QGameMode *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->exit(); break;
        case 1: _t->exchangetoScene((*reinterpret_cast< QGraphicsScene*(*)>(_a[1]))); break;
        case 2: _t->addItem((*reinterpret_cast< objectNames(*)>(_a[1])),(*reinterpret_cast< QPointF(*)>(_a[2]))); break;
        case 3: _t->Itemadded((*reinterpret_cast< QMyObject*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsScene* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QGameMode::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QGameMode::exit)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QGameMode::*_t)(QGraphicsScene * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QGameMode::exchangetoScene)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (QGameMode::*_t)(objectNames , QPointF );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QGameMode::addItem)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (QGameMode::*_t)(QMyObject * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QGameMode::Itemadded)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject QGameMode::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QGameMode.data,
      qt_meta_data_QGameMode,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QGameMode::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGameMode::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QGameMode.stringdata0))
        return static_cast<void*>(const_cast< QGameMode*>(this));
    if (!strcmp(_clname, "QGraphicsPixmapItem"))
        return static_cast< QGraphicsPixmapItem*>(const_cast< QGameMode*>(this));
    return QObject::qt_metacast(_clname);
}

int QGameMode::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QGameMode::exit()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void QGameMode::exchangetoScene(QGraphicsScene * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QGameMode::addItem(objectNames _t1, QPointF _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QGameMode::Itemadded(QMyObject * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
struct qt_meta_stringdata_QGameMainMode_t {
    QByteArrayData data[8];
    char stringdata0[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGameMainMode_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGameMainMode_t qt_meta_stringdata_QGameMainMode = {
    {
QT_MOC_LITERAL(0, 0, 13), // "QGameMainMode"
QT_MOC_LITERAL(1, 14, 19), // "AdventureMode_Start"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 12), // "NewGameStart"
QT_MOC_LITERAL(4, 48, 13), // "GameModeNames"
QT_MOC_LITERAL(5, 62, 10), // "Help_Start"
QT_MOC_LITERAL(6, 73, 15), // "Setting_Options"
QT_MOC_LITERAL(7, 89, 9) // "Quit_Game"

    },
    "QGameMainMode\0AdventureMode_Start\0\0"
    "NewGameStart\0GameModeNames\0Help_Start\0"
    "Setting_Options\0Quit_Game"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGameMainMode[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    1,   40,    2, 0x06 /* Public */,
       5,    0,   43,    2, 0x06 /* Public */,
       6,    0,   44,    2, 0x06 /* Public */,
       7,    0,   45,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QGameMainMode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QGameMainMode *_t = static_cast<QGameMainMode *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->AdventureMode_Start(); break;
        case 1: _t->NewGameStart((*reinterpret_cast< GameModeNames(*)>(_a[1]))); break;
        case 2: _t->Help_Start(); break;
        case 3: _t->Setting_Options(); break;
        case 4: _t->Quit_Game(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QGameMainMode::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QGameMainMode::AdventureMode_Start)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QGameMainMode::*_t)(GameModeNames );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QGameMainMode::NewGameStart)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (QGameMainMode::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QGameMainMode::Help_Start)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (QGameMainMode::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QGameMainMode::Setting_Options)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (QGameMainMode::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QGameMainMode::Quit_Game)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject QGameMainMode::staticMetaObject = {
    { &QGameMode::staticMetaObject, qt_meta_stringdata_QGameMainMode.data,
      qt_meta_data_QGameMainMode,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QGameMainMode::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGameMainMode::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QGameMainMode.stringdata0))
        return static_cast<void*>(const_cast< QGameMainMode*>(this));
    return QGameMode::qt_metacast(_clname);
}

int QGameMainMode::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGameMode::qt_metacall(_c, _id, _a);
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
void QGameMainMode::AdventureMode_Start()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void QGameMainMode::NewGameStart(GameModeNames _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QGameMainMode::Help_Start()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void QGameMainMode::Setting_Options()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void QGameMainMode::Quit_Game()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}
struct qt_meta_stringdata_QGameAdventureMode_t {
    QByteArrayData data[3];
    char stringdata0[30];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGameAdventureMode_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGameAdventureMode_t qt_meta_stringdata_QGameAdventureMode = {
    {
QT_MOC_LITERAL(0, 0, 18), // "QGameAdventureMode"
QT_MOC_LITERAL(1, 19, 9), // "GameStart"
QT_MOC_LITERAL(2, 29, 0) // ""

    },
    "QGameAdventureMode\0GameStart\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGameAdventureMode[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void QGameAdventureMode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QGameAdventureMode *_t = static_cast<QGameAdventureMode *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->GameStart(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject QGameAdventureMode::staticMetaObject = {
    { &QGameMode::staticMetaObject, qt_meta_stringdata_QGameAdventureMode.data,
      qt_meta_data_QGameAdventureMode,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QGameAdventureMode::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGameAdventureMode::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QGameAdventureMode.stringdata0))
        return static_cast<void*>(const_cast< QGameAdventureMode*>(this));
    return QGameMode::qt_metacast(_clname);
}

int QGameAdventureMode::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGameMode::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
