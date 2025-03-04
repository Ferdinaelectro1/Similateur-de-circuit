#ifndef __WIRE_H__
#define __WIRE_H__
#include <QGraphicsLineItem>
#include <QGraphicsItemGroup>
#include <QGraphicsRectItem>
#include <iostream>
#include <QDebug>

class Wire 
{
    public:
      Wire();
      void drawLines(QPointF curseur,QPointF origine);
      void setLines(QGraphicsItemGroup *group);
      void afficher_origine(qint8 number);
    
    private:
      QGraphicsLineItem *line;
      QPointF m_origine;
      QGraphicsRectItem *rect;
};

#endif