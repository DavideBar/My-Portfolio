/****************************************************************************
** Meta object code from reading C++ file 'view_gl.h'
**
** Created: Mon May 27 13:01:15 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../view_gl.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'view_gl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ViewMapGL[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      39,   24,   10,   10, 0x08,
      75,   69,   10,   10, 0x28,
     100,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ViewMapGL[] = {
    "ViewMapGL\0\0mapClearGL()\0x,y,c,animated\0"
    "mapPaintGL(int,int,Cell,bool)\0x,y,c\0"
    "mapPaintGL(int,int,Cell)\0timerPaintGL()\0"
};

void ViewMapGL::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ViewMapGL *_t = static_cast<ViewMapGL *>(_o);
        switch (_id) {
        case 0: _t->mapClearGL(); break;
        case 1: _t->mapPaintGL((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< Cell(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 2: _t->mapPaintGL((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< Cell(*)>(_a[3]))); break;
        case 3: _t->timerPaintGL(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ViewMapGL::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ViewMapGL::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_ViewMapGL,
      qt_meta_data_ViewMapGL, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ViewMapGL::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ViewMapGL::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ViewMapGL::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ViewMapGL))
        return static_cast<void*>(const_cast< ViewMapGL*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int ViewMapGL::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
static const uint qt_meta_data_View3DGL[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_View3DGL[] = {
    "View3DGL\0\0timerPaintGL()\0"
};

void View3DGL::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        View3DGL *_t = static_cast<View3DGL *>(_o);
        switch (_id) {
        case 0: _t->timerPaintGL(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData View3DGL::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject View3DGL::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_View3DGL,
      qt_meta_data_View3DGL, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &View3DGL::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *View3DGL::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *View3DGL::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_View3DGL))
        return static_cast<void*>(const_cast< View3DGL*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int View3DGL::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
