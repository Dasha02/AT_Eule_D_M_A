/****************************************************************************
** Meta object code from reading C++ file 'can_make_conclusion_form.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/plugins/KMPZ/forms/diagnostics/can_make_conclusion_form.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'can_make_conclusion_form.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CanMakeConclusionForm_t {
    QByteArrayData data[5];
    char stringdata0[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CanMakeConclusionForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CanMakeConclusionForm_t qt_meta_stringdata_CanMakeConclusionForm = {
    {
QT_MOC_LITERAL(0, 0, 21), // "CanMakeConclusionForm"
QT_MOC_LITERAL(1, 22, 20), // "on_yesButton_clicked"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 19), // "on_noButton_clicked"
QT_MOC_LITERAL(4, 64, 26) // "on_visualiseButton_clicked"

    },
    "CanMakeConclusionForm\0on_yesButton_clicked\0"
    "\0on_noButton_clicked\0on_visualiseButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CanMakeConclusionForm[] = {

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
       1,    0,   29,    2, 0x08 /* Private */,
       3,    0,   30,    2, 0x08 /* Private */,
       4,    0,   31,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CanMakeConclusionForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CanMakeConclusionForm *_t = static_cast<CanMakeConclusionForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_yesButton_clicked(); break;
        case 1: _t->on_noButton_clicked(); break;
        case 2: _t->on_visualiseButton_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject CanMakeConclusionForm::staticMetaObject = {
    { &YOSDIForm::staticMetaObject, qt_meta_stringdata_CanMakeConclusionForm.data,
      qt_meta_data_CanMakeConclusionForm,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CanMakeConclusionForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CanMakeConclusionForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CanMakeConclusionForm.stringdata0))
        return static_cast<void*>(this);
    return YOSDIForm::qt_metacast(_clname);
}

int CanMakeConclusionForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
