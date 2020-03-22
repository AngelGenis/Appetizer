#include "listaempleados.h"
#include "ui_listaempleados.h"
#include "services/authenticationservice.h"
#include "services/empleadoservicio.h"
#include "roles.h"
#include "rolesitemdelegate.h"
#include "tarjetaempleado.h"

#include <QSqlRecord>
#include <QDebug>
#include <QStringListModel>
#include <QMessageBox>

ListaEmpleados::ListaEmpleados(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ListaEmpleados),
    usersModel(new QStringListModel(this)),
    defaultModel (new QStringListModel(this)),
    authSrv(new AuthenticationService),
    emplServ(new EmpleadoServicio)
{
    ui->setupUi(this);
    qApp->installEventFilter(this);
    ui->listView->setModel(usersModel);
    ui->listView->setItemDelegate(new RolesItemDelegate);
    ui->cB_tipoEmpleado->activated("Mesero");


}

ListaEmpleados::~ListaEmpleados()
{
    delete ui;
}

void ListaEmpleados::on_cB_tipoEmpleado_activated(const QString &arg1)
{
    categoriaActual = arg1;
    auto empleados = authSrv->getEmpleados(arg1);
    usersModel->setStringList(empleados);
}

void ListaEmpleados::on_listView_clicked(const QModelIndex &index)
{
    qDebug() << index;
    usuarioActual = index.data().toString();
    qDebug()<< "Nombre del usuario actual: " << usuarioActual;
}

void ListaEmpleados::on_btn_nuevoEmpleado_clicked()
{
    /*ui->listView->setIndexWidget(, tarEmpl->wid());
    ui->listView->setModel(defaultModel);
    ui->listView->setItemDelegate(new RolesItemDelegate);*/
}

void ListaEmpleados::on_buscarEmpleado_textChanged(const QString &arg1)
{
    if(arg1.isEmpty()){
        auto empleados = authSrv->getEmpleados(categoriaActual);
        usersModel->setStringList(empleados);
        ui->listView->setModel(usersModel);
        ui->listView->setItemDelegate(new RolesItemDelegate);
    }else{
        textoBuscar = arg1;
        qDebug()<<"Categoria: " << categoriaActual << " texto a buscar: " << textoBuscar;
        auto empleadosFiltro = emplServ->getEmpleadosFiltro(categoriaActual, textoBuscar);
        qDebug() << empleadosFiltro;
        defaultModel->setStringList(empleadosFiltro);
        ui->listView->setModel(defaultModel);
        ui->listView->setItemDelegate(new RolesItemDelegate);
    }
}
