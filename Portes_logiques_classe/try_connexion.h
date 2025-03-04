#include <QGraphicsScene>
#include <QGraphicsLineItem>
//#include <QMouseEvent>
#include <cmath>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>

class Circuitscene : public QGraphicsScene
{
    public:
    Circuitscene(QObject *parent = nullptr);

    protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    private:
    QPointF snapToAxis(const QPointF &point);
    bool directionChanged(const QPointF &point);
    void updateDirection(const QPointF &point);
    QPointF currentPoint;
    QGraphicsLineItem *tempLine;
    bool isDrawing;
    enum Direction{Horizontal,Vertical};
    Direction lastDirection = Horizontal;

};