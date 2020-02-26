#ifndef CRUDPLATILLO_H
#define CRUDPLATILLO_H

#include <QWidget>

class QSqlDatabase;
class QSqlRecord;
class QSqlTableModel;
class PlatilloService;
class Categorias;
namespace Ui {
class CrudPlatillo;
}
class CrudPlatillo : public QWidget
{
    Q_OBJECT

public:
    explicit CrudPlatillo(QWidget *parent = nullptr);
    ~CrudPlatillo();
    void mostrarDatosPlatillo();
    void obtenerDatosPlatillo();
    void mostrarCategorias();

private slots:
    void on_btn_agregarImagen_clicked();

    void on_btn_guardarCambios_clicked();

    void on_tV_categorias_doubleClicked(const QModelIndex &index);

private:
    Ui::CrudPlatillo *ui;
    QSqlDatabase &db;
    PlatilloService *platServ;
    static Categorias *categ;
    static int idPlatillo;
    static QString nombre, descripcion, precio, imagen;
    QSqlTableModel *modeloCategoria;
    int idCategoria;
    QString nombreCategoria;
};

#endif // CRUDPLATILLO_H
