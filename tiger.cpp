#include <ctime>
#include <string>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <iostream>
#include "animal.h"
#include "tiger.h"

using namespace std;


/***********************************************

      ** Big 3 for Tiger class **

***********************************************/


Tiger::Tiger(){
  set_age(0);
  set_purchase_cost(15000);
  set_litter_size(3);
  set_food_cost(0);
  set_food_multiplier(5);
  set_monthly_revenue(1500); //*******add bonus revenue as a parameter, this will only come into play for sea lion

  //cout << "\nTiger constructor called" << endl;
}


Tiger::Tiger(const Tiger &tiger2)
{
  age = tiger2.age;
  purchase_cost = tiger2.purchase_cost;
  litter_size = tiger2.litter_size;
  food_cost = tiger2.food_cost;
  food_multiplier = tiger2.food_multiplier;
  monthly_revenue = tiger2.monthly_revenue;

  //cout << "\nTiger copy constructor called" << endl;
}


Tiger::~Tiger()
{
    //cout << "\nTiger destructor called" << endl;
}
