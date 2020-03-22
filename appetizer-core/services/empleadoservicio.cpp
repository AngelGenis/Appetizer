#include "empleadoservicio.h"
#include "databaseconnection.h"

#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>

#include <QSqlError>
#include <QDebug>

EmpleadoServicio::EmpleadoServicio() :
    db(DatabaseConnection::connect())
{
    if (!db.isValid() || !db.isOpen())
        qDebug() << db.lastError().text();
}

QStringList EmpleadoServicio::getEmpleadosFiltro(QString categoria, QString buscar){
    QSqlQuery query(db);
    QString q;
    QStringList empleados;

    if(categoria == "Mesero") {
        q = "SELECT * FROM vmeseros WHERE nombre LIKE :nombre";
    }
    if(categoria == "Host") {
        q ="SELECT * FROM vhosts WHERE nombre LIKE :nombre";
    }
    if(categoria == "Cocinero") {
        q ="SELECT * FROM vcocineros WHERE nombre LIKE :nombre";
    }
    if(categoria == "Cajero") {
        q ="SELECT * FROM vcajeros WHERE nombre LIKE :nombre";
    }
    if(categoria == "Manager") {
        q +="SELECT * FROM vmanagers WHERE nombre LIKE :nombre";
    }
    if(categoria == "Todos") {
        q = "SELECT * FROM empleado WHERE nombre LIKE :nombre";
    }
    if(categoria.isEmpty())
    {
        return empleados;
    }
    query.prepare(q);
    query.bindValue(":nombre" , QString("%%1%").arg(buscar));

    if(!query.exec())
    {
        qCritical() << "Error al obtener tabla empleado: " << query.lastError();
    }
    while(query.next())
    {
        empleados.append(query.value("nombre").toString());
    }
    return empleados;
}
