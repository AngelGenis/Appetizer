#ifndef AUTHENTICATIONSERVICE_H
#define AUTHENTICATIONSERVICE_H
#include <QString>
#include <QException>
/*!
 * \class AuthenticationException
 * \brief Servicio de autenticación.
 * 
 * Provee la interfáz necesaria para autenticar
 * a los usuarios.
 */
class AuthenticationException : public QException
{
public:
    AuthenticationException(const char *message);
    void raise() const override;
    AuthenticationException *clone() const override;
    const char* what() const noexcept override;
private:
    const char* msg;
};

class QSqlDatabase;
class QSqlRecord;
class AuthenticationService
{
    
public:
    AuthenticationService();
    bool authenticate(const QString &userName, const QString &password);
    QStringList getEmpleados(QString category);

private:
    QSqlDatabase &db;    
};

#endif // AUTHENTICATIONSERVICE_H
