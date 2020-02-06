#include "orden.h"
#include "ui_orden.h"
#include "platillo.h"
#include "QtWidgets"


Orden::Orden(QWidget *parent) :
    QWidget(parent),

    ui(new Ui::Orden)
{
    ui->setupUi(this);
   /* Platillo *myListItem = new Platillo();
    QListWidgetItem *item = new QListWidgetItem();
   // ui->ordenesListWidget->addItem(Platillo);
    ui->ordenesListWidget->addItem(item);
    //item->setSizeHint (myListItem->sizeHint ());
    ui->ordenesListWidget->setItemWidget(item, myListItem);*/

    Platillo *plati = new Platillo();
    Platillo *plati2 = new Platillo();
    ui->listaPlatillos->addWidget(plati);
    ui->listaPlatillos->addWidget(plati2);



}

Orden::~Orden()
{
    delete ui;
}


void Orden::on_pushButton_clicked()
{
   /* QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->ordenesListWidget);

    //Adding the item to the listwidget
    ui->ordenesListWidget->addItem (listWidgetItem);

    //Creating an object of the designed widget which is to be added to the listwidget
    Platillo *theWidgetItem = new Platillo();

    //Making sure that the listWidgetItem has the same size as the TheWidgetItem
    listWidgetItem->setSizeHint (theWidgetItem->sizeHint ());

    //Finally adding the itemWidget to the list
    ui->ordenesListWidget->setItemWidget (listWidgetItem, theWidgetItem);
    ui->ordenesListWidget->addItem("hola");*/
    Platillo *plati = new Platillo();
    ui->listaPlatillos->addWidget(plati);


}
