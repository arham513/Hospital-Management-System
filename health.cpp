#include "health.h"
#include "ui_health.h"
#include "secdialog.h"
#include "ui_secdialog.h"
#include "QtSql/QSql"
#include "QSqlQueryModel"
#include <QtSql>
#include <QDebug>
#include <QTableWidgetItem>
#include <QFont>
#include <QMessageBox>
health::health(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::health)
{
    ui->setupUi(this);
    QSqlDatabase mydb;

}
class Patient
{
private:
    QString name;
    int patientid;
    QString gender;
    QString cnic;
    int age;
    QString phonenumber;

public:
    Patient()
        {}
    Patient(const QString& name, int patientid, const QString& gender,
            const QString& cnic, int age, const QString& phonenumber)
        : name(name), patientid(patientid), gender(gender),
        cnic(cnic), age(age), phonenumber(phonenumber)
    {
        qDebug() << "Constructor called";
    }
    // Setter methods
    void setPatientName(const QString name) {
        this->name = name;
    }
    void setPatientGender(const QString gender) {
        this->gender = gender;
    }
    void setPatientID(const int ID) {
        patientid = ID;
    }
    void setPatientCNIC(const QString cnic) {
        this->cnic = cnic;
    }
    void setPatientphoneno(const QString phoneno) {
        phonenumber = phoneno;
    }
    void setPatientAge(const int age) {
        this->age = age;
    }
    // Getter methods
    int getPatientID() const {
        return patientid;
    }
    const QString getPatientName() const {
        return name;
    }
    const QString getPatientGender() const {
        return gender;
    }
    const QString getPatientCNIC() const {
        return cnic;
    }
    const QString getContactNo() const {
        return phonenumber;
    }
    int getPatientAge() const {
        return age;
    }
};

health::~health()
{
    delete ui;
}

void health::on_pushButton_clicked() // back to main menu
{
    close();
}
void health::on_pushButton_2_clicked() // display database
{
    Patient p1;
    p1.setPatientID(ui->lineEdit->text().toInt());
        // Create a connection to the database
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/Users/10/Desktop/Health.db"); // Replace "myDatabase.db" with your database file name
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
        query.prepare("SELECT * FROM  PatientInformation Where PatientID=:id");
         query.bindValue(":id", p1.getPatientID());
        if (query.exec()) {
            qDebug() << "Successful";
        }
            else
        {
            qDebug() << query.lastError().text();
        }
        while (query.next()) {
            ui->tableWidget->setColumnCount(24);
            QFont font1("Arial",15);
            ui->tableWidget->setFont(font1);
            ui->tableWidget->setRowCount(0);
           ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            for (int i=0; i< 23;i++)
            {
                ui->tableWidget->setColumnWidth(i,350);
                QTableWidgetItem *item= new QTableWidgetItem(query.value(i).toString());
                ui->tableWidget->setItem(0,i,item);
            }
        }
            db.close();
}




