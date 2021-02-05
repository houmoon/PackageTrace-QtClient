#ifndef TRACEITEMWIDGET_H
#define TRACEITEMWIDGET_H

#include <QPushButton>

namespace Ui {
class TraceItemWidget;
}

class TraceItemWidget : public QPushButton
{
    Q_OBJECT

public:
    explicit TraceItemWidget(QWidget *parent = nullptr);
    ~TraceItemWidget();

private:
    Ui::TraceItemWidget *ui;
    void OnClicked();
};

#endif // TRACEITEMWIDGET_H
