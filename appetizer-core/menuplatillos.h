#ifndef MENUPLATILLOS_H
#define MENUPLATILLOS_H

#include <QWidget>

namespace Ui {
class MenuPlatillos;
}

class MenuPlatillos : public QWidget
{
    Q_OBJECT

public:
    explicit MenuPlatillos(QWidget *parent = nullptr);
    ~MenuPlatillos();

private:
    Ui::MenuPlatillos *ui;
};

#endif // MENUPLATILLOS_H
