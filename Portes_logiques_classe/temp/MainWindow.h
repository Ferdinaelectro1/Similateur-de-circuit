#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__
#include <QWidget>
#include <QGraphicsScene>
#include <QMainWindow>
#include <QStatusBar>
#include "AndFront.h"
#include "OrFront.h"
#include "NotFront.h"
#include "Circuit.h"
#include "AND.h"
#include "OR.h"
#include "NOT.h"
#include "NandFront.h"

//classe de la fenêtre principale qui hérite de QMainWindow afin de pouvoir contenir des Widgets et un graphicsView dans une seule fenêtre
class MainWindow : public QMainWindow
{
public:
    MainWindow(QWidget *parent = nullptr);

private:
    //Scene qui va contenir le circuit électrique 
    QGraphicsScene *scene;
    Circuit schematic;
    
    //Méthodes pour ajouter une porte and dans la fenêtre principale  et dans le backend
    void addPortes_and()
    {
        //Portes à ajouter dans la scene 
        AndFront *porte = new AndFront();
        scene->addItem(porte);
        AND and_porte;
        schematic.addPortes(and_porte,"AND");
    }

    //Méthodes pour ajouter une porte OR dans la fenêtre principale et dans le backend
    void addPortes_or()
    {
        //Portes à ajouter dans la scene 
        OrFront *porte = new OrFront();
        scene->addItem(porte);
        OR or_porte;
        schematic.addPortes(or_porte,"OR");
    }

    void addPortes_not()
    {
        NotFront *porte = new NotFront();
        scene->addItem(porte);
        NOT not_porte;
        schematic.addPortes(not_porte,"NOT");
    }

    void addPortes_nand()
    {
        NandFront *porte = new NandFront();
        scene->addItem(porte);
        scene->update();
    } 
   
};

#endif