#include "NotFront.h"
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

NotFront::NotFront(QGraphicsItem *parent, int x, int y) :QGraphicsItemGroup(parent), isMoving(false)
{
    setFlag(QGraphicsItem::ItemIsMovable, true);// permet d'activer le  pouvoir déplacer le bloque d'item qui constitue la porte NOT
    setFlag(QGraphicsItem::ItemIsSelectable, true); // permet d'activer le pouvoir de sélectionner le bloque d'item qui constitue la porte NOT

    //Initialisation
    name_porte = new QGraphicsTextItem("NOT",this);
    addToGroup(name_porte);
    
    // Ajout de la ligne d'entrée
    QGraphicsLineItem* inputLine = new QGraphicsLineItem(-40, 0, -20, 0);
    inputLine->setPen(QPen(Qt::black, 2));  // Ligne d'entrée en blanc
    addToGroup(inputLine);

    // Dessin de la forme de la porte NOT (triangle)
    QPainterPath path;
    path.moveTo(-20, -20);       // Point en haut du triangle
    path.lineTo(-20, 20);        // Point en bas gauche du triangle
    path.lineTo(0, 0);           // Pointe du triangle à droite
    path.closeSubpath();         // Ferme le triangle

    QGraphicsPathItem* notShape = new QGraphicsPathItem(path);
    notShape->setBrush(QBrush(Qt::black));  // Remplissage en noir
    notShape->setPen(Qt::NoPen);            // Supprime le contour du triangle
    addToGroup(notShape);

    // Ajout du cercle pour la sortie de la porte NOT
    QGraphicsEllipseItem* outputCircle = new QGraphicsEllipseItem(0, -5, 10, 10);
    outputCircle->setBrush(QBrush(Qt::black));  // Cercle en noir
    outputCircle->setPen(Qt::NoPen);            // Pas de contour
    addToGroup(outputCircle);

    // Ajout de la ligne de sortie
    QGraphicsLineItem* outputLine = new QGraphicsLineItem(12, 0, 30, 0);
    outputLine->setPen(QPen(Qt::red, 2));     // Ligne de sortie en blanc
    addToGroup(outputLine);
}


//redéfinition de la méthode qui permet de pouvoir déplacer la porte en fonction de la position du curseur
void NotFront::mouseMoveEvent(QGraphicsSceneMouseEvent *even)
{
    // vérifie si on a cliqué sur la porte grâce à l'attribut isMoving (si on clique sur la porte le isMoving passe à true)
    if (isMoving)
    {
        // Si on a cliqué sur la porte alors : 
        QPointF delta = even->scenePos() - lastMousePos;/* la variable QPointF delta mémorise la valeur actuelle du curseur de la souris (grâce à even->scenePos)
        moins son ancienne poition */
        moveBy(delta.x(), delta.y());// déplace le bloc d'item(la porte Not) à cette position
        lastMousePos = even->scenePos();// mémorise à nouveau l'état actuelle de la position du curseur de la souris 
    }
}

// redefinition de la méthode qui détecte que le Bloc d'Item (porte NOT) est cliqué
void NotFront::mousePressEvent(QGraphicsSceneMouseEvent *even) 
{
    // si l'évenement de clique de boutton gauche soite un double clic est détecté alors : 
    if (even->button() == Qt::LeftButton)
    {
        isMoving = true; //faire passer l'attribut isMoving à true
        lastMousePos = even->scenePos();//mémoriser la position actuelle du curseur 
        setCursor(Qt::ClosedHandCursor); // transformer le curseur flêche en curseur de main (la flêche du curseur devient une main)
    }
}

//redefinition de la méthode du clic relacher sur l'objet (la porte Not) soite la méthode clic relaché 
void NotFront::mouseReleaseEvent(QGraphicsSceneMouseEvent *even) 
{
    // si l'evenement de clic relaché de Boutton gauche soite double clic esr détecté alors:
    if (even->button() == Qt::LeftButton)
    {
        //l'attribut isMoving passe à false pour empêcher la porte de se déplacer 
        isMoving = false;
        setCursor(Qt::ArrowCursor);// le curseur de main redevient le curseur de flêche
    }
}