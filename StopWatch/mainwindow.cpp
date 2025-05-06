#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sec = 0;
    min = 0;
    pause = false;
    connect(&reloj,SIGNAL(timeout()),this,SLOT(prosses()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_start_btn_clicked()
{
    reloj.start(1000);

}


void MainWindow::on_pause_btn_clicked()
{
    if (pause==false){
        reloj.stop();
        pause = true;
        ui->pause_btn->setText("Resume");
    }

    else {
        pause = false;
        reloj.start(1000);
        ui->pause_btn->setText("Pause");

    }
}


void MainWindow::on_stop_btn_clicked()
{
    min = 0;
    sec = 0;
    pause = false;
    ui->min->display(min);
    ui->sec->display(sec);
    reloj.stop();
}

void MainWindow::prosses()
{
    sec = sec+1;
    if (sec == 59){
        sec = 0;
        min = min+1;
    }
    else{
        ui->sec->display(sec);
        ui->min->display(min);

    }
}

