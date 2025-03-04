#include "NandFront.h"
#include <QGraphicsItem>
#include <QGraphicsItemGroup>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsLineItem>
#include <QGraphicsEllipseItem>
#include <QApplication>
#include <QGraphicsPathItem>




//Constructeur de la classe NandFront (classe qui est formées de plusieurs item permettant de désinner la porte nand)
NandFront::NandFront(QGraphicsItem *parent , int x, int y):QGraphicsItemGroup(parent), isMoving(false)
{
    setFlag(QGraphicsItem::ItemIsMovable, true);// permet d'activer le  pouvoir déplacer le bloque d'item qui constitue la porte NAND
    setFlag(QGraphicsItem::ItemIsSelectable, true); // permet d'activer le pouvoir de sélectionner le bloque d'item qui constitue la porte NAND
    nand_svg = QPixmap("AND.svg");
    nand_item = new QGraphicsPixmapItem(nand_svg);
    addToGroup(nand_item);
}

//redéfinition de la méthode qui permet de pouvoir déplacer la porte en fonction de la position du curseur
void NandFront::mouseMoveEvent(QGraphicsSceneMouseEvent *even)
{
    // vérifie si on a cliqué sur la porte grâce à l'attribut isMoving (si on clique sur la porte le isMoving passe à true)
    if (isMoving)
    {
        nand_item->setPos(even->scenePos());
    }
}

// redefinition de la méthode qui détecte que le Bloc d'Item (porte NAND) est cliqué
void NandFront::mousePressEvent(QGraphicsSceneMouseEvent *even) 
{
    // si l'évenement de clique de boutton gauche soite un double clic est détecté alors : 
    if (even->button() == Qt::LeftButton)
    {
        origine_point = even->scenePos();
        nand_item->setPos(nand_item->pos());
        addToGroup(nand_item);
        setCursor(Qt::OpenHandCursor);
        isMoving = true;
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

