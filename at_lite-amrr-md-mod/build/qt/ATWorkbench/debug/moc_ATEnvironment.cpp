/****************************************************************************
** Meta object code from reading C++ file 'ATEnvironment.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/ATShell/ATEnvironment.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ATEnvironment.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ATMdiWindow_t {
    QByteArrayData data[3];
    char stringdata0[26];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ATMdiWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ATMdiWindow_t qt_meta_stringdata_ATMdiWindow = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ATMdiWindow"
QT_MOC_LITERAL(1, 12, 12), // "editorClosed"
QT_MOC_LITERAL(2, 25, 0) // ""

    },
    "ATMdiWindow\0editorClosed\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ATMdiWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void ATMdiWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ATMdiWindow *_t = static_cast<ATMdiWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->editorClosed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ATMdiWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ATMdiWindow::editorClosed)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject ATMdiWindow::staticMetaObject = {
    { &QMdiSubWindow::staticMetaObject, qt_meta_stringdata_ATMdiWindow.data,
      qt_meta_data_ATMdiWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ATMdiWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ATMdiWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ATMdiWindow.stringdata0))
        return static_cast<void*>(this);
    return QMdiSubWindow::qt_metacast(_clname);
}

int ATMdiWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMdiSubWindow::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void ATMdiWindow::editorClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_ATEnvironment_t {
    QByteArrayData data[24];
    char stringdata0[284];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ATEnvironment_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ATEnvironment_t qt_meta_stringdata_ATEnvironment = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ATEnvironment"
QT_MOC_LITERAL(1, 14, 16), // "createNewProject"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 13), // "createNewFile"
QT_MOC_LITERAL(4, 46, 11), // "openProject"
QT_MOC_LITERAL(5, 58, 11), // "std::string"
QT_MOC_LITERAL(6, 70, 4), // "path"
QT_MOC_LITERAL(7, 75, 8), // "openFile"
QT_MOC_LITERAL(8, 84, 9), // "file_path"
QT_MOC_LITERAL(9, 94, 16), // "openNodeDocument"
QT_MOC_LITERAL(10, 111, 21), // "ADocumentProjectNode*"
QT_MOC_LITERAL(11, 133, 8), // "doc_node"
QT_MOC_LITERAL(12, 142, 12), // "openDocument"
QT_MOC_LITERAL(13, 155, 13), // "document_name"
QT_MOC_LITERAL(14, 169, 13), // "ADocumentRef*"
QT_MOC_LITERAL(15, 183, 3), // "ref"
QT_MOC_LITERAL(16, 187, 17), // "setCurrentProject"
QT_MOC_LITERAL(17, 205, 9), // "AProject*"
QT_MOC_LITERAL(18, 215, 9), // "p_project"
QT_MOC_LITERAL(19, 225, 17), // "updateWindowTitle"
QT_MOC_LITERAL(20, 243, 11), // "executeTask"
QT_MOC_LITERAL(21, 255, 10), // "APlanTask*"
QT_MOC_LITERAL(22, 266, 4), // "task"
QT_MOC_LITERAL(23, 271, 12) // "buildProject"

    },
    "ATEnvironment\0createNewProject\0\0"
    "createNewFile\0openProject\0std::string\0"
    "path\0openFile\0file_path\0openNodeDocument\0"
    "ADocumentProjectNode*\0doc_node\0"
    "openDocument\0document_name\0ADocumentRef*\0"
    "ref\0setCurrentProject\0AProject*\0"
    "p_project\0updateWindowTitle\0executeTask\0"
    "APlanTask*\0task\0buildProject"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ATEnvironment[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x0a /* Public */,
       3,    0,   80,    2, 0x0a /* Public */,
       4,    1,   81,    2, 0x0a /* Public */,
       4,    0,   84,    2, 0x0a /* Public */,
       7,    0,   85,    2, 0x0a /* Public */,
       7,    1,   86,    2, 0x0a /* Public */,
       9,    1,   89,    2, 0x0a /* Public */,
      12,    1,   92,    2, 0x0a /* Public */,
      12,    1,   95,    2, 0x0a /* Public */,
      16,    1,   98,    2, 0x0a /* Public */,
      19,    0,  101,    2, 0x0a /* Public */,
      20,    1,  102,    2, 0x0a /* Public */,
      23,    0,  105,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 5,   13,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void,

       0        // eod
};

void ATEnvironment::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ATEnvironment *_t = static_cast<ATEnvironment *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->createNewProject(); break;
        case 1: _t->createNewFile(); break;
        case 2: _t->openProject((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 3: _t->openProject(); break;
        case 4: _t->openFile(); break;
        case 5: _t->openFile((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 6: _t->openNodeDocument((*reinterpret_cast< ADocumentProjectNode*(*)>(_a[1]))); break;
        case 7: _t->openDocument((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 8: _t->openDocument((*reinterpret_cast< ADocumentRef*(*)>(_a[1]))); break;
        case 9: _t->setCurrentProject((*reinterpret_cast< AProject*(*)>(_a[1]))); break;
        case 10: _t->updateWindowTitle(); break;
        case 11: _t->executeTask((*reinterpret_cast< APlanTask*(*)>(_a[1]))); break;
        case 12: _t->buildProject(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ATEnvironment::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ATEnvironment.data,
      qt_meta_data_ATEnvironment,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ATEnvironment::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ATEnvironment::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ATEnvironment.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "AProjectManager"))
        return static_cast< AProjectManager*>(this);
    if (!strcmp(_clname, "AEditorDelegate"))
        return static_cast< AEditorDelegate*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int ATEnvironment::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
