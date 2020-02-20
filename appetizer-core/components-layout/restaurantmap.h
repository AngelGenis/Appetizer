#ifndef RESTAURANTMAP_H
#define RESTAURANTMAP_H

#include <QWidget>

namespace Ui {
class RestaurantMap;
}
class QGraphicsScene;
class QGraphicsPixmapItem;
class QGraphicsItem;

class RestaurantMap : public QWidget
{
    Q_OBJECT

public:
    explicit RestaurantMap(QWidget *parent = nullptr);
    ~RestaurantMap();
    void initRectSize();
                       
public slots:
    void setBackgroundImage(const QString &image);
    void addMesaItem(int numMesa);
    
private:
    Ui::RestaurantMap *ui;
    QGraphicsScene *gScene;
    QGraphicsPixmapItem *backGroundItem;
    QVector<QGraphicsItem*> mesas;
    
};

#endif // RESTAURANTMAP_H
