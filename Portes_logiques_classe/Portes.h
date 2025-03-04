#ifndef __PORTES_H__
#define __PORTES_H__

#include <string>

class Portes
{
    public:
      Portes();
      void setIn1(bool val1);
      void setIn2(bool val2);
      virtual bool getOut();
      virtual ~Portes() = default;
    protected:
      bool in1;
      bool in2;
      bool out;

};


#endif