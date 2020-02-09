#ifndef TARJETAPLATILLO_H
#define TARJETAPLATILLO_H

#include <QWidget>

struct Platillo1{
    QString nombre;
    QString descripcion;
    QString urlFoto;
};

namespace Ui {
class TarjetaPlatillo;
}

class TarjetaPlatillo : public QWidget
{
    Q_OBJECT

public:
    explicit TarjetaPlatillo(QWidget *parent = nullptr);
    TarjetaPlatillo(Platillo1 platillo, QWidget *parent = nullptr);
    ~TarjetaPlatillo();
    void aplicarSombraNormal();

private slots:
    void on_hoverState_pressed();
    void on_hoverState_released();

private:
    Ui::TarjetaPlatillo *ui;
    bool longTapped = false;

    quint64 mLastPressTime=0;
    static const quint64 MY_LONG_PRESS_THRESHOLD=500;

signals:
    void longPressEvent();

};

#endif // TARJETAPLATILLO_H
