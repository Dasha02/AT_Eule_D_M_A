/****************************************************************************
** Meta object code from reading C++ file 'DFDGraphicsElement.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/EDFDEditor/DFDGraphicsElement.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DFDGraphicsElement.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DFDGraphicsElement_t {
    QByteArrayData data[16];
    char stringdata0[181];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DFDGraphicsElement_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DFDGraphicsElement_t qt_meta_stringdata_DFDGraphicsElement = {
    {
QT_MOC_LITERAL(0, 0, 18), // "DFDGraphicsElement"
QT_MOC_LITERAL(1, 19, 22), // "newConnectionRequested"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 19), // "DFDGraphicsElement*"
QT_MOC_LITERAL(4, 63, 3), // "src"
QT_MOC_LITERAL(5, 67, 4), // "dest"
QT_MOC_LITERAL(6, 72, 36), // "detalizationDocumentOpeningRe..."
QT_MOC_LITERAL(7, 109, 11), // "std::string"
QT_MOC_LITERAL(8, 121, 13), // "document_name"
QT_MOC_LITERAL(9, 135, 4), // "conn"
QT_MOC_LITERAL(10, 140, 6), // "connTo"
QT_MOC_LITERAL(11, 147, 4), // "reNa"
QT_MOC_LITERAL(12, 152, 7), // "addComm"
QT_MOC_LITERAL(13, 160, 5), // "setDe"
QT_MOC_LITERAL(14, 166, 5), // "delDe"
QT_MOC_LITERAL(15, 172, 8) // "changeDe"

    },
    "DFDGraphicsElement\0newConnectionRequested\0"
    "\0DFDGraphicsElement*\0src\0dest\0"
    "detalizationDocumentOpeningRequested\0"
    "std::string\0document_name\0conn\0connTo\0"
    "reNa\0addComm\0setDe\0delDe\0changeDe"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DFDGraphicsElement[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   59,    2, 0x06 /* Public */,
       6,    1,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   67,    2, 0x0a /* Public */,
      10,    0,   68,    2, 0x0a /* Public */,
      11,    0,   69,    2, 0x08 /* Private */,
      12,    0,   70,    2, 0x08 /* Private */,
      13,    0,   71,    2, 0x08 /* Private */,
      14,    0,   72,    2, 0x08 /* Private */,
      15,    0,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    QMetaType::Void, 0x80000000 | 7,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DFDGraphicsElement::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DFDGraphicsElement *_t = static_cast<DFDGraphicsElement *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newConnectionRequested((*reinterpret_cast< DFDGraphicsElement*(*)>(_a[1])),(*reinterpret_cast< DFDGraphicsElement*(*)>(_a[2]))); break;
        case 1: _t->detalizationDocumentOpeningRequested((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 2: _t->conn(); break;
        case 3: _t->connTo(); break;
        case 4: _t->reNa(); break;
        case 5: _t->addComm(); break;
        case 6: _t->setDe(); break;
        case 7: _t->delDe(); break;
        case 8: _t->changeDe(); break;
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
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DFDGraphicsElement::*)(DFDGraphicsElement * , DFDGraphicsElement * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DFDGraphicsElement::newConnectionRequested)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DFDGraphicsElement::*)(const std::string & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DFDGraphicsElement::detalizationDocumentOpeningRequested)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DFDGraphicsElement::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DFDGraphicsElement.data,
      qt_meta_data_DFDGraphicsElement,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DFDGraphicsElement::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DFDGraphicsElement::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DFDGraphicsElement.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsItemGroup"))
        return static_cast< QGraphicsItemGroup*>(this);
    return QObject::qt_metacast(_clname);
}

int DFDGraphicsElement::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void DFDGraphicsElement::newConnectionRequested(DFDGraphicsElement * _t1, DFDGraphicsElement * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DFDGraphicsElement::detalizationDocumentOpeningRequested(const std::string & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_DFDGraphicsAnchor_t {
    QByteArrayData data[1];
    char stringdata0[18];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DFDGraphicsAnchor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DFDGraphicsAnchor_t qt_meta_stringdata_DFDGraphicsAnchor = {
    {
QT_MOC_LITERAL(0, 0, 17) // "DFDGraphicsAnchor"

    },
    "DFDGraphicsAnchor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DFDGraphicsAnchor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void DFDGraphicsAnchor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject DFDGraphicsAnchor::staticMetaObject = {
    { &DFDGraphicsElement::staticMetaObject, qt_meta_stringdata_DFDGraphicsAnchor.data,
      qt_meta_data_DFDGraphicsAnchor,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DFDGraphicsAnchor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DFDGraphicsAnchor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DFDGraphicsAnchor.stringdata0))
        return static_cast<void*>(this);
    return DFDGraphicsElement::qt_metacast(_clname);
}

int DFDGraphicsAnchor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DFDGraphicsElement::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
