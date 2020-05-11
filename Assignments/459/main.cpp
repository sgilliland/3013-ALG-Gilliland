///////////////////////////////////////////////////////////////////////////////
//
// Author:           Sarah Gilliland
// Email:            sarah13grace@gmail.com
// Label:            459
// Title:            Graph Connectivity
// Course:           3013
// Semester:         Spring 2020
// File Name:        main.cpp
//
// Description:
//  This program reads in information about a graph and uses the DFS algorithm
//  to determine the maximal connected subgraphs that can be created. The graph
//  is stored using a struct and the stl list. This process is done for any number 
//  of graphs.
// 
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

struct Graph
{
public:
    Graph(int v) // parameterized constructor
    {
        maximal = 0;
        Vertex = v;
        GraphList = new list<int>[v];
    }

    // Fill reads edges and calls Add to place them in the list
    void Fill()
    {
        int v1, v2;
        string edges;

        // conditional loop
        int j = 0;
        while (j != 50)
        {
            // read edges
            getline(cin, edges);

            if (edges == "") // if line is blank
                j = 50;      // kick out of loop
            else
            {
                // add edge to the list
                v1 = int(edges.at(0)) - 'A';
                v2 = int(edges.at(1)) - 'A';
                Add(v1, v2);
            }
        }
    }

    // Add inserts two connected vertices to the list
    void Add(int v1, int v2)
    {
        GraphList[v2].push_back(v1);
        GraphList[v1].push_back(v2);
    }

    //method for depth-first search
    void DFS(int v, bool visited[])
    {
        visited[v] = true; // vertex has been visited

        list<int>::iterator i; // iterator to search list

        for (i = GraphList[v].begin(); i != GraphList[v].end(); i++) // traverse the list
        {
            if (!visited[*i]) // vertex has not been visited
            {
                DFS(*i, visited); // recursion
            }
        } // breaks loop at end of maximal graph
    }

    // findMaximal finds and displays the number of maximal graphs by calling dfs
    void findMaximal()
    {
        bool *visited = new bool[Vertex]; // array of bools with size Vertex

        for (int i = 0; i < Vertex; i++)
        {
            visited[i] = false; // fill array with false
        }

        for (int i = 0; i < Vertex; i++)
        {
            if (visited[i] == false)
            {
                DFS(i, visited);
                maximal++;
            }
        }
        cout << maximal;
    }

private:
    // Declaring variables
    int Vertex, maximal;
    // Creating a new instance of a list for the graph
    list<int> *GraphList;
};

int main()
{
    int numGraphs;
    string x, bigNode;

    getline(cin, x);     // read in number of graphs
    numGraphs = stoi(x); // turn into an integer
    getline(cin, x);     // read in the blank line

    int i = 0;
    while (i != numGraphs) // loop for multiple graphs
    {
        getline(cin, bigNode); // read the largest node

        int graphSize = int(bigNode.at(0)) - 'A' + 1; // Calculate size of graph using largest node
        Graph newGraph(graphSize);                    // Create instance of Graph class
        newGraph.Fill();                              // fill the graph
        newGraph.findMaximal();                       // find and display the number of maximal graphs using dfs
        if (i == numGraphs - 1)
        {
            cout << endl;
        }
        else
            cout << endl
                 << endl;
        i++;
    }
    return 0;
}