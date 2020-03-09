#ifndef CONTENEDORHISTORIALCUENTAS_H
#define CONTENEDORHISTORIALCUENTAS_H

#include <QWidget>

namespace Ui {
class contenedorHistorialCuentas;
}

class contenedorHistorialCuentas : public QWidget
{
    Q_OBJECT

public:
    explicit contenedorHistorialCuentas(QWidget *parent = nullptr);
    ~contenedorHistorialCuentas();

private:
    Ui::contenedorHistorialCuentas *ui;
};

#endif // CONTENEDORHISTORIALCUENTAS_H
