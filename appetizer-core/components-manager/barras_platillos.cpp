#include "barras_platillos.h"
#include "ui_barras_platillos.h"



barras_platillos::barras_platillos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::barras_platillos)
{
    ui->setupUi(this);

    QBarSet *set0 = new QBarSet("Altuve");
    QBarSet *set1 = new QBarSet("Martinez");
    QBarSet *set2 = new QBarSet("Segura");
    QBarSet *set3 = new QBarSet("Genis");
    QBarSet *set4 = new QBarSet("Prada");

    *set0 << 283 << 341 << 313 << 338 << 346 << 310;
    *set1 << 250 << 315 << 344 << 285 << 346 << 350;
    *set2 << 240 << 58 << 358 << 40 << 386 << 335;
    *set3 << 290 << 587 << 333 << 338 << 346 << 300;
    *set4 << 222 << 444 << 334 << 333 << 333 << 299;

    QBarSeries *series = new QBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);
    series->append(set4);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Platillos");


    chart->setAnimationOptions(QChart::AllAnimations);
    QStringList categories;
    categories << "2013" << "2014" << "2015" << "2016" << "2017";

    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis, series);
    chart->legend()->setVisible(true);
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
