#include "navegador.h"
#include "ui_navegador.h"

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

void Navegador::on_btn_goMesas_clicked(){


}
