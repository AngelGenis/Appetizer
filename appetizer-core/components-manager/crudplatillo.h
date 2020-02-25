#ifndef CRUDPLATILLO_H
#define CRUDPLATILLO_H

#include <QWidget>

class QSqlDatabase;
class QSqlRecord;
class PlatilloService;
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

private slots:
    void on_btn_agregarImagen_clicked();

    void on_btn_guardarCambios_clicked();

private:
    Ui::CrudPlatillo *ui;
    QSqlDatabase &db;
    PlatilloService *platServ;
    static int idPlatillo;
    static QString nombre, descripcion, precio, imagen;
};

#endif // CRUDPLATILLO_H
