#ifndef PLATILLOSERVICE_H
#define PLATILLOSERVICE_H
#include <QString>

class QSqlDatabase;
class QSqlRecord;


class PlatilloService
{
public:
    PlatilloService();
    QString obtenerPlatillo();
    QString obtenerPrecio();
private:
    QSqlDatabase &db;
};

#endif // PLATILLOSERVICE_H
