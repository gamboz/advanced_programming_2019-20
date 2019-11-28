#include <iostream>

struct foo {
  void f(int x) { std::cout << "int " << x << std::endl; }
};

struct bar : public foo {
  using foo::f;  // brings all foo::f to this scope
  void f(char x) { std::cout << "char " << x << std::endl; }
  // function overloading does NOT work with inheritance
  // I must explicitly "import" the functions from the base class 
};

int main() {
  bar b;
  b.f(33);
  b.f('3');
}
