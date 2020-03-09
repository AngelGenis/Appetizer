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

void tarjetaOrden::llenarOrden(QString nOrden, QString precioOrden)
{
    ui->numero_orden->setText(nOrden);
    ui->precio->setText(precioOrden);
}
