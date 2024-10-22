#include "toolbar.h"
#include "ui_toolbar.h"

toolbar::toolbar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::toolbar)
{
    ui->setupUi(this);
    setSelectedMode(false);
}

toolbar::~toolbar()
{
    delete ui;
}
void toolbar::setSelectedMode(bool selected)
{
    ui->btn_eliminarMesa->setEnabled(selected);
    ui->btn_editarAsientos->setEnabled(selected);
}

void toolbar::on_btn_editarFondo_clicked()
{
    emit clickedEditarFondo();
}

void toolbar::on_btn_agregarMesa_clicked()
{
    emit clickedAgregarMesa();
}

void toolbar::on_btn_editarAsientos_clicked()
{
    emit clickedEditarAsiento();
}

void toolbar::on_btn_eliminarMesa_clicked()
{
    emit clickedEliminarMesa();
}
