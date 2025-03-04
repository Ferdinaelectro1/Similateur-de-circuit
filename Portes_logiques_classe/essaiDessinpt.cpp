#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPathItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QHBoxLayout>
#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QMainWindow>
#include <QPushButton>
#include <iostream>

class ArcWindget : public QWidget
{
    protected:
    void paintEvent(QPaintEvent *event) override
    {
        QPainter painter(this);
        QPainterPath path;

        QRectF rect(50,50,200,200);
        //path.arcMoveTo(rect,0*16);
        //path.arcTo(rect,0,90*16);

        painter.setPen(QPen(Qt::black,2));

        path.moveTo(80,90);
        path.quadTo(10,150,20,100);

       // painter.drawArc(rect,90*16,-180*16);
       painter.drawPath(path);
       
    }
};

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);

    ArcWindget window;
    window.resize(300,300);

    window.setWindowTitle("Widget modifié avec un path");
    window.show();

    return app.exec();
}




/*
class MainWindow : public QMainWindow
{
public:
MainWindow(QWidget *parent = nullptr) : QMainWindow(parent), scene(new QGraphicsScene(this)) , path(new QPainterPath), nandGateGroup(new QGraphicsItemGroup()), nandShape(new QGraphicsPathItem(*path))
{
    size = 0;
    //Boutton permettant d'ajouter une porte and dans la fenêtre 
    QPushButton *bt_and = new QPushButton("+");
    connect(bt_and, &QPushButton::clicked, this, &MainWindow::augment);


    //path->moveTo(0, 0);              
    //augment();
    //QGraphicsPathItem* nandShape = new QGraphicsPathItem(*path);
    //nandShape->setBrush(QBrush(Qt::black));  // Remplissage en noir
    //nandShape->setPen(QPen(Qt::white, 2));

    //nandGateGroup->addToGroup(nandShape);

    //scene->addItem(nandGateGroup);
    MainWindow::augment();
    //QGraphicsView permettant d'afficher la scene
    QGraphicsView *view = new QGraphicsView(scene);
    //view.setRenderHint(QPainter::Antialiasing);
    view->resize(500, 500);

    //Box layout permettant de contenir le QGraphicsView et le widget boutton de façon horizontale
    QHBoxLayout *layout = new QHBoxLayout;
    QVBoxLayout *layout_vertical = new QVBoxLayout;

    layout_vertical->addWidget(bt_and);   
    layout->addLayout(layout_vertical);
    layout->addWidget(view);

    //Widget centrale de la Fenêtre le layout créée 
    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    //titre et dimensions de la fenêtre
    setWindowTitle("Bilogis");
    resize(1800, 900);
}

private:
   QPainterPath *path;
   QGraphicsPathItem *nandShape;
   QGraphicsItemGroup *nandGateGroup;
   QGraphicsScene *scene;
   int size;

   void augment()
   {
    size += 100;
    std::cout << "passer " << size <<  std::endl;
    path->moveTo(0, 0);
    path->arcTo(0, 0, 400, 400, 400, size);
    nandShape->setBrush(QBrush(Qt::black));  // Remplissage en noir
    nandShape->setPen(QPen(Qt::white, 2));
    nandGateGroup->addToGroup(nandShape);
    scene->addItem(nandGateGroup);
   }
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow win;
    win.show();

    return app.exec();
}

*/