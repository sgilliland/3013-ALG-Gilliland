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

/**
 * Node
 * 
 * Description:
 *      A struct that creates nodes containing a
 *      term, its definition, and a pointer to the
 *      next node. The nodes will be inserted into
 *      a linked list.
 * 
 * 
 * Private Methods:
 *      Node* 					Next 
 *		string                  term
 *      string                  def
 * 
 *                              Node()         
 *                              Node(string w, string d)
 * Usage: 
 *      Dictionary W;           // create a new node
 */
struct Node
{
  string term;                  // holds term
  string def;			        //holds definition of term
  Node *Next;                   // pointer to whatever is next
  
  Node()                        //Default constructor
  {
    term = "";                  // make term an empty string
    def = "";                   // make def an empty string
    Next = NULL;
  }
  Node(string w, string d)      //Parameterized constructor accepts w and d to be the term and definition
  {
    term = w;                   // term accepts the value of string w
    def = d;                    // def accepts the value of string d
    Next = NULL;
  }
};

/**
 * Dictionary
 * 
 * Description:
 *      A linked list that holds a dictionary and 
 * 	    searches for words containing a substring
 *      of characters
 * 
 * Public Methods:
 *      						Dictionary() 
 *      void 					Add(string word, string def)
 *		void 					Search(string input) 
 * 		void 					printTenWords()
 *      void                    clearVector()
 * 		int 					getTermsFound()
 * 
 * Private Methods:
 *      Node* 					front
 *		Node* 					end	
 *		int 					totalTerms
 *		vector<string>          substrings
 * 
 * Usage: 
 *      Dictionary W;                          // create an instance of the class
 *      W.Add(word, definition);               // add the word to the list
 *      W.Search(Stuff);                       // Begin the search
 *      numSuggestions = W.getTermsFound();    // save the number of matching terms as numSuggestions
 *      W.printTenWords();                     // print the first 10 matching terms (if there are 10)
 *      clearVector();                         // clear the vector of 10 matching terms
 */
class Dictionary
{
private:
    Node *front;               // pointer to front of list
    Node *end;                 // pointer to end of list
    int totalTerms;            // number of matches
    vector<string> substrings; // vector to hold the matching terms

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
        int match = 0;         // num times when there is a match
        Node *temp = new Node; // new temporary node
        temp = front;
        int i = 0; // int to increment

        while (temp != nullptr)
        {
            string check = temp->term;        // check holds term value of the node
            size_t found = check.find(input); // finding if the input is in the term

            if (found != string::npos)
            {
                if (i < 10) // adding 10 terms to the vector
                {
                    substrings.push_back(temp->term);
                    i++;
                }
                match++;
            }
            temp = temp->Next; // move to next node
        }
        totalTerms = match;
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
                cout << substrings[i] << '\t'; // print first 10 substrings in the vector to the screen
            }
        }
        // if there are less than 10 substrings
        else
        {
            for (int i = 0; i < totalTerms; i++)
            {
                cout << substrings[i] << '\t'; // print all substrings in the vector to the screen
            }
        }

        // After printing the words, delete the contents of the vector
        clearVector();
    }

    void clearVector()
    {

        for (int i = 0; i < 10; i++)
        {
            // remove contents of the vector
            substrings.pop_back();
        }
    }

    // Gets and returns the private variable totalTerms
    int getTermsFound()
    {
        return totalTerms; // return number of matching terms
    }
};
