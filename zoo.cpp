#include <ctime>
#include <string>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <iostream>
#include "zoo.h"

using namespace std;


/***********************************************

      ** Big 3 for Zoo class **

***********************************************/


Zoo::Zoo()                                                                                                                                                                           //Zoo constructor
{                                                                                                                                                                                    //Sets all of the animal object array pointers to null
    sealions = nullptr; //new Sealion[1000];                                                                                                                                         //Sets member data variables to zero
    blackbears = nullptr; //new Blackbear[1000];
    tigers = nullptr; //new Tiger[1000];

    num_sealions = 0;
    num_blackbears = 0;
    num_tigers = 0;

    account_money = 100000;
    month_number = 0;

    //cout << "\nZoo constructor called" << endl;

}


Zoo::~Zoo()                                                                                                                                                                          //Zoo destructor
{                                                                                                                                                                                    //deletes all of the animal object pointers
    delete [] sealions;
    delete [] blackbears;
    delete [] tigers;

    //cout << "\nZoo destructor called" << endl;
}


/***********************************************

** Getters for data members of Zoo class **

***********************************************/


int Zoo::get_num_sealions()                                                                                                                                                          //Gets number of sealions
{                                                                                                                                                                                    //Returns the zoo data variable number of sealions
    return num_sealions;
}


int Zoo::get_num_blackbears()                                                                                                                                                        //Gets number of black bears
{                                                                                                                                                                                    //Returns the zoo data variable number of black bears
    return num_blackbears;
}


int Zoo::get_num_tigers()                                                                                                                                                            //Gets number of tigers
{                                                                                                                                                                                    //Returns the zoo data variable number of tigers
    return num_tigers;
}

int Zoo::get_account_money()                                                                                                                                                         //Gets amount of money in account
{                                                                                                                                                                                    //Returns the zoo data variable amount of money in account
    return account_money;
}


/***********************************************

** Setters for data members of Zoo class **

***********************************************/


void Zoo::set_num_sealions(int x)                                                                                                                                                    //Set number of sealions
{                                                                                                                                                                                    //accepts a parameter x and sets the data member num_sealions to it
    num_sealions = x;
}


void Zoo::set_num_blackbears(int x)                                                                                                                                                  //Set number of black bears
{                                                                                                                                                                                    //accepts a parameter x and sets the data member num_blackbears to it
    num_blackbears = x;
}


void Zoo::set_num_tigers(int x)                                                                                                                                                      //Set number of tigers
{                                                                                                                                                                                    //accepts a parameter x and sets the data member num_tigers to it
    num_tigers = x;
}


/***********************************************

** Program related functions for Zoo class **

***********************************************/


void Zoo::zoo_main()                                                                                                                                                                 //Main function for zoo (runs and calls most of the program)
{                                                                                                                                                                                    //Starts off by printing the zoo, then prompting the user which animal they want to buy (or if they dont want to buy any animals). If the user chooses an animal, it then prompts them how many animals they want to buy (1 or 2).
                                                                                                                                                                                     //Then, it will call a function that adds those animals to the array of its species. If the user does not buy an animal, it skips the past two proceedures. The function then calls a function that totals all of the costs for that month and trigers a random event. Lastly, it increments the month number.
  int end = 0;
  do
  {
      print_zoo();
      increment_age();
      cout << "\nWould you like to buy an animal?" << endl << "Enter --> 1 <-- to look at sealions" << endl << "Enter --> 2 <-- to look at blackbears";
      cout << endl << "Enter --> 3 <-- to look at tigers";
      cout << endl << "Enter --> 4 <-- to choose not to buy any animals" << endl << "Input: " ;
      int what_animal;
      int how_many;
      cin >> what_animal;
      if(what_animal == 1)
      {
          cout << "\nHow many sealions?" << endl << "Enter --> 1 <-- to buy one" << endl << "Enter --> 2 <-- to buy two" << endl << "Input: ";
          cin >> how_many;
          buy_sealion(how_many);
          account_money -= (sealions[0].get_purchase_cost() * how_many);
          set_monthly_cost();
          account_money -= get_total_monthly_cost();
          random_event();
          month_number ++;
      }
      else if(what_animal == 2)
      {
          cout << "\nHow many blackbears?" << endl << "Enter --> 1 <-- to buy one" << endl << "Enter --> 2 <-- to buy two" << endl << "Input: ";
          cin >> how_many;
          buy_blackbear(how_many);
          account_money -= (blackbears[0].get_purchase_cost() * how_many);
          set_monthly_cost();
          account_money -= get_total_monthly_cost();
          random_event();
          month_number ++;
      }
      else if(what_animal == 3)
      {
          cout << "\nHow many tigers?" << endl << "Enter --> 1 <-- to buy one" << endl << "Enter --> 2 <-- to buy two" << endl << "Input: ";
          cin >> how_many;
          buy_tiger(how_many);
          account_money -= (tigers[0].get_purchase_cost() * how_many);
          set_monthly_cost();
          account_money -= get_total_monthly_cost();
          random_event();
          month_number ++;
      }
      else if(what_animal == 4)
      {
          cout << "\nYou have chosen not to buy any animals." << endl;
          set_monthly_cost();
          account_money -= get_total_monthly_cost();
          random_event();
          month_number ++;
      }
      cout << "\n\nWould you like to burn down your zoo?" << endl << "Enter --> 0 <-- to do so, otherwise enter ANY integer. " << endl << "Input: ";
      cin >> end;
  } while (account_money >= 1 && end != 0);
}


