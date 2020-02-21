#ifndef MESA_H
#define MESA_H
#include <QGraphicsObject>

class Mesa : public QGraphicsObject
{
    Q_OBJECT
    
public:
    enum State {Disponible=0, Ocupada, Sucia };
    Q_PROPERTY(State _state READ getState WRITE setState NOTIFY stateChanged)
    Q_PROPERTY(int _seats READ getSeats WRITE setSeats)
    Q_PROPERTY(int _numMesa READ getNumMesa)
    Mesa(int numMesa, QGraphicsItem *parent = nullptr);

  // QGraphicsItem interface
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget) override;
    State getState() const;
    int getSeats() const;
    int getNumMesa() const;
    int piso;
    int id_mesero;
public slots:
    void setState(State state);
    void setSeats(int seats);
signals:
    void stateChanged(State s);
    
private:

    int _numMesa;
    int _seats;
    State _state;

};

#endif // MESA_H
