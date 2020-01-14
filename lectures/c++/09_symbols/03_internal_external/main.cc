#include "constants.h"
#include <iostream>

double area_circle(const double);
double golden_ratio(const double);
extern int circle_counter;
// if
// int circle_counter;
// then the compiler is happy,
// but the linker will see two definitions (also defined in greek)

// if nothing is written
// the compiler will complain that "circle_counter" is not defined

// Better:
// globals.h: external int circle_counter;
// globals.cc: int circle_counter{0};


int main() {
  std::cout << area_circle(1) << std::endl;
  std::cout << area_circle(2) << std::endl;

  std::cout << golden_ratio(1) << std::endl;

  std::cout << circle_counter << std::endl;
  std::cout << "[main] pi = " << pi << std::endl;

  return 0;
}
