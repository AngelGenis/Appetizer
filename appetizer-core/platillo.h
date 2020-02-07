#ifndef PLATILLO_H
#define PLATILLO_H

#include <QWidget>
#include <QSqlDatabase>



namespace Ui {
class Platillo;
}
class PlatilloService;
class Platillo : public QWidget
{
    Q_OBJECT

public:
    explicit Platillo(QWidget *parent = nullptr);
    void actualizarCuentasItems();
    ~Platillo();

private slots:
    void on_btnEliminar_clicked();

private:
    Ui::Platillo *ui;
    int idPlatillo=1;
    PlatilloService *plat;

};

#endif // PLATILLO_H
