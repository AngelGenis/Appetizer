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
#include <QList>
#include "components-mesero/tarjetaplatillo.h"
#include <QComboBox>
class QSqlDatabase;
class QSqlRecord;

namespace Ui {
class Orden;
}
class OrderService;
class Platillo;

class Orden : public QWidget
{
    Q_OBJECT

public:
    explicit Orden(QWidget *parent = nullptr);
    void actualizarCuentasItems();
    void mostrarWidgets(QWidget*);
    ~Orden();
void clearLayout(QLayout *layout);
 QGridLayout* devolverLay();
public slots:
 void ponerPlatillos();
 void on_tarjeta_clickeada(Platillo1);
 void platilloEliminado(int);
private slots:
    void on_btn_ordenar_clicked();

    void on_btnAgregarCuenta_clicked();

    void on_cb_Cuentas_currentIndexChanged(int index);

private:
    Ui::Orden *ui;
    OrderService *orden;
    QDateTime fechaHora;
    QString as;
    int idMesa, idOrden, idPlatillo, idBebida,numCuenta;
    QSqlDatabase &db;
    QGridLayout* laynueva;
    QList<QPushButton*> botones;
    static QGridLayout* glay;
    static QString nombre;
    static int indice;
    static Platillo* plati4;
  static QList <QList<Platillo1>*> ordenesp;
  static QComboBox* cbox;

};

#endif // ORDEN_H
