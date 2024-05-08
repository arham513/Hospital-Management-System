#ifndef APPDIALOG_H
#define APPDIALOG_H

#include <QDialog>

namespace Ui {
class appdialog;
}

class appdialog : public QDialog
{
    Q_OBJECT

public:
    explicit appdialog(QWidget *parent = nullptr);
    ~appdialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::appdialog *ui;
};

#endif // APPDIALOG_H
