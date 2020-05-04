///////////////////////////////////////////////////////////////////////////////
// 
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
//  queue and vector to keep track of car sizes and which cars are on which 
//  side to maximize effeciency - all while maintaining the original order from 
//  the input.
//
/////////////////////////////////////////////////////////////////////////////////

#include <queue>
#include <iostream>
#include <string>

using namespace std;

// Display the number of cars loaded and their respective sides
void Display(vector<string> side);

int main()
{
    int ferrySize, carSize, index, C;
    int cases = 0;
    // int loaded;

    // all car sizes are stored onto a queue in order of arrival
    queue<int> waiting;

    cin >> C; // Read in number of cases

    // For every case
    while (cases < C)
    {
        // Read in n, t, and m
        cin >> ferrySize;

        // convert meters to centimeters
        ferrySize *= 100;

        // vector to hold the resulting sides in order
        vector<string> side;

        // fill queue with sizes of waiting cars
        cin >> carSize;
        while (carSize != 0)
        {
            waiting.push(carSize);
            cin >> carSize;
        }

        bool canLoad = true;

        int left = 0;        // size of the line of cars on left side
        int right = 0;       // size of the line of cars on right side
        
        int temp;
        bool lastSide; // variable to keep track of last loaded side

        // while there are cars to load and the ferry can hold more cars
        while (!waiting.empty() && canLoad)
        {
            // if theres room on port side for waiting.front()
            if (ferrySize >= (waiting.front() + left) && left >= 0)
            {
                side.push_back("port");  
                left += waiting.front(); // add car size to length of left side
                temp = waiting.front();  // let temp hold lateset carSize
                waiting.pop();          
                lastSide = true;         // true for left
            }
            // if theres room on starboard side for waiting.front()
            else if (ferrySize >= (waiting.front() + right) && right >= 0)
            {
                side.push_back("starboard"); 
                right += waiting.front();    // add car size to length of right side
                temp = waiting.front();      // let temp hold lateset carSize
                waiting.pop();               
                lastSide = false;            // false for right
            }
            // if theres no room on either side
            else
                canLoad = false;

            // Received help from Dakota Wilson for this if statement
            // Checks for same-sized cars so that the ferry is balanced
            if (temp == waiting.front() && canLoad && !waiting.empty())
            {
                if (!lastSide) // if last side loaded was right
                {              // load to left side
                    left += waiting.front();
                    waiting.pop();
                    side.push_back("port");
                }
                else if (lastSide) // if last side loaded was left
                {                  // load to right side
                    right += waiting.front();
                    waiting.pop();
                    side.push_back("starboard");
                }
            }
        }

        // empty the cars left in the queue
        while (!waiting.empty())
        {
            waiting.pop();
        }

        // call to Display function
        Display(side);

        cases++;

        // for output formatting
        if (cases != C)
            cout << '\n';
    }
    return 0;
}

// Function to display the number of cars loaded and their respective sides
void Display(vector<string> side)
{
    cout << side.size() << '\n';

    for (int i = 0; i < side.size(); i++)
    {
        cout << side[i] << '\n';
    }
}