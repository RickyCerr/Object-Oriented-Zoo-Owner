#include <ctime>
#include <string>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <iostream>
#include "animal.h"
#include "sealion.h"

using namespace std;


/***********************************************

      ** Big 3 for Sea Lion class **

***********************************************/


Sealion::Sealion(){
  set_age(0);
  set_purchase_cost(800);
  set_litter_size(1);
  set_food_cost(0);
  set_food_multiplier(1);
  set_monthly_revenue(120);
  bonus_revenue = 0;

  //cout << "\nSea Lion constructor called" << endl;
}


Sealion::Sealion(const Sealion &sealion2)
{
  age = sealion2.age;
  purchase_cost = sealion2.purchase_cost;
  litter_size = sealion2.litter_size;
  food_cost = sealion2.food_cost;
  food_multiplier = sealion2.food_multiplier;
  monthly_revenue = sealion2.monthly_revenue;

  //cout << "\nSea Lion copy constructor called" << endl;
}


Sealion::~Sealion()
{
    //cout << "\nSea Lion destructor called" << endl;
}


int Sealion::get_bonus_revenue()
{
    return bonus_revenue;
}


void Sealion::set_bonus_revenue()
{
    bonus_revenue = 0;
    srand(time(NULL));
    int randomizer = (rand() % 250 + 150);
    bonus_revenue += randomizer;
}
