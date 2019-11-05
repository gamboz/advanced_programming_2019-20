#include <iostream>

enum class month { jan = 1,
             feb,
             mar,
             apr,
             may,
             jun,
             jul,
             aug,
             sep,
             oct,
             nov,
             dec };

using namespace std;
// use std::cout;

int main() {
  cout << static_cast<int>(month::nov) << endl;
  // cout << dec << endl;  // "dec" is defined in ios_base.h

  return 0;
}
