#ifndef GRAPH_CLIENTES_H
#define GRAPH_CLIENTES_H

#include <QWidget>
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
#include <QSqlDatabase>


QT_CHARTS_USE_NAMESPACE

namespace Ui {
class graph_clientes;
}

class graph_clientes : public QWidget
{
    Q_OBJECT

public:
    explicit graph_clientes(QWidget *parent = nullptr);
    ~graph_clientes();


private slots:
    void on_btn_clicked();

private:
    Ui::graph_clientes *ui;
    QSqlDatabase mDatabase;
    QChart *chart;
    QChartView *chartView;
    void updateGraph();
};

#endif // GRAPH_CLIENTES_H
