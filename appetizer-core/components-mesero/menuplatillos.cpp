#include "menuplatillos.h"
#include "tarjetaplatillo.h"
#include "ui_menuplatillos.h"
#include "orden.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

MenuPlatillos::MenuPlatillos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuPlatillos)
{
    ui->setupUi(this);
    ui->buscador->setAttribute(Qt::WA_MacShowFocusRect,0);

    orden = new Orden();

    categoriaActual.id = 1;

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
         connect(btn, &MenuButton::btnClicked, this, &MenuPlatillos::setCategoria);
     }

     // Conexión para los default styles de los demás botones
     for (int i = 0; i < ui->menu_layout->count(); ++i) {
        MenuButton *mb1 = dynamic_cast<MenuButton*>(ui->menu_layout->itemAt(i)->widget());
        if(mb1 != NULL){
            for (int j = 0; j < ui->menu_layout->count(); ++j) {
                MenuButton *mb2 = dynamic_cast<MenuButton*>(ui->menu_layout->itemAt(j)->widget());
                if(mb2 != NULL){
                    connect(mb1, &MenuButton::btnClicked, mb2, &MenuButton::setDefaultStyles);
                }
            }
        }
     }

}

void MenuPlatillos::llenarCatalogo(){
    limpiarLayout(ui->platillo_grid->layout());
    QSqlQuery query(mDatabase);
    query.prepare(
                "SELECT p.id_platillo, p.nombre, p.descripcion, p.urlFoto FROM platillo  AS p "
                "INNER JOIN categoriaplatillo AS cp "
                "ON  p.id_platillo = cp.idplatillo "
                "INNER JOIN categoria AS c "
                "ON c.idcategoria = cp.idcategoria "
                "WHERE (c.idcategoria = :idcategoria "
                "AND p.nombre LIKE :busqueda)"
                );
    query.bindValue(":idcategoria", categoriaActual.id);
    query.bindValue(":busqueda", QString("%%1%").arg(busqueda));
    query.exec();

    int i = 0;
    int row = 0;
    int col = 0;

    while(query.next()){
        Platillo1 platillo;
        platillo.id = query.value(0).toInt();
        platillo.nombre = query.value(1).toString();
        platillo.descripcion = query.value(2).toString();
        platillo.urlFoto = query.value(3).toString();

        row = i / 4;
        col = i % 4;
        TarjetaPlatillo *tarjeta = new TarjetaPlatillo(platillo);
        QGridLayout *gl = dynamic_cast<QGridLayout*>(ui->grid_platillos->layout());
        gl->addWidget(tarjeta, row, col);

        /*Conexión entre tarjetas y la construcción de la orden*/
        connect(tarjeta, &TarjetaPlatillo::clicked, orden, &Orden::on_tarjeta_clickeada);

        i++;
    }

}

MenuPlatillos::~MenuPlatillos(){
    delete ui;
}

void MenuPlatillos::setOrdenWidget(QWidget *ordenWidget){
    this->orden = dynamic_cast<Orden*>(ordenWidget);
}

void MenuPlatillos::setCategoria(Categoria categoriaSeleccionada){
    categoriaActual = categoriaSeleccionada;
    llenarCatalogo();
}

void MenuPlatillos::on_buscador_textChanged(const QString &text){
    busqueda = text;
    llenarCatalogo();
}
