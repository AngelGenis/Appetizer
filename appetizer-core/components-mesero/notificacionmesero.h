#ifndef NOTIFICACIONMESERO_H
#define NOTIFICACIONMESERO_H

#include <QWidget>

namespace Ui {
class NotificacionMesero;
}

class NotificacionMesero : public QWidget
{
    Q_OBJECT

public:
    explicit NotificacionMesero(QWidget *parent = nullptr);
    ~NotificacionMesero();
    void insertarDatos(QString numMesa, QString informacion, QString imagen);

private:
    Ui::NotificacionMesero *ui;
};

#endif // NOTIFICACIONMESERO_H
