#ifndef __XNOR_H__
#define __XNOR_H__
#include "Portes.h"

class XNOR : public Portes
{
    public:
        XNOR();
        bool getOut() override;

};

#endif