#include <QTimer>
#include <QCoreApplication>
#include <QDebug>

class Hello
{
    public:
      Hello();
      void afficher_fin();
};
int main(int argc, char *argv[])
{
    QCoreApplication app(argc,argv);
    QTimer *timer = new QTimer;
    Hello hell;
    timer->setInterval(5000);
    QObject::connect(timer,&QTimer::timeout,&hell,&Hello::afficher_fin);
    return 0;
}

Hello::Hello(){}

void Hello::afficher_fin()
{
    qDebug() << "Le temps est fini !";
}