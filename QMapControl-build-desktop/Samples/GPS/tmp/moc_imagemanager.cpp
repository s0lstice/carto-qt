/****************************************************************************
** Meta object code from reading C++ file 'imagemanager.h'
**
** Created: Tue 14. Feb 15:35:44 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../QMapControl/src/imagemanager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imagemanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_qmapcontrol__ImageManager[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      27,   26,   26,   26, 0x05,
      43,   26,   26,   26, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_qmapcontrol__ImageManager[] = {
    "qmapcontrol::ImageManager\0\0imageReceived()\0"
    "loadingFinished()\0"
};

const QMetaObject qmapcontrol::ImageManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_qmapcontrol__ImageManager,
      qt_meta_data_qmapcontrol__ImageManager, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &qmapcontrol::ImageManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *qmapcontrol::ImageManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *qmapcontrol::ImageManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_qmapcontrol__ImageManager))
        return static_cast<void*>(const_cast< ImageManager*>(this));
    return QObject::qt_metacast(_clname);
}

int qmapcontrol::ImageManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: imageReceived(); break;
        case 1: loadingFinished(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void qmapcontrol::ImageManager::imageReceived()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void qmapcontrol::ImageManager::loadingFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
