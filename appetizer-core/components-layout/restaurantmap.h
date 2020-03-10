#ifndef RESTAURANTMAP_H
#define RESTAURANTMAP_H

#include <QWidget>
#include <QSet>
#include <QMultiMap>
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
    enum Mode {ManagerMode, MeseroMode, HostMode};
    explicit RestaurantMap(QWidget *parent = nullptr);
  ~RestaurantMap();
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    void initRectSize();

    int askSeats(int currentSeats);
private slots:
    void emitMesaSelected();
    void groupMesas();
    void on_groupBtn_clicked();
public slots:
    void setMode(Mode mode);
    void setBackgroundImage(const QString &image);
    Mesa* addMesaItem(MesaData m);
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
    QMultiMap<int, Mesa*> gruposMesas;
    Mode mode;
    bool groupModeActivated;
    Mesa *lastSelectedMesa;

};

#endif // RESTAURANTMAP_H
