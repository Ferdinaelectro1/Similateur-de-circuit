#include "Wire.h"

Wire::Wire()
{
    line = new QGraphicsLineItem(QLineF(0,0,0,0));
    line->setFlags(QGraphicsItem::ItemIsMovable);
    //rect = new QGraphicsRectItem(-400,-400,400,400);
}

void Wire::afficher_origine(qint8 number)
{
    qDebug() << "origne n° "<<number<<" : "<< m_origine;
}

void Wire::setLines(QGraphicsItemGroup *group)
{
    group->addToGroup(line);
}

void Wire::drawLines(QPointF curseur,QPointF origine)
{
    m_origine = origine;

    qreal dx = std::abs(curseur.x() - origine.x());
    qreal dy = std::abs(curseur.y() - origine.y());
    QPointF origine_copy = origine;
    QLineF line_copy = line->line();
    if(dx > dy)
    {
        //QLineF l1(origine_copy.x(),origine_copy.y(),curseur.x(),origine_copy.y());
        line_copy.setP1(QPointF(origine.x(),origine.y()));
        line_copy.setP2(QPointF(curseur.x(),origine.y()));
        line->setLine(line_copy);
    }
    else
    {
        //QLineF l2(origine_copy.x(),origine_copy.y(),origine_copy.x(),curseur.y());
        line_copy.setP1(QPointF(origine.x(),origine.y()));
        line_copy.setP2(QPointF(origine.x(),curseur.y()));
        line->setLine(line_copy);
    }
}
