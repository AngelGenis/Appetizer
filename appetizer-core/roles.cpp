#include "roles.h"
#include "ui_roles.h"
#include <QMouseEvent>

Roles::Roles(const QString &nombre, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Roles)
{
    ui->setupUi(this);
    ui->nombre->setText(nombre);
}

Roles::~Roles()
{
    delete ui;
}

QString Roles::name() const
{
    return ui->nombre->text();
}

// void Roles::mousePressEvent(QMouseEvent *event)
// {
//     if (event->type() == QEvent::MouseButtonPress)
//     {
//         emit clicked(ui->nombre->text());
//     }
//     QWidget::mousePressEvent(event);
// }
