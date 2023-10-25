#ifndef SEALION_H
#define SEALION_H

#include <ctime>
#include <string>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>

#include <iostream>

using namespace std;

class Sealion : public Animal{
  private:
      int bonus_revenue;

  public:
      Sealion();
      Sealion(const Sealion &sealion2);
      ~Sealion();

      int get_bonus_revenue();

      void set_bonus_revenue();
};

#endif
