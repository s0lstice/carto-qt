/****************************************************************************
** Meta object code from reading C++ file 'geometry.h'
**
** Created: Tue 14. Feb 15:35:42 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../QMapControl/src/geometry.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'geometry.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_qmapcontrol__Geometry[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      28,   23,   22,   22, 0x05,
      58,   53,   22,   22, 0x05,
      95,   80,   22,   22, 0x05,
     129,   23,   22,   22, 0x05,

 // slots: signature, parameters, type, tag, flags
     164,  156,   22,   22, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_qmapcontrol__Geometry[] = {
    "qmapcontrol::Geometry\0\0geom\0"
    "updateRequest(Geometry*)\0rect\0"
    "updateRequest(QRectF)\0geometry,point\0"
    "geometryClicked(Geometry*,QPoint)\0"
    "positionChanged(Geometry*)\0visible\0"
    "setVisible(bool)\0"
};

const QMetaObject qmapcontrol::Geometry::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_qmapcontrol__Geometry,
      qt_meta_data_qmapcontrol__Geometry, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &qmapcontrol::Geometry::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *qmapcontrol::Geometry::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *qmapcontrol::Geometry::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_qmapcontrol__Geometry))
        return static_cast<void*>(const_cast< Geometry*>(this));
    return QObject::qt_metacast(_clname);
}

int qmapcontrol::Geometry::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: updateRequest((*reinterpret_cast< Geometry*(*)>(_a[1]))); break;
        case 1: updateRequest((*reinterpret_cast< QRectF(*)>(_a[1]))); break;
        case 2: geometryClicked((*reinterpret_cast< Geometry*(*)>(_a[1])),(*reinterpret_cast< QPoint(*)>(_a[2]))); break;
        case 3: positionChanged((*reinterpret_cast< Geometry*(*)>(_a[1]))); break;
        case 4: setVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void qmapcontrol::Geometry::updateRequest(Geometry * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void qmapcontrol::Geometry::updateRequest(QRectF _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void qmapcontrol::Geometry::geometryClicked(Geometry * _t1, QPoint _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void qmapcontrol::Geometry::positionChanged(Geometry * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
