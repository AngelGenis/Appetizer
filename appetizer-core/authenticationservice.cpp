#include "authenticationservice.h"
#include "databaseconnection.h"

#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>

#include <QSqlError>
#include <QDebug>

AuthenticationException::AuthenticationException(const char *message) :
    msg(message)
{

}

void AuthenticationException::raise() const
{
    throw *this;
}

AuthenticationException *AuthenticationException::clone() const
{
    return new AuthenticationException(*this);
}

const char *AuthenticationException::what() const noexcept
{
    return msg;
}


AuthenticationService::AuthenticationService() :
    db(DatabaseConnection::connect())
{
    
}

bool AuthenticationService::authenticate(const QString &userName, const QString &password)
{
    
    QSqlQuery query(db);
    query.prepare("SELECT * FROM Empleado WHERE nombre = :nombre");
    query.bindValue(":nombre", userName);
    if( !query.exec() )
    {
        qCritical() << "Error al obtener tabla empleado: " << query.lastError();
        return false;
    }
    
    query.next();
    bool userNameMatch = query.value("nombre").toString() == userName;
    bool passwMatch = query.value("password").toString() == password;

    if (!userNameMatch)
        throw AuthenticationException("Error de autenticación: Nombre de usuario no válido");

    if (!passwMatch)
        throw AuthenticationException("Error de autenticación: Contraseña incorrecta");
    
    return true;
}

QStringList AuthenticationService::getEmpleados(QString category)
{
    QSqlQuery query(db);
    QString q;
    QStringList empleados;

    if(category == "Mesero") {
        q = "SELECT * FROM VMeseros";
    }
    if(category == "Host") {
        q ="SELECT * FROM VHosts";
    }
    if(category == "Cocinero") {
        q ="SELECT * FROM VCocineros";
    }
    if(category == "Cajero") {
        q ="SELECT * FROM VCajeros";
    }
    if(category == "Manager") {
        q +="SELECT * FROM VManagers";
    }        
    if(category == "Todos") {
        q = "SELECT * FROM Empeado";
    }
    if(category.isEmpty())
    {
        return empleados;
    }
    query.prepare(q);

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

