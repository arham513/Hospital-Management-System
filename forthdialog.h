#ifndef FORTHDIALOG_H
#define FORTHDIALOG_H

#include <QDialog>

namespace Ui {
class forthdialog;
}

class forthdialog : public QDialog
{
    Q_OBJECT

public:
    explicit forthdialog(QWidget *parent = nullptr);
    ~forthdialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::forthdialog *ui;
};

#endif // FORTHDIALOG_H
