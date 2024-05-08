#ifndef THIRDDIALOG_H
#define THIRDDIALOG_H

#include <QDialog>
#include "QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlQuery"
#include <QDebug>

namespace Ui {
class thirdDialog;
}

class thirdDialog : public QDialog
{
    Q_OBJECT

public:
    explicit thirdDialog(QWidget *parent = nullptr);
    ~thirdDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::thirdDialog *ui;
};

#endif // THIRDDIALOG_H
