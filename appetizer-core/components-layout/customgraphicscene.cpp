#include "customgraphicscene.h"
#include <QPainter>
#include <QPixmap>

CustomGraphicScene::CustomGraphicScene(const QString &bgImage, QObject *parent) :
    QGraphicsScene(parent),
    bgImg(bgImage)
{

}

CustomGraphicScene::CustomGraphicScene(const QRectF &sceneRect, const QString &bgImage,
                                       QObject *parent) :
    QGraphicsScene(sceneRect, parent),
    bgImg(bgImage)
{

}

void CustomGraphicScene::setBackgroundImage(const QString &image)
{
    bgImg = image;
    update();
}


void CustomGraphicScene::drawBackground(QPainter *painter, const QRectF &rect)
{
    if(!bgImg.isEmpty()) {
        painter->save();
        QPixmap pixmap(rect.size().toSize());
        pixmap.load(bgImg);
        painter->drawPixmap(rect.toRect(), pixmap);
        painter->restore();

    }
    QGraphicsScene::drawBackground(painter, rect);
}
