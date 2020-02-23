#include "restaurantmap.h"
#include "ui_restaurantmap.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "mesa.h"
#include "../services/mesasservice.h"
#include <QDebug>
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>

RestaurantMap::RestaurantMap(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RestaurantMap),
    backGroundItem(nullptr)
{
    ui->setupUi(this);
    gScene = new QGraphicsScene(ui->graphicsView->rect(), this);
    ui->graphicsView->setScene(gScene);
    gScene->setSceneRect(QRectF());
    connect(gScene, &QGraphicsScene::selectionChanged, [=](){
                                                           bool selected = gScene->selectedItems().size() >  0;
                                                           ui->mainToolBar->setSelectedMode(selected);
                                                       });
}
RestaurantMap::~RestaurantMap()
{
    save();
    delete gScene;
    delete ui;
}

void RestaurantMap::setBackgroundImage(const QString &image)
{
    if(gScene->sceneRect().isNull())
        initRectSize();
    
    if(backGroundItem)
        gScene->removeItem(backGroundItem);
    
    QPixmap pixmap;
    pixmap.load(image);
    pixmap = pixmap.scaled(ui->graphicsView->viewport()->size(),
                           Qt::IgnoreAspectRatio, Qt::FastTransformation);
    backGroundItem = gScene->addPixmap(pixmap);
    backGroundItem->setPos(0,0);
    
}

// Este método hace que el sistema de coordenadas
// de la escena y el viewport coincidan.
void RestaurantMap::initRectSize()
{
    int _w = ui->graphicsView->viewport()->width();
    int _h = ui->graphicsView->viewport()->height();     
    ui->graphicsView->setSceneRect(0,0,_w,_h);
}

Mesa *RestaurantMap::addMesaItem(MesaDataSet m)
{

    int w = ui->graphicsView->viewport()->width();
    int h = ui->graphicsView->viewport()->height();
    auto mesa = new Mesa(m.id_mesa);
    mesa->setSeats(m.numero_personas);
    mesa->id_mesero = m.id_mesero;
    mesa->piso = m.piso;
    mesa->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    gScene->addItem(mesa);
    mesa->setPos(w/2.0, h/2.0);
    mesas.insert(mesa);
    return mesa;
}

void RestaurantMap::loadMesas()
{

    auto mesasDataList = mesasService.getMesas();
    for(auto &m : mesasDataList)
    {
        auto mesa = addMesaItem(m);
        mesa->setPos(m.x, m.y);
    }
}

void RestaurantMap::save()
{

    MesaDataSet mesaDataset;
    for (auto &m : mesas)
    {      
        mesasService.savePosition(m->getNumMesa(), m->pos().rx(), m->pos().ry());
    }
}

int RestaurantMap::askSeats()
{

    int res = -1;
    res = QInputDialog::getInt(this, "", "¿Cantidad de asientos?",
                               2, 2, 100, 1,
                               nullptr,
                               Qt::Window | Qt::FramelessWindowHint | Qt::Popup | Qt::NoDropShadowWindowHint);
    return res;
    
}
void RestaurantMap::on_mainToolBar_clickedAgregarMesa()
{
    
    int numSeats = askSeats();
    if(numSeats < 0)
        return;
    auto mesa =  mesasService.createMesa(numSeats, 0, 0);
    addMesaItem(mesa);
    
}

void RestaurantMap::on_mainToolBar_clickedEditarFondo()
{
    QString filename = QFileDialog::getOpenFileName(this);
    if(filename.isNull())
        return;
    setBackgroundImage(filename);
    
    
}
void RestaurantMap::on_mainToolBar_clickedEliminarMesa()
{

    auto item = gScene->selectedItems().at(0);
    auto mesa = qgraphicsitem_cast<Mesa*>(item);
    int res = QMessageBox::question(this, "",
                                    "Seguro que deseas eliminar la mesa "
                                    + QString::number(mesa->getNumMesa()));
    
    if(res == QMessageBox::No)
        return;
    
    mesasService.deleteMesa(mesa->getNumMesa());
    gScene->removeItem(item);
    mesas.remove(mesa); 
}

void RestaurantMap::on_mainToolBar_clickedEditarAsiento()
{
    int numSeats = askSeats();
    if(numSeats < 0)
        return;
    auto item = gScene->selectedItems().at(0);
    auto mesa = qgraphicsitem_cast<Mesa*>(item);
    mesa->setSeats(numSeats);
    mesasService.saveNumPersonas(mesa->getNumMesa(), numSeats);

    
}
