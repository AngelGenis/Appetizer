#include "realizar_cobro.h"
#include "ui_realizar_cobro.h"

#include <QDebug>
#include <QMessageBox>

realizar_cobro::realizar_cobro(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::realizar_cobro)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(1);

}

realizar_cobro::~realizar_cobro()
{
    delete ui;
}

void realizar_cobro::on_btn_cobrar_clicked(){
    QSqlQuery llenarWidget;
    double PrecioTotal= 0;

    llenarWidget.prepare("SELECT po.cantidad, p.nombre, precio FROM platilloorden AS po "
                         "INNER JOIN platillo as p "
                         "ON po.id_platillo = p.id_platillo "
                         "WHERE po.id_orden = 1;");
    llenarWidget.exec();
    double total;

    while(llenarWidget.next()){
        QString cantidad = llenarWidget.value(0).toString();
        QString nombre = llenarWidget.value(1).toString();
        QString precio = llenarWidget.value(2).toString();

        total = cantidad.toDouble() * precio.toDouble();
        PrecioTotal += total;

    }

    double iva = (PrecioTotal * 12) / 100;

    total = iva + PrecioTotal;

   double devolver = 0;

   QString cantidadRecibida = ui->cantidadRecibida->text();
   QString propina = ui->propina->text();

   devolver = cantidadRecibida.toDouble()- total-propina.toDouble();

   ui->devolver->setText("$"+ QString::number(devolver));

   QMessageBox msgBox;
   msgBox.setWindowTitle("Cuenta");
   msgBox.setText("¿Desea cerrar la cuenta?");
   msgBox.setStandardButtons(QMessageBox::Yes);
   msgBox.addButton(QMessageBox::No);
   msgBox.setDefaultButton(QMessageBox::Yes);

   if(msgBox.exec() == QMessageBox::Yes){
        QSqlQuery cerrarCuenta;
        cerrarCuenta.prepare("Update cuenta Set precio_total = "+QString::number(total)+", propina = "+propina+
                             ", estado_cuenta ='cerrada', cantidad_pago= "+ cantidadRecibida +" where id_cuenta = 1");
        cerrarCuenta.exec();

        QMessageBox msgBox;
        msgBox.setWindowTitle("Cuenta");
        msgBox.setText("Gracias!");

        ui->stackedWidget->setCurrentIndex(0);
    }


}
