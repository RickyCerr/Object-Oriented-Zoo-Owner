#ifndef ANIMAL_H
#define ANIMAL_H

#include <ctime>
#include <string>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>

#include <iostream>

using namespace std;

class Animal {
  private:
  protected:
      int age;
      int purchase_cost;
      int litter_size;
      int food_cost;
      int food_multiplier;
      int monthly_revenue;
  public:
      Animal();
      Animal(const Animal &animal2);
      ~Animal();

      int get_age() const;
      int get_purchase_cost() const;
      int get_litter_size() const;
      int get_food_cost() const;
      int get_food_multiplier() const;
      int get_monthly_revenue() const;

      void set_age(int x);
      void set_purchase_cost(int x);
      void set_litter_size(int x);
      void set_food_cost(int new_cost);
      void set_food_multiplier(int x);
      void set_monthly_revenue(int x);
};

#endif
