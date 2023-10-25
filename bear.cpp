#include <ctime>
#include <string>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <iostream>
#include "animal.h"
#include "bear.h"

using namespace std;


/***********************************************

      ** Big 3 for Black Bear class **

***********************************************/


Blackbear::Blackbear(){
  set_age(0);
  set_purchase_cost(6000);
  set_litter_size(2);
  set_food_cost(0);
  set_food_multiplier(3);
  set_monthly_revenue(600);

  //cout << "\nBlack Bear constructor called" << endl;
}


Blackbear::Blackbear(const Blackbear &blackbear2)
{
  age = blackbear2.age;
  purchase_cost = blackbear2.purchase_cost;
  litter_size = blackbear2.litter_size;
  food_cost = blackbear2.food_cost;
  food_multiplier = blackbear2.food_multiplier;
  monthly_revenue = blackbear2.monthly_revenue;

  //cout << "\nBlack Bear copy constructor called" << endl;
}


Blackbear::~Blackbear()
{
    //cout << "\nBlack Bear destructor called" << endl;
}
