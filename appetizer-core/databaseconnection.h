#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H
#include <QSqlDatabase>
/**
 *   \file databaseconnection.h
 *   \brief DatabaseConnection abstrae la conexión al base de datos.
 *
 *  Esta clase abstrae la conexión a la base de datos MySQL, utilizando un
 *  archivo de configuración llamdo db.conf localizado en la carpeta 
 *  del executable de Appetizer
 *
 */

class DatabaseConnection
{
private:
    static QSqlDatabase db;
protected:
    DatabaseConnection();
public:
    static QSqlDatabase &connect();
};


#endif // DATABASECONNECTION_H
