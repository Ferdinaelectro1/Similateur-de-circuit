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

class scene_jump : public QGraphicsScene
{
    public:
    scene_jump();

    protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    private:
    JumperXY jumpers;
    Wire wire;
    QGraphicsRectItem *rect;
    QPointF m_origine;
    
};

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);

    scene_jump scene;

    QGraphicsView view(&scene);
/*     qDebug() << "Transform : "<<view.transform();
    qDebug() << "Scale : "<<view.transform().m11() << ","<<view.transform().m22(); */
    //view.setRenderHint(QPainter::Antialiasing,false);
    //view.resetTransform();
    view.show();
    return app.exec();
}

scene_jump::scene_jump()
{
    rect = new QGraphicsRectItem(QRectF(0,0,0,0));
    rect = addRect(QRectF(0,0,800,800));
    m_origine.setX(0);
    m_origine.setY(0);
    QGraphicsItemGroup *group = scene_jump::createItemGroup({});
    wire.setLines(group);
}

void scene_jump::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    m_origine = event->scenePos();
    //wire.afficher_origine();
    //qDebug() << "m_origine :"<<m_origine;  
    //wire.setLines(addLine(QLineF(m_origine,event->sce nePos())));
}

void scene_jump::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    wire.afficher_origine(1);
    //m_origine = QPointF(rect->x() + 10,rect->y() + 10);
    wire.drawLines(m_origine,event->scenePos());
    //wire.afficher_origine();
    wire.afficher_origine(2);
}

