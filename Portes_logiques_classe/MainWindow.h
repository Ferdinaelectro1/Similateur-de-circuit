#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMainWindow>
#include <QStatusBar>
#include <QDebug>
#include "AndFront.h"
#include "OrFront.h"
#include "NotFront.h"
#include "Circuit.h"
#include "AND.h"
#include "OR.h"
#include "NOT.h"
#include "NAND.h"
#include "NandFront.h"
#include "CircuitFront.h"

//classe de la fenêtre principale qui hérite de QMainWindow afin de pouvoir contenir des Widgets et un graphicsView dans une seule fenêtre
class MainWindow : public QMainWindow
{
public:
    MainWindow(QWidget *parent = nullptr);

private:
    //Scene qui va contenir le circuit électrique 
    Circuit schematic;
    CircuitFront schematicFront;
    QGraphicsView *view;
    qint8 m_porte_numero;
    bool mouseTracking;
    //Méthodes pour ajouter une porte and dans la fenêtre principale  et dans le backend
    void addPortes_and()
    {
        //Portes à ajouter dans la scene 
        PortesFront *and_symbole = new PortesFront("AND.svg");
        mouseTracking = 1;
        if(!view->hasMouseTracking())
        {
          view->setMouseTracking(true);
          schematicFront.addPorteToCircuit(and_symbole,mouseTracking,m_porte_numero);
        }
        else
        {
            schematicFront.addPorteToCircuit(and_symbole,mouseTracking,m_porte_numero);
        }
        AND and_porte;
        schematic.addPortes(and_porte,"AND");
        m_porte_numero++;
        //qDebug() << m_porte_numero;
    }

    //Méthodes pour ajouter une porte OR dans la fenêtre principale et dans le backend
 /*    void addPortes_or()
    {
        //Portes à ajouter dans la scene 
        OrFront *porte = new OrFront();
        scene->addItem(porte);
        OR or_porte;
        schematic.addPortes(or_porte,"OR");
    }
*/
    void addPortes_not()
    {
        mouseTracking = 1;
        PortesFront *not_ = new PortesFront("NOT.svg");
        if(!view->hasMouseTracking())
        {
          view->setMouseTracking(true);
          schematicFront.addPorteToCircuit(not_,view->hasMouseTracking(),m_porte_numero);
        }
        else
        {
            schematicFront.addPorteToCircuit(not_,mouseTracking,m_porte_numero);
        }
        NOT not_porte;
        schematic.addPortes(not_porte,"NOT");
        m_porte_numero++;
    }

    void addPortes_nand()
    {
        mouseTracking = 1;
        PortesFront *nand = new PortesFront("NAND.svg");
        //si la tracking de la souris n'est pas activé , on l'active, sinon on appel juste la méthode 
        //addPortesToCircuit pour ajouter la porte au circuit
        if(!view->hasMouseTracking())
        {
          view->setMouseTracking(true);
          schematicFront.addPorteToCircuit(nand,view->hasMouseTracking(),m_porte_numero);
        }
        else
        {
          schematicFront.addPorteToCircuit(nand,view->hasMouseTracking(),m_porte_numero);
        }
        NAND nand_porte;
        schematic.addPortes(nand_porte,"NAND");
        m_porte_numero++;
    }  
   
};

#endif