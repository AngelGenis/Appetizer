#include "mesasservice.h"
#include "databaseconnection.h"

#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QSqlRecord>

MesasService::MesasService() :
    db(DatabaseConnection::connect())
{
    
}

bool MesasService::savePosition(int id, int x, int y)
{
    QSqlQuery q(db);
    q.prepare("UPDATE mesa SET x = :x, y = :y WHERE id_mesa=:id");
    q.bindValue(":x",  x);
    q.bindValue(":y",  y);
    q.bindValue(":id", id);
    return q.exec();
}
bool MesasService::saveNumPersonas(int id, int numPersonas)
{
    QSqlQuery q(db);
    q.prepare("UPDATE mesa SET numero_personas = :num WHERE id_mesa=:id");
    q.bindValue(":num",  numPersonas);
    q.bindValue(":id", id);
    return q.exec();
}
bool MesasService::saveMesa(MesaDataSet mesa)
{
    QSqlQuery q(db);
    q.prepare("UPDATE mesa SET numero_personas = :num, piso = :piso, "
              "id_mesero = :idMesero, x = :x, y = :y WHERE id_mesa=:id");
    q.bindValue(":num",  mesa.numero_personas);
    q.bindValue(":piso",  mesa.piso);
    q.bindValue(":idMesero",  mesa.id_mesero);
    q.bindValue(":x",  mesa.x);
    q.bindValue(":y",  mesa.y);
    q.bindValue(":id", mesa.id_mesa);
    return q.exec();
}
QList<MesaDataSet> MesasService::getMesas()
{
    QList<MesaDataSet> mesas;
    QSqlQuery q(db);
    q.prepare("SELECT * FROM mesa");
    if(!q.exec())
        return mesas;
    while(q.next())
    {
        MesaDataSet mesa;
        mesa.id_mesa         = q.value("id_mesa").toInt();
        mesa.numero_personas = q.value("numero_personas").toInt();
        mesa.piso            = q.value("piso").toInt();
        mesa.id_mesero         = q.value("id_mesero").toInt();
        mesa.x               = q.value("x").toInt();
        mesa.y               = q.value("y").toInt();
        mesas.append(mesa);
    }
    return mesas;    
}
MesaDataSet MesasService::createMesa(int numPersonas, int x, int y)
{
    int newID = lastMesaID() + 1;
    QSqlQuery q(db);
    q.prepare("INSERT mesa(id_mesa, numero_personas, x, y) VALUES(:id, :num, :x, :y)");
    q.bindValue(":id", newID);
    q.bindValue(":num", numPersonas);
    q.bindValue(":x", x);
    q.bindValue(":y", y);
    MesaDataSet mesa;
    if(q.exec())
    {
        qDebug() << q.lastInsertId();       
        mesa.id_mesa         = q.lastInsertId().toInt();
        mesa.numero_personas = numPersonas;
        mesa.x = x;
        mesa.y = y;
    }
    return mesa;
}

bool MesasService::deleteMesa(int id)
{
    QSqlQuery q(db);
    q.prepare("DELETE FROM mesa WHERE id_mesa = :id");
    q.bindValue(":id", id);
    return q.exec();
}

int MesasService::lastMesaID() const
{
    QSqlQuery q(db);
    
    q.prepare("SELECT MAX(id_mesa)  FROM mesa");
    if (q.exec())
    {
        q.next();
        return q.value(0).toInt();
    }
    return 0;
    
}
