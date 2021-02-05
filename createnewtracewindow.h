#ifndef CREATENEWTRACEWINDOW_H
#define CREATENEWTRACEWINDOW_H

#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class CreateNewTraceWindow;
}

class CreateNewTraceWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CreateNewTraceWindow(MainWindow *mainwindow = nullptr,QWidget *parent = nullptr);
    ~CreateNewTraceWindow();

private slots:
    void on_Button_AddTrace_clicked();

private:
    Ui::CreateNewTraceWindow *ui;
    MainWindow *parentWnd;
    QPixmap *pixmap(const int index);
};

#endif // CREATENEWTRACEWINDOW_H
