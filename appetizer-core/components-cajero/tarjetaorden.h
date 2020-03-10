#ifndef TARJETAORDEN_H
#define TARJETAORDEN_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class tarjetaOrden;
}
class QSqlDatabase;

class tarjetaOrden : public QWidget
{
    Q_OBJECT

public:
    explicit tarjetaOrden(QWidget *parent = nullptr);
    ~tarjetaOrden();
    void llenarOrden(QString nOrden, QString precioOrden);

private:
    Ui::tarjetaOrden *ui;
    QSqlDatabase &db;
};

#endif // TARJETAORDEN_H
