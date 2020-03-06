#include "tarjetaplatillo.h"
#include "ui_tarjetaplatillo.h"

#include <QDateTime>
#include <QDebug>
#include <QGraphicsDropShadowEffect>
#include <QSqlQuery>

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

    plat = platillo;
    idPlatillo = plat.id;
    ui->nombre->setText(plat.nombre);
    QPixmap pixmap(plat.urlFoto);
    ui->img->setPixmap(pixmap);
    ui->descripcion->setText(plat.descripcion);
    ui->descripcion->hide();

    aplicarSombraNormal();

}

TarjetaPlatillo::~TarjetaPlatillo()
{
    delete ui;
}

void TarjetaPlatillo::on_hoverState_pressed(){
    if(longTapped){
        longTapped = false;
        ui->descripcion->hide();
        aplicarSombraNormal();
        ui->btnEliminarTarjeta->hide();
        ui->img_btn->hide();
    }
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
            longTapped = true;
            if(ui->descripcion->isHidden()) {
                ui->descripcion->show();
                ui->btnEliminarTarjeta->show();
                ui->img_btn->show();

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
                ui->img_btn->hide();
                ui->btnEliminarTarjeta->hide();
                aplicarSombraNormal();

            }
        }
}

void TarjetaPlatillo::on_hoverState_clicked(){
    emit clicked(plat);
    emit clickedPlatillo(plat);
}

void TarjetaPlatillo::on_btnEliminarTarjeta_clicked(){

    QSqlQuery query(mDatabase);

    QString est = "agotado";

    query.prepare("UPDATE platillo SET estado = '"+ est +"'" + " WHERE id_platillo = " +  QString::number(idPlatillo));

    query.exec();


}
