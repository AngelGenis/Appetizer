#include "mesa.h"
#include <QGraphicsRectItem>
#include <QBrush>
#include <QPainter>
#include <QPainterPath>
Mesa::Mesa(int numMesa, QGraphicsItem *parent) :
    QGraphicsObject(parent),
    _numMesa(numMesa),
    _seats(2),
    _state(Disponible)
{
    
}


QRectF Mesa::boundingRect() const
{
    qreal penWidth = 0;
    qreal l = 60;
    return QRectF(-l - penWidth / 2, -l - penWidth / 2, l + penWidth, l + penWidth);
    
}

void Mesa::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->save();
    painter->setRenderHint(QPainter::Antialiasing);
    QColor stateColor;
    
    switch (_state)
    {
    case Disponible: {
        stateColor.setNamedColor("#738FF4");
        break;        
    }
    case Ocupada: {
        stateColor.setNamedColor("#F4C873");
        break;
    }
    case Sucia: {
        stateColor.setNamedColor("#F4C873");
        break;
    }
    }
    
    auto rect = boundingRect();
    
    int l = rect.width();
    QPainterPath path;
    path.addRoundRect(rect, 10,10);
    painter->fillPath(path, stateColor);    
    painter->setPen(Qt::white);
    painter->setFont(QFont("SF Pro Text", 12, QFont::Bold));
    painter->drawText(rect, Qt::AlignCenter, QString::number(_numMesa));
    if(isSelected())
    {
        auto selectedRect  = rect;
        selectedRect += QMargins(5,5,5,5);
        QColor selColor(0,0,0,45);
        path.addRoundRect(selectedRect, 10,10);
        painter->fillPath(path, selColor);
    }
    painter->restore();    
}

Mesa::State Mesa::getState() const
{
    return _state;
}

void Mesa::setState(State state)
{
    _state = state;

    emit stateChanged(_state);
}

void Mesa::setSeats(int seats)
{
    _seats = seats;
}

int Mesa::getSeats() const
{
    return _seats;
}
int Mesa::getNumMesa() const
{
    return _numMesa;
}
