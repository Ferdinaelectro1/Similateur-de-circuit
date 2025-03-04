#include "JumperXY.h"
#include <QDebug>

JumperXY::JumperXY()
{
  line1 = new QGraphicsLineItem(0,0,0,0);
  line2 = new QGraphicsLineItem(0,0,0,0);
  m_origine.setX(0);
  m_origine.setY(0);
  verti_bas = 0;
  verti_haut = 0;
  hori_droite = 0;
  hori_gauche = 0;
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

void JumperXY::draw(QPointF curseur,QPointF origine)
{
  static int debut = 0;
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
        line1->setLine(origine.x(),origine.y(),origine.x(),curseur.y());
        line2->setLine(origine.x(),curseur.y(),curseur.x(),curseur.y());
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
        line1->setLine(origine.x(),origine.y(),origine.x(),curseur.y());
        line2->setLine(origine.x(),curseur.y(),curseur.x(),curseur.y());
      }
    }
  }
  else if (debut == 2)
  {
    if (curseur.y() - origine.y() > 0)
    {
      verti_bas = 1;
      if(verti_haut)
      {
        line1->setLine(origine.x(),origine.y(),curseur.x(),origine.y());
        line2->setLine(curseur.x(),origine.y(),curseur.x(),curseur.y());
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
        line1->setLine(origine.x(),origine.y(),curseur.x(),origine.y());
        line2->setLine(curseur.x(),origine.y(),curseur.x(),curseur.y());
      }
      else
      {
        line1->setLine(origine.x(),origine.y(),origine.x(),curseur.y());
        line2->setLine(origine.x(),curseur.y(),curseur.x(),curseur.y());
      }
    }
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


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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



////////////////////////////////////////////////////////////////////////////////::


#include "NandFront.h"
#include <QGraphicsItem>
#include <QGraphicsItemGroup>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsLineItem>
#include <QGraphicsEllipseItem>
#include <QApplication>
#include <QGraphicsPathItem>
#include <QPen>
#include <QBrush>




//Constructeur de la classe NandFront (classe qui est formées de plusieurs item permettant de désinner la porte nand)
NandFront::NandFront(QGraphicsItem *parent , int x, int y):QGraphicsItemGroup(parent), isMoving(false)
{
    setFlag(QGraphicsItem::ItemIsMovable, true);// permet d'activer le  pouvoir déplacer le bloque d'item qui constitue la porte NAND
    setFlag(QGraphicsItem::ItemIsSelectable, true); // permet d'activer le pouvoir de sélectionner le bloque d'item qui constitue la porte NAND

    // Ajout des lignes d'entrée
    QGraphicsLineItem* input1 = new QGraphicsLineItem(50 + x, 15 + y, 100 + x, 15 + y);
    QGraphicsLineItem* input2 = new QGraphicsLineItem(50 + x, 35 + y, 100 + x, 35 + y);

    addToGroup(input1);
    addToGroup(input2);

    // Ajout de la ligne de sortie en blanc
    QGraphicsLineItem* output = new QGraphicsLineItem(120 + x, 25 + y, 170 + x, 25 + y);
    addToGroup(output);

    SimpleDessin *corps_de_la_porte = new SimpleDessin();
    addToGroup(corps_de_la_porte);
    
}

//redéfinition de la méthode qui permet de pouvoir déplacer la porte en fonction de la position du curseur
void NandFront::mouseMoveEvent(QGraphicsSceneMouseEvent *even)
{
    // vérifie si on a cliqué sur la porte grâce à l'attribut isMoving (si on clique sur la porte le isMoving passe à true)
    if (isMoving)
    {
        // Si on a cliqué sur la porte alors : 
        QPointF delta = even->scenePos() - lastMousePos;/* la variable QPointF delta mémorise la valeur actuelle du curseur de la souris (grâce à even->scenePos)
        moins son ancienne poition */
        moveBy(delta.x(), delta.y());// déplace le bloc d'item(la porte NAND) à cette position
        lastMousePos = even->scenePos();// mémorise à nouveau l'état actuelle de la position du curseur de la souris 
    }
}

// redefinition de la méthode qui détecte que le Bloc d'Item (porte NAND) est cliqué
void NandFront::mousePressEvent(QGraphicsSceneMouseEvent *even) 
{
    // si l'évenement de clique de boutton gauche soite un double clic est détecté alors : 
    if (even->button() == Qt::LeftButton)
    {
        isMoving = true; //faire passer l'attribut isMoving à true
        lastMousePos = even->scenePos();//mémoriser la position actuelle du curseur 
        setCursor(Qt::ClosedHandCursor); // transformer le curseur flêche en curseur de main (la flêche du curseur devient une main)
    }
}

//redefinition de la méthode du clic relacher sur l'objet (la porte NAND) soite la méthode clic relaché 
void NandFront::mouseReleaseEvent(QGraphicsSceneMouseEvent *even) 
{
    // si l'evenement de clic relaché de Boutton gauche soite double clic esr détecté alors:
    if (even->button() == Qt::LeftButton)
    {
        //l'attribut isMoving passe à false pour empêcher la porte de se déplacer 
        isMoving = false;
        setCursor(Qt::ArrowCursor);// le curseur de main redevient le curseur de flêche
    }
}

//constucteur de simple dessin
SimpleDessin::SimpleDessin(QGraphicsItem *parent) : QGraphicsPathItem(parent)
{
    setPath(QPainterPath());
}

//redefinition de la methode paint pour permettre de dessiner 
void SimpleDessin::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) 
{
    painter->setPen(QPen(Qt::black,3));
    painter->setBrush(QBrush(Qt::black));
    //rectangle corps de la porte nand 
    painter->drawRect(85,10,30,30);
    //cercle pour former la courbe qui est devant la porte nand
    painter->drawEllipse(100,11,30,30);
    //changement de la couleur du remplissage
    painter->setBrush(QBrush(Qt::white));
    //petit cercle devant la porte nand
    painter->drawEllipse(130,20,10,10);
}


//Création d'un Item pour permettre d'utiliser un QPainter pour dessiner facilement au lieu d'un QPainterpath .
// Cet Item represente le corps de la porte logique 
class SimpleDessin : public QGraphicsPathItem
{
    public:
    SimpleDessin(QGraphicsItem *parent = nullptr);

    protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};
