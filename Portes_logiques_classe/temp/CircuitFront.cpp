#include "CircuitFront.h"

CircuitFront::CircuitFront()
{
    mouseTracking = true;
    mouseInScene = false;
    mouseInPorte = false;
    rect = new QGraphicsRectItem;
    rect = addRect(QRectF(-427,-484,850,850));
}

void CircuitFront::addPorteToCircuit(PortesFront *porteFront,bool movePorte,qint8 numero_porte)
{
    mouseTracking = movePorte;
    m_porteFront = porteFront;
    m_porteFront->addPorte();
    m_porte_numero = numero_porte;
}

void CircuitFront::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    //m_porteFront->setCursor(Qt::OpenHandCursor);
    static qint8 n = -1;
    //qDebug() << "passé"<<event->scenePos();
    if(rect->contains(event->scenePos()) && mouseTracking )
    {
        //ceci permet à ce que si une porte est déja ajouté, que elle ne soit plus ajouté, du genre si le numéro de la 
        //porte est déja rentrée et l'item est ajouté , cette porte ne rentre plus
        //du genre on vérifie si l'attributs m_portes_numero est incrémenté
        if(m_porte_numero == (n+1))
        {
            addItem(m_porteFront);
            n = m_porte_numero;
        }
        //qDebug() << "passer : "<<n;
      mouseInScene = true;
      m_porteFront->movePorte(event->scenePos(),mouseTracking);
    }
    else
    {
        mouseInScene = false;
    }
}

void CircuitFront::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    mouseTracking = !mouseTracking;
}