
// default includes
#include <shiboken.h>
#ifndef QT_NO_VERSION_TAGGING
#  define QT_NO_VERSION_TAGGING
#endif
#include <QDebug>
#include <pysidesignal.h>
#include <pysideproperty.h>
#include <pyside.h>
#include <pysideqenum.h>
#include <feature_select.h>
#include <qapp_macro.h>

QT_WARNING_DISABLE_DEPRECATED

#include <typeinfo>
#include <signalmanager.h>
#include <pysidemetafunction.h>
#include <algorithm>
#include <set>
#include <iterator>

// module include
#include "pyside2_qlitehtmlwidget_python.h"

// main header
#include "qlitehtmlwidget_wrapper.h"

// inner classes

#include <cctype>
#include <cstring>



template <class T>
static const char *typeNameOf(const T &t)
{
    const char *typeName =  typeid(t).name();
    auto size = std::strlen(typeName);
#if defined(Q_CC_MSVC) // MSVC: "class QPaintDevice * __ptr64"
    if (auto lastStar = strchr(typeName, '*')) {
        // MSVC: "class QPaintDevice * __ptr64"
        while (*--lastStar == ' ') {
        }
        size = lastStar - typeName + 1;
    }
#else // g++, Clang: "QPaintDevice *" -> "P12QPaintDevice"
    if (size > 2 && typeName[0] == 'P' && std::isdigit(typeName[1])) {
        ++typeName;
        --size;
    }
#endif
    char *result = new char[size + 1];
    result[size] = '\0';
    memcpy(result, typeName, size);
    return result;
}

// Native ---------------------------------------------------------

void QLiteHtmlWidgetWrapper::pysideInitQtMetaTypes()
{
}

void QLiteHtmlWidgetWrapper::resetPyMethodCache()
{
    std::fill_n(m_PyMethodCache, sizeof(m_PyMethodCache) / sizeof(m_PyMethodCache[0]), false);
}

QLiteHtmlWidgetWrapper::QLiteHtmlWidgetWrapper(QWidget * parent) : QLiteHtmlWidget(parent)
{
    resetPyMethodCache();
    // ... middle
}

void QLiteHtmlWidgetWrapper::actionEvent(QActionEvent * event)
{
    if (m_PyMethodCache[0]) {
        return this->::QWidget::actionEvent(event);
    }
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "actionEvent";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[0] = true;
        return this->::QWidget::actionEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtGuiTypes[SBK_QACTIONEVENT_IDX]), event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return;
    }
    if (invalidateArg1)
    Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QLiteHtmlWidgetWrapper::changeEvent(QEvent * arg__1)
{
    if (m_PyMethodCache[1]) {
        return this->::QFrame::changeEvent(arg__1);
    }
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "changeEvent";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[1] = true;
        return this->::QFrame::changeEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtCoreTypes[SBK_QEVENT_IDX]), arg__1)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return;
    }
    if (invalidateArg1)
    Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QLiteHtmlWidgetWrapper::childEvent(QChildEvent * event)
{
    if (m_PyMethodCache[2]) {
        return this->::QObject::childEvent(event);
    }
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "childEvent";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[2] = true;
        return this->::QObject::childEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtCoreTypes[SBK_QCHILDEVENT_IDX]), event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return;
    }
    if (invalidateArg1)
    Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QLiteHtmlWidgetWrapper::closeEvent(QCloseEvent * event)
{
    if (m_PyMethodCache[3]) {
        return this->::QWidget::closeEvent(event);
    }
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "closeEvent";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[3] = true;
        return this->::QWidget::closeEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtGuiTypes[SBK_QCLOSEEVENT_IDX]), event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return;
    }
    if (invalidateArg1)
    Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QLiteHtmlWidgetWrapper::connectNotify(const QMetaMethod & signal)
{
    if (m_PyMethodCache[4]) {
        return this->::QObject::connectNotify(signal);
    }
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "connectNotify";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[4] = true;
        return this->::QObject::connectNotify(signal);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtCoreTypes[SBK_QMETAMETHOD_IDX]), &signal)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return;
    }
}

void QLiteHtmlWidgetWrapper::contextMenuEvent(QContextMenuEvent * event)
{
    if (m_PyMethodCache[5]) {
        return this->::QLiteHtmlWidget::contextMenuEvent(event);
    }
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "contextMenuEvent";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[5] = true;
        return this->::QLiteHtmlWidget::contextMenuEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtGuiTypes[SBK_QCONTEXTMENUEVENT_IDX]), event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return;
    }
    if (invalidateArg1)
    Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QLiteHtmlWidgetWrapper::customEvent(QEvent * event)
{
    if (m_PyMethodCache[6]) {
        return this->::QObject::customEvent(event);
    }
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "customEvent";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[6] = true;
        return this->::QObject::customEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtCoreTypes[SBK_QEVENT_IDX]), event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return;
    }
    if (invalidateArg1)
    Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

int QLiteHtmlWidgetWrapper::devType() const
{
    if (m_PyMethodCache[7])
        return this->::QWidget::devType();
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return 0;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "devType";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[7] = true;
        return this->::QWidget::devType();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return 0;
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QLiteHtmlWidget.devType", "int", Py_TYPE(pyResult)->tp_name);
        return 0;
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QLiteHtmlWidgetWrapper::disconnectNotify(const QMetaMethod & signal)
{
    if (m_PyMethodCache[8]) {
        return this->::QObject::disconnectNotify(signal);
    }
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "disconnectNotify";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[8] = true;
        return this->::QObject::disconnectNotify(signal);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtCoreTypes[SBK_QMETAMETHOD_IDX]), &signal)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return;
    }
}

void QLiteHtmlWidgetWrapper::dragEnterEvent(QDragEnterEvent * arg__1)
{
    if (m_PyMethodCache[9]) {
        return this->::QAbstractScrollArea::dragEnterEvent(arg__1);
    }
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "dragEnterEvent";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[9] = true;
        return this->::QAbstractScrollArea::dragEnterEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtGuiTypes[SBK_QDRAGENTEREVENT_IDX]), arg__1)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return;
    }
    if (invalidateArg1)
    Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QLiteHtmlWidgetWrapper::dragLeaveEvent(QDragLeaveEvent * arg__1)
{
    if (m_PyMethodCache[10]) {
        return this->::QAbstractScrollArea::dragLeaveEvent(arg__1);
    }
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "dragLeaveEvent";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[10] = true;
        return this->::QAbstractScrollArea::dragLeaveEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtGuiTypes[SBK_QDRAGLEAVEEVENT_IDX]), arg__1)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return;
    }
    if (invalidateArg1)
    Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QLiteHtmlWidgetWrapper::dragMoveEvent(QDragMoveEvent * arg__1)
{
    if (m_PyMethodCache[11]) {
        return this->::QAbstractScrollArea::dragMoveEvent(arg__1);
    }
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "dragMoveEvent";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[11] = true;
        return this->::QAbstractScrollArea::dragMoveEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtGuiTypes[SBK_QDRAGMOVEEVENT_IDX]), arg__1)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return;
    }
    if (invalidateArg1)
    Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QLiteHtmlWidgetWrapper::dropEvent(QDropEvent * arg__1)
{
    if (m_PyMethodCache[12]) {
        return this->::QAbstractScrollArea::dropEvent(arg__1);
    }
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "dropEvent";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[12] = true;
        return this->::QAbstractScrollArea::dropEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtGuiTypes[SBK_QDROPEVENT_IDX]), arg__1)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return;
    }
    if (invalidateArg1)
    Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QLiteHtmlWidgetWrapper::enterEvent(QEvent * event)
{
    if (m_PyMethodCache[13]) {
        return this->::QWidget::enterEvent(event);
    }
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "enterEvent";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[13] = true;
        return this->::QWidget::enterEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtCoreTypes[SBK_QEVENT_IDX]), event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return;
    }
    if (invalidateArg1)
    Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