void Zoo::birth_sealion()                                                                                                                                                            //Birth sealion function
{                                                                                                                                                                                    //This function points to the original sealion array, it then creates a new array that is one index size larger than the original. After that, it duplicates the information in the orginal array.
    Sealion **sealions_point = &sealions;                                                                                                                                            //Then, it sets the age of the last index (the new animal) to zero. Lastly, it sets the original array to the new array and deletes the new array increments the number of sealions by the litter size
    Sealion *updated_sealions = new Sealion[num_sealions + 1];

    for(int i = 0; i < num_sealions; i++)
    {
        updated_sealions[i] = sealions[i];
    }

    for(int i = num_sealions; i < (1 + num_sealions); i++)
    {
      updated_sealions[i].set_age(0);
      //cout << "Sealions array " << updated_sealions[i].get_age() << endl;
    }

    delete [] *sealions_point;
    *sealions_point = NULL;
    *sealions_point = updated_sealions;
    num_sealions += 1;
//
}


void Zoo::birth_blackbear()                                                                                                                                                          //Birth a black bear
{                                                                                                                                                                                    //This function points to the original black bear array, it then creates a new array that is five index size larger than the original. After that, it duplicates the information in the orginal array.
    Blackbear **blackbears_point = &blackbears;                                                                                                                                      //Then, it sets the age of the last index (the new animal) to zero. Lastly, it sets the original array to the new array and deletes the new array increments the number of black bears by the litter size
    Blackbear *updated_blackbears = new Blackbear[num_blackbears + 2];

    for(int i = 0; i < num_blackbears; i++)
    {
        updated_blackbears[i] = blackbears[i];
    }

    for(int i = num_blackbears; i < (2 + num_blackbears); i++)
    {
        updated_blackbears[i].set_age(0);
        //cout << "Blackbears array " << updated_blackbears[i].get_age() << endl;
    }

    delete [] *blackbears_point;
    *blackbears_point = NULL;
    *blackbears_point = updated_blackbears;
    num_blackbears += 2;

}


void Zoo::birth_tiger()                                                                                                                                                              //Birth a tiger
{                                                                                                                                                                                    //This function points to the original tiger array, it then creates a new array that is three index size larger than the original. After that, it duplicates the information in the orginal array.
    Tiger **tigers_point = &tigers;                                                                                                                                                  //Then, it sets the age of the last index (the new animal) to zero. Lastly, it sets the original array to the new array and deletes the new array and increments the number of tigers by the litter size
    Tiger *updated_tigers = new Tiger[num_tigers + 3];

    for(int i = 0; i < num_tigers; i++)
    {
        updated_tigers[i] = tigers[i];
    }

    for(int i = num_tigers; i < (3 + num_tigers); i++)
    {
        updated_tigers[i].set_age(0);
        //cout << "Tigers array " << updated_tigers[i].get_age() << endl;
    }

    delete [] *tigers_point;
    *tigers_point = NULL;
    *tigers_point = updated_tigers;
    num_tigers += 3;

}


