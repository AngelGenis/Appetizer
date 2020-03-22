#ifndef EMPLEADOSERVICIO_H
#define EMPLEADOSERVICIO_H

#include <QString>

class QSqlDatabase;
class QSqlRecord;

class EmpleadoServicio
{
public:
    EmpleadoServicio();
    QStringList getEmpleadosFiltro(QString categoria, QString buscar);

private:
    QSqlDatabase &db;
};

#endif // EMPLEADOSERVICIO_H
