#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsLineItem>
#include <QDebug>
#include <QGraphicsRectItem>
#include <QGraphicsItemGroup>
#include "JumperXY.h"
#include "Wire.h"
#include "Fil.h"

class scene_jump : public QGraphicsScene
{
    public:
    scene_jump();
    void set_view_mouseTrack(QGraphicsView &vu);

    protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    private:
    JumperXY jumpers;
    Wire wire;
    Fil *fil;
    QGraphicsRectItem *rect;
    QGraphicsLineItem *ligne;
    QPointF m_origine;
    bool m_mouseTracking;
};

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);

    scene_jump scene;

    
    QGraphicsView view(&scene);
    scene.set_view_mouseTrack(view);
/*     qDebug() << "Transform : "<<view.transform();
    qDebug() << "Scale : "<<view.transform().m11() << ","<<view.transform().m22(); */
    //view.setRenderHint(QPainter::Antialiasing,false);
    //view.resetTransform();
    view.show();
    return app.exec();
}

scene_jump::scene_jump()
{
    ligne = new QGraphicsLineItem;
    rect = new QGraphicsRectItem(QRectF(0,0,0,0));
    rect = addRect(QRectF(0,0,800,800));
    m_origine.setX(0);
    m_origine.setY(0);
    m_mouseTracking = false;
}

void scene_jump::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    static bool passage = 0;
    if(!passage)
    {
        m_origine = event->scenePos();
        passage = 1;
    }
    else
    {
        m_origine = fil->get_new_origine();
    }
    fil = new Fil(addLine(QLineF(m_origine,m_origine)));
    m_mouseTracking = true;
}

void scene_jump::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    fil->moveLine(m_origine,event->scenePos(),true);
}

void scene_jump::set_view_mouseTrack(QGraphicsView &vu)
{
    vu.setMouseTracking(m_mouseTracking);
}