void Zoo::buy_sealion(int new_num_sealions)                                                                                                                                          //Buy a sealion
{                                                                                                                                                                                    //This function points to the original sealion array, it then creates a new array that is an x index size larger than the original. The x is determined the parameter it accepts. After that, it duplicates the information in the orginal array.
    Sealion **sealions_point = &sealions;                                                                                                                                            //Then, it sets the age of the last index (the new animal) to 48. Lastly, it sets the original array to the new array and deletes the new array and increments the number of sealions by the amount bought.
    Sealion *updated_sealions = new Sealion[num_sealions + new_num_sealions];

    for(int i = 0; i < num_sealions; i++)
    {
        updated_sealions[i] = sealions[i];
    }

    for(int i = num_sealions; i < (new_num_sealions + num_sealions); i++)
    {
        updated_sealions[i].set_age(4 * 12);
        //cout << "Sealions array " << updated_sealions[i].get_age() << endl;
    }

    delete [] *sealions_point;
    *sealions_point = NULL;
    *sealions_point = updated_sealions;
    num_sealions += new_num_sealions;

}


void Zoo::buy_blackbear(int new_num_blackbears)                                                                                                                                      //Buy a black bear (does the exact same thing as buy_sealion)
{
    Blackbear **blackbears_point = &blackbears;
    Blackbear *updated_blackbears = new Blackbear[num_blackbears + new_num_blackbears];

    for(int i = 0; i < num_blackbears; i++)
    {
        updated_blackbears[i] = blackbears[i];
    }

    for(int i = num_blackbears; i < (new_num_blackbears + num_blackbears); i++)
    {
        updated_blackbears[i].set_age(4 * 12);
        //cout << "Balck Bears array " << updated_blackbears[i].get_age() << endl;
    }

    delete [] *blackbears_point;
    *blackbears_point = NULL;
    *blackbears_point = updated_blackbears;
    num_blackbears += new_num_blackbears;

}


void Zoo::buy_tiger(int new_num_tigers)                                                                                                                                              //Buy a tiger (does the exact same thing as buy_sealion)
{
    Tiger **tigers_point = &tigers;
    Tiger *updated_tigers = new Tiger[num_tigers + new_num_tigers];

    for(int i = 0; i < num_tigers; i++)
    {
        updated_tigers[i] = tigers[i];
    }

    for(int i = num_tigers; i < (new_num_tigers + num_tigers); i++)
    {
        updated_tigers[i].set_age(4 * 12);
        //cout << "Tigers array " << updated_tigers[i].get_age() << endl;
    }

    delete [] *tigers_point;
    *tigers_point = NULL;
    *tigers_point = updated_tigers;
    num_tigers += new_num_tigers;
}


void Zoo::kill_sealion()                                                                                                                                                             //Kill a sealion
{                                                                                                                                                                                    //This does a similar thing as birth_sealion. The difference is that it creates a new animal array that is one index size SMALLER. At the end, it de-increments the number of sealions by one
    Sealion **sealions_point = &sealions;
    Sealion *updated_sealions = new Sealion[num_sealions - 1];

    for(int i = 0; i < (num_sealions - 1); i++)
    {
        updated_sealions[i] = sealions[i];
    }

    delete [] *sealions_point;
    *sealions_point = NULL;
    *sealions_point = updated_sealions;
    num_sealions -= 1;

}


void Zoo::kill_blackbear()                                                                                                                                                           //Kill a black bear (exact same as kill_sealion)
{
    Blackbear **blackbears_point = &blackbears;
    Blackbear *updated_blackbears = new Blackbear[num_blackbears - 1];

    for(int i = 0; i < (num_blackbears - 1); i++)
    {
        updated_blackbears[i] = blackbears[i];
    }


    delete [] *blackbears_point;
    *blackbears_point = NULL;
    *blackbears_point = updated_blackbears;
    num_blackbears -= 1;

}


void Zoo::kill_tiger()                                                                                                                                                               //Kill a tiger (exact same as kill_sealion)
{
    Tiger **tigers_point = &tigers;
    Tiger *updated_tigers = new Tiger[num_tigers - 1];

    for(int i = 0; i < (num_tigers - 1); i++)
    {
        updated_tigers[i] = tigers[i];
    }

    delete [] *tigers_point;
    *tigers_point = NULL;
    *tigers_point = updated_tigers;
    num_tigers -= 1;

}


void Zoo::print_zoo()
{
    cout << "\n\n\n-----------------------------------------------------------------" << endl << endl;                                                                               //Print zoo
    cout << "MONTH: " << month_number << endl;                                                                                                                                       //Prints out what month it is, the monthly cost of food for each animal, and the amount of money in the users bank account. and calls the print functions for each animal
    cout << "MONTHLY COST: -$" << get_total_monthly_cost() << endl;
    //cout << "MONTHLY REVENUE: +$" << get_total_monthly_revenue(0) << endl;
    cout << "MONEY IN YOUR BANK ACCOUNT: $" << account_money << endl << endl << endl;
    print_sealions();
    print_blackbears();
    print_tigers();
    cout << "-----------------------------------------------------------------";
}


