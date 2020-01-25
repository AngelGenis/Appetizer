#include "authenticationservice.h"
#include "databaseconnection.h"

#include <QSqlQuery>
#include <QVariant>
#include <QSqlError>
#include <QDebug>

BlockedUserException::BlockedUserException() :
    msg("Error de autenticación: Usuario Bloqueado")
{

}

void BlockedUserException::raise() const
{
    throw *this;
}

BlockedUserException *BlockedUserException::clone() const
{
    return new BlockedUserException(*this);
}

const char *BlockedUserException::what() const noexcept
{
    return msg;
}



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
    QSqlQuery q(db);
    q.prepare("SELECT * FROM Empleado WHERE nombre = :nombre");
    q.bindValue(":nombre", userName);
    if( !q.exec() )
    {
        qCritical() << "Error al obtener tabla empleado: " << q.lastError();
        return false;
    }
    
    q.next();
    bool userNameMatch = q.value("nombre").toString() == userName;
    bool passwMatch = q.value("password").toString() == password;

    if (!userNameMatch)
        throw AuthenticationException("Error de autenticación: Nombre de usuario no válido");

    if (!passwMatch)
        throw AuthenticationException("Error de autenticación: Contraseña incorrecta");
    
    return true;
}

