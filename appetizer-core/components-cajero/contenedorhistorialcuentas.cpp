#include "contenedorhistorialcuentas.h"
#include "ui_contenedorhistorialcuentas.h"

contenedorHistorialCuentas::contenedorHistorialCuentas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::contenedorHistorialCuentas)
{
    ui->setupUi(this);
}

contenedorHistorialCuentas::~contenedorHistorialCuentas()
{
    delete ui;
}
