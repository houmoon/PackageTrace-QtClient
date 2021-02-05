#ifndef TRACEITEMWIDGET_H
#define TRACEITEMWIDGET_H

#include <QPushButton>
#include <mainwindow.h>
#include "ui_traceitemwidget.h"

namespace Ui {
class TraceItemWidget;
}

class TraceItemWidget : public QPushButton
{
    Q_OBJECT

public:
    explicit TraceItemWidget(MainWindow *parentWnd = nullptr, QWidget *parent = nullptr);
    ~TraceItemWidget();

    Ui::TraceItemWidget *ui;

private:
    MainWindow *parentWnd;
    void OnClicked();

};

#endif // TRACEITEMWIDGET_H
