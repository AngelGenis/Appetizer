#ifndef MENUPLATILLOS_H
#define MENUPLATILLOS_H

#include "menubutton.h"

#include <QSqlDatabase>
#include <QWidget>

namespace Ui {
class MenuPlatillos;
}

class MenuPlatillos : public QWidget
{
    Q_OBJECT

public:
    explicit MenuPlatillos(QWidget *parent = nullptr);
    ~MenuPlatillos();

private:
    Ui::MenuPlatillos *ui;
    QSqlDatabase mDatabase;
    void limpiarLayout(QLayout *);
    void llenarCatalogo();
    void llenarCategorias();
    Categoria categoriaActual;
    QString busqueda = "";

public slots:
    void setCategoria(Categoria);
private slots:
    void on_buscador_textChanged(const QString &arg1);
};

#endif // MENUPLATILLOS_H
