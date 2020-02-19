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
  Dictionary *W;

  W = new Dictionary;
  
  ifstream fin("test.json");
  string word;

   while(fin>>word)
   {
     W->Add(word);
   }

  W->Print();

  W->ReOrder();

  W->Print();

  delete W;
}