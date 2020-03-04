#include "mesa.h"
#include <QBrush>
#include <QPainter>
#include <QPainterPath>
#include <QTapAndHoldGesture>
#include <QDebug>
#include <QMenu>
#include <QAction>

Mesa::Mesa(int numMesa, QGraphicsItem *parent) :
    QGraphicsObject(parent),
    _numMesa(numMesa),
    _seats(2),
    _state(Disponible),
    _numMesaGroup(_numMesa),
    _group(0)
{
    grabGesture(Qt::TapAndHoldGesture);
    if(numMesa)
        mesaData =  mesasService.getMesa(numMesa);
    initColors();
}


QRectF Mesa::boundingRect() const
{
    qreal penWidth = 0;
    qreal l = 60;
    return QRectF(-l - penWidth / 2, -l - penWidth / 2, l + penWidth, l + penWidth);
    
}
bool Mesa::event(QEvent *event)
{
    if(event->type() == QEvent::Gesture)
        return gestureEvent(static_cast<QGestureEvent*>(event));
    return QGraphicsObject::event(event);
}

bool Mesa::gestureEvent(QGestureEvent *event)
{
    if(QGesture *longTap = event->gesture(Qt::TapAndHoldGesture))
        longTapTriggered(static_cast<QTapAndHoldGesture*>(longTap));
    return true;
}

void Mesa::longTapTriggered(QTapAndHoldGesture* gesture)
{
    if(gesture->state() == Qt::GestureFinished)
    {
        QMenu menu;       
        QAction *disponible = menu.addAction("Disponible");
        QAction *ocupada    = menu.addAction("Ocupada");
        QAction *sucia      = menu.addAction("Sucia");
        QPoint point        = gesture->position().toPoint();
        
        QAction *selectedAction = menu.exec(point);
        
        if(selectedAction == disponible)
            setState(Disponible);
        else if(selectedAction == ocupada)
            setState(Ocupada);
        else if(selectedAction == sucia)
            setState(Sucia);        
    }
}


void Mesa::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->save();
    painter->setRenderHint(QPainter::Antialiasing);
    QColor stateColor;
    
    switch (_state)
    {
    case Disponible: {
        stateColor.setNamedColor("#74C11B");
        break;        
    }
    case Ocupada: {
        stateColor.setNamedColor("#20D6EA");
        break;
    }
    case Sucia: {
        stateColor.setNamedColor("#FF4921");
        break;
    }
    }
    
    auto rect = boundingRect();
    
    QPainterPath path;
    path.addRoundRect(rect, 10,10);
    painter->fillPath(path, stateColor);    
    painter->setPen(Qt::white);
    painter->setFont(QFont("SF Pro Text", 12, QFont::Bold));
    painter->drawText(rect, Qt::AlignCenter, QString::number(getNumMesa()));
    if(mesaData.grupo > 0)        
    {
        painter->setPen(QColor(colors.at(mesaData.grupo - 1)));
        painter->drawRoundedRect(rect + QMarginsF(10,10,10,10), 5, 5);
    }
    
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
    update();
    emit stateChanged(_state);
}

void Mesa::setSeats(int seats)
{
    mesaData.numero_personas = seats;
}

int Mesa::getSeats() const
{
    return mesaData.numero_personas;
}

int Mesa::getNumMesa() const
{
    if(_numMesa == _numMesaGroup)
        return mesaData.id_mesa;
    else
        return mesaData.id_mesa_maestra;
}

int Mesa::getMesaGroup() const
{
    return mesaData.id_mesa_maestra;
}


void Mesa::setMesaGroup(int mesaGroup)
{
    mesaData.id_mesa_maestra = mesaGroup;
}

int Mesa::getGroup() const
{
    return mesaData.grupo;
}

void Mesa::setGroup(int group)
{
    mesaData.grupo = group;
}


bool Mesa::load(int id)
{
    mesaData = mesasService.getMesa(id);
}

bool Mesa::save()
{
    return mesasService.saveMesa(mesaData);
}

MesaData Mesa::getMesaData() const
{
    return mesaData;
}

void Mesa::setMesaData(const MesaData &mesaData)
{
    this->mesaData = mesaData;
}


void Mesa::initColors()
{
    colors << "#808080";
    colors << "#000000";
    colors << "#FF0000";
    colors << "#800000";
    colors << "#9370DB";
    colors << "#808000";
    colors << "#00FF00";
    colors << "#008000";
    colors << "#00FFFF";
    colors << "#008080";
    colors << "#0000FF";
    colors << "#000080";
    colors << "#FF00FF";
    colors << "#800080";
    
}
