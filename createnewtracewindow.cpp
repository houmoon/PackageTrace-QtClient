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
    const QString name = ui->name->text();
    const QString num = ui->num->text();
    const QPixmap icon = *pixmap(ui->company->currentIndex());
    parentWnd->CreateNewTraceItem(&name,&num,&icon);
}

QPixmap* CreateNewTraceWindow::pixmap(int index)
{
    QPixmap *_pixmap = nullptr;

    switch(index)
    {
        case 0: //킹체국
        _pixmap = new QPixmap(":/icons/icon_epost.png");
        break;
        case 1: //대한통운
        _pixmap = new QPixmap(":/icons/icon_cj.png");
        break;
    }

    return _pixmap;
}
