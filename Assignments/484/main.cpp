// Sarah Gilliland

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