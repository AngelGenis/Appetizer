#include "realizar_cobro2.h"
#include "ui_realizar_cobro2.h"

realizar_cobro2::realizar_cobro2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::realizar_cobro2)
{
    ui->setupUi(this);
}

realizar_cobro2::~realizar_cobro2()
{
    delete ui;
}
