#include "orderservice.h"
#include "databaseconnection.h"
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
bool OrderService::crearOrdenPlatillo(const int &idOrden, const int &idPlatillo){
    QSqlQuery query;
    query.prepare("INSERT INTO PlatilloOrden (id_orden, id_platillo) "
                  "VALUES (:id_orden, :id_platillo) ");
    query.bindValue(":id_orden",     idOrden);
    query.bindValue(":id_platillo",  idPlatillo);

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
    QSqlQuery query;
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
    QSqlQuery query;
    query.prepare("INSERT INTO Orden (hora_fecha, id_mesa) "
                  "VALUES (:hora_fecha, :id_mesa) ");
    query.bindValue(":hora_fecha",     horaFecha);
    query.bindValue(":id_mesa",        idMesa);

    if(query.exec())
    {
        query.exec("SELECT id_orden FROM Orden");
        query.last();
        idOrden=query.record().value(0).toInt();
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
