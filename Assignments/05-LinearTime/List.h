///////////////////////////////////////////////////////////////////////////////
//
// Author:           Sarah Gilliland
// Email:            sarah13grace@gmail.com
// Label:            P02
// Title:            Assignment 5 - LinearTime
// Course:           3013
// Semester:         Spring 2020
//
// Description:
//      A linked list that reads in and holds a dictionary. It has nodes which
//  save the term, definition, and a pointer to the next node.
//
/////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/*
Node
*/
struct Node
{
  string term;
  string def;			//holds definition of term
  Node *Next;
  Node(string w, string d)
  {
    term = w;
    def = d;
    Next = NULL;
  }
};

class OldList
{
private:
  Node *front;
  Node *end;
  string firstTen[10];
  vector<string> substrings;
  int totalTerms;
  // Method to get rid of capital letters
  string LowerCase(string input)
  {
    for (int i = 0; i < input.length(); i++)
    {
      if ((int)input[i] < 96)
      {
        input[i] += 32;
      }
    }
    return input;
  }


public:
  OldList()
  {
    Start = NULL;
  }

  ~OldList()
  {
    //cout<<
  }

  void Add(string word, string def)
  {

    word = LowerCase(word);   // make the term all lowercase letters
    def = LowerCase(def);   // make the definition all lowercase letters

    // create new memory
    Node *temp = new Node(word, def);

    // if list is empty hook in new Node
    if (Start == NULL)
    {
      Start = temp;
    }
    else
    {
      // get ready to walk the list
      Node *traverse = Start;
      while (traverse->Next != NULL)
      {
        // walks the list
        traverse = traverse->Next;
      }
      // now at proper place to link in new memory
      traverse->Next = temp;
    }
  }

  string Remove(string key)
  {
    string temp = "";

    if (!front)
    {
      return "";
    }
    else
    {
      Node *cptr = front;
      Node *prev = front;
      while (cptr && cptr->term != key)
      {
        prev = cptr;
        cptr = cptr->Next;
      }
      // if cptr then we found the word
      if (cptr)
      {
        temp = cptr->term;
        prev->Next = cptr->Next;
        delete cptr;
      }
      else
      {
        // no word, return empty
        temp = "";
      }
      return temp;
    }

    return temp;
  }

  int Search(vector<char> someWord)
  {
    string suggestion;          // substring to be inserted in the vector
    int index = 0;              // index of the vector
    Node *Temp = front;

    // Search through whole json dictionary file
    while (Temp != end)
    {
      suggestion = Temp->term;
      // Add all things that someword's characters are substrings of
      // if () someWord is within or equal to suggestion, put it in substrings vector
      if (1 == 1)
      {
        substrings[index] = suggestion;       // adding the suggestion to the substring vector
        index++;          
        totalTerms++;
      }
      Temp = Temp->Next;
    }
  }
  void print(){}
  // void search(string input){}
  void printFirstTen()
  {
    for (int i = 0; i < 10; i++){
      cout << substrings[i] << '\t';
    }
    cout << "\n";
  }

  int getTermsFound(){}

  void ReOrder()
  {
    // pointers for new list
    Node *NewList = NULL;
    Node *Tail = NULL;

    int i;

    while (Start != NULL)
    {

      // helper pointers to manipulate lists
      Node *Ptr = Start;
      Node *Min = Start;
      Node *Prev = Start;
      Node *MinPrev = Start;

      // find one minimum word in old list
      while (Ptr != NULL)
      {
        if (Ptr->term < Min->term)
        {
          MinPrev = Prev;
          Min = Ptr;
        }

        Prev = Ptr;
        Ptr = Ptr->Next;
      }
      //end finding one word in old list

      // add one word to new list

      if (!NewList)
      {
        NewList = Min;
      }
      else
      {
        Tail->Next = Min;
      }

      Tail = Min;
      if (MinPrev == Start)
      {
        Start = Start->Next;
      }
      else
      {
        MinPrev->Next = Min->Next;
      }

      Min->Next = NULL;
      i++;
    }

    Start = NewList;
  }

  void Print()
  {
    Node *temp = Start;
    while (temp)
    {
      cout << temp->term;
      if (temp->Next)
      {
        cout << "->";
      }
      temp = temp->Next;
    }
    cout << endl;
  }
};