///////////////////////////////////////////////////////////////////////////////
// (INCOMPLETE)
// Author:           Sarah Gilliland
// Email:            sarah13grace@gmail.com
// Label:            10261
// Title:            FerryLoading I
// Course:           3013
// Semester:         Spring 2020
// File Name:        main.cpp
//
// Description:
//  This program reads in information about ferries which transports up to a
//  certain amount of cars in a certain amount of time. All cars are a different
//  size, so this impacts which ferry the car should board. The program uses a
//  queue and arrays to keep track of car sizes, when it arrived, and
//  which cars are on which ferries to maximize effeciency - all while 
//  maintaining the original order from the input.
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Function to fill the queue (bank) and the array (order)
void Fill(queue<int> bank[], int *order, int arrival, string side, int m)
{
    // Go through the data and fill the queue and array
    for (int i = 0; i < m; i++)
    {
        // Read in a new car
        cin >> arrival >> side;

        // Load the respective side of the queue with index of order array
        if (side == "left")
            bank[0].push(i);
        else if (side == "right")
            bank[1].push(i);

        order[i] = arrival; // load arrival times in the order from the file
    }
}

// Function to display the output in the correct order
void display(int *results, int m)
{
    for (int i = 0; i < m; i++)
        cout << results[i] << '\n';
}

int main()
{
    // Declaring variables
    int n, t, m, arrival, C, numOnFerry, clock, newTime;
    int cases = 0;
    string side;
    bool leftOrRight; // left will be false

    cin >> C; // Read in number of cases

    // For every case
    while (cases < C)
    {
        // Read in n, t, and m
        cin >> n >> t >> m;

        // bank holds the index of the car on the left or right side
        queue<int> bank[2];
        // order holds the order of the input
        int *order;
        order = new int[m];
        // Begin on the left side each time
        leftOrRight = false;
        // Result holds the resulting time to display
        int *Result;
        Result = new int[m];
        clock = 0;

        Fill(bank, order, arrival, side, m);

        // while there are cars on at least one side
        while (!bank[0].empty() || !bank[1].empty())
        {
            // newTime is the variable for the new time
            newTime = 0;

            if (bank[0].empty()) // Check for left side empty
                newTime = order[bank[1].front()];
            else if (bank[1].empty()) // Check for right side empty
                newTime = order[bank[0].front()];
            else // neither is empty
            {
                if (order[bank[0].front()] <= order[bank[1].front()]) // left arrove first
                    newTime = order[bank[0].front()];
                else // right arrove first
                    newTime = order[bank[1].front()];
            }

            // if clock needs to be updated
            if (newTime >= clock)
                clock = newTime;

            numOnFerry = 0;

            // unload and reload the Ferry
            while ((!bank[leftOrRight].empty()) && (clock >= order[bank[leftOrRight].front()]) && (numOnFerry < n))
            {
                // unload: store the time of unloading into Result
                Result[bank[leftOrRight].front()] = clock + t;
                // reload: pop from bank and increment numOnFerry
                bank[leftOrRight].pop();
                numOnFerry++;
            }

            clock += t; //increment clock

            if (leftOrRight)         // if on right side (true)
                leftOrRight = false; // go to left side (false)
            else                     // if on left side (false)
                leftOrRight = true;  // go to right side (true)
        }

        display(Result, m); // display the results

        // Get rid of allocated memory
        delete[] order;
        delete[] Result;

        cout << '\n';
        cases++;
    }
    return 0;
}