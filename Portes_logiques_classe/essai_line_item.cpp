#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

class line_connexion : public QLineF
{
    public: 
    line_connexion();
    QLineF drawLine(QPointF curseur);

    private:
    QLineF segment;
};

class line_scene : public QGraphicsScene
{
    public:
    line_scene(QObject *parent = nullptr);

    protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    private:
    QGraphicsLineItem *segment;
    line_connexion connexion;
};


int main(int argc, char *argv[])
{
    QApplication app(argc,argv);

    line_scene scene;

    QGraphicsView view(&scene);
    view.show();
    return app.exec();
}

line_scene::line_scene(QObject *parent) : QGraphicsScene(parent)
{
    addLine(connexion,QPen(Qt::red));
}

line_connexion::line_connexion()
{
    segment.setLine(0,0,0,0);
}

QLineF line_connexion::drawLine(QPointF curseur)
{
    segment.setLine(0,0,curseur.x(),curseur.y());
    return segment;
}

void line_scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    QLineF current_seg = connexion.drawLine(event->scenePos());
    addLine(current_seg);
    QGraphicsScene::mouseMoveEvent(event);
}

void line_scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mousePressEvent(event);
}