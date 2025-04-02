#ifndef SBK_QLITEHTMLWIDGETWRAPPER_H
#define SBK_QLITEHTMLWIDGETWRAPPER_H

#include <qlitehtmlwidget.h>


// Extra includes
#include <qobject.h>
#include <qwidget.h>
#include <qurl.h>
#include <qfont.h>
#include <qpoint.h>
#include <qsize.h>
#include <qrect.h>
#include <qmargins.h>
#include <qobjectdefs.h>
#include <qbytearray.h>
#include <qpaintdevice.h>
#include <QList>
namespace PySide { class DynamicQMetaObject; }

class QLiteHtmlWidgetWrapper : public QLiteHtmlWidget
{
public:
    QLiteHtmlWidgetWrapper(QWidget * parent = nullptr);
    inline void actionEvent_protected(QActionEvent * event) { QLiteHtmlWidget::actionEvent(event); }
    void actionEvent(QActionEvent * event) override;
    inline void changeEvent_protected(QEvent * arg__1) { QLiteHtmlWidget::changeEvent(arg__1); }
    void changeEvent(QEvent * arg__1) override;
    inline void childEvent_protected(QChildEvent * event) { QLiteHtmlWidget::childEvent(event); }
    void childEvent(QChildEvent * event) override;
    inline void closeEvent_protected(QCloseEvent * event) { QLiteHtmlWidget::closeEvent(event); }
    void closeEvent(QCloseEvent * event) override;
    inline void connectNotify_protected(const QMetaMethod & signal) { QLiteHtmlWidget::connectNotify(signal); }
    void connectNotify(const QMetaMethod & signal) override;
    inline void contextMenuEvent_protected(QContextMenuEvent * event) { QLiteHtmlWidget::contextMenuEvent(event); }
    void contextMenuEvent(QContextMenuEvent * event) override;
    inline void customEvent_protected(QEvent * event) { QLiteHtmlWidget::customEvent(event); }
    void customEvent(QEvent * event) override;
    int devType() const override;
    inline void disconnectNotify_protected(const QMetaMethod & signal) { QLiteHtmlWidget::disconnectNotify(signal); }
    void disconnectNotify(const QMetaMethod & signal) override;
    inline void dragEnterEvent_protected(QDragEnterEvent * arg__1) { QLiteHtmlWidget::dragEnterEvent(arg__1); }
    void dragEnterEvent(QDragEnterEvent * arg__1) override;
    inline void dragLeaveEvent_protected(QDragLeaveEvent * arg__1) { QLiteHtmlWidget::dragLeaveEvent(arg__1); }
    void dragLeaveEvent(QDragLeaveEvent * arg__1) override;
    inline void dragMoveEvent_protected(QDragMoveEvent * arg__1) { QLiteHtmlWidget::dragMoveEvent(arg__1); }
    void dragMoveEvent(QDragMoveEvent * arg__1) override;
    inline void dropEvent_protected(QDropEvent * arg__1) { QLiteHtmlWidget::dropEvent(arg__1); }
    void dropEvent(QDropEvent * arg__1) override;
    inline void enterEvent_protected(QEvent * event) { QLiteHtmlWidget::enterEvent(event); }
    void enterEvent(QEvent * event) override;
    inline bool event_protected(QEvent * arg__1) { return QLiteHtmlWidget::event(arg__1); }
    bool event(QEvent * arg__1) override;
    inline bool eventFilter_protected(QObject * arg__1, QEvent * arg__2) { return QLiteHtmlWidget::eventFilter(arg__1, arg__2); }
    bool eventFilter(QObject * arg__1, QEvent * arg__2) override;
    inline void focusInEvent_protected(QFocusEvent * event) { QLiteHtmlWidget::focusInEvent(event); }
    void focusInEvent(QFocusEvent * event) override;
    inline bool focusNextPrevChild_protected(bool next) { return QLiteHtmlWidget::focusNextPrevChild(next); }
    bool focusNextPrevChild(bool next) override;
    inline void focusOutEvent_protected(QFocusEvent * event) { QLiteHtmlWidget::focusOutEvent(event); }
    void focusOutEvent(QFocusEvent * event) override;
    bool hasHeightForWidth() const override;
    int heightForWidth(int arg__1) const override;
    inline void hideEvent_protected(QHideEvent * event) { QLiteHtmlWidget::hideEvent(event); }
    void hideEvent(QHideEvent * event) override;
    inline void initPainter_protected(QPainter * painter) const { QLiteHtmlWidget::initPainter(painter); }
    void initPainter(QPainter * painter) const override;
    inline void inputMethodEvent_protected(QInputMethodEvent * event) { QLiteHtmlWidget::inputMethodEvent(event); }
    void inputMethodEvent(QInputMethodEvent * event) override;
    QVariant inputMethodQuery(Qt::InputMethodQuery arg__1) const override;
    inline void keyPressEvent_protected(QKeyEvent * event) { QLiteHtmlWidget::keyPressEvent(event); }
    void keyPressEvent(QKeyEvent * event) override;
    inline void keyReleaseEvent_protected(QKeyEvent * event) { QLiteHtmlWidget::keyReleaseEvent(event); }
    void keyReleaseEvent(QKeyEvent * event) override;
    inline void leaveEvent_protected(QEvent * event) { QLiteHtmlWidget::leaveEvent(event); }
    void leaveEvent(QEvent * event) override;
    const QMetaObject * metaObject() const override;
    inline int metric_protected(QPaintDevice::PaintDeviceMetric arg__1) const { return QLiteHtmlWidget::metric(QPaintDevice::PaintDeviceMetric(arg__1)); }
    int metric(QPaintDevice::PaintDeviceMetric arg__1) const override;
    QSize minimumSizeHint() const override;
    inline void mouseDoubleClickEvent_protected(QMouseEvent * event) { QLiteHtmlWidget::mouseDoubleClickEvent(event); }
    void mouseDoubleClickEvent(QMouseEvent * event) override;
    inline void mouseMoveEvent_protected(QMouseEvent * event) { QLiteHtmlWidget::mouseMoveEvent(event); }
    void mouseMoveEvent(QMouseEvent * event) override;
    inline void mousePressEvent_protected(QMouseEvent * event) { QLiteHtmlWidget::mousePressEvent(event); }
    void mousePressEvent(QMouseEvent * event) override;
    inline void mouseReleaseEvent_protected(QMouseEvent * event) { QLiteHtmlWidget::mouseReleaseEvent(event); }
    void mouseReleaseEvent(QMouseEvent * event) override;
    inline void moveEvent_protected(QMoveEvent * event) { QLiteHtmlWidget::moveEvent(event); }
    void moveEvent(QMoveEvent * event) override;
    inline bool nativeEvent_protected(const QByteArray & eventType, void * message, long * result) { return QLiteHtmlWidget::nativeEvent(eventType, message, result); }
    bool nativeEvent(const QByteArray & eventType, void * message, long * result) override;
    QPaintEngine * paintEngine() const override;
    inline void paintEvent_protected(QPaintEvent * event) { QLiteHtmlWidget::paintEvent(event); }
    void paintEvent(QPaintEvent * event) override;
    inline QPaintDevice * redirected_protected(QPoint * offset) const { return QLiteHtmlWidget::redirected(offset); }
    QPaintDevice * redirected(QPoint * offset) const override;
    inline void resizeEvent_protected(QResizeEvent * event) { QLiteHtmlWidget::resizeEvent(event); }
    void resizeEvent(QResizeEvent * event) override;
    inline void scrollContentsBy_protected(int dx, int dy) { QLiteHtmlWidget::scrollContentsBy(dx, dy); }
    void scrollContentsBy(int dx, int dy) override;
    inline void setViewportMargins_protected(const QMargins & margins) { QLiteHtmlWidget::setViewportMargins(margins); }
    inline void setViewportMargins_protected(int left, int top, int right, int bottom) { QLiteHtmlWidget::setViewportMargins(left, top, right, bottom); }
    void setVisible(bool visible) override;
    void setupViewport(QWidget * viewport) override;
    inline QPainter * sharedPainter_protected() const { return QLiteHtmlWidget::sharedPainter(); }
    QPainter * sharedPainter() const override;
    inline void showEvent_protected(QShowEvent * event) { QLiteHtmlWidget::showEvent(event); }
    void showEvent(QShowEvent * event) override;
    QSize sizeHint() const override;
    inline void tabletEvent_protected(QTabletEvent * event) { QLiteHtmlWidget::tabletEvent(event); }
    void tabletEvent(QTabletEvent * event) override;
    inline void timerEvent_protected(QTimerEvent * event) { QLiteHtmlWidget::timerEvent(event); }
    void timerEvent(QTimerEvent * event) override;
    inline bool viewportEvent_protected(QEvent * arg__1) { return QLiteHtmlWidget::viewportEvent(arg__1); }
    bool viewportEvent(QEvent * arg__1) override;
    inline QMargins viewportMargins_protected() const { return QLiteHtmlWidget::viewportMargins(); }
    inline QSize viewportSizeHint_protected() const { return QLiteHtmlWidget::viewportSizeHint(); }
    QSize viewportSizeHint() const override;
    inline void wheelEvent_protected(QWheelEvent * arg__1) { QLiteHtmlWidget::wheelEvent(arg__1); }
    void wheelEvent(QWheelEvent * arg__1) override;
    ~QLiteHtmlWidgetWrapper();
public:
    int qt_metacall(QMetaObject::Call call, int id, void **args) override;
    void *qt_metacast(const char *_clname) override;
    static void pysideInitQtMetaTypes();
    void resetPyMethodCache();
private:
    mutable bool m_PyMethodCache[52];
};

