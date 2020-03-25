#include "graph_clientes.h"
#include "ui_graph_clientes.h"

#include <QSqlQuery>
#include <QDebug>

graph_clientes::graph_clientes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::graph_clientes)
{
    ui->setupUi(this);
    updateGraph();
}

graph_clientes::~graph_clientes()
{
    delete ui;
}

void graph_clientes::updateGraph(){
    QDate fechaInicio= ui->fechaInicio->date();
    QDate fechaFin = ui->fechaFin->date();

    QSqlQuery query(mDatabase);
    query.prepare("SELECT hour(ord.hora_fecha) AS hora, "
                    "AVG(mesa.numero_personas) AS avgPersonas "
              "FROM orden AS ord "
              "INNER JOIN mesa "
              "ON ord.id_mesa = mesa.id_mesa "
              "WHERE date(ord.hora_fecha)  between :fechaInicio and :fechaFin "
              "GROUP BY hour(ord.hora_fecha) "
              );

    query.bindValue(":fechaInicio", fechaInicio);
    query.bindValue(":fechaFin", fechaFin);

    query.exec();

    QLineSeries *series = new QLineSeries();
    while(query.next()){
        int hora = query.value("hora").toInt();
        int avgPersonas = query.value("avgPersonas").toInt();

        series->append(hora, avgPersonas);
    }


    chart = new QChart();
    chart->legend()->hide();
    chart->createDefaultAxes();
    chart->setTitle("Densidad de clientes por hora");
    chart->addSeries(series);

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    ui->layout->addWidget(chartView);

}

void graph_clientes::on_btn_clicked(){
    updateGraph();
}
