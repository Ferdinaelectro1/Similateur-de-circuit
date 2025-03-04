#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QPointF>
#include <QGraphicsLineItem>
#include <QList>
#include <QDebug>

class pos_curs : public QGraphicsScene
{
    QGraphicsLineItem *lineItem;
    QPointF startPoint;

    public:
      pos_curs(QObject *parent = nullptr);

    protected:
      void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;  
      void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
      void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    private:
      QGraphicsLineItem *ligne;
      QList<QLineF> lignes;
};