#ifndef RESTAURANTMAP_H
#define RESTAURANTMAP_H

#include <QWidget>
#include "services/mesasservice.h"
namespace Ui {
class RestaurantMap;
}
class QGraphicsScene;
class QGraphicsPixmapItem;
class Mesa;

class RestaurantMap : public QWidget
{
    Q_OBJECT

public:
    explicit RestaurantMap(QWidget *parent = nullptr);
    ~RestaurantMap();

private:
    void initRectSize();
                       
public slots:
    void setBackgroundImage(const QString &image);
    Mesa* addMesaItem(MesaDataSet m);
    void loadMesas();
    void save();
private:
    MesasService mesasService;
    Ui::RestaurantMap *ui;
    QGraphicsScene *gScene;
    QGraphicsPixmapItem *backGroundItem;
    QList<Mesa*> mesas;
    
};

#endif // RESTAURANTMAP_H
