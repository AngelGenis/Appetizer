#include "platilloservice.h"
#include "databaseconnection.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>

#include <QSqlError>
#include <QDebug>

PlatilloService::PlatilloService() :
    db(DatabaseConnection::connect())
{
    if (!db.isValid() || !db.isOpen())
        qDebug() << db.lastError().text();
}
QString PlatilloService::obtenerPlatillo(){
    QString nombre;
    QSqlQuery query;
    int idPlatillo=1;
    query.prepare("SELECT nombre FROM Platillo WHERE id_platillo= :idPlatillo");
    query.bindValue(":idPlatillo", idPlatillo);

    if(query.exec() && query.first()){
        nombre=query.record().value(0).toString();
        return nombre;
    }else{
        return nullptr;
    }
}

QString PlatilloService::obtenerPrecio(){
    QString precio;
    QSqlQuery query;
    int idPlatillo=1;
    query.prepare("SELECT precio FROM Platillo WHERE id_platillo= :idPlatillo");
    query.bindValue(":idPlatillo", idPlatillo);

    if(query.exec() && query.first()){
        precio=query.record().value(0).toString();
        return precio;
    }else{
        return nullptr;
    }

}

