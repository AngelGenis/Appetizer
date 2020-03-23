#include "platillo_cuenta.h"
#include "ui_platillo_cuenta.h"

platillo_cuenta::platillo_cuenta(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::platillo_cuenta)
{
    ui->setupUi(this);

}

platillo_cuenta::~platillo_cuenta()
{
    delete ui;
}

void platillo_cuenta::llenarPlatillo(QString cantidad, QString nombre, QString total)
{
    ui->nombrePlat->setText(nombre);
    ui->cantidad->setText(cantidad);
    ui->totalPlat->setText("$"+total);
}
