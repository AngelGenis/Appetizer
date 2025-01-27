#ifndef CONTENEDOR_GRAFICAS_H
#define CONTENEDOR_GRAFICAS_H

#include <QWidget>

namespace Ui {
class contenedor_graficas;
}

class contenedor_graficas : public QWidget
{
    Q_OBJECT

public:
    explicit contenedor_graficas(QWidget *parent = nullptr);
    ~contenedor_graficas();

private slots:
    void on_btn_ingresos_clicked();

    void on_btn_densidad_clicked();

    void on_btn_popularidad_clicked();

private:
    Ui::contenedor_graficas *ui;
};

#endif // CONTENEDOR_GRAFICAS_H
