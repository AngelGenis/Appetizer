#include "platillo.h"
#include "ui_platillo.h"
#include "platilloservice.h"
#include <QDebug>

Platillo::Platillo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Platillo)
{

    ui->setupUi(this);
    ui->lbNombrePlatillo->setText(plat->obtenerPlatillo());
    ui->lbSubtotal->setText("$" + plat->obtenerPrecio());
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
    close();
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
}
