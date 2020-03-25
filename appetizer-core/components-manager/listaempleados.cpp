#include "listaempleados.h"
#include "ui_listaempleados.h"
#include "services/empleadoservicio.h"
#include "roles.h"
#include "rolesitemdelegate.h"
#include "tarjetaempleado.h"
#include "tarjetaempleadodelegate.h"
#include "crudempleados.h"

#include <QSqlRecord>
#include <QDebug>
#include <QStringListModel>
#include <QMessageBox>

ListaEmpleados::ListaEmpleados(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ListaEmpleados),
    usersModel(new QStringListModel(this)),
    defaultModel (new QStringListModel(this)),
    emplServ(new EmpleadoServicio)
{
    ui->setupUi(this);
    qApp->installEventFilter(this);
    ui->listView->setModel(usersModel);
    ui->listView->setItemDelegate(new RolesItemDelegate);
    ui->cB_tipoEmpleado->activated("Todos");
    crudEmpl = new CrudEmpleados();
}

ListaEmpleados::~ListaEmpleados()
{
    delete ui;
}

void ListaEmpleados::on_cB_tipoEmpleado_activated(const QString &arg1)
{
    categoriaActual = arg1;
    auto empleados = emplServ->getEmpleadosFiltro(arg1, "");
    usersModel->setStringList(empleados);

}

void ListaEmpleados::on_listView_clicked(const QModelIndex &index)
{
    connect(this, &ListaEmpleados::clicked, crudEmpl, &CrudEmpleados::on_empleado_clickeado);
    qDebug() << "Conexion para eliminar: " << connect(crudEmpl, &CrudEmpleados::on_actualizar_empleados, this, &ListaEmpleados::actualizarLista);
    usuarioActual = index.data().toString();
    qDebug()<< "Nombre del usuario seleccionado: " << usuarioActual;
    crudEmpl->obtenerUsuario(usuarioActual);
    emit clicked();
}

void ListaEmpleados::on_btn_nuevoEmpleado_clicked()
{
    connect(this, &ListaEmpleados::clickedDefault, crudEmpl, &CrudEmpleados::on_agregar_empleado);
    emit clickedDefault();

}

void ListaEmpleados::on_buscarEmpleado_textChanged(const QString &arg1)
{
    if(arg1.isEmpty()){
        auto empleados = emplServ->getEmpleadosFiltro(categoriaActual, arg1);
        usersModel->setStringList(empleados);
        ui->listView->setModel(usersModel);
        ui->listView->setItemDelegate(new RolesItemDelegate);
    }else{
        textoBuscar = arg1;
        auto empleadosFiltro = emplServ->getEmpleadosFiltro(categoriaActual, textoBuscar);
        defaultModel->setStringList(empleadosFiltro);
        ui->listView->setModel(defaultModel);
        ui->listView->setItemDelegate(new RolesItemDelegate);
    }
}

void ListaEmpleados::actualizarLista(){
    qDebug () << "categoria actual, para eliminar:" << categoriaActual;
    auto empleados = emplServ->getEmpleadosFiltro(categoriaActual, "");
    usersModel->setStringList(empleados);
    ui->listView->setModel(usersModel);
    ui->listView->setItemDelegate(new RolesItemDelegate);
}
