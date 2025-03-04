#ifndef __OR_H__
#define __OR_H__
#include "Portes.h"

class OR : public Portes
{
    public:
      OR();
      bool getOut() override;
    
};

#endif