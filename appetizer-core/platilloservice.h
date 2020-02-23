#ifndef PLATILLOSERVICE_H
#define PLATILLOSERVICE_H
#include <QString>

class QSqlDatabase;
class QSqlRecord;


class PlatilloService
{
public:
    PlatilloService();
    QString obtenerPlatillo(int);
    QString obtenerPrecio(int);
    bool guardarComentario(const int &idOrden, const int &idPlatillo, const QString &comentario);
    void getComentario(QString comentario);
    QString setComentario();
private:
    QSqlDatabase &db;
    QString comentario;
    int idPlatillo, idOrden;
};

#endif // PLATILLOSERVICE_H
