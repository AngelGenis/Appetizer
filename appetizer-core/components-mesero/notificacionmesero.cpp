#include "notificacionmesero.h"
#include "ui_notificacionmesero.h"

NotificacionMesero::NotificacionMesero(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NotificacionMesero)
{
    ui->setupUi(this);
}

NotificacionMesero::~NotificacionMesero()
{
    delete ui;
}

void NotificacionMesero::insertarDatos(QString numMesa, QString informacion, QString imagen)
{
    ui->numMesa->setText(numMesa);
    ui->informacion->setText(informacion);
    QPixmap imag(imagen);
    ui->imagen->setPixmap(imag);

}
