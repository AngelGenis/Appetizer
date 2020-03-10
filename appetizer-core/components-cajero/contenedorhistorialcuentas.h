#ifndef CONTENEDORHISTORIALCUENTAS_H
#define CONTENEDORHISTORIALCUENTAS_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class contenedorHistorialCuentas;
}
class QSqlDatabase;

class contenedorHistorialCuentas : public QWidget
{
    Q_OBJECT

public:
    explicit contenedorHistorialCuentas(QWidget *parent = nullptr);
    ~contenedorHistorialCuentas();
    void llenarCuentas();
    void limpiarCatalogo();

private slots:
    void on_fecha_textChanged(const QString &arg1);

private:
    Ui::contenedorHistorialCuentas *ui;
    QSqlDatabase &db;
};

#endif // CONTENEDORHISTORIALCUENTAS_H
