// Sarah Gilliland
#include <iostream>
#include <string>
#include <fstream>
#include "NewList.h"
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


  // create a list to hold the dictionary in
  Dictionary *W;  
  W = new Dictionary;


  // open the Json file
  ifstream fin("test.json");                // opening json file to read from
  string word;                              // variable to store words read from json
  string definition;                        // variable to store definitions read from json

  // Read dictionary and load the dictionary list
  while(fin>>word>>definition)              // while file is not empty
  {
    W->Add(word, definition);               // add the word to the list
  }

  // stop timer for loading - display to screen to check?
  Loading.End();                            // end timer
  double l = Loading.Seconds();             // save seconds timed as the variable l
  cout << l << " seconds" <<endl;           // just to test the timer
  
  cout << "To exit the program, type 9";
  
  // read typed characters and put them into a vector to read as a string
  string input = "";
  char letter;                              // variable for letter read in
  int index = 0;                            // creating an index for the vector
  int numSuggestions = 0;                   // variable for total number of suggestions

  while (letter = getch() != '9')           // program ends when user types a 9 instead of a letter
  {
    while (letter = getch() != ' ')         // loop to read until they press space
    {
      input += letter;                      // placing the new character in the vector
      cout << letter;
    }

    // start timer for searching dictionary for suggestions
    Timer Searching;                        // creating an object for the timer
    Searching.Start();                      // starting timer to time the load

    // Begin the search
    W->Search(input);

    // stop timer and display time taken to search
    Searching.End();                        // end timer
    double s = Searching.Seconds();         // save number of seconds as the variable s
      
    numSuggestions = W->getTermsFound();

    W->printTenWords();
    // display number of total suggestions
    cout << "\n\nThere were " << numSuggestions << " in total.";
    cout << "\nTo go again, go ahead and type your next word.";
  }
  
  

  
  
  // Deallocate memory ?
  delete W;

  system("pause");
  return 0;
}