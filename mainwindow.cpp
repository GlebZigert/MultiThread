#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

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

void MainWindow::update()
{
    ui->threadsCombobox->clear();
    foreach(QString str, list.list.keys()){
        ui->threadsCombobox->addItem(str);

    }
}


void MainWindow::on_start_clicked()
{
    list.append(ui->lineEdit->text());
    update();

}

void MainWindow::on_stop_clicked()
{

    foreach(QString str, list.list.keys()){

       if(str==ui->threadsCombobox->currentText()){


           list.remove(str);
       }

    }

    update();
}

void MainWindow::on_threadsCombobox_activated(const QString &arg1)
{

}
