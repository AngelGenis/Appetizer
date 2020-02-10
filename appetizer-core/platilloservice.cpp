#include "platilloservice.h"
#include "services/databaseconnection.h"
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

bool PlatilloService::guardarComentario(const int &idOrden, const int &idPlatillo, const QString &coment){
    QSqlQuery query;
    query.prepare("UPDATE platilloorden SET descripcion = :descripcion "
                  "WHERE id_orden = :id_orden AND id_platillo = :id_platillo");
    query.bindValue(":descripcion",     coment);
    query.bindValue(":id_orden",        idOrden);
    query.bindValue(":id_platillo",     idPlatillo);

    if(query.exec()){
        return true;
    }else{
        qCritical() << query.lastQuery();
        qCritical() << query.lastError();
        return false;
    }

}
void PlatilloService::getComentario(QString comentario){
    this->comentario=comentario;
}
QString PlatilloService::setComentario(){
    return comentario;
}

