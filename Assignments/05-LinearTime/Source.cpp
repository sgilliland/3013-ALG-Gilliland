///////////////////////////////////////////////////////////////////////////////
//
// Author:           Sarah Gilliland
// Email:            sarah13grace@gmail.com
// Label:            P02
// Title:            A05-LinearTime
// Course:           3013
// Semester:         Spring 2020
// File Name:        Source.cpp
//
// Description:
//  This main function implements a list class called Dictionary. Main will
//  prompt the user to type a few characters and send this new string to the
//  class to find. The class finds other strings stored in Dictionary which
//  contain the passed string. Main calls methods to display these, as well as
//  timing how long it took to search and store information.
//
/////////////////////////////////////////////////////////////////////////////////

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
  Timer Loading;   // creating an object for the timer
  Loading.Start(); // starting timer to time the load


  // create a list to hold the dictionary in
  Dictionary W;

  // open the Json file
  JsonFacade J("dict_w_defs.json");

  // Read dictionary and load the dictionary list
  string key;
  vector<string> keys = J.getKeys();
  for (int i = 0; i < keys.size(); i++)   // while file is not empty
  {
    string word = J.getKey(i);            // word will store terms from json
    string definition = J.getValue(word); // definition will store definitions from json
    W.Add(word, definition);              // add the word and definition to the list
  }


  Loading.End();                // stop timer for loading
  double l = Loading.Seconds(); // save seconds timed as the variable l

  
  string Stuff = "";      // Stuff holds the string of characters read in
  char letter;            // variable for char read in
  int numSuggestions = 0; // variable for total number of suggestions

  // read typed characters and put them into a vector to read as a string
  cout << "\nBegin typing and suggestions may appear.\n\n";
  
  while ((letter = getch()) != '9') // program ends when user types a 9 instead of a letter
  {
    if ((int)letter != 10) // if the letter is a not a space
    {
      // Clear the screen for formatting
      for (int space = 0; space < 15; space++)
      {
        cout << '\n\n';   
      }

      cout << "\nBegin typing and suggestions may appear.\n";

      Stuff += letter; // placing the new character in the vector
      cout << Stuff << '\n';
    }


    Timer Searching;   // creating an object for the timer
    Searching.Start(); // starting timer to time loading the list

    W.Search(Stuff); // Begin the search

    // stop timer and display time taken to search
    Searching.End();                // end timer
    double s = Searching.Seconds(); // save number of seconds as the variable s

    numSuggestions = W.getTermsFound(); // save the number of matching terms as numSuggestions

    // display number of total suggestions
    cout << "\nThere were " << numSuggestions << " words found in " << s << " seconds.\n";
    W.printTenWords(); // print the first 10 matching terms (if there are 10)
    cout << "\n\nTo end, press 9. Otherwise, just continue typing.\n\n\n";
  }
  system("pause");
  return 0;
}