#pragma once

#include <string>
#include <algorithm>
#include <iostream>

void print_lower(const std::string& s); // src1
void print_upper(const std::string& s); // src2


std::string to_upper(const std::string& os);
std::string to_lower(const std::string& os);

std::string to_upper(const std::string& os){
  static int n = 0;
  ++n;
  auto s = os;
  std::transform(s.begin(), s.end(), s.begin(), ::toupper);
  std::cout << "function " << __func__ << " has been called " << n << " times\n";
  return s;
}

std::string to_lower(const std::string& os){
  static auto s = os;
  std::transform(s.begin(), s.end(), s.begin(), ::tolower);
  return s;
}
