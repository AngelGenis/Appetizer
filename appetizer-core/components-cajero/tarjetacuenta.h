#ifndef TARJETACUENTA_H
#define TARJETACUENTA_H

#include <QWidget>

namespace Ui {
class tarjetaCuenta;
}

class tarjetaCuenta : public QWidget
{
    Q_OBJECT

public:
    explicit tarjetaCuenta(QWidget *parent = nullptr);
    ~tarjetaCuenta();

private:
    Ui::tarjetaCuenta *ui;
};

#endif // TARJETACUENTA_H
