#ifndef ORDEN_H
#define ORDEN_H

#include <QWidget>
#include <QListWidget>
#include <QListWidgetItem>
#include "platillo.h"
#include <QDebug>
#include <QDateTime>
#include <QGridLayout>
#include <components-mesero/tarjetaplatillo.h>


class QSqlDatabase;
class QSqlRecord;

namespace Ui {
class Orden;
}
class OrderService;
class PlatilloService;
class Platillo;

class Orden : public QWidget
{
    Q_OBJECT

public:
    explicit Orden(QWidget *parent = nullptr);
    void actualizarCuentasItems();
    int countWidgets();
    void setPlatillo(int);
    void mostrarWidgets(QWidget *);
    static void eliminarWidgets(QWidget *);
    ~Orden();

public slots:
    void on_btn_ordenar_clicked();

    /*Receptor de tarjeta que clickearon*/
    void on_tarjeta_clickeada(Platillo1);

private slots:
    void on_btn_imprimir_clicked();

private:
    Ui::Orden *ui;
    OrderService *orden;
    PlatilloService *platServ;
    static QGridLayout *gl;
    static Platillo *plati;
    QString fechaHora;
    static QString nombrePlat;
    static int idPlati;
    int idMesa, idOrden, idBebida, idPlatillo=0, prueba=0;
    QSqlDatabase &db;
    static QList<int> idsPlati;
};

#endif // ORDEN_H
