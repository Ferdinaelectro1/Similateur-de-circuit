#include <QApplication>
//#include "MainWindow.h"
#include "AndFront.h"
#include "apk_window.h"
#include "curs_pos.h"
#include "try_connexion.h"
#include <QGraphicsView>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

/*    Circuitscene windows;
    QGraphicsView view(&windows);
    
    windows.setSceneRect(0,0,500,500);

/*    view.show();*/
   /* MainWindow win;
    win.show();*/

    apk_window window;
    window.show(); 

    return app.exec();
}
