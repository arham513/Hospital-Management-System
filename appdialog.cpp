#include "appdialog.h"
#include "ui_appdialog.h"
#include<QPixmap>
#include <QMessageBox>
#include "QMessageBox"
#include "QSqlDatabase"
#include "QtSql/QSql"
#include "QSqlQueryModel"
#include <QtSql>
#include <QDebug>
#include <QTableWidgetItem>
#include <QFont>

appdialog::appdialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::appdialog)
{
    ui->setupUi(this);

}
void appdialog::on_pushButton_clicked()
{
    // better yet connect database of doctor and display to user doctor, speciality and available timings
    QString doctorname = ui->doc_name->text();
    QString day = ui->Day->text();
    QString time = ui->appointtime->text();
    QMessageBox :: information(this,"Done", "Request forwaded to doctor") ;

        close();
}
appdialog::~appdialog()
{
    delete ui;
}




void appdialog::on_pushButton_2_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/10/Desktop/Doctors.db"); // Replace "myDatabase.db" with your database file name
    // Open the database
    if (!db.open()) {
        qDebug() << "Error: Unable to open database";
        exit;
    }
    // Check if the database is open
    if (db.isOpen()) {
        qDebug() << "Database opened successfully";
    }
    // to select record from database, using QSqlQuery class
    QSqlQuery query;
    query.prepare("SELECT * FROM  Doctor");
    if (query.exec()) {
        qDebug() << "Successful"; }
    else
    {  qDebug() << query.lastError().text();
    }
    while (query.next()) {
        int row = 0;
        QFont font1("Arial",15);
        ui->tableWidget->setFont(font1);
        ui->tableWidget->setRowCount(25);
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setColumnCount(4);
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        for (int i = 0; i < 4; i++) {
            ui->tableWidget->setColumnWidth(i,300);
            QTableWidgetItem *item = new QTableWidgetItem(query.value(i).toString());
            ui->tableWidget->setItem(row, i, item);
        }
        row++;
    }
    db.close();
}

