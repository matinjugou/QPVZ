/****************************************************************************
** Meta object code from reading C++ file 'QGameDisplayer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QGameDisplayer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QGameDisplayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QGameDisplayer_t {
    QByteArrayData data[8];
    char stringdata0[76];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGameDisplayer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGameDisplayer_t qt_meta_stringdata_QGameDisplayer = {
    {
QT_MOC_LITERAL(0, 0, 14), // "QGameDisplayer"
QT_MOC_LITERAL(1, 15, 8), // "setScene"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 15), // "QGraphicsScene*"
QT_MOC_LITERAL(4, 41, 5), // "scene"
QT_MOC_LITERAL(5, 47, 7), // "addItem"
QT_MOC_LITERAL(6, 55, 11), // "objectNames"
QT_MOC_LITERAL(7, 67, 8) // "Position"

    },
    "QGameDisplayer\0setScene\0\0QGraphicsScene*\0"
    "scene\0addItem\0objectNames\0Position"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGameDisplayer[] = {

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
       1,    1,   24,    2, 0x0a /* Public */,
       5,    2,   27,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 7,    2,    2,

       0        // eod
};

void QGameDisplayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QGameDisplayer *_t = static_cast<QGameDisplayer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setScene((*reinterpret_cast< QGraphicsScene*(*)>(_a[1]))); break;
        case 1: _t->addItem((*reinterpret_cast< objectNames(*)>(_a[1])),(*reinterpret_cast< Position(*)>(_a[2]))); break;
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
        }
    }
}

const QMetaObject QGameDisplayer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QGameDisplayer.data,
      qt_meta_data_QGameDisplayer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QGameDisplayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGameDisplayer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QGameDisplayer.stringdata0))
        return static_cast<void*>(const_cast< QGameDisplayer*>(this));
    return QObject::qt_metacast(_clname);
}

int QGameDisplayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
