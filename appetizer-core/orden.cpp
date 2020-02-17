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

 QGridLayout* Orden::glay;
QString Orden::nombre="";
int Orden::indice=0;
Platillo* Orden::plati4;
QList<QList<Platillo1>*> Orden::ordenesp;
QComboBox* Orden::cbox;
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
   glay=ui->listaPlatillos;
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
/*
    Platillo *plati = new Platillo();
    Platillo *plati2 = new Platillo();
    ui->listaPlatillos->addWidget(plati);
    ui->listaPlatillos->addWidget(plati2);
    Platillo *plati3 = new Platillo();
    ui->listaPlatillos->addWidget(plati3);
*/
numCuenta=1;

cbox=ui->cb_Cuentas;


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

void Orden::on_btnAgregarCuenta_clicked()
{

    cbox->addItem("Cuenta "+ QString::number(cbox->count() + 1));

    clearLayout(ui->listaPlatillos);



    QList<Platillo1> *platillos=new QList<Platillo1>;
    ordenesp.append(platillos);
    qDebug()<<"El tamanio es "<<ordenesp.size();


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
void Orden::on_tarjeta_clickeada(Platillo1 platillo){

    nombre=platillo.nombre;
    indice=platillo.id;
    plati4=new Platillo(indice);
    mostrarWidgets(plati4);
qDebug()<<"El indice es "<<indice;
qDebug()<<"Los items son "<<cbox->count();
    if(ordenesp.size()==0){
        QList<Platillo1> *platillos=new QList<Platillo1>;
        ordenesp.append(platillos);
        qDebug()<<"Entro condicion 1";
    }
    if(cbox->count()>=1){
        QList<Platillo1> *lista=ordenesp.at(cbox->currentIndex());
        lista->append(platillo);
        qDebug()<<"Entro condicion 2";
    }
    connect(plati4,&Platillo::clicked,this,&Orden::platilloEliminado);

}

 QGridLayout* Orden::devolverLay(){
   /*
     laynueva=ui->listaPlatillos;
    qDebug()<<"El original dice"<<laynueva->rowCount();
    QPushButton *b=new QPushButton();
    b->setText("Hola");
   // ui->listaPlatillos->addWidget(b);
*/
    return laynueva;
}

 void Orden::ponerPlatillos(){
  Platillo *plati5=new Platillo();

    glay->addWidget(plati5);

 }


 void Orden::mostrarWidgets(QWidget* plat){

     glay->addWidget(plat);


 }

void Orden::on_cb_Cuentas_currentIndexChanged(int index)
{




if(!ordenesp.isEmpty()){
         QList<Platillo1> *lista=ordenesp.at(index);
         int i=0;
        clearLayout(glay);
        qDebug()<<lista->size();
         while (i<lista->size()) {

            Platillo1 agregado=lista->at(i);
            qDebug()<<"El id es "<<agregado.id;
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
