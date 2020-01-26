#ifndef ROLESITEMDELEGATE_H
#define ROLESITEMDELEGATE_H

#include <QStyledItemDelegate>

/*!
 * \class RolesItemDelegate
 * \brief Muestra los datos de un modelo como un widget Roles.
 * 
 * Este delegate está pensado para mostrar los nombres de los
 * usuarios con el widget Roles en cualquier QAbstractListModel.
 * 
*/
class RolesItemDelegate : public QStyledItemDelegate
{
public:
    RolesItemDelegate(QObject* parent = nullptr);
    void paint(QPainter* painter, const QStyleOptionViewItem& 
               option, const QModelIndex& index) const override;
    QSize sizeHint(const QStyleOptionViewItem& option, 
                   const QModelIndex& index) const override;
};


#endif /* ROLESITEMDELEGATE_H */
