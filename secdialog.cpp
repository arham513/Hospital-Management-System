#include "secdialog.h"
#include "ui_secdialog.h"
#include"thirddialog.h"
#include "dialog.h"
#include<QPixmap>
#include"forthdialog.h"
#include <appdialog.h>
#include <iostream>
#include <health.h>
using namespace std;
//#include"forthdialog.h"
SecDialog::SecDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SecDialog)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/10/Desktop/img22.jpg");
    ui->label2->setPixmap(pix);
}

SecDialog::~SecDialog()
{
    delete ui;
}





void SecDialog::on_pushButton_1_clicked() // patient reg and admission process
{
    thirdDialog thirddilog;
    thirddilog.setModal(true);
    thirddilog.exec();


}



void SecDialog::on_pushButton_5_clicked()  // tracking of medicine and equipment
{
    forthdialog forthdilog;
    forthdilog.setModal(true);
    forthdilog.exec();
}


void SecDialog::on_pushButton_3_clicked() // hospital contact information
{
    dialog Dialogfile;
    Dialogfile.setModal(true);
    Dialogfile.exec();

}


void SecDialog::on_pushButton_2_clicked() // appointment booking system
{
    appdialog App;
    App.setModal(true);
    App.exec();

}


void SecDialog::on_pushButton_4_clicked() // health record viewer
{
    health h1;
    h1.setModal(true);
    h1.exec();
}

