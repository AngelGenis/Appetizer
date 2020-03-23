#include "orden_cuenta.h"
#include "ui_orden_cuenta.h"
#include "services/databaseconnection.h"
#include "components-cajero/platillo_cuenta.h"

#include <QDebug>
#include <QSqlError>

orden_cuenta::orden_cuenta(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::orden_cuenta),
    db(DatabaseConnection::connect())
{
    if (!db.isValid() || !db.isOpen())
        qDebug() << db.lastError().text();

    ui->setupUi(this);
    QSqlQuery query;

    llenarPlatillos();

    query.prepare("SELECT orden.id_mesa, orden.id_orden, cuenta.id_cuenta, cuenta.precio_total "
                  "FROM cuenta "
                  "INNER JOIN orden "
                  "ON cuenta.id_orden = orden.id_orden "
                  "WHERE orden.id_mesa = 5");
    query.exec();
    int tam = 0;

    qDebug()<<query.lastQuery();

    double iva = 0;
    double total = 0;

    while(query.next()){
        tam++;

        QString id_mesa = query.value(0).toString();
        QString id_orden = query.value(1).toString();
        QString id_cuenta = query.value(2).toString();
        QString subtotal = query.value(3).toString();


        iva = (subtotal.toDouble() * 12) / 100;
        total = iva + subtotal.toDouble();

        llenarDatos(subtotal, QString::number(total) , QString::number(iva));
    }

    qDebug()<<"Tamaño de la query: "<<tam;

}

orden_cuenta::~orden_cuenta()
{
    delete ui;
}

void orden_cuenta::llenarDatos(QString subtotal,QString total, QString iva)
{
    ui->subtotal->setText("$"+subtotal);
    ui->total->setText("$"+total);
    ui->iva->setText("$"+iva);
}

void orden_cuenta::llenarPlatillos(){
    QSqlQuery llenarWidget;

    llenarWidget.prepare("SELECT po.cantidad, p.nombre, precio FROM platilloorden AS po "
                         "INNER JOIN platillo as p "
                         "ON po.id_platillo = p.id_platillo "
                         "WHERE po.id_orden = 1;");
    llenarWidget.exec();

    int i=0;
    int row = 0;
    int col = 0;

    while(llenarWidget.next()){
        QString cantidad = llenarWidget.value(0).toString();
        QString nombre = llenarWidget.value(1).toString();
        QString precio = llenarWidget.value(2).toString();

        row = i/1;
        col= i%1;

        double total = cantidad.toDouble() * precio.toDouble();

        platillo_cuenta *tarjeta = new platillo_cuenta();
        tarjeta->llenarPlatillo(cantidad, nombre, QString::number(total));
        i++;
        ui->gridLayout->addWidget(tarjeta, row, col);

    }

}
