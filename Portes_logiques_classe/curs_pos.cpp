#include "curs_pos.h"

/* pos_curs::pos_curs()
{
}

void pos_curs::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF pos = event->scenePos();
    qDebug() << "Postion : "<<pos;
    //static int n = 0;
    //static QPointF pos_init;
/*     if (n == 0)
    {
        pos_init = event->scenePos();
        ligne = new QGraphicsLineItem(pos_init.x(), pos_init.y() , event->scenePos().x() , event->scenePos().y());
        ligne->setPen(QPen(Qt::red));
        n = 1;
    }
    else if (n == 1)
    {
      ligne = new QGraphicsLineItem(pos_init.x(), pos_init.y() , event->scenePos().x() , event->scenePos().y());
      ligne->setPen(QPen(Qt::red));
       n = 0;
    } */
/*
    ligne = new QGraphicsLineItem(event->scenePos().x() , event->scenePos().y()  , event->scenePos().x() , event->scenePos().y());
    ligne->setPen(QPen(Qt::red));
    addItem(ligne);
    
    QGraphicsScene::mouseMoveEvent(event);
} */

pos_curs::pos_curs(QObject *parent): QGraphicsScene(parent)
{
    lignes.append(QLineF(0,0,0,0));
}

void pos_curs::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    startPoint = event->scenePos();
    lineItem = addLine(QLineF(startPoint,startPoint));
    lineItem->setPen(QPen(Qt::green));
    QGraphicsScene::mousePressEvent(event);
}

void pos_curs::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    static int n = 0;
    if(lineItem)
    {
        if((startPoint.y() - event->scenePos().y()) > 50 && (startPoint.y() - event->scenePos().y()) > 0)
        {
            QLineF newLine(startPoint.x(),startPoint.y(),startPoint.x(),event->scenePos().y());
            lineItem->setLine(newLine); 
        }
        else if (-(startPoint.y() - event->scenePos().y()) > 50 && (startPoint.y() - event->scenePos().y()) < 0)
        {
            QLineF newLine(startPoint.x(),startPoint.y(),startPoint.x(),event->scenePos().y());
            lineItem->setLine(newLine);   
        }
        else 
        {
            lignes.push_front(QLineF(startPoint.x(),startPoint.y(),event->scenePos().x(),startPoint.y()));
            lineItem->setLine(lignes[n]);
            //lineItem->setLine(newLine);
            //qDebug() << "passer";
        }
    }
    QGraphicsScene::mouseMoveEvent(event);
}

void pos_curs::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    lineItem = nullptr;
    QGraphicsScene::mouseReleaseEvent(event);
}
