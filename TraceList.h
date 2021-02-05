#ifndef TRACELIST_H
#define TRACELIST_H

#include <QMainWindow>
#include <ui_mainwindow.h>

class TraceList : public QMainWindow
{
    Q_OBJECT

    public:
    TraceList(QWidget *parent = Q_NULLPTR);
    ~TraceList();

    void OnAddTrace();
    void OnRemoveTrace();

    private:
    Ui::MainWindow ui;
};

#endif // TRACELIST_H
