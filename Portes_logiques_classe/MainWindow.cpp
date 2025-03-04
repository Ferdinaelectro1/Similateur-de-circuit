#include "MainWindow.h"
#include <QGraphicsScene>
#include <QHBoxLayout>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QWidget>
#include <QPushButton>


//constructeur de la fenêtre principale
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    m_porte_numero = 0;
    mouseTracking = 1;
    //Boutton permettant d'ajouter une porte AND dans la fenêtre 
    QPushButton *bt_and = new QPushButton("AND");
    connect(bt_and, &QPushButton::clicked, this, &MainWindow::addPortes_and);

/*     //Boutton permettant d'ajouter une porte OR dans la fenêtre 
    QPushButton *bt_or = new QPushButton("OR");
    connect(bt_or, &QPushButton::clicked, this, &MainWindow::addPortes_or);
*/
    //Boutton permettant d'ajouter une porte NOT dans la fenêtre 
    QPushButton *bt_not = new QPushButton("NOT");
    connect(bt_not, &QPushButton::clicked, this, &MainWindow::addPortes_not);

    //Boutton permettant d'ajouter une porte NAND dans la fenêtre 
    QPushButton *bt_nand = new QPushButton("NAND");
    connect(bt_nand, &QPushButton::clicked, this, &MainWindow::addPortes_nand); 

    //QGraphicsView permettant d'afficher la scene
    view = new QGraphicsView(&schematicFront);
    view->resize(500, 500);

    //Box layout permettant de contenir le QGraphicsView et le widget boutton de façon horizontale
    QHBoxLayout *layout = new QHBoxLayout;
    QVBoxLayout *layout_vertical = new QVBoxLayout;

    layout_vertical->addWidget(bt_and);
/*     layout_vertical->addWidget(bt_or);*/
    layout_vertical->addWidget(bt_not);    
    layout_vertical->addWidget(bt_nand); 
    layout->addLayout(layout_vertical);
    layout->addWidget(view);

    //Widget centrale de la Fenêtre le layout créée 
    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);


    //titre et dimensions de la fenêtre
    QStatusBar *bar_status = new QStatusBar(this);
    bar_status->showMessage("Circuit Editing");
    setStatusBar(bar_status);
    setWindowTitle("Bilogis");
    resize(1800, 900);
}

