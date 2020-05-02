///////////////////////////////////////////////////////////////////////////////
//
// Author:           Sarah Gilliland (with help from David Hawkins & Dr. Griffin)
// Email:            sarah13grace@gmail.com
// Label:            1112
// Title:            Mice & Maze
// Course:           3013
// Semester:         Spring 2020
// File Name:        main.cpp
//
// Description:
//  This program reads in information about a maze. The maze consists of cells
//  (which each contain a mouse) and connections (which each take a certain
//  amount of time). The program uses Dijkstra's greedy algorithm to find the
//  shortest path between connections. This allows the program to predict the
//  number of mice who will make it to the exit cell in a given amount of time.
//  The program uses an adjacency matrix to represent the graph.
// 
/////////////////////////////////////////////////////////////////////////////////

#include <string>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

// function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool shortest[], int N)
{
    // initialize min values
    int min = INT_MAX;
    int index;

    for (int i = 0; i < N; i++)
    {
        if (shortest[i] == false && dist[i] <= min)
        {
            min = dist[i];
            index = i;
        }
    }

    return index;
}

// function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int **graph, int exit, int N, int *dist)
{
    bool shortest[N]; // bool array for if cell is in shortest path

    for (int i = 0; i < N; i++) // set all distances to INT_MAX and shortest[] to false
    {
        dist[i] = INT_MAX;
        shortest[i] = false;
    }

    dist[exit] = 0; // distance of exit cell from itself is always 0

    for (int j = 0; j < N - 1; j++) // find shortest path for all cells
    {

        int u = minDistance(dist, shortest, N); // u is min distance and in shortest path
        shortest[u] = true;

        for (int v = 0; v < N; v++) // update dist[v] value
        {
            // if dist[u] is not in shortest, there is an edge from u to v, and total time
            // of path from exit to v through u is smaller than current value of dist[v]
            if (!shortest[v] && graph[u][v] && dist[u] != INT_MAX 
            && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
}

// function to create the 2D array for the maze
int **Make2dArray(int width, int height)
{
    int **newMaze;
    newMaze = new int *[height];

    for (int i = 0; i < height; i++)
    {
        newMaze[i] = new int[width];
    }

    return newMaze;
}

// function to calculate and display the 
// number of mice who will make it out of the maze
void display(int *otherDist, int V, int T)
{
    int numMice = 0;
    for (int i = 1; i < V; i++)
    {
        if (otherDist[i] <= T)
        {
            numMice++;
        }
    }
    cout << numMice;
}

// function to deallocate all dynamic memory
void clear(int **g, int *d, int *od)
{
    delete[] g;
    delete[] d;
    delete[] od;
}

// driver program to test above function
int main()
{
    int tests, counter = 0;
    int N, E, T, M, numMice;
    int a, b, time;
    string x;

    cin >> tests;

    int **maze;     // 2D array to hold the maze
    int *dist;      // array to hold distance from exit to cell
    int *otherDist; // array to hold distance from cell to exit

    while (counter < tests)
    {
        getline(cin, x); // read in the blank line
        cin >> N;        // read in number of cells
        cin >> E;        // read in index of the exit cell
        cin >> T;        // read in starting value of timer
        cin >> M;        // read in number of connections

        N = N + 1;

        maze = Make2dArray(N, N);

        dist = new int[N]; // allocate memory for distance arrays
        otherDist = new int[N];

        for (int i = 0; i < M; i++) // read in all connections
        {
            cin >> a >> b >> time; // a -> b with time of (int)time
            maze[a][b] = time;     // add to maze array
        }

        for (int j = 0; j < N; j++)
        {
            otherDist[j] = INT_MAX; // set all values of otherDist to INT_MAX
        }

        for (int r = 1; r < N; r++) // for all cells except the exit cell
        {
            dijkstra(maze, r, N, dist); // run dijkstras algorithm

            if (otherDist[r] > dist[E]) // distance from exit to cell > cell to exit
            {
                otherDist[r] = dist[E];
            }
        }

        display(otherDist, N, T); // display the result

        clear(maze, dist, otherDist); // delete the allocated memory

        if (counter != tests - 1) // dutput formatting for UVA
        {
            cout << "\n\n";
        }

        counter++;
    }

    return 0;
}