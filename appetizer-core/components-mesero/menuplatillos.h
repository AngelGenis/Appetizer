#ifndef MENUPLATILLOS_H
#define MENUPLATILLOS_H

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

public slots:
    void setCategoria(int idCategoria);
};

#endif // MENUPLATILLOS_H
