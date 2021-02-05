#include "traceitemwidget.h"
#include "ui_traceitemwidget.h"

TraceItemWidget::TraceItemWidget(QWidget *parent) :
    QPushButton(parent),
    ui(new Ui::TraceItemWidget)
{
    connect(this,&QPushButton::clicked,this,&TraceItemWidget::OnClicked);


    ui->setupUi(this);
}

TraceItemWidget::~TraceItemWidget()
{
    delete ui;
}

void TraceItemWidget::OnClicked()
{
    this->setStyleSheet("QPushButton{background-color: rgb(0, 150, 255);}");
}
