#include "crudplatillo.h"
#include "ui_crudplatillo.h"
#include "services/databaseconnection.h"
#include "platilloservice.h"
#include "categorias.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlTableModel>

int CrudPlatillo::idPlatillo;
QString CrudPlatillo::nombre,
CrudPlatillo::descripcion,
CrudPlatillo::precio,
CrudPlatillo::imagen;
Categorias *CrudPlatillo::categ;
PlatilloService *CrudPlatillo::platServ;
CrudPlatillo *CrudPlatillo::crudPla;
QLineEdit *CrudPlatillo::lE_nombre, *CrudPlatillo::lE_precio;
QTextEdit *CrudPlatillo::lE_desc;
QLabel *CrudPlatillo::l_imagen;
QHBoxLayout *CrudPlatillo::layoutCateg;
QPushButton *CrudPlatillo::btn_imagen;

CrudPlatillo::CrudPlatillo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CrudPlatillo),
    db(DatabaseConnection::connect())
{
    if (!db.isValid() || !db.isOpen())
        qDebug() << db.lastError().text();
    ui->setupUi(this);
    //mostrarDatosPlatillo();
   /* QPushButton *pb = new QPushButton("Boton", ui->imagen);
    pb->show();
    pb->setStyleSheet("position: right top;"
                      "background-color: #FFFFFF;"
                      "max-width: 44px;"
                      "max-height: 44px;"
                      "max-width: 44px;"
                      "max-height: 44px;"
                      "border-radius: 15px;");*/
    lE_nombre = ui->nombrePlatillo;
    lE_precio = ui->precioPlatillo;
    lE_desc = ui->descripcionPlatillo;
    l_imagen = ui->imagen;
    layoutCateg = ui->LayoutCategoria;
    btn_imagen = ui->btn_agregarImagen;

    mostrarCategorias();
}

CrudPlatillo::~CrudPlatillo()
{
    delete ui;
}

void CrudPlatillo::mostrarDatosPlatillo(){
    qDebug() << nombre;
    lE_nombre->setText(nombre);
    lE_precio->setText(precio);
    lE_desc->setPlainText(descripcion);

    QSqlQuery query;
    query.prepare("SELECT urlFoto FROM platillo WHERE id_platillo = :id_platillo");
    query.bindValue(":id_platillo", idPlatillo);
    if(query.exec() && query.first()){
        imagen=query.value("urlFoto").toString();
        if(!imagen.isEmpty())
        {
            int w=344;
            int h=l_imagen->height();
            QPixmap pix;
            pix.load(imagen);
            l_imagen->setPixmap(pix.scaled(w,h));
        }
        else
        {
            int w=344;
            int h=l_imagen->height();
            QPixmap imgPixmap("");
            imgPixmap.load(imagen);
            l_imagen->setPixmap(imgPixmap.scaled(w,h));
        }
    }
    /*qDebug() << l_imagen->pos();

    int menu_x_pos = l_imagen->pos().x();
    int menu_y_pos = l_imagen->pos().y();
    qDebug() << "Posiciones: " << menu_x_pos << " " << menu_y_pos;
    //btn_imagen->setGeometry(menu_x_pos, menu_y_pos,0,0);
     btn_imagen->*/
}

void CrudPlatillo::on_btn_agregarImagen_clicked()
{
    QStringList imagenes = QFileDialog::getOpenFileNames(this, tr("abrir"), QString(), tr("(*.jpg, *.png)"));

    if(imagenes.isEmpty())
        return;

    if(imagenes.size() > 1)
    {
        QMessageBox::warning(this, "Advertencia", "Por favor, elige solamente una imagen.");
        imagenes.clear();
        return;
    }
    imagen = imagenes.first();
    int w=344;
    int h=l_imagen->height();
    QPixmap pix;
    pix.load(imagen);
    l_imagen->setPixmap(pix.scaled(w,h));

    imagenes.clear();
}

void CrudPlatillo::obtenerDatosPlatillo(){
    nombre=ui->nombrePlatillo->text();
    precio=ui->precioPlatillo->text();
    descripcion=ui->descripcionPlatillo->toPlainText();
}

void CrudPlatillo::on_btn_guardarCambios_clicked()
{
    obtenerDatosPlatillo();
    double pre = precio.toDouble();
    if(platServ->actualizarDatosPlatillo(idPlatillo, nombre, pre, descripcion, imagen)){
        db.commit();
        QMessageBox::information(this, "Hecho",
                                         "Se guardaron los cambios del platillo");
    }else{
        db.rollback();
        QMessageBox::critical(this, "Error",
                                         "No se guardaron los cambios del platillo");
    }
}

