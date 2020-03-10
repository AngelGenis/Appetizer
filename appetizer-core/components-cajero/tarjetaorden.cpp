#include "tarjetaorden.h"
#include "ui_tarjetaorden.h"
#include "services/databaseconnection.h"

#include <QDebug>
#include <QSqlError>

tarjetaOrden::tarjetaOrden(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tarjetaOrden),
    db(DatabaseConnection::connect())
{
    if (!db.isValid() || !db.isOpen())
        qDebug() << db.lastError().text();
    ui->setupUi(this);
}

tarjetaOrden::~tarjetaOrden()
{
    delete ui;
}

void tarjetaOrden::llenarOrden(QString nOrden, QString precioOrden)
{
    ui->numero_orden->setText("Orden "+nOrden);
    ui->precio->setText("$"+precioOrden);
}
