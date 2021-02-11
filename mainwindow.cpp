#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "traceitemwidget.h"
#include "createnewtracewindow.h"

#include <QProcess>
#include <QMessageBox>
#include <QJsonObject>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Button_Refresh_clicked()
{

        //json에서 저장되어 있는 배송정보를 가지고 리프레쉬하는 메서드가 필요할듯.파이썬에서 실행.
        JsonData::TraceData tracedata_test(this);

        //json 데이터를 역직렬화해서 아이템에 배송내역을 넣고, 아이템을 구성해 위젯에 할당하는 메서드 필요.

}

void MainWindow::UpdateTraces(const QString *name, const QString *num, const QString *company)
{
    QString path = QCoreApplication::applicationDirPath();
    QString  command("python3");
    QStringList params = QStringList() << "tracer.py" << *company << *num << *name ;

    QProcess *process = new QProcess();

    process->startDetached(command, params, path);
    process->waitForFinished();
    process->close();

    JsonData::TraceData tracedata_test(this);
}

void MainWindow::LoadJsonData()
{

}

void MainWindow::ShowTraceExData()
{
    ui->TraceExScrollList->setEnabled(true);
}

void MainWindow::CreateNewTraceItem(const QString *name, const QString *num ,const QPixmap *icon, const QString *state)
{
    TraceItemWidget *itemwidget = new TraceItemWidget(this,this->ui->TraceScrollList);
    itemwidget->ui->name->setText(*name);
    itemwidget->ui->num->setText(*num);
    if(icon != nullptr)
    itemwidget->ui->CompanyIcon->setPixmap(*icon);
    itemwidget->ui->state->setText(*state);

    ui->TraceScrollList->layout()->addWidget(itemwidget);

}

void MainWindow::on_Button_AddTrace_clicked()
{
    CreateNewTraceWindow *newwindow = new CreateNewTraceWindow(this);
    newwindow->show();
}
