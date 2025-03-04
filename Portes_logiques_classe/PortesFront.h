#ifndef __PORTESFRONT_H__
#define __PORTESFRONT_H__
#include <QGraphicsItemGroup>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

class PortesFront : public QGraphicsItemGroup
{
    public:
      PortesFront(QString porte_picture_dir);
      void addPorte();
      void movePorte(const QPointF curs_pos,bool isMove);
    
    protected:
      void mousePressEvent(QGraphicsSceneMouseEvent *event);

    private:
      QGraphicsPixmapItem *porte_item;
};

#endif