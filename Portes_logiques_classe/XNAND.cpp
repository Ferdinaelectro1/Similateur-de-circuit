#include "XNAND.h"

XNAND::XNAND(){
    out = !((in1 && in2) || (!in1 && !in2));
}

bool XNAND::getOut()
{
    out = !((in1 && in2) || (!in1 && !in2));
    return out;
} 