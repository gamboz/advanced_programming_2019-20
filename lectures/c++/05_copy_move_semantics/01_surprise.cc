#include <iostream>

struct X {
  char member;
};

int main() {
  X x1;                 // default ctor
  //  x1.member = 'a';
  X x2{x1};             // copy ctor
  X x3{std::move(x2)};  // move ctor
  X x4{};               // default ctor calling {} to each member
  x4 = x3;              // copy assignment
  X x5;                 // default ctor
  x5 = std::move(x4);   // move assignment
  std::cout << x5.member << std::endl;  // what do you expect??

  // random, because char (member) is a built-in type

  char x{};
  std::cout << x << std::endl;
  
  return 0;
}
