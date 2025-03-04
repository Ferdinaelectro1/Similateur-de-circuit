#include "try_connexion.h"

Circuitscene::Circuitscene(QObject *parent) : QGraphicsScene(parent),tempLine(nullptr), isDrawing(false){}

void Circuitscene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {

        currentPoint = event->scenePos();
        isDrawing = true;
        lastDirection = Horizontal;
    }
    else if(event->button() == Qt::RightButton && isDrawing)
    {
        isDrawing = false;
        delete tempLine;
        tempLine = nullptr;
    }
}

void Circuitscene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(isDrawing)
    {
        QPointF snappedPoint = snapToAxis(event->scenePos());
        if(directionChanged(snappedPoint))
        {
            addLine(QLineF(currentPoint,snappedPoint));
            currentPoint = snappedPoint;
            updateDirection(snappedPoint);
        }
        if(!tempLine)
        {
            tempLine = addLine(QLineF(currentPoint,snappedPoint),QPen(Qt::DashLine));
        }
        else
        {
            tempLine->setLine(QLineF(currentPoint,snappedPoint));
        }
    }
    QGraphicsScene::mouseMoveEvent(event);
}

void Circuitscene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
}

QPointF Circuitscene::snapToAxis(const QPointF &point)
{
    qreal dx = std::abs(point.x() - currentPoint.x());
    qreal dy = std::abs(point.y() - currentPoint.y());
    if(dx > dy)
    {
        return QPointF(point.x(),currentPoint.y());
    }
    else
    {
        return QPointF(currentPoint.x(),point.y());
    }
}

bool Circuitscene::directionChanged(const QPointF &point)
{
    qreal dx = std::abs(point.x() - currentPoint.x());
    qreal dy = std::abs(point.y() - currentPoint.y());
    return (dx>dy && lastDirection == Vertical) || (dy > dx && lastDirection == Horizontal);
}

void Circuitscene::updateDirection(const QPointF &point)
{
    qreal dx = std::abs(point.x() - currentPoint.x());
    qreal dy = std::abs(point.y() - currentPoint.y());
    if(dx > dy)
    {
        lastDirection = Horizontal;
    }
    else
    {
        lastDirection = Vertical;
    }
}