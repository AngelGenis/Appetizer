#include "orden.h"
#include "ui_orden.h"
#include "platillo.h"
#include "orderservice.h"
#include "services/databaseconnection.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>

#include <QSqlError>
#include <QDebug>


Orden::Orden(QWidget *parent) :
    QWidget(parent),

    ui(new Ui::Orden),
    db(DatabaseConnection::connect())
{
   if (!db.isValid() || !db.isOpen())
       qDebug() << db.lastError().text();

    ui->setupUi(this);
    actualizarCuentasItems();
   /* Platillo *myListItem = new Platillo();
    QListWidgetItem *item = new QListWidgetItem();
   // ui->ordenesListWidget->addItem(Platillo);
    ui->ordenesListWidget->addItem(item);
    //item->setSizeHint (myListItem->sizeHint ());
    ui->ordenesListWidget->setItemWidget(item, myListItem);*/

    QString f="yyyy-MM-dd HH:mm:ss";
    //fechaHora = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    QDateTime b = QDateTime::currentDateTime();
    as = b.toString(f);
    fechaHora = QDateTime::fromString(as);
    //fechaHora = QDateTime::fromString(as,f);
    /*fechaHora = QDateTime::fromString("yyyy-MM-dd");
    f = fechaHora.toString() + QDateTime::fromString("hh:mm:ss");*/
    qDebug() << as;
    qDebug() << fechaHora;
    idMesa=1;

    Platillo *plati = new Platillo();
    Platillo *plati2 = new Platillo();
    ui->listaPlatillos->addWidget(plati);
    ui->listaPlatillos->addWidget(plati2);
    Platillo *plati3 = new Platillo();
    ui->listaPlatillos->addWidget(plati3);
}

Orden::~Orden()
{
    delete ui;
}

void Orden::on_btn_ordenar_clicked()
{
    if(orden->crearOrden(as, idMesa) == true){
        qDebug () << "Se creo orden";
        if(orden->crearOrdenPlatillo(5, 1) == true){
            qDebug () << "Se crearon platillos en orden";
        }
        if(orden->crearOrdenBebida(5, 1) == true){
            qDebug () << "Se crearon bebidas en orden";
        }
    }
}

void Orden::on_tarjeta_clickeada(Platillo1 platillo){
/*
 * Liz,
 * Acá recibes el platillo que clickearon.
 * Haz lo que debas con él.
 * Platillo1 es un struct definido en tarjetaplatillo.h
 *
 * Prueba dando click en una tarjeta,se imprimira su nombre.
 */
    qDebug() << platillo.nombre;
}

void Orden::actualizarCuentasItems()
{
    QSqlQuery query;
    ui->cb_Cuentas->clear();
    query.exec("SELECT id_cuenta FROM Cuenta");
    while(query.next()){
        ui->cb_Cuentas->addItem("Cuenta: " + query.record().value(0).toString());
    }
    for(int i=0; i < ui->cb_Cuentas->count(); ++i){
        QString itemCombo;
        itemCombo = ui->cb_Cuentas->itemText(i);
    }
}
