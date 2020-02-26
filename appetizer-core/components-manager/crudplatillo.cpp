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

int CrudPlatillo::idPlatillo=1;
QString CrudPlatillo::nombre="Hamburguesa doble",
CrudPlatillo::descripcion="Hamburguesa con doble carne. Acompañado de papas a la francesa.",
CrudPlatillo::precio="80",
CrudPlatillo::imagen="";
Categorias *CrudPlatillo::categ;


CrudPlatillo::CrudPlatillo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CrudPlatillo),
    db(DatabaseConnection::connect()),
    platServ(new PlatilloService)
{
    if (!db.isValid() || !db.isOpen())
        qDebug() << db.lastError().text();
    ui->setupUi(this);
    mostrarDatosPlatillo();
    QPushButton *pb = new QPushButton("Boton", ui->imagen);
    pb->show();
    pb->setStyleSheet("position: right top;"
                      "background-color: #FFFFFF;"
                      "max-width: 44px;"
                      "max-height: 44px;"
                      "max-width: 44px;"
                      "max-height: 44px;"
                      "border-radius: 15px;");
    mostrarCategorias();

}

CrudPlatillo::~CrudPlatillo()
{
    delete ui;
}

void CrudPlatillo::mostrarDatosPlatillo(){
    ui->nombrePlatillo->setText(nombre);
    ui->precioPlatillo->setText(precio);
    ui->descripcionPlatillo->setPlainText(descripcion);
    QSqlQuery query;
    query.prepare("SELECT urlFoto FROM platillo WHERE id_platillo = :id_platillo");
    query.bindValue(":id_platillo", idPlatillo);
    if(query.exec() && query.first()){
        imagen=query.value("urlFoto").toString();
        if(!imagen.isEmpty())
        {
            QPixmap imgPixmap(imagen);
            ui->imagen->setPixmap(imgPixmap.scaled(ui->imagen->size(),
                                                Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
        else
        {
            QPixmap imgPixmap("");
            ui->imagen->setPixmap(imgPixmap.scaled(ui->imagen->size(),
                                                Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
    }
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
    QPixmap imgPixmap(imagen);
    ui->imagen->setPixmap(imgPixmap.scaled(ui->imagen->size(),
                                        Qt::KeepAspectRatio, Qt::SmoothTransformation));

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
    if(platServ->actualizarDatosPlatillo(idPlatillo, nombre, pre, descripcion, imagen))
        QMessageBox::information(this, "Hecho",
                                         "Se guardaron los cambios del platillo");
    else
        QMessageBox::critical(this, "Error",
                                         "No se guardaron los cambios del platillo");
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

    categ = new Categorias(idCategoria, nombreCategoria);
    ui->LayoutCategoria->addWidget(categ);
}
