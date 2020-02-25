#include "crudplatillo.h"
#include "ui_crudplatillo.h"
#include "services/databaseconnection.h"
#include "platilloservice.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

int CrudPlatillo::idPlatillo=1;
QString CrudPlatillo::nombre="Hamburguesa doble",
CrudPlatillo::descripcion="Hamburguesa con doble carne. Acompañado de papas a la francesa.",
CrudPlatillo::precio="80",
CrudPlatillo::imagen="";


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
