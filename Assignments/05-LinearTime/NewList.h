// New Linked List bc i'm going insane
#pragma once
#include <string>
using namespace std;

struct Node
{
  string term;
  string def;			//holds definition of term
  Node *Next;

};

class NewList{
    private:
        Node *front = nullptr;
        Node *end = nullptr;
        
    public:
        
};