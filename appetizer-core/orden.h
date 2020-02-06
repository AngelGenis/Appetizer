#ifndef ORDEN_H
#define ORDEN_H

#include <QWidget>
#include <QListWidget>
#include <QListWidgetItem>
#include "platillo.h"
#include <QVector>
#include <QDebug>


namespace Ui {
class Orden;
}

class Orden : public QWidget
{
    Q_OBJECT

public:
    explicit Orden(QWidget *parent = nullptr);
    ~Orden();
    QVector <Platillo*> itemVec;

private slots:
    void on_pushButton_clicked();

private:
    Ui::Orden *ui;
};

#endif // ORDEN_H
