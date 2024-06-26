class QLiteHtmlWidget : QAbstractScrollArea
{
%TypeHeaderCode
#include "qlitehtmlwidget.h"
%End

public:
    QLiteHtmlWidget(QWidget *parent /TransferThis/ = 0);
    ~QLiteHtmlWidget();

    void setUrl(const QUrl &url);
    QUrl url() const;
    void setHtml(const QString &content);
    QString html() const;
    QString title() const;

    void setZoomFactor(qreal scale);
    qreal zoomFactor() const;

    bool findText(const QString &text,
                  QTextDocument::FindFlags flags,
                  bool incremental,
                  bool *wrapped = nullptr);

    void setDefaultFont(const QFont &font);
    QFont defaultFont() const;
    void setAntialias(bool on);

    void scrollToAnchor(const QString &name);

    // using ResourceHandler = std::function<QByteArray(QUrl)>;
    // void setResourceHandler(const ResourceHandler &handler);

    QString selectedText() const;

signals:
    void linkClicked(const QUrl &url);
    void linkHighlighted(const QUrl &url);
    void copyAvailable(bool available);
    void contextMenuRequested(const QPoint &pos, const QUrl &url);

protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void resizeEvent(QResizeEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void mouseDoubleClickEvent(QMouseEvent *event);
    virtual void leaveEvent(QEvent *event);
    virtual void contextMenuEvent(QContextMenuEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);

private:
    void updateHightlightedLink();
    void setHightlightedLink(const QUrl &url);
    // void withFixedTextPosition(const std::function<void()> &action);
    void render();
    QPoint scrollPosition() const;
    void htmlPos(const QPoint &pos, QPoint *viewportPos, QPoint *htmlPos) const;
    QPoint toVirtual(const QPoint &p) const;
    QSize toVirtual(const QSize &s) const;
    QRect toVirtual(const QRect &r) const;
    QRect fromVirtual(const QRect &r) const;
};