#ifndef __XNAND_H__
#define __XNAND_H__
#include "Portes.h"

class XNAND : public Portes
{
    public:
        XNAND();
        bool getOut();
};

#endif