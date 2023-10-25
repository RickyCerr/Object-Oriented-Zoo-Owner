#include <ctime>
#include <string>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <iostream>
#include "animal.h"

using namespace std;


/***********************************************

      ** Big 3 for Animal class **

***********************************************/


Animal::Animal()
{
  set_age(0);
  set_purchase_cost(0);
  set_litter_size(0);
  set_food_cost(0);
  set_food_multiplier(0);
  set_monthly_revenue(0);

  //cout << "\nAnimal constructor called" << endl;
}


Animal::Animal(const Animal &animal2)
{
  age = animal2.age;
  purchase_cost = animal2.purchase_cost;
  litter_size = animal2.litter_size;
  food_cost = animal2.food_cost;
  food_multiplier = animal2.food_multiplier;
  monthly_revenue = animal2.monthly_revenue;

  //cout << "\nAnimal copy constructor called" << endl;
}


Animal::~Animal()
{
    //cout << "\nAnimal destructor called" << endl;
}


/***********************************************

** Getters for data members of Animal class **

***********************************************/


int Animal::get_age() const
{
    return age;
}


int Animal::get_purchase_cost() const
{
    return purchase_cost;
}


int Animal::get_litter_size() const
{
    return litter_size;
}


int Animal::get_food_cost() const
{
    return food_cost;
}


int Animal::get_food_multiplier() const
{
    return food_multiplier;
}


int Animal::get_monthly_revenue() const
{
    return monthly_revenue;
}


/***********************************************

** Setters for data members of Animal class **

***********************************************/


void Animal::set_age(int x)
{
    age = x;                                                                    //Sets the base age to zero
}


void Animal::set_purchase_cost(int x)
{
    purchase_cost = x;                                                          //Sets the base cost to $0, it will later be adjusted based on which animal it is.
}


void Animal::set_litter_size(int x)
{
    litter_size = x;
}


void Animal::set_food_cost(int new_cost)
{                                                                               //new_cost is based on a function that determines the base cost for all animals that month (varies month to month)
    food_cost = new_cost * food_multiplier;                                     //food_multiplier is based on each specific animal eg: Tigers have a monthly food cost of 5 times the base food cost, so for tiger: food_multiplier = 5
}


void Animal::set_food_multiplier(int x)
{                                                                               //new_cost is based on a function that determines the base cost for all animals that month (varies month to month)
    food_multiplier = x;                                                        //food_multiplier is based on each specific animal eg: Tigers have a monthly food cost of 5 times the base food cost, so for tiger: food_multiplier = 5
}


void Animal::set_monthly_revenue(int x)
{
    monthly_revenue = x;
}

//needs some way to figure out if its a baby, adolescent, or adult
//then based on that, set the age
