#ifndef CRUDEMPLEADOS_H
#define CRUDEMPLEADOS_H

#include "services/empleadoservicio.h"

#include <QWidget>
#include <QDate>
#include <QLineEdit>
#include <QComboBox>
#include <QDateEdit>
#include <QDoubleSpinBox>
#include <QLabel>

namespace Ui {
class CrudEmpleados;
}
class EmpleadoServicio;
class CrudEmpleados : public QWidget
{
    Q_OBJECT

public:
    explicit CrudEmpleados(QWidget *parent = nullptr);
    ~CrudEmpleados();
    void obtenerUsuario(QString nombre);
    void mostrarDatos();

public slots:
    void on_empleado_clickeado();

private:
    Ui::CrudEmpleados *ui;
    static QString nombre, urlFoto, sexo, telefono, correo, password, cargo;
    static int idEmpleado;
    static QDate fecha_nacimiento, fecha_ingreso;
    static double sueldo;
    EmpleadoServicio *emplServ;
    static QLineEdit *lE_nombre, *lE_telefono, *lE_correo, *lE_password;
    static QComboBox *cB_sexo, *cB_cargo;
    static QDateEdit *dE_f_nacimiento, *dE_f_ingreso;
    static QDoubleSpinBox *dSB_sueldo;
    static QLabel *lB_foto;
};

#endif // CRUDEMPLEADOS_H
