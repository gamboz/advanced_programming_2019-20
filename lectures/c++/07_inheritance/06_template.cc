#include <iostream>

template <typename T>
struct Base {
  void foo() const { std::cout << "base foo" << std::endl; }
};

template <typename T>
struct Derived : public Base<T> {
  void bar() const { this->foo(); }
  // since the  base class is templated
  // the derived class should use "this"
  // which is a pointer to the class
  // (so members are accessed via ->)
};

int main() {
  Derived<int> d;
  d.bar();
}
