/****************************************************************************
** Meta object code from reading C++ file 'AQProjectTreeWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/ATShell/AQProjectTreeWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AQProjectTreeWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AQProjectTreeWidget_t {
    QByteArrayData data[17];
    char stringdata0[258];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AQProjectTreeWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AQProjectTreeWidget_t qt_meta_stringdata_AQProjectTreeWidget = {
    {
QT_MOC_LITERAL(0, 0, 19), // "AQProjectTreeWidget"
QT_MOC_LITERAL(1, 20, 22), // "createNewFileRequested"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 14), // "AQProjectNode*"
QT_MOC_LITERAL(4, 59, 19), // "project_parent_node"
QT_MOC_LITERAL(5, 79, 21), // "openNodeFileRequested"
QT_MOC_LITERAL(6, 101, 21), // "ADocumentProjectNode*"
QT_MOC_LITERAL(7, 123, 8), // "doc_node"
QT_MOC_LITERAL(8, 132, 15), // "showContextMenu"
QT_MOC_LITERAL(9, 148, 3), // "pos"
QT_MOC_LITERAL(10, 152, 19), // "onRenameItemClicked"
QT_MOC_LITERAL(11, 172, 21), // "onAddGroupItemClicked"
QT_MOC_LITERAL(12, 194, 19), // "onRemoveItemClicked"
QT_MOC_LITERAL(13, 214, 14), // "changeItemName"
QT_MOC_LITERAL(14, 229, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(15, 246, 4), // "item"
QT_MOC_LITERAL(16, 251, 6) // "column"

    },
    "AQProjectTreeWidget\0createNewFileRequested\0"
    "\0AQProjectNode*\0project_parent_node\0"
    "openNodeFileRequested\0ADocumentProjectNode*\0"
    "doc_node\0showContextMenu\0pos\0"
    "onRenameItemClicked\0onAddGroupItemClicked\0"
    "onRemoveItemClicked\0changeItemName\0"
    "QTreeWidgetItem*\0item\0column"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AQProjectTreeWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       5,    1,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   55,    2, 0x08 /* Private */,
      10,    0,   58,    2, 0x08 /* Private */,
      11,    0,   59,    2, 0x08 /* Private */,
      12,    0,   60,    2, 0x08 /* Private */,
      13,    2,   61,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14, QMetaType::Int,   15,   16,

       0        // eod
};

void AQProjectTreeWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AQProjectTreeWidget *_t = static_cast<AQProjectTreeWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->createNewFileRequested((*reinterpret_cast< AQProjectNode*(*)>(_a[1]))); break;
        case 1: _t->openNodeFileRequested((*reinterpret_cast< ADocumentProjectNode*(*)>(_a[1]))); break;
        case 2: _t->showContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 3: _t->onRenameItemClicked(); break;
        case 4: _t->onAddGroupItemClicked(); break;
        case 5: _t->onRemoveItemClicked(); break;
        case 6: _t->changeItemName((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AQProjectTreeWidget::*)(AQProjectNode * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AQProjectTreeWidget::createNewFileRequested)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AQProjectTreeWidget::*)(ADocumentProjectNode * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AQProjectTreeWidget::openNodeFileRequested)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AQProjectTreeWidget::staticMetaObject = {
    { &QTreeWidget::staticMetaObject, qt_meta_stringdata_AQProjectTreeWidget.data,
      qt_meta_data_AQProjectTreeWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AQProjectTreeWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AQProjectTreeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AQProjectTreeWidget.stringdata0))
        return static_cast<void*>(this);
    return QTreeWidget::qt_metacast(_clname);
}

int AQProjectTreeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void AQProjectTreeWidget::createNewFileRequested(AQProjectNode * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AQProjectTreeWidget::openNodeFileRequested(ADocumentProjectNode * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
