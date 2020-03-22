#include "contenedor_graficas.h"
#include "ui_contenedor_graficas.h"

contenedor_graficas::contenedor_graficas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::contenedor_graficas)
{
    ui->setupUi(this);
}

contenedor_graficas::~contenedor_graficas()
{
    delete ui;
}
