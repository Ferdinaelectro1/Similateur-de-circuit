#include "NOR.h"

NOR::NOR(){
    out = !(in1 || in2);
}

bool NOR::getOut()
{
    out = !(in1 || in2);
    return out;
} 
