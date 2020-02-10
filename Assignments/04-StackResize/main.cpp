
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
class ArrayStack
{
private:
	int *A;			 		 			   // pointer to array of int's
	int size;		 		 			   // current stack size
	int maxSize;	 		 			   // current max stack size
	int top;		 		 			   // top of stack
	int numResize;   		 			   // number of times stack is resized
	int currentSize; 		 			   // the number of elements in the stack

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
	ArrayStack()
	{
		size = 10;		     			   // size takes value of 10
		maxSize = size;		 			   // size is the maximum size reached
		A = new int[size];   			   // intantiating an array
		top = -1;		     			   // stack is empty
		numResize = 0;	     			   // nothing has been resized yet
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
	ArrayStack(int s)
	{
		size = s;		     			   // size takes value of s
		maxSize = size; 	 			   // size is the maximum size reached
		A = new int[s]; 	    		   // intantiating an array of size s
		top = -1;			 			   // stack is empty
		numResize = 0;  	 			   // nothing has been resized yet
	}

	/**
	* getNumResize
	*
	* Description:
	*      Getter function for the private variable numResize
	*
	* Params:
	*     - NULL
	*
	* Returns:
	*     - [int] numResize
	*/
	int getNumResize()
	{
		return numResize; 	    			// returns private variable numResize
	}

	/**
	* getMaxSize
	*
	* Description:
	*      Getter function for the private variable maxSize
	*
	* Params:
	*     - NULL
	*
	* Returns:
	*     - [int] maxSize
	*/
	int getMaxSize()
	{
		return maxSize; 	 			   // returns private variable maxSize
	}

	/**
	* getSize
	*
	* Description:
	*      Getter function for the private variable size
	*
	* Params:
	*     - NULL
	*
	* Returns:
	*     - [int] size
	*/
	int getSize()
	{
		return size; 		 			   // returns private variable size
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
	bool HalfEmpty()
	{
		return (top <= size / 2); 		   // returns true if the stack is half-empty
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
	bool Empty()
	{
		return (top <= -1);  		   	   // returns true if the stack is empty
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
	bool Full()
	{
		return (top >= size - 1); 		   // returns true if the stack is full
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
	int Peek()
	{
		if (!Empty()) 		 			   // if stack is not empty
		{
			return A[top]; 	 			   // returns value at top of stack
		}

		return -99; 		 			   // some sentinel value if stack is empty
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
	int Pop()
	{
		if (!Empty()) 		 			   // if stack is not empty
		{
			top--;		   	 			   // decrement top
			CheckResize();   			   // check for decreasing the size of the stack
			return A[top];   			   // return the value for top
		}

		return -99; 		 			   // some sentinel value if stack is empty
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
	void Push(int x)
	{
		CheckResize(); 		 			   // Check for decreasing the size of the stack
		if (!Full())   		 			   // If stack isn't full
		{
			A[++top] = x; 	 			   // Add x to the top of the stack
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
	void ContainerGrow()
	{
		int newSize = size * 1.75; 		   // newSize is 1.75 times bigger than size
		int *B = new int[newSize]; 		   // allocate new memory

		for (int i = 0; i < newSize; i++)
		{
			B[i] = A[i]; 	 			   // copy values to new array
		}

		delete[] A; 		 			   // delete old array

		if (newSize >= maxSize) 		   // if newSize > current maxSize
		{
			maxSize = newSize; 			   // maxSize will now be newSize
		}
		size = newSize; 	 			   // save new size

		A = B;		  		 			   // reset array pointer
		numResize++; 		 		   	   // increment numResize
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
	void ContainerShrink()
	{
		int newSize = size * 0.5;  		   // newSize is half of size
		int *B = new int[newSize]; 		   // allocate new memory

		for (int i = 0; i < newSize; i++)
		{
			B[i] = A[i]; 	 			   // copy values to new array
		}

		delete[] A; 		 			   // delete old array

		size = newSize; 	 			   // save new size

		A = B;		 		 			   // reset array pointer
		numResize++; 		 			   // increment numResize
	}

	/*
	* Public void: CheckResize
	*
	* Description :
	*	   Checks to see if the stack needs to be
	*	   resized, and whether it should grow or shrink.
	*	   Does not allow stack to reach a size < 10.
	*
	* Params :
	*	   NULL
	*
	* Returns :
	*	   NULL
	*/
	void CheckResize()
	{
		if (Full()) 					   // if stack is full
		{
			ContainerGrow(); 			   // increase the size of the container
		}
		else if (HalfEmpty() && size > 20) // if stack is more than half empty
		{
			ContainerShrink(); 			   // shrink the stack
		}
		else if (HalfEmpty() && size < 20) // if the size is less than 20,
		{								   // but needs to shrink
			int newSize = 10;			   // change size of stack to 10
			int *B = new int[newSize];	   // allocate new memory

			for (int i = 0; i < newSize; i++)
			{
				B[i] = A[i]; 			   // copy values to new array
			}

			delete[] A; 				   // delete old array

			size = newSize; 			   // save new size

			A = B; 						   // reset array pointer
			numResize++;
		}
	}
};

void Print(ofstream &outfile, ArrayStack &stack);

// MAIN DRIVER
// Simple Array Based Stack Usage:
int main()
{
	ArrayStack stack; 					   // Defining the stack and variables
	int num = 0;	  					   // num represents the number read from the file

	ifstream infile; 					   // Open the files
	ofstream outfile;
	infile.open("nums_test.dat");
	outfile.open("out.txt");

	while (!infile.eof()) 				   // Loop until file is enpty
	{
		infile >> num;		 			   // Read in a number from the file
		if (num % 2 == 0)				   // num is even
			stack.Push(num); 			   // push num to stack
		else				 			   // num is odd
			stack.Pop();	 			   // pop an even number from the end of the stack
	}
	Print(outfile, stack); 				   // Call function to print the results
}

/**
  * Public void: Print
  *
  * Description:
  *      Prints max size of stack, number of times
  *      stack was resized, and ending size of stack
  *
  * Params:
  *      [ outfile ] : allows the function to print to a file
  *      [ stack ] : gives the function access to the stack
  *
  * Returns:
  *      NULL
  */
void Print(ofstream &outfile, ArrayStack &stack)
{
	outfile << "****************************************************\n";
	outfile << "\t\tAssignment 4 - Resizing the Stack\n" 
		<< "\t\tCMPS 3013\n\t\tSarah Gilliland\n\n";
	outfile << "\t\tMax Stack Size: " 
		<< stack.getMaxSize() << '\n';		   // Print max size of stack
	outfile << "\t\tEnd Stack Size: "
		<< stack.getSize() << '\n';			   // Print final size of stack
	outfile << "\t\tStack Resized:  " 
		<< stack.getNumResize() << " times\n"; // Print number of resizes
	outfile << "****************************************************\n";
}