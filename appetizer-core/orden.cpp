#include "orden.h"
#include "ui_orden.h"
#include "platillo.h"
#include "orderservice.h"
#include "platilloservice.h"
#include "services/databaseconnection.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>

#include <QSqlError>
#include <QDebug>


Orden::Orden(QWidget *parent) :
    QWidget(parent),

    ui(new Ui::Orden),
    orden(new OrderService),
    platServ(new PlatilloService),
    db(DatabaseConnection::connect())
{
   if (!db.isValid() || !db.isOpen())
       qDebug() << db.lastError().text();

    ui->setupUi(this);
    actualizarCuentasItems();


    QString f="yyyy-MM-dd HH:MM:ss";
    QDateTime b = QDateTime::currentDateTime();
    fechaHora = b.toString(f);
    qDebug() << fechaHora;
    idMesa=1;


    Platillo *plati = new Platillo();
    ui->listaPlatillos->addWidget(plati);
    Platillo *plati2 = new Platillo();
    //ui->listaPlatillos->addWidget(plati);
    ui->listaPlatillos->addWidget(plati2);
    Platillo *plati3 = new Platillo();
    ui->listaPlatillos->addWidget(plati3);
    countWidgets();
}

Orden::~Orden()
{
    delete ui;
}

void Orden::on_btn_ordenar_clicked()
{
    qDebug() <<"Id platillo: " << idPlatillo;
    qDebug() <<"Nombre platillo: " << nombrePlat;
    if(orden->crearOrden(fechaHora, idMesa) == true){
        qDebug () << "Se creo orden";
        QString coment = platServ->setComentario();
        idOrden=orden->getIdOrden();
        if(platServ->guardarComentario(idOrden, idPlatillo, coment)){
            qDebug () << "Se agregaron comentarios";
        }
        if(orden->crearOrdenPlatillo(idOrden, 1) == true){
            qDebug () << "Se crearon platillos en orden";
        }
        if(orden->crearOrdenBebida(idOrden, 1) == true){
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
    qDebug() << platillo.id;
    nombrePlat = platillo.nombre;
   /* idPlatillo = platillo.id;
    qDebug() << idPlatillo;*/
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

void Orden::countWidgets(){
    int i= ui->listaPlatillos->rowCount();
    qDebug () << "numero de widgets: " << i;
}
