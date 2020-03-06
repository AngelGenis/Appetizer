#ifndef CATEGORIAS_H
#define CATEGORIAS_H

#include <QWidget>
class CrudPlatillo;
namespace Ui {
class Categorias;
}

class Categorias : public QWidget
{
    Q_OBJECT

public:
    explicit Categorias(QWidget *parent = nullptr);
    Categorias(int _id, QString _nombre, QWidget *parent = nullptr);
    ~Categorias();

private:
    Ui::Categorias *ui;
    static int idCat;
    static QString nomCat;
    CrudPlatillo *crudPlat;

signals:
    //int obtenerCategoria(int id, QString nombre);
    void elimWid(QWidget *, int);
private slots:
    void on_btn_borrar_clicked();
};

#endif // CATEGORIAS_H
