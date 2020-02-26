#ifndef CATEGORIAS_H
#define CATEGORIAS_H

#include <QWidget>

namespace Ui {
class Categorias;
class CrudPlatillo;
}

class Categorias : public QWidget
{
    Q_OBJECT

public:
    explicit Categorias(QWidget *parent = nullptr);
    Categorias(int _id, QString _nombre, QWidget *parent = nullptr);
    ~Categorias();

public slots:
    void on_categoria_clickeada(int id, QString nombre);

private:
    Ui::Categorias *ui;
    static int idCat;
    static QString nomCat;

signals:
    int obtenerCategoria(int id, QString nombre);
};

#endif // CATEGORIAS_H
