#include "tarjetacuenta.h"
#include "ui_tarjetacuenta.h"

tarjetaCuenta::tarjetaCuenta(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tarjetaCuenta)
{
    ui->setupUi(this);
    ui->contenedor_ordenes->hide();
    ui->scrollArea->hide();
}

tarjetaCuenta::~tarjetaCuenta()
{
    delete ui;
}

void tarjetaCuenta::llenarCuenta(QString idOrden, QString mesa, QString fecha, QString hora, QString precioCuenta){
    ui->numero_mesa->setText(mesa);
    ui->fecha->setText(fecha);
    ui->hora->setText(hora);
    ui->precio->setText(precioCuenta);

    QSqlQuery query;
    query.prepare("SELECT urlFoto FROM platillo WHERE id_platillo = :id_platillo");
    query.bindValue(":id_platillo", idOrden);

    query.exec();
}


void tarjetaCuenta::on_btn_mesa_clicked(){
    ui->contenedor_ordenes->show();
    ui->scrollArea->show();
}
