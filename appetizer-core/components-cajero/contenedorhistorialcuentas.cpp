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

    QSqlQuery query0;
    query0.prepare("SELECT DISTINCT id_mesa from orden order by id_mesa");
    query0.exec();


    int i=0;
    int row = 0;
    int col = 0;

    QString precioTotal;
    while (query0.next()) {
        QString idMesa = query0.value(0).toString();

        QSqlQuery query;
        query.prepare("SELECT SUM(c.precio_total), ord.hora_fecha "
                      "FROM cuenta as c "
                      "INNER JOIN orden as ord "
                      "ON c.id_orden = ord.id_orden where ord.id_mesa =" + idMesa);

        query.exec();

        while(query.next()){
            QString precioTotal = query.value(0).toString();
            QString horaFecha = query.value(1).toString();


            QStringList list1 = horaFecha.split('T');
            qDebug()<<list1.at(0);
            qDebug()<<list1.at(1);
            QString fecha = list1.at(0);
            QString hora = list1.at(1);

            row = i/1;
            col= i%1;

            tarjetaCuenta *tarjeta = new tarjetaCuenta();
            tarjeta->llenarCuenta(idMesa, fecha, hora,precioTotal);
            i++;
            ui->gridLayout->addWidget(tarjeta, row, col);
        }

    }


}

contenedorHistorialCuentas::~contenedorHistorialCuentas()
{
    delete ui;
}
