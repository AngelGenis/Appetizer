#ifndef ROLES_H
#define ROLES_H

#include <services/empleadoservicio.h>

#include <QWidget>

namespace Ui {
class Roles;
}
class EmpleadoServicio;
class Roles : public QWidget
{
    Q_OBJECT

public:
    explicit Roles(const QString &nombre, QWidget *parent = nullptr);
    ~Roles();
    QString name() const;
    void setSelected(bool slected = true);
    void mostrarFoto();
    // void mousePressEvent(QMouseEvent *event) override;
// signals:
//     void clicked();
//     void clicked(QString);
private:
    Ui::Roles *ui;
    QString urlFoto;
    EmpleadoServicio *emplServ;
};

#endif // ROLES_H
