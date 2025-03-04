#ifndef __ANDFRONT_H__
#define __ANDFRONT_H__
#include <QGraphicsItem>
#include <QGraphicsTextItem>

class AndFront : public QGraphicsItemGroup
{
public:
    AndFront(QGraphicsItem *parent = nullptr, int x = 0, int y = 0);

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *even)  override ;

    void mousePressEvent(QGraphicsSceneMouseEvent *even) override;

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *even) override;

private:
    bool isMoving;
    QPointF lastMousePos;
    QGraphicsTextItem *name_porte;
};

#endif