#  ifndef SBK_QABSTRACTSCROLLAREAWRAPPER_H
#  define SBK_QABSTRACTSCROLLAREAWRAPPER_H

// Inherited base class:
class QAbstractScrollAreaWrapper : public QAbstractScrollArea
{
public:
    QAbstractScrollAreaWrapper(QWidget * parent = nullptr);
    inline void actionEvent_protected(QActionEvent * event) { QAbstractScrollArea::actionEvent(event); }
    void actionEvent(QActionEvent * event) override;
    inline void changeEvent_protected(QEvent * arg__1) { QAbstractScrollArea::changeEvent(arg__1); }
    void changeEvent(QEvent * arg__1) override;
    inline void childEvent_protected(QChildEvent * event) { QAbstractScrollArea::childEvent(event); }
    void childEvent(QChildEvent * event) override;
    inline void closeEvent_protected(QCloseEvent * event) { QAbstractScrollArea::closeEvent(event); }
    void closeEvent(QCloseEvent * event) override;
    inline void connectNotify_protected(const QMetaMethod & signal) { QAbstractScrollArea::connectNotify(signal); }
    void connectNotify(const QMetaMethod & signal) override;
    inline void contextMenuEvent_protected(QContextMenuEvent * arg__1) { QAbstractScrollArea::contextMenuEvent(arg__1); }
    void contextMenuEvent(QContextMenuEvent * arg__1) override;
    inline void customEvent_protected(QEvent * event) { QAbstractScrollArea::customEvent(event); }
    void customEvent(QEvent * event) override;
    int devType() const override;
    inline void disconnectNotify_protected(const QMetaMethod & signal) { QAbstractScrollArea::disconnectNotify(signal); }
    void disconnectNotify(const QMetaMethod & signal) override;
    inline void dragEnterEvent_protected(QDragEnterEvent * arg__1) { QAbstractScrollArea::dragEnterEvent(arg__1); }
    void dragEnterEvent(QDragEnterEvent * arg__1) override;
    inline void dragLeaveEvent_protected(QDragLeaveEvent * arg__1) { QAbstractScrollArea::dragLeaveEvent(arg__1); }
    void dragLeaveEvent(QDragLeaveEvent * arg__1) override;
    inline void dragMoveEvent_protected(QDragMoveEvent * arg__1) { QAbstractScrollArea::dragMoveEvent(arg__1); }
    void dragMoveEvent(QDragMoveEvent * arg__1) override;
    inline void drawFrame_protected(QPainter * arg__1) { QAbstractScrollArea::drawFrame(arg__1); }
    inline void dropEvent_protected(QDropEvent * arg__1) { QAbstractScrollArea::dropEvent(arg__1); }
    void dropEvent(QDropEvent * arg__1) override;
    inline void enterEvent_protected(QEvent * event) { QAbstractScrollArea::enterEvent(event); }
    void enterEvent(QEvent * event) override;
    inline bool event_protected(QEvent * arg__1) { return QAbstractScrollArea::event(arg__1); }
    bool event(QEvent * arg__1) override;
    inline bool eventFilter_protected(QObject * arg__1, QEvent * arg__2) { return QAbstractScrollArea::eventFilter(arg__1, arg__2); }
    bool eventFilter(QObject * arg__1, QEvent * arg__2) override;
    inline void focusInEvent_protected(QFocusEvent * event) { QAbstractScrollArea::focusInEvent(event); }
    void focusInEvent(QFocusEvent * event) override;
    inline bool focusNextPrevChild_protected(bool next) { return QAbstractScrollArea::focusNextPrevChild(next); }
    bool focusNextPrevChild(bool next) override;
    inline void focusOutEvent_protected(QFocusEvent * event) { QAbstractScrollArea::focusOutEvent(event); }
    void focusOutEvent(QFocusEvent * event) override;
    bool hasHeightForWidth() const override;
    int heightForWidth(int arg__1) const override;
    inline void hideEvent_protected(QHideEvent * event) { QAbstractScrollArea::hideEvent(event); }
    void hideEvent(QHideEvent * event) override;
    inline void initPainter_protected(QPainter * painter) const { QAbstractScrollArea::initPainter(painter); }
    void initPainter(QPainter * painter) const override;
    inline void initStyleOption_protected(QStyleOptionFrame * option) const { QAbstractScrollArea::initStyleOption(option); }
    inline void inputMethodEvent_protected(QInputMethodEvent * event) { QAbstractScrollArea::inputMethodEvent(event); }
    void inputMethodEvent(QInputMethodEvent * event) override;
    QVariant inputMethodQuery(Qt::InputMethodQuery arg__1) const override;
    inline void keyPressEvent_protected(QKeyEvent * arg__1) { QAbstractScrollArea::keyPressEvent(arg__1); }
    void keyPressEvent(QKeyEvent * arg__1) override;
    inline void keyReleaseEvent_protected(QKeyEvent * event) { QAbstractScrollArea::keyReleaseEvent(event); }
    void keyReleaseEvent(QKeyEvent * event) override;
    inline void leaveEvent_protected(QEvent * event) { QAbstractScrollArea::leaveEvent(event); }
    void leaveEvent(QEvent * event) override;
    const QMetaObject * metaObject() const override;
    inline int metric_protected(QPaintDevice::PaintDeviceMetric arg__1) const { return QAbstractScrollArea::metric(QPaintDevice::PaintDeviceMetric(arg__1)); }
    int metric(QPaintDevice::PaintDeviceMetric arg__1) const override;
    QSize minimumSizeHint() const override;
    inline void mouseDoubleClickEvent_protected(QMouseEvent * arg__1) { QAbstractScrollArea::mouseDoubleClickEvent(arg__1); }
    void mouseDoubleClickEvent(QMouseEvent * arg__1) override;
    inline void mouseMoveEvent_protected(QMouseEvent * arg__1) { QAbstractScrollArea::mouseMoveEvent(arg__1); }
    void mouseMoveEvent(QMouseEvent * arg__1) override;
    inline void mousePressEvent_protected(QMouseEvent * arg__1) { QAbstractScrollArea::mousePressEvent(arg__1); }
    void mousePressEvent(QMouseEvent * arg__1) override;
    inline void mouseReleaseEvent_protected(QMouseEvent * arg__1) { QAbstractScrollArea::mouseReleaseEvent(arg__1); }
    void mouseReleaseEvent(QMouseEvent * arg__1) override;
    inline void moveEvent_protected(QMoveEvent * event) { QAbstractScrollArea::moveEvent(event); }
    void moveEvent(QMoveEvent * event) override;
    inline bool nativeEvent_protected(const QByteArray & eventType, void * message, long * result) { return QAbstractScrollArea::nativeEvent(eventType, message, result); }
    bool nativeEvent(const QByteArray & eventType, void * message, long * result) override;
    QPaintEngine * paintEngine() const override;
    inline void paintEvent_protected(QPaintEvent * arg__1) { QAbstractScrollArea::paintEvent(arg__1); }
    void paintEvent(QPaintEvent * arg__1) override;
    inline QPaintDevice * redirected_protected(QPoint * offset) const { return QAbstractScrollArea::redirected(offset); }
    QPaintDevice * redirected(QPoint * offset) const override;
    inline void resizeEvent_protected(QResizeEvent * arg__1) { QAbstractScrollArea::resizeEvent(arg__1); }
    void resizeEvent(QResizeEvent * arg__1) override;
    inline void scrollContentsBy_protected(int dx, int dy) { QAbstractScrollArea::scrollContentsBy(dx, dy); }
    void scrollContentsBy(int dx, int dy) override;
    inline void setViewportMargins_protected(const QMargins & margins) { QAbstractScrollArea::setViewportMargins(margins); }
    inline void setViewportMargins_protected(int left, int top, int right, int bottom) { QAbstractScrollArea::setViewportMargins(left, top, right, bottom); }
    void setVisible(bool visible) override;
    void setupViewport(QWidget * viewport) override;
    inline QPainter * sharedPainter_protected() const { return QAbstractScrollArea::sharedPainter(); }
    QPainter * sharedPainter() const override;
    inline void showEvent_protected(QShowEvent * event) { QAbstractScrollArea::showEvent(event); }
    void showEvent(QShowEvent * event) override;
    QSize sizeHint() const override;
    inline void tabletEvent_protected(QTabletEvent * event) { QAbstractScrollArea::tabletEvent(event); }
    void tabletEvent(QTabletEvent * event) override;
    inline void timerEvent_protected(QTimerEvent * event) { QAbstractScrollArea::timerEvent(event); }
    void timerEvent(QTimerEvent * event) override;
    inline bool viewportEvent_protected(QEvent * arg__1) { return QAbstractScrollArea::viewportEvent(arg__1); }
    bool viewportEvent(QEvent * arg__1) override;
    inline QMargins viewportMargins_protected() const { return QAbstractScrollArea::viewportMargins(); }
    inline QSize viewportSizeHint_protected() const { return QAbstractScrollArea::viewportSizeHint(); }
    QSize viewportSizeHint() const override;
    inline void wheelEvent_protected(QWheelEvent * arg__1) { QAbstractScrollArea::wheelEvent(arg__1); }
    void wheelEvent(QWheelEvent * arg__1) override;
    ~QAbstractScrollAreaWrapper();
public:
    int qt_metacall(QMetaObject::Call call, int id, void **args) override;
    void *qt_metacast(const char *_clname) override;
    static void pysideInitQtMetaTypes();
    void resetPyMethodCache();
private:
    mutable bool m_PyMethodCache[52];
};

