#ifndef __ORFRONT_H__
#define __ORFRONT_H__
#include <QGraphicsItemGroup>
#include <QGraphicsTextItem>

class OrFront : public QGraphicsItemGroup
{
    public:
    OrFront(QGraphicsItem *parent = nullptr, int x = 0, int y = 0);

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
