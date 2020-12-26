/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[345];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 25), // "on_basicTableView_clicked"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 11), // "QModelIndex"
QT_MOC_LITERAL(4, 50, 5), // "index"
QT_MOC_LITERAL(5, 56, 26), // "on_tabWidget_tabBarClicked"
QT_MOC_LITERAL(6, 83, 9), // "onTimeOut"
QT_MOC_LITERAL(7, 93, 14), // "slot_getParams"
QT_MOC_LITERAL(8, 108, 12), // "slot_resetCT"
QT_MOC_LITERAL(9, 121, 32), // "on_horizontalSlider_valueChanged"
QT_MOC_LITERAL(10, 154, 5), // "value"
QT_MOC_LITERAL(11, 160, 31), // "on_horizontalSlider_sliderMoved"
QT_MOC_LITERAL(12, 192, 8), // "position"
QT_MOC_LITERAL(13, 201, 30), // "on_verticalSlider_valueChanged"
QT_MOC_LITERAL(14, 232, 29), // "on_verticalSlider_sliderMoved"
QT_MOC_LITERAL(15, 262, 13), // "slot_img2Gray"
QT_MOC_LITERAL(16, 276, 17), // "slot_guassianBlur"
QT_MOC_LITERAL(17, 294, 15), // "slot_bilateBlur"
QT_MOC_LITERAL(18, 310, 14), // "slot_threshold"
QT_MOC_LITERAL(19, 325, 4), // "type"
QT_MOC_LITERAL(20, 330, 14) // "slot_cellCount"

    },
    "MainWindow\0on_basicTableView_clicked\0"
    "\0QModelIndex\0index\0on_tabWidget_tabBarClicked\0"
    "onTimeOut\0slot_getParams\0slot_resetCT\0"
    "on_horizontalSlider_valueChanged\0value\0"
    "on_horizontalSlider_sliderMoved\0"
    "position\0on_verticalSlider_valueChanged\0"
    "on_verticalSlider_sliderMoved\0"
    "slot_img2Gray\0slot_guassianBlur\0"
    "slot_bilateBlur\0slot_threshold\0type\0"
    "slot_cellCount"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x08 /* Private */,
       5,    1,   87,    2, 0x08 /* Private */,
       6,    0,   90,    2, 0x08 /* Private */,
       7,    0,   91,    2, 0x08 /* Private */,
       8,    0,   92,    2, 0x08 /* Private */,
       9,    1,   93,    2, 0x08 /* Private */,
      11,    1,   96,    2, 0x08 /* Private */,
      13,    1,   99,    2, 0x08 /* Private */,
      14,    1,  102,    2, 0x08 /* Private */,
      15,    0,  105,    2, 0x08 /* Private */,
      16,    0,  106,    2, 0x08 /* Private */,
      17,    0,  107,    2, 0x08 /* Private */,
      18,    1,  108,    2, 0x08 /* Private */,
      20,    0,  111,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_basicTableView_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->on_tabWidget_tabBarClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->onTimeOut(); break;
        case 3: _t->slot_getParams(); break;
        case 4: _t->slot_resetCT(); break;
        case 5: _t->on_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_horizontalSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_verticalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_verticalSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->slot_img2Gray(); break;
        case 10: _t->slot_guassianBlur(); break;
        case 11: _t->slot_bilateBlur(); break;
        case 12: _t->slot_threshold((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->slot_cellCount(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
