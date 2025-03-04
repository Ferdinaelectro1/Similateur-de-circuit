#include "XOR.h"

XOR::XOR(){
    out = ((in1 || in2) && (!in1 || !in2));
}

bool XOR::getOut()
{
    out = ((in1 || in2) && (!in1 || !in2));
    return out;
} 