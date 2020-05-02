///////////////////////////////////////////////////////////////////////////////
//
// Author:           Sarah Gilliland
// Email:            sarah13grace@gmail.com
// Label:            10440
// Title:            FerryLoading II
// Course:           3013
// Semester:         Spring 2020
// File Name:        main.cpp
//
// Description:
//  This program reads in information about a ferry which transports up to a
//  certain amount of cars in a certain amount of time. The program uses an
//  array to keep track of the number of cars left and when they arrived 
//  with the goal of finding maximum efficiency.
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <stdio.h>

using namespace std;

// Function that displays the desired output
void Display(int time, int trips)
{
    cout << time << " " << trips << '\n';
}

int main()
{
    // declare all variables
    int n, t, m, C, endTime, numTrips, arrival, totalTime, time;
    int cases = 0;

    // read in number of cases
    cin >> C;

    while (cases < C)
    {
        // Read in n, t, and m
        cin >> n >> t >> m;

        // dynamically allocate memory for newCar array
        int *newCar;
        newCar = new int[m];

        // fill newCar array
        for (int i = 0; i < m; i++)
        {
            cin >> arrival;
            newCar[i] = arrival;
        }

        // number of cars taken
        int taken = (m + n - 1) % n;

        // keep track of time
        totalTime = 0;
        time = 0;

        // while there are still cars to take
        while (taken < m)
        {
            // if amt has higher precedence
            if (totalTime > newCar[taken])
            {
                time = totalTime;
            }
            // if the value of newCar[taken] has higher precedence
            else if (totalTime < newCar[taken])
            {
                time = newCar[taken];
            }

            // update the total time
            totalTime = time + 2 * t;

            // load however many cars you can hold
            taken += n;
        }

        // calculate and display endTime and numTrips
        endTime = totalTime - t;
        numTrips = (m + n - 1) / n;
        Display(endTime, numTrips);

        // clear dynamically allocated memory
        delete[] newCar;

        cases++;
    }
    return 0;
}