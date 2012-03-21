/****************************************************************************
** Meta object code from reading C++ file 'mapcontrol.h'
**
** Created: Tue 14. Feb 15:36:07 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../QMapControl/src/mapcontrol.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mapcontrol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_qmapcontrol__MapControl[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      41,   25,   24,   24, 0x05,
      90,   24,   24,   24, 0x05,
     127,  109,   24,   24, 0x05,
     177,  161,   24,   24, 0x05,

 // slots: signature, parameters, type, tag, flags
     202,   24,   24,   24, 0x0a,
     211,   24,   24,   24, 0x0a,
     231,  221,   24,   24, 0x0a,
     250,  244,   24,   24, 0x0a,
     266,   24,   24,   24, 0x2a,
     279,  244,   24,   24, 0x0a,
     296,   24,   24,   24, 0x2a,
     310,  244,   24,   24, 0x0a,
     324,   24,   24,   24, 0x2a,
     335,  244,   24,   24, 0x0a,
     351,   24,   24,   24, 0x2a,
     371,  364,   24,   24, 0x0a,
     391,  386,   24,   24, 0x0a,
     412,   24,   24,   24, 0x0a,
     439,  431,   24,   24, 0x0a,
     453,   24,   24,   24, 0x08,
     460,   24,   24,   24, 0x08,
     483,  478,   24,   24, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_qmapcontrol__MapControl[] = {
    "qmapcontrol::MapControl\0\0evnt,coordinate\0"
    "mouseEventCoordinate(const QMouseEvent*,QPointF)\0"
    "boxDragged(QRectF)\0geometry,coord_px\0"
    "geometryClicked(Geometry*,QPoint)\0"
    "coordinate,zoom\0viewChanged(QPointF,int)\0"
    "zoomIn()\0zoomOut()\0zoomlevel\0setZoom(int)\0"
    "pixel\0scrollLeft(int)\0scrollLeft()\0"
    "scrollRight(int)\0scrollRight()\0"
    "scrollUp(int)\0scrollUp()\0scrollDown(int)\0"
    "scrollDown()\0scroll\0scroll(QPoint)\0"
    "rect\0updateRequest(QRect)\0updateRequestNew()\0"
    "newSize\0resize(QSize)\0tick()\0"
    "loadingFinished()\0geom\0"
    "positionChanged(Geometry*)\0"
};

const QMetaObject qmapcontrol::MapControl::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_qmapcontrol__MapControl,
      qt_meta_data_qmapcontrol__MapControl, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &qmapcontrol::MapControl::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *qmapcontrol::MapControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *qmapcontrol::MapControl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_qmapcontrol__MapControl))
        return static_cast<void*>(const_cast< MapControl*>(this));
    return QWidget::qt_metacast(_clname);
}

int qmapcontrol::MapControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: mouseEventCoordinate((*reinterpret_cast< const QMouseEvent*(*)>(_a[1])),(*reinterpret_cast< const QPointF(*)>(_a[2]))); break;
        case 1: boxDragged((*reinterpret_cast< const QRectF(*)>(_a[1]))); break;
        case 2: geometryClicked((*reinterpret_cast< Geometry*(*)>(_a[1])),(*reinterpret_cast< QPoint(*)>(_a[2]))); break;
        case 3: viewChanged((*reinterpret_cast< const QPointF(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: zoomIn(); break;
        case 5: zoomOut(); break;
        case 6: setZoom((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: scrollLeft((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: scrollLeft(); break;
        case 9: scrollRight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: scrollRight(); break;
        case 11: scrollUp((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: scrollUp(); break;
        case 13: scrollDown((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: scrollDown(); break;
        case 15: scroll((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 16: updateRequest((*reinterpret_cast< QRect(*)>(_a[1]))); break;
        case 17: updateRequestNew(); break;
        case 18: resize((*reinterpret_cast< const QSize(*)>(_a[1]))); break;
        case 19: tick(); break;
        case 20: loadingFinished(); break;
        case 21: positionChanged((*reinterpret_cast< Geometry*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void qmapcontrol::MapControl::mouseEventCoordinate(const QMouseEvent * _t1, const QPointF _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void qmapcontrol::MapControl::boxDragged(const QRectF _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void qmapcontrol::MapControl::geometryClicked(Geometry * _t1, QPoint _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void qmapcontrol::MapControl::viewChanged(const QPointF & _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
