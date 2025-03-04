#include <iostream>
#include <string>
#include "OR.h"
#include "AND.h"
#include "XAND.h"
#include "NAND.h"
#include "XOR.h"
#include "XNOR.h"
#include "Circuit.h"

int main()
{
    OR p1;
    NAND p2;
    //NAND p3;
    Circuit c;

    int repeat = 1;
    bool a;
    bool b;
    bool cb;
    std::string flux;

    c.addPortes(p1,"XNOR");
    c.addPortes(p2,"NAND");
    //c.addPortes(p3,"NAND");

    do {
        std::cout << "Entrez la valeur de a : ";
        std::cin >> a;
        std::cout << "   "<<std::endl;
        std::cout << "Entrez la valeur de b : ";
        std::cin >> b;
        std::cout << "    "<<std::endl;
        std::cout << "Entrez la valeur de c : ";
        std::cin >> cb;

        c.setInValue(0,1,a);
        c.setInValue(0,2,b);
        c.setInValue(1,2,cb);

        c.connect(1,1,0);

        std::cout<<"      "<<std::endl;
        std::cout<< "taille = " << c.getsize() << std::endl;
        std::cout << "Sortie du circuit = "<<c.getOutCircuit(1)<<std::endl;
        //std::cout << "Sortie de OR = "<<c.getOutCircuit(0)<<std::endl;

        std::cout << "Voulez vous continuez ? Si oui cliquez entrez  'oui' "<< std::endl;
        std::cin >> flux;
        if ( flux == "oui")
        {
            repeat = 1;
        }      
        else
        {
            repeat = 0;            
        }  
    } while (repeat);
    
    //c.connect(0,2,1);


    //std::cout << "Sortie AND p2 = "<<c.getOutCircuit(1)<<std::endl;
    //std::cout << "Sortie OR p3 = "<<c.getOutCircuit(0)<<std::endl;    
 
    return 0;
}
