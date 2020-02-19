// Sarah Gilliland
#include <iostream>
#include <string>
#include <fstream>
#include "List.h"
#include "JsonFacade.hpp"       
#include <time.h>
#include <chrono> 
#include "Timer.hpp" 
#include "mygetch.hpp"

using namespace std;

int main()
{
  // Start the timer to time loading process
  Timer T;        // creating an object for the timer
  T.Start();      // starting timer to time the load
  T.Sleep(1500);  //milliseconds

  // create a list to hold the dictionary in
  Dictionary *W;  
  W = new Dictionary;

  // read dictionary and load the dictionary list
  ifstream fin("test.json");      // opening json file to read from
  string word;                    // variable to store words read from json file

  while(fin>>word)                // while file is not empty
  {
    W->Add(word);                 // add the word to the list
  }
  
  // stop timer for loading - maybe display to screen to check?

  // Start loop to loop 10 times
  for (int i = 0; i < 10; i++)
  {
    // do all of the things in here
    // start timer for searching ? or after reading characters?
    // read typed characters using getch
    // place typed characters into an empty string (maybe overload the + operator)
    // maybe start timer here?
    // search for suggestions
    // increment # of suggestions
    // stop timer and display time taken to search
    // display the ith suggestion
    // loop back to beginning
  }
    
  
  // What is this ///////////////////////////////////////////////
  W->Print();
  //
  W->ReOrder();
  //
  W->Print();
  //
  delete W;
  ///////////////////////////////////////////////////////////////

  // display number of total suggestions

  system("pause");
  return 0;
}