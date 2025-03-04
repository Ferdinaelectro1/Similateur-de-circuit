#include <iostream>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class MonRect : public QGraphicsRectItem
{
    public:
      MonRect(QGraphicsItem *parent = nullptr) : QGraphicsRectItem(parent), isMoving(false)
      {
          setFlag(QGraphicsItem::ItemIsMovable, true);
          setFlag(QGraphicsItem::ItemIsSelectable, true);
      }

    protected:

      void mouseMoveEvent(QGraphicsSceneMouseEvent *even) override
      {
        if (isMoving)
        {
            // Utiliser les positions dans la scène plutôt que les positions locales
            QPointF delta = even->scenePos() - lastMousePos;
            moveBy(delta.x(), delta.y());
            lastMousePos = even->scenePos();  // Mettre à jour la dernière position de la souris
        }
      }

      void mousePressEvent(QGraphicsSceneMouseEvent* even) override
      {
        if (even->button() == Qt::LeftButton)
        {
            isMoving = true;
            lastMousePos = even->scenePos();  // Prendre les coordonnées dans la scène
            setCursor(Qt::ClosedHandCursor);
        }
      }

      void mouseReleaseEvent(QGraphicsSceneMouseEvent *even) override
      {
        if (even->button() == Qt::LeftButton)
        {
            isMoving = false;
            setCursor(Qt::ArrowCursor);
        }
      }

    private:
      bool isMoving;
      QPointF lastMousePos;
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QGraphicsScene scene;

    MonRect *rect = new MonRect();
    rect->setRect(0, 0, 30, 30);
    rect->setBrush(Qt::yellow);
    scene.addItem(rect);

    QGraphicsView view(&scene);
    view.resize(800, 800);
    view.show();

    return app.exec();
}
