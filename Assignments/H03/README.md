## Homework - Data Structures and Complexity
#### Due: 03-13-2020 (Friday @ 3:30 p.m.)

- Given a collection of algorithms that runs on **O(1), O(n log n), O(n), O(n<sup>2</sup>), O(log n), O(n!)**, order the algorithms from fastest to slowest. **O(1), O(log n), O(n), O(n log n), O(n<sup>2</sup>), O(n!)**
- Suppose that the complexity of an algorithm is O(n<sup>2</sup>). Suppose that the program that uses the algorithm run in 10 seconds for a data set of size n. If the data size is doubled, how long will it take (approximately) to run the program? **Approximately 14.14 seconds**


- Complexities : **O(1), O(n log n), O(n), O(n<sup>2</sup>), O(log n), O(n!) , O(h)**
1.Finding the max element in an unordered stack would require ___ **O(n)**____ operations?
2. Finding the min element in an unordered queue would require ____ **O(n)**_____ operations?
3. Finding some element in some Binary Search Tree would require ____ **O(h)**_____ operations?
4. Finding some element in a balanced Binary Search Tree would require _____ **O(log(n))**____ operations?
5. Finding some element in an ordered linked list would require ____ **O(n)**_____ operations (worst case)?
6. Finding some element in an ordered linked list would require ____ **O(n/2)**____ operations (average case)?
7. Finding some element in an unordered linked list would require ____ **O(n)**____ operations (worst case)?


8. For each of the following, count the number of operations where some_statement is executed based on the loops

   **O(n<sup>2</sup>)**
```cpp
//A
for (int I = 0; I < n; I++)
    for (int j = 1; j < n; j++)
        {some_statement;}
```
   **O(n<sup>2</sup>/2)**


```cpp
//B
for (int I = 0; I < n; I +=2)
    for (int j = 1; j < n; j++)
        {some_statement;}
```
   **O(nlog(n))**


```cpp
//C
for (int j = 1 ; j < n ; j *= 2)
    for (int I = 1; i<n; i++)
        {some_statement;} 
```



At most, how many comparisons are required to search a sorted vector of 1023 elements using the binary
search algorithm? **About 10**

In each of the following examples, please choose the best data structure(s).
- Options are: **Array, Linked Lists, Stack, Queues, Trees, Graphs, Sets, Hash Tables**. 
- Note that there may not be one clear answer.

1. You have to store social network “feeds”. You do not know the size, and things may need to be dynamically added. **List**
2. You need to store undo/redo operations in a word processor. **Stack**
3. You need to evaluate an expression (i.e., parse). **Stack**
4. You need to store the friendship information on a social networking site. I.e., who is friends with who. **Graph**
5. You need to store an image (1000 by 1000 pixels) as a bitmap. **2D Array**
6. To implement printer spooler so that jobs can be printed in the order of their arrival. **Queue**
7. To implement back functionality in the internet browser. **Stack**
8. To store the possible moves in a chess game. **Directed Graph**
9. To store a set of fixed key words which are referenced very frequently. **Hash Table**
10. To store the customer order information in a drive-in burger place. (Customers keep on coming and they have to get their correct food at the payment/food collection window.) **Queue**
11. To store the genealogy information of biological species. **Tree**
12. To store an alphabetized list of names in order to look up quickly. **Hash Table**
