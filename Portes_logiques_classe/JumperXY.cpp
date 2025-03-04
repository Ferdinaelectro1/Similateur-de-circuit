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
  connect(this,&JumperXY::appel_a_horizontale,this,&JumperXY::drawHorizontale);
  connect(this,&JumperXY::appel_a_verticale,this,&JumperXY::drawVerticale);
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




void JumperXY::tracer_ligne_direction(const direction Direction,const sens Sens,const QPointF curseur, QPointF origine, QGraphicsLineItem *ligne)
{
  if (Direction == Vertical && (Sens == v_droite | Sens == v_gauche))
  {
    return;
  }
  if (Direction == Horizontal && (Sens == v_haut | Sens == v_bas))
  {
    return;
  }
  if (Direction == Vertical && Sens == v_bas)
  {
    if (curseur.y() - origine.y() > 0)
    {
      ligne->setLine(origine.x(),origine.y(),origine.x(),curseur.y());
    }
  }
  else if (Direction == Vertical && Sens == v_haut)
  {
    if(curseur.y() - origine.y() < 0)
    {
      ligne->setLine(origine.x(),origine.y(),origine.x(),curseur.y());
    }
  }
  else if (Direction == Horizontal && Sens == v_droite)
  {
    if (curseur.x() - origine.x() > 0)
    {
      ligne->setLine(origine.x(),origine.y(),curseur.x(),origine.y());
    }
  }
  else if (Direction == Horizontal && Sens == v_gauche)
  {
    if (curseur.x() - origine.x() < 0)
    {
      ligne->setLine(origine.x(),origine.y(),curseur.x(),origine.y());   
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

void JumperXY::drawVerticale(QPointF curseur,QPointF origine,bool isFunctionappel)
{
    static int verti_bas = 0;
    static int verti_haut = 0;
    if (isFunctionappel)
    {
      verti_bas = 0;
      verti_haut = 0;
    }
    if (curseur.y() - origine.y() > 0)
    {
      verti_bas = 1;
      if(verti_haut)
      {
/*         line1->setLine(origine.x(),origine.y(),curseur.x(),origine.y());
        line2->setLine(curseur.x(),origine.y(),curseur.x(),curseur.y()); */
        emit appel_a_horizontale(curseur,origine,1);
      }
      else
      {
        line1->setLine(origine.x(),origine.y(),origine.x(),curseur.y());
        line2->setLine(origine.x(),curseur.y(),curseur.x(),curseur.y());
      }
    }
    else
    {
      verti_haut = 1;
      if(verti_bas)
      {
/*         line1->setLine(origine.x(),origine.y(),curseur.x(),origine.y());
        line2->setLine(curseur.x(),origine.y(),curseur.x(),curseur.y()); */
        emit appel_a_horizontale(curseur,origine,1);
      }
      else
      {
        line1->setLine(origine.x(),origine.y(),origine.x(),curseur.y());
        line2->setLine(origine.x(),curseur.y(),curseur.x(),curseur.y());
      }
    }
} 

void JumperXY::drawHorizontale(QPointF curseur,QPointF origine,bool isFunctionappel)
{
  static int hori_droite = 0;
  static int hori_gauche = 0;
  if(isFunctionappel)
  {
    hori_droite = 0;
    hori_gauche = 0;
  }
  if(curseur.x() - origine.x() > 0)
  {
    hori_droite = 1;
    if (!hori_gauche)
    {
      line1->setLine(origine.x(),origine.y(),curseur.x(),origine.y());
      line2->setLine(curseur.x(),origine.y(),curseur.x(),curseur.y());
    }
    else
    {
/*       line1->setLine(origine.x(),origine.y(),origine.x(),curseur.y());
      line2->setLine(origine.x(),curseur.y(),curseur.x(),curseur.y()); */
      emit appel_a_verticale(curseur,origine,1);
    }
  }
  else
  {
    hori_gauche = 1;
    if(!hori_droite)
    {
      line1->setLine(origine.x(),origine.y(),curseur.x(),origine.y());
      line2->setLine(curseur.x(),origine.y(),curseur.x(),curseur.y());
    }
    else
    {
/*       line1->setLine(origine.x(),origine.y(),origine.x(),curseur.y());
      line2->setLine(origine.x(),curseur.y(),curseur.x(),curseur.y()); */
      emit appel_a_verticale(curseur,origine,1);
    }
  }
}


void JumperXY::draw(QPointF curseur,QPointF origine)
{
  static int debut = 0;
  static int deuxieme = 0;
  qreal dx = std::abs(curseur.x() - origine.x());
  qreal dy = std::abs(curseur.y() - origine.y());
  if (dx>dy && !debut)
  {
    debut = 1;
  }
  else if (dx < dy && !debut)
  {
    debut = 2;
  }
  if (debut == 1)
  {
    JumperXY::drawHorizontale(curseur,origine,0);
  }
  else if (debut == 2)
  {
    JumperXY::drawVerticale(curseur,origine,0);
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
/*   line1->setLine(QLineF(m_origine,snapToAxis(curseur)));
  line2->setLine(QLineF(snapToAxis(curseur).x(),snapToAxis(curseur).y(),snapToAxis(curseur).x(),curseur.y())); */
/*   tracer_ligne_direction(Vertical,v_bas,curseur,m_origine,line1);
  tracer_ligne_direction(Vertical,v_haut,curseur,m_origine,line1); */
  draw(curseur,m_origine);
}

