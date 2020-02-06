#include "menuplatillos.h"
#include "ui_menuplatillos.h"

MenuPlatillos::MenuPlatillos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuPlatillos)
{
    ui->setupUi(this);
}

MenuPlatillos::~MenuPlatillos()
{
    delete ui;
}