bool QLiteHtmlWidgetWrapper::event(QEvent * arg__1)
{
    if (m_PyMethodCache[14])
        return this->::QAbstractScrollArea::event(arg__1);
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return false;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "event";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[14] = true;
        return this->::QAbstractScrollArea::event(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtCoreTypes[SBK_QEVENT_IDX]), arg__1)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return false;
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QLiteHtmlWidget.event", "bool", Py_TYPE(pyResult)->tp_name);
        return false;
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
    Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QLiteHtmlWidgetWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
{
    if (m_PyMethodCache[15])
        return this->::QAbstractScrollArea::eventFilter(arg__1, arg__2);
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return false;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "eventFilter";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[15] = true;
        return this->::QAbstractScrollArea::eventFilter(arg__1, arg__2);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
    Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtCoreTypes[SBK_QOBJECT_IDX]), arg__1),
    Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtCoreTypes[SBK_QEVENT_IDX]), arg__2)
    ));
    bool invalidateArg2 = PyTuple_GET_ITEM(pyArgs, 1)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return false;
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QLiteHtmlWidget.eventFilter", "bool", Py_TYPE(pyResult)->tp_name);
        return false;
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
    Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QLiteHtmlWidgetWrapper::focusInEvent(QFocusEvent * event)
{
    if (m_PyMethodCache[16]) {
        return this->::QWidget::focusInEvent(event);
    }
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "focusInEvent";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[16] = true;
        return this->::QWidget::focusInEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtGuiTypes[SBK_QFOCUSEVENT_IDX]), event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return;
    }
    if (invalidateArg1)
    Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

bool QLiteHtmlWidgetWrapper::focusNextPrevChild(bool next)
{
    if (m_PyMethodCache[17])
        return this->::QWidget::focusNextPrevChild(next);
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return false;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "focusNextPrevChild";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[17] = true;
        return this->::QWidget::focusNextPrevChild(next);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &next)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return false;
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QLiteHtmlWidget.focusNextPrevChild", "bool", Py_TYPE(pyResult)->tp_name);
        return false;
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QLiteHtmlWidgetWrapper::focusOutEvent(QFocusEvent * event)
{
    if (m_PyMethodCache[18]) {
        return this->::QWidget::focusOutEvent(event);
    }
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "focusOutEvent";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[18] = true;
        return this->::QWidget::focusOutEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtGuiTypes[SBK_QFOCUSEVENT_IDX]), event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return;
    }
    if (invalidateArg1)
    Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

bool QLiteHtmlWidgetWrapper::hasHeightForWidth() const
{
    if (m_PyMethodCache[19])
        return this->::QWidget::hasHeightForWidth();
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return false;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "hasHeightForWidth";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[19] = true;
        return this->::QWidget::hasHeightForWidth();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return false;
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QLiteHtmlWidget.hasHeightForWidth", "bool", Py_TYPE(pyResult)->tp_name);
        return false;
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

int QLiteHtmlWidgetWrapper::heightForWidth(int arg__1) const
{
    if (m_PyMethodCache[20])
        return this->::QWidget::heightForWidth(arg__1);
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return 0;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "heightForWidth";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[20] = true;
        return this->::QWidget::heightForWidth(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
    arg__1
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return 0;
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QLiteHtmlWidget.heightForWidth", "int", Py_TYPE(pyResult)->tp_name);
        return 0;
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QLiteHtmlWidgetWrapper::hideEvent(QHideEvent * event)
{
    if (m_PyMethodCache[21]) {
        return this->::QWidget::hideEvent(event);
    }
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "hideEvent";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[21] = true;
        return this->::QWidget::hideEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtGuiTypes[SBK_QHIDEEVENT_IDX]), event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return;
    }
    if (invalidateArg1)
    Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QLiteHtmlWidgetWrapper::initPainter(QPainter * painter) const
{
    if (m_PyMethodCache[22]) {
        return this->::QWidget::initPainter(painter);
    }
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "initPainter";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[22] = true;
        return this->::QWidget::initPainter(painter);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtGuiTypes[SBK_QPAINTER_IDX]), painter)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return;
    }
}

void QLiteHtmlWidgetWrapper::inputMethodEvent(QInputMethodEvent * event)
{
    if (m_PyMethodCache[23]) {
        return this->::QWidget::inputMethodEvent(event);
    }
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "inputMethodEvent";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[23] = true;
        return this->::QWidget::inputMethodEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtGuiTypes[SBK_QINPUTMETHODEVENT_IDX]), event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return;
    }
    if (invalidateArg1)
    Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

QVariant QLiteHtmlWidgetWrapper::inputMethodQuery(Qt::InputMethodQuery arg__1) const
{
    if (m_PyMethodCache[24])
        return this->::QWidget::inputMethodQuery(arg__1);
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return ::QVariant();
    static PyObject *nameCache[2] = {};
    static const char *funcName = "inputMethodQuery";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[24] = true;
        return this->::QWidget::inputMethodQuery(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::copyToPython(*PepType_SGTP(SbkPySide2_QtCoreTypes[SBK_QT_INPUTMETHODQUERY_IDX])->converter, &arg__1)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QVariant();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QVARIANT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QLiteHtmlWidget.inputMethodQuery", "QVariant", Py_TYPE(pyResult)->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QLiteHtmlWidgetWrapper::keyPressEvent(QKeyEvent * event)
{
    if (m_PyMethodCache[25]) {
        return this->::QLiteHtmlWidget::keyPressEvent(event);
    }
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "keyPressEvent";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[25] = true;
        return this->::QLiteHtmlWidget::keyPressEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtGuiTypes[SBK_QKEYEVENT_IDX]), event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return;
    }
    if (invalidateArg1)
    Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QLiteHtmlWidgetWrapper::keyReleaseEvent(QKeyEvent * event)
{
    if (m_PyMethodCache[26]) {
        return this->::QWidget::keyReleaseEvent(event);
    }
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "keyReleaseEvent";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[26] = true;
        return this->::QWidget::keyReleaseEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtGuiTypes[SBK_QKEYEVENT_IDX]), event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return;
    }
    if (invalidateArg1)
    Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QLiteHtmlWidgetWrapper::leaveEvent(QEvent * event)
{
    if (m_PyMethodCache[27]) {
        return this->::QLiteHtmlWidget::leaveEvent(event);
    }
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "leaveEvent";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[27] = true;
        return this->::QLiteHtmlWidget::leaveEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtCoreTypes[SBK_QEVENT_IDX]), event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return;
    }
    if (invalidateArg1)
    Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

int QLiteHtmlWidgetWrapper::metric(QPaintDevice::PaintDeviceMetric arg__1) const
{
    if (m_PyMethodCache[29])
        return this->::QWidget::metric(arg__1);
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return 0;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "metric";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[29] = true;
        return this->::QWidget::metric(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::copyToPython(*PepType_SGTP(SbkPySide2_QtGuiTypes[SBK_QPAINTDEVICE_PAINTDEVICEMETRIC_IDX])->converter, &arg__1)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return 0;
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QLiteHtmlWidget.metric", "int", Py_TYPE(pyResult)->tp_name);
        return 0;
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QSize QLiteHtmlWidgetWrapper::minimumSizeHint() const
{
    if (m_PyMethodCache[30])
        return this->::QAbstractScrollArea::minimumSizeHint();
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return {};
    static PyObject *nameCache[2] = {};
    static const char *funcName = "minimumSizeHint";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[30] = true;
        return this->::QAbstractScrollArea::minimumSizeHint();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return {};
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtCoreTypes[SBK_QSIZE_IDX]), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QLiteHtmlWidget.minimumSizeHint", reinterpret_cast<PyTypeObject *>(Shiboken::SbkType< QSize >())->tp_name, Py_TYPE(pyResult)->tp_name);
        return {};
    }
    ::QSize cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QLiteHtmlWidgetWrapper::mouseDoubleClickEvent(QMouseEvent * event)
{
    if (m_PyMethodCache[31]) {
        return this->::QLiteHtmlWidget::mouseDoubleClickEvent(event);
    }
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "mouseDoubleClickEvent";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[31] = true;
        return this->::QLiteHtmlWidget::mouseDoubleClickEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtGuiTypes[SBK_QMOUSEEVENT_IDX]), event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return;
    }
    if (invalidateArg1)
    Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QLiteHtmlWidgetWrapper::mouseMoveEvent(QMouseEvent * event)
{
    if (m_PyMethodCache[32]) {
        return this->::QLiteHtmlWidget::mouseMoveEvent(event);
    }
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "mouseMoveEvent";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[32] = true;
        return this->::QLiteHtmlWidget::mouseMoveEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtGuiTypes[SBK_QMOUSEEVENT_IDX]), event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return;
    }
    if (invalidateArg1)
    Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QLiteHtmlWidgetWrapper::mousePressEvent(QMouseEvent * event)
{
    if (m_PyMethodCache[33]) {
        return this->::QLiteHtmlWidget::mousePressEvent(event);
    }
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "mousePressEvent";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[33] = true;
        return this->::QLiteHtmlWidget::mousePressEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtGuiTypes[SBK_QMOUSEEVENT_IDX]), event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return;
    }
    if (invalidateArg1)
    Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QLiteHtmlWidgetWrapper::mouseReleaseEvent(QMouseEvent * event)
{
    if (m_PyMethodCache[34]) {
        return this->::QLiteHtmlWidget::mouseReleaseEvent(event);
    }
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "mouseReleaseEvent";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[34] = true;
        return this->::QLiteHtmlWidget::mouseReleaseEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtGuiTypes[SBK_QMOUSEEVENT_IDX]), event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return;
    }
    if (invalidateArg1)
    Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QLiteHtmlWidgetWrapper::moveEvent(QMoveEvent * event)
{
    if (m_PyMethodCache[35]) {
        return this->::QWidget::moveEvent(event);
    }
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "moveEvent";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[35] = true;
        return this->::QWidget::moveEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtGuiTypes[SBK_QMOVEEVENT_IDX]), event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return;
    }
    if (invalidateArg1)
    Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

