#include "authenticationservice.h"
#include "databaseconnection.h"

#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>

#include <QSqlError>
#include <QDebug>

AuthenticationService::AuthenticationService() :
    db(DatabaseConnection::connect())
{
    if (!db.isValid() || !db.isOpen())
        lastErrorMsg = db.lastError().text();
}
QString AuthenticationService::lastErrorMessage() const
{
    return lastErrorMsg;
}

usuario AuthenticationService::getDatosUsuario(const QString &userName){
    QString cargo = "";
    tipoUsuario tipoUsuario = getTipoDeUsuario(userName);
    usuario persona;

    switch(tipoUsuario){
        case 1:
            cargo = "mesero";
            break;
        case 2:
            cargo = "host";
            break;
        case 3:
            cargo = "cajero";
            break;
        case 4:
            cargo = "cocinero";
            break;
        case 5:
            cargo = "manager";
            break;
    default:
        break;
    }

    QSqlQuery query(db);
    query.prepare("SELECT urlFoto, nombre FROM empleado WHERE nombre = :nombre");
    query.bindValue(":nombre", userName);

    query.exec();
    query.next();

    persona.nombre = query.value("nombre").toString();
    persona.foto = query.value("urlFoto").toString();
    persona.cargo = cargo;

    return (persona);
}

QString AuthenticationService::getUsuarioActual()
{
    qDebug()<<"Este es el usuario del getUsuario: "<<UsuarioActual;
    return UsuarioActual;
}
bool AuthenticationService::authenticate(const QString &userName, const QString &password)
{
    
    QSqlQuery query(db);
    query.prepare("SELECT * FROM empleado WHERE nombre = :nombre");
    query.bindValue(":nombre", userName);
    if( !query.exec() )
    {
        lastErrorMsg = "Error al obtener tabla empleado: " + query.lastError().text();
        return false;
    }
    
    query.next();
    bool userNameMatch = query.value("nombre").toString() == userName;
    bool passwMatch = query.value("password").toString() == password;

    if (!userNameMatch)
        lastErrorMsg = "Error de autenticación: Nombre de usuario no válido";

    if (!passwMatch)
        lastErrorMsg = "Error de autenticación: Contraseña incorrecta";


    if(userNameMatch && passwMatch){

        qDebug()<<"Este es el userName: "<<userName;
        UsuarioActual = userName;
        qDebug()<<"Este es el userName2: "<<UsuarioActual;
        return true;
    }
    return false;
}

tipoUsuario AuthenticationService::getTipoDeUsuario(const QString &userName){

    /*
    0: not signed in;
    1: mesero
    2: host
    3: cajero
    4: cocinero
    5: manager
    */

    QString views[] = {"vmeseros", "vhosts", "vcajeros", "vcocineros", "vmanagers"};

    QSqlQuery query(db);

    for (int i = 0; i < 5; i++) {
        query.prepare("SELECT * FROM "+ views[i] + " WHERE nombre = '" + userName + "'");

        if(query.exec()){

            qDebug()<<query.lastQuery();
            query.next();
            if(query.value("nombre").toString() != "") return static_cast<tipoUsuario>(i+1);
        } else{
            qDebug() << "ERROR getTipoUsuario: ";
            qDebug() << query.lastError();
        }
    }

    return none;
}

QStringList AuthenticationService::getEmpleados(QString category)
{
    QSqlQuery query(db);
    QString q;
    QStringList empleados;

    if(category == "Mesero") {
        q = "SELECT * FROM vmeseros";
    }
    if(category == "Host") {
        q ="SELECT * FROM vhosts";
    }
    if(category == "Cocinero") {
        q ="SELECT * FROM vcocineros";
    }
    if(category == "Cajero") {
        q ="SELECT * FROM vcajeros";
    }
    if(category == "Manager") {
        q +="SELECT * FROM vmanagers";
    }        
    if(category == "Todos") {
        q = "SELECT * FROM empleado";
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

