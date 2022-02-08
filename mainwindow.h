#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <threadlist.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    threadList list;

    void update();

private slots:
    void on_start_clicked();

    void on_stop_clicked();

    void on_threadsCombobox_activated(const QString &arg1);



private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
