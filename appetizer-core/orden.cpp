#include "orden.h"
#include "ui_orden.h"
#include "platillo.h"
#include "orderservice.h"
#include "platilloservice.h"
#include "services/databaseconnection.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>
#include <QApplication>

#include <QSqlError>
#include <QDebug>

QString Orden::nombrePlat = "";
int Orden::idPlati = 0;
Platillo *Orden::plati;
QGridLayout *Orden::gl;




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
    gl = ui->listaPlatillos;



    QString f="yyyy-MM-dd HH:MM:ss";
    QDateTime b = QDateTime::currentDateTime();
    fechaHora = b.toString(f);
    qDebug() << fechaHora;
    idMesa=1;
    //countWidgets();
}

Orden::~Orden()
{
    delete ui;
}

void Orden::on_btn_ordenar_clicked()
{
    qDebug() <<"Id platillo: " << idPlati;
    qDebug() <<"Nombre platillo: " << nombrePlat;
    if(orden->crearOrden(fechaHora, idMesa) == true){
        qDebug () << "Se creo orden";
        QString coment = platServ->setComentario();
        idOrden=orden->getIdOrden();
        if(platServ->guardarComentario(idOrden, idPlati, coment)){
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
    nombrePlat = platillo.nombre;
    idPlati = platillo.id;
    qDebug() << "Nombre: " << nombrePlat;
    qDebug() << "Id: " << idPlati;
    //setPlatillo(platillo.id);
    plati = new Platillo(idPlati);
    mostrarWidgets(plati);
    countWidgets();

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
    int i= gl->rowCount();
    //int i = ui->listaPlatillos->columnCount();
    qDebug () << "numero de widgets: " << i;
}

void Orden::setPlatillo(int idPla){
    prueba=idPla;
    qDebug() << "prueba: " << prueba;
}


void Orden::mostrarWidgets(QWidget *plat){
    gl->addWidget(plat);
}
