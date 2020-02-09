#include "menubutton.h"
#include "ui_menubutton.h"

#include <QDebug>

MenuButton::MenuButton(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuButton)
{
    ui->setupUi(this);
}

MenuButton::MenuButton(Categoria categoria, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuButton)
{
    ui->setupUi(this);
    categoriaAct = categoria;
    ui->btn->setText(categoriaAct.nombre);
}

MenuButton::~MenuButton(){
    delete ui;
}

void MenuButton::on_btn_clicked(){
    ui->btn->setStyleSheet(
                "QPushButton{"
                    "color: #3C6AF1;"
                    "font: 12x \"SF Pro Text\";"
                    "border: 2px solid rgba(0,0,0,0);"
                    "padding-bottom: 11px;"
                    "border-bottom: 2px solid #3C6AF1;"
                    "padding-left: 15px;"
                    "padding-right: 15px;"
                "}"
                );
}