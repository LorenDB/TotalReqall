/****************************************************************************
** Meta object code from reading C++ file 'ChooseReferenceWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../ChooseReferenceWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ChooseReferenceWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ChooseReferenceWidget_t {
    QByteArrayData data[10];
    char stringdata0[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChooseReferenceWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChooseReferenceWidget_t qt_meta_stringdata_ChooseReferenceWidget = {
    {
QT_MOC_LITERAL(0, 0, 21), // "ChooseReferenceWidget"
QT_MOC_LITERAL(1, 22, 18), // "signalRunMemorizer"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 12), // "resizeNeeded"
QT_MOC_LITERAL(4, 55, 24), // "updateChapterVerseValues"
QT_MOC_LITERAL(5, 80, 17), // "updateVerseValues"
QT_MOC_LITERAL(6, 98, 20), // "updateEndVerseValues"
QT_MOC_LITERAL(7, 119, 15), // "updateSaveVerse"
QT_MOC_LITERAL(8, 135, 12), // "displayVerse"
QT_MOC_LITERAL(9, 148, 12) // "runMemorizer"

    },
    "ChooseReferenceWidget\0signalRunMemorizer\0"
    "\0resizeNeeded\0updateChapterVerseValues\0"
    "updateVerseValues\0updateEndVerseValues\0"
    "updateSaveVerse\0displayVerse\0runMemorizer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChooseReferenceWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       3,    0,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   58,    2, 0x08 /* Private */,
       5,    0,   59,    2, 0x08 /* Private */,
       6,    0,   60,    2, 0x08 /* Private */,
       7,    0,   61,    2, 0x08 /* Private */,
       8,    0,   62,    2, 0x08 /* Private */,
       9,    0,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ChooseReferenceWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ChooseReferenceWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalRunMemorizer((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->resizeNeeded(); break;
        case 2: _t->updateChapterVerseValues(); break;
        case 3: _t->updateVerseValues(); break;
        case 4: _t->updateEndVerseValues(); break;
        case 5: _t->updateSaveVerse(); break;
        case 6: _t->displayVerse(); break;
        case 7: _t->runMemorizer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ChooseReferenceWidget::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChooseReferenceWidget::signalRunMemorizer)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ChooseReferenceWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChooseReferenceWidget::resizeNeeded)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ChooseReferenceWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ChooseReferenceWidget.data,
    qt_meta_data_ChooseReferenceWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ChooseReferenceWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChooseReferenceWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ChooseReferenceWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ChooseReferenceWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void ChooseReferenceWidget::signalRunMemorizer(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ChooseReferenceWidget::resizeNeeded()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
