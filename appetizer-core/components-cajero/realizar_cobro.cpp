#include "realizar_cobro.h"
#include "ui_realizar_cobro.h"

realizar_cobro::realizar_cobro(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::realizar_cobro)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(1);

}

realizar_cobro::~realizar_cobro()
{
    delete ui;
}
