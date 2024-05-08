#include "diah.h"
#include "ui_diah.h"

Diah::Diah(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Diah)
{
    ui->setupUi(this);
}

Diah::~Diah()
{
    delete ui;
}
