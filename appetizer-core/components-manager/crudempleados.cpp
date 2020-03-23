#include "crudempleados.h"
#include "ui_crudempleados.h"
#include "services/empleadoservicio.h"

#include <QDebug>

int CrudEmpleados::idEmpleado=0;
QString CrudEmpleados::urlFoto = "", CrudEmpleados::nombre = "", CrudEmpleados::sexo="",
CrudEmpleados::telefono="", CrudEmpleados::correo="", CrudEmpleados::password="",
CrudEmpleados::cargo="";
QDate CrudEmpleados::fecha_ingreso, CrudEmpleados::fecha_nacimiento;
double CrudEmpleados::sueldo=0.0;
QLineEdit *CrudEmpleados::lE_nombre, *CrudEmpleados::lE_telefono,
*CrudEmpleados::lE_correo, *CrudEmpleados::lE_password;
QComboBox *CrudEmpleados::cB_sexo, *CrudEmpleados::cB_cargo;
QDateEdit *CrudEmpleados::dE_f_nacimiento, *CrudEmpleados::dE_f_ingreso;
QDoubleSpinBox *CrudEmpleados::dSB_sueldo;
QLabel *CrudEmpleados::lB_foto;

CrudEmpleados::CrudEmpleados(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CrudEmpleados),
    emplServ(new EmpleadoServicio)
{
    ui->setupUi(this);
    lE_nombre           = ui->nombre;
    dSB_sueldo          = ui->sueldo;
    lE_telefono         = ui->telefono;
    lE_correo           = ui->correo;
    lE_password         = ui->password;
    cB_sexo             = ui->sexo;
    cB_cargo            = ui->cargo;
    dE_f_nacimiento     = ui->fechaNacimiento;
    dE_f_ingreso        = ui->fechaIngreso;
    lB_foto             = ui->foto;
}

CrudEmpleados::~CrudEmpleados()
{
    delete ui;
}

void CrudEmpleados::obtenerUsuario(QString nombre){
    this->nombre = nombre;
}

void CrudEmpleados::on_empleado_clickeado(){
    Empleado empleado;
    empleado = emplServ->getDatosEmpleado(nombre);

    idEmpleado          = empleado.idEmpleado;
    urlFoto             = empleado.urlFoto;
    fecha_nacimiento    = empleado.fecha_nacimiento;
    sexo                = empleado.sexo;
    sueldo              = empleado.sueldo;
    fecha_ingreso       = empleado.fecha_ingreso;
    telefono            = empleado.telefono;
    correo              = empleado.correo;
    password            = empleado.password;
    cargo               = empleado.cargo;


    qDebug() << nombre;
    mostrarDatos();
}

void CrudEmpleados::mostrarDatos(){
    lE_nombre->setText(nombre);
    dE_f_nacimiento->setDate(fecha_nacimiento);
    cB_sexo->setCurrentIndex(cB_sexo->findText(sexo));
    dSB_sueldo->setValue(sueldo);
    dE_f_ingreso->setDate(fecha_ingreso);
    lE_telefono->setText(telefono);
    lE_correo->setText(correo);
    lE_password->setText(password);
    cB_cargo->setCurrentIndex(cB_cargo->findText(cargo));
    if(!urlFoto.isEmpty())
    {
        int w=344;
        int h=lB_foto->height();
        QPixmap pix;
        pix.load(urlFoto);
        lB_foto->setPixmap(pix.scaled(w,h));
    }
    else
    {
        int w=344;
        int h=lB_foto->height();
        QPixmap imgPixmap("");
        imgPixmap.load(urlFoto);
        lB_foto->setPixmap(imgPixmap.scaled(w,h));
    }

}
