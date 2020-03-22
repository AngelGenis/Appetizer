#include "tarjetaempleado.h"
#include "ui_tarjetaempleado.h"

TarjetaEmpleado::TarjetaEmpleado(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TarjetaEmpleado)
{
    ui->setupUi(this);
}

TarjetaEmpleado::~TarjetaEmpleado()
{
    delete ui;
}

QWidget *TarjetaEmpleado::wid(){
    return this;
}
