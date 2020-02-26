#include "categorias.h"
#include "ui_categorias.h"

int Categorias::idCat = 0;
QString Categorias::nomCat = "";
Categorias::Categorias(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Categorias)
{
    ui->setupUi(this);
}

Categorias::Categorias(int _id, QString _nombre, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Categorias)
{
    ui->setupUi(this);
    idCat   = _id;
    nomCat  = _nombre;
    ui->nombreCategoria->setText(nomCat);
}

Categorias::~Categorias()
{
    delete ui;
}

void Categorias::on_categoria_clickeada(int id, QString nombre){
    idCat = id;
    nomCat = nombre;
}
