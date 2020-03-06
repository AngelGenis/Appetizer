#include "componentenotificaciones.h"
#include "ui_componentenotificaciones.h"
#include "components-mesero/notificacionmesero.h"
#include "services/databaseconnection.h"
#include "services/authenticationservice.h"

#include <QDebug>


ComponenteNotificaciones::ComponenteNotificaciones(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ComponenteNotificaciones),
    db(DatabaseConnection::connect()),
    authSrv(new AuthenticationService)
{
    ui->setupUi(this);

    MostrarNotificaciones();
}

ComponenteNotificaciones::~ComponenteNotificaciones()
{
    delete ui;
}

void ComponenteNotificaciones::MostrarNotificaciones(){
    QSqlQuery query;

    QString usuarioActual = authSrv->getUsuarioActual();

    //Falta obtener el mesero al que le corresponde la notificacion

    query.prepare("SELECT * FROM notificacion "
                  "inner join orden "
                  "on notificacion.orden_id_orden = orden.id_orden "
                  "inner join mesa "
                  "on orden.id_mesa = mesa.id_mesa LIMIT 10");

    query.exec();

    int row = 0;
    int col = 0;
    int i= 0;
    qDebug()<<query.exec();
    while(query.next()){
        QString contenido = query.value(1).toString();
        QString mesa = query.value(5).toString();
        QString imagen = "";

        if(contenido == "Limpiar Mesa"){
            imagen = "://Img/mesasucia.png";
        }else if(contenido == "Entregar Platillo"){
            imagen = "://Img/favicon.png";
        }

        row = i/1;
        col= i%1;

        NotificacionMesero *noti = new NotificacionMesero();

        noti->insertarDatos("Mesa "+ mesa, contenido, imagen);
        ui->gridLayout->addWidget(noti, row, col);
        i++;
    }

}
