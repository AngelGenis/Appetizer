#ifndef TARJETAPLATILLO_H
#define TARJETAPLATILLO_H

#include <QWidget>
#include <QPushButton>
#include <QSqlDatabase>
struct Platillo1{
    int id;
    QString nombre;
    QString precio;
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
    QPushButton* devolverBoton();
private slots:
    void on_hoverState_pressed();
    void on_hoverState_released();
    void on_hoverState_clicked();



    void on_btnEliminarTarjeta_clicked();

private:
    Ui::TarjetaPlatillo *ui;
    bool longTapped = false;
    Platillo1 plat;
    quint64 mLastPressTime=0;
    static const quint64 MY_LONG_PRESS_THRESHOLD=500;
    int idPlatillo;
    QSqlDatabase mDatabase;

signals:
    void longPressEvent();
    int clicked(Platillo1);
    void clickedPlatillo(Platillo1);

};

#endif // TARJETAPLATILLO_H
