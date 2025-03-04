/****************************************************************************
** Meta object code from reading C++ file 'JumperXY.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Portes_logiques_classe/JumperXY.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'JumperXY.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_JumperXY_t {
    QByteArrayData data[9];
    char stringdata0[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_JumperXY_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_JumperXY_t qt_meta_stringdata_JumperXY = {
    {
QT_MOC_LITERAL(0, 0, 8), // "JumperXY"
QT_MOC_LITERAL(1, 9, 19), // "appel_a_horizontale"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 7), // "curseur"
QT_MOC_LITERAL(4, 38, 7), // "origine"
QT_MOC_LITERAL(5, 46, 15), // "isFunctionappel"
QT_MOC_LITERAL(6, 62, 17), // "appel_a_verticale"
QT_MOC_LITERAL(7, 80, 15), // "drawHorizontale"
QT_MOC_LITERAL(8, 96, 13) // "drawVerticale"

    },
    "JumperXY\0appel_a_horizontale\0\0curseur\0"
    "origine\0isFunctionappel\0appel_a_verticale\0"
    "drawHorizontale\0drawVerticale"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_JumperXY[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   34,    2, 0x06 /* Public */,
       6,    3,   41,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    3,   48,    2, 0x08 /* Private */,
       8,    3,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPointF, QMetaType::QPointF, QMetaType::Bool,    3,    4,    5,
    QMetaType::Void, QMetaType::QPointF, QMetaType::QPointF, QMetaType::Bool,    3,    4,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QPointF, QMetaType::QPointF, QMetaType::Bool,    3,    4,    5,
    QMetaType::Void, QMetaType::QPointF, QMetaType::QPointF, QMetaType::Bool,    3,    4,    5,

       0        // eod
};

void JumperXY::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<JumperXY *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->appel_a_horizontale((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< QPointF(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 1: _t->appel_a_verticale((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< QPointF(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 2: _t->drawHorizontale((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< QPointF(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 3: _t->drawVerticale((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< QPointF(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (JumperXY::*)(QPointF , QPointF , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JumperXY::appel_a_horizontale)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (JumperXY::*)(QPointF , QPointF , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JumperXY::appel_a_verticale)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject JumperXY::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_JumperXY.data,
    qt_meta_data_JumperXY,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *JumperXY::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *JumperXY::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_JumperXY.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int JumperXY::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void JumperXY::appel_a_horizontale(QPointF _t1, QPointF _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void JumperXY::appel_a_verticale(QPointF _t1, QPointF _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