bool QLiteHtmlWidgetWrapper::nativeEvent(const QByteArray & eventType, void * message, long * result)
{
    if (m_PyMethodCache[36]) {
        return this->::QWidget::nativeEvent(eventType, message, result);
    }
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return false;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "nativeEvent";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[36] = true;
        return this->::QWidget::nativeEvent(eventType, message, result);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
    Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtCoreTypes[SBK_QBYTEARRAY_IDX]), &eventType),
    Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<void *>(), message)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return false;
    }
    // Begin code injection
    // TEMPLATE - return_native_eventfilter_conversion - START
    bool cppResult = false;
    if (PySequence_Check(pyResult) && (PySequence_Size(pyResult) == 2)) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyResult, 0));
        Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyItem, &(cppResult));
        if (result) {
            Shiboken::AutoDecRef pyResultItem(PySequence_GetItem(pyResult, 1));
            Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<long>(), pyResultItem, (result));
        }
    }
    // TEMPLATE - return_native_eventfilter_conversion - END

    // End of code injection


    return cppResult;
}

QPaintEngine * QLiteHtmlWidgetWrapper::paintEngine() const
{
    if (m_PyMethodCache[37])
        return this->::QWidget::paintEngine();
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return nullptr;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "paintEngine";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[37] = true;
        return this->::QWidget::paintEngine();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return nullptr;
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtGuiTypes[SBK_QPAINTENGINE_IDX]), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QLiteHtmlWidget.paintEngine", reinterpret_cast<PyTypeObject *>(Shiboken::SbkType< QPaintEngine >())->tp_name, Py_TYPE(pyResult)->tp_name);
        return nullptr;
    }
    ::QPaintEngine *cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QLiteHtmlWidgetWrapper::paintEvent(QPaintEvent * event)
{
    if (m_PyMethodCache[38]) {
        return this->::QLiteHtmlWidget::paintEvent(event);
    }
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "paintEvent";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[38] = true;
        return this->::QLiteHtmlWidget::paintEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtGuiTypes[SBK_QPAINTEVENT_IDX]), event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return;
    }
    if (invalidateArg1)
    Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

QPaintDevice * QLiteHtmlWidgetWrapper::redirected(QPoint * offset) const
{
    if (m_PyMethodCache[39])
        return this->::QWidget::redirected(offset);
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return nullptr;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "redirected";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[39] = true;
        return this->::QWidget::redirected(offset);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtCoreTypes[SBK_QPOINT_IDX]), offset)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return nullptr;
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtGuiTypes[SBK_QPAINTDEVICE_IDX]), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QLiteHtmlWidget.redirected", reinterpret_cast<PyTypeObject *>(Shiboken::SbkType< QPaintDevice >())->tp_name, Py_TYPE(pyResult)->tp_name);
        return nullptr;
    }
    ::QPaintDevice *cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QLiteHtmlWidgetWrapper::resizeEvent(QResizeEvent * event)
{
    if (m_PyMethodCache[40]) {
        return this->::QLiteHtmlWidget::resizeEvent(event);
    }
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "resizeEvent";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[40] = true;
        return this->::QLiteHtmlWidget::resizeEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtGuiTypes[SBK_QRESIZEEVENT_IDX]), event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return;
    }
    if (invalidateArg1)
    Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QLiteHtmlWidgetWrapper::scrollContentsBy(int dx, int dy)
{
    if (m_PyMethodCache[41]) {
        return this->::QAbstractScrollArea::scrollContentsBy(dx, dy);
    }
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "scrollContentsBy";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[41] = true;
        return this->::QAbstractScrollArea::scrollContentsBy(dx, dy);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(ii)",
    dx,
    dy
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return;
    }
}

void QLiteHtmlWidgetWrapper::setVisible(bool visible)
{
    if (m_PyMethodCache[42]) {
        return this->::QWidget::setVisible(visible);
    }
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return;
    static PyObject *nameCache[2] = {};
    // This method belongs to a property.
    static const char *funcName = "2:setVisible";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[42] = true;
        return this->::QWidget::setVisible(visible);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &visible)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return;
    }
}

void QLiteHtmlWidgetWrapper::setupViewport(QWidget * viewport)
{
    if (m_PyMethodCache[43]) {
        return this->::QAbstractScrollArea::setupViewport(viewport);
    }
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "setupViewport";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[43] = true;
        return this->::QAbstractScrollArea::setupViewport(viewport);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtWidgetsTypes[SBK_QWIDGET_IDX]), viewport)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return;
    }
}

QPainter * QLiteHtmlWidgetWrapper::sharedPainter() const
{
    if (m_PyMethodCache[44])
        return this->::QWidget::sharedPainter();
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return nullptr;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "sharedPainter";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[44] = true;
        return this->::QWidget::sharedPainter();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return nullptr;
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtGuiTypes[SBK_QPAINTER_IDX]), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QLiteHtmlWidget.sharedPainter", reinterpret_cast<PyTypeObject *>(Shiboken::SbkType< QPainter >())->tp_name, Py_TYPE(pyResult)->tp_name);
        return nullptr;
    }
    ::QPainter *cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QLiteHtmlWidgetWrapper::showEvent(QShowEvent * event)
{
    if (m_PyMethodCache[45]) {
        return this->::QWidget::showEvent(event);
    }
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "showEvent";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[45] = true;
        return this->::QWidget::showEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtGuiTypes[SBK_QSHOWEVENT_IDX]), event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return;
    }
    if (invalidateArg1)
    Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

QSize QLiteHtmlWidgetWrapper::sizeHint() const
{
    if (m_PyMethodCache[46])
        return this->::QAbstractScrollArea::sizeHint();
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return {};
    static PyObject *nameCache[2] = {};
    static const char *funcName = "sizeHint";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[46] = true;
        return this->::QAbstractScrollArea::sizeHint();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return {};
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtCoreTypes[SBK_QSIZE_IDX]), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QLiteHtmlWidget.sizeHint", reinterpret_cast<PyTypeObject *>(Shiboken::SbkType< QSize >())->tp_name, Py_TYPE(pyResult)->tp_name);
        return {};
    }
    ::QSize cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QLiteHtmlWidgetWrapper::tabletEvent(QTabletEvent * event)
{
    if (m_PyMethodCache[47]) {
        return this->::QWidget::tabletEvent(event);
    }
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "tabletEvent";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[47] = true;
        return this->::QWidget::tabletEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtGuiTypes[SBK_QTABLETEVENT_IDX]), event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return;
    }
    if (invalidateArg1)
    Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QLiteHtmlWidgetWrapper::timerEvent(QTimerEvent * event)
{
    if (m_PyMethodCache[48]) {
        return this->::QObject::timerEvent(event);
    }
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "timerEvent";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[48] = true;
        return this->::QObject::timerEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtCoreTypes[SBK_QTIMEREVENT_IDX]), event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return;
    }
    if (invalidateArg1)
    Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

