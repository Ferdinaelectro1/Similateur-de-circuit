#include "JumperXY.h"
#include <QDebug>

JumperXY::JumperXY()
{
  line1 = new QGraphicsLineItem(0,0,0,0);
  line2 = new QGraphicsLineItem(0,0,0,0);
  m_origine.setX(0);
  m_origine.setY(0);
  direction_change_X = 0;
  direction_change_Y = 0;
}

QPointF JumperXY::snapToAxis(const QPointF &point)
{
    qreal dx = std::abs(m_origine.x() - point.x());
    qreal dy = std::abs(m_origine.y() - point.y());
    if(dx > dy)
    {
      direction_change_X = 1;
      if (direction_change_Y)
      {
        direction_change_X = 0;
        return QPointF(m_origine.x(),point.y());
      }
      else
      {
        return QPointF(point.x(),m_origine.y());
      }
    }
    else
    {
      direction_change_Y = 1;
      if (direction_change_X)
      {
        direction_change_Y = 0;
        return QPointF(point.x(),m_origine.y());
      }
       else
      {
        return QPointF(m_origine.x(),point.y());
      }
    }
}


JumperXY::sens JumperXY::sens_line_horizontale(const QPointF &point)
{
  if((m_origine.x() - point.x()) < 0)
  {
    return sens::v_droite;
  }
  else 
  {
    return sens::v_gauche;
  }
}

JumperXY::sens JumperXY::sens_line_verticale(const QPointF &point)
{
  if ((m_origine.y() - point.y()) < 0)
  {
    return sens::v_bas;
  }
  else 
  {
    return sens::v_haut; 
  }
}

void JumperXY::setLines(QGraphicsLineItem *ligne1 , QGraphicsLineItem *ligne2)
{
  line1 = ligne1;
  line2 = ligne2;
  line1->setLine(QLineF(0,0,100,200));
  line2->setLine(QLineF(0,0,70,150));
}

void JumperXY::drawLines(QPointF origine , QPointF curseur)
{
  m_origine.setX(origine.x());
  m_origine.setY(origine.y());
  line1->setLine(QLineF(m_origine,snapToAxis(curseur)));
  line2->setLine(QLineF(snapToAxis(curseur).x(),snapToAxis(curseur).y(),snapToAxis(curseur).x(),curseur.y()));
}

