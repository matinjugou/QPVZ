/****************************************************************************
** Meta object code from reading C++ file 'QZombies.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QZombies.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QZombies.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QZombies_t {
    QByteArrayData data[2];
    char stringdata0[13];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QZombies_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QZombies_t qt_meta_stringdata_QZombies = {
    {
QT_MOC_LITERAL(0, 0, 8), // "QZombies"
QT_MOC_LITERAL(1, 9, 3) // "pos"

    },
    "QZombies\0pos"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QZombies[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       1,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QPointF, 0x00095103,

       0        // eod
};

void QZombies::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        QZombies *_t = static_cast<QZombies *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QPointF*>(_v) = _t->pos(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QZombies *_t = static_cast<QZombies *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setPos(*reinterpret_cast< QPointF*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject QZombies::staticMetaObject = {
    { &QMyObject::staticMetaObject, qt_meta_stringdata_QZombies.data,
      qt_meta_data_QZombies,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QZombies::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QZombies::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QZombies.stringdata0))
        return static_cast<void*>(const_cast< QZombies*>(this));
    return QMyObject::qt_metacast(_clname);
}

int QZombies::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMyObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
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
struct qt_meta_stringdata_QPoleVaultingZombie_t {
    QByteArrayData data[4];
    char stringdata0[42];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QPoleVaultingZombie_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QPoleVaultingZombie_t qt_meta_stringdata_QPoleVaultingZombie = {
    {
QT_MOC_LITERAL(0, 0, 19), // "QPoleVaultingZombie"
QT_MOC_LITERAL(1, 20, 9), // "ChangeGif"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 10) // "ChangeGif2"

    },
    "QPoleVaultingZombie\0ChangeGif\0\0"
    "ChangeGif2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QPoleVaultingZombie[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x0a /* Public */,
       3,    0,   25,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QPoleVaultingZombie::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QPoleVaultingZombie *_t = static_cast<QPoleVaultingZombie *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ChangeGif(); break;
        case 1: _t->ChangeGif2(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject QPoleVaultingZombie::staticMetaObject = {
    { &QZombies::staticMetaObject, qt_meta_stringdata_QPoleVaultingZombie.data,
      qt_meta_data_QPoleVaultingZombie,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QPoleVaultingZombie::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QPoleVaultingZombie::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QPoleVaultingZombie.stringdata0))
        return static_cast<void*>(const_cast< QPoleVaultingZombie*>(this));
    return QZombies::qt_metacast(_clname);
}

int QPoleVaultingZombie::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QZombies::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