void Zoo::print_sealions()                                                                                                                                                           //Print sealions
{                                                                                                                                                                                    //Prints the number of sealions. It then loops through each individual sealion in the sealion array and prints out all of its data members
    cout << "NUMBER OF SEALIONS: " << num_sealions << endl << endl;
    for(int i = 0; i < num_sealions; i++)
    {
        cout << "Sealion " << i + 1 << ": " << endl;
        cout << "Age: " << sealions[i].get_age() << " months old" << endl;
        cout << "Purchase cost: $" << sealions[i].get_purchase_cost() << endl;
        cout << "Food cost: $" << sealions[i].get_food_cost() << endl;
        cout << "Litter size: " << sealions[i].get_litter_size() << endl;
        cout << "Food multiplier compared with other animals: " << sealions[i].get_food_multiplier() << endl;
        cout << "Monthly revenue: $" << sealions[i].get_monthly_revenue() << endl;
        cout << endl << endl;
    }
    cout << endl << endl;
}


void Zoo::print_blackbears()                                                                                                                                                         //Print black bears (does the exact same thing as print_sealions)
{
    cout << "NUMBER OF BLACK BEARS: " << num_blackbears << endl << endl;
    for(int i = 0; i < num_blackbears; i++)
    {
        cout << "Black Bear " << i + 1 << ": " << endl;
        cout << "Age: " << blackbears[i].get_age() << " months old" << endl;
        cout << "Purchase cost: $" << blackbears[i].get_purchase_cost() << endl;
        cout << "Food cost: $" << blackbears[i].get_food_cost() << endl;
        cout << "Litter size: " << blackbears[i].get_litter_size() << endl;
        cout << "Food multiplier compared with other animals: " << blackbears[i].get_food_multiplier() << endl;
        cout << "Monthly revenue: $" << blackbears[i].get_monthly_revenue() << endl;
        cout << endl << endl;
    }
    cout << endl << endl;
}


void Zoo::print_tigers()                                                                                                                                                             //Print tigers (does the exact same thing as print_sealions)
{
    cout << "NUMBER OF TIGERS: " << num_tigers << endl << endl;
    for(int i = 0; i < num_tigers; i++)
    {
        cout << "Tiger " << i + 1 << ": " << endl;
        cout << "Age: " << tigers[i].get_age() << " months old" << endl;
        cout << "Purchase cost: $" << tigers[i].get_purchase_cost() << endl;
        cout << "Food cost: $" << tigers[i].get_food_cost() << endl;
        cout << "Litter size: " << tigers[i].get_litter_size() << endl;
        cout << "Food multiplier compared with other animals: " << tigers[i].get_food_multiplier() << endl;
        cout << "Monthly revenue: $" << tigers[i].get_monthly_revenue() << endl;
        cout << endl << endl;
    }
    cout << endl << endl;
}


void Zoo::set_monthly_cost()                                                                                                                                                         //Set monthly cost
{                                                                                                                                                                                    //This function starts off by creating a random number between 64 and 96. It then checks if its the first month. If it detects that it is indeed the first month, then it loops through every animal and sets its food cost to $80.
    srand(time(NULL));                                                                                                                                                               //If it is any other month after the first month, then it loops through every animal and sets the food cost to that random number between 64 and 96
    int randomizer = (rand() % 32 + 64);

    if(month_number == 0)
    {
        for(int i = 0; i < num_sealions; i++)
        {
            sealions[i].set_food_cost(80);
        }
        for(int i = 0; i < num_blackbears; i++)
        {
            blackbears[i].set_food_cost(80);
        }
        for(int i = 0; i < num_tigers; i++)
        {
            tigers[i].set_food_cost(80);
        }
    }
    else
    {
        for(int i = 0; i < num_sealions; i++)
        {
            sealions[i].set_food_cost(randomizer);
        }
        for(int i = 0; i < num_blackbears; i++)
        {
            blackbears[i].set_food_cost(randomizer);
        }
        for(int i = 0; i < num_tigers; i++)
        {
            tigers[i].set_food_cost(randomizer);
        }
    }
}

int Zoo::get_total_monthly_cost()                                                                                                                                                    //Get total monthly cost
{                                                                                                                                                                                    //Starts off by defining an integer: total_cost. It then loops through every animal and increments total_cost based on what the food cost is of each animal.
    int total_cost = 0;                                                                                                                                                              //This is necessary because each animal has a food multiplier on top of the base food cost. Finally, it returns total_cost which is the total cost to feed all the animals.

    for(int i = 0; i < num_sealions; i++)
    {
        total_cost += sealions[i].get_food_cost();
    }
    for(int i = 0; i < num_blackbears; i++)
    {
        total_cost += blackbears[i].get_food_cost();
    }
    for(int i = 0; i < num_tigers; i++)
    {
        total_cost += tigers[i].get_food_cost();
    }

    return total_cost;
}

