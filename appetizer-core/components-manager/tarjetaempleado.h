#ifndef TARJETAEMPLEADO_H
#define TARJETAEMPLEADO_H

#include <QWidget>

namespace Ui {
class TarjetaEmpleado;
}

class TarjetaEmpleado : public QWidget
{
    Q_OBJECT

public:
    explicit TarjetaEmpleado(QWidget *parent = nullptr);
    ~TarjetaEmpleado();
    QWidget *wid();

private:
    Ui::TarjetaEmpleado *ui;
};

#endif // TARJETAEMPLEADO_H
