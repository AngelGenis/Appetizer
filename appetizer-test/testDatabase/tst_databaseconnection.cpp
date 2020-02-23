#include "services/databaseconnection.h"
#include "components-mesero/notificacionmesero.h"
#include <QtTest>
#include <QSqlQuery>


// add necessary includes here

class TestDatabaseConnection : public QObject
{
    Q_OBJECT

public:
    TestDatabaseConnection();
    ~TestDatabaseConnection();

private slots: 

    void conexionExitosa();
    void MostrarNotificaciones();
};

TestDatabaseConnection::TestDatabaseConnection()
{
    QSqlDatabase &mDataBase = DatabaseConnection::connect();

}

TestDatabaseConnection::~TestDatabaseConnection()
{

}


void TestDatabaseConnection::conexionExitosa()
{
    try {
        QSqlDatabase &db = DatabaseConnection::connect();
        QVERIFY(db.isValid() && db.isOpen());
    } catch (DatabaseException &e) {
        qCritical() << e.what();
    }


}

void TestDatabaseConnection::MostrarNotificaciones()
{
    QSqlQuery query;
    bool band = false;
    query.prepare("SELECT * FROM notificacion "
                  "inner join orden "
                  "on notificacion.orden_id_orden = orden.id_orden "
                  "inner join mesa "
                  "on orden.id_mesa = mesa.id_mesa  where id_mesero = 1 LIMIT 10");
    query.exec();
    int row = 0, col = 0, i = 0;
    while(query.next()){
        QString contenido = query.value(1).toString();
        QString mesa = query.value(5).toString();
        QString imagen = "";
        //Cambiar rutas de acuerdo a la ubicacion en su pc

        if(contenido == "Limpiar Mesa"){
            imagen = "C:/Users/Angel/Documents/Appetizer/appetizer-core/Img/mesasucia.png";
        }else if(contenido == "Entregar Platillo"){
            imagen = "C:/Users/Angel/Documents/Appetizer/appetizer-core/Img/favicon.png";
        }

        row = i/1;
        col= i%1;

        NotificacionMesero *noti = new NotificacionMesero();
        noti->insertarDatos("Mesa "+ mesa, contenido, imagen);
        i++;
        band = true;
    }
    QCOMPARE(band, true);
}
QTEST_MAIN(TestDatabaseConnection)

#include "tst_databaseconnection.moc"

