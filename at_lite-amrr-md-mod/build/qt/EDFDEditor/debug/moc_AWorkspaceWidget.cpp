/****************************************************************************
** Meta object code from reading C++ file 'AWorkspaceWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/EDFDEditor/AWorkspaceWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AWorkspaceWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AWorkspaceWidget_t {
    QByteArrayData data[6];
    char stringdata0[64];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AWorkspaceWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AWorkspaceWidget_t qt_meta_stringdata_AWorkspaceWidget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "AWorkspaceWidget"
QT_MOC_LITERAL(1, 17, 16), // "createConnection"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 19), // "DFDGraphicsElement*"
QT_MOC_LITERAL(4, 55, 3), // "src"
QT_MOC_LITERAL(5, 59, 4) // "dest"

    },
    "AWorkspaceWidget\0createConnection\0\0"
    "DFDGraphicsElement*\0src\0dest"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AWorkspaceWidget[] = {

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
       1,    2,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,

       0        // eod
};

void AWorkspaceWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AWorkspaceWidget *_t = static_cast<AWorkspaceWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->createConnection((*reinterpret_cast< DFDGraphicsElement*(*)>(_a[1])),(*reinterpret_cast< DFDGraphicsElement*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< DFDGraphicsElement* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AWorkspaceWidget::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_AWorkspaceWidget.data,
      qt_meta_data_AWorkspaceWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AWorkspaceWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AWorkspaceWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AWorkspaceWidget.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int AWorkspaceWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
