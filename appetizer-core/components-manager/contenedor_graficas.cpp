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

void contenedor_graficas::on_btn_ingresos_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void contenedor_graficas::on_btn_densidad_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void contenedor_graficas::on_btn_popularidad_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
