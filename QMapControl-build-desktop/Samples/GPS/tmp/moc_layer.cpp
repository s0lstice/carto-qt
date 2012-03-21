/****************************************************************************
** Meta object code from reading C++ file 'layer.h'
**
** Created: Tue 14. Feb 15:35:48 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../QMapControl/src/layer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'layer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_qmapcontrol__Layer[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      35,   20,   19,   19, 0x05,
      74,   69,   19,   19, 0x05,
      96,   19,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
     120,  112,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_qmapcontrol__Layer[] = {
    "qmapcontrol::Layer\0\0geometry,point\0"
    "geometryClicked(Geometry*,QPoint)\0"
    "rect\0updateRequest(QRectF)\0updateRequest()\0"
    "visible\0setVisible(bool)\0"
};

const QMetaObject qmapcontrol::Layer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_qmapcontrol__Layer,
      qt_meta_data_qmapcontrol__Layer, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &qmapcontrol::Layer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *qmapcontrol::Layer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *qmapcontrol::Layer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_qmapcontrol__Layer))
        return static_cast<void*>(const_cast< Layer*>(this));
    return QObject::qt_metacast(_clname);
}

int qmapcontrol::Layer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: geometryClicked((*reinterpret_cast< Geometry*(*)>(_a[1])),(*reinterpret_cast< QPoint(*)>(_a[2]))); break;
        case 1: updateRequest((*reinterpret_cast< QRectF(*)>(_a[1]))); break;
        case 2: updateRequest(); break;
        case 3: setVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void qmapcontrol::Layer::geometryClicked(Geometry * _t1, QPoint _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void qmapcontrol::Layer::updateRequest(QRectF _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void qmapcontrol::Layer::updateRequest()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
