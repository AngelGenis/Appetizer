#include "menuplatillos.h"
#include "ui_menuplatillos.h"

MenuPlatillos::MenuPlatillos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuPlatillos)
{
    ui->setupUi(this);
    ui->buscador->setAttribute(Qt::WA_MacShowFocusRect,0);
}

MenuPlatillos::~MenuPlatillos()
{
    delete ui;
}
