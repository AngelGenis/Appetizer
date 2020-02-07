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
}

void MenuPlatillos::limpiarCatalogo()
{
    while (QLayoutItem *item = ui->grid_platillos->takeAt(0))
    {
        Q_ASSERT(!item->layout()); // otherwise the layout will leak
        delete item->widget();
        delete item;
    }
}

void MenuPlatillos::llenarCatalogo()
{
    QSqlQuery query(mDatabase);
    query.prepare("SELECT nombre, descripcion, urlFoto FROM platillo");
    query.exec();

    int i = 0;
    int row = 0;
    int col = 0;

    while(query.next()){

        Platillo platillo;
        platillo.nombre = query.value(0).toString();
        platillo.descripcion = query.value(1).toString();
        platillo.urlFoto = query.value(2).toString();

        row = i / 4;
        col = i % 4;
        TarjetaPlatillo *tarjeta = new TarjetaPlatillo(platillo);
        ui->grid_platillos->addWidget(tarjeta, row, col);

        i++;
    }

}

MenuPlatillos::~MenuPlatillos()
{
    delete ui;
}
