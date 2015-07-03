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

// Class prototypes
class TripleString
{
private:
   string string1, string2, string3;
public:
   static const int MAX_LEN;

public:
   //default constructor
   TripleString();
   //mutators and accessors
   bool set1stString(string str);
   string get1stString();
   bool set2ndString(string str);
   string get2ndString();
   bool set3rdString(string str);
   string get3rdString();
private:
   //helper method checking validity
   bool validString(string str);
};

// Initialize constant
const int TripleString::MAX_LEN = 20;

// Global-scope method prototypes
int getBet();
TripleString pull();
string randString();
int getPayMultiplier (TripleString thePull);
void display (TripleString thePull, int winnings);


//-------------- main() method definition --------------
int main()
{
   const int QUIT_BET = 0;
   int userBet, payFactor;
   TripleString pullString;

   // Start a loop to play, enter 0 to quit game
   while (true)
   {
      userBet = getBet();
      if (userBet == QUIT_BET)
         break;
      else
      {
         pullString = pull();
         payFactor = getPayMultiplier(pullString);
         display(pullString, payFactor * userBet);
      }
   }

   return 0;
}

//------------ Global-scope methods definitions ------------

// Ask for the user's bet ($1 - $100)
int getBet()
{
   const int MINIMUM_INPUT = 0, MAXIMUM_INPUT = 100;
   int theBet;

   do
   {
      cout << "How much would you like to bet (1 - 100) or 0 to quit? ";
      cin >> theBet;
   } while (theBet < MINIMUM_INPUT || theBet > MAXIMUM_INPUT);

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

// Generate a random string among "BAR", "cherries", "space" and "7".
string randString()
{
   const int NEW_RAND_MAX = 100, PERCENTAGE_OF_BAR = 50,
      PERCENTAGE_OF_CHERRY = 25, PERCENTAGE_OF_SPACE = 12.5;
   int randNum = rand() % NEW_RAND_MAX + 1;

   if (randNum > PERCENTAGE_OF_BAR)
      return "BAR";
   else if (randNum > PERCENTAGE_OF_CHERRY)
      return "cherries";
   else if (randNum > PERCENTAGE_OF_SPACE)
      return "space";
   else
      return "7";
}

// Decide the winning factors
int getPayMultiplier (TripleString thePull)
{
   const int SEVEN_SEVEN_SEVEN = 100, BAR_BAR_BAR = 50,
      CHERRY_CHERRY_CHERRY = 30, CHERRY_CHERRY_NOCHERRY = 15,
      CHERRY_NOCHERRY_ANY = 5;

   if (thePull.get1stString() == "cherries")
   {
      if (thePull.get2ndString() == "cherries")
      {
         if (thePull.get3rdString() == "cherries")
         {
            return CHERRY_CHERRY_CHERRY;
         }
         else
            return CHERRY_CHERRY_NOCHERRY;
      }
      else
         return CHERRY_NOCHERRY_ANY;
   }
   else if (thePull.get1stString() == "BAR" && thePull.get2ndString() == "BAR"
         && thePull.get3rdString() == "BAR")
      return BAR_BAR_BAR;
   else if (thePull.get1stString() == "7" && thePull.get2ndString() == "7"
         && thePull.get3rdString() == "7")
      return SEVEN_SEVEN_SEVEN;

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


//------------ TripleString member methods definitions ------------

// Default constructor
TripleString::TripleString()
{
   string1 = "";
   string2 = "";
   string3 = "";
}

// Set the 1st string
bool TripleString::set1stString(string str)
{
   if (validString(str))
   {
      string1 = str;
      return true;
   }
   else
      return false;
}

// Get the 1st string
string TripleString::get1stString()
{
   return string1;
}

// Set the 2nd string
bool TripleString::set2ndString(string str)
{
   if (validString(str))
   {
      string2 = str;
      return true;
   }
   else
      return false;
}

// Get the 2nd string
string TripleString::get2ndString()
{
   return string2;
}

// Set the 3rd string
bool TripleString::set3rdString(string str)
{
   if (validString(str))
   {
      string3 = str;
      return true;
   }
   else
      return false;
}

// Get the 3rd string
string TripleString::get3rdString()
{
   return string3;
}

// Check if a string is valid
bool TripleString::validString(string str)
{
   if (str.length() <= MAX_LEN)
      return true;
   else
      return false;
}



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
 cherries BAR space
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
 cherries space 7
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
 BAR space cherries
Sorry, you lose.

How much would you like to bet (1 - 100) or 0 to quit? 2
whirrrrrr .... and your pull is ... 
 BAR cherries space
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
 space BAR BAR
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
 BAR BAR space
Sorry, you lose.

How much would you like to bet (1 - 100) or 0 to quit? 2
whirrrrrr .... and your pull is ... 
 BAR cherries 7
Sorry, you lose.

How much would you like to bet (1 - 100) or 0 to quit? 5
whirrrrrr .... and your pull is ... 
 space BAR cherries
Sorry, you lose.

How much would you like to bet (1 - 100) or 0 to quit? 5
whirrrrrr .... and your pull is ... 
 space 7 BAR
Sorry, you lose.

How much would you like to bet (1 - 100) or 0 to quit? 5
whirrrrrr .... and your pull is ... 
 BAR 7 cherries
Sorry, you lose.

How much would you like to bet (1 - 100) or 0 to quit? 5
whirrrrrr .... and your pull is ... 
 cherries BAR BAR
Congratulations, you win: $25!

How much would you like to bet (1 - 100) or 0 to quit? 5
whirrrrrr .... and your pull is ... 
 cherries space BAR
Congratulations, you win: $25!

How much would you like to bet (1 - 100) or 0 to quit? 5
whirrrrrr .... and your pull is ... 
 space BAR cherries
Sorry, you lose.

How much would you like to bet (1 - 100) or 0 to quit? 5
whirrrrrr .... and your pull is ... 
 cherries BAR space
Congratulations, you win: $25!

How much would you like to bet (1 - 100) or 0 to quit? 5
whirrrrrr .... and your pull is ... 
 BAR cherries 7
Sorry, you lose.

How much would you like to bet (1 - 100) or 0 to quit? 5
whirrrrrr .... and your pull is ... 
 space BAR 7
Sorry, you lose.

How much would you like to bet (1 - 100) or 0 to quit? 5
whirrrrrr .... and your pull is ... 
 7 BAR BAR
Sorry, you lose.

How much would you like to bet (1 - 100) or 0 to quit? 100
whirrrrrr .... and your pull is ... 
 BAR space 7
Sorry, you lose.

How much would you like to bet (1 - 100) or 0 to quit? 100
whirrrrrr .... and your pull is ... 
 BAR BAR BAR
Congratulations, you win: $5000!

How much would you like to bet (1 - 100) or 0 to quit? 100
whirrrrrr .... and your pull is ... 
 space cherries cherries
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
 BAR BAR space
Sorry, you lose.

How much would you like to bet (1 - 100) or 0 to quit? 0


------------------------------------------------------------ */