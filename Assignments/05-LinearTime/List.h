///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Sarah Gilliland
// Email:            sarah13grace@gmail.com
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
/////////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct Node
{
  string term;                  // holds term
  string def;			        //holds definition of term
  Node *Next;                   // pointer to whatever is next
  
  Node(string w, string d)      //Node(string w, string d)
  {
    term = w;
    def = d;
    Next = NULL;
  }
};

class Dictionary
{
    private:
        Node *front;
        Node *end;
        int totalTerms;
        vector<string> substrings;          // 


    public:
        // Default Constructor
        Dictionary()
        {
            front = NULL;
            end = NULL;
            totalTerms = 0;
        }
        // Receives a word and its definition and places them in a node
        // Adds the node to the linked list
        void Add(string word, string def)
        {
            // create new memory
            Node *temp = new Node(word, def);

            // if list is empty hook in new Node
            if (front == NULL)
            {
                front = end = temp;
                temp = NULL;
            }
            else
            {
                // get ready to walk the list
                end->Next = temp;
                end = temp;
                temp = NULL;
            }
        }

        void Search(string someWord)
        {
            string suggestion;          // substring to be inserted in the vector
            Node *Temp = front;         // temporary pointer begins pointing to front of list
            string suggestionSub;       // string variable to hold substrings of suggestion
            int index = 0;              // index for substring vector

            // Search through whole json dictionary file
            while (Temp != NULL)
            {
                // suggestion takes value of the term we are looking at
                suggestion = Temp->term;
                
                // use .substr() to get substrings of suggestion
                // save substring as suggestionSub
                suggestionSub = suggestion.substr(0, someWord.length());
                
                // if someWord is a substring of suggestion, place in substrings vector
                if (someWord == suggestionSub && index < 10)
                {
                    substrings[index] = suggestion;       // adding the suggestion to the substring vector
                    index++;                              // increment index for substrings vector
                    totalTerms++;                         // increment total number of matching terms
                }
                Temp = Temp->Next;                        // move to the next node
            }
        }

        // Prints the first 10 terms of the vector if there are 10 or more
        // or prints all terms if there are less than 10 terms
        void printTenWords()
        {
            // if there are 10 or more substrings
            if (totalTerms >= 10)
            {
                for (int i = 0; i < 10; i++)
                {
                    cout << substrings[i] << '\t';            // print first 10 substrings in the vector to the screen
                }
            }
            // if there are less than 10 substrings
            else
            {
                for (int i = 0; i < totalTerms; i++)
                {
                    cout << substrings[i] << '\t';            // print all substrings in the vector to the screen
                }
            }
        }

        // Gets and returns the private variable totalTerms
        int getTermsFound()
        {
            return totalTerms;                            // return number of matching terms
        }
};