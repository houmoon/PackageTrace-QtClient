#ifndef TRACEITEMWIDGET_H
#define TRACEITEMWIDGET_H

#include <QWidget>

namespace Ui {
class TraceItemWidget;
}

class TraceItemWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TraceItemWidget(QWidget *parent = nullptr);
    ~TraceItemWidget();

private:
    Ui::TraceItemWidget *ui;
};

#endif // TRACEITEMWIDGET_H
