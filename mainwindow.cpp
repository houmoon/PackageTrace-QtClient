#include "mainwindow.h"
#include "ui_mainwindow.h"
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
        //프로그램 상에 데이터가 없다면 메서드를 실행하지 않고 경고문을 출력하고 종료.

        QString path = QCoreApplication::applicationDirPath();
        QString  command("python");
        QStringList params = QStringList() << "tracer.py" << "kr.cjlogistics" << "637197513201";

        QProcess *process = new QProcess();

        process->startDetached(command, params, path);

        if(process->WriteError)
        {
            QMessageBox MsgBox;
            MsgBox.setFixedSize(500,200);
            MsgBox.warning(0,"에러","프로세스를 불러오지 못했습니다.");
        }
        process->waitForFinished();
        process->close();


        //json 데이터를 역직렬화해서 아이템에 배송내역을 넣고, 아이템을 구성해 위젯에 할당하는 메서드 필요.

}

void MainWindow::LoadJsonData()
{

}

