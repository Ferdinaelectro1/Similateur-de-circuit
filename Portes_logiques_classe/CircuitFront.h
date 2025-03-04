#ifndef __CIRCUITFRONT_H__
#define __CIRCUITFRONT_H__
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QGraphicsRectItem>
#include "PortesFront.h"
#include "Fil.h"

class CircuitFront : public QGraphicsScene
{
    public:
      CircuitFront();
      void addPorteToCircuit(PortesFront *porteFront,bool movePorte,qint8 numero_porte);
    
    protected:
      void mouseMoveEvent(QGraphicsSceneMouseEvent *event)  override;
      void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
      //void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    
    private:
      PortesFront *m_porteFront;
      bool mouseTracking;
      bool mouseInScene;
      QGraphicsRectItem *rect;
      qint8 m_porte_numero;
      bool mouseInPorte;
      Fil *fil;
      QPointF m_origine;
      bool draw_schema_wire;
};

#endif