#  endif // SBK_QABSTRACTSCROLLAREAWRAPPER_H

#  ifndef SBK_QFRAMEWRAPPER_H
#  define SBK_QFRAMEWRAPPER_H

// Inherited base class:
class QFrameWrapper : public QFrame
{
public:
    QFrameWrapper(QWidget * parent = nullptr, QFlags<Qt::WindowType> f = Qt::WindowFlags());
    inline void actionEvent_protected(QActionEvent * event) { QFrame::actionEvent(event); }
    void actionEvent(QActionEvent * event) override;
    inline void changeEvent_protected(QEvent * arg__1) { QFrame::changeEvent(arg__1); }
    void changeEvent(QEvent * arg__1) override;
    inline void childEvent_protected(QChildEvent * event) { QFrame::childEvent(event); }
    void childEvent(QChildEvent * event) override;
    inline void closeEvent_protected(QCloseEvent * event) { QFrame::closeEvent(event); }
    void closeEvent(QCloseEvent * event) override;
    inline void connectNotify_protected(const QMetaMethod & signal) { QFrame::connectNotify(signal); }
    void connectNotify(const QMetaMethod & signal) override;
    inline void contextMenuEvent_protected(QContextMenuEvent * event) { QFrame::contextMenuEvent(event); }
    void contextMenuEvent(QContextMenuEvent * event) override;
    inline void create_protected(WId arg__1 = 0, bool initializeWindow = true, bool destroyOldWindow = true) { QFrame::create(arg__1, initializeWindow, destroyOldWindow); }
    inline void customEvent_protected(QEvent * event) { QFrame::customEvent(event); }
    void customEvent(QEvent * event) override;
    inline void destroy_protected(bool destroyWindow = true, bool destroySubWindows = true) { QFrame::destroy(destroyWindow, destroySubWindows); }
    int devType() const override;
    inline void disconnectNotify_protected(const QMetaMethod & signal) { QFrame::disconnectNotify(signal); }
    void disconnectNotify(const QMetaMethod & signal) override;
    inline void dragEnterEvent_protected(QDragEnterEvent * event) { QFrame::dragEnterEvent(event); }
    void dragEnterEvent(QDragEnterEvent * event) override;
    inline void dragLeaveEvent_protected(QDragLeaveEvent * event) { QFrame::dragLeaveEvent(event); }
    void dragLeaveEvent(QDragLeaveEvent * event) override;
    inline void dragMoveEvent_protected(QDragMoveEvent * event) { QFrame::dragMoveEvent(event); }
    void dragMoveEvent(QDragMoveEvent * event) override;
    inline void drawFrame_protected(QPainter * arg__1) { QFrame::drawFrame(arg__1); }
    inline void dropEvent_protected(QDropEvent * event) { QFrame::dropEvent(event); }
    void dropEvent(QDropEvent * event) override;
    inline void enterEvent_protected(QEvent * event) { QFrame::enterEvent(event); }
    void enterEvent(QEvent * event) override;
    inline bool event_protected(QEvent * e) { return QFrame::event(e); }
    bool event(QEvent * e) override;
    bool eventFilter(QObject * watched, QEvent * event) override;
    inline void focusInEvent_protected(QFocusEvent * event) { QFrame::focusInEvent(event); }
    void focusInEvent(QFocusEvent * event) override;
    inline bool focusNextChild_protected() { return QFrame::focusNextChild(); }
    inline bool focusNextPrevChild_protected(bool next) { return QFrame::focusNextPrevChild(next); }
    bool focusNextPrevChild(bool next) override;
    inline void focusOutEvent_protected(QFocusEvent * event) { QFrame::focusOutEvent(event); }
    void focusOutEvent(QFocusEvent * event) override;
    inline bool focusPreviousChild_protected() { return QFrame::focusPreviousChild(); }
    bool hasHeightForWidth() const override;
    int heightForWidth(int arg__1) const override;
    inline void hideEvent_protected(QHideEvent * event) { QFrame::hideEvent(event); }
    void hideEvent(QHideEvent * event) override;
    inline void initPainter_protected(QPainter * painter) const { QFrame::initPainter(painter); }
    void initPainter(QPainter * painter) const override;
    inline void initStyleOption_protected(QStyleOptionFrame * option) const { QFrame::initStyleOption(option); }
    inline void inputMethodEvent_protected(QInputMethodEvent * event) { QFrame::inputMethodEvent(event); }
    void inputMethodEvent(QInputMethodEvent * event) override;
    QVariant inputMethodQuery(Qt::InputMethodQuery arg__1) const override;
    inline void keyPressEvent_protected(QKeyEvent * event) { QFrame::keyPressEvent(event); }
    void keyPressEvent(QKeyEvent * event) override;
    inline void keyReleaseEvent_protected(QKeyEvent * event) { QFrame::keyReleaseEvent(event); }
    void keyReleaseEvent(QKeyEvent * event) override;
    inline void leaveEvent_protected(QEvent * event) { QFrame::leaveEvent(event); }
    void leaveEvent(QEvent * event) override;
    const QMetaObject * metaObject() const override;
    inline int metric_protected(QPaintDevice::PaintDeviceMetric arg__1) const { return QFrame::metric(QPaintDevice::PaintDeviceMetric(arg__1)); }
    int metric(QPaintDevice::PaintDeviceMetric arg__1) const override;
    QSize minimumSizeHint() const override;
    inline void mouseDoubleClickEvent_protected(QMouseEvent * event) { QFrame::mouseDoubleClickEvent(event); }
    void mouseDoubleClickEvent(QMouseEvent * event) override;
    inline void mouseMoveEvent_protected(QMouseEvent * event) { QFrame::mouseMoveEvent(event); }
    void mouseMoveEvent(QMouseEvent * event) override;
    inline void mousePressEvent_protected(QMouseEvent * event) { QFrame::mousePressEvent(event); }
    void mousePressEvent(QMouseEvent * event) override;
    inline void mouseReleaseEvent_protected(QMouseEvent * event) { QFrame::mouseReleaseEvent(event); }
    void mouseReleaseEvent(QMouseEvent * event) override;
    inline void moveEvent_protected(QMoveEvent * event) { QFrame::moveEvent(event); }
    void moveEvent(QMoveEvent * event) override;
    inline bool nativeEvent_protected(const QByteArray & eventType, void * message, long * result) { return QFrame::nativeEvent(eventType, message, result); }
    bool nativeEvent(const QByteArray & eventType, void * message, long * result) override;
    QPaintEngine * paintEngine() const override;
    inline void paintEvent_protected(QPaintEvent * arg__1) { QFrame::paintEvent(arg__1); }
    void paintEvent(QPaintEvent * arg__1) override;
    inline QPaintDevice * redirected_protected(QPoint * offset) const { return QFrame::redirected(offset); }
    QPaintDevice * redirected(QPoint * offset) const override;
    inline void resizeEvent_protected(QResizeEvent * event) { QFrame::resizeEvent(event); }
    void resizeEvent(QResizeEvent * event) override;
    void setVisible(bool visible) override;
    inline QPainter * sharedPainter_protected() const { return QFrame::sharedPainter(); }
    QPainter * sharedPainter() const override;
    inline void showEvent_protected(QShowEvent * event) { QFrame::showEvent(event); }
    void showEvent(QShowEvent * event) override;
    QSize sizeHint() const override;
    inline void tabletEvent_protected(QTabletEvent * event) { QFrame::tabletEvent(event); }
    void tabletEvent(QTabletEvent * event) override;
    inline void timerEvent_protected(QTimerEvent * event) { QFrame::timerEvent(event); }
    void timerEvent(QTimerEvent * event) override;
    inline void updateMicroFocus_protected() { QFrame::updateMicroFocus(); }
    inline void wheelEvent_protected(QWheelEvent * event) { QFrame::wheelEvent(event); }
    void wheelEvent(QWheelEvent * event) override;
    ~QFrameWrapper();
public:
    int qt_metacall(QMetaObject::Call call, int id, void **args) override;
    void *qt_metacast(const char *_clname) override;
    static void pysideInitQtMetaTypes();
    void resetPyMethodCache();
private:
    mutable bool m_PyMethodCache[48];
};

