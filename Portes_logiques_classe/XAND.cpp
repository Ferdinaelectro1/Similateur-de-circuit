#include "XAND.h"

XAND::XAND(){
   out = ((in1 && in2) || (!in1 && !in2));
}

bool XAND::getOut()
{
    out = ((in1 && in2) || (!in1 && !in2));
    return out;
} 