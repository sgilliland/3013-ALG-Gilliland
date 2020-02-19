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
  Timer Loading;        // creating an object for the timer
  Loading.Start();      // starting timer to time the load
  Loading.Sleep(1500);  //milliseconds

  // create a list to hold the dictionary in
  Dictionary *W;  
  W = new Dictionary;

  // read dictionary and load the dictionary list
  ifstream fin("test.json");      // opening json file to read from
  string word;                    // variable to store words read from json

  while(fin>>word)                // while file is not empty
  {
    W->Add(word);                 // add the word to the list
  }

  // stop timer for loading - maybe display to screen to check?
  Loading.End();                        // end timer
  double l = Loading.Seconds();         // save seconds timed as the variable l
  cout << l << " seconds" <<endl;       // just to test the timer
  // read typed characters and put them into a vector to read as a string
  vector<char> input;
  char letter;                          // variable for letter read in
  int index = 0;                        // creating an index for the vector
  while (letter = getch() != ' '){      // loop to read until they press space
    input[index] = letter;              // placing the new character in the vector
    index++;                            // incrementing the index
  }

  int numSuggestions = 0;               // variable for total number of suggestions
  string suggestion;
  // Start loop to loop 10 times
  for (int i = 0; i < 10; i++)
  {
    // start timer for searching dictionary for suggestions
    Timer Searching;        // creating an object for the timer
    Searching.Start();      // starting timer to time the load
    Searching.Sleep(1500);  //milliseconds

    // search for suggestions
    suggestion = "";
    // increment # of suggestions
    numSuggestions++;
    // stop timer and display time taken to search
    Searching.End();                        // end timer
    double s = Searching.Seconds();         // save number of seconds as the variable s

    // display the ith suggestion
    cout << suggestion << '\t';             // ???????
    
  }
    
  
  // What is this ///////////////////////////////////////////////
  delete W;
  ///////////////////////////////////////////////////////////////

  // display number of total suggestions
  cout << "\n\nThere were " << numSuggestions << " in total.";
  
  system("pause");
  return 0;
}