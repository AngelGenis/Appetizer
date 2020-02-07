#include "tarjetaplatillo.h"
#include "ui_tarjetaplatillo.h"

#include <QDateTime>
#include <QDebug>
#include <QGraphicsDropShadowEffect>

TarjetaPlatillo::TarjetaPlatillo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TarjetaPlatillo)
{
    ui->setupUi(this);
}


TarjetaPlatillo::TarjetaPlatillo(Platillo1 platillo, QWidget *parent):
    QWidget(parent),
    ui(new Ui::TarjetaPlatillo)
{
    ui->setupUi(this);
    ui->nombre->setText(platillo.nombre);
    QPixmap pixmap(platillo.urlFoto);
    ui->img->setPixmap(pixmap);
    ui->descripcion->setText(platillo.descripcion);
    ui->descripcion->hide();

    aplicarSombraNormal();

}

TarjetaPlatillo::~TarjetaPlatillo()
{
    delete ui;
}

void TarjetaPlatillo::on_hoverState_pressed(){
    mLastPressTime=QDateTime::currentMSecsSinceEpoch();
}

void TarjetaPlatillo::aplicarSombraNormal(){
    // shadow
    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect;
    effect->setBlurRadius(55);
    effect->setXOffset(0);
    effect->setYOffset(4);
    QColor rgb(202,206,213);
    effect->setColor(rgb);

    this->setGraphicsEffect(effect);
}

void TarjetaPlatillo::on_hoverState_released()
{
        const quint64 pressTime = QDateTime::currentMSecsSinceEpoch() - mLastPressTime;
        if( pressTime > MY_LONG_PRESS_THRESHOLD){
            if(ui->descripcion->isHidden()) {
                ui->descripcion->show();
                QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect;
                effect->setBlurRadius(30);
                effect->setXOffset(0);
                effect->setYOffset(4);
                QColor rgb(160,160,160);
                effect->setColor(rgb);

                this->setGraphicsEffect(effect);
            }
            else {
                ui->descripcion->hide();
                aplicarSombraNormal();
            }
        }
}
