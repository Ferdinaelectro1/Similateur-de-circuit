#ifndef __JUMPERXY_H__
#define __JUMPERXY_H__
#include <QLineF>
#include <cmath>
#include <QDebug>
#include <QGraphicsLineItem>

class JumperXY
{
    public:
    JumperXY();
    void setLines(QGraphicsLineItem *ligne1 , QGraphicsLineItem *ligne2);
    void drawLines(QPointF origine , QPointF curseur);

    private:
    enum sens{v_droite,v_gauche,v_bas,v_haut,v_centre};
    QPointF snapToAxis(const QPointF &point);
    sens sens_line_horizontale(const QPointF &point);
    sens sens_line_verticale(const QPointF &point);
    QPointF m_origine;
    bool direction_change_X;
    bool direction_change_Y;
    sens m_horizontale;
    sens m_verticale;
    QGraphicsLineItem *line1;
    QGraphicsLineItem *line2;

};

#endif