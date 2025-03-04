#include "Portes.h"
#include <iostream>
#include <string>

Portes::Portes()
{ 
    out = 0;  
    in1 = 0;
    in2 = 0;
}


//retourne la valeur de la sortie de la porte
bool Portes::getOut()
{
    return 0;
}

//permet d'envoyer un signal (val1) à l'entrée 1
void Portes::setIn1(bool val1)
{
    in1 = val1;
}

////permet d'envoyer un signal (val2) à l'entrée 2
void Portes::setIn2(bool val2)
{
    in2 = val2;
}