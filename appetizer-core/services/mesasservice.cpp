#include "mesasservice.h"
#include "databaseconnection.h"

#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QSqlRecord>
#include <QVariant>
#include <QSqlError>
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
bool MesasService::saveMesa(MesaData mesa)
{
    QSqlQuery q(db);
    q.prepare("UPDATE mesa SET numero_personas = :num, piso = :piso, "
              "id_mesero = :idMesero, x = :x, y = :y, "
              " grupo = :grupo, id_mesa_maestra = :mesaMaestra , estado = :estado "
              " WHERE id_mesa=:id");
    q.bindValue(":num",  mesa.numero_personas);
    q.bindValue(":piso",  mesa.piso);
    q.bindValue(":idMesero",  mesa.id_mesero);
    q.bindValue(":x",  mesa.x);
    q.bindValue(":y",  mesa.y);
    q.bindValue(":id", mesa.id_mesa);
    q.bindValue(":grupo", mesa.grupo);
    q.bindValue(":mesaMaestra", mesa.id_mesa_maestra);
    q.bindValue(":estado", mesa.estado);
    if(q.exec())
        return true;
    else
    {
        qDebug() << "Error " << q.lastError().text();
        return false;
    }
}
QList<MesaData> MesasService::getMesas()
{
    QList<MesaData> mesas;
    QSqlQuery q(db);
    q.prepare("SELECT * FROM mesa");
    if(!q.exec())
        return mesas;
    while(q.next())
    {
        MesaData mesa;
        mesa.id_mesa         = q.value("id_mesa").toInt();
        mesa.numero_personas = q.value("numero_personas").toInt();
        mesa.piso            = q.value("piso").toInt();
        mesa.id_mesero       = q.value("id_mesero").toInt();
        mesa.x               = q.value("x").toInt();
        mesa.y               = q.value("y").toInt();
        mesa.grupo           = q.value("grupo").toInt();
        mesa.id_mesa_maestra = q.value("id_mesa_maestra").toInt();
        mesa.estado          = q.value("estado").toInt();
        mesas.append(mesa);
    }
    return mesas;    
}
MesaData MesasService::createMesa(int numPersonas, int x, int y)
{
    int newID = lastMesaID() + 1;
    qDebug() << "newID: " << newID;
    QSqlQuery q(db);
    q.prepare("INSERT mesa(id_mesa, numero_personas, x, y) VALUES(:id, :num, :x, :y)");
    q.bindValue(":id", newID);
    q.bindValue(":num", numPersonas);
    q.bindValue(":x", x);
    q.bindValue(":y", y);
    MesaData mesa;
    if(q.exec())
    {
        mesa.id_mesa         = newID;
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
    int res = 0;
    q.prepare("SELECT MAX(id_mesa) AS maxid  FROM mesa");
    if (q.exec())
    {
        q.next();
        res = q.value("maxid").toInt();
    }
    return res;    
}

MesaData MesasService::getMesa(int id)
{
    QSqlQuery q(db);
    MesaData mesa;
    q.prepare("SELECT * FROM mesa WHERE id_mesa = :id");
    q.bindValue(":id", id);
    if (q.exec() && q.next())
    {
        mesa.id_mesa         = q.value("id_mesa").toInt();
        mesa.numero_personas = q.value("numero_personas").toInt();
        mesa.piso            = q.value("piso").toInt();
        mesa.id_mesero       = q.value("id_mesero").toInt();
        mesa.x               = q.value("x").toInt();
        mesa.y               = q.value("y").toInt();
        mesa.grupo           = q.value("grupo").toInt();
        mesa.id_mesa_maestra = q.value("id_mesa_maestra").toInt();
        mesa.estado          = q.value("estado").toInt();        
    }
    return mesa;    
}
