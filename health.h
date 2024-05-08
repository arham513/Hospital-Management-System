#ifndef HEALTH_H
#define HEALTH_H

#include <QDialog>
#include "QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlQuery"

namespace Ui {
class health;
}

class health : public QDialog
{
    Q_OBJECT

public:
    explicit health(QWidget *parent = nullptr);
    ~health();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::health *ui;
};

#endif // HEALTH_H
