#include "tarjetacuenta.h"
#include "ui_tarjetacuenta.h"

tarjetaCuenta::tarjetaCuenta(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tarjetaCuenta)
{
    ui->setupUi(this);
}

tarjetaCuenta::~tarjetaCuenta()
{
    delete ui;
}
