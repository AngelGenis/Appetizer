#ifndef RESTAURANTMAP_H
#define RESTAURANTMAP_H

#include <QWidget>

namespace Ui {
class RestaurantMap;
}
class QGraphicsScene;
class QGraphicsPixmapItem;

class RestaurantMap : public QWidget
{
    Q_OBJECT

public:
    explicit RestaurantMap(QWidget *parent = nullptr);
    ~RestaurantMap();
    void initRectSize();
public slots:
    void setBackgroundImage(const QString &image);
    
private:
    Ui::RestaurantMap *ui;
    QGraphicsScene *gScene;
    QGraphicsPixmapItem *backGroundItem;
};

#endif // RESTAURANTMAP_H
