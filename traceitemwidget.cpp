#include "traceitemwidget.h"
#include "ui_traceitemwidget.h"
#include <QMainWindow>

TraceItemWidget::TraceItemWidget(MainWindow *parentWnd,QWidget *parent) :
    QPushButton(parent),
    ui(new Ui::TraceItemWidget)
{    
    this->parentWnd = parentWnd;
    connect(this,&QPushButton::clicked,this,&TraceItemWidget::OnClicked);

    ui->setupUi(this);
}

TraceItemWidget::~TraceItemWidget()
{
    delete ui;
}

void TraceItemWidget::OnClicked()
{
    this->setStyleSheet(" QPushButton{ border-radius : 10px; background-color: rgb(0, 150, 255); } ");
    parentWnd->ShowTraceExData();
}
