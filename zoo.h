#ifndef ZOO_H
#define ZOO_H

#include <ctime>
#include <string>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <iostream>

#include "animal.h"
#include "sealion.h"
#include "bear.h"
#include "tiger.h"

using namespace std;

class Zoo{
  private:
      Sealion *sealions;
      Blackbear *blackbears;
      Tiger *tigers;

      int num_sealions;
      int num_blackbears;
      int num_tigers;

      int account_money;
      int month_number;

  public:
      Zoo();
      Zoo(const Sealion &sealion2);
      ~Zoo();

      int get_num_sealions();
      int get_num_blackbears();
      int get_num_tigers();
      int get_account_money();

      void set_num_sealions(int x);
      void set_num_blackbears(int x);
      void set_num_tigers(int x);

      void buy_sealion(int new_num_sealions);
      void buy_blackbear(int new_num_blackbears);
      void buy_tiger(int new_num_tigers);

      void kill_sealion();
      void kill_blackbear();
      void kill_tiger();

      void birth_sealion();
      void birth_blackbear();
      void birth_tiger();

      void print_zoo();
      void print_sealions();
      void print_blackbears();
      void print_tigers();

      void zoo_main();
      void random_event();
      void set_monthly_cost();
      int get_total_monthly_cost();
      int get_total_monthly_revenue(int is_special_event);
      int get_randomnum();
      int get_randomnum2();
      void increment_age();
};

#endif
