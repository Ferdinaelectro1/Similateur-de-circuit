#include "OrFront.h"
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

//Constructeur de la classe OrFront (classe qui est formées de plusieurs item permettant de désinner la porte Or)
OrFront::OrFront(QGraphicsItem *parent , int x, int y):QGraphicsItemGroup(parent), isMoving(false)
{
    setFlag(QGraphicsItem::ItemIsMovable, true);// permet d'activer le  pouvoir déplacer le bloque d'item qui constitue la porte OR
    setFlag(QGraphicsItem::ItemIsSelectable, true); // permet d'activer le pouvoir de sélectionner le bloque d'item qui constitue la porte OR

    //initialisation
    name_porte = new QGraphicsTextItem("OR",this);
    addToGroup(name_porte);

    // Ajout des lignes d'entrée
    QGraphicsLineItem* input1 = new QGraphicsLineItem(-50, -20, -15, -20);
    QGraphicsLineItem* input2 = new QGraphicsLineItem(-50, 20, -15, 20);

    addToGroup(input1);
    addToGroup(input2);

    // Dessin de la forme de la porte OR avec des courbes
    QPainterPath path;
    // Courbe gauche pour l'arrondi
    path.moveTo(-20, -30);
    path.quadTo(-5, 0, -20, 30);
    
    // Courbe droite pour la sortie, plus prononcée
    path.moveTo(-20, -30);
    path.cubicTo(20, -30, 30, 30, -20, 30);

    // Création de l'élément de forme de la porte OR et ajout d'un remplissage noir
    QGraphicsPathItem* orShape = new QGraphicsPathItem(path);
    orShape->setBrush(QBrush(Qt::black));  // Remplissage en noir
    orShape->setPen(Qt::NoPen);            // Supprime le contour de la courbe

    addToGroup(orShape);

    // Ajout de la ligne de sortie en blanc
    QGraphicsLineItem* output = new QGraphicsLineItem(13, 0, 50, 0);
    addToGroup(output);

}

//redéfinition de la méthode qui permet de pouvoir déplacer la porte en fonction de la position du curseur
void OrFront::mouseMoveEvent(QGraphicsSceneMouseEvent *even)
{
    // vérifie si on a cliqué sur la porte grâce à l'attribut isMoving (si on clique sur la porte le isMoving passe à true)
    if (isMoving)
    {
        // Si on a cliqué sur la porte alors : 
        QPointF delta = even->scenePos() - lastMousePos;/* la variable QPointF delta mémorise la valeur actuelle du curseur de la souris (grâce à even->scenePos)
        moins son ancienne poition */
        moveBy(delta.x(), delta.y());// déplace le bloc d'item(la porte Or) à cette position
        lastMousePos = even->scenePos();// mémorise à nouveau l'état actuelle de la position du curseur de la souris 
    }
}

// redefinition de la méthode qui détecte que le Bloc d'Item (porte OR) est cliqué
void OrFront::mousePressEvent(QGraphicsSceneMouseEvent *even) 
{
    // si l'évenement de clique de boutton gauche soite un double clic est détecté alors : 
    if (even->button() == Qt::LeftButton)
    {
        isMoving = true; //faire passer l'attribut isMoving à true
        lastMousePos = even->scenePos();//mémoriser la position actuelle du curseur 
        setCursor(Qt::ClosedHandCursor); // transformer le curseur flêche en curseur de main (la flêche du curseur devient une main)
    }
}

//redefinition de la méthode du clic relacher sur l'objet (la porte OR) soite la méthode clic relaché 
void OrFront::mouseReleaseEvent(QGraphicsSceneMouseEvent *even) 
{
    // si l'evenement de clic relaché de Boutton gauche soite double clic esr détecté alors:
    if (even->button() == Qt::LeftButton)
    {
        //l'attribut isMoving passe à false pour empêcher la porte de se déplacer 
        isMoving = false;
        setCursor(Qt::ArrowCursor);// le curseur de main redevient le curseur de flêche
    }
}