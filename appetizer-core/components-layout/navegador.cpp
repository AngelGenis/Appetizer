#include "navegador.h"
#include "ui_navegador.h"

#include <QGraphicsDropShadowEffect>

Navegador::Navegador(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Navegador)
{
    ui->setupUi(this);
}

Navegador::~Navegador()
{
    delete ui;
}

void Navegador::on_profileBtn_clicked()
{
    emit profileBtnClicked();
}

void Navegador::on_hamBtn_clicked()
{
    emit hamBtnClicked();
}

void Navegador::on_notifBtn_clicked()
{
    emit notificationBtnClicked();
}
