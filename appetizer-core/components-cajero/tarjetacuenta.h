#ifndef TARJETACUENTA_H
#define TARJETACUENTA_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class tarjetaCuenta;
}
class QSqlDatabase;

class tarjetaCuenta : public QWidget
{
    Q_OBJECT

public:
    explicit tarjetaCuenta(QWidget *parent = nullptr);
    ~tarjetaCuenta();
    void llenarCuenta(QString mesa, QString fecha, QString hora, QString precioCuenta);

private slots:
    void on_btn_mesa_clicked();

private:
    Ui::tarjetaCuenta *ui;
    QSqlDatabase &db;
    QString mesa;
    bool band = false;
};

#endif // TARJETACUENTA_H
