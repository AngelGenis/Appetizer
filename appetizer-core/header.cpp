#include "header.h"
#include "ui_header.h"

Header::Header(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Header)
{
    ui->setupUi(this);
}

Header::~Header()
{
    delete ui;
}
