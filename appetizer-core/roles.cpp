#include "roles.h"
#include "ui_roles.h"
#include <QMouseEvent>
#include <QGraphicsDropShadowEffect>

Roles::Roles(const QString &nombre, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Roles)
{
    ui->setupUi(this);
    ui->nombre->setText(nombre);
    ui->nombre_selected->setText(nombre);
    setSelected(false);
    QGraphicsDropShadowEffect *dropshadow1 = new QGraphicsDropShadowEffect(this);
    QGraphicsDropShadowEffect *dropshadow2 = new QGraphicsDropShadowEffect(this);
    dropshadow1->setXOffset(0);
    dropshadow1->setYOffset(0);
    dropshadow1->setBlurRadius(10);
    dropshadow1->setColor(QColor::fromRgb(0, 0, 0, 70));
    dropshadow2->setXOffset(0);
    dropshadow2->setYOffset(0);
    dropshadow2->setBlurRadius(10);
    dropshadow2->setColor(QColor::fromRgb(0, 0, 0, 70));
    
    ui->label->setGraphicsEffect(dropshadow1);
    ui->label_selected->setGraphicsEffect(dropshadow2);
}

Roles::~Roles()
{
    delete ui;
}

QString Roles::name() const
{
    return ui->nombre->text();
    
}

void Roles::setSelected(bool selected)
{
    ui->label_selected->setHidden(!selected);
    ui->label->setHidden(selected);
    ui->nombre_selected->setHidden(!selected);
    ui->nombre->setHidden(selected);
}
// void Roles::mousePressEvent(QMouseEvent *event)
// {
//     if (event->type() == QEvent::MouseButtonPress)
//     {
//         emit clicked(ui->nombre->text());
//     }
//     QWidget::mousePressEvent(event);
// }
