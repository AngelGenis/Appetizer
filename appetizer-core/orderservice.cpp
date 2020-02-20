#include "orderservice.h"
#include "services/databaseconnection.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>

#include <QSqlError>
#include <QDebug>

OrderService::OrderService() :
    db(DatabaseConnection::connect())
{
    if (!db.isValid() || !db.isOpen())
        qDebug() << db.lastError().text();

}
bool OrderService::crearOrdenPlatillo(const int &idOrden, const int &idPlatillo,
                                      const int &cantidad, const QString &descripcion){
    QSqlQuery query(db);
    query.prepare("INSERT INTO platilloorden (id_orden, id_platillo, cantidad, descripcion) "
                  "VALUES (:id_orden, :id_platillo, :cantidad, :descripcion) ");
    query.bindValue(":id_orden",     idOrden);
    query.bindValue(":id_platillo",  idPlatillo);
    query.bindValue(":cantidad",     cantidad);
    query.bindValue(":descripcion",  descripcion);

    if(query.exec())
    {
        return true;
    }
    else
    {
        qCritical() << "Last Query: " << query.lastQuery();
        qCritical() << query.lastError().text();
        return false;
    }
}

bool OrderService::crearOrdenBebida(const int &idOrden, const int &idBebida){
    QSqlQuery query(db);
    query.prepare("INSERT INTO BebidaOrden (id_orden, id_bebida) "
                  "VALUES (:id_orden, :id_bebida) ");
    query.bindValue(":id_orden",     idOrden);
    query.bindValue(":id_bebida",    idBebida);

    if(query.exec())
    {
        return true;
    }
    else
    {
        qCritical() << "Last Query: " << query.lastQuery();
        qCritical() << query.lastError().text();
        return false;
    }
}

bool OrderService::crearOrden(const QString &horaFecha, const int &idMesa){
    QSqlQuery query(db), query2(db);
    query.prepare("INSERT INTO Orden (hora_fecha, id_mesa) "
                  "VALUES (:hora_fecha, :id_mesa) ");
    query.bindValue(":hora_fecha",     horaFecha);
    query.bindValue(":id_mesa",        idMesa);

    if(query.exec())
    {
        query2.exec("SELECT id_orden FROM Orden");
        query2.last();
        idOrden=query2.value("id_orden").toInt();
        qDebug() << idOrden;
        return true;
    }
    else
    {
        qCritical() << "Last Query: " << query.lastQuery();
        qCritical() << query.lastError().text();
        return false;
    }
}
int OrderService::getIdOrden(){
    return idOrden;
}