#  endif // SBK_QFRAMEWRAPPER_H

#  ifndef SBK_QWIDGETWRAPPER_H
#  define SBK_QWIDGETWRAPPER_H

// Inherited base class:
class QWidgetWrapper : public QWidget
{
public:
    QWidgetWrapper(QWidget * parent = nullptr, QFlags<Qt::WindowType> f = Qt::WindowFlags());
    inline void actionEvent_protected(QActionEvent * event) { QWidget::actionEvent(event); }
    void actionEvent(QActionEvent * event) override;
    inline void changeEvent_protected(QEvent * event) { QWidget::changeEvent(event); }
    void changeEvent(QEvent * event) override;
    inline void childEvent_protected(QChildEvent * event) { QWidget::childEvent(event); }
    void childEvent(QChildEvent * event) override;
    inline void closeEvent_protected(QCloseEvent * event) { QWidget::closeEvent(event); }
    void closeEvent(QCloseEvent * event) override;
    inline void connectNotify_protected(const QMetaMethod & signal) { QWidget::connectNotify(signal); }
    void connectNotify(const QMetaMethod & signal) override;
    inline void contextMenuEvent_protected(QContextMenuEvent * event) { QWidget::contextMenuEvent(event); }
    void contextMenuEvent(QContextMenuEvent * event) override;
    inline void create_protected(WId arg__1 = 0, bool initializeWindow = true, bool destroyOldWindow = true) { QWidget::create(arg__1, initializeWindow, destroyOldWindow); }
    inline void customEvent_protected(QEvent * event) { QWidget::customEvent(event); }
    void customEvent(QEvent * event) override;
    inline void destroy_protected(bool destroyWindow = true, bool destroySubWindows = true) { QWidget::destroy(destroyWindow, destroySubWindows); }
    int devType() const override;
    inline void disconnectNotify_protected(const QMetaMethod & signal) { QWidget::disconnectNotify(signal); }
    void disconnectNotify(const QMetaMethod & signal) override;
    inline void dragEnterEvent_protected(QDragEnterEvent * event) { QWidget::dragEnterEvent(event); }
    void dragEnterEvent(QDragEnterEvent * event) override;
    inline void dragLeaveEvent_protected(QDragLeaveEvent * event) { QWidget::dragLeaveEvent(event); }
    void dragLeaveEvent(QDragLeaveEvent * event) override;
    inline void dragMoveEvent_protected(QDragMoveEvent * event) { QWidget::dragMoveEvent(event); }
    void dragMoveEvent(QDragMoveEvent * event) override;
    inline void dropEvent_protected(QDropEvent * event) { QWidget::dropEvent(event); }
    void dropEvent(QDropEvent * event) override;
    inline void enterEvent_protected(QEvent * event) { QWidget::enterEvent(event); }
    void enterEvent(QEvent * event) override;
    inline bool event_protected(QEvent * event) { return QWidget::event(event); }
    bool event(QEvent * event) override;
    bool eventFilter(QObject * watched, QEvent * event) override;
    inline void focusInEvent_protected(QFocusEvent * event) { QWidget::focusInEvent(event); }
    void focusInEvent(QFocusEvent * event) override;
    inline bool focusNextChild_protected() { return QWidget::focusNextChild(); }
    inline bool focusNextPrevChild_protected(bool next) { return QWidget::focusNextPrevChild(next); }
    bool focusNextPrevChild(bool next) override;
    inline void focusOutEvent_protected(QFocusEvent * event) { QWidget::focusOutEvent(event); }
    void focusOutEvent(QFocusEvent * event) override;
    inline bool focusPreviousChild_protected() { return QWidget::focusPreviousChild(); }
    bool hasHeightForWidth() const override;
    int heightForWidth(int arg__1) const override;
    inline void hideEvent_protected(QHideEvent * event) { QWidget::hideEvent(event); }
    void hideEvent(QHideEvent * event) override;
    inline void initPainter_protected(QPainter * painter) const { QWidget::initPainter(painter); }
    void initPainter(QPainter * painter) const override;
    inline void inputMethodEvent_protected(QInputMethodEvent * event) { QWidget::inputMethodEvent(event); }
    void inputMethodEvent(QInputMethodEvent * event) override;
    QVariant inputMethodQuery(Qt::InputMethodQuery arg__1) const override;
    inline bool isSignalConnected_protected(const QMetaMethod & signal) const { return QWidget::isSignalConnected(signal); }
    inline void keyPressEvent_protected(QKeyEvent * event) { QWidget::keyPressEvent(event); }
    void keyPressEvent(QKeyEvent * event) override;
    inline void keyReleaseEvent_protected(QKeyEvent * event) { QWidget::keyReleaseEvent(event); }
    void keyReleaseEvent(QKeyEvent * event) override;
    inline void leaveEvent_protected(QEvent * event) { QWidget::leaveEvent(event); }
    void leaveEvent(QEvent * event) override;
    const QMetaObject * metaObject() const override;
    inline int metric_protected(QPaintDevice::PaintDeviceMetric arg__1) const { return QWidget::metric(QPaintDevice::PaintDeviceMetric(arg__1)); }
    int metric(QPaintDevice::PaintDeviceMetric arg__1) const override;
    QSize minimumSizeHint() const override;
    inline void mouseDoubleClickEvent_protected(QMouseEvent * event) { QWidget::mouseDoubleClickEvent(event); }
    void mouseDoubleClickEvent(QMouseEvent * event) override;
    inline void mouseMoveEvent_protected(QMouseEvent * event) { QWidget::mouseMoveEvent(event); }
    void mouseMoveEvent(QMouseEvent * event) override;
    inline void mousePressEvent_protected(QMouseEvent * event) { QWidget::mousePressEvent(event); }
    void mousePressEvent(QMouseEvent * event) override;
    inline void mouseReleaseEvent_protected(QMouseEvent * event) { QWidget::mouseReleaseEvent(event); }
    void mouseReleaseEvent(QMouseEvent * event) override;
    inline void moveEvent_protected(QMoveEvent * event) { QWidget::moveEvent(event); }
    void moveEvent(QMoveEvent * event) override;
    inline bool nativeEvent_protected(const QByteArray & eventType, void * message, long * result) { return QWidget::nativeEvent(eventType, message, result); }
    bool nativeEvent(const QByteArray & eventType, void * message, long * result) override;
    QPaintEngine * paintEngine() const override;
    inline void paintEvent_protected(QPaintEvent * event) { QWidget::paintEvent(event); }
    void paintEvent(QPaintEvent * event) override;
    inline int receivers_protected(const char * signal) const { return QWidget::receivers(signal); }
    inline QPaintDevice * redirected_protected(QPoint * offset) const { return QWidget::redirected(offset); }
    QPaintDevice * redirected(QPoint * offset) const override;
    inline void resizeEvent_protected(QResizeEvent * event) { QWidget::resizeEvent(event); }
    void resizeEvent(QResizeEvent * event) override;
    inline QObject * sender_protected() const { return QWidget::sender(); }
    inline int senderSignalIndex_protected() const { return QWidget::senderSignalIndex(); }
    void setVisible(bool visible) override;
    inline QPainter * sharedPainter_protected() const { return QWidget::sharedPainter(); }
    QPainter * sharedPainter() const override;
    inline void showEvent_protected(QShowEvent * event) { QWidget::showEvent(event); }
    void showEvent(QShowEvent * event) override;
    QSize sizeHint() const override;
    inline void tabletEvent_protected(QTabletEvent * event) { QWidget::tabletEvent(event); }
    void tabletEvent(QTabletEvent * event) override;
    inline void timerEvent_protected(QTimerEvent * event) { QWidget::timerEvent(event); }
    void timerEvent(QTimerEvent * event) override;
    inline void updateMicroFocus_protected() { QWidget::updateMicroFocus(); }
    inline void wheelEvent_protected(QWheelEvent * event) { QWidget::wheelEvent(event); }
    void wheelEvent(QWheelEvent * event) override;
    ~QWidgetWrapper();
public:
    int qt_metacall(QMetaObject::Call call, int id, void **args) override;
    void *qt_metacast(const char *_clname) override;
    static void pysideInitQtMetaTypes();
    void resetPyMethodCache();
private:
    mutable bool m_PyMethodCache[48];
};

