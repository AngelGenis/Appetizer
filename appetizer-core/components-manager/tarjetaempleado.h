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
    explicit TarjetaEmpleado(const QString &nombre, QWidget *parent = nullptr);
    ~TarjetaEmpleado();
    QWidget *wid();
    void setSelected(bool selected);

private:
    Ui::TarjetaEmpleado *ui;
};

#endif // TARJETAEMPLEADO_H
