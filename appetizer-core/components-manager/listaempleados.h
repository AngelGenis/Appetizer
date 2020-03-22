#ifndef LISTAEMPLEADOS_H
#define LISTAEMPLEADOS_H

#include <QWidget>
#include <QModelIndex>

namespace Ui {
class ListaEmpleados;
}
class TarjetaEmpleado;
class QStringListModel;
class AuthenticationService;
class EmpleadoServicio;
class ListaEmpleados : public QWidget
{
    Q_OBJECT

public:
    explicit ListaEmpleados(QWidget *parent = nullptr);
    ~ListaEmpleados();

private slots:
    void on_cB_tipoEmpleado_activated(const QString &arg1);

    void on_listView_clicked(const QModelIndex &index);

    void on_btn_nuevoEmpleado_clicked();

    void on_buscarEmpleado_textChanged(const QString &arg1);

private:
    Ui::ListaEmpleados *ui;
    QStringListModel *usersModel, *defaultModel;
    AuthenticationService *authSrv;
    EmpleadoServicio *emplServ;
    TarjetaEmpleado *tarEmpl;
    QString usuarioActual, textoBuscar, categoriaActual;
    int idUsuario;
};

#endif // LISTAEMPLEADOS_H
