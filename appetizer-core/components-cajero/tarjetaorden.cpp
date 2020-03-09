#include "tarjetaorden.h"
#include "ui_tarjetaorden.h"

tarjetaOrden::tarjetaOrden(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tarjetaOrden)
{
    ui->setupUi(this);
}

tarjetaOrden::~tarjetaOrden()
{
    delete ui;
}
