#ifndef MENUPLATILLOS_H
#define MENUPLATILLOS_H
#include "orden.h"
#include <QSqlDatabase>
#include <QWidget>
#include <QDebug>
#include "platillo.h"
#include<QGridLayout>
#include "orden.h"
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
private slots:
    void agregarPlatillos(QString);
private:
    Ui::MenuPlatillos *ui;
    QSqlDatabase mDatabase;
    void limpiarLayout(QLayout *);
    void llenarCatalogo();
    void llenarCategorias();
    Orden orden;
    QGridLayout *lay;

};

#endif // MENUPLATILLOS_H
