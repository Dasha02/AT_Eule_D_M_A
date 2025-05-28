/****************************************************************************
** Meta object code from reading C++ file 'KBStatementWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/editors/KBEditor/KBStatementWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'KBStatementWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_KBStatementWidget_t {
    QByteArrayData data[10];
    char stringdata0[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KBStatementWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KBStatementWidget_t qt_meta_stringdata_KBStatementWidget = {
    {
QT_MOC_LITERAL(0, 0, 17), // "KBStatementWidget"
QT_MOC_LITERAL(1, 18, 9), // "setObject"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 4), // "name"
QT_MOC_LITERAL(4, 34, 12), // "setAttribute"
QT_MOC_LITERAL(5, 47, 8), // "setValue"
QT_MOC_LITERAL(6, 56, 5), // "value"
QT_MOC_LITERAL(7, 62, 9), // "setBelief"
QT_MOC_LITERAL(8, 72, 13), // "setProbabilty"
QT_MOC_LITERAL(9, 86, 11) // "setAccuracy"

    },
    "KBStatementWidget\0setObject\0\0name\0"
    "setAttribute\0setValue\0value\0setBelief\0"
    "setProbabilty\0setAccuracy"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KBStatementWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x08 /* Private */,
       4,    1,   47,    2, 0x08 /* Private */,
       5,    1,   50,    2, 0x08 /* Private */,
       7,    1,   53,    2, 0x08 /* Private */,
       8,    1,   56,    2, 0x08 /* Private */,
       9,    1,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,

       0        // eod
};

void KBStatementWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        KBStatementWidget *_t = static_cast<KBStatementWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setObject((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->setAttribute((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->setValue((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->setBelief((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setProbabilty((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setAccuracy((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject KBStatementWidget::staticMetaObject = {
    { &KBElementWidget::staticMetaObject, qt_meta_stringdata_KBStatementWidget.data,
      qt_meta_data_KBStatementWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *KBStatementWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KBStatementWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KBStatementWidget.stringdata0))
        return static_cast<void*>(this);
    return KBElementWidget::qt_metacast(_clname);
}

int KBStatementWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = KBElementWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
