#ifndef MESA_H
#define MESA_H
#include <QGraphicsObject>
#include "services/mesasservice.h"

class QGestureEvent;
class QTapAndHoldGesture;

class Mesa : public QGraphicsObject
{
    Q_OBJECT
    
public:
    enum State {Disponible=0, Ocupada, Sucia };
    Q_PROPERTY(State _state READ getState WRITE setState NOTIFY stateChanged)
    Q_PROPERTY(int _seats READ getSeats WRITE setSeats)
    Q_PROPERTY(int _numMesa READ getNumMesa)
    Q_PROPERTY(int _numMesaGroup READ getMesaGroup WRITE setMesaGroup)
    Q_PROPERTY(int _group READ getGroup WRITE setGroup)
    Q_PROPERTY(MesaData mesaData READ getMesaData WRITE setMesaData)
    Mesa(int numMesa = 0, QGraphicsItem *parent = nullptr);

    // QGraphicsItem interface
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
    State getState() const;
    int getSeats() const;
    int getNumMesa() const;
    int getMesaGroup() const;
    int getGroup() const;
    MesaData getMesaData() const;
    void setMesaData(const MesaData& mesaData);
    bool save();
    bool load(int id);
    
protected:
    virtual bool event(QEvent* event) override;
public slots:
    void setState(State state);
    void setSeats(int seats);
    void setMesaGroup(int mesaGroup);
    void setGroup(int group);

signals:
    void stateChanged(State s);
    void longTapFinished();
private:
    void initColors();
    MesasService mesasService;
    bool gestureEvent(QGestureEvent *event);
    void longTapTriggered(QTapAndHoldGesture* gesture);
    int _numMesa;
    int _seats;
    State _state;
    int _numMesaGroup;
    int _group;
    MesaData mesaData;
    QStringList colors;

};

#endif // MESA_H
