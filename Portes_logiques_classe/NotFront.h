#ifndef __NOTFRONT__
#define __NOTFRONT__
#include <QGraphicsItemGroup>
#include <QGraphicsTextItem>

class NotFront : public QGraphicsItemGroup
{
    public:
    NotFront(QGraphicsItem *parent = nullptr, int x = 0, int y = 0);

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