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


    // Manejamos el estado de seleccion del item
    if (option.state.testFlag(QStyle::State_Selected)) { 
        rol.setSelected(true);
    }
    // convertimos el widget a un pixmap
    QPixmap pixmap(rol.size());
    rol.render(&pixmap);
    painter->drawPixmap(x,y, pixmap);
    painter->restore();
}

QSize RolesItemDelegate::sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    Q_UNUSED(index);
    Q_UNUSED(option);
    Roles rol("");
    return rol.size();
}
