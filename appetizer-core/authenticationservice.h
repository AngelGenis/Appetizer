#ifndef AUTHENTICATIONSERVICE_H
#define AUTHENTICATIONSERVICE_H
#include <QString>
#include <QException>

class BlockedUserException : public QException
{
public:
    BlockedUserException();
    void raise() const override;
    BlockedUserException *clone() const override;
    const char* what() const noexcept override;
private:
    const char* msg;
};

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
class AuthenticationService
{
public:
    AuthenticationService();
    bool authenticate(const QString &userName, const QString &password);    
private:
    QSqlDatabase &db;    
};

#endif // AUTHENTICATIONSERVICE_H
