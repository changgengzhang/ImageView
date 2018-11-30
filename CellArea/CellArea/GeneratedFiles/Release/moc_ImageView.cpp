/****************************************************************************
** Meta object code from reading C++ file 'ImageView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ImageView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ImageView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ImageView_t {
    QByteArrayData data[6];
    char stringdata0[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImageView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImageView_t qt_meta_stringdata_ImageView = {
    {
QT_MOC_LITERAL(0, 0, 9), // "ImageView"
QT_MOC_LITERAL(1, 10, 13), // "slotLoadImage"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 9), // "imagePath"
QT_MOC_LITERAL(4, 35, 39), // "slotOnPushButtonSaveCroppedIm..."
QT_MOC_LITERAL(5, 75, 43) // "slotOnPushButtonSaveCroppedIm..."

    },
    "ImageView\0slotLoadImage\0\0imagePath\0"
    "slotOnPushButtonSaveCroppedImageClicked\0"
    "slotOnPushButtonSaveCroppedImageMaskClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImageView[] = {

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
       1,    1,   29,    2, 0x0a /* Public */,
       4,    0,   32,    2, 0x0a /* Public */,
       5,    0,   33,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ImageView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ImageView *_t = static_cast<ImageView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotLoadImage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->slotOnPushButtonSaveCroppedImageClicked(); break;
        case 2: _t->slotOnPushButtonSaveCroppedImageMaskClicked(); break;
        default: ;
        }
    }
}

const QMetaObject ImageView::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_ImageView.data,
      qt_meta_data_ImageView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ImageView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImageView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ImageView.stringdata0))
        return static_cast<void*>(const_cast< ImageView*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int ImageView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
