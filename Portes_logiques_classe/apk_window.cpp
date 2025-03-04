#include "apk_window.h"
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QApplication>
#include <QFileDialog>
#include <iostream>
#include <QMainWindow>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include <QDebug>
#include <QDataStream>
#include <QStatusBar>

apk_window::apk_window()
{
    //Initialisation des attributs
    dialog_color = new QColorDialog(this);

    //creation des menus
    QMenu *menu_file  = new QMenu("&File",this);
    QMenu *menu_edit  = new QMenu("&Edit",this);
    QMenu *menu_view  = new QMenu("&View",this);
    QMenu *menu_tools = new QMenu("&Tools",this);
    QMenu *menu_help  = new QMenu("&Help",this);

    //ajout des menus à la barre de menu de la fenetre
    menuBar()->addMenu(menu_file);
    menuBar()->addMenu(menu_edit);
    menuBar()->addMenu(menu_view);
    menuBar()->addMenu(menu_tools);
    menuBar()->addMenu(menu_help);

    //creation des actions du menu file et ajout des ses actions
    QAction *action_new_project    = new QAction("New Projects",this);
    menu_recent_project = new QMenu("Recent Projects",this);
    QAction *action_open_project   = new QAction("Open Projects",this);
    QAction *action_save_project   = new QAction("Save Projects",this);
    QAction *action_preferences    = new QAction("Preferences",this);
    QAction *action_quit           = new QAction("Quit",this);
    menu_file->addAction(action_new_project);
    menu_file->addMenu(menu_recent_project);
    menu_file->addAction(action_open_project);
    menu_file->addAction(action_save_project);
    menu_file->addAction(action_preferences);
    menu_file->addAction(action_quit);
    
    //ajout des projets récents au menu recent_project
    menu_recent_project->addActions(recent_project_list());

    //creation des actions du menu Edit
    QAction *action_copy  = new QAction("Copy",this);
    QAction *action_cut   = new QAction("Cut",this);
    QAction *action_paste = new QAction("Paste",this);
    menu_edit->addAction(action_copy);
    menu_edit->addAction(action_cut);
    menu_edit->addAction(action_paste);

    //creation des actions du menu View 
    QAction *action_theme = new QAction("Theme",this);
    QAction *action_resize = new QAction("Resize",this);
    menu_view->addAction(action_theme);
    menu_view->addAction(action_resize);

    //creation des actions du menu Tools
    QMenu *menu_schematic_tools =  menu_tools->addMenu("Schematic Tools");
    QAction *action_components_manage = new QAction("Components Manage",this);
    QAction *action_spice_model       = new QAction("Spice Model",this);
    menu_schematic_tools->addAction(action_components_manage);
    menu_schematic_tools->addAction(action_spice_model);
    
    QMenu *menu_simulator_tools = menu_tools->addMenu("Simulator Tools");
    QAction *action_configurations = new QAction("Configurations",this);
    QAction *action_step_by_step = new QAction("Step by Step Simulation",this);
    menu_simulator_tools->addAction(action_configurations);
    menu_simulator_tools->addAction(action_step_by_step);

    QAction *action_settings = new QAction("Settings",this);
    menu_tools->addAction(action_settings);

    //creation des actions du menu help
    QAction *action_apropos = new QAction("À Propos",this);
    action_apropos->setIcon(QIcon("icon_fer.jpg"));
    QAction *action_manual  = new QAction("Manual",this);
    QAction *action_website = new QAction("WebSite",this);
    menu_help->addAction(action_apropos);
    menu_help->addAction(action_manual);
    menu_help->addAction(action_website);

    //conexion des actions
    QObject::connect(action_quit,&QAction::triggered,this,&apk_window::quit);
    QObject::connect(action_open_project,&QAction::triggered,this,&apk_window::open_project_action);
    QObject::connect(action_new_project,&QAction::triggered,this,&apk_window::new_projects_action);
    QObject::connect(action_theme,&QAction::triggered,this,&apk_window::theme_change);
    //QObject::connect(&win_project_new,&win_new_project::update_recent_project,this,&apk_window::update_apk_recent);

    //configurations du treeview
    treeview->setMaximumHeight(1200);
    treeview->setMaximumWidth(500);

    //widget centrale
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(splitter);
    splitter->addWidget(treeview);
    splitter->addWidget(centralWidget);

    //statusBar()->setStyleSheet("background-color : blue;");
    QStatusBar *bar_status = new QStatusBar(this);
    bar_status->showMessage("Welcome in Bilogis");
    setStatusBar(bar_status);

    //info sur la fenetre
    //QColor color(Qt::gray);
    //setPalette(QPalette(color)); 
    setWindowTitle("Bilogis");
    //showFullScreen();
    resize(1800, 900);


}

//fonctions slot
void apk_window::quit()
{
    delete menu_recent_project;
    delete dialog_color;
    QApplication::quit();
}

//fonction permettant d'ouvrir un projet existant
void apk_window::open_project_action()
{
    QUrl project = QFileDialog::getExistingDirectory(this,"Open Folder","/",QFileDialog::ShowDirsOnly);
    model->setRootPath(project.toString());
    treeview->setModel(model);
    treeview->setRootIndex(model->index(project.toString()));
    treeview->hideColumn(1);
    treeview->hideColumn(2);
    treeview->hideColumn(3);
}

void apk_window::new_projects_action()
{ 
    win_project_new.show();
}

//cette fonction permet de retourner une liste des actions dont le nom  
// correspond au projet recemment placer dans le fichier binaire recent_project.bin
// il lis le fichier jusqu'à la fin (à la fin on trouve le caractère : "")
QList<QAction *> apk_window::recent_project_list()
{
    QFile *fichier_bin = new QFile("recent_project.bin",this);
    QDataStream flux(fichier_bin);
    QString project_name = "Nom";
    QList<QAction *> list_projets_recent;
    if (fichier_bin->open(QIODevice::ReadOnly))
    {
        do
        {
            flux >> project_name;
            QAction *recent = new QAction(project_name,this);
            if (project_name != "")
            {
            list_projets_recent.push_front(recent);
            //qDebug() << "Nom du projet : "<< project_name;
            }    
        }   
        while (project_name != "");   
    }
    fichier_bin->close();
    return list_projets_recent;
}

void apk_window::update_apk_recent()
{
    menu_recent_project->addActions(recent_project_list());   
}

void apk_window::theme_change()
{
    QColor color = dialog_color->getColor();
    setPalette(QPalette(color));
    treeview->setPalette(QPalette(color));
    //dialog_color->show();
/*     if (styleSheet() == "background-color : blue;")
    setStyleSheet("background-color : white;");
    else
    setStyleSheet("background-color : blue;"); */
}