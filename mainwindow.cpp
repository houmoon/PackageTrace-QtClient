#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include <QMessageBox>

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
        QString path = QCoreApplication::applicationDirPath();
        QString  command("python");
        QStringList params = QStringList() << "tracer.py" << "kr.cjlogistics" << "637197513201";

        QProcess *process = new QProcess();

        if(!process->startDetached(command, params, path))
        {
            QMessageBox MsgBox;
            MsgBox.critical(0,"에러","프로세스를 실행하지 못했습니다.");
            MsgBox.setFixedSize(500,200);
            MsgBox.exec();
        }

        process->waitForFinished();
        process->close();
}
