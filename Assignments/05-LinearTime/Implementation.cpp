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

  ifstream fin("dict_w_defs.json");
  string word;

   while(fin>>word)
   {
     W.Add(word);
   }

  //W.Add("Ant");
  W->Add("Dog");
  //W.Add("Aaron");
  //W.Add("Aardvark");
  W->Add("Cow");
  //W.Add("Rabbit");

  W->Print();

  W->ReOrder();

  W->Print();

  delete W;
}