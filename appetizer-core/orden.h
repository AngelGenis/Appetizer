#ifndef ORDEN_H
#define ORDEN_H

#include <QWidget>
#include <QListWidget>
#include <QListWidgetItem>
#include "platillo.h"
#include <QDebug>
#include <QDateTime>
#include <components-mesero/tarjetaplatillo.h>


class QSqlDatabase;
class QSqlRecord;

namespace Ui {
class Orden;
}
class OrderService;
class PlatilloService;

class Orden : public QWidget
{
    Q_OBJECT

public:
    explicit Orden(QWidget *parent = nullptr);
    void actualizarCuentasItems();
    void countWidgets();
    ~Orden();

private slots:
    void on_btn_ordenar_clicked();

public slots:
    /*Receptor de tarjeta que clickearon*/
    void on_tarjeta_clickeada(Platillo1);

private:
    Ui::Orden *ui;
    OrderService *orden;
    PlatilloService *platServ;
    QString fechaHora;
    QString nombrePlat;
    int idMesa, idOrden, idPlatillo, idBebida;
    QSqlDatabase &db;
};

#endif // ORDEN_H
