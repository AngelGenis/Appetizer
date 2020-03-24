#ifndef BARRAS_PLATILLOS_H
#define BARRAS_PLATILLOS_H

#include <QWidget>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QGridLayout>


QT_CHARTS_USE_NAMESPACE

namespace Ui {
class barras_platillos;
}

class barras_platillos : public QWidget
{
    Q_OBJECT

public:
    explicit barras_platillos(QWidget *parent = nullptr);
    ~barras_platillos();

private:
    Ui::barras_platillos *ui;

};

#endif // BARRAS_PLATILLOS_H
