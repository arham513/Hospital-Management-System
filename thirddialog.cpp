#include "thirddialog.h"
#include "ui_thirddialog.h"
 //#include <QtSql/QSqlDatabase>
//#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include  <QSqlError> // Add this line to include QSqlError
#include <iostream>
#include "QMessageBox"
 using namespace std;
thirdDialog::thirdDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::thirdDialog)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/10/Desktop/img3.jpg");
    ui->labelman->setPixmap(pix);
}
// creating class Patient
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
    void insertdata()
    {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/Users/10/Desktop/database/patientdb.db");
        if (db.open()) {
            qDebug() << "Connected";
            QSqlQuery query1(db);
            query1.prepare("INSERT INTO patient (patient_id, name, gender, age, cnic, phone_number) VALUES (:id, :name, :gender, :age, :cnic, :phone_number);");
            query1.bindValue(":id", patientid);
            query1.bindValue(":name", name);
            query1.bindValue(":gender", gender);
            query1.bindValue(":age", age);
            query1.bindValue(":cnic", cnic);
            query1.bindValue(":phone_number", phonenumber);

            if (query1.exec())
                qDebug() << "Successful";
            else
                qDebug() << "Insert failed:" << query1.lastError();
        } else {
            qDebug()<< "Not Connected";
        }
    }

    ~Patient()
    {
        qDebug() << "Destructor called";
    }
};

void thirdDialog::on_pushButton_clicked()
{
    // Create an instance of the Patient class and insert data
    Patient patient(ui->name_box->text(), ui->id_box->text().toInt(),
                    ui->gender_box->text(), ui->cnic_box->text(),
                    ui->age_box->text().toInt(), ui->phoneno_box->text());
    patient.insertdata();
    if (ui->id_box->text().toInt() < 0 || ui->age_box->text().toInt() < 0 || ui->phoneno_box->text() < "0" || ui->cnic_box->text() < "0") // VALIDATION OF INPUTS
    {
        QMessageBox:: information(this,"Done", "The fields cannot be negative nor blank" );
        close(); } // INPUT VALIDATION done...
    else
        {
         QMessageBox::information(this,"DONE","DATA IS ENTERED");
            close();
            }
}

thirdDialog::~thirdDialog()
{
    delete ui;
}


