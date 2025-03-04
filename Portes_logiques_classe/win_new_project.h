#ifndef __WIN_NEW_PROJECT_H__
#define __WIN_NEW_PROJECT_H__
#include <QDialog>
#include <QLineEdit>
#include <QFormLayout>
#include <QPushButton>
#include <QString>
#include <QMainWindow>
#include <QIODevice>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include "MainWindow.h"
#include <QDataStream>

class win_new_project : public QDialog
{
    public :
        win_new_project();
        QString get_project_name();
        QString get_project_path();
        void bt_next_clic();
        void bt_next_clic_2();

    private:
        QLineEdit *input_new_project_name = new QLineEdit(this);
        QLineEdit *input_new_project_path = new QLineEdit(this);
        QFormLayout *layout_new_project = new QFormLayout(this);
        QPushButton *bt_next = new QPushButton("Next",this);
        QFile *fichier;
        QFile *fichier_2;
        MainWindow schematic_win ;
        
     signals:
        void update_recent_project(); 
};


#endif