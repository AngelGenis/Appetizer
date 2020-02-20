#include "platillo.h"
#include "ui_platillo.h"
#include "platilloservice.h"
#include "orden.h"
#include <QDebug>

Platillo::Platillo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Platillo),
    plat(new PlatilloService)
{

    ui->setupUi(this);
    ui->lbNombrePlatillo->setText(plat->obtenerPlatillo(idPlatillo));
    ui->lbSubtotal->setText("$" + plat->obtenerPrecio(idPlatillo));
    ui->lineEComentarios->hide();
    ui->btnGuardarComentario->hide();
    ui->btnCancelarComentario->hide();

}

Platillo::Platillo(int _id,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Platillo),
    plat(new PlatilloService)
{

    idPlatillo = _id;
    qDebug () << "Id en el wid platillo: " << idPlatillo;
    ui->setupUi(this);
    ui->sbCantidad->setMinimum(1);
    sub = plat->obtenerPrecio(idPlatillo).toInt();
    ui->lbNombrePlatillo->setText(plat->obtenerPlatillo(idPlatillo));
    ui->lbSubtotal->setText("$"+plat->obtenerPrecio(idPlatillo));
    ui->lineEComentarios->hide();
    ui->btnGuardarComentario->hide();
    ui->btnCancelarComentario->hide();
}


Platillo::~Platillo()
{
    delete ui;
}

void Platillo::on_btnEliminar_clicked()
{
    plati = this;
    Orden::eliminarWidgets(plati);

}


void Platillo::on_btnComentarios_clicked()
{
    ui->lineEComentarios->show();
    ui->btnGuardarComentario->show();
    ui->btnCancelarComentario->show();
    ui->btnEliminar->hide();
    ui->btnComentarios->hide();
    ui->lbTotal->hide();
    ui->lbSubtotal->hide();
    ui->sbCantidad->hide();
    ui->lbNombrePlatillo->hide();
}

void Platillo::on_btnCancelarComentario_clicked()
{
    ui->lineEComentarios->hide();
    ui->btnGuardarComentario->hide();
    ui->btnCancelarComentario->hide();
    ui->btnEliminar->show();
    ui->btnComentarios->show();
    ui->lbTotal->show();
    ui->lbSubtotal->show();
    ui->sbCantidad->show();
    ui->lbNombrePlatillo->show();
}

void Platillo::on_btnGuardarComentario_clicked()
{
    comentario = ui->lineEComentarios->text();
        /*if(plat->guardarComentario(idOrden, idPlatillo, comentario)){
            qDebug () << "Se ingresó comentario";

        }*/
    plat->getComentario(comentario);
    ui->lineEComentarios->hide();
    ui->btnGuardarComentario->hide();
    ui->btnCancelarComentario->hide();
    ui->btnEliminar->show();
    ui->btnComentarios->show();
    ui->lbTotal->show();
    ui->lbSubtotal->show();
    ui->sbCantidad->show();
    ui->lbNombrePlatillo->show();
}

int Platillo::getPlatillo(){
    return idPlatillo;
}

int Platillo::getCantidad(){
    return cantidad;
}

void Platillo::on_sbCantidad_valueChanged(int arg1)
{
    /*ord = new Orden();
    plati = new Platillo();

    //Platillo *plat =new Platillo();
    //ord = new Orden();
    connect(plati, &Platillo::changeValue, ord, &Orden::obtenerCantidad);*/
    int i= sub * arg1;
    QString total="$"+QString::number(i);
    ui->lbTotal->setText(total);
    ui->lbSubtotal->setText("$"+plat->obtenerPrecio(idPlatillo));
    cantidad=arg1;
    emit changeValue(arg1, idPlatillo);

}
