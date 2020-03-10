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
#include <QSettings>

RestaurantMap::RestaurantMap(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RestaurantMap),
    backGroundItem(nullptr),
    mode(ViewMode)
{
    ui->setupUi(this);
    gScene = new QGraphicsScene(ui->graphicsView->rect(), this);
    ui->graphicsView->setScene(gScene);
    gScene->setSceneRect(QRectF());
    connect(gScene,
            &QGraphicsScene::selectionChanged,
            [=](){
                bool selected = gScene->selectedItems().size() >  0;
                auto mesa = qgraphicsitem_cast<Mesa*>(gScene->selectedItems().at(0));
                selected = selected && (mode == EditMode);
                ui->mainToolBar->setSelectedMode(selected);
                emit mesaSelected(mesa->getNumMesa());
            });
}
RestaurantMap::~RestaurantMap()
{
    save();
    delete gScene;
    delete ui;
}
void RestaurantMap::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    if(gScene->sceneRect().isNull())
    {
        initRectSize();
        QSettings settings;
        QPixmap pixmap = settings.value("restaurantmap").value<QPixmap>();
        if(!pixmap.isNull())
        {
            pixmap = pixmap.scaled(ui->graphicsView->viewport()->size(),
                                   Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
            backGroundItem = gScene->addPixmap(pixmap);
            backGroundItem->setPos(0,0);
        }
        loadMesas();
        
    }
        
}
void RestaurantMap::setBackgroundImage(const QString &image)
{
    if(backGroundItem)
        gScene->removeItem(backGroundItem);
    
    QPixmap pixmap;
    pixmap.load(image);
    pixmap = pixmap.scaled(ui->graphicsView->viewport()->size(),
                           Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
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
    gScene->addItem(mesa);
    mesa->setPos(w/2.0, h/2.0);
    mesas.insert(mesa);
    setMode(mode);
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
    QSettings settings;
    settings.setValue("restaurantmap", backGroundItem->pixmap());
}

int RestaurantMap::askSeats(int currentSeats)
{

    int min = currentSeats < 0 ? 2 : currentSeats;
    currentSeats = QInputDialog::getInt(this, "", "¿Cantidad de asientos?",
                                        min, 2, 100, 1,
                                        nullptr,
                                        Qt::Window | Qt::FramelessWindowHint | Qt::Popup | Qt::NoDropShadowWindowHint);
    return currentSeats;
    
}
void RestaurantMap::on_mainToolBar_clickedAgregarMesa()
{
    
    int numSeats = askSeats(-1);
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
   
    auto item = gScene->selectedItems().at(0);
    auto mesa = qgraphicsitem_cast<Mesa*>(item);
    int numSeats = askSeats(mesa->getSeats());
    if(numSeats == mesa->getSeats())
        return;
    mesa->setSeats(numSeats);
    mesasService.saveNumPersonas(mesa->getNumMesa(), numSeats);

    
}

void RestaurantMap::setMode(Mode mode)
{
    this->mode = mode;
    QGraphicsItem::GraphicsItemFlags flags;
    if(mode == EditMode)
    {
        ui->mainToolBar->setHidden(false);
        flags = QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable;
    }
    else
    {
        ui->mainToolBar->setHidden(true);
        
        flags = QGraphicsItem::ItemIsSelectable;
    }

    for(auto &m :  mesas)
    {
        m->setFlags(flags);
    }
}
