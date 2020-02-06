#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H
#include <QSqlDatabase>
#include <QException>
/*!
 * \class AuthenticationException
 * \brief Excepción lanzada al generar un error de autenticación
 */
class DatabaseException : public QException
{
public:
    DatabaseException(const QString &message);
    void raise() const override;
    DatabaseException *clone() const override;
    const char* what() const noexcept override;
private:
    QString msg;
};
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
