#ifndef TRACEITEMWIDGET_H
#define TRACEITEMWIDGET_H

#include <QPushButton>
#include <mainwindow.h>
#include "ui_traceitemwidget.h"
#include "jsondata.h"

using namespace JsonData;

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

    TraceData tracedata;

    //역직렬화한 json 데이터를 위젯 하나당 들고 있어야합니다.
    //데이터는 onclicked 에서 활용되어 세부 정보를 여는데 활용됩니다.
    //인덱스와 json 데이터는 다시

};

#endif // TRACEITEMWIDGET_H
