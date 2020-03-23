#ifndef PLATILLO_CUENTA_H
#define PLATILLO_CUENTA_H

#include <QWidget>

namespace Ui {
class platillo_cuenta;
}

class platillo_cuenta : public QWidget
{
    Q_OBJECT

public:
    explicit platillo_cuenta(QWidget *parent = nullptr);
    ~platillo_cuenta();
    void llenarPlatillo(QString cantidad, QString nombre, QString total);

private:
    Ui::platillo_cuenta *ui;
};

#endif // PLATILLO_CUENTA_H
