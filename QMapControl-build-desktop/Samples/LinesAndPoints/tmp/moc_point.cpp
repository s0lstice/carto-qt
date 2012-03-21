/****************************************************************************
** Meta object code from reading C++ file 'point.h'
**
** Created: Tue 14. Feb 15:33:50 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../QMapControl/src/point.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'point.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_qmapcontrol__Point[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      26,   20,   19,   19, 0x0a,
      57,   49,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_qmapcontrol__Point[] = {
    "qmapcontrol::Point\0\0point\0"
    "setCoordinate(QPointF)\0visible\0"
    "setVisible(bool)\0"
};

const QMetaObject qmapcontrol::Point::staticMetaObject = {
    { &Geometry::staticMetaObject, qt_meta_stringdata_qmapcontrol__Point,
      qt_meta_data_qmapcontrol__Point, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &qmapcontrol::Point::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *qmapcontrol::Point::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *qmapcontrol::Point::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_qmapcontrol__Point))
        return static_cast<void*>(const_cast< Point*>(this));
    return Geometry::qt_metacast(_clname);
}

int qmapcontrol::Point::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Geometry::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setCoordinate((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 1: setVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
