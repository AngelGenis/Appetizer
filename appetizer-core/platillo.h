#ifndef PLATILLO_H
#define PLATILLO_H

#include <QWidget>
#include <QSqlDatabase>
#include <QDebug>


namespace Ui {
class Platillo;
}
class PlatilloService;
class Platillo : public QWidget
{
    Q_OBJECT

public:
    explicit Platillo(QWidget *parent = nullptr);
    Platillo(int _id,QWidget *parent=nullptr);
    void actualizarCuentasItems();

    ~Platillo();

private slots:
    void on_btnEliminar_clicked();

private:
    Ui::Platillo *ui;
    int idPlatillo=1, idOrden;
    PlatilloService *plat;



signals:
    int clicked(int);



};

#endif // PLATILLO_H
