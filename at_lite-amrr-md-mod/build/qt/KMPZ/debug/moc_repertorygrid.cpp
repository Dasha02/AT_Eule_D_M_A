/****************************************************************************
** Meta object code from reading C++ file 'repertorygrid.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/plugins/KMPZ/AMRR/repertorygrid.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'repertorygrid.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RepertoryGrid_t {
    QByteArrayData data[3];
    char stringdata0[35];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RepertoryGrid_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RepertoryGrid_t qt_meta_stringdata_RepertoryGrid = {
    {
QT_MOC_LITERAL(0, 0, 13), // "RepertoryGrid"
QT_MOC_LITERAL(1, 14, 19), // "on_OKButton_clicked"
QT_MOC_LITERAL(2, 34, 0) // ""

    },
    "RepertoryGrid\0on_OKButton_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RepertoryGrid[] = {

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
       1,    0,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void RepertoryGrid::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RepertoryGrid *_t = static_cast<RepertoryGrid *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_OKButton_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject RepertoryGrid::staticMetaObject = {
    { &YOSDIForm::staticMetaObject, qt_meta_stringdata_RepertoryGrid.data,
      qt_meta_data_RepertoryGrid,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RepertoryGrid::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RepertoryGrid::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RepertoryGrid.stringdata0))
        return static_cast<void*>(this);
    return YOSDIForm::qt_metacast(_clname);
}

int RepertoryGrid::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = YOSDIForm::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
