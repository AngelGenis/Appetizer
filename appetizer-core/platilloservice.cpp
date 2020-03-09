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
QString PlatilloService::obtenerPlatillo(int idPlatillo){
    QString nombre;
    QSqlQuery query;
    query.prepare("SELECT nombre FROM Platillo WHERE id_platillo= :idPlatillo");
    query.bindValue(":idPlatillo", idPlatillo);

    if(query.exec() && query.first()){
        nombre=query.record().value(0).toString();
        return nombre;
    }else{
        return nullptr;
    }
}

QString PlatilloService::obtenerPrecio(int idPlatillo){
    QString precio;
    QSqlQuery query;
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

void PlatilloService::getFoto(QStringList foto){
    this->foto = foto;
}

bool PlatilloService::actualizarDatosPlatillo(const int &idPlatillo, const QString &nombre,
                                              const double &precio, const QString &descripcion,
                                              const QString &imagen){
    db.transaction();
    QSqlQuery query(db);
    query.prepare("UPDATE platillo SET nombre = :nombre, precio = :precio, "
                  "descripcion = :descripcion, urlFoto = :urlFoto WHERE id_platillo = :id_platillo");
    query.bindValue(":nombre",        nombre);
    query.bindValue(":precio",        precio);
    query.bindValue(":descripcion",   descripcion);
    query.bindValue(":urlFoto",       imagen);
    query.bindValue(":id_platillo",   idPlatillo);
    if(query.exec()){
        return true;
    }else{
        qCritical() << query.lastQuery();
        qCritical() << query.lastError();
        return false;
    }
}

bool PlatilloService::agregarCategoria(const QString &nombre){
    db.transaction();
    QSqlQuery query(db);
    query.prepare("INSERT INTO categoria (Nombre) VALUES (:Nombre)");
    query.bindValue(":Nombre",  nombre);
    if(query.exec()){
        return true;
    }else{
        qCritical() << "Last Query: " << query.lastQuery();
        qCritical() << query.lastError().text();
        return false;
    }
}

bool PlatilloService::agregarPlatilloCategoria(const int &idCategoria, const int &idPlat){
    db.transaction();
    QSqlQuery query(db);
    query.prepare("INSERT INTO categoriaplatillo (idcategoria, idplatillo) "
                  "VALUES (:idcategoria, :idplatillo)");
    query.bindValue(":idcategoria",  idCategoria);
    query.bindValue(":idplatillo",  idPlat);
    if(query.exec()){
        return true;
    }else{
        qCritical() << "Last Query: " << query.lastQuery();
        qCritical() << query.lastError().text();
        return false;
    }
}

bool PlatilloService::eliminarCategoriaPlatillo(const int &idCategoria, const int &idPlati){
    db.transaction();
    QSqlQuery query(db);
    query.prepare("DELETE FROM categoriaplatillo WHERE "
                  "idplatillo = :idplatillo and idcategoria = :idcategoria");
    query.bindValue(":idplatillo",   idPlati);
    query.bindValue(":idcategoria",  idCategoria);
    if(query.exec()){
        return true;
    }else{
        qCritical() << "Last Query: " << query.lastQuery();
        qCritical() << query.lastError().text();
        return false;
    }
}

bool PlatilloService::agregarPlatilloDefault(){
    db.transaction();
    QSqlQuery query(db), query2(db);
    query.prepare("INSERT INTO platillo (nombre, precio, descripcion, urlFoto) VALUES "
                  "(:nombre, :precio, :descripcion, :urlFoto)");
    query.bindValue(":nombre"  ,     "NUEVO PLATILLO");
    query.bindValue(":precio",       0.0);
    query.bindValue(":descripcion",  "");
    query.bindValue(":urlFoto",      "://Img/default_img.png");
    if(query.exec()){
        query2.prepare("SELECT id_platillo FROM platillo");
        if(query2.exec()){
            query2.last();
            idPlatillo = query2.value(0).toInt();
            qDebug () << idPlatillo;
        }
        return true;
    }else{
        qCritical() << "Last Query: " << query.lastQuery();
        qCritical() << query.lastError().text();
        return false;
    }
}

bool PlatilloService::eliminarPlatillo(const int &idPlatillo){
    QSqlQuery query(db);

    QString estado = "agotado";
    query.prepare("UPDATE platillo SET estado = :estado WHERE id_platillo = :id_platillo");
    query.bindValue(":estado",      estado);
    query.bindValue(":id_platillo", idPlatillo);
    if(query.exec()){
        return true;
    }else{
        qCritical() << "Last Query: " << query.lastQuery();
        qCritical() << query.lastError().text();
        return false;
    }
}

void PlatilloService::guardarCambios(){
    db.commit();
}

void PlatilloService::cancelarCambios(){
    db.rollback();
}

int PlatilloService::obtenerIdPlatillo(){
    return idPlatillo;
}

