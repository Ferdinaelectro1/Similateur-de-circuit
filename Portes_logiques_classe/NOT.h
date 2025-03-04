#ifndef __NOT_H__
#define __NOT_H__
#include "Portes.h"

class NOT : public Portes
{
    public:
        NOT();
        bool getOut() override;

};


#endif