int Zoo::get_total_monthly_revenue(int is_special_event)                                                                                                                             //Get total monthly revenue
{                                                                                                                                                                                    //This function is very similar to the get_total_monthly_cost function. It creates an integer that stores the total revenue starting it at zero.
    int total_revenue = 0;                                                                                                                                                           //The difference is before it loops through each animal, it first checks if it is a special event. This will be determined by its parameter being 1 or 0.
                                                                                                                                                                                     //Zero means no speacial event, 1 means it is a special event. If it is NOT a special event, the function will loop through every animal, getting its individual monthly revenue, and add it to total_revenue. Before it can get that number it will first check if the animal is a baby (<= 6 months).
    if(is_special_event == 0)                                                                                                                                                        //If it is a baby, it will get that monthly revenue and multiply it by two for that animal and then add it to the total. If not, it will get its monthly revenue and add it to the total without mutliplying it. If it IS a special event, the function will do the same thing for every animal EXCEPT sealions.
    {                                                                                                                                                                                //For sealions, it will add a bonus on top of every seal that is derived by calling a sealion member function that generates a bonus revenue.
        for(int i = 0; i < num_sealions; i++)
        {
            if(sealions[i].get_age() <= 6)
            {
                total_revenue += (sealions[i].get_monthly_revenue() * 2);
            }
            else
            {
                total_revenue += sealions[i].get_monthly_revenue();
            }
        }
        for(int i = 0; i < num_blackbears; i++)
        {
            if(blackbears[i].get_age() <= 6)
            {
                total_revenue += (blackbears[i].get_monthly_revenue() * 2);
            }
            else
            {
                total_revenue += blackbears[i].get_monthly_revenue();
            }
        }
        for(int i = 0; i < num_tigers; i++)
        {
            if(tigers[i].get_age() <= 6)
            {
                total_revenue += (tigers[i].get_monthly_revenue() * 2);
            }
            else
            {
                total_revenue += tigers[i].get_monthly_revenue();
            }
        }
    }
    else if(is_special_event == 1)
    {
        for(int i = 0; i < num_sealions; i++)
        {
            sealions[i].set_bonus_revenue();
            if(sealions[i].get_age() <= 6)
            {
                total_revenue += ((sealions[i].get_monthly_revenue() * 2) + sealions[i].get_bonus_revenue());
            }
            else
            {
                total_revenue += (sealions[i].get_monthly_revenue() + sealions[i].get_bonus_revenue());
            }
        }
        for(int i = 0; i < num_blackbears; i++)
        {
            if(blackbears[i].get_age() <= 6)
            {
                total_revenue += (blackbears[i].get_monthly_revenue() * 2);
            }
            else
            {
                total_revenue += blackbears[i].get_monthly_revenue();
            }
        }
        for(int i = 0; i < num_tigers; i++)
        {
            if(tigers[i].get_age() <= 6)
            {
                total_revenue += (tigers[i].get_monthly_revenue() * 2);
            }
            else
            {
                total_revenue += tigers[i].get_monthly_revenue();
            }
        }
    }

    return total_revenue;
}


void Zoo::increment_age()                                                                                                                                                            //Increment age
{                                                                                                                                                                                    //Loops through every animal of every species and sets its age to one month larger
    for(int i = 0; i < num_sealions; i++)
    {
        sealions[i].set_age(sealions[i].get_age() + 1);
    }
    for(int i = 0; i < num_blackbears; i++)
    {
        blackbears[i].set_age(blackbears[i].get_age() + 1);
    }
    for(int i = 0; i < num_tigers; i++)
    {
        tigers[i].set_age(tigers[i].get_age() + 1);
    }
}


