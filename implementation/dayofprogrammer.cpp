#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

string day_of_programmer(int yr) {
  if (yr >= 1700 && yr <= 1917) {
    bool leap = (yr % 4 == 0);
    if (leap) {
      return "12.09." + to_string(yr);
    } else {
      return "13.09." + to_string(yr);
    }
  } else if (yr == 1918) {
    return "27.09.1918";
  } else if (yr > 1918) {
    bool leap = ((yr % 4 == 0) && (yr % 100 != 0)) || (yr % 400 == 0);

    if (leap) {
      return "12.09." + to_string(yr);
    } else {
      return "13.09." + to_string(yr);
    }
  }
}

int main() {
  int yr;
  cin >> yr;
  cout << day_of_programmer(yr);
}