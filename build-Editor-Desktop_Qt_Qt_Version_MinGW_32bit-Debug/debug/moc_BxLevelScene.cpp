/****************************************************************************
** Meta object code from reading C++ file 'BxLevelScene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Editor/BxLevelScene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BxLevelScene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BxLevelScene_t {
    QByteArrayData data[7];
    char stringdata[65];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BxLevelScene_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BxLevelScene_t qt_meta_stringdata_BxLevelScene = {
    {
QT_MOC_LITERAL(0, 0, 12), // "BxLevelScene"
QT_MOC_LITERAL(1, 13, 11), // "itemDeleted"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 12), // "itemInserted"
QT_MOC_LITERAL(4, 39, 14), // "cameraComplete"
QT_MOC_LITERAL(5, 54, 7), // "setMode"
QT_MOC_LITERAL(6, 62, 2) // "in"

    },
    "BxLevelScene\0itemDeleted\0\0itemInserted\0"
    "cameraComplete\0setMode\0in"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BxLevelScene[] = {

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
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,
       4,    0,   36,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   37,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,

       0        // eod
};

void BxLevelScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BxLevelScene *_t = static_cast<BxLevelScene *>(_o);
        switch (_id) {
        case 0: _t->itemDeleted(); break;
        case 1: _t->itemInserted(); break;
        case 2: _t->cameraComplete(); break;
        case 3: _t->setMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (BxLevelScene::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BxLevelScene::itemDeleted)) {
                *result = 0;
            }
        }
        {
            typedef void (BxLevelScene::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BxLevelScene::itemInserted)) {
                *result = 1;
            }
        }
        {
            typedef void (BxLevelScene::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BxLevelScene::cameraComplete)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject BxLevelScene::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_BxLevelScene.data,
      qt_meta_data_BxLevelScene,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BxLevelScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BxLevelScene::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BxLevelScene.stringdata))
        return static_cast<void*>(const_cast< BxLevelScene*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int BxLevelScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
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
void BxLevelScene::itemDeleted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void BxLevelScene::itemInserted()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void BxLevelScene::cameraComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
