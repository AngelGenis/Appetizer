#ifndef AUTHENTICATIONSERVICE_H
#define AUTHENTICATIONSERVICE_H
#include <QString>


class QSqlDatabase;
class QSqlRecord;

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
    QStringList getEmpleados(QString category);
    QString lastErrorMessage() const ;

private:
    QSqlDatabase &db;
    QString lastErrorMsg;
};

#endif // AUTHENTICATIONSERVICE_H
