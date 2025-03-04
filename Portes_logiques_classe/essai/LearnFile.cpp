#include <iostream>
#include <QIODevice>
#include <QFile>
#include <QTextStream>
#include <QDebug>

int main()
{
    QFile fichier("note.txt");
    QTextStream flu(&fichier);
    QString ligne_fichier;

    if(fichier.open(QIODevice::ReadWrite))
    {
        ligne_fichier = flu.readLine();
        qDebug() << ligne_fichier;
    }

    fichier.close();

    return 0;
}