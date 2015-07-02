//
//  By Chen Shi - Assignment 6
//
//  This program will simulate a slot machine. The user can input his/her bet,
//  The machine will run and let you know if you win/lose.
//

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

// ------- class prototypes -------
class TripleString
{
public:
   static const int MAX_LEN = 20;
private:
   string string1, string2, string3;
public:
   void set1stString(string str);
   string get1stString();
   void set2ndString(string str);
   string get2ndString();
   void set3rdString(string str);
   string get3rdString();
};

// Global-scope method prototypes
int getBet();
TripleString pull();
string randString();
int getPayMultiplier (TripleString thePull);
void display (TripleString thePull, int winnings);
bool validString(string str);

// main() method defination
int main()
{
   int userBet;

   do
   {
      userBet = getBet();
      if (userBet != 0)
      {
         TripleString thePull = pull();
         int pay = getPayMultiplier(thePull);
         display(thePull, pay * userBet);
      }
      else
      {
         cout << "\nHope you had a wonderful time. Good bye!\n";
      }
   } while (userBet != 0);

   return 0;
}

// Ask for the user's bet (1-100)
int getBet()
{
   int theBet;
   do
   {
      cout << "How much would you like to bet (1 - 100) or 0 to quit? ";
      cin >> theBet;
   } while ((theBet < 1 || theBet > 100) && theBet != 0);

   return theBet;
}

// Get a random pull
TripleString pull()
{
   TripleString triStrings;
   triStrings.set1stString(randString());
   triStrings.set2ndString(randString());
   triStrings.set3rdString(randString());

   return triStrings;
}

// Generate a random string among "BAR", "cherries", "(space)" and "7".
string randString()
{
   int randNum = rand() % 100 + 1;

   if (randNum > 50)
      return "BAR";
   else if (randNum > 25)
      return "cherries";
   else if (randNum > 12.5)
      return "(space)";
   else
      return "7";
}

// Decide the winning amount
int getPayMultiplier (TripleString thePull)
{
   if (thePull.get1stString() == "cherries")
   {
      if (thePull.get2ndString() == "cherries")
      {
         if (thePull.get3rdString() == "cherries")
         {
            return 30;
         }
         else
            return 15;
      }
      else
         return 5;
   }
   else if (thePull.get1stString() == "BAR" && thePull.get2ndString() == "BAR"
         && thePull.get3rdString() == "BAR")
      return 50;
   else if (thePull.get1stString() == "7" && thePull.get2ndString() == "7"
         && thePull.get3rdString() == "7")
      return 100;
   return 0;
}

// Display the pull and win/lose
void display (TripleString thePull, int winnings)
{
   cout << "whirrrrrr .... and your pull is ... " << endl;
   cout << " " + thePull.get1stString() + " " + thePull.get2ndString() + " "
      + thePull.get3rdString() << endl;
   if (winnings == 0)
      cout << "Sorry, you lose.\n" << endl;
   else
      cout << "Congratulations, you win: $" << winnings << "!" << endl << endl;
}

// Check if a string is valid
bool validString(string str)
{
   if (str.length() <= TripleString::MAX_LEN)
      return true;
   else
      return false;
}

// Set the 1st string
void TripleString::set1stString(string str)
{
   if (validString(str)) {
      string1 = str;
   }
}

// Get the 1st string
string TripleString::get1stString()
{
   return string1;
}

// Set the 2nd string
void TripleString::set2ndString(string str)
{
   if (validString(str)) {
      string2 = str;
   }
}

// Get the 2nd string
string TripleString::get2ndString()
{
   return string2;
}

// Set the 3rd string
void TripleString::set3rdString(string str)
{
   if (validString(str)) {
      string3 = str;
   }
}

// Get the 3rd string
string TripleString::get3rdString()
{
   return string3;
}

/*TripleString::TripleString()
{
   string1 = "";
   string2 = "";
   string3 = "";
}*/


