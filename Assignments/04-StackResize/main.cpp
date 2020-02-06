
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
class ArrayStack {
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
	ArrayStack() {
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
	ArrayStack(int s) {
		size = s;
		maxSize = size;
		A = new int[s];
		top = -1;
		numResize = 0;
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
	int getNumResize() {
		return numResize;
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
	int getMaxSize() {
		return maxSize;
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
	int getSize() {
		return size;
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
	bool HalfEmpty() {
		return (top <= size / 2);
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
	bool Empty() {
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
	bool Full() {
		return (top >= size - 1);
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
	int Peek() {
		if (!Empty()) {
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
	int Pop() {
		if (!Empty()) {
			top--;
			CheckResize();                  // Check for decreasing the size of the stack
			return A[top];

		}

		return -99;                       // some sentinel value
										  // not a good solution
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
	void Push(int x) {
		CheckResize();						// Check for decreasing the size of the stack
		if (!Full()) {                      // If stack isn't full
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
	void ContainerGrow() {
		int newSize = size * 1.75;             // double size of original
		int *B = new int[newSize];        // allocate new memory

		for (int i = 0; i < newSize; i++) {          // copy values to new array
			B[i] = A[i];
		}

		delete[] A;                      // delete old array

		if (newSize >= maxSize) {          // if the new size > current maxSize
			maxSize = newSize;
		}
		size = newSize;                   // save new size

		A = B;                            // reset array pointer
		numResize++;					  // increment numResize
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
	void ContainerShrink() {
		int newSize = size / 2;           // cut size of original in half
		int *B = new int[newSize];        // allocate new memory

		for (int i = 0; i < newSize; i++) {          // copy values to new array
			B[i] = A[i];
		}

		delete[] A;                      // delete old array

		size = newSize;                   // save new size

		A = B;                            // reset array pointer
		numResize++;
	}

	/*
	* Public void: CheckResize
	*
	* Description :
	*	   Checks to see if the stack needs to be
	*	   resized, and whether it should grow or shrink
	*
	* Params :
	*	   NULL
	*
	* Returns :
	*	   NULL
	*/
	void CheckResize() {
		if (Full()) {
			ContainerGrow();
		}
		else if (HalfEmpty() && size > 20) {
			ContainerShrink();
		}
		else if (HalfEmpty() && size < 20) {
			int newSize = 10;		          // changes size of stack to 10
			int *B = new int[newSize];        // allocate new memory

			for (int i = 0; i < newSize; i++) {          // copy values to new array
				B[i] = A[i];
			}

			delete[] A;                      // delete old array

			size = newSize;                   // save new size

			A = B;                            // reset array pointer
			numResize++;
		}
	}
};

void Print(ofstream& outfile, ArrayStack& stack);

// MAIN DRIVER
// Simple Array Based Stack Usage:
int main() {
	// Defining the stack and variables
	ArrayStack stack;
	int num = 0;
	int even = 0;
	int odd = 0;
	// Open the files
	ifstream infile;
	ofstream outfile;
	infile.open("nums_test.dat");
	outfile.open("out.txt");

	while (!infile.eof())               // Loop until file is enpty
	{
		infile >> num;                    // Read in a number from the file
		if (num % 2 == 0) 				        // num is even
			stack.Push(num);			          // push num to stack            
		else							                // num is odd
			stack.Pop();				            // pop an even number from the end of the stack
	}
	Print(outfile, stack);              // Call function to print the results
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
void Print(ofstream& outfile, ArrayStack& stack) {
	outfile << "****************************************************\n";
	outfile << "\t\tAssignment 4 - Resizing the Stack\n\t\tCMPS 3013\n\t\tSarah Gilliland\n\n";
	outfile << "\t\tMax Stack Size: " << stack.getMaxSize() << '\n';				// Print max size of stack (maxSize)
	outfile << "\t\tEnd Stack Size: " << stack.getSize() << '\n';                   // Print the final size of the stack (size)
	outfile << "\t\tStack Resized:  " << stack.getNumResize() << " times\n";			// Print the number of resizes (numResize)
	outfile << "****************************************************\n";
}