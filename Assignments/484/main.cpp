///////////////////////////////////////////////////////////////////////////////
//
// Author:           Sarah Gilliland
// Email:            sarah13grace@gmail.com
// Label:            484
// Title:            The Department of Redundancy Department
// Course:           3013
// Semester:         Spring 2020
// File Name:        main.cpp
//
// Description:
//  This program reads in a list of integers and deletes all duplicates. To do
//  this, the program uses creates a map of each number and it's number of
//  occurances, as well as a vector of the "keys" or the number being searched.
//  This program will display each number and it's number of occurances.
// 
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    vector<int> KeyVec; // vector of keys
    map<int, int> m;    // holds pair of number and occurances
    int key;            // variable to hold the current number

    while (cin >> key) // read a number from the file
    {

        if (m.find(key) == m.end()) // if key is not already in map
        {
            KeyVec.push_back(key); // push key to vector of keys
            m[key] = 1;            // set occurance to 1
        }
        else                         // key is in the map
            ++(m.find(key)->second); // increment occurance of the key & don't add key
    }

    // display
    for (int i = 0; i < KeyVec.size(); i++)
    {
        cout << KeyVec[i] << ' ' << m[KeyVec[i]] << '\n';
    }
    return 0;
}