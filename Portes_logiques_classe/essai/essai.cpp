#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>

void porte_and(QGraphicsScene &scene, int x , int y)
{
    QGraphicsRectItem *rectangle = new QGraphicsRectItem(85 + x,10 + y,30,30);
    rectangle->setBrush(Qt::black);
    scene.addItem(rectangle);


    QGraphicsEllipseItem *cercle = new QGraphicsEllipseItem(100 + x,10 + y,30,30);
    cercle->setBrush(Qt::black);
    scene.addItem(cercle); 

    QGraphicsLineItem *ligne1 = new QGraphicsLineItem(50 + x,15+ y,100 + x,15 + y);
    //ligne1->setBrush(Qt::red);
    scene.addItem(ligne1);

    QGraphicsLineItem *ligne2 = new QGraphicsLineItem(50 + x,35 + y,100 + x,35 + y);
    //ligne1->setBrush(Qt::red);
    scene.addItem(ligne2);

    QGraphicsLineItem *ligne3 = new QGraphicsLineItem(100 + x,25 + y,150 + x,25 + y);
    //ligne1->setBrush(Qt::red);
    scene.addItem(ligne3);
}

int main(int argc , char *argv[])
{
    QApplication app(argc,argv);
    
    QGraphicsScene scene;

    porte_and(scene,50,0);
    porte_and(scene,150,50);
    porte_and(scene,50,100);
    porte_and(scene,150,150);
    porte_and(scene,50,200);
    porte_and(scene,150,250);
    porte_and(scene,50,300);

    QGraphicsTextItem *texte = new QGraphicsTextItem("CIRCUIT 1");
    texte->setDefaultTextColor(Qt::red);
    texte->setPos(10,200);
    scene.addItem(texte);

    QGraphicsView view(&scene);
    view.setWindowTitle("Ma fenetre ");
    view.resize(400,400);
    view.show();
    

    return app.exec();
}

