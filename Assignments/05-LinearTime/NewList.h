// New Linked List bc i'm going insane
#pragma once
#include <string>
#include <iostream>
using namespace std;

struct Node
{
  string term;          // holds term
  string def;			//holds definition of term
  Node *Next;           // pointer to whatever is next
  
  Node(string w, string d) //Node(string w, string d)
  {
    term = w;
    def = d;
    Next = NULL;
  }
};

class NewList
{
    private:
        Node *front;
        Node *end;
        int totalTerms;

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
        NewList()
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
        
        void print()
        {
            //print stuff
        }
        void search(string input)
        {
            // some algorithm here to find subsets of input and words that input is a subset of
        }
        void printTenWords(string tenWords[10])
        {
            for (int i = 0; i < 10; i++)
            {
                cout << tenWords[i];
            }
        }
        int getTermsFound()
        {
            return totalTerms;
        }
};