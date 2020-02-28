#ifndef MENUPLATILLOS_H
#define MENUPLATILLOS_H
#include "orden.h"

#include "menubutton.h"
#include "tarjetaplatillo.h"

#include <QSqlDatabase>
#include <QWidget>
#include <QDebug>
#include "platillo.h"
#include "tarjetaplatillo.h"
#include<QGridLayout>

class Orden;
namespace Ui {
class MenuPlatillos;
}

class MenuPlatillos : public QWidget
{
    Q_OBJECT

public:
    explicit MenuPlatillos(QWidget *parent = nullptr);
    void clearLayout(QLayout *layout);
    ~MenuPlatillos();
     void setOrdenWidget(QWidget *ordenWidget);
     void setEditionMode();

private:
    Ui::MenuPlatillos *ui;
    QSqlDatabase mDatabase;
    void limpiarLayout(QLayout *);
    void llenarCatalogo();
    void llenarCategorias();
    Categoria categoriaActual;
    QString busqueda = "";
    Orden *orden;
    int i = 0;
    int row = 0;
    int col = 0;

public slots:
    void setCategoria(Categoria);

private slots:
    void on_buscador_textChanged(const QString &arg1);
    void on_btn_agregarPlatillo_clicked();
    void on_btn_agregarCategoria_clicked();
};

#endif // MENUPLATILLOS_H
