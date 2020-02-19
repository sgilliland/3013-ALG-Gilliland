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
        vector<string> substrings;
 

        // Method to make a string all lowercase letters
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
        Dictionary()
        {
            front = nullptr;
            end = nullptr;
            totalTerms = 0;

        }

        void Add(string word, string def)
        {
            word = LowerCase(word);   // make the term all lowercase letters
            def = LowerCase(def);   // make the definition all lowercase letters

            // create new memory
            Node *temp = new Node(word, def);

            // if list is empty hook in new Node
            if (front == NULL)
            {
                front = temp;
                end = temp;
            }
            else
            {
                // get ready to walk the list
                Node *traverse = front;
                while (traverse->Next != NULL)
                {
                    // walks the list
                    traverse = traverse->Next;
                }
                // now at proper place to link in new memory
                traverse->Next = temp;
                end = temp;
            }
        }

        void Search(string someWord)
        {
            string suggestion;          // substring to be inserted in the vector
            Node *Temp = front;         // temporary pointer begins pointing to front of list
            string suggestionSub;       // string variable to hold substrings of suggestion
            int index = 0;              // index for substring vector

            // Search through whole json dictionary file
            while (Temp != end->Next)
            {
                // suggestion takes value of the term we are looking at
                suggestion = Temp->term;
                
                // use .substr() to get substrings of suggestion
                // save substring as suggestionSub
                suggestionSub = suggestion.substr(0, someWord.length());

                // if someWord is a substring of suggestion, place in substrings vector
                if (someWord == suggestionSub)
                {
                    substrings[index] = suggestion;       // adding the suggestion to the substring vector
                    index++;                              // increment index for substrings vector
                    totalTerms++;                         // increment total number of matching terms
                }
                Temp = Temp->Next;                        // move to the next node
            }
        }

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

        int getTermsFound()
        {
            return totalTerms;                            // return number of matching terms
        }
};