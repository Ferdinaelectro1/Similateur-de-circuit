#ifndef __CIRCUIT_H__
#define __CIRCUIT_H__
#include "Portes.h"
#include <vector>
#include <string>
#include <memory>

class Circuit
{
    public:
      Circuit();
      void addPortes(Portes &p, std::string typ);
      bool getOutCircuit(int numero_portes);
      int getsize();
      void connect(int num_portes1, int broche_p1 , int num_portes2);
      void setInValue(int portes, int broche, bool value);

    private:
      std::vector<std::shared_ptr <Portes>> tab_portes;

};


#endif