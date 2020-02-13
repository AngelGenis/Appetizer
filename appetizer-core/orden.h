#ifndef ORDEN_H
#define ORDEN_H
#include<QGridLayout>
#include <QWidget>
#include <QListWidget>
#include <QListWidgetItem>
#include "platillo.h"
#include <QDebug>
#include <QDateTime>
#include <QList>
#include <QPushButton>
#include "components-mesero/tarjetaplatillo.h"
class QSqlDatabase;
class QSqlRecord;

namespace Ui {
class Orden;
}
class OrderService;

class Orden : public QWidget
{
    Q_OBJECT

public:
    explicit Orden(QWidget *parent = nullptr);
    void actualizarCuentasItems();
    ~Orden();
void clearLayout(QLayout *layout);
 QGridLayout* devolverLay();
public slots:
 void ponerPlatillos();
private slots:

    void on_btn_ordenar_clicked();

    void on_btnAgregarCuenta_clicked();

private:
    Ui::Orden *ui;
    OrderService *orden;
    QDateTime fechaHora;
    QString as;
    int idMesa, idOrden, idPlatillo, idBebida,numCuenta;
    QSqlDatabase &db;
    QGridLayout* laynueva;
    QList<QPushButton*> botones;
    static QLayout* glay;
    static QString nombre;
    static int indice;
    static Platillo* plati4;

};

#endif // ORDEN_H
