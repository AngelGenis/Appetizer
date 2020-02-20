#include "restaurantmap.h"
#include "ui_restaurantmap.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QGraphicsObject>
#include <QDebug>
#include <iostream>

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
