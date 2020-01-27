///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Terry Griffin & Sarah Gilliland
// Email:            sarah13grace@gmail.com
// Label:            A04
// Title:            Linked List Class
// Course:           CMPS 3013
// Semester:         Spring 2020
//
// Description:
//       This program implements a class that allows a linked list to be used just like 
//       an array. It overloads the "[]" (square brackets) to simulate accessing seperate 
//       array elements, but really it traverses the list to find the specified node using
//       an index value. It also overloads the "+" and "-" signs allowing a user to "add"
//       or "push" items onto the end of the list, as well as "pop" items off the end of our 
//       array. This class is not meant to replace the STL vector library, its simply a project
//       to introduce the beginnings of creating complex / abstract data types. 
//       
// Usage: 
//      - $ ./main filename
//      - This will read in a file containing whatever values to be read into our list/array. 
//      
// Files:            
//      main.cpp    : driver program 
//      list.h      : header file with list defintion
//      list.cpp    : list implementation
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

int A[100];                             // Global array of integers with size 100

/**
 * Struct
 * 
 * Description:
 *      This struct implements a node. The node has an integer value that it holds and
 *      a pointer which will point to another node when the node is placed in a list.
 * 
 * Public Methods:
 *                          Node()                               
 *                          Node(val)
 * 
 * 
 * Usage: 
 * 
 *      Node *Head;                     // Create Instance of Node
 *                                                  
 *      Node *Temp = new Node(val);     // Dynamically Allocating a Node that holds a value
 * 
 *      Node();                         // Construct Default Node        
 *      
 */
struct Node
{
    int x;                              // the value to be held by the node
    Node *next;                         // the pointer that points to the next node
    Node()                              // default constructor
    {
        x = -1;                         // has node hold -1 until given a new value
        next = NULL;                    // this is the last node so it points to NULL
    }
    Node(int n)                         // parameterized constructor
    {
        x = n;                          // gives the node a specific value, n, to hold
        next = NULL;
    }
};

/**
 * List
 * 
 * Description:
 *      This class implements a list of nodes. The list has a Head pointer, a Tail pointer and a Size.
 *      The Head pointer will point to the first node in the list and the Tail will point to the
 *      last node in the list. The class uses methods such as insert and push to place the nodes
 *      in the list and uses pop to remove nodes. The Size variable increments and decrements as nodes
 *      are added and removed. There are also methods which will aid in printing the list.
 * 
 * Public Methods:
 *                          List()                               
 *      void                Push(int val)
 *      void                Insert(int val)
 *      void                PrintTail()
 *      string              Print()
 *      int                 Pop()
 *      List                operator+(const List &Rhs)
 *      int                 operator[](int index)
 *      friend ostream      &operator<<(ostream &os, List L)
 * 
 * Private Methods: None
 * 
 * Usage: 
 * 
 *      List L1;                        // Create Instance of List
 *                                                  
 *      L1.Push(i);                     // Push the value in the parameter to the list
 * 
 *      L1.PrintTail();                 // Print the last value in the list 
 *      
 *      List L3 = L1 + L2;              // + and = are overloaded to combine two separate lists
 * 
 *      cout << L3 << endl;             // << is overloaded to print the list with the Print() method
 * 
 *      os << L.Print();                // Print a string containing the value from each node of the list
 * 
 *      cout << L3[5] << endl;          // [] is overloaded to give only the value from a specific node
 *      
 */
class List
{
private:
    Node *Head;                         // Pointer to beginning of List
    Node *Tail;                         // Pointer to end of List
    int Size;                           // Size of List

public:
    List()
    {
        Head = Tail = NULL;             // Default empty list
        Size = 0;
    }

    void Push(int val)
    {
        Node *Temp = new Node(val);     // Allocate new memory and initialize node

        if (!Head && !Tail)             // List is empty
        {
            Head = Tail = Temp;         // Set head and tail to point to the new node
        }
        else                            // List is not empty
        {
            Tail->next = Temp;          // Make previous node point to the new node
            Tail = Temp;                // Make tail point to the new node
        }
        Size++;                         // Increment size
    }

    void Insert(int val)
    {
        
        Node *Temp = new Node(val);     // Allocate new memory and initialize node

        Temp->next = Head;
        Head = Temp;
        if (!Tail)                      // Tail was pointing to NULL
        {
            Tail = Head;                // Tail points to what Head points to
        }
        Size++;                         // Increment size
    }

    void PrintTail()
    {
        cout << Tail->x << endl;        // Print the value of the last node
    }
    
    string Print()
    {
        Node *Temp = Head;              // Get a reference to beginning of local list
        string list;                    // String which will hold all values from List

        while (Temp != NULL)            // List is not empty
        {                               // All values from the list are added to the string
                                        // and separated by arrows
            list += to_string(Temp->x) + "->";
            Temp = Temp->next;          
        }

        return list;                    // Return the new string of the values from List
    }

    // not implemented
    int Pop()
    {
        Size--;                         // Decrement size
        return 0;
    }

    List operator+(const List &Rhs)
    {
        
        List NewList;                   // Create a new list that will contain both when done

        
        Node *Temp = Head;              // Get a reference to beginning of local list

        
        while (Temp != NULL)            // Loop through local list and Push values onto new list
        {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }


        Temp = Rhs.Head;                // Get a reference to head of Rhs


        while (Temp != NULL)            // Same as above, loop and push
        {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }


        return NewList;                 // Return new concatenated version of lists
    }

                                        // Implementation of [] operator.  This function returns an
                                        // int value as if the list were an array.
    int operator[](int index)
    {
        Node *Temp = Head;              // Get a reference to beginning of local list


        if (index >= Size)              // If index is out of bounds, display an error message
        {
            cout << "Index out of bounds, exiting";
            exit(0);
        }
        else                            // Index is within bounds
        {

            for (int i = 0; i < index; i++)
            {
                Temp = Temp->next;      // Make temp point to the correct index
            }
            return Temp->x;             // Return the value help by the node in the location of index
        }
    }

    friend ostream &operator<<(ostream &os, List L)
    {
        os << L.Print();                // Calls the Print() method to print all values in the list
        return os;
    }
};

int main(int argc, char **argv)
{
    List L1;                            // First list object
    List L2;                            // Second list object

    for (int i = 0; i < 25; i++)        // Loop where i has the values 0 through 24
    {
        L1.Push(i);                     // Pushes the value of i to the first list
    }

    for (int i = 50; i < 100; i++)      // Loop where i has the values 50 through 99
    {
        L2.Push(i);                     // Pushes the new value of i to the second list
    }

    //cout << L1 << endl;
    L1.PrintTail();                     // Prints the last node of the first list
    L2.PrintTail();                     // Prints the last node of the second list

    List L3 = L1 + L2;                  // Uses overloaded operators to combine the first
                                        // and second list and saves as a third list
    
    cout << L3 << endl;                 // Uses overloaded operators to print all values
                                        // of the third list to the screen

    cout << L3[5] << endl;              // Uses overloaded operators to print
                                        // only the 5th node's value from the third list
    return 0;
}