#include <iostream>
#include <string>
#include <queue>

using namespace std;

bool checkLoad(queue <int> side, int clock)
{
  bool canLoad = false;
  if (side.front() <= clock)
    canLoad = true;
  return canLoad;
}
int Load(queue <int> side, int capacity, int carsSoFar)
{
  if (carsSoFar <= capacity){
    side.pop();
    carsSoFar++;
  }
  return carsSoFar;
}

void UnLoad(queue <int> side, int numCars, int clock){
  for (int i = 0; i < numCars; i++){
    cout << clock << '\n'; 
  }
}

int main()
{
  int n, t, m, arrival, c, numOnFerry, clock;
  int cases = 0;
  string side, car;
  
  cin >> c; // Read in number of cases

  // Queues hold int of the arrival time for each car
  queue <int> Left; // Left cars in left queue
  queue <int> Right;  // Right cars in right queue

  
  // For howerver many cases
  while (cases < c)
  {
    // Read in n, t, and m
    cin >> n >> t >> m;

    // Go through the data and fill the two queues
    for (int i = 0; i < m; i++)
    {
      // Read in car
      cin >> arrival >> side;
      // Load the respective queue
      if (side == "left")
        Left.push(arrival);
      else if (side == "right")
        Right.push(arrival);
    }

    // Starting
    clock = 0;
    for (int j = 0; j < m;){
      numOnFerry = 0;
      // Start on left side
      // If there are any cars on left queue w/ time <= clock, load
      if (checkLoad(Left, clock)){
        j = Load(Left, n, numOnFerry);
        // Cross the river
        clock += t;
      }
      else{ // If there were no cars to load, just cross the river
        //
        clock += t;
      }

      // Now unload
      UnLoad(Left, numOnFerry, clock);
      numOnFerry = 0;

      // Now check the right side
      if (checkLoad(Right, clock)){
        j = Load(Right, n, numOnFerry);
        // Cross the river
        clock += t;
      }
      else{ // If there were no cars to load, just cross the river
        //
        clock += t;
      }

      // Now unload
      UnLoad(Right, numOnFerry, clock);
    }
    cout << '\n';
    cases++;
  }
  return 0;
}