bool QLiteHtmlWidgetWrapper::viewportEvent(QEvent * arg__1)
{
    if (m_PyMethodCache[49])
        return this->::QAbstractScrollArea::viewportEvent(arg__1);
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return false;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "viewportEvent";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[49] = true;
        return this->::QAbstractScrollArea::viewportEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtCoreTypes[SBK_QEVENT_IDX]), arg__1)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return false;
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QLiteHtmlWidget.viewportEvent", "bool", Py_TYPE(pyResult)->tp_name);
        return false;
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
    Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

QSize QLiteHtmlWidgetWrapper::viewportSizeHint() const
{
    if (m_PyMethodCache[50])
        return this->::QAbstractScrollArea::viewportSizeHint();
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return {};
    static PyObject *nameCache[2] = {};
    static const char *funcName = "viewportSizeHint";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[50] = true;
        return this->::QAbstractScrollArea::viewportSizeHint();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return {};
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtCoreTypes[SBK_QSIZE_IDX]), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QLiteHtmlWidget.viewportSizeHint", reinterpret_cast<PyTypeObject *>(Shiboken::SbkType< QSize >())->tp_name, Py_TYPE(pyResult)->tp_name);
        return {};
    }
    ::QSize cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QLiteHtmlWidgetWrapper::wheelEvent(QWheelEvent * arg__1)
{
    if (m_PyMethodCache[51]) {
        return this->::QAbstractScrollArea::wheelEvent(arg__1);
    }
    Shiboken::GilState gil;
    if (PyErr_Occurred())
    return;
    static PyObject *nameCache[2] = {};
    static const char *funcName = "wheelEvent";
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, nameCache, funcName));
        if (pyOverride.isNull()) {
        gil.release();
        m_PyMethodCache[51] = true;
        return this->::QAbstractScrollArea::wheelEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
    Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtGuiTypes[SBK_QWHEELEVENT_IDX]), arg__1)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return;
    }
    if (invalidateArg1)
    Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

const QMetaObject *QLiteHtmlWidgetWrapper::metaObject() const
{
    if (QObject::d_ptr->metaObject)
        return QObject::d_ptr->dynamicMetaObject();
    SbkObject *pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == nullptr)
        return QLiteHtmlWidget::metaObject();
    return PySide::SignalManager::retrieveMetaObject(reinterpret_cast<PyObject *>(pySelf));
}

int QLiteHtmlWidgetWrapper::qt_metacall(QMetaObject::Call call, int id, void **args)
{
    int result = QLiteHtmlWidget::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void *QLiteHtmlWidgetWrapper::qt_metacast(const char *_clname)
{
        if (!_clname) return {};
        SbkObject *pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void *>(const_cast< QLiteHtmlWidgetWrapper *>(this));
        return QLiteHtmlWidget::qt_metacast(_clname);
}

QLiteHtmlWidgetWrapper::~QLiteHtmlWidgetWrapper()
{
    SbkObject *wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QLiteHtmlWidget_Init(PyObject *self, PyObject *args, PyObject *kwds)
{
    const char *argNames[] = {"parent"};
    const QMetaObject *metaObject;
    SbkObject *sbkSelf = reinterpret_cast<SbkObject *>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QLiteHtmlWidget >()))
        return -1;

    ::QLiteHtmlWidgetWrapper *cptr{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr };
    SBK_UNUSED(pythonToCpp)
    const Py_ssize_t numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|O:QLiteHtmlWidget", &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QLiteHtmlWidget::QLiteHtmlWidget(QWidget*)
    if (numArgs == 0) {
        overloadId = 0; // QLiteHtmlWidget(QWidget*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtWidgetsTypes[SBK_QWIDGET_IDX]), (pyArgs[0])))) {
        overloadId = 0; // QLiteHtmlWidget(QWidget*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLiteHtmlWidget_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject *keyName = nullptr;
            PyObject *value = nullptr;
            keyName = Py_BuildValue("s","parent");
            if (PyDict_Contains(kwds, keyName)) {
                value = PyDict_GetItem(kwds, keyName);
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide2.QLiteHtmlWidget.QLiteHtmlWidget(): got multiple values for keyword argument 'parent'.");
                    return -1;
                }
                if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtWidgetsTypes[SBK_QWIDGET_IDX]), (pyArgs[0]))))
                        goto Sbk_QLiteHtmlWidget_Init_TypeError;
                }
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return -1;
        ::QWidget *cppArg0 = nullptr;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
            // QLiteHtmlWidget(QWidget*)
            void *addr = PySide::nextQObjectMemoryAddr();
            if (addr) {
                cptr = new (addr) ::QLiteHtmlWidgetWrapper(cppArg0);
                PySide::setNextQObjectMemoryAddr(0);
            } else {
                cptr = new ::QLiteHtmlWidgetWrapper(cppArg0);
            }

            Shiboken::Object::setParent(pyArgs[0], self);
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QLiteHtmlWidget >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QLiteHtmlWidget_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    if (Shiboken::BindingManager::instance().hasWrapper(cptr)) {
        Shiboken::BindingManager::instance().releaseWrapper(Shiboken::BindingManager::instance().retrieveWrapper(cptr));
    }
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 1))
    return -1;


    return 1;

    Sbk_QLiteHtmlWidget_Init_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "PySide2.QLiteHtmlWidget.QLiteHtmlWidget");
        return -1;
}

