#include "rolesitemdelegate.h"
#include "roles.h"
#include <QPainter>
#include <QPixmap>

RolesItemDelegate::RolesItemDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{
    
}

void RolesItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
                         const QModelIndex &index) const
{
    painter->save();
    Roles rol(index.data().toString());
    // región de dibujo
    int x = option.rect.x();
    int y = option.rect.y();
    int w = option.rect.width();
    rol.setFixedWidth(w);
    // convertimos el widget a un pixmap
    QPixmap pixmap(rol.size());
    rol.render(&pixmap);
    painter->drawPixmap(x,y, pixmap);

    // Manejamos el estado de seleccion del item
    if (option.state.testFlag(QStyle::State_Selected)) { 
        QColor selectedColor = option.palette.highlight().color();
        selectedColor.setAlpha(100);
        painter->fillRect(option.rect, selectedColor); 
    } 
    painter->restore();
}

QSize RolesItemDelegate::sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    Q_UNUSED(index);
    Q_UNUSED(option);
    Roles rol("");
    return rol.size();
}