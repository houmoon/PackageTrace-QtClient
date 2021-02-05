#include "traceitemwidget.h"
#include "ui_traceitemwidget.h"

TraceItemWidget::TraceItemWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TraceItemWidget)
{
    ui->setupUi(this);
}

TraceItemWidget::~TraceItemWidget()
{
    delete ui;
}
