/****************************************************************************
** Meta object code from reading C++ file 'amrr_form.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/plugins/KMPZ/AMRR/amrr_form.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'amrr_form.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AMRR_form_t {
    QByteArrayData data[7];
    char stringdata0[80];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AMRR_form_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AMRR_form_t qt_meta_stringdata_AMRR_form = {
    {
QT_MOC_LITERAL(0, 0, 9), // "AMRR_form"
QT_MOC_LITERAL(1, 10, 9), // "showEvent"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 11), // "QShowEvent*"
QT_MOC_LITERAL(4, 33, 5), // "event"
QT_MOC_LITERAL(5, 39, 21), // "on_close_amrr_clicked"
QT_MOC_LITERAL(6, 61, 18) // "on_to_amrr_clicked"

    },
    "AMRR_form\0showEvent\0\0QShowEvent*\0event\0"
    "on_close_amrr_clicked\0on_to_amrr_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AMRR_form[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x08 /* Private */,
       5,    0,   32,    2, 0x08 /* Private */,
       6,    0,   33,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AMRR_form::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AMRR_form *_t = static_cast<AMRR_form *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showEvent((*reinterpret_cast< QShowEvent*(*)>(_a[1]))); break;
        case 1: _t->on_close_amrr_clicked(); break;
        case 2: _t->on_to_amrr_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AMRR_form::staticMetaObject = {
    { &YOSDIForm::staticMetaObject, qt_meta_stringdata_AMRR_form.data,
      qt_meta_data_AMRR_form,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AMRR_form::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AMRR_form::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AMRR_form.stringdata0))
        return static_cast<void*>(this);
    return YOSDIForm::qt_metacast(_clname);
}

int AMRR_form::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = YOSDIForm::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