void Zoo::random_event()                                                                                                                                                             //Random event
{                                                                                                                                                                                    //Starts off by creating a random number between 1 and 4. Depending on what that number generates, decides which of the four random events occur. The first one being that one of the animals gets sick. For it to decide which animal will get sick, it has to call the function get_randomnum.
    srand(time(NULL));                                                                                                                                                               //It then notifies the user that their animal has gotten sick and how much they need to pay in order to save it. They then can input a 1 or 2. A 1 saves the animal and charges them the fee, 2 calls the function to kill that animal.
    int randomizer = 0;                                                                                                                                                              //OPTION 2 means that one of the animals will give birth. The function calls the get_randomnum2 function to decide which animal will give birth. Based on this it will notify you which animal is giving birth. After that it calls the birth function for that animal.
    randomizer = (rand() % 4 + 1);                                                                                                                                                   //OPTION 3 means that there is a boom in zoo attendance. So, the function calls the get_total_monthly_revenue function with the parameter that lets that function know it is a special event.
                                                                                                                                                                                     //OPTION 4 means there is no random event this month, so nothing special happens.
    if(randomizer == 1)                                                                                                                                                              //NOTE: after each random event, it calls the get_total_monthly_revenue function and adds it to the zoo data member account_money. They all call it saying its NOT a special even EXCEPT in OPTION 3.
    {
        srand(time(NULL));
        int randomizer2 = 0;
        randomizer2 = get_randomnum();
        int save_or_kill;

        if(randomizer2 == 1)
        {
            cout << "\nOh no!!! one of your SEALIONS has gotten sick." << endl << "Enter --> 1 <-- to save the animal and pay " << (sealions[0].get_purchase_cost() / 2)<< endl;
            cout << "Enter --> 2 <-- to choose not to save this animal." << endl << "Input: ";
            cin >> save_or_kill;
            if(save_or_kill == 1)
            {
                cout << "\n\nYou have chosen to save the animal..." << endl << "Charging you $" << (sealions[0].get_purchase_cost() / 2) << endl;
                account_money -= (sealions[0].get_purchase_cost() / 2);
            }
            else if(save_or_kill == 2)
            {
                cout << "You have chose NOT to save the animal..." << endl;
                kill_sealion();
            }
        }
        else if(randomizer2 == 2)
        {
            cout << "\nOh no!!! one of your BLACK BEARS has gotten sick." << endl << "Enter --> 1 <-- to save the animal and pay " << (blackbears[0].get_purchase_cost() / 2)<< endl;
            cout << "Enter --> 2 <-- to choose not to save this animal." << endl << "Input: ";
            cin >> save_or_kill;
            if(save_or_kill == 1)
            {
                cout << "\n\nYou have chosen to save the animal..." << endl << "Charging you $" << (blackbears[0].get_purchase_cost() / 2) << endl;
                account_money -= (blackbears[0].get_purchase_cost() / 2);
            }
            else if(save_or_kill == 2)
            {
                cout << "You have chose NOT to save the animal..." << endl;
                kill_blackbear();
            }
        }
        else if(randomizer2 == 3)
        {
            cout << "\nOh no!!! one of your TIGERS has gotten sick." << endl << "Enter --> 1 <-- to save the animal and pay " << (tigers[0].get_purchase_cost() / 2)<< endl;
            cout << "Enter --> 2 <-- to choose not to save this animal." << endl << "Input: ";
            cin >> save_or_kill;
            if(save_or_kill == 1)
            {
                cout << "\n\nYou have chosen to save the animal..." << endl << "Charging you $" << (tigers[0].get_purchase_cost() / 2) << endl;
                account_money -= (tigers[0].get_purchase_cost() / 2);
            }
            else if(save_or_kill == 2)
            {
                cout << "You have chose NOT to save the animal..." << endl;
                kill_tiger();
            }
        }
        else if(randomizer2 == 4)
        {
            cout << "\nNo animals in your zoo" << endl;
        }
        account_money += get_total_monthly_revenue(0);
    }
    else if(randomizer == 2)
    {
        srand(time(NULL));
        int randomizer4 = 0;
        randomizer4 = get_randomnum2();
        if(randomizer4 == 1)
        {
            cout << "\n\nOne of your sealions has given birth!!! " << endl << endl;
            birth_sealion();
        }
        else if(randomizer4 == 2)
        {
            cout << "\n\nOne of your black bears has given birth!!! " << endl << endl;
            birth_blackbear();
        }
        else if(randomizer4 == 3)
        {
            cout << "\n\nOne of your tigers has given birth!!! " << endl << endl;
            birth_tiger();
        }
        else if(randomizer4 == 4)
        {
            cout << "\n\nNo adult animals in your zoo to give birth" << endl << endl;
        }
        account_money += get_total_monthly_revenue(0);
    }
    else if(randomizer == 3)
    {
        cout << "\n\nThere is a BOOM in zoo attendance" << endl << "Totalling up the bonus revenue gained from each sealion!" << endl << endl;
        account_money += get_total_monthly_revenue(1);
    }
    else if(randomizer == 4)
    {
        cout << "\n\nNo random event this month" << endl << endl;
        account_money += get_total_monthly_revenue(0);
    }
}


