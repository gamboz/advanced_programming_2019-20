#include <cmath>
#include <iostream>

int main() {
  double d = std::sqrt(4);
  std::cout << d << " " << errno << std::endl;

  // errno is a global macro which defaults value is 0
  
  d = std::sqrt(-4);
  std::cout << d << " " << errno << std::endl;


  // errno is not reset automatically reset to 0
  // errno = 0;
  
  d = std::sqrt(4);
  std::cout << d << " " << errno << std::endl;

  return 0;
}
