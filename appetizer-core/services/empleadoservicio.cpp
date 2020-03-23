#include "empleadoservicio.h"
#include "databaseconnection.h"

#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>
#include <QWidget>

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

    if(categoria == "Todos"){
        q = "SELECT *FROM empleado WHERE nombre LIKE :nombre";
    }

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

tipoEmpleado EmpleadoServicio::getTipoDeUsuario(const QString &userName){

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
            if(query.value("nombre").toString() != "") return static_cast<tipoEmpleado>(i+1);
        } else{
            qDebug() << "ERROR getTipoUsuario: ";
            qDebug() << query.lastError();
        }
    }

    return ninguno;
}

Empleado EmpleadoServicio::getDatosEmpleado(const QString &userName){
    QString cargo = "";
    tipoEmpleado tipoEmpleado = getTipoDeUsuario(userName);
    Empleado empleado;

    switch(tipoEmpleado){
        case 1:
            cargo = "Mesero";
            break;
        case 2:
            cargo = "Host";
            break;
        case 3:
            cargo = "Cajero";
            break;
        case 4:
            cargo = "Cocinero";
            break;
        case 5:
            cargo = "Manager";
            break;
    default:
        break;
    }

    QSqlQuery query(db);
    query.prepare("SELECT * FROM empleado WHERE nombre = :nombre");
    query.bindValue(":nombre", userName);

    query.exec();
    query.next();

    empleado.idEmpleado         = query.value("id_empleado").toInt();
    empleado.urlFoto            = query.value("urlFoto").toString();
    empleado.nombre             = query.value("nombre").toString();
    empleado.fecha_nacimiento   = query.value("fecha_nacimiento").toDate();
    empleado.sexo               = query.value("sexo").toString();
    empleado.sueldo             = query.value("sueldo").toDouble();
    empleado.fecha_ingreso      = query.value("fecha_ingreso").toDate();
    empleado.telefono           = query.value("telefono").toString();
    empleado.correo             = query.value("correo").toString();
    empleado.password           = query.value("password").toString();
    empleado.cargo              = cargo;

    return (empleado);
}

bool EmpleadoServicio::actualizarEmpleado(const int &idEmpleado, const QString &urlFoto,
                                          const QString &nombre, const QDate &f_naci,
                                          const QString &sexo, const double &sueldo,
                                          const QDate &f_ingre, const QString &tel,
                                          const QString &correo, const QString &password){
    db.transaction();
    QSqlQuery query(db);
    query.prepare("UPDATE empleado SET urlFoto = :urlFoto, nombre = :nombre, "
                  "fecha_nacimiento = :fecha_nacimiento, sexo = :sexo, sueldo = :sueldo, "
                  "fecha_ingreso = :fecha_ingreso, telefono = :telefono, correo = :correo, "
                  "password = :password "
                  "WHERE id_empleado = :id_empleado");
    query.bindValue(":urlFoto",             urlFoto);
    query.bindValue(":nombre",              nombre);
    query.bindValue(":fecha_nacimiento",    f_naci);
    query.bindValue(":sexo",                sexo);
    query.bindValue(":sueldo",              sueldo);
    query.bindValue(":fecha_ingreso",       f_ingre);
    query.bindValue(":telefono",            tel);
    query.bindValue(":correo",              correo);
    query.bindValue(":password",            password);
    query.bindValue(":id_empleado",         idEmpleado);
    if(query.exec()){
        return true;
    }else{
        qCritical() << query.lastQuery();
        qCritical() << query.lastError();
        return false;
    }

}

bool EmpleadoServicio::agregarEmpleadoDefault(){
    db.transaction();
    QDate date = QDate::currentDate();
    QSqlQuery query(db), query2(db);
    query.prepare("INSERT INTO empleado (urlFoto, nombre, fecha_nacimiento, sexo, sueldo, fecha_ingreso,"
                  "telefono, correo, password) VALUES "
                  "(:urlFoto, :nombre, :fecha_nacimiento, :sexo, :sueldo, :fecha_ingreso, :telefono, "
                  ":correo, :password)");
    query.bindValue(":urlFoto",             "://Img/user.png");
    query.bindValue(":nombre"  ,            "NOMBRE COMPLETO");
    query.bindValue(":fecha_nacimiento",    date);
    query.bindValue(":sexo",                "Ninguno");
    query.bindValue(":sueldo",              0.0);
    query.bindValue(":fecha_ingreso",       date);
    query.bindValue(":telefono",            "0000000000");
    query.bindValue(":correo",              "correo@ejemplo.correo");
    query.bindValue(":password",            "contraseña");

    if(query.exec()){
        query2.prepare("SELECT id_empleado FROM empleado");
        if(query2.exec()){
            query2.last();
            idEmpleado = query2.value(0).toInt();
            qDebug () << idEmpleado;
        }
        return true;
    }else{
        qCritical() << "Last Query: " << query.lastQuery();
        qCritical() << query.lastError().text();
        return false;
    }
}

bool EmpleadoServicio::agregarCargo(const int &idEmpleado, const QString &cargo){
    if(verificarCargo(idEmpleado, cargo) ==0){
        db.transaction();
        QSqlQuery query(db);
        QString q;
        if(cargo == "Mesero") {
            q = "INSERT INTO mesero (id_empleado) VALUES (:id_empleado)";
        }
        if(cargo == "Host") {
            q ="INSERT INTO host (id_empleado) VALUES (:id_empleado)";
        }
        if(cargo == "Cocinero") {
            q ="INSERT INTO cocinero (id_empleado) VALUES (:id_empleado)";
        }
        if(cargo == "Cajero") {
            q ="INSERT INTO cajero (id_empleado) VALUES (:id_empleado)";
        }
        if(cargo == "Manager") {
            q ="INSERT INTO manager (id_empleado) VALUES (:id_empleado)";
        }
        query.prepare(q);
        query.bindValue(":id_empleado" , idEmpleado);

        if(query.exec())
        {
            return true;
        }else{
            qCritical() << "Last Query: " << query.lastQuery();
            qCritical() << query.lastError().text();
            return false;
        }
    }else{
        qDebug() << "Ya existe cargo del empleado: " << idEmpleado << " con cargo" << cargo;
        return false;
    }

}

int EmpleadoServicio::verificarCargo(const int &idEmpleado, const QString &cargo){
    QSqlQuery query(db);
    QString q;
    if(cargo == "Mesero") {
        q = "SELECT id_mesero FROM mesero WHERE id_empleado = :id_empleado";
    }
    if(cargo == "Host") {
        q ="SELECT id_host FROM host WHERE id_empleado = :id_empleado";
    }
    if(cargo == "Cocinero") {
        q ="SELECT id_cocinero FROM cocinero WHERE id_empleado = :id_empleado";
    }
    if(cargo == "Cajero") {
        q ="SELECT id_cajero FROM cajero WHERE id_empleado = :id_empleado";
    }
    if(cargo == "Manager") {
        q ="SELECT id_manager FROM manager WHERE id_empleado = :id_empleado";
    }
    query.prepare(q);
    query.bindValue(":id_empleado" , idEmpleado);

    if(query.exec())
    {
        query.next();
        qDebug () << "id existente: " << query.value(0).toInt();
        return query.value(0).toInt();
    }else{
        qCritical() << "Last Query: " << query.lastQuery();
        qCritical() << query.lastError().text();
        return 0;
    }

}

int EmpleadoServicio::obtenerIdEmpleado(){
    return idEmpleado;
}
