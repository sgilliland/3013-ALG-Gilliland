
///////////////////////////////////////////////////////////////////////////////
//
// Author:           Sarah Gilliland
// Email:            sarah13grace@gmail.com
// Label:            P01
// Title:            Program 01 - Resize the Stack
// Course:           3013
// Semester:         Spring 2020
//
// Description:
//      Resizing an array based stack so that if the stack gets full, it
//      is doubled in capacity and if it gets halfway empty, it shrinks
//      in size to half of its capacity.
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>

using namespace std;

/**
 * ArrayStack
 * 
 * Description:
 *      Array based stack
 * 
 * Public Methods:
 *      - See class below
 * 
 * Usage: 
 *      - See main program
 *      
 */
class ArrayStack{
private:
  int *A;                             // pointer to array of int's
  int size;                           // current stack size
  int maxSize;                        // current max stack size
  int top;                            // top of stack
  int numResize;                      // times stack is resized
  int currentSize;                    // the number of elements in the stack

public:
 /**
  * ArrayStack
  * 
  * Description:
  *      Constructor no params
  * 
  * Params:
  *     - None
  * 
  * Returns:
  *     - NULL
  */
  ArrayStack(){
    size = 10;
    maxSize = size;
    A = new int[size];
    top = -1;
    numResize = 0;
  }

 /**
  * ArrayStack
  * 
  * Description:
  *      Constructor size param
  * 
  * Params:
  *     - int size
  * 
  * Returns:
  *     - NULL
  */
  ArrayStack(int s){
    size = s;
    maxSize = size;
    A = new int[s];
    top = -1;
    numResize = 0;
  }
 

 /**
  * Public bool: HalfEmpty
  * 
  * Description:
  *      Stack half empty?
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      [bool] true = stack half empty
  */
  bool HalfEmpty(){
    return (top <= size/2);
  }
  
  /**
  * Public bool: Empty
  * 
  * Description:
  *      Stack empty?
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      [bool] true = empty
  */
  bool Empty(){
    return (top <= -1);
  }

 /**
  * Public bool: Full
  * 
  * Description:
  *      Stack full?
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      [bool] true = full
  */
  bool Full(){
    return (top >= size-1);
  }

 /**
  * Public int: Peek
  * 
  * Description:
  *      Returns top value without altering the stack
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      [int] top value if any
  */
  int Peek(){
    if(!Empty()){
      return A[top];
    }
    
    return -99;                       // some sentinel value
                                      // not a good solution
  }

 /**
  * Public int: Pop
  * 
  * Description:
  *      Returns top value and removes it from stack
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      [int] top value if any
  */
  int Pop(){
    if(!Empty()){
      top--;
      CheckResize();                  // Check for decreasing the size of the stack
      return A[top];
      
    }

    return -99;                       // some sentinel value
                                      // not a good solution
  }

 /**
  * Public void: Print
  * 
  * Description:
  *      Prints max size of stack, number of times 
  *      stack was resized, and ending size of stack
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      NULL
  */
  void Print(){
    cout << "The maximum capacity reached was " << maxSize << '\n';   // Print max size of stack (maxSize)
    cout << "The stack was resized " << numResize << "times\n";   // Print the number of resizes (numResize)
    cout << "The ending size is " << size << '\n';   // Print the final size of the stack (size)
  } 

 /**
  * Public bool: Push
  * 
  * Description:
  *      Adds an item to top of stack
  * 
  * Params:
  *      [int] : item to be added
  * 
  * Returns:
  *      NULL
  */
  void Push(int x){
    CheckResize();                    // Check for decreasing the size of the stack
    if(!Full()){                      // If stack isn't full
      A[++top] = x;                   // Add x to the top of the stack
    }
    
  }

 /**
  * Public void: ContainerGrow
  * 
  * Description:
  *      Resizes the container for the stack by doubling
  *      its capacity
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      NULL
  */
  void ContainerGrow(){
    int newSize = size*2;             // double size of original
    int *B = new int[newSize];        // allocate new memory

    for(int i=0;i<size;i++){          // copy values to new array
      B[i] = A[i];
    }

    delete [] A;                      // delete old array

    if (newSize >= maxSize){          // if the new size > current maxSize
      maxSize = newSize;
    }
    size = newSize;                   // save new size

    A = B;                            // reset array pointer

  }

  /**
  * Public void: ContainerShrink
  * 
  * Description:
  *      Resizes the container for the stack by cutting
  *      its capacity in half
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      NULL
  */
  void ContainerShrink(){
    int newSize = size*0.5;           // cut size of original in half
    int *B = new int[newSize];        // allocate new memory

    for(int i=0;i<size;i++){          // copy values to new array
      B[i] = A[i];
    }

    delete [] A;                      // delete old array

    size = newSize;                   // save new size

    A = B;                            // reset array pointer

  }
  void CheckResize(){
      if (Full()){
        ContainerGrow();
      }
      else if (HalfEmpty()){
        ContainerShrink();
      }
  }

};

// MAIN DRIVER
// Simple Array Based Stack Usage:
int main() {
  // Defining the stack and variables
  ArrayStack stack;
  int num = 0;

  // Open the file
  ifstream infile;
	ofstream outfile;
  infile.open("commands.dat");
  // outfile.open(inFileName);

                
  infile >> num;                      // Read in a number from the file
  while (!infile.eof())               // Loop until file is enpty
  {
    if (num % 2 == 0)                 // num is even
      stack.Push(num);                // push num to stack
    else                              // num is odd
      stack.Pop();                    // pop an even number from the end of the stack

    infile >> num;                    // Read in a new number and begin loop again
  }
  stack.Print();
}