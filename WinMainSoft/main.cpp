#include "mainwinsoft.h"
#include <QApplication>
#include <QtGui>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWinSoft w;
    w.show();
    return a.exec();
}
