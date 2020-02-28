#ifndef CUSTOMGRAPHICSCENE_H
#define CUSTOMGRAPHICSCENE_H

#include <QGraphicsScene>



class CustomGraphicScene : public QGraphicsScene
{
    Q_OBJECT

public:
    CustomGraphicScene(const QString &bgImage = "",
                       QObject *parent = nullptr);

    CustomGraphicScene(const QRectF &sceneRect,
                       const QString &bgImage = "",
                       QObject *parent = nullptr);
public slots:
    void setBackgroundImage(const QString &image);
    // QGraphicsScene interface
protected:
    void drawBackground(QPainter *painter, const QRectF &rect) override;
private:
    QString bgImg;
};

#endif // CUSTOMGRAPHICSCENE_H
