#ifndef ORDERSERVICE_H
#define ORDERSERVICE_H
#include <QString>
#include <QDateTime>
class QSqlDatabase;
class QSqlRecord;

class OrderService
{
public:
    OrderService();
    bool crearOrdenPlatillo(const int &idOrden, const int &idPlatillo, const int &cantidad, const QString &descripcion);
    bool crearOrdenBebida(const int &idOrden,const int &idBebida);
    bool crearOrden(const QString &horaFecha, const int &idMesa);
    int getIdOrden();
private:
    QSqlDatabase &db;
    int idOrden;
    //QString lastErrorMsg;
};


#endif // ORDERSERVICE_H
