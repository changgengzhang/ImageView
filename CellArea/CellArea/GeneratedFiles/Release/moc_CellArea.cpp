/****************************************************************************
** Meta object code from reading C++ file 'CellArea.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CellArea.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CellArea.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CellArea_t {
    QByteArrayData data[5];
    char stringdata0[62];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CellArea_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CellArea_t qt_meta_stringdata_CellArea = {
    {
QT_MOC_LITERAL(0, 0, 8), // "CellArea"
QT_MOC_LITERAL(1, 9, 15), // "signalLoadImage"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 4), // "path"
QT_MOC_LITERAL(4, 31, 30) // "slotOnActionLoadImageTriggered"

    },
    "CellArea\0signalLoadImage\0\0path\0"
    "slotOnActionLoadImageTriggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CellArea[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   27,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void CellArea::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CellArea *_t = static_cast<CellArea *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalLoadImage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->slotOnActionLoadImageTriggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CellArea::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CellArea::signalLoadImage)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject CellArea::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_CellArea.data,
      qt_meta_data_CellArea,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CellArea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CellArea::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CellArea.stringdata0))
        return static_cast<void*>(const_cast< CellArea*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int CellArea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void CellArea::signalLoadImage(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE