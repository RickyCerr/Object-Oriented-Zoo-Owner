#ifndef TIGER_H
#define TIGER_H

#include <ctime>
#include <string>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>

#include <iostream>

using namespace std;

class Tiger : public Animal{
  private:

  public:
      Tiger();
      Tiger(const Tiger &tiger2);
      ~Tiger();



};

#endif
