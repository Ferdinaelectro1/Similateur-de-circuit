#include "Circuit.h"
#include <iostream>
#include <string>
#include "XNOR.h"
#include "XAND.h"
#include "XNAND.h"
#include "XOR.h"
#include "NAND.h"
#include "NOR.h"
#include "AND.h"
#include "OR.h"
#include "NOT.h"

Circuit::Circuit()
{}

//Stocke un pointeur vers un objet de type porte dans le tableau dynamique
//elle permet d'ajouter une porte au circuit electrique 
void Circuit::addPortes(Portes &p, std::string typ)
{
    /*en fonction de la portes concernées on stockes une référence vers cette portes dans le tableau 
    de portes placées dans le circuit */
    if (typ == "XNOR")
    {
      tab_portes.push_back(std::make_shared<XNOR>());
    }
    else if (typ == "XAND")
    {
        tab_portes.push_back(std::make_shared<XAND>());
    }
    else if (typ == "XNAND")
    {
        tab_portes.push_back(std::make_shared<XNAND>());
    }
    else if (typ == "XOR")
    {
        tab_portes.push_back(std::make_shared<XOR>());
    }
    else if (typ == "NAND")
    {
        tab_portes.push_back(std::make_shared<NAND>());
    }
    else if (typ == "NOR")
    {
        tab_portes.push_back(std::make_shared<NOR>());
    }
    else if (typ == "AND")
    {
        tab_portes.push_back(std::make_shared<AND>());
        //std::cout << "AND ajouté \n";
    }
    else if (typ == "OR")
    {
        tab_portes.push_back(std::make_shared<OR>());
        //std::cout << "OR ajouté \n";
    }
    else if (typ == "NOT")
    {
        tab_portes.push_back(std::make_shared<NOT>());
        //std::cout << "NOT ajouté \n";
    }
    else
    {
        std::cerr << "Nom de portes inconnu " << std::endl;
    }    
}

//retourne la sortie de la portes numéro : numero_portes passées en paramètre
bool Circuit::getOutCircuit(int numero_portes)
{
    return tab_portes[numero_portes]->getOut();
}

//retourne la taille du tableau contenant les portes soite le nombre de portes placées dans le circuit 
int Circuit::getsize()
{
    return (std::size(tab_portes));
}

/// @brief 
/// @param num_portes1 premiere porte dont on veux utiliser pour faire la connexion (celle qui recoit la sortie de l'autre)
/// @param broche_p1 broche de cette porte  à conncter
/// @param num_portes2 deuxieme porte dont on veux utiliser pour faire la connexion 
/// @param broche_p2 broche de cette porte  à conncter
void Circuit::connect(int num_portes1, int broche_p1 , int num_portes2)
{
    //met la valeur de sortie de p2, sur la valeur d'entrée de p1
    switch (broche_p1)
    {
    case 1:
        tab_portes[num_portes1]->setIn1(tab_portes[num_portes2]->getOut());
        //std::cout <<"p.getout() = " << tab_portes[num_portes1].getOut()<< std::endl;
        break;
    case 2:
        tab_portes[num_portes1]->setIn2(tab_portes[num_portes2]->getOut());
        break;
    default:
        std::cerr <<"Erreur : Vous devez assigner la connexion à une broche d'entrée valide" << std::endl;
        break;
    }
}

/// @brief fonction pour faire passer un signal à l'entrée d'une porte 
/// @param portes Portes dont on veut placer un signal à son entrée 
/// @param broche Broches sur laquelle le signal serait passé
/// @param value valeur du signal à faire envoyer à l'entrée de la porte concernée 

void Circuit::setInValue(int portes, int broche, bool value)
{
    //si la broche est la broche 1 ou 2 on appele la fonction setIn1 (charger de placer un signal sur l'entrée 1 ou 2) à la 
    // portes concernées dans le tableau de portes placées dans circuit 
    if (broche == 1)
    {
        tab_portes[portes]->setIn1(value);
    }
    else if (broche == 2)
    {
        tab_portes[portes]->setIn2(value);
    }
    else
    {
        //si on veut assigner le signal à une broche entrée de porte inconnu on renvoie le message d'erreur
        std::cerr <<"Broche à assigner inexisante "<< std::endl;
    }    
}