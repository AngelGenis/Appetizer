#ifndef EMPLEADOSERVICIO_H
#define EMPLEADOSERVICIO_H

#include <QString>
#include <QDate>

class QSqlDatabase;
class QSqlRecord;
struct Empleado{
    QString nombre, urlFoto, sexo, telefono, correo, password, cargo;
    int idEmpleado;
    QDate fecha_nacimiento, fecha_ingreso;
    double sueldo;

};
enum tipoEmpleado {ninguno = 0, mes = 1, anfitrion = 2, caj = 3, chef = 4, admin = 5};

class EmpleadoServicio
{
public:
    EmpleadoServicio();
    QStringList getEmpleadosFiltro(QString categoria, QString buscar);
    tipoEmpleado getTipoDeUsuario(const QString &userName);
    Empleado getDatosEmpleado(const QString &userName);

private:
    QSqlDatabase &db;
};

#endif // EMPLEADOSERVICIO_H
