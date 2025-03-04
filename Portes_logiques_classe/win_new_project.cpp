#include "win_new_project.h"
#include <QDebug>

win_new_project::win_new_project()
{
    //ajout des info dans la layout et des bouttons
    layout_new_project->addRow("&Enter project Name : ",input_new_project_name);
    layout_new_project->addRow("&Enter project path    : ",input_new_project_path);
    layout_new_project->insertRow(3,bt_next);

    //ajout du layout à la QDialog
    setLayout(layout_new_project);

    //info fenetre de dialogue
/*     QColor color(Qt::gray);
    setPalette(QPalette(color)); */
    resize(640,480);
    setWindowTitle("New Project");
    
    //connexion au slot
    QObject::connect(bt_next,&QPushButton::clicked,this,&win_new_project::bt_next_clic);

    //gestion de fichier d'informations projets
    fichier = new QFile("info_project.txt",this);
    fichier_2 = new QFile("recent_project.bin");
    
}

//retourne le nom du projet
QString win_new_project::get_project_name()
{
    return input_new_project_name->text();
}

//lorsque le boutton next est cliqué ça créé une nouvelle fenetre schematic 
void win_new_project::bt_next_clic()
{
    //la fenetre schematic prend pour titre le nom du projet
    schematic_win.setWindowTitle("bilogis - " + get_project_name());
    schematic_win.resize(1800,900);
    schematic_win.show();

    //écriture des informations du projet dans le fichier 
    QTextStream flux(fichier);
    QDataStream flux_2(fichier_2);
    QDateTime temps = QDateTime::currentDateTime();
    if (fichier->open(QIODevice::Append))
    {
        flux << "Project "<<": "<<"Name : "<< get_project_name() <<" , Date : "<<temps.date().day()<<"/"<< temps.date().month()<<
        "/"<<temps.date().year()<<" , Temps : "<< temps.time().hour()<<":"<<temps.time().minute()<<":"<<temps.time().second()<< "\n" ;
    }
    if (fichier_2->open(QIODevice::Append))
    {
        flux_2 << get_project_name();
    }
    fichier_2->close();
    fichier->close();

    //emit(update_recent_project());
    qDebug() << "Signal émit"; 
    //détruit la fenetre de dialogue après le clic sur le next
    win_new_project::close();  
}

/* void win_new_project::update_recent_project(){} */

void win_new_project::bt_next_clic_2()
{

}