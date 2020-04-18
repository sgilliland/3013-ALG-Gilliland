// Sarah Gilliland
#include <iostream>

using namespace std;

int main()
{
    int vertex, edge, maxTrees, i = 0;

    cin >> vertex;
    while (vertex != 0)
    {
        i++; // Increment case number

        edge = (vertex * (vertex - 1)) / 2; // Calculate number of edges
        maxTrees = edge / (vertex - 1);     // Calculuate number of maximum subtrees

        cout << "Case " << i << ": " << maxTrees << "\n"; // Display information

        cin >> vertex; // Read in the next case
    }
    return 0;
}