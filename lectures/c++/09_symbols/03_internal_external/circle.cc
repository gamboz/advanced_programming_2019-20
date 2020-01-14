#include "constants.h"
#include <iostream>

int circle_counter{0};

double area_circle(const double r) {
  //pi = 123;
  std::cout << "[circle] pi = " << pi << std::endl;
  ++circle_counter;
  return pi * r * r;
}
