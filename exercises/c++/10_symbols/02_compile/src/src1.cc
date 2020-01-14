#include <iostream>
#include <string>
#include <algorithm>
#include "utility.h"

std::string greetings(){
  std::string s{"Welcome\n"};
  return s;
}


void print_upper(const std::string& s){
  std::cout << to_upper(greetings()) << to_upper(s) << std::endl;
}


std::string to_upper(const std::string& os){
  static int n = 0;
  ++n;
  auto s = os;
  std::transform(s.begin(), s.end(), s.begin(), ::toupper);
  std::cout << "function " << __func__ << " has been called " << n << " times\n";
  return s;
}