/* ----------------------- Sample RUN ---------------------------

How much would you like to bet (1 - 100) or 0 to quit? 1000
How much would you like to bet (1 - 100) or 0 to quit? -1
How much would you like to bet (1 - 100) or 0 to quit? 1
whirrrrrr .... and your pull is ... 
 7 cherries BAR
Sorry, you lose.

How much would you like to bet (1 - 100) or 0 to quit? 1
whirrrrrr .... and your pull is ... 
 BAR cherries BAR
Sorry, you lose.

How much would you like to bet (1 - 100) or 0 to quit? 1
whirrrrrr .... and your pull is ... 
 cherries BAR (space)
Congratulations, you win: $5!

How much would you like to bet (1 - 100) or 0 to quit? 1
whirrrrrr .... and your pull is ... 
 7 cherries BAR
Sorry, you lose.

How much would you like to bet (1 - 100) or 0 to quit? 1
whirrrrrr .... and your pull is ... 
 BAR cherries BAR
Sorry, you lose.

How much would you like to bet (1 - 100) or 0 to quit? 1
whirrrrrr .... and your pull is ... 
 7 cherries cherries
Sorry, you lose.

How much would you like to bet (1 - 100) or 0 to quit? 1
whirrrrrr .... and your pull is ... 
 cherries (space) 7
Congratulations, you win: $5!

How much would you like to bet (1 - 100) or 0 to quit? 1
whirrrrrr .... and your pull is ... 
 BAR 7 BAR
Sorry, you lose.

How much would you like to bet (1 - 100) or 0 to quit? 1
whirrrrrr .... and your pull is ... 
 BAR cherries BAR
Sorry, you lose.

How much would you like to bet (1 - 100) or 0 to quit? 1
whirrrrrr .... and your pull is ... 
 BAR (space) cherries
Sorry, you lose.

How much would you like to bet (1 - 100) or 0 to quit? 2
whirrrrrr .... and your pull is ... 
 BAR cherries (space)
Sorry, you lose.

How much would you like to bet (1 - 100) or 0 to quit? 2
whirrrrrr .... and your pull is ... 
 BAR 7 cherries
Sorry, you lose.

How much would you like to bet (1 - 100) or 0 to quit? 2
whirrrrrr .... and your pull is ... 
 BAR cherries BAR
Sorry, you lose.

How much would you like to bet (1 - 100) or 0 to quit? 2
whirrrrrr .... and your pull is ... 
 (space) BAR BAR
Sorry, you lose.

How much would you like to bet (1 - 100) or 0 to quit? 2
whirrrrrr .... and your pull is ... 
 BAR cherries BAR
Sorry, you lose.

How much would you like to bet (1 - 100) or 0 to quit? 2
whirrrrrr .... and your pull is ... 
 cherries cherries BAR
Congratulations, you win: $30!

How much would you like to bet (1 - 100) or 0 to quit? 2
whirrrrrr .... and your pull is ... 
 BAR BAR 7
Sorry, you lose.

How much would you like to bet (1 - 100) or 0 to quit? 2
whirrrrrr .... and your pull is ... 
 BAR 7 cherries
Sorry, you lose.

How much would you like to bet (1 - 100) or 0 to quit? 2
whirrrrrr .... and your pull is ... 
 BAR BAR (space)
Sorry, you lose.

How much would you like to bet (1 - 100) or 0 to quit? 2
whirrrrrr .... and your pull is ... 
 BAR cherries 7
Sorry, you lose.

How much would you like to bet (1 - 100) or 0 to quit? 10
whirrrrrr .... and your pull is ... 
 (space) BAR cherries
Sorry, you lose.

How much would you like to bet (1 - 100) or 0 to quit? 10
whirrrrrr .... and your pull is ... 
 (space) 7 BAR
Sorry, you lose.

How much would you like to bet (1 - 100) or 0 to quit? 10
whirrrrrr .... and your pull is ... 
 BAR 7 cherries
Sorry, you lose.

How much would you like to bet (1 - 100) or 0 to quit? 10
whirrrrrr .... and your pull is ... 
 cherries BAR BAR
Congratulations, you win: $50!

How much would you like to bet (1 - 100) or 0 to quit? 10
whirrrrrr .... and your pull is ... 
 cherries (space) BAR
Congratulations, you win: $50!

How much would you like to bet (1 - 100) or 0 to quit? 10
whirrrrrr .... and your pull is ... 
 (space) BAR cherries
Sorry, you lose.

How much would you like to bet (1 - 100) or 0 to quit? 10
whirrrrrr .... and your pull is ... 
 cherries BAR (space)
Congratulations, you win: $50!

How much would you like to bet (1 - 100) or 0 to quit? 10
whirrrrrr .... and your pull is ... 
 BAR cherries 7
Sorry, you lose.

How much would you like to bet (1 - 100) or 0 to quit? 10
whirrrrrr .... and your pull is ... 
 (space) BAR 7
Sorry, you lose.

How much would you like to bet (1 - 100) or 0 to quit? 10
whirrrrrr .... and your pull is ... 
 7 BAR BAR
Sorry, you lose.

How much would you like to bet (1 - 100) or 0 to quit? 100
whirrrrrr .... and your pull is ... 
 BAR (space) 7
Sorry, you lose.

How much would you like to bet (1 - 100) or 0 to quit? 100
whirrrrrr .... and your pull is ... 
 BAR BAR BAR
Congratulations, you win: $5000!

How much would you like to bet (1 - 100) or 0 to quit? 100
whirrrrrr .... and your pull is ... 
 (space) cherries cherries
Sorry, you lose.

How much would you like to bet (1 - 100) or 0 to quit? 100
whirrrrrr .... and your pull is ... 
 cherries 7 BAR
Congratulations, you win: $500!

How much would you like to bet (1 - 100) or 0 to quit? 100
whirrrrrr .... and your pull is ... 
 BAR cherries cherries
Sorry, you lose.

How much would you like to bet (1 - 100) or 0 to quit? 100
whirrrrrr .... and your pull is ... 
 BAR BAR BAR
Congratulations, you win: $5000!

How much would you like to bet (1 - 100) or 0 to quit? 100
whirrrrrr .... and your pull is ... 
 BAR 7 7
Sorry, you lose.

How much would you like to bet (1 - 100) or 0 to quit? 100
whirrrrrr .... and your pull is ... 
 cherries cherries BAR
Congratulations, you win: $1500!

How much would you like to bet (1 - 100) or 0 to quit? 100
whirrrrrr .... and your pull is ... 
 cherries BAR cherries
Congratulations, you win: $500!

How much would you like to bet (1 - 100) or 0 to quit? 100
whirrrrrr .... and your pull is ... 
 BAR BAR (space)
Sorry, you lose.

How much would you like to bet (1 - 100) or 0 to quit? 0

Hope you had a wonderful time. Good bye!

------------------------------------------------------------ */