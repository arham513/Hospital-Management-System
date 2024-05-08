
#include "forthdialog.h"
#include "ui_forthdialog.h"
#include "QMessageBox"
#include "QSqlDatabase"
#include "QtSql/QSql"
#include "QSqlQueryModel"
#include <QtSql>
#include <QDebug>
#include <QTableWidgetItem>
#include <QFont>
#include <QMessageBox>
forthdialog::forthdialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::forthdialog)
{
    ui->setupUi(this);
}
#include <iostream>
#include <string>
using namespace std;
class Administrator {
private:
    QString adminusername;
    QString adminpassword;
public:
    Administrator(QString adminusername, QString adminpassword) // setting administrative credentials
    {
        this->adminusername = adminusername;
        this->adminpassword = adminpassword;
    }
    void setadminusername(QString adminusername)
    {
        this->adminusername = adminusername;
    }
    void setadminpassword(QString adminpassword)
    {
        this->adminpassword = adminpassword;
    }
    QString const getadminusername() const
    {
        return  adminusername;
    }
    QString const getadminpassword() const
    {
        return  adminpassword;
    }
    void tracknviewmedicinesandequipmentinventory()
    {
 // difficult to incorporate different settings in member functions of classes so kept empty....
    }
};


forthdialog::~forthdialog()
{
    delete ui;
}

void forthdialog::on_pushButton_clicked()
{
    Administrator a1("Admin1", "user1");
    QString username = ui->daba1->text();
    QString password = ui->daba2->text();
    if (username == a1.getadminusername() && password == a1.getadminpassword())
    {
        a1.tracknviewmedicinesandequipmentinventory();
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/Users/10/Desktop/Administrator.db"); // Replace "myDatabase.db" with your database file name
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
        query.prepare("SELECT * FROM  InventoryEquipment");
        // query.bindValue(":id", p1.getPatientID());
        if (query.exec()) {
            qDebug() << "Successful"; }
        else
        {  qDebug() << query.lastError().text();
        }
        while (query.next()) {
            int row = 0;
                QFont font1("Arial",15);
                ui->tableWidget->setFont(font1);
                ui->tableWidget->setRowCount(5);
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
        // ADD SOMETHING Take Input from user InventoryEquipmentID, ya MedicineID
         //   query.prepare(INSERT INTO Medicine VALUES();); // just make line edit buttons in UI
            // use of bindvalue
            // delete kay liye Delete From Table Where MedicineID= decide ..
        query.prepare("SELECT * FROM  Medicine");
        if (query.exec()) {
            qDebug() << "Successful"; }
        else
        {  qDebug() << query.lastError().text();
        }
        while (query.next()) {
                int row = 0;
                QFont font1("Arial",15);
                ui->tableWidget_2->setFont(font1);
                ui->tableWidget_2->setRowCount(5);
                ui->tableWidget_2->insertRow(row);
                ui->tableWidget_2->setColumnCount(4);
                ui->tableWidget_2->insertRow(ui->tableWidget->rowCount());
                for (int i = 0; i < 4; i++) {
                      ui->tableWidget->setColumnWidth(i,300);
                    QTableWidgetItem *item = new QTableWidgetItem(query.value(i).toString());
                    ui->tableWidget_2->setItem(row, i, item);
                }
                row++;
            }
        db.close();
            QMessageBox :: information(this, "Done","You can now easily view and navigate the database to track equipment and medicine at hospital");    }
    else
    {
        QMessageBox :: information(this, "Done","You are not an administrator or you have entered the wrong credentials");
        close();
    }
}

