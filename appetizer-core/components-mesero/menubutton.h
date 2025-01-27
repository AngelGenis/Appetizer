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
    void click();

private slots:
    void on_btn_clicked();

public slots:
    void setDefaultStyles();

private:
    Ui::MenuButton *ui;
    int estado = normal;
    Categoria categoriaAct;

signals:
    void btnClicked(Categoria);

};

#endif // MENUBUTTON_H
