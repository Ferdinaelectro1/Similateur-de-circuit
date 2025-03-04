#ifndef __FIL_H__
#define __FIL_H__
#include <QGraphicsLineItem>
#include <iostream>
#include <QDebug>

class Fil 
{
    public:
      Fil();
      Fil(QGraphicsLineItem *line);
      void moveLine(QPointF origine,QPointF curseur,bool isMove);
      QPointF get_new_origine();
    
    private:
      QGraphicsLineItem *m_line;
      QPointF m_origine;
      QPointF m_curseur;
      QPointF m_new_origine;
};

#endif