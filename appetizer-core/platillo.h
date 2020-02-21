#ifndef PLATILLO_H
#define PLATILLO_H

#include <QWidget>
#include <QSqlDatabase>



namespace Ui {
class Platillo;
}
class PlatilloService;
class Orden;
class Platillo : public QWidget
{
    Q_OBJECT

public:
    explicit Platillo(QWidget *parent = nullptr);
    Platillo(int _id,QWidget *parent = nullptr);
    void actualizarCuentasItems();
    int getPlatillo();
    int getCantidad();
    ~Platillo();

private slots:
    void on_btnEliminar_clicked();

    void on_btnComentarios_clicked();

    void on_btnCancelarComentario_clicked();

    void on_btnGuardarComentario_clicked();

    void on_sbCantidad_valueChanged(int arg1);


private:
    Ui::Platillo *ui;
    int idPlatillo=1, idOrden, cantidad=1;
    QString comentario;
    PlatilloService *plat;
    Orden *ord;
    Platillo *plati;
    int sub;

signals:
    int changeValue(int value, int id);

    void saveComent(int, QString);

    void elimWid(QWidget *);

};

#endif // PLATILLO_H
