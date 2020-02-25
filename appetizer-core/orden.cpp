#include "orden.h"
#include "ui_orden.h"
#include "platillo.h"
#include "orderservice.h"
#include "platilloservice.h"
#include "services/databaseconnection.h"
#include "components-manager/crudplatillo.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>
#include <QApplication>
#include <QList>
#include <QSqlError>
#include <QDebug>


QString Orden::nombrePlat = "", Orden::coment="";
int Orden::idPlati = 0, Orden::cantidad = 1, Orden::auxidPlati;
Platillo *Orden::plati;
Orden *Orden::ord;
QGridLayout *Orden::gl;
QList<int> Orden::idsPlati, Orden::keys;
QList<QString> Orden::nombresPlati;
QMultiMap<int, int> Orden::cant;
QMultiMap<int, QString> Orden::comen;




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
    if(orden->crearOrden(fechaHora, idMesa) == true){
        qDebug () << "Se creo orden";
        idOrden=orden->getIdOrden();

        for (int i=0; i<idsPlati.size(); ++i){
            cantidad=1;
            coment="";
            //for (int i=0; i<nombresPlati.size(); ++i){
            qDebug() << "NO entra a ciclos" ;
            //cantidad=1;
            for (auto key : cant.uniqueKeys())
                {
                cantidad = cant.value(key, cant.first());
                qDebug() << "key: " << key;
                qDebug() << "Cantidad diferente a 1: " << cantidad;
                for (auto key2 : comen.uniqueKeys()){
                    coment = comen.value(key2, comen.first());
                    qDebug() << "key2: " << key2;
                     qDebug()<< "Cantidad diferente a 1: " << cantidad << " y comentario diferente a vacio: " << coment;
                    if((idsPlati.at(i) == key) && (idsPlati.at(i) == key2)){
                        //if(orden->identificarPlatiOBebida(nombresPlati.at(i)) == 1){
                            if(orden->crearOrdenPlatillo(idOrden, idsPlati.at(i), cantidad, coment) == true){
                                qDebug () << "Se crearon platillos en orden";
                            }
                         /*}else if(orden->identificarPlatiOBebida(nombresPlati.at(i)) == 2){
                                qDebug() << "es bebida";
                                if(orden->crearOrdenBebida(idOrden, 1) == true){
                                    qDebug () << "Se crearon bebidas en orden";
                                }
                           }*/
                        }
                    }
                /*if((idsPlati.at(i) == key)){
                if(coment==nullptr){
                    if(orden->crearOrdenPlatillo(idOrden, idsPlati.at(i), cantidad, coment) == true){
                        qDebug () << "Se crearon platillos en orden";
                    }
                }
                }*/
                }
            if(cantidad==1){
                qDebug() << "Cantidad igual a 1: " << cantidad;
                 for (auto key2 : comen.uniqueKeys()){
                     coment = comen.value(key2, comen.first());
                     qDebug() << "Cantidad igual a 1: " << cantidad << " y comentario diferente de vacio: " << coment;
                     if((idsPlati.at(i) == key2)){
                         if(orden->crearOrdenPlatillo(idOrden, idsPlati.at(i), cantidad, coment) == true){
                             qDebug () << "Se crearon platillos en orden";
                         }
                     }
                 }
                 }
            if(cantidad==1 && coment == ""){
                qDebug() << "Cantidad igual a 1: " << cantidad << " y comentario igual a vacio: " << coment;
                if(orden->crearOrdenPlatillo(idOrden, idsPlati.at(i), cantidad, coment) == true){
                    qDebug () << "Se crearon platillos en orden";
                }
             }
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
    //ord = new Orden();
    plati = new Platillo(idPlati);
    idsPlati.append(platillo.id);
    nombresPlati.append(platillo.nombre);
    mostrarWidgets(plati);
    countWidgets();
    ord = this;
    connect(plati, &Platillo::changeValue, ord, &Orden::obtenerCantidad);
    connect(plati, &Platillo::elimWid, ord, &Orden::eliminarWidgets);
    connect(plati, &Platillo::saveComent, ord, &Orden::obtenerComentario);

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
    //QLayoutItem *item = gl->wi
    //delete gl->widget();
    //qDebug() << pla;
    //pla = new Platillo();
    while (QLayoutItem *item = gl->takeAt(0)){
        Q_ASSERT(!item->layout()); // otherwise the layout will leak
        /*qDebug () << item;
        qDebug()<<pla->winId();
        qDebug () <<item->widget()->winId();*/
        if(item->widget()->winId() == pla->winId()){
            delete item->widget();
            qDebug() << item;
            delete item;
            qDebug() << gl->rowCount();
            /*delete item->widget();
            delete item;*/
        }
       // pla = gl->takeAt(1)->widget();
    }
    /*gl->removeWidget(pla);
    gl->removeItem();*/
}

void Orden::on_btn_imprimir_clicked()
{
 CrudPlatillo *crud = new CrudPlatillo();
 crud->show();

}

void Orden::obtenerCantidad(int cantidad, int id){
    /*this->cantidad = cantidad;
    this->auxidPlati = id;
    qDebug() << "Valor del spinbox: " << this->cantidad;
    qDebug() << "Id platillo: " << this->auxidPlati;*/
    cant.insert(id, cantidad);
    /*int i = cant.uniqueKeys();
    if(!keys.contains(cant.uniqueKeys())
    {
        keys.append(cant.uniqueKeys());
    }*/
}

void Orden::obtenerComentario(int id, QString com){
    comen.insert(id, com);
}
