/****************************************************************************
** Meta object code from reading C++ file 'gps_neo.h'
**
** Created: Tue 14. Feb 15:36:39 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../QMapControl/Samples/GPS/src/gps_neo.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gps_neo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GPS_Neo[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,    9,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      39,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GPS_Neo[] = {
    "GPS_Neo\0\0,\0new_position(float,QPointF)\0"
    "tick()\0"
};

const QMetaObject GPS_Neo::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GPS_Neo,
      qt_meta_data_GPS_Neo, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GPS_Neo::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GPS_Neo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GPS_Neo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GPS_Neo))
        return static_cast<void*>(const_cast< GPS_Neo*>(this));
    return QObject::qt_metacast(_clname);
}

int GPS_Neo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: new_position((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< QPointF(*)>(_a[2]))); break;
        case 1: tick(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void GPS_Neo::new_position(float _t1, QPointF _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
