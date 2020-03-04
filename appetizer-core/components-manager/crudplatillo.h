#ifndef CRUDPLATILLO_H
#define CRUDPLATILLO_H

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>
#include <components-mesero/tarjetaplatillo.h>

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
    void mostrarCategoriasPlatillo();
    void clearLayout(QHBoxLayout *layout);


private slots:
    void on_btn_agregarImagen_clicked();

    void on_btn_guardarCambios_clicked();

    void on_tV_categorias_doubleClicked(const QModelIndex &index);

    void on_btn_agregarCategoria_clicked();

    void on_btn_EliminarPlatillo_clicked();

public slots:
    void eliminarWidget(QWidget *, int);
    void on_tarjeta_clickeada(Platillo1);

private:
    Ui::CrudPlatillo *ui;
    QSqlDatabase &db;
    static PlatilloService *platServ;
    static Categorias *categ;
    static CrudPlatillo *crudPla;
    static int idPlatillo;
    static QString nombre, descripcion, precio, imagen;
    QSqlTableModel *modeloCategoria;
    int idCategoria;
    QString nombreCategoria;
    QWidget *widElim;
    static QLineEdit *lE_nombre, *lE_precio;
    static QTextEdit *lE_desc;
    static QLabel *l_imagen;
    static QHBoxLayout *layoutCateg;
    static QPushButton *btn_imagen;
};

#endif // CRUDPLATILLO_H
