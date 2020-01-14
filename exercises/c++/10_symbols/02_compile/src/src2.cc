#include <iostream>
#include <string>
#include <algorithm>
#include "utility.h"

std::string greetings(){
  std::string s{"Good afternoon\n"};
  return s;
}


void print_lower(const std::string& s){
  std::cout << to_lower(greetings()) << to_lower(s) << std::endl;
}


std::string to_lower(const std::string& os){
  static auto s = os;
  std::transform(s.begin(), s.end(), s.begin(), ::tolower);
  return s;
}
