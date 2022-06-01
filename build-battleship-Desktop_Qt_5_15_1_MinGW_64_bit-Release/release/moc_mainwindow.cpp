/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../battleship/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[22];
    char stringdata0[319];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 19), // "player_grid_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 3), // "row"
QT_MOC_LITERAL(4, 36, 3), // "col"
QT_MOC_LITERAL(5, 40, 21), // "opponent_grid_clicked"
QT_MOC_LITERAL(6, 62, 17), // "player_grid_hover"
QT_MOC_LITERAL(7, 80, 25), // "player_grid_right_clicked"
QT_MOC_LITERAL(8, 106, 26), // "create_position_indicators"
QT_MOC_LITERAL(9, 133, 14), // "Ship::ShipType"
QT_MOC_LITERAL(10, 148, 9), // "ship_type"
QT_MOC_LITERAL(11, 158, 3), // "cow"
QT_MOC_LITERAL(12, 162, 17), // "Ship::Orientation"
QT_MOC_LITERAL(13, 180, 11), // "orientation"
QT_MOC_LITERAL(14, 192, 18), // "handlePlayerShipCV"
QT_MOC_LITERAL(15, 211, 18), // "handlePlayerShipBB"
QT_MOC_LITERAL(16, 230, 18), // "handlePlayerShipCA"
QT_MOC_LITERAL(17, 249, 18), // "handlePlayerShipSS"
QT_MOC_LITERAL(18, 268, 18), // "handlePlayerShipDD"
QT_MOC_LITERAL(19, 287, 13), // "random_deploy"
QT_MOC_LITERAL(20, 301, 11), // "reset_ships"
QT_MOC_LITERAL(21, 313, 5) // "begin"

    },
    "MainWindow\0player_grid_clicked\0\0row\0"
    "col\0opponent_grid_clicked\0player_grid_hover\0"
    "player_grid_right_clicked\0"
    "create_position_indicators\0Ship::ShipType\0"
    "ship_type\0cow\0Ship::Orientation\0"
    "orientation\0handlePlayerShipCV\0"
    "handlePlayerShipBB\0handlePlayerShipCA\0"
    "handlePlayerShipSS\0handlePlayerShipDD\0"
    "random_deploy\0reset_ships\0begin"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   79,    2, 0x08 /* Private */,
       5,    2,   84,    2, 0x08 /* Private */,
       6,    2,   89,    2, 0x08 /* Private */,
       7,    0,   94,    2, 0x08 /* Private */,
       8,    4,   95,    2, 0x08 /* Private */,
      14,    0,  104,    2, 0x08 /* Private */,
      15,    0,  105,    2, 0x08 /* Private */,
      16,    0,  106,    2, 0x08 /* Private */,
      17,    0,  107,    2, 0x08 /* Private */,
      18,    0,  108,    2, 0x08 /* Private */,
      19,    0,  109,    2, 0x08 /* Private */,
      20,    0,  110,    2, 0x08 /* Private */,
      21,    0,  111,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9, QMetaType::Int, QMetaType::Int, 0x80000000 | 12,   10,    3,   11,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->player_grid_clicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->opponent_grid_clicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->player_grid_hover((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->player_grid_right_clicked(); break;
        case 4: _t->create_position_indicators((*reinterpret_cast< Ship::ShipType(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< Ship::Orientation(*)>(_a[4]))); break;
        case 5: _t->handlePlayerShipCV(); break;
        case 6: _t->handlePlayerShipBB(); break;
        case 7: _t->handlePlayerShipCA(); break;
        case 8: _t->handlePlayerShipSS(); break;
        case 9: _t->handlePlayerShipDD(); break;
        case 10: _t->random_deploy(); break;
        case 11: _t->reset_ships(); break;
        case 12: _t->begin(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
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
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
