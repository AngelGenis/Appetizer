#include "menuplatillos.h"
#include "tarjetaplatillo.h"
#include "ui_menuplatillos.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

MenuPlatillos::MenuPlatillos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuPlatillos)
{
    ui->setupUi(this);
    ui->buscador->setAttribute(Qt::WA_MacShowFocusRect,0);

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
    query.prepare("SELECT nombre, descripcion, urlFoto FROM platillo LIMIT 5");
    query.exec();

    int i = 0;
    int row = 0;
    int col = 0;

    while(query.next()){

        Platillo1 platillo;
        platillo.nombre = query.value(0).toString();
        platillo.descripcion = query.value(1).toString();
        platillo.urlFoto = query.value(2).toString();

        row = i / 4;
        col = i % 4;
        TarjetaPlatillo *tarjeta = new TarjetaPlatillo(platillo);
        QGridLayout *gl = dynamic_cast<QGridLayout*>(ui->grid_platillos->layout());
        gl->addWidget(tarjeta, row, col);

        i++;
    }

}

MenuPlatillos::~MenuPlatillos()
{
    delete ui;
}