#  endif // SBK_QWIDGETWRAPPER_H

#  ifndef SBK_QOBJECTWRAPPER_H
#  define SBK_QOBJECTWRAPPER_H

// Inherited base class:
class QObjectWrapper : public QObject
{
public:
    QObjectWrapper(QObject * parent = nullptr);
    inline void childEvent_protected(QChildEvent * event) { QObject::childEvent(event); }
    void childEvent(QChildEvent * event) override;
    inline void connectNotify_protected(const QMetaMethod & signal) { QObject::connectNotify(signal); }
    void connectNotify(const QMetaMethod & signal) override;
    inline void customEvent_protected(QEvent * event) { QObject::customEvent(event); }
    void customEvent(QEvent * event) override;
    inline void disconnectNotify_protected(const QMetaMethod & signal) { QObject::disconnectNotify(signal); }
    void disconnectNotify(const QMetaMethod & signal) override;
    bool event(QEvent * event) override;
    bool eventFilter(QObject * watched, QEvent * event) override;
    inline bool isSignalConnected_protected(const QMetaMethod & signal) const { return QObject::isSignalConnected(signal); }
    const QMetaObject * metaObject() const override;
    inline int receivers_protected(const char * signal) const { return QObject::receivers(signal); }
    inline QObject * sender_protected() const { return QObject::sender(); }
    inline int senderSignalIndex_protected() const { return QObject::senderSignalIndex(); }
    inline void timerEvent_protected(QTimerEvent * event) { QObject::timerEvent(event); }
    void timerEvent(QTimerEvent * event) override;
    ~QObjectWrapper();
public:
    int qt_metacall(QMetaObject::Call call, int id, void **args) override;
    void *qt_metacast(const char *_clname) override;
    static void pysideInitQtMetaTypes();
    void resetPyMethodCache();
private:
    mutable bool m_PyMethodCache[8];
};

#  endif // SBK_QOBJECTWRAPPER_H

#endif // SBK_QLITEHTMLWIDGETWRAPPER_H

