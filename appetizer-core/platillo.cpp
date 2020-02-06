#include "platillo.h"
#include "ui_platillo.h"

Platillo::Platillo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Platillo)
{
    ui->setupUi(this);
}

Platillo::~Platillo()
{
    delete ui;
}
