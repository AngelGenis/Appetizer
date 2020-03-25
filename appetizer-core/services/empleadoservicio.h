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
    bool actualizarEmpleado(const int &idEmpleado, const QString &urlFoto, const QString &nombre,
                            const QDate &f_naci, const QString &sexo, const double &sueldo,
                            const QDate &f_ingre, const QString &tel, const QString &correo,
                            const QString &password);
    bool agregarEmpleadoDefault();
    int  obtenerIdEmpleado();
    bool agregarCargo(const int &idEmpleado, const QString &cargo);
    int verificarCargo(const int &idEmpleado, const QString &cargo);
    bool eliminarEmpleado(const int &idEmpleado, const QString &cargo);
    QString obtenerImagen(QString nombreEmpleado);

private:
    QSqlDatabase &db;
    int idEmpleado;
};

#endif // EMPLEADOSERVICIO_H
