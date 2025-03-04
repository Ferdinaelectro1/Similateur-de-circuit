#ifndef __JUMPERXY_H__
#define __JUMPERXY_H__
#include <QLineF>
#include <cmath>
#include <QDebug>
#include <QGraphicsLineItem>
#include <functional>
#include <QObject>

class JumperXY : public QObject
{
    Q_OBJECT

    public:
    JumperXY();
    void setLines(QGraphicsLineItem *ligne1 , QGraphicsLineItem *ligne2);
    void drawLines(QPointF origine , QPointF curseur);
    void appel_debut1(QPointF curseur,QPointF origine,bool& hori_droite,bool& hori_gauche,int appel);

    private:
    enum sens{v_droite,v_gauche,v_bas,v_haut,v_centre};
    enum direction{Horizontal,Vertical};
    QPointF snapToAxis(const QPointF &point);
    sens sens_line_horizontale(const QPointF &point);
    sens sens_line_verticale(const QPointF &point);
    void tracer_ligne_direction(const direction Direction,const sens Sens,const QPointF curseur,QPointF origine,QGraphicsLineItem *ligne);
    void draw(QPointF curseur,QPointF origine);
    void debut_1(QPointF curseur, QPointF origine, bool &hori_droite,bool &hori_gauche,int appel,std::function<void(QPointF,QPointF,bool&,bool&,int)> fonction,QPointF curseur_func,QPointF origine_func,bool &hori_droite_func,bool &hori_gauche_func,int appel_func);
    void debut_2(QPointF curseur, QPointF origine,bool &verti_bas,bool &verti_haut,int appel);
    QPointF m_origine;
    bool direction_change_X;
    bool direction_change_Y;
    bool verti_bas_2;
    bool verti_haut_2;
    bool hori_droite_2;
    bool hori_gauche_2;
    sens m_horizontale;
    sens m_verticale;
    QGraphicsLineItem *line1;
    QGraphicsLineItem *line2;

private slots:
    void drawHorizontale(QPointF curseur,QPointF origine,bool isFunctionappel);
    void drawVerticale(QPointF curseur,QPointF origine,bool isFunctionappel);

signals:
    void appel_a_horizontale(QPointF curseur,QPointF origine,bool isFunctionappel);
    void appel_a_verticale(QPointF curseur,QPointF origine,bool isFunctionappel);
};

#endif