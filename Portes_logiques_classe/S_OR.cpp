#include "OR.h"
#include <iostream>

OR::OR()
{
    out = (in1 || in2);
}


bool OR::getOut()
{
    out = (in1 || in2);
    return out;
}