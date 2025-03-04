#include <QCoreApplication>
#include <QDebug>
#include <QList>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc,argv);
    QList<int> list;
    list.push_front(5);
    list.push_front(9);
    list.push_front(2);
    qDebug() << list[0];
    qDebug() << list[1];
    qDebug() << list[2];
    return 0;
}
