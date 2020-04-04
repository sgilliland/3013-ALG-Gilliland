// Sarah Gilliland

#include <iostream>

#define endl '\n';

using namespace std;

int main() {
  int num, x, y;
  cin >> num;
  for (int i = 0; i < num; i++) {
    cin >> x >> y;
    
    if (x < y) {
      cout << '<' << endl;
    }
    else if (x > y) {
      cout << '>' << endl;
    }
    else{
      cout << '=' << endl;
    } 
  }
  return 0;
}