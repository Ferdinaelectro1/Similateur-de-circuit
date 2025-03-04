#include "NOT.h"

NOT::NOT()
{
    out = (!in1 | !in2);
}

bool NOT::getOut()
{
    out = (!in1 | !in2);
    return out;
}