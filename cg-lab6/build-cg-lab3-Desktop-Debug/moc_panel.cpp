/****************************************************************************
** Meta object code from reading C++ file 'panel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cg-lab6/panel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'panel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Panel_t {
    QByteArrayData data[12];
    char stringdata0[164];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Panel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Panel_t qt_meta_stringdata_Panel = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Panel"
QT_MOC_LITERAL(1, 6, 14), // "accuracyChange"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 7), // "aChange"
QT_MOC_LITERAL(4, 30, 12), // "heightChange"
QT_MOC_LITERAL(5, 43, 12), // "lengthChange"
QT_MOC_LITERAL(6, 56, 16), // "lightPowerChange"
QT_MOC_LITERAL(7, 73, 19), // "ambientFactorChange"
QT_MOC_LITERAL(8, 93, 20), // "specularFactorChange"
QT_MOC_LITERAL(9, 114, 22), // "absorptionFactorChange"
QT_MOC_LITERAL(10, 137, 13), // "buttonClicked"
QT_MOC_LITERAL(11, 151, 12) // "handleButton"

    },
    "Panel\0accuracyChange\0\0aChange\0"
    "heightChange\0lengthChange\0lightPowerChange\0"
    "ambientFactorChange\0specularFactorChange\0"
    "absorptionFactorChange\0buttonClicked\0"
    "handleButton"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Panel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       3,    1,   67,    2, 0x06 /* Public */,
       4,    1,   70,    2, 0x06 /* Public */,
       5,    1,   73,    2, 0x06 /* Public */,
       6,    1,   76,    2, 0x06 /* Public */,
       7,    1,   79,    2, 0x06 /* Public */,
       8,    1,   82,    2, 0x06 /* Public */,
       9,    1,   85,    2, 0x06 /* Public */,
      10,    0,   88,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   89,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Panel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Panel *_t = static_cast<Panel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->accuracyChange((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->aChange((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->heightChange((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->lengthChange((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->lightPowerChange((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->ambientFactorChange((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->specularFactorChange((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->absorptionFactorChange((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->buttonClicked(); break;
        case 9: _t->handleButton(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Panel::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Panel::accuracyChange)) {
                *result = 0;
            }
        }
        {
            typedef void (Panel::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Panel::aChange)) {
                *result = 1;
            }
        }
        {
            typedef void (Panel::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Panel::heightChange)) {
                *result = 2;
            }
        }
        {
            typedef void (Panel::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Panel::lengthChange)) {
                *result = 3;
            }
        }
        {
            typedef void (Panel::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Panel::lightPowerChange)) {
                *result = 4;
            }
        }
        {
            typedef void (Panel::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Panel::ambientFactorChange)) {
                *result = 5;
            }
        }
        {
            typedef void (Panel::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Panel::specularFactorChange)) {
                *result = 6;
            }
        }
        {
            typedef void (Panel::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Panel::absorptionFactorChange)) {
                *result = 7;
            }
        }
        {
            typedef void (Panel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Panel::buttonClicked)) {
                *result = 8;
            }
        }
    }
}

const QMetaObject Panel::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Panel.data,
      qt_meta_data_Panel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Panel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Panel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Panel.stringdata0))
        return static_cast<void*>(const_cast< Panel*>(this));
    return QWidget::qt_metacast(_clname);
}

int Panel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Panel::accuracyChange(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Panel::aChange(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Panel::heightChange(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Panel::lengthChange(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Panel::lightPowerChange(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Panel::ambientFactorChange(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Panel::specularFactorChange(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Panel::absorptionFactorChange(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Panel::buttonClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 8, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
