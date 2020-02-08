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
    void limpiarCatalogo();
    void llenarCatalogo();
};

#endif // MENUPLATILLOS_H
