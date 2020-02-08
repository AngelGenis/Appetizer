#ifndef CUENTAS_H
#define CUENTAS_H

#include <QWidget>
#include <QPdfWriter>
#include <QPainter>
#include <QDesktopServices>
#include<QUrl>
#include<QFileDialog>
#include<QList>
#include<QStringList>
#include<QTime>
#include<QListWidgetItem>
#include<QDebug>
namespace Ui {
class cuentas;
}

class cuentas : public QWidget
{
    Q_OBJECT

public:
    explicit cuentas(QWidget *parent = nullptr);
    ~cuentas();

private slots:
    void on_pbimprimir_clicked();

    void on_listcuentas_itemChanged(QListWidgetItem *item);

    void on_comboBox_currentIndexChanged(int index);

    void on_pbcancelar_clicked();

private:
    Ui::cuentas *ui;
    void imprimirCuenta();
    QList<QList<QString>*> *ordenes;
    int filas;

};

#endif // CUENTAS_H
