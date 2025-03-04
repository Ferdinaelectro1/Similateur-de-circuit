#include "JumperXY.h"

JumperXY::JumperXY()
{
    m_origine.setX(0);
    m_origine.setY(0);
    isDrawing_line1 = 1;
    isDrawing_line2 = 1;
}

QPointF JumperXY::snapToAxis(const QPointF &point)
{
    qreal dx = std::abs(m_origine.x() - point.x());
    qreal dy = std::abs(m_origine.y() - point.y());
    if(dx > dy)
      return QPointF(point.x(),m_origine.y());
    else
      return QPointF(m_origine.x(),point.y());
}

QLineF JumperXY::xyDrawer_line1(const QPointF origine,const QPointF point)
{
  m_origine.setX(origine.x());
  m_origine.setY(origine.y());
  m_sommet1 = snapToAxis(point);
  if (isDrawing_line1)
  {
    m_ligne1 = QLineF(m_origine,m_sommet1);
    return m_ligne1;
  }
  else
  {
    return QLineF(m_origine.x(),m_origine.y(),m_origine.x(),m_sommet1.y());
  }
}

QLineF JumperXY::xyDrawer_line2()
{
  if(m_ligne1.dy() == 0)
    isDrawing_line2 = 0;
  else
    isDrawing_line2 = 1;

  if (isDrawing_line2)
  {
    if(m_ligne1.dy() > 0)
    {
      //isDrawing_line1 = 0;
      return QLineF(m_sommet1.x(),100,500,300);
      //return QLineF(m_origine.x(),m_sommet1.y(),m_sommet1.x(),m_sommet1.y());
    }
    else
    {
     // isDrawing_line1 = 0;
      return QLineF(m_sommet1.x(),100,500,300);
      //return QLineF(m_origine.x(),m_sommet1.y(),m_sommet1.x(),m_sommet1.y());
    }   
  }
  else
  {
    return QLineF(m_sommet1,m_sommet1);
  }
}

void JumperXY::directionChanged(const QPointF &point)
{

}