#include "restaurantmap.h"
#include "ui_restaurantmap.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>

#include "mesa.h"

RestaurantMap::RestaurantMap(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RestaurantMap),
    backGroundItem(nullptr)
{
    ui->setupUi(this);
    gScene = new QGraphicsScene(ui->graphicsView->rect(), this);
    ui->graphicsView->setScene(gScene);    
}

RestaurantMap::~RestaurantMap()
{
    delete gScene;
    delete ui;
}

void RestaurantMap::setBackgroundImage(const QString &image)
{
    if(backGroundItem)
        gScene->removeItem(backGroundItem);
    
    QPixmap pixmap;
    pixmap.load(image);
    pixmap = pixmap.scaled(ui->graphicsView->viewport()->size(),
                           Qt::KeepAspectRatio, Qt::FastTransformation);
    backGroundItem = gScene->addPixmap(pixmap);
    backGroundItem->setPos(0,0);
    
}

void RestaurantMap::initRectSize()
{
    int _w = ui->graphicsView->viewport()->width();
    int _h = ui->graphicsView->viewport()->height();     
    ui->graphicsView->setSceneRect(0,0,_w,_h);
}
void RestaurantMap::addMesaItem(int numMesa)
{
    auto mesa = new Mesa(numMesa);
    int w = ui->graphicsView->viewport()->width();
    int h = ui->graphicsView->viewport()->height();
    mesa->setFlags(QGraphicsItem::ItemIsMovable);
    gScene->addItem(mesa);
    mesa->setPos(w/2.0, h/2.0);
}
