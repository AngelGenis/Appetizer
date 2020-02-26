#ifndef AUTHENTICATIONSERVICE_H
#define AUTHENTICATIONSERVICE_H
#include <QString>


class QSqlDatabase;
class QSqlRecord;

enum tipoUsuario {none = 0, mesero = 1, host = 2, cajero = 3, cocinero = 4, manager = 5};
struct usuario{
    QString nombre, foto, cargo;
};

/*!
 * \class AuthenticationService
 * \brief Servicio de autenticación.
 * 
 * Provee la interfáz necesaria para autenticar
 * a los usuarios.
 */
class AuthenticationService
{
    
public:
    AuthenticationService();
    bool authenticate(const QString &userName, const QString &password);
    tipoUsuario getTipoDeUsuario(const QString &userName);
    QStringList getEmpleados(QString category);
    QString lastErrorMessage() const ;
    usuario getDatosUsuario(const QString &userName);


private:
    QSqlDatabase &db;
    QString lastErrorMsg;
};

#endif // AUTHENTICATIONSERVICE_H
