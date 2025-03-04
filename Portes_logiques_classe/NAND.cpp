#include "NAND.h"
#include <iostream>

NAND::NAND(){
    out = !(in1 && in2);
};

bool NAND::getOut()
{
    out = !(in1 && in2);
    return out;
} 
