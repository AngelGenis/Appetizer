#include "navegador.h"
#include "ui_navegador.h"

#include <QGraphicsDropShadowEffect>

Navegador::Navegador(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Navegador)
{
    ui->setupUi(this);
    //ui->btn_goMesas->hide();

}

Navegador::~Navegador()
{
    delete ui;
}

void Navegador::setDatosUsuario(QString nombre, QString cargo, QString foto){
    QPixmap img(foto);
    ui->nombre->setText(nombre);
    ui->cargo->setText(cargo);
    ui->imgHeader->setPixmap(img);
}

void Navegador::setEditorMode(bool editor)
{
    QString src = editor ? "://Img/Logo.png" : "://Img/ham.png";
    QPixmap pix(src);
    ui->logo->setPixmap(pix);
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

void Navegador::on_btn_goMesas_clicked()
{
   // ui->btn_goMesas->hide();
    emit btnAtrasMesasClicked();

}
