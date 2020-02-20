///////////////////////////////////////////////////////////////////////////////
//
// Author:           Sarah Gilliland
// Email:            sarah13grace@gmail.com
// Label:            P02
// Title:            A05-LinearTime
// Course:           3013
// Semester:         Spring 2020
// File Name:        List.h
//
// Description:
//  This class is a linked list. It reads in words and their corresponding 
//  definitions from a json file and stores them as nodes. Strings containing
//  some combinations of characters are passed in and a search method goes
// through to put all strings which contain the passed in string as a
// substring. The class also has functions to print the first ten resulting
// strings (if there are ten) as well as the number of total matches.
//
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
  
  Node()      //Node()
  {
    term = "";
    def = "";
    Next = NULL;
  }
  Node(string w, string d)      //Node(string w, string d)
  {
    term = w;
    def = d;
    Next = NULL;
  }
};

/**
 * ListDictionary
 * 
 * Description:
 *      A linked list that holds a dictionary and 
 * 		can search for substrings of chars
 * 
 * Public Methods:
 *      						ListDictionary() 
 *      void 					insert(string W, string D)
 *      void 					print()
 *		void 					search(string input) 
 * 		void 					printTenWords()
 * 		int 					getTermsFound()
 * 
 * Private Methods:
 *      Node* 					Head;
 *		Node* 					Tail;	
 *		int 					length;
 *		string 					TenWords[10];
 *		int 					TermsFound;
 * 
 * Usage: 
 *      Dictionary W;                          // create an instance of the class
 *      W.Add(word, definition);               // add the word to the list
 *      W.Search(Stuff);                       // Begin the search
 *      numSuggestions = W.getTermsFound();    // save the number of matching terms as numSuggestions
 *      W.printTenWords();                     // print the first 10 matching terms (if there are 10)
 *      
 */
class Dictionary
{
    private:
        Node *front;
        Node *end;
        int totalTerms;
        vector<string> substrings;          // vector to hold the 


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
        
        void Search(string input)
	    {
            int seen = 0;
            Node* temp = new Node;	
            temp = front;
            int i = 0;

            while (temp != nullptr)
            {
                string check = temp->term;
                size_t found = check.find(input);

                if (found != string::npos)
                {
                    if(i < 10)
                    {
                        substrings.push_back(temp->term);
                        i++;
                    }
                    seen++;
                }
                temp = temp->Next;
            }
            totalTerms = seen; 
            temp = nullptr;
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