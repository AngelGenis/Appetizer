#include "menuplatillos.h"
#include "tarjetaplatillo.h"
#include "ui_menuplatillos.h"
#include "orden.h"
#include "components-manager/crudplatillo.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include<QSignalMapper>
#include <QInputDialog>
#include <QScrollBar>


MenuPlatillos::MenuPlatillos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuPlatillos)
{
    ui->setupUi(this);
    ui->buscador->setAttribute(Qt::WA_MacShowFocusRect,0);

    orden = new Orden();
    crudPlat = new CrudPlatillo();

    categoriaActual.id = 1;

    llenarCatalogo();
    llenarCategorias();

    ui->btn_agregarPlatillo->hide();
    ui->btn_agregarCategoria->hide();
    ui->menu->resize(421, 55);
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
                "SELECT p.id_platillo, p.nombre, p.descripcion, p.urlFoto, p.precio FROM platillo  AS p "
                "INNER JOIN categoriaplatillo AS cp "
                "ON  p.id_platillo = cp.idplatillo "
                "INNER JOIN categoria AS c "
                "ON c.idcategoria = cp.idcategoria "
                "WHERE (c.idcategoria = :idcategoria "
                "AND p.nombre LIKE :busqueda "
                "AND p.estado = 'disponible')"
                );


    query.bindValue(":idcategoria", categoriaActual.id);
    query.bindValue(":busqueda", QString("%%1%").arg(busqueda));

    query.exec();

    i = 0;
    row = 0;
    col = 0;

    while(query.next()){
        Platillo1 platillo;
        platillo.id = query.value(0).toInt();
        platillo.nombre = query.value(1).toString();
        platillo.descripcion = query.value(2).toString();
        platillo.urlFoto = query.value(3).toString();
        platillo.precio = query.value(4).toString();

        row = i / 4;
        col = i % 4;
        TarjetaPlatillo *tarjeta = new TarjetaPlatillo(platillo);
        QGridLayout *gl = dynamic_cast<QGridLayout*>(ui->grid_platillos->layout());
        gl->addWidget(tarjeta, row, col);
        // QSignalMapper *mapper=new QSignalMapper(this);
       // connect(tarjeta,&TarjetaPlatillo::clicked,orden,&Orden::on_tarjeta_clickeada);
          //connect(tarjeta->devolverBoton(),SIGNAL(clicked(bool)),orden1,SLOT(ponerPlatillos()));
         //connect(tarjeta->devolverBoton(),SIGNAL(clicked(bool)),mapper,SLOT(map()));
         //mapper->setMapping(tarjeta->devolverBoton(),platillo.nombre);
          //connect(mapper,SIGNAL(mapped(QString)),this,SLOT(agregarPlatillos(QString)));

        /*Conexión entre tarjetas y la construcción de la orden*/
        //connect(tarjeta, &TarjetaPlatillo::clicked, orden, &Orden::on_tarjeta_clickeada);
        connect(tarjeta, &TarjetaPlatillo::clickedPlatillo, crudPlat, &CrudPlatillo::on_tarjeta_clickeada);

        i++;
    }

}

MenuPlatillos::~MenuPlatillos(){
    delete ui;
}

void MenuPlatillos::setOrdenWidget(QWidget *ordenWidget){
    this->orden = dynamic_cast<Orden*>(ordenWidget);
}

void MenuPlatillos::setEditionMode()
{
    ui->btn_agregarPlatillo->show();
    ui->btn_agregarCategoria->show();
    ui->menu->resize(381, 55);
}

void MenuPlatillos::setCategoria(Categoria categoriaSeleccionada){
    categoriaActual = categoriaSeleccionada;
    llenarCatalogo();
}

void MenuPlatillos::on_buscador_textChanged(const QString &text){
    busqueda = text;
    llenarCatalogo();
}

void MenuPlatillos::on_btn_agregarPlatillo_clicked()
{
    Platillo1 platillo;
    platillo.nombre = "NUEVO PLATILLO";
    platillo.precio = "0.0";
    platillo.descripcion = "";
    platillo.urlFoto = "://Img/default_img.png";

    row = i / 4;
    col = i % 4;

    TarjetaPlatillo *tarjeta = new TarjetaPlatillo(platillo);
    QGridLayout *gl = dynamic_cast<QGridLayout*>(ui->grid_platillos->layout());


    QSqlQuery query(mDatabase);
    query.prepare("INSERT INTO platillo (nombre, precio, descripcion, urlFoto) "
                  "VALUES (:nombre, :precio, :decripcion, :urlFoto)");
    query.bindValue(":nombre", platillo.nombre);
    query.bindValue(":precio", 0);
    query.bindValue(":descripcion", platillo.descripcion);
    query.bindValue(":urlFoto", platillo.urlFoto);

    if(!query.exec()){
        qDebug() << "ERROR AL CREAR PLATILLO: " << query.lastError();
    }else{


        QSqlQuery query2(mDatabase);
        query2.prepare("INSERT INTO categoriaplatillo (idcategoria, idplatillo) "
                      "VALUES (:idCategoria, :idPlatillo)");
        query2.bindValue(":idCategoria", categoriaActual.id);
        query2.bindValue(":idPlatillo", query.lastInsertId());

        if(!query2.exec()){
            qDebug() << "ERROR AL ASOCIAR PLATILLO - CATEGORIA : " << query2.lastError();
        }else{
            gl->addWidget(tarjeta, row, col);
            i++;

            // scroll
            QScrollBar *sb = ui->menu->verticalScrollBar();
            sb->setValue(sb->maximum());
        }
    }

}

void MenuPlatillos::on_btn_agregarCategoria_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(0, "Categoría nueva",
                                         "Nombre de la categoría nueva: ", QLineEdit::Normal,
                                         "", &ok);
    if (ok && !text.isEmpty()) {
        Categoria categ;
        categ.nombre = text;

        QSqlQuery query(mDatabase);
        query.prepare("INSERT INTO categoria (Nombre) "
                        "VALUES (:categ) ");
        query.bindValue(":categ", categ.nombre);
        if(!query.exec()){
            qDebug() << "ERROR CREAR CATEGORIA: " << query.lastError();
        }else{
            llenarCategorias();

            MenuButton *lastMenuBtn = qobject_cast<MenuButton*>(ui->menu_lay->children().last());
            if(lastMenuBtn){
                lastMenuBtn->click();
                QScrollBar *sb = ui->menu->horizontalScrollBar();
                sb->setValue(sb->maximum());
            }
        }
    }

}
