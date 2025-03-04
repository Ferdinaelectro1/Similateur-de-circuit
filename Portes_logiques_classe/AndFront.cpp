#include "AndFront.h"
#include <QGraphicsItem>
#include <QGraphicsItemGroup>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsLineItem>
#include <QGraphicsEllipseItem>
#include <QApplication>
#include <QBrush>

AndFront::AndFront(QGraphicsItem *parent , int x, int y):QGraphicsItemGroup(parent), isMoving(false)
{
        setFlag(QGraphicsItem::ItemIsMovable, true);
        setFlag(QGraphicsItem::ItemIsSelectable, true);

        //initialisation attributs
        name_porte = new QGraphicsTextItem("AND",this);
        addToGroup(name_porte);

        QGraphicsRectItem *rectangle = new QGraphicsRectItem(85 + x, 10 + y, 30, 30);
        rectangle->setBrush(QBrush(Qt::black));
        addToGroup(rectangle);

        QGraphicsEllipseItem *cercle = new QGraphicsEllipseItem(100 + x, 10 + y, 30, 30);
        cercle->setBrush(QBrush(Qt::black));
        addToGroup(cercle);

        QGraphicsLineItem *ligne1 = new QGraphicsLineItem(50 + x, 15 + y, 100 + x, 15 + y);
        addToGroup(ligne1);

        QGraphicsLineItem *ligne2 = new QGraphicsLineItem(50 + x, 35 + y, 100 + x, 35 + y);
        addToGroup(ligne2);

        QGraphicsLineItem *ligne3 = new QGraphicsLineItem(100 + x, 25 + y, 150 + x, 25 + y);
        addToGroup(ligne3);
}

void AndFront::mouseMoveEvent(QGraphicsSceneMouseEvent *even)
{
    if (isMoving)
    {
        QPointF delta = even->scenePos() - lastMousePos;
        moveBy(delta.x(), delta.y());
        lastMousePos = even->scenePos();
    }
}

void AndFront::mousePressEvent(QGraphicsSceneMouseEvent *even) 
{
        if (even->button() == Qt::LeftButton)
    {
        isMoving = true;
        lastMousePos = even->scenePos();
        setCursor(Qt::ClosedHandCursor);
    }
}

void AndFront::mouseReleaseEvent(QGraphicsSceneMouseEvent *even) 
{
        if (even->button() == Qt::LeftButton)
    {
        isMoving = false;
        setCursor(Qt::ArrowCursor);
    }
}