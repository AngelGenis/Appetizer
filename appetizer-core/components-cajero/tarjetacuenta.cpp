#include "tarjetacuenta.h"
#include "ui_tarjetacuenta.h"
#include "services/databaseconnection.h"
#include "components-cajero/tarjetaorden.h"

#include <QDebug>
#include <QSqlError>

tarjetaCuenta::tarjetaCuenta(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tarjetaCuenta),
    db(DatabaseConnection::connect())
{
    if (!db.isValid() || !db.isOpen())
        qDebug() << db.lastError().text();
    ui->setupUi(this);
    ui->contenedor_ordenes->hide();
    ui->scrollArea->hide();



}

tarjetaCuenta::~tarjetaCuenta()
{
    delete ui;
}

void tarjetaCuenta::llenarCuenta(QString idOrden, QString mesa, QString fecha, QString hora, QString precioCuenta){
    this->mesa = mesa;
    ui->numero_mesa->setText("Mesa "+mesa);
    ui->fecha->setText(fecha);
    ui->hora->setText(hora);
    ui->precio->setText("$"+precioCuenta);

    QSqlQuery query;
    query.prepare("SELECT c.id_orden, c.precio_total "
                  "FROM cuenta as c "
                  "INNER JOIN orden as ord "
                  "ON c.id_orden = ord.id_orden "
                  "where ord.id_mesa = " + mesa);
    qDebug()<<"idMesa"<<mesa;
    qDebug()<<query.last();
    query.exec();

    int i=0;
    int row = 0;
    int col = 0;

    while(query.next()){
        QString idOrden = query.value(0).toString();
        QString precio = query.value(1).toString();

        row = i/1;
        col= i%1;

        tarjetaOrden *orden = new tarjetaOrden();
        orden->llenarOrden(idOrden,precio);
        i++;
        ui->gridLayout->addWidget(orden, row, col);

    }

}


void tarjetaCuenta::on_btn_mesa_clicked(){
    if(this->band == true){
        band = false;
        ui->contenedor_ordenes->hide();
        ui->scrollArea->hide();
    }else{
        band = true;
        ui->contenedor_ordenes->show();
        ui->scrollArea->show();
    }
}
