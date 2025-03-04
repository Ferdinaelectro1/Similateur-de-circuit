#include <iostream>
#include <QApplication>
#include <QDialog>
#include <QInputDialog>
#include <QColorDialog>
#include <QFontDialog>
#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QList>

class MyDialog : public QDialog
{
    public:
    MyDialog();
      
};

class Win : public QMainWindow
{
    public:
      Win(QWidget *parent = nullptr);
      void afficher_color();
      void afficher_font();
      void afficher_input();
    
    private:
      QPushButton  *bt_input;
      QPushButton  *bt_color;
      QPushButton  *bt_font;
      QInputDialog *dialog_entre;
      QColorDialog *dialog_color;
      QFontDialog  *dialog_font;   
      QHBoxLayout  *layout;
};


int main(int argc, char *argv[])
{
    QApplication app(argc,argv);

    Win windows;
    windows.show();

    return app.exec();
}

MyDialog::MyDialog(){}

Win::Win(QWidget *parent) : QMainWindow(parent)
{
    bt_input = new QPushButton("Input");
    bt_font = new QPushButton("Font");
    bt_color = new QPushButton("Color");
    layout = new QHBoxLayout();
    dialog_color = new QColorDialog;
    dialog_entre = new QInputDialog;
    dialog_font = new QFontDialog;
    layout->addWidget(bt_color);
    layout->addWidget(bt_font);
    layout->addWidget(bt_input);
    QWidget *widg = new QWidget;
    widg->setLayout(layout);

    //connexion des bouttons
    QObject::connect(bt_color,&QPushButton::clicked,this,&Win::afficher_color);
    QObject::connect(bt_font,&QPushButton::clicked,this,&Win::afficher_font);
    QObject::connect(bt_input,&QPushButton::clicked,this,&Win::afficher_input);

    setCentralWidget(widg); 
    setWindowTitle("Fenetre de test");
    resize(1800, 900);
}

void Win::afficher_color()
{
    dialog_color->show();
}

void Win::afficher_font()
{
    dialog_font->show();
}

void Win::afficher_input()
{
    dialog_entre->show();
}