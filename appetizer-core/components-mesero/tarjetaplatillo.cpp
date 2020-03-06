#include "tarjetaplatillo.h"
#include "ui_tarjetaplatillo.h"
#include "services/notificationservice.h"
#include "services/authenticationservice.h"

#include <QDateTime>
#include <QDebug>
#include <QGraphicsDropShadowEffect>
#include <QSqlQuery>
#include <QMessageBox>


TarjetaPlatillo::TarjetaPlatillo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TarjetaPlatillo),
    notiService(new NotificationService(this)),
    authSrv(new AuthenticationService)
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
      qDebug()<<"Si entra ala eliminacion";
      QMessageBox msgBox;
      msgBox.setWindowTitle("Platillo");
      msgBox.setText("¿Está seguro de eliminar el platillo del menú?");
      msgBox.setStandardButtons(QMessageBox::Yes);
      msgBox.addButton(QMessageBox::No);
      msgBox.setDefaultButton(QMessageBox::Yes);

      if(msgBox.exec() == QMessageBox::Yes){
          QSqlQuery query(mDatabase);

          QString est = "agotado";
          query.prepare("UPDATE platillo SET estado = '"+ est +"'" + " WHERE id_platillo = " +  QString::number(idPlatillo));
          query.exec();

          //emit senial_actualizar_catalogo();
          /*notiService->notify("Se eliminó del menú correctamente",
                              Qt::AlignBottom,
                              4000,
                              NotificationDialog::Information);*/

      }



}
