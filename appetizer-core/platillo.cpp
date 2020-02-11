#include "platillo.h"
#include "ui_platillo.h"
#include "platilloservice.h"


Platillo::Platillo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Platillo)
{

    ui->setupUi(this);
    ui->lbNombrePlatillo->setText(plat->obtenerPlatillo());
    ui->lbSubtotal->setText("$" + plat->obtenerPrecio());

}

Platillo::~Platillo()
{
    delete ui;
}

void Platillo::on_btnEliminar_clicked()
{
    close();
}

