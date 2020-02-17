#include <iostream>

using namespace std;

/**
 * Class Heap
 * 
 * @methods:
 *      constructors:
 *          Heap        : default constructor
 *          Heap(int)   : overload constructor with heap size
 *      private:
 *          BubbleUp    : moves a number up to its correct place
 *          Left        : finds index of left child
 *          OnHeap      : checks if a value is on the heap
 *          Parent      : finds parent index of a child index
 *          Right       : finds index of right child
 *          Swap        : swaps values of two indices
 *          Heapify     : takes an array and puts all values in a heap
 *          SinkDown    : sorts heap after an item is removed
 *          PickChild   : picks the smaller child or the only child
 *      public:
 *          Insert      : adds an item to the heap
 *          Print       : prints the contents of the heap to the screen
 *          Remove      : removes and item from the heap
 */
class Heap {
private:
    int size; // size of the array
    int *H;   // array pointer
    int end;  // 1 past last item in array

    /**
   * BubbleUp
   * 
   * @description: 
   *    This puts one value into its proper
   *    place in the heap.
   * 
   * @param  {int} index : index to start bubbling at
   * @return             : void
   */
    void BubbleUp(int index) {
        // check parent is not of beginning of heap
        if (Parent(index) >= 1) {
            // index is on array and value is less than parent
            while (index > 1 && H[index] < H[Parent(index)]) {
                // do a swap
                Swap(index, Parent(index));

                // update index to values new position
                index = Parent(index);
            }
        }
    }

    /**
     * Left
     * @description:
     *      Calculates index of left child.
     * 
     * @param  {int} index : index of parent
     * @return {int}       : index of left child
     */
    int Left(int index) {
        return 2 * index;
    }

    /**
     * OnHeap
     * @description:
     *      Checks if an index is on the array (past the end).
     * 
     * @param  {int} index : index to check
     * @return {bool}      : 0 = off heap / 1 = on heap
     */
    bool OnHeap(int index) {
        return index < end;
    }

    /**
     * Parent
     * @description:
     *      Calculates parent of a given index.
     * 
     * @param  {int} index : index to check
     * @return {int}       : parent index
     */
    int Parent(int index) {
        return index / 2;
    }

    /**
     * Right
     * @description:
     *      Calculates index of right child.
     * 
     * @param  {int} index : index of parent
     * @return {int}       : index of right child
     */
    int Right(int index) {
        return 2 * index + 1;
    }

    /**
     * Swap
     * 
     * @description: 
     *      Swaps to values in the heap
     * 
     * @param  {int} i  : index in array
     * @param  {int} j  : index in array
     * @return          : void
     */
    void Swap(int i, int j) {
        int temp = H[i];
        H[i] = H[j];
        H[j] = temp;
    }

    /**
     *  Heapify
     * @description:
     *      Creates a heap and uses the Insert method to copy all values from 
     *      a given array into their specific order in the heap.
     * 
     * @param  {int*} A   :  array pointer with unsorted values to make into a heap
     * @param  {int} size :  size of new heap
     * @return            :  void
     */
    void Heapify(int* A, int size) {                        
        for (int i = 1; i <= size; i++){
            Insert(A[i]);                                   // inserting all values from array into the heap
        }
    }

    /**
     * SinkDown
     * @description:
     *      Places one heap item into its proper place in the heap
     *      by bubbling it down to it proper location.
     * 
     * @param  {int} index  : index to start from in the array
     * @return              : void 
     */
    void SinkDown(int index) { 
        if (H[Left(index)] > H[index] && Left(index) < end){                // if left child is greater than parent
            Swap(index, Left(index));                                       // swap parent and left child
            SinkDown(Left(index));                                          // call function recursively
        }
        else if (H[Right(index)] > H[index] && Right(index) < end){         // if right child is greater than parent
            Swap(index, Right(index));                                      // swap parent and right child
            SinkDown(Right(index));                                         // call function recursively
        }
    }

    /**
     * PickChild
     * @description:
     *      If one child exists, return it.
     *      Otherwise, return the smaller of the two.
     * 
     * @param  {int} index  : index of parent in the array
     * @return              : index to child 
     */
    int PickChild(int index) {
        if (Right(index) == end)                             // check if only child
            return H[Left(index)];

        if (H[Left(index)] <=  H[Right(index)])              // left child is the smallest
            return H[Left(index)];                           // return the left child
            
        else if (H[Left(index)] >  H[Right(index)])          // right child is the smallest
            return H[Right(index)];                          // returns the right child

        else                                                 // there are no children
            return 0;                                        // return a zero
    }

public:
    /**
   * Heap constructor
   */
    Heap() {
        size = 100;
        H = new int[size];
        end = 1;
    }

    /**
   * Heap constructor
   * 
   * @param  {int} s : heap size 
   */
    Heap(int s) {
        size = s;
        H = new int[s];
        end = 1;
    }

    /**
   * Insert
   * 
   * @description:
   *        Add a value to the heap.
   * 
   * @param  {int} x : value to Insert
   * @return         : void
   */
    void Insert(int x) {
        H[end] = x;
        BubbleUp(end);
        end++;
    }

    /**
     * For testing our heap !!!  
     */
    void Print() {
        for (int i = 1; i <= end - 1; i++) {
            cout << H[i];
            if (i < end - 1) {
                cout << "->";
            }
        }
    }

    /**
     * Remove
     * @description:
     *      Removes item from top of heap
     * 
     * @return {int}  : top of heap
     */
    int Remove() {
        int temp = H[1];
        H[1] = H[end];
        --end;
        SinkDown(1);            // call SinkDown method to start from index 1
        return temp;
    }
};

int main() {
    Heap H;

    H.Insert(17);
    H.Insert(11);

    for (int i = 1; i <= 10; i++) {
        H.Insert(i);
    }

    H.Print();
}
