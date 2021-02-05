#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void LoadJsonData();
    void ShowTraceExData();
    void CreateNewTraceItem(const QString *name = nullptr, const QString *num = nullptr ,const QPixmap *icon = nullptr, const QString *state = nullptr);

private slots:
    void on_Button_Refresh_clicked();

    void on_Button_AddTrace_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
