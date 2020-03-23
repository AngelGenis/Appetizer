#ifndef ORDEN_CUENTA_H
#define ORDEN_CUENTA_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class orden_cuenta;
}
class QSqlDatabase;

class orden_cuenta : public QWidget
{
    Q_OBJECT

public:
    explicit orden_cuenta(QWidget *parent = nullptr);
    ~orden_cuenta();
    void llenarDatos(QString subtotal,QString total, QString iva);
    void llenarPlatillos();

private:
    Ui::orden_cuenta *ui;
    QSqlDatabase &db;
};

#endif // ORDEN_CUENTA_H
