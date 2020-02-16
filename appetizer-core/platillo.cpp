#include "platillo.h"
#include "ui_platillo.h"
#include "platilloservice.h"
#include <QSignalMapper>

Platillo::Platillo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Platillo),
    plat(new PlatilloService)
{

    ui->setupUi(this);
    ui->lbNombrePlatillo->setText(plat->obtenerPlatillo(idPlatillo));
    ui->lbSubtotal->setText("$" + plat->obtenerPrecio());

}


Platillo::Platillo(int _id,QWidget *parent):
    QWidget(parent),
    ui(new Ui::Platillo),
    plat(new PlatilloService){
    ui->setupUi(this);
    idPlatillo=_id;
    ui->lbNombrePlatillo->setText(plat->obtenerPlatillo(idPlatillo));
    ui->lbSubtotal->setText("$" + plat->obtenerPrecio());


}

Platillo::~Platillo()
{
    delete ui;
}

void Platillo::on_btnEliminar_clicked()
{


    emit clicked(idPlatillo);

    close();

}

