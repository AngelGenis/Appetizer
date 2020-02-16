#include "menuplatillos.h"
#include "tarjetaplatillo.h"
#include "ui_menuplatillos.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include<QSignalMapper>


MenuPlatillos::MenuPlatillos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuPlatillos)
{
    ui->setupUi(this);
    ui->buscador->setAttribute(Qt::WA_MacShowFocusRect,0);

orden=new Orden();

    llenarCatalogo();
    llenarCategorias();
}

void MenuPlatillos::limpiarLayout(QLayout *lay){
    while (QLayoutItem *item = lay->takeAt(0)){
        Q_ASSERT(!item->layout()); // otherwise the layout will leak
        delete item->widget();
        delete item;
    }
}

void MenuPlatillos::llenarCategorias(){
    limpiarLayout(ui->menu_layout);
    QSqlQuery query(mDatabase);
    query.prepare("SELECT * FROM categoria");
    query.exec();

     while(query.next()){
         Categoria categ;
         categ.id = query.value(0).toInt();
         categ.nombre = query.value(1).toString();

         MenuButton *btn = new MenuButton(categ);
         ui->menu_layout->addWidget(btn);
     }
}

void MenuPlatillos::llenarCatalogo(){
    limpiarLayout(ui->platillo_grid->layout());
    QSqlQuery query(mDatabase);
    query.prepare("SELECT id_platillo,nombre, descripcion, urlFoto FROM platillo LIMIT 5");
    query.exec();

    int i = 0;
    int row = 0;
    int col = 0;

    while(query.next()){

        Platillo1 platillo;
        platillo.id=query.value(0).toInt();
        platillo.nombre = query.value(1).toString();
        platillo.descripcion = query.value(2).toString();
        platillo.urlFoto = query.value(3).toString();

        row = i / 4;
        col = i % 4;
        TarjetaPlatillo *tarjeta = new TarjetaPlatillo(platillo);
        QGridLayout *gl = dynamic_cast<QGridLayout*>(ui->grid_platillos->layout());
        gl->addWidget(tarjeta, row, col);
        // QSignalMapper *mapper=new QSignalMapper(this);
        connect(tarjeta,&TarjetaPlatillo::clicked,orden,&Orden::on_tarjeta_clickeada);
          //connect(tarjeta->devolverBoton(),SIGNAL(clicked(bool)),orden1,SLOT(ponerPlatillos()));
         //connect(tarjeta->devolverBoton(),SIGNAL(clicked(bool)),mapper,SLOT(map()));
         //mapper->setMapping(tarjeta->devolverBoton(),platillo.nombre);
          //connect(mapper,SIGNAL(mapped(QString)),this,SLOT(agregarPlatillos(QString)));

        i++;
    }

}

MenuPlatillos::~MenuPlatillos()
{
    delete ui;
}

void MenuPlatillos::clearLayout(QLayout *layout) {
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
void MenuPlatillos::agregarPlatillos(QString nombre){

    QPushButton *b=new QPushButton();
    b->setText("Hola");
   // qDebug()<<indice;






}
