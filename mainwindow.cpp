#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPixmap>
#include"secdialog.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/10/Desktop/img1.jpg");
    ui->label->setPixmap(pix);
}

MainWindow::~MainWindow()
{

    delete ui;
}







void MainWindow::on_pushButton_1_clicked()
{
    close();
    SecDialog secdilog;
    secdilog.setModal(true);
    secdilog.exec();
}




