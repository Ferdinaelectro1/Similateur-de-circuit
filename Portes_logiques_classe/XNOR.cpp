#include "XNOR.h"

XNOR::XNOR(){
    out = !((in1 || in2) && (!in1 || !in2));
}

bool XNOR::getOut() 
{
    out = !((in1 || in2) && (!in1 || !in2));
    return out;
} 