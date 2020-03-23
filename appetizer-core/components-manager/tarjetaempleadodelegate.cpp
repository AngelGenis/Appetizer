#include "tarjetaempleadodelegate.h"
#include "tarjetaempleado.h"
#include <QPainter>
#include <QPixmap>

TarjetaEmpleadoDelegate::TarjetaEmpleadoDelegate(QObject *parent) :
      QStyledItemDelegate(parent)
{

}

void TarjetaEmpleadoDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
                         const QModelIndex &index) const
{
    painter->save();
    TarjetaEmpleado tarjetaEmpl("NOMBRE COMPLETO");
    // región de dibujo
    int x = option.rect.x();
    int y = option.rect.y();
    int w = option.rect.width();
    tarjetaEmpl.setFixedWidth(w);


    // Manejamos el estado de seleccion del item
    if (option.state.testFlag(QStyle::State_Selected)) {
        tarjetaEmpl.setSelected(true);
    }
    // convertimos el widget a un pixmap
    QPixmap pixmap(tarjetaEmpl.size());
    tarjetaEmpl.render(&pixmap);
    painter->drawPixmap(x,y, pixmap);
    painter->restore();
}

QSize TarjetaEmpleadoDelegate::sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    Q_UNUSED(index);
    Q_UNUSED(option);
    TarjetaEmpleado tarjetaEmpl("");
    return tarjetaEmpl.size();
}

