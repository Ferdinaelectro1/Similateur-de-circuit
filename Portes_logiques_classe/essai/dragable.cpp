#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGraphicsSceneMouseEvent>

class DraggableRect : public QGraphicsRectItem {
public:
    DraggableRect() : QGraphicsRectItem() {}

    // On réimplémente l'événement de clic souris
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override {
        setBrush(Qt::green);  // Change la couleur quand on clique dessus
        QGraphicsRectItem::mousePressEvent(event);
    }

    // On réimplémente l'événement de déplacement de la souris
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override {
        setPos(mapToScene(event->pos()));  // Déplace le rectangle
        QGraphicsRectItem::mouseMoveEvent(event);
    }
};

int main(int argc , char *argv[])
{
    QApplication app(argc,argv);
    
    QGraphicsScene scene;

    DraggableRect *draggableRect = new DraggableRect();
    draggableRect->setRect(0, 0, 100, 100);
    draggableRect->setBrush(Qt::red);
    scene.addItem(draggableRect);

    QGraphicsView view(&scene);
    view.setWindowTitle("Fenetre de test");
    //view.resize(800,800);
    view.setTransformationAnchor(QGraphicsView::AnchorUnderMouse);  // Zoomer à l'endroit du curseur
    view.setDragMode(QGraphicsView::ScrollHandDrag);  // Permet de faire glisser la vue
    view.scale(1.2, 1.2);  // Zoom à 120%
    view.setDragMode(QGraphicsView::ScrollHandDrag);  // Déplacement de la scène en maintenant le clic
    view.show();
    return app.exec();
}