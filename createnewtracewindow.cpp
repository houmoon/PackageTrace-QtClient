#include "createnewtracewindow.h"
#include "ui_createnewtracewindow.h"

CreateNewTraceWindow::CreateNewTraceWindow(MainWindow *mainwindow, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateNewTraceWindow)
{
    parentWnd = mainwindow;
    ui->setupUi(this);
}

CreateNewTraceWindow::~CreateNewTraceWindow()
{
    delete ui;
}

void CreateNewTraceWindow::on_Button_AddTrace_clicked()
{
    parentWnd->CreateNewTraceItem(" "," "," ");
}
