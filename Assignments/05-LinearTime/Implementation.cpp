///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Sarah Gilliland
// Email:            sarah13grace@gmail.com
// Label:            P02
// Title:            05-LinearTime
// Course:           CMPS 301
// Semester:         (semester and year)
// Title:            List.h
//
// Description:
//          This class is a linked list. It reads in words and their
//          corresponding definitions and stores them as nodes.
//
// Usage:
//
//      
//
// Files:           
//      None?
/////////////////////////////////////////////////////////////////////////////////#include <iostream>
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


  // create a list to hold the dictionary in
  Dictionary W;


  // open the Json file
  JsonFacade J("test.json");                // create instance of json class

  string word;                              // variable to store words read from json
  string definition;                        // variable to store definitions read from json


  // Read dictionary and load the dictionary list
  string key;
  vector<string> keys = J.getKeys();
  for (int i = 0; i < keys.size(); i++)     // while file is not empty
  {
    word = J.getKey(i);
    definition = J.getValue(word);
    W.Add(word, definition);               // add the word to the list
  }

  // stop timer for loading - display to screen to check?
  Loading.End();                            // end timer
  double l = Loading.Seconds();             // save seconds timed as the variable l
  
  
  // read typed characters and put them into a vector to read as a string
  string input = "";
  char letter;                              // variable for letter read in
  int numSuggestions = 0;                   // variable for total number of suggestions


  while (letter = getch() != '9')           // program ends when user types a 9 instead of a letter
  {
    cout << "Begin typing and type a space when you want suggestions.\n";

    input += letter;                      // placing the new character in the vector
    cout << letter;


    Timer Searching;                        // creating an object for the timer
    Searching.Start();                      // starting timer to time loading the list


    W.Search(input);                       // Begin the search


    // stop timer and display time taken to search
    Searching.End();                        // end timer
    double s = Searching.Seconds();         // save number of seconds as the variable s
    
    numSuggestions = W.getTermsFound();    // save the number of matching terms as numSuggestions
    W.printTenWords();                     // print the first 10 matching terms (if there are 10)
    // display number of total suggestions
    cout << "\n\nThere were " << numSuggestions << " in total.";
    cout << "\nTo end, press 9. To continue, just begin typing and type a space for suggestions.\n";
  }

  system("pause");
  return 0;
}