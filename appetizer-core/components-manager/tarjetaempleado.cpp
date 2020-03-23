#include "tarjetaempleado.h"
#include "ui_tarjetaempleado.h"
#include <QMouseEvent>
#include <QGraphicsDropShadowEffect>

TarjetaEmpleado::TarjetaEmpleado(const QString &nombre, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TarjetaEmpleado)
{
    ui->setupUi(this);
    ui->nombre->setText(nombre);
    ui->nombreSeleccionar->setText(nombre);
    setSelected(false);
    QGraphicsDropShadowEffect *dropshadow1 = new QGraphicsDropShadowEffect(this);
    QGraphicsDropShadowEffect *dropshadow2 = new QGraphicsDropShadowEffect(this);
    dropshadow1->setXOffset(0);
    dropshadow1->setYOffset(0);
    dropshadow1->setBlurRadius(10);
    dropshadow1->setColor(QColor::fromRgb(0, 0, 0, 70));
    dropshadow2->setXOffset(0);
    dropshadow2->setYOffset(0);
    dropshadow2->setBlurRadius(10);
    dropshadow2->setColor(QColor::fromRgb(0, 0, 0, 70));

    ui->label->setGraphicsEffect(dropshadow1);
    ui->nombreSeleccionar->setGraphicsEffect(dropshadow2);
}

TarjetaEmpleado::~TarjetaEmpleado()
{
    delete ui;
}

QWidget *TarjetaEmpleado::wid(){
    return this;
}

void TarjetaEmpleado::setSelected(bool selected)
{
    ui->seleccionar->setHidden(!selected);
    ui->label->setHidden(selected);
    ui->seleccionar->setHidden(!selected);
    ui->nombre->setHidden(selected);
}
