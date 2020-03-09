#ifndef TARJETAORDEN_H
#define TARJETAORDEN_H

#include <QWidget>

namespace Ui {
class tarjetaOrden;
}

class tarjetaOrden : public QWidget
{
    Q_OBJECT

public:
    explicit tarjetaOrden(QWidget *parent = nullptr);
    ~tarjetaOrden();

private:
    Ui::tarjetaOrden *ui;
};

#endif // TARJETAORDEN_H