int Zoo::get_randomnum()                                                                                                                                                             //Get random number for the animal getting sick function.
{                                                                                                                                                                                    //Checks every possible case of there being any animals in the user's zoo. This is needed because a sealion CANT get sick if there are no sealions in the zoo in the first place.
    srand(time(NULL));                                                                                                                                                               //Example: There ARE sealions and blackbears but NO tigers. So only generate a random number between 1 and 2
    int randomizer2 = 0;

    if(num_sealions > 0 && num_blackbears > 0 && num_tigers > 0)
    {
        randomizer2 = (rand() % 3 + 1);
    }
    else if(num_sealions > 0 && num_blackbears > 0 && num_tigers == 0)
    {
        randomizer2 = (rand() % 2 + 1);
    }
    else if(num_sealions > 0 && num_blackbears == 0 && num_tigers > 0)
    {
        int randomizer3 = (rand() % 2 + 1);
        if(randomizer3 == 1)
        {
            randomizer2 = 1;
        }
        else if(randomizer3 == 2)
        {
            randomizer2 = 3;
        }
    }
    else if(num_sealions == 0 && num_blackbears > 0 && num_tigers > 0)
    {
        randomizer2 = (rand() % 2 + 2);
    }
    else if(num_sealions == 0 && num_blackbears == 0 && num_tigers > 0)
    {
        randomizer2 = 3;
    }
    else if(num_sealions == 0 && num_blackbears > 0 && num_tigers == 0)
    {
        randomizer2 = 2;
    }
    else if(num_sealions > 0 && num_blackbears == 0 && num_tigers == 0)
    {
        randomizer2 = 1;
    }
    else if(num_sealions == 0 && num_blackbears == 0 && num_tigers == 0)
    {
        randomizer2 = 4;
    }
    return randomizer2;
}


