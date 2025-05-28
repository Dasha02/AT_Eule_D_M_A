/****************************************************************************
** Meta object code from reading C++ file 'AProjectExplorer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/ATShell/AProjectExplorer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AProjectExplorer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AProjectExplorer_t {
    QByteArrayData data[14];
    char stringdata0[203];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AProjectExplorer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AProjectExplorer_t qt_meta_stringdata_AProjectExplorer = {
    {
QT_MOC_LITERAL(0, 0, 16), // "AProjectExplorer"
QT_MOC_LITERAL(1, 17, 22), // "createNewFileRequested"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 21), // "openDocumentRequested"
QT_MOC_LITERAL(4, 63, 13), // "ADocumentRef*"
QT_MOC_LITERAL(5, 77, 15), // "showContextMenu"
QT_MOC_LITERAL(6, 93, 3), // "pos"
QT_MOC_LITERAL(7, 97, 19), // "onRenameItemClicked"
QT_MOC_LITERAL(8, 117, 19), // "onRemoveItemClicked"
QT_MOC_LITERAL(9, 137, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(10, 154, 4), // "item"
QT_MOC_LITERAL(11, 159, 14), // "changeItemName"
QT_MOC_LITERAL(12, 174, 6), // "column"
QT_MOC_LITERAL(13, 181, 21) // "openNodeFileRequested"

    },
    "AProjectExplorer\0createNewFileRequested\0"
    "\0openDocumentRequested\0ADocumentRef*\0"
    "showContextMenu\0pos\0onRenameItemClicked\0"
    "onRemoveItemClicked\0QTreeWidgetItem*\0"
    "item\0changeItemName\0column\0"
    "openNodeFileRequested"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AProjectExplorer[] = {

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
       1,    0,   49,    2, 0x06 /* Public */,
       3,    1,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   53,    2, 0x08 /* Private */,
       7,    0,   56,    2, 0x08 /* Private */,
       8,    1,   57,    2, 0x08 /* Private */,
      11,    2,   60,    2, 0x08 /* Private */,
      13,    1,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9, QMetaType::Int,   10,   12,
    QMetaType::Void, 0x80000000 | 9,   10,

       0        // eod
};

void AProjectExplorer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AProjectExplorer *_t = static_cast<AProjectExplorer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->createNewFileRequested(); break;
        case 1: _t->openDocumentRequested((*reinterpret_cast< ADocumentRef*(*)>(_a[1]))); break;
        case 2: _t->showContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 3: _t->onRenameItemClicked(); break;
        case 4: _t->onRemoveItemClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 5: _t->changeItemName((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->openNodeFileRequested((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AProjectExplorer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AProjectExplorer::createNewFileRequested)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AProjectExplorer::*)(ADocumentRef * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AProjectExplorer::openDocumentRequested)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AProjectExplorer::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AProjectExplorer.data,
      qt_meta_data_AProjectExplorer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AProjectExplorer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AProjectExplorer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AProjectExplorer.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int AProjectExplorer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void AProjectExplorer::createNewFileRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AProjectExplorer::openDocumentRequested(ADocumentRef * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
