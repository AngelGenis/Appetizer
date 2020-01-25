#ifndef ROLES_H
#define ROLES_H

#include <QWidget>

namespace Ui {
class Roles;
}

class Roles : public QWidget
{
    Q_OBJECT

public:
    explicit Roles(QWidget *parent = nullptr);
    ~Roles();

private:
    Ui::Roles *ui;
};

#endif // ROLES_H
