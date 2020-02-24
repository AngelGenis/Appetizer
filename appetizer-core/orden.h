#ifndef ORDEN_H
#define ORDEN_H
#include<QGridLayout>
#include <QWidget>
#include <QListWidget>
#include <QListWidgetItem>
#include "platillo.h"
#include <QDebug>
#include <QDateTime>
#include <QGridLayout>
#include <components-mesero/tarjetaplatillo.h>
#include <QList>
#include <QPushButton>
#include <QList>
#include <QComboBox>

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
    void setMesa(int numMesa);
    
void clearLayout(QLayout *layout);
    ~Orden();

public slots:
    void on_btn_ordenar_clicked();
    void platilloEliminado(int);
    /*Receptor de tarjeta que clickearon*/
    void on_tarjeta_clickeada(Platillo1);

    void obtenerCantidad(int, int);

    void obtenerComentario(int, QString);

    void eliminarWidgets(QWidget *);

private slots:
    void on_btn_imprimir_clicked();

     void on_btnAgregarCuenta_clicked();

 void on_cb_Cuentas_currentIndexChanged(int index);

private:
    Ui::Orden *ui;
    OrderService *orden;
    PlatilloService *platServ;
    static QGridLayout *gl;
    static Platillo *plati;
    static Orden *ord;
    QString fechaHora;
    static QString nombrePlat, coment;
    static int idPlati, cantidad, auxidPlati;
    int idMesa, idOrden, idBebida, idPlatillo=0, prueba=0;
    QSqlDatabase &db;
    static QList<int> idsPlati;
    static QList<QString> nombresPlati;
    static QMultiMap<int, int> cant;
    static QMultiMap<int, QString> comen;
    static QList <QList<Platillo1>*> ordenesp;
  static QComboBox* cbox;
};

#endif // ORDEN_H
