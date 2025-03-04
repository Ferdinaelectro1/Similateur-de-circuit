#include "AND.h"

AND::AND()
{
    out = (in1 && in2);
}

bool AND::getOut()
{
    out = (in1 && in2);
    return out;
}