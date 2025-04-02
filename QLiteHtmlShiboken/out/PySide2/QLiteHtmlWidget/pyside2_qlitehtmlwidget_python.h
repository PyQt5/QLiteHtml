

#ifndef SBK_QLITEHTMLWIDGET_PYTHON_H
#define SBK_QLITEHTMLWIDGET_PYTHON_H

#include <sbkpython.h>
#include <sbkconverter.h>
// Module Includes
#include <pyside2_qtwidgets_python.h>
#include <pyside2_qtgui_python.h>
#include <pyside2_qtcore_python.h>

// Bound library includes
#include <qlitehtmlwidget.h>
// Conversion Includes - Primitive Types
#include <wtypes.h>
#include <qabstractitemmodel.h>
#include <QString>
#include <QStringList>
#include <signalmanager.h>

// Conversion Includes - Container Types
#include <pysideqflags.h>
#include <QLinkedList>
#include <QList>
#include <QMap>
#include <QMultiMap>
#include <QPair>
#include <QQueue>
#include <QSet>
#include <QStack>
#include <QVector>

// Type indices
enum : int {
    SBK_QLITEHTMLWIDGET_IDX                                  = 0,
    SBK_QLiteHtmlWidget_IDX_COUNT                            = 1
};
// This variable stores all Python types exported by this module.
extern PyTypeObject **SbkPySide2_QLiteHtmlWidgetTypes;

// This variable stores the Python module object exported by this module.
extern PyObject *SbkPySide2_QLiteHtmlWidgetModuleObject;

// This variable stores all type converters exported by this module.
extern SbkConverter **SbkPySide2_QLiteHtmlWidgetTypeConverters;

// Converter indices
enum : int {
    SBK_QLITEHTMLWIDGET_QLIST_QWIDGETPTR_IDX                 = 0, // QList<QWidget* >
    SBK_QLITEHTMLWIDGET_QLIST_QVARIANT_IDX                   = 1, // QList<QVariant >
    SBK_QLITEHTMLWIDGET_QLIST_QSTRING_IDX                    = 2, // QList<QString >
    SBK_QLITEHTMLWIDGET_QMAP_QSTRING_QVARIANT_IDX            = 3, // QMap<QString,QVariant >
    SBK_QLiteHtmlWidget_CONVERTERS_IDX_COUNT                 = 4
};
// Macros for type check

namespace Shiboken
{

// PyType functions, to get the PyObjectType for a type T
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
template<> inline PyTypeObject *SbkType< ::QLiteHtmlWidget >() { return reinterpret_cast<PyTypeObject *>(SbkPySide2_QLiteHtmlWidgetTypes[SBK_QLITEHTMLWIDGET_IDX]); }
QT_WARNING_POP

} // namespace Shiboken

#endif // SBK_QLITEHTMLWIDGET_PYTHON_H

