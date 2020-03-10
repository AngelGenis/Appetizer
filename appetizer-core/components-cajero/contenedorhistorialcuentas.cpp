#include "contenedorhistorialcuentas.h"
#include "ui_contenedorhistorialcuentas.h"
#include "services/databaseconnection.h"
#include "components-cajero/tarjetacuenta.h"

#include <QDebug>
#include <QSqlError>

contenedorHistorialCuentas::contenedorHistorialCuentas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::contenedorHistorialCuentas),
    db(DatabaseConnection::connect())
{
    if (!db.isValid() || !db.isOpen())
        qDebug() << db.lastError().text();
    ui->setupUi(this);


    QSqlQuery query;
    query.prepare("SELECT c.id_cuenta,c.id_orden, c.precio_total, ord.id_mesa, ord.hora_fecha "
                  "FROM cuenta as c "
                  "INNER JOIN orden as ord "
                  "ON c.id_orden = ord.id_orden;");
    query.exec();


    int i=0;
    int row = 0;
    int col = 0;

    while(query.next()){
        QString id_cuenta = query.value(0).toString();
        QString id_orden = query.value(1).toString();
        QString precioTotal = query.value(2).toString();
        QString mesa = query.value(3).toString();
        QString horaFecha = query.value(4).toString();

        QStringList list1 = horaFecha.split('T');
        qDebug()<<list1.at(0);
        qDebug()<<list1.at(1);
        QString fecha = list1.at(0);
        QString hora = list1.at(1);

        row = i/1;
        col= i%1;

        tarjetaCuenta *tarjeta = new tarjetaCuenta();
        tarjeta->llenarCuenta(id_orden, mesa, fecha, hora,precioTotal);
        i++;
        ui->gridLayout->addWidget(tarjeta, row, col);

    }
}

contenedorHistorialCuentas::~contenedorHistorialCuentas()
{
    delete ui;
}
