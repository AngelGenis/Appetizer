#include "crudempleados.h"
#include "ui_crudempleados.h"
#include "services/empleadoservicio.h"
#include "services/databaseconnection.h"

#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlError>

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
    db(DatabaseConnection::connect()),
    emplServ(new EmpleadoServicio)
{
    if (!db.isValid() || !db.isOpen())
        qDebug() << db.lastError().text();
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

    lE_nombre->setEnabled(false);
    cB_sexo->setEnabled(false);
    cB_cargo->setEnabled(false);
    dE_f_nacimiento->setEnabled(false);
    dE_f_ingreso->setEnabled(false);
}

CrudEmpleados::~CrudEmpleados()
{
    db.rollback();
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

void CrudEmpleados::on_agregar_empleado(){
    lE_nombre->setEnabled(true);
    cB_sexo->setEnabled(true);
    cB_cargo->setEnabled(true);
    dE_f_nacimiento->setEnabled(true);
    dE_f_ingreso->setEnabled(true);

    mostrarDatosDefault();
    emplServ->agregarEmpleadoDefault();
    idEmpleado = emplServ->obtenerIdEmpleado();
    urlFoto = "://Img/user.png";
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
        int w=lB_foto->width();
        int h=lB_foto->height();
        QPixmap pix;
        pix.load(urlFoto);
        lB_foto->setPixmap(pix.scaled(w,h));
    }
    else
    {
        int w=lB_foto->width();
        int h=lB_foto->height();
        QPixmap imgPixmap("");
        imgPixmap.load(urlFoto);
        lB_foto->setPixmap(imgPixmap.scaled(w,h));
    }

}

void CrudEmpleados::mostrarDatosDefault(){
    //QDate date(2020, 3, 30);
    QDate date = QDate::currentDate();
    lE_nombre->setText("NOMBRE COMPLETO");
    dE_f_nacimiento->setDate(date);
    cB_sexo->setCurrentIndex(cB_sexo->findText("Ninguno"));
    dSB_sueldo->setValue(0.0);
    dE_f_ingreso->setDate(date);
    lE_telefono->setText("0000000000");
    lE_correo->setText("correo@ejemplo.correo");
    lE_password->setText("contraseña");
    cB_cargo->setCurrentIndex(cB_cargo->findText("Ninguno"));
    int w=lB_foto->height();
    int h=lB_foto->height();
    QPixmap imgPixmap("");
    imgPixmap.load("://Img/user.png");
    lB_foto->setPixmap(imgPixmap.scaled(w,h));
}

void CrudEmpleados::on_btn_agregarImagen_clicked()
{
    QStringList imagenes = QFileDialog::getOpenFileNames(this, tr("abrir"), QString(), tr("(*.jpg, *.png)"));

    if(imagenes.isEmpty())
        return;

    if(imagenes.size() > 1)
    {
        QMessageBox::warning(this, "Advertencia", "Por favor, elige solamente una imagen.");
        imagenes.clear();
        return;
    }
    urlFoto = imagenes.first();
    int w=lB_foto->width();
    int h=lB_foto->height();
    QPixmap pix;
    pix.load(urlFoto);
    lB_foto->setPixmap(pix.scaled(w,h));

    imagenes.clear();
}

void CrudEmpleados::on_btn_guardarCambios_clicked()
{
    obtenerDatos();
    /***solo para cuando se agrega un nuevo empleado***/
    emplServ->agregarCargo(idEmpleado, cargo);
    if(validarDatos() == true){
        if(emplServ->actualizarEmpleado(idEmpleado, urlFoto, nombre, fecha_nacimiento, sexo, sueldo,
                                        fecha_ingreso, telefono, correo, password)){
            db.commit();
            QMessageBox::information(this, "Hecho",
                                             "Se guardaron los cambios del platillo");
        }else{
            db.rollback();
            QMessageBox::critical(this, "Error",
                                             "No se guardaron los cambios del platillo");
        }
    }
}

void CrudEmpleados::obtenerDatos(){
    nombre              = ui->nombre->text();
    fecha_nacimiento    = ui->fechaNacimiento->date();
    sexo                = ui->sexo->currentText();
    sueldo              = ui->sueldo->value();
    fecha_ingreso       = ui->fechaIngreso->date();
    telefono            = ui->telefono->text();
    correo              = ui->correo->text();
    password            = ui->password->text();
    cargo               = ui->cargo->currentText();
}

bool CrudEmpleados::validarDatos(){
    QDate date = QDate::currentDate();
    if(nombre == "NOMBRE COMPLETO" || fecha_nacimiento == date || sexo == "Ninguno" || sueldo == 0.0 ||
            telefono == "0000000000" || correo == "correo@ejemplo.correo" || password == "contraseña" ||
            cargo == "Ninguno"){
        QMessageBox::warning(this, "Advertencia", "Hay datos incorrectos, no se puede procesar la operación");
        return false;
    }else{
        return true;
    }
}
