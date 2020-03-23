#ifndef TARJETAEMPLEADODELEGATE_H
#define TARJETAEMPLEADODELEGATE_H

#include <QStyledItemDelegate>


class TarjetaEmpleadoDelegate : public QStyledItemDelegate
{
public:
    TarjetaEmpleadoDelegate(QObject* parent = nullptr);
    void paint(QPainter* painter, const QStyleOptionViewItem&
               option, const QModelIndex& index) const override;
    QSize sizeHint(const QStyleOptionViewItem& option,
                   const QModelIndex& index) const override;
};

#endif // TARJETAEMPLEADODELEGATE_H