int Zoo::get_randomnum2()                                                                                                                                                            //Get random number for the animal giving birth function.
{                                                                                                                                                                                    //Does the same thing as get_randomnum function except after checking which species's of animals exist in the zoo, it then has to check through those species's if there is an adult present. Based on that, it will return a random number of which animals could give birth.
    srand(time(NULL));
    int randomizer2 = 0;

    if(num_sealions > 0 && num_blackbears > 0 && num_tigers > 0)
    {
        int sealion_adult = 0;
        for(int i = 0; i < num_sealions; i++)
        {
            if(sealions[i].get_age() >= 48)
            {
                sealion_adult += 1;
            }
        }
        int blackbear_adult = 0;
        for(int i = 0; i < num_blackbears; i++)
        {
            if(blackbears[i].get_age() >= 48)
            {
                blackbear_adult += 1;
            }
        }
        int tiger_adult = 0;
        for(int i = 0; i < num_tigers; i++)
        {
            if(tigers[i].get_age() >= 48)
            {
                tiger_adult += 1;
            }
        }
        if(sealion_adult > 0 && blackbear_adult > 0 && tiger_adult > 0)
        {
            randomizer2 = (rand() % 3 + 1);
        }
        else if(sealion_adult > 0 && blackbear_adult > 0 && tiger_adult == 0)
        {
            randomizer2 = (rand() % 2 + 1);
        }
        else if(sealion_adult > 0 && blackbear_adult == 0 && tiger_adult > 0)
        {
            int randomizer3 = (rand() % 2 + 1);
            if(randomizer3 == 1)
            {
                randomizer2 = 1;
            }
            else if(randomizer3 == 2)
            {
                randomizer2 = 3;
            }
        }
        else if(sealion_adult == 0 && blackbear_adult > 0 && tiger_adult > 0)
        {
            randomizer2 = (rand() % 2 + 2);
        }
        else if(sealion_adult == 0 && blackbear_adult == 0 && tiger_adult > 0)
        {
            randomizer2 = 3;
        }
        else if(sealion_adult == 0 && blackbear_adult > 0 && tiger_adult == 0)
        {
            randomizer2 = 2;
        }
        else if(sealion_adult > 0 && blackbear_adult == 0 && tiger_adult == 0)
        {
            randomizer2 = 1;
        }
        else if(sealion_adult == 0 && blackbear_adult == 0 && tiger_adult == 0)
        {
            randomizer2 = 4;
        }
    }


    else if(num_sealions > 0 && num_blackbears > 0 && num_tigers == 0)
    {
        int sealion_adult = 0;
        for(int i = 0; i < num_sealions; i++)
        {
            if(sealions[i].get_age() >= 48)
            {
                sealion_adult += 1;
            }
        }
        int blackbear_adult = 0;
        for(int i = 0; i < num_blackbears; i++)
        {
            if(blackbears[i].get_age() >= 48)
            {
                blackbear_adult += 1;
            }
        }
        if(sealion_adult > 0 && blackbear_adult > 0)
        {
            randomizer2 = (rand() % 2 + 1);
        }
        else if(sealion_adult > 0 && blackbear_adult == 0)
        {
            randomizer2 = 1;
        }
        else if(sealion_adult == 0 && blackbear_adult > 0)
        {
            randomizer2 = 2;
        }
        else if(sealion_adult == 0 && blackbear_adult == 0)
        {
            randomizer2 = 4;
        }
    }


    else if(num_sealions > 0 && num_blackbears == 0 && num_tigers > 0)
    {
        int sealion_adult = 0;
        for(int i = 0; i < num_sealions; i++)
        {
            if(sealions[i].get_age() >= 48)
            {
                sealion_adult += 1;
            }
        }
        int tiger_adult = 0;
        for(int i = 0; i < num_tigers; i++)
        {
            if(tigers[i].get_age() >= 48)
            {
                tiger_adult += 1;
            }
        }
        if(sealion_adult > 0 && tiger_adult > 0)
        {
            int randomizer3 = (rand() % 2 + 1);
            if(randomizer3 == 1)
            {
                randomizer2 = 1;
            }
            else if(randomizer3 == 2)
            {
                randomizer2 = 3;
            }
        }
        else if(sealion_adult > 0 && tiger_adult == 0)
        {
            randomizer2 = 1;
        }
        else if(sealion_adult == 0 && tiger_adult > 0)
        {
            randomizer2 = 3;
        }
        else if(sealion_adult == 0 && tiger_adult == 0)
        {
            randomizer2 = 4;
        }
    }


    else if(num_sealions == 0 && num_blackbears > 0 && num_tigers > 0)
    {
        int blackbear_adult = 0;
        for(int i = 0; i < num_blackbears; i++)
        {
            if(blackbears[i].get_age() >= 48)
            {
                blackbear_adult += 1;
            }
        }
        int tiger_adult = 0;
        for(int i = 0; i < num_tigers; i++)
        {
            if(tigers[i].get_age() >= 48)
            {
                tiger_adult += 1;
            }
        }
        if(tiger_adult > 0 && blackbear_adult > 0)
        {
            randomizer2 = (rand() % 2 + 2);
        }
        else if(tiger_adult > 0 && blackbear_adult == 0)
        {
            randomizer2 = 3;
        }
        else if(tiger_adult == 0 && blackbear_adult > 0)
        {
            randomizer2 = 2;
        }
        else if(tiger_adult == 0 && blackbear_adult == 0)
        {
            randomizer2 = 4;
        }
    }


    else if(num_sealions == 0 && num_blackbears == 0 && num_tigers > 0)
    {
        int tiger_adult = 0;
        for(int i = 0; i < num_tigers; i++)
        {
            if(tigers[i].get_age() >= 48)
            {
                tiger_adult += 1;
            }
        }
        if(tiger_adult > 0)
        {
            randomizer2 = 3;
        }
        else if(tiger_adult == 0)
        {
            randomizer2 = 4;
        }
    }


    else if(num_sealions == 0 && num_blackbears > 0 && num_tigers == 0)
    {
        int blackbear_adult = 0;
        for(int i = 0; i < num_blackbears; i++)
        {
            if(blackbears[i].get_age() >= 48)
            {
                blackbear_adult += 1;
            }
        }
        if(blackbear_adult > 0)
        {
            randomizer2 = 2;
        }
        else if(blackbear_adult == 0)
        {
            randomizer2 = 4;
        }
    }


    else if(num_sealions > 0 && num_blackbears == 0 && num_tigers == 0)
    {
        int sealion_adult = 0;
        for(int i = 0; i < num_sealions; i++)
        {
            if(sealions[i].get_age() >= 48)
            {
                sealion_adult += 1;
            }
        }
        if(sealion_adult > 0)
        {
            randomizer2 = 1;
        }
        else if(sealion_adult == 0)
        {
            randomizer2 = 4;
        }
    }


    else if(num_sealions == 0 && num_blackbears == 0 && num_tigers == 0)
    {
        randomizer2 = 4;
    }
    return randomizer2;
}
