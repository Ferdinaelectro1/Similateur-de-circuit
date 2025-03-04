#include "XNOR.h"
#include "XAND.h"
#include "XNAND.h"
#include "XOR.h"
#include "NAND.h"
#include "NOR.h"
#include "AND.h"
#include "OR.h"
#include "NOT.h"

#include <iostream>

int main()
{
    XNOR p1;
    XAND p2;
    XNAND p3;
    XOR p4;
    NAND p5;
    NOR p6;
    AND p7;
    OR p8;
    NOT p9;
    bool in1 = 0;
    bool in2 = 0;
    std::cout<< in1 << " XNOR "<<in2<<" = "<< p1.getOut()<< std::endl;
    std::cout<< in1 << " XAND "<<in2<<" = "<< p2.getOut()<< std::endl;
    std::cout<< in1 << " XNAND "<<in2<<" = "<< p3.getOut()<< std::endl;
    std::cout<< in1 << " XOR "<<in2<<" = "<< p4.getOut()<< std::endl; 
    std::cout<< in1 << " NAND "<<in2<<" = "<< p5.getOut()<< std::endl;
    std::cout<< in1 << " NOR "<<in2<<" = "<< p6.getOut()<< std::endl;
    std::cout<< in1 << " AND "<<in2<<" = "<< p7.getOut()<< std::endl;
    std::cout<< in1 << " OR "<<in2<<" = "<< p8.getOut()<< std::endl; 
    std::cout<< in1<< " NOT "<<" = "<< p9.getOut()<< std::endl;
     std::cout<< in2<< " NOT "<<" = "<< p9.getOut()<< std::endl;
    return 0;
}