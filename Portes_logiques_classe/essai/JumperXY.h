#ifndef __JUMPERXY_H__
#define __JUMPERXY_H__
#include <QLineF>
#include <cmath>
#include <QDebug>

class JumperXY : public QLineF
{
    public:
    JumperXY();
    QLineF xyDrawer_line1(const QPointF origine,const QPointF point);
    QLineF xyDrawer_line2();

    private:
    QPointF snapToAxis(const QPointF &point);
    void directionChanged(const QPointF &point);
    enum Direction{Horizontal,Vertical};
    Direction m_direction;
    QPointF m_origine;
    QPointF m_origineTemp;
    QPointF m_sommet1;
    QPointF m_sommet2;
    QLineF m_ligne1;
    QLineF m_ligne2;
    bool isDrawing_line1;
    bool isDrawing_line2;
};

#endif