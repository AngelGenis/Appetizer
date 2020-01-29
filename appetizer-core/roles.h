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
    explicit Roles(const QString &nombre, QWidget *parent = nullptr);
    ~Roles();
    QString name() const;
    // void mousePressEvent(QMouseEvent *event) override;
// signals:
//     void clicked();
//     void clicked(QString);
private:
    Ui::Roles *ui;
};

#endif // ROLES_H
