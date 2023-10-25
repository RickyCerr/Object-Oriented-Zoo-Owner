#ifndef BLACKBEAR_H
#define BLACKBEAR_H

#include <ctime>
#include <string>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>

#include <iostream>

using namespace std;

class Blackbear : public Animal{
  private:

  public:
      Blackbear();
      Blackbear(const Blackbear &blackbear2);
      ~Blackbear();



};

#endif
