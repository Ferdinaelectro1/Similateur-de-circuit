#include <iostream>
#include <QApplication>
#include <QMainWindow>
#include <QLineEdit>
#include <QFormLayout>
#include <QMdiArea>
#include <QTextEdit>
#include <QMdiSubWindow>
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QTreeView>
#include <QFileSystemModel>
#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>

class ma_win : public QMainWindow
{
    public : 
      ma_win();
};

class mdi : public QMainWindow
{
    public : 
      mdi();
};

class window : public QMainWindow
{
    public : 
    window();
};

class fichier : public QMainWindow
{
    public : 
      fichier();
};

int main(int argc , char *argv[])
{
    QApplication app(argc,argv);
    
    window win;
    win.show();

    return app.exec();
}


ma_win::ma_win()
{
    QWidget *centralWidg = new QWidget;
    QLineEdit *name = new QLineEdit;
    QLineEdit *password = new QLineEdit;
    QFormLayout *layout = new QFormLayout;
    layout->addRow("&Entrez votre nom : ", name);
    layout->addRow("&Entrez votre mot de passe : ", password);
    centralWidg->setLayout(layout);
    setCentralWidget(centralWidg);
    setWindowTitle("Fenetre de saisi");
}

mdi::mdi()
{
    QMdiArea *mdi_apk = new QMdiArea;
    
    QTextEdit *edit1 = new QTextEdit;
    QTextEdit *edit2 = new QTextEdit;

    QMdiSubWindow *sub1 = mdi_apk->addSubWindow(edit1);
    QMdiSubWindow *sub2 = mdi_apk->addSubWindow(edit2);

    mdi_apk->setViewMode(QMdiArea::TabbedView);
    setCentralWidget(mdi_apk);
    setWindowTitle("Application Mdi ");
}

window::window()
{
    QMenu *menu_file = new QMenu("&File",this);
    QMenu *menu_edit = new QMenu("&Edit",this);
    QMenu *menu_view = new QMenu("&View",this);
    QMenu *menu_tools = new QMenu("&Tools",this);
    QMenu *menu_help = new QMenu("&Help",this);

    menuBar()->addMenu(menu_file);
    menuBar()->addMenu(menu_edit);
    menuBar()->addMenu(menu_view);
    menuBar()->addMenu(menu_tools);
    menuBar()->addMenu(menu_help);


}

fichier::fichier()
{
    QWidget *centralWidget = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout;

    QTreeView *vue_arbre = new QTreeView;
    QPushButton *bt = new QPushButton("Ouvrir",this);
    QFileSystemModel *fichier_sys = new QFileSystemModel;
    fichier_sys->setRootPath(QDir::currentPath());
    vue_arbre->setModel(fichier_sys);

    layout->addWidget(vue_arbre);
    layout->addWidget(bt);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
    setWindowTitle("Fenetre fichier");
    resize(640,480);
}