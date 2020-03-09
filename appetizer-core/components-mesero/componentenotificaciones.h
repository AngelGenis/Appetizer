#ifndef COMPONENTENOTIFICACIONES_H
#define COMPONENTENOTIFICACIONES_H

#include <QWidget>
#include <QSqlQuery>

namespace Ui {
class ComponenteNotificaciones;
}
class QSqlDatabase;
class AuthenticationService;


class ComponenteNotificaciones : public QWidget
{
    Q_OBJECT

public:
    explicit ComponenteNotificaciones(QWidget *parent = nullptr);
    ~ComponenteNotificaciones();
    void MostrarNotificaciones();

private:
    Ui::ComponenteNotificaciones *ui;
    QSqlDatabase &db;
    AuthenticationService *authSrv;
};

#endif // COMPONENTENOTIFICACIONES_H
