#include "PortesFront.h"

PortesFront::PortesFront(QString porte_picture_dir)
{
    setFlag(QGraphicsItem::ItemIsMovable,true);
    setFlag(QGraphicsItem::ItemIsSelectable,true);
    QPixmap porte_pixmap(porte_picture_dir);
    porte_item = new QGraphicsPixmapItem(porte_pixmap);
}

void PortesFront::addPorte()
{
    addToGroup(porte_item);
}

void PortesFront::movePorte(const QPointF curs_pos,bool isMove)
{
    if(isMove)
    {
        porte_item->setPos(curs_pos);
    }
}

void PortesFront::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //qDebug() << "Toucher";
}