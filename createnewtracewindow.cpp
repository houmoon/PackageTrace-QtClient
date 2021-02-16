#include "createnewtracewindow.h"
#include "ui_createnewtracewindow.h"
#include "clientvariable.h"

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
    //const QPixmap icon = *pixmap(ui->company->currentIndex());

    const QString company = ClientVariable::IndexToCompanycode(ui->company->currentIndex());
    parentWnd->UpdateTraces(&name,&num,&company);
}

QPixmap* CreateNewTraceWindow::pixmap(int index)
{
    QPixmap *_pixmap = new QPixmap(ClientVariable::IndexToIcon(index));

    return _pixmap;
}
