#include "componentenotificaciones.h"
#include "ui_componentenotificaciones.h"
#include "components-mesero/notificacionmesero.h"
#include "services/databaseconnection.h"

#include <QDebug>


ComponenteNotificaciones::ComponenteNotificaciones(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ComponenteNotificaciones),
    db(DatabaseConnection::connect())
{
    ui->setupUi(this);



}

ComponenteNotificaciones::~ComponenteNotificaciones()
{
    delete ui;
}

void ComponenteNotificaciones::MostrarNotificaciones(){
    QSqlQuery query;

    query.exec("SELECT * FROM notificacion"
               "inner join orden"
               "on notificacion.orden_id_orden = orden.id_orden"
               "inner join mesa"
               "on order.id_mesa = mesa.id_mesa");
    int row = 0;
    int col = 0;
    int i= 0;
    while(query.next()){
        QString contenido = query.value(1).toString();
        QString mesa = query.value(5).toString();

        row = i/1;
        col= i%1;

        NotificacionMesero *noti = new NotificacionMesero();
        noti->insertarDatos("Numero de mesa: "+ mesa, contenido, "C:/Users/Angel/Documents/Appetizer/appetizer-core/Img/favicon.png");
        ui->gridLayout->addWidget(noti, row, col);
        i++;
    }

}
