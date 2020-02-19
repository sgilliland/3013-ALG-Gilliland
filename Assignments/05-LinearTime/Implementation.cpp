

#include <iostream>
#include <string>
#include <fstream>
#include "List.h"

using namespace std;

int main()
{
  Dictionary *W;

  W = new Dictionary;

  ifstream fin("dictionary.txt");
  string word;

  // while(fin>>word){
  //   W.Add(word);
  // }

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