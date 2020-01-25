#include "roles.h"
#include "ui_roles.h"

Roles::Roles(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Roles)
{
    ui->setupUi(this);
}

Roles::~Roles()
{
    delete ui;
}
