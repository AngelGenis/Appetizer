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


QString Orden::nombrePlat = "", Orden::coment="";
int Orden::idPlati = 0, Orden::cantidad = 1, Orden::auxidPlati;
Platillo *Orden::plati;
Orden *Orden::ord;
QGridLayout *Orden::gl;
QList<int> Orden::idsPlati;
QList<QString> Orden::nombresPlati;
QMultiMap<int, int> Orden::cant;
QMultiMap<int, QString> Orden::comen;




QList<QList<Platillo1>*> Orden::ordenesp;
QComboBox* Orden::cbox;


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
   cbox=ui->cb_Cuentas;
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
            for (auto key : cant.uniqueKeys())
                {
                cantidad = cant.value(key, cant.first());
                for (auto key2 : comen.uniqueKeys()){
                    coment = comen.value(key2, comen.first());
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
                 for (auto key2 : comen.uniqueKeys()){
                     coment = comen.value(key2, comen.first());
                     if((idsPlati.at(i) == key2)){
                         if(orden->crearOrdenPlatillo(idOrden, idsPlati.at(i), cantidad, coment) == true){
                             qDebug () << "Se crearon platillos en orden";
                         }
                     }
                 }
                 }
            if(cantidad==1 && coment == ""){
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
    QList<Platillo1> *lista=ordenesp.at(cbox->currentIndex());
    lista->append(platillo);
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
    countWidgets();
    for (int i=0; i<idsPlati.size(); ++i){
            qDebug() << idsPlati.at(i)  << "Posición: ";
    }

}

void Orden::obtenerCantidad(int cantidad, int id){
    /*this->cantidad = cantidad;
    this->auxidPlati = id;
    qDebug() << "Valor del spinbox: " << this->cantidad;
    qDebug() << "Id platillo: " << this->auxidPlati;*/
    cant.insert(id, cantidad);
}

void Orden::obtenerComentario(int id, QString com){
    comen.insert(id, com);
}
void Orden::on_btnAgregarCuenta_clicked()
{

    cbox->addItem("Cuenta "+ QString::number(cbox->count() + 1));

    clearLayout(ui->listaPlatillos);



    QList<Platillo1> *platillos=new QList<Platillo1>;
    ordenesp.append(platillos);
    qDebug()<<"El tamanio es "<<ordenesp.size();
    cbox->setCurrentIndex(cbox->count()-1);

}
void Orden::clearLayout(QLayout *layout) {
    QLayoutItem *item;
    while((item = layout->takeAt(0))) {
        if (item->layout()) {
            clearLayout(item->layout());
            delete item->layout();
        }
        if (item->widget()) {
           delete item->widget();
        }
        delete item;
    }
}



void Orden::on_cb_Cuentas_currentIndexChanged(int index)
{




if(!ordenesp.isEmpty()){
         QList<Platillo1> *lista=ordenesp.at(index);
         int i=0;
        clearLayout(gl);

         while (i<lista->size()) {

            Platillo1 agregado=lista->at(i);

             Platillo* plato=new Platillo(agregado.id);
             ui->listaPlatillos->addWidget(plato);

             i++;
         }

}

}



void Orden::platilloEliminado(int id){


    QList<Platillo1> *lista=ordenesp.at(cbox->currentIndex());
    int i=0;

    while (i<lista->size()) {
        if(id==lista->at(i).id){
            lista->takeAt(i);
            break;
        }


        i++;
    }
}
