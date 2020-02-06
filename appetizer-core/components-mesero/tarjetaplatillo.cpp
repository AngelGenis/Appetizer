#include "tarjetaplatillo.h"
#include "ui_tarjetaplatillo.h"

TarjetaPlatillo::TarjetaPlatillo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TarjetaPlatillo)
{
    ui->setupUi(this);
}

TarjetaPlatillo::~TarjetaPlatillo()
{
    delete ui;
}
