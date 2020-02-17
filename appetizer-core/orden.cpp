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
#include <QList>
#include <QSqlError>
#include <QDebug>

QString Orden::nombrePlat = "";
int Orden::idPlati = 0;
Platillo *Orden::plati;
QGridLayout *Orden::gl;
QList<int> Orden::idsPlati;




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
   /* qDebug() <<"Id platillo: " << idPlati;
    qDebug() <<"Nombre platillo: " << nombrePlat;*/
    if(orden->crearOrden(fechaHora, idMesa) == true){
        qDebug () << "Se creo orden";
        idOrden=orden->getIdOrden();
        for (int i=0; i<idsPlati.size(); ++i){
            QString coment = platServ->setComentario();
            if(orden->crearOrdenPlatillo(idOrden, idsPlati.at(i), plati->getCantidad(), "") == true){
                qDebug () << "Se crearon platillos en orden";
            }
            if(platServ->guardarComentario(idOrden, idsPlati.at(i), coment)){
                qDebug () << "Se agregaron comentarios";
            }
        }
            /*if(orden->crearOrdenBebida(idOrden, 1) == true){
                qDebug () << "Se crearon bebidas en orden";
            }*/
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
    idsPlati.append(platillo.id);
    mostrarWidgets(plati);

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

int Orden::countWidgets(){
    int i= gl->rowCount();
    //int i = ui->listaPlatillos->columnCount();
    qDebug () << "numero de widgets: " << i;
    return i;
}

void Orden::setPlatillo(int idPla){
    prueba=idPla;
    qDebug() << "prueba: " << prueba;
}


void Orden::mostrarWidgets(QWidget *plat){
    gl->addWidget(plat);
        qDebug() << idsPlati << " ";

}

void Orden::eliminarWidgets(QWidget *pla){
    gl->removeWidget(pla);
}

void Orden::on_btn_imprimir_clicked()
{
    countWidgets();
    for (int i=0; i<idsPlati.size(); ++i){
            qDebug() << idsPlati.at(i)  << "Posición: ";
    }
}