void CrudPlatillo::mostrarCategorias(){
    modeloCategoria = new QSqlTableModel(this);
    modeloCategoria->setTable("categoria");
    modeloCategoria->select();
    ui->tV_categorias->setModel(modeloCategoria);

    modeloCategoria->setHeaderData(modeloCategoria->fieldIndex("categoria"), Qt::Horizontal, tr("Categorías:"));
    ui->tV_categorias->hideColumn(0);
    ui->tV_categorias->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tV_categorias->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    modeloCategoria->setFilter("");
}

void CrudPlatillo::on_tV_categorias_doubleClicked(const QModelIndex &index)
{
    QSqlQuery query;
    int row =index.row();
    idCategoria=ui->tV_categorias->model()->index(row,0).data().toInt();
    nombreCategoria = ui->tV_categorias->model()->index(row, 1).data().toString();
    qDebug() << idCategoria;
    qDebug() << nombreCategoria;


    crudPla = this;
    categ = new Categorias(idCategoria, nombreCategoria);
    layoutCateg->addWidget(categ);

    qDebug() << connect(categ, &Categorias::elimWid, crudPla, &CrudPlatillo::eliminarWidget);

    platServ->agregarPlatilloCategoria(idCategoria, idPlatillo);
}

void CrudPlatillo::mostrarCategoriasPlatillo(){
    clearLayout(layoutCateg);
    QSqlQuery query;
    query.prepare("SELECT c.idcategoria, c.Nombre "
                  "FROM categoria as c INNER JOIN categoriaplatillo as cp "
                  "ON c.idcategoria = cp.idcategoria WHERE cp.idplatillo=:idplatillo");
    query.bindValue(":idplatillo",   idPlatillo);
    if(query.exec()){
        while(query.next()){
            categ = new Categorias(query.value(0).toInt(), query.value(1).toString());
            layoutCateg->addWidget(categ);
            crudPla = this;
            qDebug() << connect(categ, &Categorias::elimWid, crudPla, &CrudPlatillo::eliminarWidget);
        }
    }else{
        qCritical() << "Last Query: " << query.lastQuery();
        qCritical() << query.lastError().text();
    }
}

void CrudPlatillo::on_btn_agregarCategoria_clicked()
{
    QString nuevaCategoria;
    nuevaCategoria = ui->lE_categoria->text();
    if(nuevaCategoria.isEmpty()){
        QMessageBox::warning(this, "Advertencia", "Escribe el nombre de la categoria antes de agregarla");
        return;
    }
    platServ->agregarCategoria(nuevaCategoria);
    ui->lE_categoria->clear();
    mostrarCategorias();
}

void CrudPlatillo::eliminarWidget(QWidget *wid, int idCat){
   // widElim=wid;
    qDebug() << "si entra";
    qDebug() << layoutCateg->indexOf(wid) << " " << idCat;
    int i= layoutCateg->indexOf(wid);
    if (QLayoutItem *item = layoutCateg->takeAt(i)){
        Q_ASSERT(!item->layout()); // otherwise the layout will leak
        delete item->widget();
        delete item;
    }
    platServ->eliminarCategoriaPlatillo(idCat, idPlatillo);
}

void CrudPlatillo::on_btn_EliminarPlatillo_clicked()
{
    if(QMessageBox::question(this, "Confirmación", "¿Está seguro que desea eliminar este "
                             "platillo")==QMessageBox::Yes){
        if(platServ->eliminarPlatillo(idPlatillo)){
             QMessageBox::information(this, "Éxito", "El platillo ha sido eliminado");
             emit on_actualizarMenu();
        }
    }
}

void CrudPlatillo::on_tarjeta_clickeada(Platillo1 platillo){
    platServ = new PlatilloService();
    idPlatillo = platillo.id;
    qDebug() << idPlatillo;
    if(idPlatillo == -1){
        platServ->agregarPlatilloDefault();
        idPlatillo = platServ->obtenerIdPlatillo();
        qDebug() << "Id platillo diferente de -1: " << idPlatillo;
    }
    nombre = platillo.nombre;
    precio = platillo.precio;
    descripcion = platillo.descripcion;
    imagen = platillo.urlFoto;
    mostrarDatosPlatillo();
    mostrarCategoriasPlatillo();
    //connect(this, &CrudPlatillo::on_actualizarMenu, menuPla, &MenuPlatillos::llenarCatalogo);

}

void CrudPlatillo::clearLayout(QHBoxLayout *layout){
    while (QLayoutItem *item = layout->takeAt(0)){
        Q_ASSERT(!item->layout()); // otherwise the layout will leak
        delete item->widget();
        delete item;
    }
}
