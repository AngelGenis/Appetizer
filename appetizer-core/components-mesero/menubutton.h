#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <QWidget>

struct Categoria{
    int id;
    QString nombre;
};

enum estado{normal, hover, active};

namespace Ui {
class MenuButton;
}

class MenuButton : public QWidget
{
    Q_OBJECT

public:
    explicit MenuButton(QWidget *parent = nullptr);
    MenuButton(Categoria categoria, QWidget *parent = nullptr);
    ~MenuButton();

private slots:

    void on_btn_clicked();

private:
    Ui::MenuButton *ui;
    int estado = normal;
    Categoria categoriaAct;

};

#endif // MENUBUTTON_H
