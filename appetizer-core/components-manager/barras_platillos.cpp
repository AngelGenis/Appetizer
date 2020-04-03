#include "barras_platillos.h"
#include "services/databaseconnection.h"
#include "ui_barras_platillos.h"
#include <QHorizontalBarSeries>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>

#include <QDebug>

barras_platillos::barras_platillos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::barras_platillos),
    db(DatabaseConnection::connect()){
    if (!db.isValid() || !db.isOpen())
        qDebug() << db.lastError().text();
    ui->setupUi(this);

    qDebug()<<"Aqui empiexxa";
    QBarSet *set0 = new QBarSet(nullptr);


    obtenerPorcentajes(set0);

    qDebug()<< categories.size()<< "Este es el tamasdo";

    for(int i=0; i<categories.size(); i++){
        qDebug()<<"valor: " << categories.value(i);
    }

    QHorizontalBarSeries *series = new QHorizontalBarSeries();
    series->append(set0);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Popularidad de Platillos");


    chart->setAnimationOptions(QChart::AllAnimations);

    QBarCategoryAxis *axisY = new QBarCategoryAxis();
    axisY->append(categories);
    chart->createDefaultAxes();
    chart->setAxisY(axisY, series);

    QValueAxis *axisX = new QValueAxis();
    chart->setAxisX(axisX, series);
    axisX->applyNiceNumbers();

    chart->legend()->setVisible(false);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QPalette pal = qApp->palette();
    pal.setColor(QPalette::Window, QRgb(0xffffff));
    pal.setColor(QPalette::WindowText, QRgb(0x404040));
    qApp->setPalette(pal);

    ui->gridLayout->addWidget(chartView,0,0);



}

barras_platillos::~barras_platillos()
{
    delete ui;
}

void barras_platillos::obtenerPorcentajes(QBarSet *n){
    QSqlQuery ids_platillos;
    QSqlQuery obtener_suma;
    QSqlQuery total;

    ids_platillos.prepare("SELECT DISTINCT id_platillo FROM platilloorden");
    ids_platillos.exec();

    total.prepare("SELECT SUM(cantidad) FROM platilloorden");
    total.exec();

     QString cantidad_total;

     while (total.next()){
         cantidad_total = total.value(0).toString();
         qDebug()<<cantidad_total;
     }


    int i=0;

    while (ids_platillos.next()) {
        QString id = ids_platillos.value(0).toString();

        obtener_suma.prepare("SELECT p.nombre, SUM(po.cantidad) FROM platillo AS p "
                             "INNER JOIN platilloorden AS po "
                             "ON p.id_platillo = po.id_platillo "
                             " WHERE p.id_platillo =" + id);

        obtener_suma.exec();
        qDebug()<<obtener_suma.lastQuery();
        i++;
       while (obtener_suma.next()) {
            QString plat = obtener_suma.value(0).toString();
            QString sum = obtener_suma.value(1).toString();

            double porcentaje = (sum.toInt() * 100)/cantidad_total.toInt();

            qreal valorGrafica = porcentaje;

            n->append(valorGrafica);
            categories.append(plat);
            categories.push_back(plat);

        }
    }
}


