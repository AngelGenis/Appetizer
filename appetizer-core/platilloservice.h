#ifndef PLATILLOSERVICE_H
#define PLATILLOSERVICE_H
#include <QString>
#include <QStringList>

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
    void getFoto(QStringList);
    bool actualizarDatosPlatillo(const int &idPlatillo, const QString &nombre, const double &precio,
                                 const QString &descripcion, const QString &imagen);
    bool agregarCategoria(const QString &nombre);
    bool agregarPlatilloCategoria(const int &idCategoria, const int &idPlat);
    bool eliminarCategoriaPlatillo(const int &idCategoria, const int &idPlati);
    bool agregarPlatilloDefault();
    bool eliminarPlatillo(const int &idPlatillo);
    int obtenerIdPlatillo();
    void guardarCambios();
    void cancelarCambios();
private:
    QSqlDatabase &db;
    QString comentario;
    int idPlatillo, idOrden;
    QStringList foto;
};

#endif // PLATILLOSERVICE_H
