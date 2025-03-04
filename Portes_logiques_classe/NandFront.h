#ifndef __NANDFRONT_H__
#define __NANDFRONT_H__

#include <QGraphicsItemGroup>
#include <QWidget>
#include <QGraphicsPixmapItem>

class NandFront : public QGraphicsItemGroup
{
    public:
    NandFront(QGraphicsItem *parent = nullptr, int x = 0, int y = 0);

    protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *even)  override ;

    void mousePressEvent(QGraphicsSceneMouseEvent *even) override;

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *even) override;

    private:
    bool isMoving;
    QPointF lastMousePos;
    QPixmap nand_svg;
    QGraphicsPixmapItem *nand_item;
    QPointF origine_point;
};

#endif