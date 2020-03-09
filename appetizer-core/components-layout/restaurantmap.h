#ifndef RESTAURANTMAP_H
#define RESTAURANTMAP_H

#include <QWidget>
#include <QSet>
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
    enum Mode {EditMode, ViewMode};
    explicit RestaurantMap(QWidget *parent = nullptr);
  ~RestaurantMap();
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    void initRectSize();
    int askSeats(int currentSeats);
public slots:
    void setMode(Mode mode);
    void setBackgroundImage(const QString &image);
    Mesa* addMesaItem(MesaDataSet m);
    void loadMesas();
    void save();
    void on_mainToolBar_clickedEditarFondo();
    void on_mainToolBar_clickedAgregarMesa();
    void on_mainToolBar_clickedEliminarMesa();
    void on_mainToolBar_clickedEditarAsiento();

signals:
    void mesaSelected(int mesa);
    
private:
    MesasService mesasService;
    Ui::RestaurantMap *ui;
    QGraphicsScene *gScene;
    QGraphicsPixmapItem *backGroundItem;
    QSet<Mesa*> mesas;
    Mode mode;
};

#endif // RESTAURANTMAP_H