static PyObject *Sbk_QLiteHtmlWidgetFunc_contextMenuEvent(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<QLiteHtmlWidgetWrapper *>(reinterpret_cast< ::QLiteHtmlWidget *>(Shiboken::Conversions::cppPointer(SbkPySide2_QLiteHtmlWidgetTypes[SBK_QLITEHTMLWIDGET_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: QWidget::contextMenuEvent(QContextMenuEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtGuiTypes[SBK_QCONTEXTMENUEVENT_IDX]), (pyArg)))) {
        overloadId = 0; // contextMenuEvent(QContextMenuEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLiteHtmlWidgetFunc_contextMenuEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return {};
        ::QContextMenuEvent *cppArg0;
        pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
            // contextMenuEvent(QContextMenuEvent*)
            static_cast<::QLiteHtmlWidgetWrapper *>(cppSelf)->QLiteHtmlWidgetWrapper::contextMenuEvent_protected(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_QLiteHtmlWidgetFunc_contextMenuEvent_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide2.QLiteHtmlWidget.QLiteHtmlWidget.contextMenuEvent");
        return {};
}

static PyObject *Sbk_QLiteHtmlWidgetFunc_defaultFont(PyObject *self)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<QLiteHtmlWidgetWrapper *>(reinterpret_cast< ::QLiteHtmlWidget *>(Shiboken::Conversions::cppPointer(SbkPySide2_QLiteHtmlWidgetTypes[SBK_QLITEHTMLWIDGET_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};

    // Call function/method
    {

            if (!PyErr_Occurred()) {
            // defaultFont()const
            QFont cppResult = const_cast<const ::QLiteHtmlWidgetWrapper *>(cppSelf)->defaultFont();
            pyResult = Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtGuiTypes[SBK_QFONT_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_QLiteHtmlWidgetFunc_findText(PyObject *self, PyObject *args, PyObject *kwds)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<QLiteHtmlWidgetWrapper *>(reinterpret_cast< ::QLiteHtmlWidget *>(Shiboken::Conversions::cppPointer(SbkPySide2_QLiteHtmlWidgetTypes[SBK_QLITEHTMLWIDGET_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    const Py_ssize_t numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    const Py_ssize_t numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide2.QLiteHtmlWidget.QLiteHtmlWidget.findText(): too many arguments");
        return {};
    } else if (numArgs < 3) {
        PyErr_SetString(PyExc_TypeError, "PySide2.QLiteHtmlWidget.QLiteHtmlWidget.findText(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OOOO:findText", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return {};


    // Overloaded function decisor
    // 0: QLiteHtmlWidget::findText(QString,QFlags<QTextDocument::FindFlag>,bool,bool*)
    if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(*PepType_SGTP(SbkPySide2_QtGuiTypes[SBK_QFLAGS_QTEXTDOCUMENT_FINDFLAG_IDX])->converter, (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // findText(QString,QFlags<QTextDocument::FindFlag>,bool,bool*)
        } else if (PyBool_Check(pyArgs[3]) && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[3])))) {
            overloadId = 0; // findText(QString,QFlags<QTextDocument::FindFlag>,bool,bool*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLiteHtmlWidgetFunc_findText_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject *keyName = nullptr;
            PyObject *value = nullptr;
            keyName = Py_BuildValue("s","wrapped");
            if (PyDict_Contains(kwds, keyName)) {
                value = PyDict_GetItem(kwds, keyName);
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide2.QLiteHtmlWidget.QLiteHtmlWidget.findText(): got multiple values for keyword argument 'wrapped'.");
                    return {};
                }
                if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[3]))))
                        goto Sbk_QLiteHtmlWidgetFunc_findText_TypeError;
                }
            }
        }
        ::QString cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QFlags<QTextDocument::FindFlag> cppArg1 = QFlags<QTextDocument::FindFlag>(0);
        pythonToCpp[1](pyArgs[1], &cppArg1);
        bool cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        bool *cppArg3 = nullptr;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
            // findText(QString,QFlags<QTextDocument::FindFlag>,bool,bool*)
            bool cppResult = cppSelf->findText(cppArg0, cppArg1, cppArg2, cppArg3);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_QLiteHtmlWidgetFunc_findText_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "PySide2.QLiteHtmlWidget.QLiteHtmlWidget.findText");
        return {};
}

static PyObject *Sbk_QLiteHtmlWidgetFunc_html(PyObject *self)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<QLiteHtmlWidgetWrapper *>(reinterpret_cast< ::QLiteHtmlWidget *>(Shiboken::Conversions::cppPointer(SbkPySide2_QLiteHtmlWidgetTypes[SBK_QLITEHTMLWIDGET_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};

    // Call function/method
    {

            if (!PyErr_Occurred()) {
            // html()const
            QString cppResult = const_cast<const ::QLiteHtmlWidgetWrapper *>(cppSelf)->html();
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_QLiteHtmlWidgetFunc_keyPressEvent(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<QLiteHtmlWidgetWrapper *>(reinterpret_cast< ::QLiteHtmlWidget *>(Shiboken::Conversions::cppPointer(SbkPySide2_QLiteHtmlWidgetTypes[SBK_QLITEHTMLWIDGET_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: QWidget::keyPressEvent(QKeyEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtGuiTypes[SBK_QKEYEVENT_IDX]), (pyArg)))) {
        overloadId = 0; // keyPressEvent(QKeyEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLiteHtmlWidgetFunc_keyPressEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return {};
        ::QKeyEvent *cppArg0;
        pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
            // keyPressEvent(QKeyEvent*)
            static_cast<::QLiteHtmlWidgetWrapper *>(cppSelf)->QLiteHtmlWidgetWrapper::keyPressEvent_protected(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_QLiteHtmlWidgetFunc_keyPressEvent_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide2.QLiteHtmlWidget.QLiteHtmlWidget.keyPressEvent");
        return {};
}

static PyObject *Sbk_QLiteHtmlWidgetFunc_leaveEvent(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<QLiteHtmlWidgetWrapper *>(reinterpret_cast< ::QLiteHtmlWidget *>(Shiboken::Conversions::cppPointer(SbkPySide2_QLiteHtmlWidgetTypes[SBK_QLITEHTMLWIDGET_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: QWidget::leaveEvent(QEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtCoreTypes[SBK_QEVENT_IDX]), (pyArg)))) {
        overloadId = 0; // leaveEvent(QEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLiteHtmlWidgetFunc_leaveEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return {};
        ::QEvent *cppArg0;
        pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
            // leaveEvent(QEvent*)
            static_cast<::QLiteHtmlWidgetWrapper *>(cppSelf)->QLiteHtmlWidgetWrapper::leaveEvent_protected(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_QLiteHtmlWidgetFunc_leaveEvent_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide2.QLiteHtmlWidget.QLiteHtmlWidget.leaveEvent");
        return {};
}

static PyObject *Sbk_QLiteHtmlWidgetFunc_mouseDoubleClickEvent(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<QLiteHtmlWidgetWrapper *>(reinterpret_cast< ::QLiteHtmlWidget *>(Shiboken::Conversions::cppPointer(SbkPySide2_QLiteHtmlWidgetTypes[SBK_QLITEHTMLWIDGET_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: QWidget::mouseDoubleClickEvent(QMouseEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtGuiTypes[SBK_QMOUSEEVENT_IDX]), (pyArg)))) {
        overloadId = 0; // mouseDoubleClickEvent(QMouseEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLiteHtmlWidgetFunc_mouseDoubleClickEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return {};
        ::QMouseEvent *cppArg0;
        pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
            // mouseDoubleClickEvent(QMouseEvent*)
            static_cast<::QLiteHtmlWidgetWrapper *>(cppSelf)->QLiteHtmlWidgetWrapper::mouseDoubleClickEvent_protected(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_QLiteHtmlWidgetFunc_mouseDoubleClickEvent_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide2.QLiteHtmlWidget.QLiteHtmlWidget.mouseDoubleClickEvent");
        return {};
}

static PyObject *Sbk_QLiteHtmlWidgetFunc_mouseMoveEvent(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<QLiteHtmlWidgetWrapper *>(reinterpret_cast< ::QLiteHtmlWidget *>(Shiboken::Conversions::cppPointer(SbkPySide2_QLiteHtmlWidgetTypes[SBK_QLITEHTMLWIDGET_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: QWidget::mouseMoveEvent(QMouseEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtGuiTypes[SBK_QMOUSEEVENT_IDX]), (pyArg)))) {
        overloadId = 0; // mouseMoveEvent(QMouseEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLiteHtmlWidgetFunc_mouseMoveEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return {};
        ::QMouseEvent *cppArg0;
        pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
            // mouseMoveEvent(QMouseEvent*)
            static_cast<::QLiteHtmlWidgetWrapper *>(cppSelf)->QLiteHtmlWidgetWrapper::mouseMoveEvent_protected(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_QLiteHtmlWidgetFunc_mouseMoveEvent_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide2.QLiteHtmlWidget.QLiteHtmlWidget.mouseMoveEvent");
        return {};
}

static PyObject *Sbk_QLiteHtmlWidgetFunc_mousePressEvent(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<QLiteHtmlWidgetWrapper *>(reinterpret_cast< ::QLiteHtmlWidget *>(Shiboken::Conversions::cppPointer(SbkPySide2_QLiteHtmlWidgetTypes[SBK_QLITEHTMLWIDGET_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: QWidget::mousePressEvent(QMouseEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtGuiTypes[SBK_QMOUSEEVENT_IDX]), (pyArg)))) {
        overloadId = 0; // mousePressEvent(QMouseEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLiteHtmlWidgetFunc_mousePressEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return {};
        ::QMouseEvent *cppArg0;
        pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
            // mousePressEvent(QMouseEvent*)
            static_cast<::QLiteHtmlWidgetWrapper *>(cppSelf)->QLiteHtmlWidgetWrapper::mousePressEvent_protected(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_QLiteHtmlWidgetFunc_mousePressEvent_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide2.QLiteHtmlWidget.QLiteHtmlWidget.mousePressEvent");
        return {};
}

static PyObject *Sbk_QLiteHtmlWidgetFunc_mouseReleaseEvent(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<QLiteHtmlWidgetWrapper *>(reinterpret_cast< ::QLiteHtmlWidget *>(Shiboken::Conversions::cppPointer(SbkPySide2_QLiteHtmlWidgetTypes[SBK_QLITEHTMLWIDGET_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: QWidget::mouseReleaseEvent(QMouseEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtGuiTypes[SBK_QMOUSEEVENT_IDX]), (pyArg)))) {
        overloadId = 0; // mouseReleaseEvent(QMouseEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLiteHtmlWidgetFunc_mouseReleaseEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return {};
        ::QMouseEvent *cppArg0;
        pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
            // mouseReleaseEvent(QMouseEvent*)
            static_cast<::QLiteHtmlWidgetWrapper *>(cppSelf)->QLiteHtmlWidgetWrapper::mouseReleaseEvent_protected(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_QLiteHtmlWidgetFunc_mouseReleaseEvent_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide2.QLiteHtmlWidget.QLiteHtmlWidget.mouseReleaseEvent");
        return {};
}

static PyObject *Sbk_QLiteHtmlWidgetFunc_paintEvent(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<QLiteHtmlWidgetWrapper *>(reinterpret_cast< ::QLiteHtmlWidget *>(Shiboken::Conversions::cppPointer(SbkPySide2_QLiteHtmlWidgetTypes[SBK_QLITEHTMLWIDGET_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: QWidget::paintEvent(QPaintEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtGuiTypes[SBK_QPAINTEVENT_IDX]), (pyArg)))) {
        overloadId = 0; // paintEvent(QPaintEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLiteHtmlWidgetFunc_paintEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return {};
        ::QPaintEvent *cppArg0;
        pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
            // paintEvent(QPaintEvent*)
            static_cast<::QLiteHtmlWidgetWrapper *>(cppSelf)->QLiteHtmlWidgetWrapper::paintEvent_protected(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_QLiteHtmlWidgetFunc_paintEvent_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide2.QLiteHtmlWidget.QLiteHtmlWidget.paintEvent");
        return {};
}

static PyObject *Sbk_QLiteHtmlWidgetFunc_resizeEvent(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<QLiteHtmlWidgetWrapper *>(reinterpret_cast< ::QLiteHtmlWidget *>(Shiboken::Conversions::cppPointer(SbkPySide2_QLiteHtmlWidgetTypes[SBK_QLITEHTMLWIDGET_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: QWidget::resizeEvent(QResizeEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtGuiTypes[SBK_QRESIZEEVENT_IDX]), (pyArg)))) {
        overloadId = 0; // resizeEvent(QResizeEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLiteHtmlWidgetFunc_resizeEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return {};
        ::QResizeEvent *cppArg0;
        pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
            // resizeEvent(QResizeEvent*)
            static_cast<::QLiteHtmlWidgetWrapper *>(cppSelf)->QLiteHtmlWidgetWrapper::resizeEvent_protected(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_QLiteHtmlWidgetFunc_resizeEvent_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide2.QLiteHtmlWidget.QLiteHtmlWidget.resizeEvent");
        return {};
}

static PyObject *Sbk_QLiteHtmlWidgetFunc_scrollToAnchor(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<QLiteHtmlWidgetWrapper *>(reinterpret_cast< ::QLiteHtmlWidget *>(Shiboken::Conversions::cppPointer(SbkPySide2_QLiteHtmlWidgetTypes[SBK_QLITEHTMLWIDGET_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: QLiteHtmlWidget::scrollToAnchor(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // scrollToAnchor(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLiteHtmlWidgetFunc_scrollToAnchor_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
            // scrollToAnchor(QString)
            cppSelf->scrollToAnchor(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_QLiteHtmlWidgetFunc_scrollToAnchor_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide2.QLiteHtmlWidget.QLiteHtmlWidget.scrollToAnchor");
        return {};
}

static PyObject *Sbk_QLiteHtmlWidgetFunc_selectedText(PyObject *self)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<QLiteHtmlWidgetWrapper *>(reinterpret_cast< ::QLiteHtmlWidget *>(Shiboken::Conversions::cppPointer(SbkPySide2_QLiteHtmlWidgetTypes[SBK_QLITEHTMLWIDGET_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};

    // Call function/method
    {

            if (!PyErr_Occurred()) {
            // selectedText()const
            QString cppResult = const_cast<const ::QLiteHtmlWidgetWrapper *>(cppSelf)->selectedText();
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_QLiteHtmlWidgetFunc_setAntialias(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<QLiteHtmlWidgetWrapper *>(reinterpret_cast< ::QLiteHtmlWidget *>(Shiboken::Conversions::cppPointer(SbkPySide2_QLiteHtmlWidgetTypes[SBK_QLITEHTMLWIDGET_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: QLiteHtmlWidget::setAntialias(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setAntialias(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLiteHtmlWidgetFunc_setAntialias_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
            // setAntialias(bool)
            cppSelf->setAntialias(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_QLiteHtmlWidgetFunc_setAntialias_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide2.QLiteHtmlWidget.QLiteHtmlWidget.setAntialias");
        return {};
}

static PyObject *Sbk_QLiteHtmlWidgetFunc_setDefaultFont(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<QLiteHtmlWidgetWrapper *>(reinterpret_cast< ::QLiteHtmlWidget *>(Shiboken::Conversions::cppPointer(SbkPySide2_QLiteHtmlWidgetTypes[SBK_QLITEHTMLWIDGET_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: QLiteHtmlWidget::setDefaultFont(QFont)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtGuiTypes[SBK_QFONT_IDX]), (pyArg)))) {
        overloadId = 0; // setDefaultFont(QFont)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLiteHtmlWidgetFunc_setDefaultFont_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return {};
        ::QFont cppArg0_local;
        ::QFont *cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtGuiTypes[SBK_QFONT_IDX]), pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
            // setDefaultFont(QFont)
            cppSelf->setDefaultFont(*cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_QLiteHtmlWidgetFunc_setDefaultFont_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide2.QLiteHtmlWidget.QLiteHtmlWidget.setDefaultFont");
        return {};
}

static PyObject *Sbk_QLiteHtmlWidgetFunc_setHtml(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<QLiteHtmlWidgetWrapper *>(reinterpret_cast< ::QLiteHtmlWidget *>(Shiboken::Conversions::cppPointer(SbkPySide2_QLiteHtmlWidgetTypes[SBK_QLITEHTMLWIDGET_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: QLiteHtmlWidget::setHtml(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setHtml(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLiteHtmlWidgetFunc_setHtml_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
            // setHtml(QString)
            cppSelf->setHtml(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_QLiteHtmlWidgetFunc_setHtml_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide2.QLiteHtmlWidget.QLiteHtmlWidget.setHtml");
        return {};
}

static PyObject *Sbk_QLiteHtmlWidgetFunc_setUrl(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<QLiteHtmlWidgetWrapper *>(reinterpret_cast< ::QLiteHtmlWidget *>(Shiboken::Conversions::cppPointer(SbkPySide2_QLiteHtmlWidgetTypes[SBK_QLITEHTMLWIDGET_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: QLiteHtmlWidget::setUrl(QUrl)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtCoreTypes[SBK_QURL_IDX]), (pyArg)))) {
        overloadId = 0; // setUrl(QUrl)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLiteHtmlWidgetFunc_setUrl_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return {};
        ::QUrl cppArg0_local;
        ::QUrl *cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtCoreTypes[SBK_QURL_IDX]), pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
            // setUrl(QUrl)
            cppSelf->setUrl(*cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_QLiteHtmlWidgetFunc_setUrl_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide2.QLiteHtmlWidget.QLiteHtmlWidget.setUrl");
        return {};
}

static PyObject *Sbk_QLiteHtmlWidgetFunc_setZoomFactor(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<QLiteHtmlWidgetWrapper *>(reinterpret_cast< ::QLiteHtmlWidget *>(Shiboken::Conversions::cppPointer(SbkPySide2_QLiteHtmlWidgetTypes[SBK_QLITEHTMLWIDGET_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: QLiteHtmlWidget::setZoomFactor(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setZoomFactor(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLiteHtmlWidgetFunc_setZoomFactor_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
            // setZoomFactor(qreal)
            cppSelf->setZoomFactor(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_QLiteHtmlWidgetFunc_setZoomFactor_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide2.QLiteHtmlWidget.QLiteHtmlWidget.setZoomFactor");
        return {};
}

static PyObject *Sbk_QLiteHtmlWidgetFunc_title(PyObject *self)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<QLiteHtmlWidgetWrapper *>(reinterpret_cast< ::QLiteHtmlWidget *>(Shiboken::Conversions::cppPointer(SbkPySide2_QLiteHtmlWidgetTypes[SBK_QLITEHTMLWIDGET_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};

    // Call function/method
    {

            if (!PyErr_Occurred()) {
            // title()const
            QString cppResult = const_cast<const ::QLiteHtmlWidgetWrapper *>(cppSelf)->title();
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_QLiteHtmlWidgetFunc_url(PyObject *self)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<QLiteHtmlWidgetWrapper *>(reinterpret_cast< ::QLiteHtmlWidget *>(Shiboken::Conversions::cppPointer(SbkPySide2_QLiteHtmlWidgetTypes[SBK_QLITEHTMLWIDGET_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};

    // Call function/method
    {

            if (!PyErr_Occurred()) {
            // url()const
            QUrl cppResult = const_cast<const ::QLiteHtmlWidgetWrapper *>(cppSelf)->url();
            pyResult = Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtCoreTypes[SBK_QURL_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_QLiteHtmlWidgetFunc_zoomFactor(PyObject *self)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<QLiteHtmlWidgetWrapper *>(reinterpret_cast< ::QLiteHtmlWidget *>(Shiboken::Conversions::cppPointer(SbkPySide2_QLiteHtmlWidgetTypes[SBK_QLITEHTMLWIDGET_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};

    // Call function/method
    {

            if (!PyErr_Occurred()) {
            // zoomFactor()const
            qreal cppResult = const_cast<const ::QLiteHtmlWidgetWrapper *>(cppSelf)->zoomFactor();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}


static const char *Sbk_QLiteHtmlWidget_PropertyStrings[] = {
    nullptr // Sentinel
};

static PyMethodDef Sbk_QLiteHtmlWidget_methods[] = {
    {"contextMenuEvent", reinterpret_cast<PyCFunction>(Sbk_QLiteHtmlWidgetFunc_contextMenuEvent), METH_O},
    {"defaultFont", reinterpret_cast<PyCFunction>(Sbk_QLiteHtmlWidgetFunc_defaultFont), METH_NOARGS},
    {"findText", reinterpret_cast<PyCFunction>(Sbk_QLiteHtmlWidgetFunc_findText), METH_VARARGS|METH_KEYWORDS},
    {"html", reinterpret_cast<PyCFunction>(Sbk_QLiteHtmlWidgetFunc_html), METH_NOARGS},
    {"keyPressEvent", reinterpret_cast<PyCFunction>(Sbk_QLiteHtmlWidgetFunc_keyPressEvent), METH_O},
    {"leaveEvent", reinterpret_cast<PyCFunction>(Sbk_QLiteHtmlWidgetFunc_leaveEvent), METH_O},
    {"mouseDoubleClickEvent", reinterpret_cast<PyCFunction>(Sbk_QLiteHtmlWidgetFunc_mouseDoubleClickEvent), METH_O},
    {"mouseMoveEvent", reinterpret_cast<PyCFunction>(Sbk_QLiteHtmlWidgetFunc_mouseMoveEvent), METH_O},
    {"mousePressEvent", reinterpret_cast<PyCFunction>(Sbk_QLiteHtmlWidgetFunc_mousePressEvent), METH_O},
    {"mouseReleaseEvent", reinterpret_cast<PyCFunction>(Sbk_QLiteHtmlWidgetFunc_mouseReleaseEvent), METH_O},
    {"paintEvent", reinterpret_cast<PyCFunction>(Sbk_QLiteHtmlWidgetFunc_paintEvent), METH_O},
    {"resizeEvent", reinterpret_cast<PyCFunction>(Sbk_QLiteHtmlWidgetFunc_resizeEvent), METH_O},
    {"scrollToAnchor", reinterpret_cast<PyCFunction>(Sbk_QLiteHtmlWidgetFunc_scrollToAnchor), METH_O},
    {"selectedText", reinterpret_cast<PyCFunction>(Sbk_QLiteHtmlWidgetFunc_selectedText), METH_NOARGS},
    {"setAntialias", reinterpret_cast<PyCFunction>(Sbk_QLiteHtmlWidgetFunc_setAntialias), METH_O},
    {"setDefaultFont", reinterpret_cast<PyCFunction>(Sbk_QLiteHtmlWidgetFunc_setDefaultFont), METH_O},
    {"setHtml", reinterpret_cast<PyCFunction>(Sbk_QLiteHtmlWidgetFunc_setHtml), METH_O},
    {"setUrl", reinterpret_cast<PyCFunction>(Sbk_QLiteHtmlWidgetFunc_setUrl), METH_O},
    {"setZoomFactor", reinterpret_cast<PyCFunction>(Sbk_QLiteHtmlWidgetFunc_setZoomFactor), METH_O},
    {"title", reinterpret_cast<PyCFunction>(Sbk_QLiteHtmlWidgetFunc_title), METH_NOARGS},
    {"url", reinterpret_cast<PyCFunction>(Sbk_QLiteHtmlWidgetFunc_url), METH_NOARGS},
    {"zoomFactor", reinterpret_cast<PyCFunction>(Sbk_QLiteHtmlWidgetFunc_zoomFactor), METH_NOARGS},

    {nullptr, nullptr} // Sentinel
};

static int Sbk_QLiteHtmlWidget_setattro(PyObject *self, PyObject *name, PyObject *value)
{
    PySide::Feature::Select(self);
    if (value && PyCallable_Check(value)) {
        auto plain_inst = reinterpret_cast< ::QLiteHtmlWidget *>(Shiboken::Conversions::cppPointer(SbkPySide2_QLiteHtmlWidgetTypes[SBK_QLITEHTMLWIDGET_IDX], reinterpret_cast<SbkObject *>(self)));
        auto inst = dynamic_cast<QLiteHtmlWidgetWrapper *>(plain_inst);
        if (inst)
            inst->resetPyMethodCache();
    }
    Shiboken::AutoDecRef pp(reinterpret_cast<PyObject *>(PySide::Property::getObject(self, name)));
    if (!pp.isNull())
        return PySide::Property::setValue(reinterpret_cast<PySideProperty *>(pp.object()), self, value);
    return PyObject_GenericSetAttr(self, name, value);
}

} // extern "C"

static int Sbk_QLiteHtmlWidget_traverse(PyObject *self, visitproc visit, void *arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_QLiteHtmlWidget_clear(PyObject *self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
static void * Sbk_QLiteHtmlWidgetSpecialCastFunction(void *obj, SbkObjectType *desiredType)
{
    auto me = reinterpret_cast< ::QLiteHtmlWidget *>(obj);
    if (desiredType == reinterpret_cast<SbkObjectType *>(SbkPySide2_QtWidgetsTypes[SBK_QABSTRACTSCROLLAREA_IDX]))
        return static_cast< ::QAbstractScrollArea *>(me);
    else if (desiredType == reinterpret_cast<SbkObjectType *>(SbkPySide2_QtWidgetsTypes[SBK_QFRAME_IDX]))
        return static_cast< ::QFrame *>(me);
    else if (desiredType == reinterpret_cast<SbkObjectType *>(SbkPySide2_QtWidgetsTypes[SBK_QWIDGET_IDX]))
        return static_cast< ::QWidget *>(me);
    else if (desiredType == reinterpret_cast<SbkObjectType *>(SbkPySide2_QtCoreTypes[SBK_QOBJECT_IDX]))
        return static_cast< ::QObject *>(me);
    else if (desiredType == reinterpret_cast<SbkObjectType *>(SbkPySide2_QtGuiTypes[SBK_QPAINTDEVICE_IDX]))
        return static_cast< ::QPaintDevice *>(me);
    return me;
}


// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_QLiteHtmlWidget_Type = nullptr;
static SbkObjectType *Sbk_QLiteHtmlWidget_TypeF(void)
{
    return _Sbk_QLiteHtmlWidget_Type;
}

static PyType_Slot Sbk_QLiteHtmlWidget_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void *>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    reinterpret_cast<void *>(Sbk_QLiteHtmlWidget_setattro)},
    {Py_tp_traverse,    reinterpret_cast<void *>(Sbk_QLiteHtmlWidget_traverse)},
    {Py_tp_clear,       reinterpret_cast<void *>(Sbk_QLiteHtmlWidget_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void *>(Sbk_QLiteHtmlWidget_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        reinterpret_cast<void *>(Sbk_QLiteHtmlWidget_Init)},
    {Py_tp_new,         reinterpret_cast<void *>(SbkObjectTpNew)},
    {0, nullptr}
};
static PyType_Spec Sbk_QLiteHtmlWidget_spec = {
    "2:PySide2.QLiteHtmlWidget.QLiteHtmlWidget",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_QLiteHtmlWidget_slots
};

} //extern "C"

static void *Sbk_QLiteHtmlWidget_typeDiscovery(void *cptr, SbkObjectType *instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType *>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QLiteHtmlWidget *>(reinterpret_cast< ::QObject *>(cptr));
    if (instanceType == reinterpret_cast<SbkObjectType *>(Shiboken::SbkType< ::QPaintDevice >()))
        return dynamic_cast< ::QLiteHtmlWidget *>(reinterpret_cast< ::QPaintDevice *>(cptr));
    return {};
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QLiteHtmlWidget_PythonToCpp_QLiteHtmlWidget_PTR(PyObject *pyIn, void *cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_QLiteHtmlWidget_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_QLiteHtmlWidget_PythonToCpp_QLiteHtmlWidget_PTR_Convertible(PyObject *pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject *>(Sbk_QLiteHtmlWidget_TypeF())))
        return QLiteHtmlWidget_PythonToCpp_QLiteHtmlWidget_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject *QLiteHtmlWidget_PTR_CppToPython_QLiteHtmlWidget(const void *cppIn) {
    return PySide::getWrapperForQObject(reinterpret_cast<::QLiteHtmlWidget *>(const_cast<void *>(cppIn)), Sbk_QLiteHtmlWidget_TypeF());

}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *QLiteHtmlWidget_SignatureStrings[] = {
    "PySide2.QLiteHtmlWidget.QLiteHtmlWidget(self,parent:PySide2.QtWidgets.QWidget=nullptr)",
    "PySide2.QLiteHtmlWidget.QLiteHtmlWidget.contextMenuEvent(self,event:PySide2.QtGui.QContextMenuEvent)",
    "PySide2.QLiteHtmlWidget.QLiteHtmlWidget.defaultFont(self)->PySide2.QtGui.QFont",
    "PySide2.QLiteHtmlWidget.QLiteHtmlWidget.findText(self,text:QString,flags:PySide2.QtGui.QTextDocument.FindFlags,incremental:bool,wrapped:bool*=nullptr)->bool",
    "PySide2.QLiteHtmlWidget.QLiteHtmlWidget.html(self)->QString",
    "PySide2.QLiteHtmlWidget.QLiteHtmlWidget.keyPressEvent(self,event:PySide2.QtGui.QKeyEvent)",
    "PySide2.QLiteHtmlWidget.QLiteHtmlWidget.leaveEvent(self,event:PySide2.QtCore.QEvent)",
    "PySide2.QLiteHtmlWidget.QLiteHtmlWidget.mouseDoubleClickEvent(self,event:PySide2.QtGui.QMouseEvent)",
    "PySide2.QLiteHtmlWidget.QLiteHtmlWidget.mouseMoveEvent(self,event:PySide2.QtGui.QMouseEvent)",
    "PySide2.QLiteHtmlWidget.QLiteHtmlWidget.mousePressEvent(self,event:PySide2.QtGui.QMouseEvent)",
    "PySide2.QLiteHtmlWidget.QLiteHtmlWidget.mouseReleaseEvent(self,event:PySide2.QtGui.QMouseEvent)",
    "PySide2.QLiteHtmlWidget.QLiteHtmlWidget.paintEvent(self,event:PySide2.QtGui.QPaintEvent)",
    "PySide2.QLiteHtmlWidget.QLiteHtmlWidget.resizeEvent(self,event:PySide2.QtGui.QResizeEvent)",
    "PySide2.QLiteHtmlWidget.QLiteHtmlWidget.scrollToAnchor(self,name:QString)",
    "PySide2.QLiteHtmlWidget.QLiteHtmlWidget.selectedText(self)->QString",
    "PySide2.QLiteHtmlWidget.QLiteHtmlWidget.setAntialias(self,on:bool)",
    "PySide2.QLiteHtmlWidget.QLiteHtmlWidget.setDefaultFont(self,font:PySide2.QtGui.QFont)",
    "PySide2.QLiteHtmlWidget.QLiteHtmlWidget.setHtml(self,content:QString)",
    "PySide2.QLiteHtmlWidget.QLiteHtmlWidget.setUrl(self,url:PySide2.QtCore.QUrl)",
    "PySide2.QLiteHtmlWidget.QLiteHtmlWidget.setZoomFactor(self,scale:qreal)",
    "PySide2.QLiteHtmlWidget.QLiteHtmlWidget.title(self)->QString",
    "PySide2.QLiteHtmlWidget.QLiteHtmlWidget.url(self)->PySide2.QtCore.QUrl",
    "PySide2.QLiteHtmlWidget.QLiteHtmlWidget.zoomFactor(self)->qreal",
    nullptr}; // Sentinel

void init_QLiteHtmlWidget(PyObject *module)
{
    _Sbk_QLiteHtmlWidget_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "QLiteHtmlWidget",
        "QLiteHtmlWidget*",
        &Sbk_QLiteHtmlWidget_spec,
        &Shiboken::callCppDestructor< ::QLiteHtmlWidget >,
        reinterpret_cast<SbkObjectType *>(SbkPySide2_QtWidgetsTypes[SBK_QABSTRACTSCROLLAREA_IDX]),
        0,
        Shiboken::ObjectType::WrapperFlags::DeleteInMainThread    );
    
    auto pyType = reinterpret_cast<PyTypeObject *>(_Sbk_QLiteHtmlWidget_Type);
    InitSignatureStrings(pyType, QLiteHtmlWidget_SignatureStrings);
    SbkObjectType_SetPropertyStrings(reinterpret_cast<PyTypeObject *>(_Sbk_QLiteHtmlWidget_Type), Sbk_QLiteHtmlWidget_PropertyStrings);
    SbkPySide2_QLiteHtmlWidgetTypes[SBK_QLITEHTMLWIDGET_IDX]
        = reinterpret_cast<PyTypeObject *>(Sbk_QLiteHtmlWidget_TypeF());

    // Register Converter
    SbkConverter *converter = Shiboken::Conversions::createConverter(Sbk_QLiteHtmlWidget_TypeF(),
        QLiteHtmlWidget_PythonToCpp_QLiteHtmlWidget_PTR,
        is_QLiteHtmlWidget_PythonToCpp_QLiteHtmlWidget_PTR_Convertible,
        QLiteHtmlWidget_PTR_CppToPython_QLiteHtmlWidget);

    Shiboken::Conversions::registerConverterName(converter, "QLiteHtmlWidget");
    Shiboken::Conversions::registerConverterName(converter, "QLiteHtmlWidget*");
    Shiboken::Conversions::registerConverterName(converter, "QLiteHtmlWidget&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QLiteHtmlWidget).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QLiteHtmlWidgetWrapper).name());


    MultipleInheritanceInitFunction func = Shiboken::ObjectType::getMultipleInheritanceFunction(reinterpret_cast<SbkObjectType *>(SbkPySide2_QtWidgetsTypes[SBK_QWIDGET_IDX]));
    Shiboken::ObjectType::setMultipleInheritanceFunction(Sbk_QLiteHtmlWidget_TypeF(), func);
    Shiboken::ObjectType::setCastFunction(Sbk_QLiteHtmlWidget_TypeF(), &Sbk_QLiteHtmlWidgetSpecialCastFunction);
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_QLiteHtmlWidget_TypeF(), &Sbk_QLiteHtmlWidget_typeDiscovery);

    PySide::Signal::registerSignals(Sbk_QLiteHtmlWidget_TypeF(), &::QLiteHtmlWidget::staticMetaObject);

    QLiteHtmlWidgetWrapper::pysideInitQtMetaTypes();
    Shiboken::ObjectType::setSubTypeInitHook(Sbk_QLiteHtmlWidget_TypeF(), &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(Sbk_QLiteHtmlWidget_TypeF(), &::QLiteHtmlWidget::staticMetaObject, sizeof(QLiteHtmlWidgetWrapper));
}
