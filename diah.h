#ifndef DIAH_H
#define DIAH_H

#include <QDialog>

namespace Ui {
class Diah;
}

class Diah : public QDialog
{
    Q_OBJECT

public:
    explicit Diah(QWidget *parent = nullptr);
    ~Diah();

private:
    Ui::Diah *ui;
};

#endif // DIAH_H
